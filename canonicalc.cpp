#include "canonicalc.h"
#include "ui_canonicalc.h"

#include <QDebug>
#include <QString>

Canonicalc::Canonicalc(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Canonicalc)
{
    ui->setupUi(this);
    setFocusPolicy(Qt::ClickFocus);
}

Canonicalc::~Canonicalc()
{
    delete ui;
}


void Canonicalc::on_btnChangeSign_clicked()
{
    if (equalPressed) { clear(); equalPressed = false; };
    //Gets current display value, casts that to double,
    //  changes sign (multiplies by -1), and then casts that back to QString for display.
    QString newDisplayValue = QString::number((ui->display->text().toDouble() * -1), 'g', 15);
    //Refreshes display with new value.
    ui->display->setText(newDisplayValue);
    currentValue = newDisplayValue.toDouble();
}

void Canonicalc::on_btnDecimal_clicked()
{
    if (equalPressed) { clear(); equalPressed = false; };
    //Checks if value contains ".", decimal symbol,
    //  if doesn't appends "." to the end of display value.
    if (!ui->display->text().contains(".")) {
        ui->display->setText(ui->display->text() + ".");
    }
}

void Canonicalc::on_btn0_clicked() { appendValue(0); }
void Canonicalc::on_btn1_clicked() { appendValue(1); }
void Canonicalc::on_btn2_clicked() { appendValue(2); }
void Canonicalc::on_btn3_clicked() { appendValue(3); }
void Canonicalc::on_btn4_clicked() { appendValue(4); }
void Canonicalc::on_btn5_clicked() { appendValue(5); }
void Canonicalc::on_btn6_clicked() { appendValue(6); }
void Canonicalc::on_btn7_clicked() { appendValue(7); }
void Canonicalc::on_btn8_clicked() { appendValue(8); }
void Canonicalc::on_btn9_clicked() { appendValue(9); }

void Canonicalc::on_btnClear_clicked(){ clear(); }

void Canonicalc::on_btnBackspace_clicked()
{
    if (equalPressed) { clear(); equalPressed = false; };
    QString newValue = ui->display->text();
    newValue.chop(1);
    ui->display->setText(newValue);
    currentValue = newValue.toDouble();
}

void Canonicalc::on_btnSqrt_clicked()
{
    if (equalPressed) { clear(0); equalPressed = false; };

    isSqrt = true;
    latestEntry = "√(" + ui->display->text() + ")";
    latestHistory += latestEntry;
    ui->latestCalculation->setText(latestHistory);
    valueSaved = true;

    currentValue = sqrt(ui->display->text().toDouble());

    ui->display->setText(QString::number(currentValue, 'g', 15));
    awaitingInput = true;
    valueChanged = true; //???
}

void Canonicalc::on_btnDivide_clicked()
{
    if (equalPressed) { clear(0); equalPressed = false; };

    if (valueChanged) {
        refresh(currentValue);
        calculate();
        awaitingInput = true;
        valueChanged = false;
    }
    else {
        previousValue = ui->display->text().toDouble();
        currentValue = NULL;
        awaitingInput = true;
        currentOperation = Operation::Divide;
        refresh(previousValue);
    }
}

void Canonicalc::on_btnMultiply_clicked()
{
    if (equalPressed) { clear(0); equalPressed = false; };

    if (valueChanged) {
        refresh(currentValue);
        calculate();
        awaitingInput = true;
        valueChanged = false;
    }
    else {
        previousValue = ui->display->text().toDouble();
        currentValue = NULL;
        awaitingInput = true;
        currentOperation = Operation::Multiply;
        refresh(previousValue);
    }
}

void Canonicalc::on_btnSubtract_clicked()
{
    if (equalPressed) { clear(0); equalPressed = false; };

    if (valueChanged) {
        refresh(currentValue);
        calculate();
        awaitingInput = true;
        valueChanged = false;
    }
    else {
        previousValue = ui->display->text().toDouble();
        currentValue = NULL;
        awaitingInput = true;
        currentOperation = Operation::Subtract;
        refresh(previousValue);
    }
}

void Canonicalc::on_btnAdd_clicked()
{
    if (equalPressed) { clear(0); equalPressed = false; };

    if (valueChanged) { //Second value
        refresh(currentValue);
        calculate();
        awaitingInput = true;
        valueChanged = false;
    }
    else {
        previousValue = ui->display->text().toDouble();
        currentValue = NULL;
        awaitingInput = true;
        currentOperation = Operation::Add;
        refresh(previousValue);
    }
}

void Canonicalc::on_btnEquals_clicked()
{
    if (equalPressed) {
        QString newDisplayValue;

        switch (previousOperation) {
        case Operation::None:
            latestHistory = QString::number(result, 'g', 15);
            result = currentValue;
            ui->display->setText(QString::number(currentValue, 'g', 15));
            break;

        case Operation::Divide:
            latestHistory = QString::number(result, 'g', 15);
            result /= currentValue;
            latestHistory += " / ";
            latestHistory += QString::number(currentValue, 'g', 15);
            newDisplayValue = QString::number(result, 'g', 15);
            ui->display->setText(newDisplayValue);
            break;

        case Operation::Multiply:
            latestHistory = QString::number(result, 'g', 15);
            result *= currentValue;
            latestHistory += " * ";
            latestHistory += QString::number(currentValue, 'g', 15);
            newDisplayValue = QString::number(result, 'g', 15);
            ui->display->setText(newDisplayValue);
            break;

        case Operation::Subtract:
            latestHistory = QString::number(result, 'g', 15);
            result -= currentValue;
            latestHistory += " - ";
            latestHistory += QString::number(currentValue, 'g', 15);
            newDisplayValue = QString::number(result, 'g', 15);
            ui->display->setText(newDisplayValue);
            break;

        case Operation::Add:
            latestHistory = QString::number(result, 'g', 15);
            result += currentValue;
            latestHistory += " + ";
            latestHistory += QString::number(currentValue, 'g', 15);
            newDisplayValue = QString::number(result, 'g', 15);
            ui->display->setText(newDisplayValue);
            break;
        }
        latestHistory += " = ";
        ui->latestCalculation->setText(latestHistory);
        saveHistory();
    }
    else {
        calculate();

        if (!valueSaved) { //Save previous value to history if needed
            latestEntry = QString::number(currentValue, 'g', 15);
            latestHistory += latestEntry;
            valueSaved = true;
        }

        //if (latestHistory.endsWith(" ")) {
        //    latestHistory.chop(3);
        //} Probably useless?
        latestHistory += " = ";

        ui->latestCalculation->setText(latestHistory);
        saveHistory();

        equalPressed = true; //This is to allow repetitive operation.
    }
}


//Overrided function, handles keyboard clicks.
void Canonicalc::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key::Key_0: appendValue(0); break;
    case Qt::Key::Key_1: appendValue(1); break;
    case Qt::Key::Key_2: appendValue(2); break;
    case Qt::Key::Key_3: appendValue(3); break;
    case Qt::Key::Key_4: appendValue(4); break;
    case Qt::Key::Key_5: appendValue(5); break;
    case Qt::Key::Key_6: appendValue(6); break;
    case Qt::Key::Key_7: appendValue(7); break;
    case Qt::Key::Key_8: appendValue(8); break;
    case Qt::Key::Key_9: appendValue(9); break;
    case Qt::Key::Key_Backspace:
        if (equalPressed) { clear(); equalPressed = false; };
        QString newValue = ui->display->text();
        newValue.chop(1);
        ui->display->setText(newValue);
        currentValue = newValue.toDouble();
        break;
    }
}

//Overrided function, checks if there's enough space for "calc history browser",
//  if possible, shows calculations history list.
void Canonicalc::resizeEvent(QResizeEvent*)
{
    if (this->width() > 520) {
        ui->historyBrowser->setEnabled(true);
        ui->historyBrowser->setHidden(false);
        ui->historyLabel->setHidden(false);
        ui->historyClear->setHidden(false);

        ui->btnHistory->setHidden(true);
    }
    else {
        ui->historyBrowser->setHidden(true);
        ui->historyLabel->setHidden(true);
        ui->historyClear->setHidden(true);

        ui->btnHistory->setHidden(false);
    }

    //This is for "fixed history browser" which is opened by button.
    ui->buttons->setHidden(false);
    ui->fixedHistoryBrowser->setHidden(true);
    ui->fixedHistoryLabel->setHidden(true);
    ui->fixedHistoryClear->setHidden(true);
}

void Canonicalc::clear(bool clearDisplay)
{
    previousValue = NULL;
    currentValue = NULL;
    result = NULL;

    awaitingInput = false;
    valueChanged = false;
    valueSaved = false;
    isSqrt = false;
    equalPressed = false;

    previousOperation = Operation::None;
    currentOperation = Operation::None;

    latestEntry.clear();
    latestHistory.clear();

    if (clearDisplay) {
        ui->display->setText(NULL);
    }
    ui->latestCalculation->setText(NULL);
}

void Canonicalc::appendValue(double btnValue)
{
    QString newDisplayValue;

    if (equalPressed) { clear(); equalPressed = false; };

    //Clears display if needed.
    if (awaitingInput) {
        ui->display->setText(QString::number(0, 'g', 15));
        awaitingInput = false;
        valueChanged = true;
        if (isSqrt) {
            latestHistory.chop(latestEntry.length());
            ui->latestCalculation->setText(latestHistory);
        }
    }

    //Appends 0 as QString (due to bug) when display value is a decimal.
    if (ui->display->text().contains(".") && btnValue == 0) {
        newDisplayValue = ui->display->text() + QString::number(btnValue);
    }
    else {
        //Appends btnValue (first casted to QString, to allow appending)
        //  to current display value, casts that to double, and then back to QString for display.
        newDisplayValue = QString::number((ui->display->text() + QString::number(btnValue)).toDouble(), 'g', 15);
    }

    //Refreshes display with new value.
    ui->display->setText(newDisplayValue);
    currentValue = newDisplayValue.toDouble();

    valueSaved = false;
}

void Canonicalc::refresh(double value)
{
    if (!valueSaved) { //Save previous value to history.
        latestEntry = QString::number(value, 'g', 15);
        latestHistory += latestEntry;
        valueSaved = true;
    }
    if (!latestHistory.endsWith(" ")) { //Append operation type to history
        switch (currentOperation)
        {
        case Operation::None:
            break;

        case Operation::Divide:
            latestHistory += " / ";
            break;

        case Operation::Multiply:
            latestHistory += " * ";
            break;

        case Operation::Subtract:
            latestHistory += " - ";
            break;

        case Operation::Add:
            latestHistory += " + ";
            break;
        }
    }
    if (currentOperation != previousOperation) {
        latestHistory.chop(3);
        switch (currentOperation)
        {
        case Operation::None:
            break;

        case Operation::Divide:
            latestHistory += " / ";
            break;

        case Operation::Multiply:
            latestHistory += " * ";
            break;

        case Operation::Subtract:
            latestHistory += " - ";
            break;

        case Operation::Add:
            latestHistory += " + ";
            break;
        }
    }
    previousOperation = currentOperation;
    ui->latestCalculation->setText(latestHistory);
}

void Canonicalc::calculate()
{
    QString newDisplayValue;

    currentValue = ui->display->text().toDouble();

    if (result == NULL) {
        result = previousValue;
    }

    switch (previousOperation) {
    case Operation::None:
        result = currentValue;
        ui->display->setText(QString::number(currentValue, 'g', 15));
        break;

    case Operation::Divide:
        result /= currentValue;
        newDisplayValue = QString::number(result, 'g', 15);
        ui->display->setText(newDisplayValue);
        break;

    case Operation::Multiply:
        result *= currentValue;
        newDisplayValue = QString::number(result, 'g', 15);
        ui->display->setText(newDisplayValue);
        break;

    case Operation::Subtract:
        result -= currentValue;
        newDisplayValue = QString::number(result, 'g', 15);
        ui->display->setText(newDisplayValue);
        break;

    case Operation::Add:
        result += currentValue;
        newDisplayValue = QString::number(result, 'g', 15);
        ui->display->setText(newDisplayValue);
        break;
    }

    previousOperation = currentOperation;
    //previousValue = result;
}

void Canonicalc::calculate(double firstValue, double secondValue, Operation op)
{
    QString newDisplayValue;

    currentValue = ui->display->text().toDouble();

    if (result == NULL) {
        result = firstValue;
    }

    switch (op) {
    case Operation::None:
        result = currentValue;
        ui->display->setText(QString::number(currentValue));
        break;

    case Operation::Divide:
        result /= secondValue;
        newDisplayValue = QString::number(result, 'g', 15);
        ui->display->setText(newDisplayValue);
        break;

    case Operation::Multiply:
        result *= secondValue;
        newDisplayValue = QString::number(result, 'g', 15);
        ui->display->setText(newDisplayValue);
        break;

    case Operation::Subtract:
        result -= secondValue;
        newDisplayValue = QString::number(result, 'g', 15);
        ui->display->setText(newDisplayValue);
        break;

    case Operation::Add:
        result += secondValue;
        newDisplayValue = QString::number(result, 'g', 15);
        ui->display->setText(newDisplayValue);
        break;
    }

    previousOperation = currentOperation;
    //previousValue = result;
}

/* HISTORY */
void Canonicalc::on_btnHistory_clicked()
{
    if (ui->fixedHistoryBrowser->isHidden()) {
        ui->buttons->setHidden(true);
        ui->fixedHistoryBrowser->setHidden(false);
        ui->fixedHistoryLabel->setHidden(false);
        ui->fixedHistoryClear->setHidden(false);
    }
    else {
        ui->buttons->setHidden(false);
        ui->fixedHistoryBrowser->setHidden(true);
        ui->fixedHistoryLabel->setHidden(true);
        ui->fixedHistoryClear->setHidden(true);
    }
}

void Canonicalc::on_fixedHistoryClear_clicked() { clearHistory(); }

void Canonicalc::on_historyClear_clicked() { clearHistory(); }

void Canonicalc::saveHistory()
{
    ui->historyBrowser->setHtml("<div style=\"text-align:right; margin-bottom: 100px;\">"
        "<p style=\"font-size: 16pt; color: #717171\">" +
        latestHistory + "</p><p style=\"font-size: 18pt; font-weight: 700; color:#fafaf6;\">" +
        QString::number(result) + "</p></div><br><br>" + ui->historyBrowser->toHtml());
    ui->fixedHistoryBrowser->setHtml(ui->historyBrowser->toHtml());
}

void Canonicalc::clearHistory()
{
    ui->historyBrowser->clear();
    ui->fixedHistoryBrowser->clear();
}
