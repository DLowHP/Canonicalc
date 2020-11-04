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

    connect(ui->btnClear, SIGNAL(clicked()), this, SLOT(clearHandler()));
    connect(ui->btnBackspace, SIGNAL(clicked()), this, SLOT(backspace()));

    connect(ui->btnDivide, SIGNAL(clicked()), this, SLOT(divide()));
    connect(ui->btnMultiply, SIGNAL(clicked()), this, SLOT(multiply()));
    connect(ui->btnSubtract, SIGNAL(clicked()), this, SLOT(subtract()));
    connect(ui->btnAdd, SIGNAL(clicked()), this, SLOT(add()));
    connect(ui->btnEquals, SIGNAL(clicked()), this, SLOT(equals()));

    connect(ui->btnDecimal, SIGNAL(clicked()), this, SLOT(decimal()));
    connect(ui->btnSqrt, SIGNAL(clicked()), this, SLOT(squareroot()));
    connect(ui->btnChangeSign, SIGNAL(clicked()), this, SLOT(changeSign()));

    connect(ui->btn0, SIGNAL(clicked()), this, SLOT(appendValueHandler()));
    connect(ui->btn1, SIGNAL(clicked()), this, SLOT(appendValueHandler()));
    connect(ui->btn2, SIGNAL(clicked()), this, SLOT(appendValueHandler()));
    connect(ui->btn3, SIGNAL(clicked()), this, SLOT(appendValueHandler()));
    connect(ui->btn4, SIGNAL(clicked()), this, SLOT(appendValueHandler()));
    connect(ui->btn5, SIGNAL(clicked()), this, SLOT(appendValueHandler()));
    connect(ui->btn6, SIGNAL(clicked()), this, SLOT(appendValueHandler()));
    connect(ui->btn7, SIGNAL(clicked()), this, SLOT(appendValueHandler()));
    connect(ui->btn8, SIGNAL(clicked()), this, SLOT(appendValueHandler()));
    connect(ui->btn9, SIGNAL(clicked()), this, SLOT(appendValueHandler()));

    connect(ui->btnHistory, SIGNAL(clicked()), this, SLOT(showHistory()));
    connect(ui->historyClear, SIGNAL(clicked()), this, SLOT(clearHistory()));
    connect(ui->fixedHistoryClear, SIGNAL(clicked()), this, SLOT(clearHistory()));
}

Canonicalc::~Canonicalc() { delete ui; }



void Canonicalc::clearHandler() { clear(1); }

//Clears everything by setting to default values.
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
//Nice ( ͡° ͜ʖ ͡° )
        ui->display->setText("0");
    }
    ui->latestCalculation->setText(NULL);
}

void Canonicalc::backspace()
{
    if (equalPressed) { clear(); equalPressed = false; };

    QString newValue = ui->display->text();

    if (newValue.length() > 1) {
        newValue.chop(1);
    }
    else {
        newValue = "0";
    }

    ui->display->setText(newValue);
    currentValue = newValue.toDouble();
}



/**************************************
*   OPERATIONS
**************************************/
void Canonicalc::divide()
{
    if (equalPressed) { clear(0); equalPressed = false; };

    if (valueChanged) {
        calculate();
        currentOperation = Operation::Divide;
        refresh(currentValue);
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

void Canonicalc::multiply()
{
    if (equalPressed) { clear(0); equalPressed = false; };

    if (valueChanged) {
        calculate();
        currentOperation = Operation::Multiply;
        refresh(currentValue);
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

void Canonicalc::subtract()
{
    if (equalPressed) { clear(0); equalPressed = false; };

    if (valueChanged) {
        calculate();
        currentOperation = Operation::Subtract;
        refresh(currentValue);
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

void Canonicalc::add()
{
    if (equalPressed) { clear(0); equalPressed = false; };

    if (valueChanged) { //Second value
        calculate();
        currentOperation = Operation::Add;
        refresh(currentValue);
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

void Canonicalc::equals()
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



/**************************************
*   MODIFIERS
**************************************/
void Canonicalc::decimal()
{
    if (equalPressed) { clear(); equalPressed = false; };
    //Checks if value contains ".", decimal symbol,
    //  if doesn't appends "." to the end of display value.
    if (!ui->display->text().contains(".")) {
        ui->display->setText(ui->display->text() + ".");
    }
}

void Canonicalc::squareroot()
{
    if (equalPressed) { clear(0); equalPressed = false; };

    isSqrt = true;
    latestEntry = "sqrt(" + ui->display->text() + ")";
    latestHistory += latestEntry;
    ui->latestCalculation->setText(latestHistory);
    valueSaved = true;

    currentValue = sqrt(ui->display->text().toDouble());

    ui->display->setText(QString::number(currentValue, 'g', 15));
    awaitingInput = true;
    valueChanged = true; //???
}

void Canonicalc::changeSign()
{
    if (equalPressed) { clear(); equalPressed = false; };
    //Gets current display value, casts that to double,
    //  changes sign (multiplies by -1), and then casts that back to QString for display.
    QString newDisplayValue = QString::number((ui->display->text().toDouble() * -1), 'g', 15);
    //Refreshes display with new value.
    ui->display->setText(newDisplayValue);
    currentValue = newDisplayValue.toDouble();
}



/**************************************
*   HISTORY
**************************************/
void Canonicalc::showHistory()
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

void Canonicalc::clearHistory()
{
    ui->historyBrowser->clear();
    ui->fixedHistoryBrowser->clear();
    ui->historyClear->setEnabled(false);
    ui->fixedHistoryClear->setEnabled(false);
}

void Canonicalc::saveHistory()
{
    ui->historyBrowser->setHtml("<div style=\"text-align:right; margin-bottom: 100px;\">"
        "<p style=\"font-size: 16pt; color: #717171\">" +
        latestHistory + "</p><p style=\"font-size: 18pt; font-weight: 700; color:#fafaf6;\">" +
        QString::number(result) + "</p></div><br><br>" + ui->historyBrowser->toHtml());
    ui->fixedHistoryBrowser->setHtml(ui->historyBrowser->toHtml());
    ui->historyClear->setEnabled(true);
    ui->fixedHistoryClear->setEnabled(true);
}



/**************************************
*   OTHER
**************************************/
void Canonicalc::appendValueHandler()
{
    QPushButton * btn = (QPushButton*)sender();
    switch(btn->text().toInt()){
    case 0: { appendValue(0); break; }
    case 1: { appendValue(1); break; }
    case 2: { appendValue(2); break; }
    case 3: { appendValue(3); break; }
    case 4: { appendValue(4); break; }
    case 5: { appendValue(5); break; }
    case 6: { appendValue(6); break; }
    case 7: { appendValue(7); break; }
    case 8: { appendValue(8); break; }
    case 9: { appendValue(9); break; }
    }
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

//Refreshes history and changes previousOperation to currentOperation.
void Canonicalc::refresh(double value)
{
    if (!valueSaved) { //Save previous value to history.
        if (value < 0) {
            latestEntry += "(" + QString::number(value, 'g', 15) + ")";
        }
        else {
            latestEntry = QString::number(value, 'g', 15);
        }
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

//Calculates latest operation.
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

//Overrided function, handles keyboard events.
void Canonicalc::keyPressEvent(QKeyEvent* event)
{
    switch (event->key()) {
    case Qt::Key::Key_Delete: { clear(); break; }
    case Qt::Key::Key_Backspace: { backspace(); break; }

    case Qt::Key::Key_Slash: { divide(); break; }
    case Qt::Key::Key_Asterisk: { multiply(); break; }
    case Qt::Key::Key_Minus: { subtract(); break; }
    case Qt::Key::Key_Plus: { add(); break; }
    case Qt::Key::Key_Equal:
    case Qt::Key::Key_Enter: { equals(); break; }

    case Qt::Key::Key_Comma:
    case Qt::Key::Key_Period: { decimal(); break; }

    case Qt::Key::Key_0: { appendValue(0); break; }
    case Qt::Key::Key_1: { appendValue(1); break; }
    case Qt::Key::Key_2: { appendValue(2); break; }
    case Qt::Key::Key_3: { appendValue(3); break; }
    case Qt::Key::Key_4: { appendValue(4); break; }
    case Qt::Key::Key_5: { appendValue(5); break; }
    case Qt::Key::Key_6: { appendValue(6); break; }
    case Qt::Key::Key_7: { appendValue(7); break; }
    case Qt::Key::Key_8: { appendValue(8); break; }
    case Qt::Key::Key_9: { appendValue(9); break; }
    }
}

//Whoa, you went so deep...
