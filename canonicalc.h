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

    void clear(bool clearDisplay = true);
    void appendValue(double btnValue);
    void refresh(double value);
    void calculate();

    /* HISTORY */
    QString latestEntry;
    QString latestHistory;

    void saveHistory();
    

private slots:
    void clearHandler();
    void backspace();

    void divide();
    void multiply();
    void subtract();
    void add();
    void equals();

    void decimal();
    void squareroot();
    void changeSign();

    void appendValueHandler();

    void showHistory();
    void clearHistory();
};
#endif // CANONICALC_H
