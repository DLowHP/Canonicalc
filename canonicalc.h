#ifndef CANONICALC_H
#define CANONICALC_H

#include <QMainWindow>
#include <QKeyEvent>

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
    virtual void keyPressEvent(QKeyEvent *event);

private:
    Ui::Canonicalc *ui;

    double previousValue = NULL;
    double currentValue = NULL;
    double result = NULL;

    bool awaitingInput = false;
    bool valueChanged = false;
    bool valueSaved = false;
    bool isSqrt = false;
    bool equalPressed = false;

    enum class Operation {
        None,
        Divide,
        Multiply,
        Subtract,
        Add
    };
    Operation previousOperation = Operation::None;
    Operation currentOperation = Operation::None;

    /*  */
    void appendValue(double btnValue);
    void clear(bool clearDisplay = true);
    void refresh(double value);
    void calculate();
    void calculate(double firstValue, double secondValue, Operation op);

    /* HISTORY */
    QString latestEntry;
    QString latestHistory;

    void saveHistory();
    void clearHistory();

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
    void on_fixedHistoryClear_clicked();
    void on_historyClear_clicked();
};
#endif // CANONICALC_H
