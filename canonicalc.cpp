#include "canonicalc.h"
#include "ui_canonicalc.h"

#include <QDebug>
#include <QString>

Canonicalc::Canonicalc(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Canonicalc)
{
    ui->setupUi(this);
}

Canonicalc::~Canonicalc()
{
    delete ui;
}

//Overrided function, checks if there's enough space for "calc history browser",
//  if possible, shows calculations history list.
void Canonicalc::resizeEvent(QResizeEvent *)
{
    if(this->width() > 520) {
        ui->historyBrowser->setEnabled(true);
        ui->historyBrowser->setHidden(false);
        ui->historyLabel->setHidden(false);

        ui->btnHistory->setHidden(true);
    }
    else {
        ui->historyBrowser->setHidden(true);
        ui->historyLabel->setHidden(true);

        ui->btnHistory->setHidden(false);
    }

    //This is for "fixed history browser" which is opened by button.
    ui->buttons->setHidden(false);
    ui->fixedHistoryBrowser->setHidden(true);
    ui->fixedHistoryLabel->setHidden(true);
}

void Canonicalc::appendValue(double btnValue)
{
    QString newDisplayValue;

    //Clears display if needed (this is used to input second value).
    if(awaitingInput) {
        if(ui->latestCalculation->toPlainText().contains("=")) {
            firstValue = NULL;
            secondValue = NULL;

            latestCalculation.clear();
            ui->latestCalculation->setText(NULL);
        }
        ui->display->setText(QString::number(0));
        awaitingInput = false;
    }

    //Appends 0 as QString (because of bug) when display value is a decimal .
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
}

void Canonicalc::on_btnClear_clicked()
{
    firstValue = NULL;
    secondValue = NULL;

    ui->latestCalculation->setText(NULL);

    ui->display->setText(QString::number(0));
    currentOperation = Operation::None;
}

void Canonicalc::on_btnBackspace_clicked()
{
    QString newValue = ui->display->text();
    newValue.chop(1);
    ui->display->setText(newValue);
}

void Canonicalc::on_btnSqrt_clicked()
{
    //Update latest calculation display.
    isSqrt = true;
    updateLatestCalculation();
    isSqrt = false;
    //Change display to square root of firstValue.
    ui->display->setText(QString::number(sqrt(ui->display->text().toDouble())));
    //Store current value.
    secondValue = ui->display->text().toDouble();
}

void Canonicalc::on_btnDivide_clicked()
{
    //Store current value.
    firstValue = ui->display->text().toDouble();
    //Clear secondValue.
    secondValue = NULL;
    //Set awaitingInput to true to indicate need for secondValue.
    awaitingInput = true;
    //Set current operation.
    currentOperation = Operation::Divide;
    //Update latest calculation display.
    updateLatestCalculation();
}

void Canonicalc::on_btnMultiply_clicked()
{
    //Store current value.
    firstValue = ui->display->text().toDouble();
    //Clear secondValue.
    secondValue = NULL;
    //Set awaitingInput to true to indicate need for secondValue.
    awaitingInput = true;
    //Set current operation.
    currentOperation = Operation::Multiply;
    //Update latest calculation display.
    updateLatestCalculation();
}

void Canonicalc::on_btnSubtract_clicked()
{
    //Store current value.
    firstValue = ui->display->text().toDouble();
    //Clear secondValue.
    secondValue = NULL;
    //Set awaitingInput to true to indicate need for secondValue.
    awaitingInput = true;
    //Set current operation.
    currentOperation = Operation::Subtract;
    //Update latest calculation display.
    updateLatestCalculation();
}

void Canonicalc::on_btnAdd_clicked()
{
    //Store current value.
    firstValue = ui->display->text().toDouble();
    //Clear secondValue.
    secondValue = NULL;
    //Set awaitingInput to true to indicate need for secondValue.
    awaitingInput = true;
    //Set current operation.
    currentOperation = Operation::Add;
    //Update latest calculation display.
    updateLatestCalculation();
}

void Canonicalc::on_btnEquals_clicked()
{

    if(secondValue == NULL) {
        secondValue = ui->display->text().toDouble();
    }

    QString newDisplayValue;

    switch(currentOperation) {
    case Operation::None:
        break;

    case Operation::Divide:
        //Divides two values and casts them to QString.
        newDisplayValue = QString::number((firstValue / secondValue), 'g', 15);
        //Refreshes display with new value.
        ui->display->setText(newDisplayValue);
        break;

    case Operation::Multiply:
        //Multiplies two values and casts them to QString.
        newDisplayValue = QString::number((firstValue * secondValue), 'g', 15);
        //Refreshes display with new value.
        ui->display->setText(newDisplayValue);
        break;

    case Operation::Subtract:
        //Subtracts two values and casts them to QString.
        newDisplayValue = QString::number((firstValue - secondValue), 'g', 15);
        //Refreshes display with new value.
        ui->display->setText(newDisplayValue);
        break;

    case Operation::Add:
        //Adds two values and casts them to QString.
        newDisplayValue = QString::number((firstValue + secondValue), 'g', 15);
        //Refreshes display with new value.
        ui->display->setText(newDisplayValue);
        break;
    }

    updateLatestCalculation();
    saveLatestCalculation(ui->display->text());
    firstValue = newDisplayValue.toDouble();
    awaitingInput = true;
}

void Canonicalc::on_btnChangeSign_clicked()
{
    //Gets current display value, casts that to double,
    //  changes sign (multiplies by -1), and then casts that back to QString for display.
    QString newDisplayValue = QString::number((ui->display->text().toDouble() * -1), 'g', 15);
    //Refreshes display with new value.
    ui->display->setText(newDisplayValue);
}

void Canonicalc::on_btnDecimal_clicked()
{
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



void Canonicalc::on_btnHistory_clicked()
{
    if(ui->fixedHistoryBrowser->isHidden()){
        ui->buttons->setHidden(true);
        ui->fixedHistoryBrowser->setHidden(false);
        ui->fixedHistoryLabel->setHidden(false);
    }
    else {
        ui->buttons->setHidden(false);
        ui->fixedHistoryBrowser->setHidden(true);
        ui->fixedHistoryLabel->setHidden(true);
    }
}


/* CALCULATIONS  */



/* HISTORY HANDLER */

void Canonicalc::updateLatestCalculation()
{
    if (firstValue != NULL){
        latestCalculation = QString::number(firstValue);
        switch (currentOperation){
        case Operation::None:
            break;

        case Operation::Divide:
            latestCalculation += " / ";
            break;

        case Operation::Multiply:
            latestCalculation += " * ";
            break;

        case Operation::Subtract:
            latestCalculation += " - ";
            break;

        case Operation::Add:
            latestCalculation += " + ";
            break;
        }
    }

    if(secondValue != NULL && (!isSqrt)) {
        latestCalculation += QString::number(secondValue);
    } else if(isSqrt) {
        latestCalculation += "√(" + ui->display->text() + ")";
    }

    ui->latestCalculation->setText(latestCalculation);
}

void Canonicalc::saveLatestCalculation(const QString result)
{
    //Append equals sign to latest calculation.
    latestCalculation += " = ";
    //Update latest calculation display.
    ui->latestCalculation->setText(latestCalculation);
    //Store lates calculation in history browser.
    ui->historyBrowser->setHtml("<div style=\"text-align:right; margin-bottom: 100px;\">"
                                "<p style=\"font-size: 16pt; color: #717171\">" +
                                latestCalculation + "</p><p style=\"font-size: 18pt; font-weight: 700; color:#fafaf6;\">" +
                                result + "</p></div><br><br>" + ui->historyBrowser->toHtml());
}
