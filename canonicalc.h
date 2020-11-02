#ifndef CANONICALC_H
#define CANONICALC_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Canonicalc; }
QT_END_NAMESPACE

class Canonicalc : public QMainWindow
{
    Q_OBJECT

public:
    Canonicalc(QWidget *parent = nullptr);
    ~Canonicalc();

protected:
    //Overrides QWidget class function that handles window resize event
    virtual void resizeEvent(QResizeEvent *);

private:
    Ui::Canonicalc *ui;

    bool awaitingInput = false;
    double firstValue = NULL;
    double secondValue = NULL;
    void appendValue(double btnValue);
    enum class Operation {
        None,
        Divide,
        Multiply,
        Subtract,
        Add
    };
    bool isSqrt = false;
    Operation currentOperation = Operation::None;

    /* HISTORY HANDLER */
    QString latestCalculation;
    void updateLatestCalculation();
    void saveLatestCalculation(const QString result);

private slots:
    void on_btnClear_clicked();
    void on_btnBackspace_clicked();
    void on_btnSqrt_clicked();
    void on_btnDivide_clicked();
    void on_btnMultiply_clicked();
    void on_btnSubtract_clicked();
    void on_btnAdd_clicked();
    void on_btnEquals_clicked();
    void on_btnChangeSign_clicked();
    void on_btnDecimal_clicked();
    void on_btn0_clicked();
    void on_btn1_clicked();
    void on_btn2_clicked();
    void on_btn3_clicked();
    void on_btn4_clicked();
    void on_btn5_clicked();
    void on_btn6_clicked();
    void on_btn7_clicked();
    void on_btn8_clicked();
    void on_btn9_clicked();
    void on_btnHistory_clicked();
};
#endif // CANONICALC_H
