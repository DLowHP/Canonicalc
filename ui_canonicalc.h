/********************************************************************************
** Form generated from reading UI file 'canonicalc.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CANONICALC_H
#define UI_CANONICALC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Canonicalc
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *btnHistory;
    QHBoxLayout *horizontalLayout;
    QLabel *fixedHistoryLabel;
    QPushButton *fixedHistoryClear;
    QWidget *buttons;
    QGridLayout *btnGrid;
    QPushButton *btnChangeSign;
    QPushButton *btnDecimal;
    QPushButton *btn1;
    QPushButton *btn5;
    QPushButton *btnDivide;
    QPushButton *btn4;
    QPushButton *btn9;
    QPushButton *btn6;
    QPushButton *btn3;
    QPushButton *btnBackspace;
    QPushButton *btnEquals;
    QPushButton *btn7;
    QPushButton *btnSubtract;
    QPushButton *btn8;
    QPushButton *btnClear;
    QPushButton *btnSqrt;
    QPushButton *btnMultiply;
    QPushButton *btn2;
    QPushButton *btn0;
    QPushButton *btnAdd;
    QVBoxLayout *displayWrapper;
    QTextBrowser *latestCalculation;
    QLabel *display;
    QTextEdit *fixedHistoryBrowser;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *historyLabelWrapper;
    QLabel *historyLabel;
    QPushButton *historyClear;
    QTextEdit *historyBrowser;
    QMenuBar *menubar;

    void setupUi(QMainWindow *Canonicalc)
    {
        if (Canonicalc->objectName().isEmpty())
            Canonicalc->setObjectName(QString::fromUtf8("Canonicalc"));
        Canonicalc->resize(442, 740);
        Canonicalc->setStyleSheet(QString::fromUtf8("background-color: #404958;"));
        centralwidget = new QWidget(Canonicalc);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        btnHistory = new QPushButton(centralwidget);
        btnHistory->setObjectName(QString::fromUtf8("btnHistory"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnHistory->sizePolicy().hasHeightForWidth());
        btnHistory->setSizePolicy(sizePolicy);
        btnHistory->setMinimumSize(QSize(45, 45));
        btnHistory->setMaximumSize(QSize(16777215, 45));
        btnHistory->setStyleSheet(QString::fromUtf8("/* History button */\n"
"QPushButton {\n"
"	border: 0;\n"
"	padding: 10px;\n"
"    background-color: #3A4353;\n"
"    outline: none;\n"
"    font-size: 18pt;\n"
"    color: #17b978;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #4a515f;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #5C6576;\n"
"}"));

        gridLayout->addWidget(btnHistory, 0, 0, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        fixedHistoryLabel = new QLabel(centralwidget);
        fixedHistoryLabel->setObjectName(QString::fromUtf8("fixedHistoryLabel"));
        fixedHistoryLabel->setEnabled(true);
        fixedHistoryLabel->setMinimumSize(QSize(0, 45));
        fixedHistoryLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font-size: 16pt;\n"
"	color: #fafaf6;\n"
"	qproperty-alignment: 'AlignVCenter | AlignLeft';\n"
"	border-bottom: 3px solid #17b978;\n"
"}"));

        horizontalLayout->addWidget(fixedHistoryLabel);

        fixedHistoryClear = new QPushButton(centralwidget);
        fixedHistoryClear->setObjectName(QString::fromUtf8("fixedHistoryClear"));
        fixedHistoryClear->setEnabled(false);
        fixedHistoryClear->setMinimumSize(QSize(45, 45));
        fixedHistoryClear->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 0;\n"
"    background-color: #3A4353;\n"
"    outline: none;\n"
"    font-size: 18pt;\n"
"    color: #C35B52;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #4a515f;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #5C6576;\n"
"}"));

        horizontalLayout->addWidget(fixedHistoryClear);


        gridLayout->addLayout(horizontalLayout, 5, 0, 1, 2);

        buttons = new QWidget(centralwidget);
        buttons->setObjectName(QString::fromUtf8("buttons"));
        btnGrid = new QGridLayout(buttons);
        btnGrid->setSpacing(3);
        btnGrid->setObjectName(QString::fromUtf8("btnGrid"));
        btnGrid->setContentsMargins(1, 1, 1, 1);
        btnChangeSign = new QPushButton(buttons);
        btnChangeSign->setObjectName(QString::fromUtf8("btnChangeSign"));
        btnChangeSign->setMinimumSize(QSize(70, 70));
        btnChangeSign->setStyleSheet(QString::fromUtf8("/* Numbers */\n"
"QPushButton {\n"
"	border: 0;\n"
"    background-color: #3A4353;\n"
"    outline: none;\n"
"    font-size: 18pt;\n"
"    color: #fafaf6;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #4a515f;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #5C6576;\n"
"}"));

        btnGrid->addWidget(btnChangeSign, 6, 0, 1, 1);

        btnDecimal = new QPushButton(buttons);
        btnDecimal->setObjectName(QString::fromUtf8("btnDecimal"));
        btnDecimal->setMinimumSize(QSize(70, 70));
        btnDecimal->setStyleSheet(QString::fromUtf8("/* Numbers */\n"
"QPushButton {\n"
"	border: 0;\n"
"    background-color: #3A4353;\n"
"    outline: none;\n"
"    font-size: 18pt;\n"
"    color: #fafaf6;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #4a515f;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #5C6576;\n"
"}"));

        btnGrid->addWidget(btnDecimal, 6, 2, 1, 1);

        btn1 = new QPushButton(buttons);
        btn1->setObjectName(QString::fromUtf8("btn1"));
        btn1->setMinimumSize(QSize(70, 70));
        btn1->setStyleSheet(QString::fromUtf8("/* Numbers */\n"
"QPushButton {\n"
"	border: 0;\n"
"    background-color: #3A4353;\n"
"    outline: none;\n"
"    font-size: 18pt;\n"
"    color: #fafaf6;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #4a515f;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #5C6576;\n"
"}"));

        btnGrid->addWidget(btn1, 4, 0, 1, 1);

        btn5 = new QPushButton(buttons);
        btn5->setObjectName(QString::fromUtf8("btn5"));
        btn5->setMinimumSize(QSize(70, 70));
        btn5->setStyleSheet(QString::fromUtf8("/* Numbers */\n"
"QPushButton {\n"
"	border: 0;\n"
"    background-color: #3A4353;\n"
"    outline: none;\n"
"    font-size: 18pt;\n"
"    color: #fafaf6;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #4a515f;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #5C6576;\n"
"}"));

        btnGrid->addWidget(btn5, 3, 1, 1, 1);

        btnDivide = new QPushButton(buttons);
        btnDivide->setObjectName(QString::fromUtf8("btnDivide"));
        btnDivide->setMinimumSize(QSize(70, 70));
        btnDivide->setStyleSheet(QString::fromUtf8("/* Modifiers */\n"
"QPushButton {\n"
"	border: 0;\n"
"    background-color: #3A4353;\n"
"    outline: none;\n"
"    font-size: 18pt;\n"
"    color: #717171;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #4a515f;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #5C6576;\n"
"}"));
        btnDivide->setCheckable(false);

        btnGrid->addWidget(btnDivide, 1, 3, 1, 1);

        btn4 = new QPushButton(buttons);
        btn4->setObjectName(QString::fromUtf8("btn4"));
        btn4->setMinimumSize(QSize(70, 70));
        btn4->setStyleSheet(QString::fromUtf8("/* Numbers */\n"
"QPushButton {\n"
"	border: 0;\n"
"    background-color: #3A4353;\n"
"    outline: none;\n"
"    font-size: 18pt;\n"
"    color: #fafaf6;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #4a515f;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #5C6576;\n"
"}"));

        btnGrid->addWidget(btn4, 3, 0, 1, 1);

        btn9 = new QPushButton(buttons);
        btn9->setObjectName(QString::fromUtf8("btn9"));
        btn9->setMinimumSize(QSize(70, 70));
        btn9->setStyleSheet(QString::fromUtf8("/* Numbers */\n"
"QPushButton {\n"
"	border: 0;\n"
"    background-color: #3A4353;\n"
"    outline: none;\n"
"    font-size: 18pt;\n"
"    color: #fafaf6;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #4a515f;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #5C6576;\n"
"}"));

        btnGrid->addWidget(btn9, 2, 2, 1, 1);

        btn6 = new QPushButton(buttons);
        btn6->setObjectName(QString::fromUtf8("btn6"));
        btn6->setMinimumSize(QSize(70, 70));
        btn6->setStyleSheet(QString::fromUtf8("/* Numbers */\n"
"QPushButton {\n"
"	border: 0;\n"
"    background-color: #3A4353;\n"
"    outline: none;\n"
"    font-size: 18pt;\n"
"    color: #fafaf6;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #4a515f;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #5C6576;\n"
"}"));

        btnGrid->addWidget(btn6, 3, 2, 1, 1);

        btn3 = new QPushButton(buttons);
        btn3->setObjectName(QString::fromUtf8("btn3"));
        btn3->setMinimumSize(QSize(70, 70));
        btn3->setStyleSheet(QString::fromUtf8("/* Numbers */\n"
"QPushButton {\n"
"	border: 0;\n"
"    background-color: #3A4353;\n"
"    outline: none;\n"
"    font-size: 18pt;\n"
"    color: #fafaf6;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #4a515f;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #5C6576;\n"
"}"));

        btnGrid->addWidget(btn3, 4, 2, 1, 1);

        btnBackspace = new QPushButton(buttons);
        btnBackspace->setObjectName(QString::fromUtf8("btnBackspace"));
        btnBackspace->setMinimumSize(QSize(70, 70));
        btnBackspace->setStyleSheet(QString::fromUtf8("/* Modifiers */\n"
"QPushButton {\n"
"	border: 0;\n"
"    background-color: #3A4353;\n"
"    outline: none;\n"
"    font-size: 18pt;\n"
"    color: #717171;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #4a515f;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #5C6576;\n"
"}"));

        btnGrid->addWidget(btnBackspace, 1, 1, 1, 1);

        btnEquals = new QPushButton(buttons);
        btnEquals->setObjectName(QString::fromUtf8("btnEquals"));
        btnEquals->setMinimumSize(QSize(70, 70));
        btnEquals->setStyleSheet(QString::fromUtf8("/* Modifiers */\n"
"QPushButton {\n"
"	border: 0;\n"
"    background-color: #3A4353;\n"
"    outline: none;\n"
"    font-size: 18pt;\n"
"    color: #717171;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #4a515f;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #5C6576;\n"
"}"));

        btnGrid->addWidget(btnEquals, 6, 3, 1, 1);

        btn7 = new QPushButton(buttons);
        btn7->setObjectName(QString::fromUtf8("btn7"));
        btn7->setMinimumSize(QSize(70, 70));
        btn7->setStyleSheet(QString::fromUtf8("/* Numbers */\n"
"QPushButton {\n"
"	border: 0;\n"
"    background-color: #3A4353;\n"
"    outline: none;\n"
"    font-size: 18pt;\n"
"    color: #fafaf6;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #4a515f;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #5C6576;\n"
"}"));

        btnGrid->addWidget(btn7, 2, 0, 1, 1);

        btnSubtract = new QPushButton(buttons);
        btnSubtract->setObjectName(QString::fromUtf8("btnSubtract"));
        btnSubtract->setMinimumSize(QSize(70, 70));
        btnSubtract->setStyleSheet(QString::fromUtf8("/* Modifiers */\n"
"QPushButton {\n"
"	border: 0;\n"
"    background-color: #3A4353;\n"
"    outline: none;\n"
"    font-size: 18pt;\n"
"    color: #717171;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #4a515f;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #5C6576;\n"
"}"));
        btnSubtract->setCheckable(false);

        btnGrid->addWidget(btnSubtract, 3, 3, 1, 1);

        btn8 = new QPushButton(buttons);
        btn8->setObjectName(QString::fromUtf8("btn8"));
        btn8->setMinimumSize(QSize(70, 70));
        btn8->setStyleSheet(QString::fromUtf8("/* Numbers */\n"
"QPushButton {\n"
"	border: 0;\n"
"    background-color: #3A4353;\n"
"    outline: none;\n"
"    font-size: 18pt;\n"
"    color: #fafaf6;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #4a515f;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #5C6576;\n"
"}"));

        btnGrid->addWidget(btn8, 2, 1, 1, 1);

        btnClear = new QPushButton(buttons);
        btnClear->setObjectName(QString::fromUtf8("btnClear"));
        btnClear->setMinimumSize(QSize(70, 70));
        btnClear->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 0;\n"
"    background-color: #3A4353;\n"
"    outline: none;\n"
"    font-size: 18pt;\n"
"    color: #C35B52;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #4a515f;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #5C6576;\n"
"}"));

        btnGrid->addWidget(btnClear, 1, 0, 1, 1);

        btnSqrt = new QPushButton(buttons);
        btnSqrt->setObjectName(QString::fromUtf8("btnSqrt"));
        btnSqrt->setMinimumSize(QSize(70, 70));
        btnSqrt->setStyleSheet(QString::fromUtf8("/* Modifiers */\n"
"QPushButton {\n"
"	border: 0;\n"
"    background-color: #3A4353;\n"
"    outline: none;\n"
"    font-size: 18pt;\n"
"    color: #717171;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #4a515f;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #5C6576;\n"
"}"));

        btnGrid->addWidget(btnSqrt, 1, 2, 1, 1);

        btnMultiply = new QPushButton(buttons);
        btnMultiply->setObjectName(QString::fromUtf8("btnMultiply"));
        btnMultiply->setMinimumSize(QSize(70, 70));
        btnMultiply->setStyleSheet(QString::fromUtf8("/* Modifiers */\n"
"QPushButton {\n"
"	border: 0;\n"
"    background-color: #3A4353;\n"
"    outline: none;\n"
"    font-size: 18pt;\n"
"    color: #717171;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #4a515f;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #5C6576;\n"
"}"));
        btnMultiply->setCheckable(false);

        btnGrid->addWidget(btnMultiply, 2, 3, 1, 1);

        btn2 = new QPushButton(buttons);
        btn2->setObjectName(QString::fromUtf8("btn2"));
        btn2->setMinimumSize(QSize(70, 70));
        btn2->setStyleSheet(QString::fromUtf8("/* Numbers */\n"
"QPushButton {\n"
"	border: 0;\n"
"    background-color: #3A4353;\n"
"    outline: none;\n"
"    font-size: 18pt;\n"
"    color: #fafaf6;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #4a515f;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #5C6576;\n"
"}"));

        btnGrid->addWidget(btn2, 4, 1, 1, 1);

        btn0 = new QPushButton(buttons);
        btn0->setObjectName(QString::fromUtf8("btn0"));
        btn0->setMinimumSize(QSize(70, 70));
        btn0->setStyleSheet(QString::fromUtf8("/* Numbers */\n"
"QPushButton {\n"
"	border: 0;\n"
"    background-color: #3A4353;\n"
"    outline: none;\n"
"    font-size: 18pt;\n"
"    color: #fafaf6;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #4a515f;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #5C6576;\n"
"}"));

        btnGrid->addWidget(btn0, 6, 1, 1, 1);

        btnAdd = new QPushButton(buttons);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));
        btnAdd->setMinimumSize(QSize(70, 70));
        btnAdd->setStyleSheet(QString::fromUtf8("/* Modifiers */\n"
"QPushButton {\n"
"	border: 0;\n"
"    background-color: #3A4353;\n"
"    outline: none;\n"
"    font-size: 18pt;\n"
"    color: #717171;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #4a515f;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #5C6576;\n"
"}"));
        btnAdd->setCheckable(false);

        btnGrid->addWidget(btnAdd, 4, 3, 1, 1);


        gridLayout->addWidget(buttons, 4, 0, 1, 2);

        displayWrapper = new QVBoxLayout();
        displayWrapper->setSpacing(0);
        displayWrapper->setObjectName(QString::fromUtf8("displayWrapper"));
        displayWrapper->setContentsMargins(1, 1, 1, 1);
        latestCalculation = new QTextBrowser(centralwidget);
        latestCalculation->setObjectName(QString::fromUtf8("latestCalculation"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(latestCalculation->sizePolicy().hasHeightForWidth());
        latestCalculation->setSizePolicy(sizePolicy1);
        latestCalculation->setMinimumSize(QSize(0, 50));
        latestCalculation->setStyleSheet(QString::fromUtf8("QTextBrowser {\n"
"	font-size: 14pt;\n"
"	color: #717171;\n"
"	border: 1px solid gray;\n"
"	border-bottom: none;\n"
"}"));
        latestCalculation->setInputMethodHints(Qt::ImhNone);

        displayWrapper->addWidget(latestCalculation);

        display = new QLabel(centralwidget);
        display->setObjectName(QString::fromUtf8("display"));
        display->setMinimumSize(QSize(0, 100));
        display->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font-size: 20pt;\n"
"	color: #fafaf6;\n"
"	qproperty-alignment: 'AlignVCenter | AlignRight';\n"
"	border: 1px solid gray;\n"
"	border-top: none;\n"
"}"));
        display->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        displayWrapper->addWidget(display);


        gridLayout->addLayout(displayWrapper, 3, 0, 1, 2);

        fixedHistoryBrowser = new QTextEdit(centralwidget);
        fixedHistoryBrowser->setObjectName(QString::fromUtf8("fixedHistoryBrowser"));
        sizePolicy.setHeightForWidth(fixedHistoryBrowser->sizePolicy().hasHeightForWidth());
        fixedHistoryBrowser->setSizePolicy(sizePolicy);
        fixedHistoryBrowser->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"	border: 0;\n"
"    background-color: #3A4353;\n"
"}"));
        fixedHistoryBrowser->setReadOnly(true);

        gridLayout->addWidget(fixedHistoryBrowser, 8, 0, 1, 2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        historyLabelWrapper = new QHBoxLayout();
        historyLabelWrapper->setObjectName(QString::fromUtf8("historyLabelWrapper"));
        historyLabel = new QLabel(centralwidget);
        historyLabel->setObjectName(QString::fromUtf8("historyLabel"));
        historyLabel->setEnabled(true);
        sizePolicy1.setHeightForWidth(historyLabel->sizePolicy().hasHeightForWidth());
        historyLabel->setSizePolicy(sizePolicy1);
        historyLabel->setMinimumSize(QSize(0, 45));
        historyLabel->setMaximumSize(QSize(16777215, 16777215));
        historyLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font-size: 18pt;\n"
"	color: #fafaf6;\n"
"	qproperty-alignment: 'AlignVCenter | AlignCenter';\n"
"	border-bottom: 3px solid #17b978;\n"
"}"));

        historyLabelWrapper->addWidget(historyLabel);

        historyClear = new QPushButton(centralwidget);
        historyClear->setObjectName(QString::fromUtf8("historyClear"));
        historyClear->setEnabled(false);
        sizePolicy1.setHeightForWidth(historyClear->sizePolicy().hasHeightForWidth());
        historyClear->setSizePolicy(sizePolicy1);
        historyClear->setMinimumSize(QSize(45, 45));
        historyClear->setMaximumSize(QSize(16777215, 16777215));
        historyClear->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 0;\n"
"    background-color: #3A4353;\n"
"    outline: none;\n"
"    font-size: 18pt;\n"
"    color: #C35B52;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #4a515f;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #5C6576;\n"
"}"));

        historyLabelWrapper->addWidget(historyClear);


        verticalLayout->addLayout(historyLabelWrapper);

        historyBrowser = new QTextEdit(centralwidget);
        historyBrowser->setObjectName(QString::fromUtf8("historyBrowser"));
        sizePolicy.setHeightForWidth(historyBrowser->sizePolicy().hasHeightForWidth());
        historyBrowser->setSizePolicy(sizePolicy);
        historyBrowser->setMaximumSize(QSize(300, 16777215));
        historyBrowser->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"	border: 0;\n"
"    background-color: #3A4353;\n"
"}"));
        historyBrowser->setReadOnly(true);

        verticalLayout->addWidget(historyBrowser);


        gridLayout->addLayout(verticalLayout, 3, 2, 2, 1);

        Canonicalc->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Canonicalc);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 442, 20));
        Canonicalc->setMenuBar(menubar);

        retranslateUi(Canonicalc);

        QMetaObject::connectSlotsByName(Canonicalc);
    } // setupUi

    void retranslateUi(QMainWindow *Canonicalc)
    {
        Canonicalc->setWindowTitle(QCoreApplication::translate("Canonicalc", "Canonicalc", nullptr));
        btnHistory->setText(QCoreApplication::translate("Canonicalc", "History", nullptr));
        fixedHistoryLabel->setText(QCoreApplication::translate("Canonicalc", "History", nullptr));
        fixedHistoryClear->setText(QCoreApplication::translate("Canonicalc", "C", nullptr));
        btnChangeSign->setText(QCoreApplication::translate("Canonicalc", "+ / -", nullptr));
        btnDecimal->setText(QCoreApplication::translate("Canonicalc", ".", nullptr));
        btn1->setText(QCoreApplication::translate("Canonicalc", "1", nullptr));
        btn5->setText(QCoreApplication::translate("Canonicalc", "5", nullptr));
        btnDivide->setText(QCoreApplication::translate("Canonicalc", "/", nullptr));
        btn4->setText(QCoreApplication::translate("Canonicalc", "4", nullptr));
        btn9->setText(QCoreApplication::translate("Canonicalc", "9", nullptr));
        btn6->setText(QCoreApplication::translate("Canonicalc", "6", nullptr));
        btn3->setText(QCoreApplication::translate("Canonicalc", "3", nullptr));
        btnBackspace->setText(QCoreApplication::translate("Canonicalc", "<", nullptr));
        btnEquals->setText(QCoreApplication::translate("Canonicalc", "=", nullptr));
        btn7->setText(QCoreApplication::translate("Canonicalc", "7", nullptr));
        btnSubtract->setText(QCoreApplication::translate("Canonicalc", "-", nullptr));
        btn8->setText(QCoreApplication::translate("Canonicalc", "8", nullptr));
        btnClear->setText(QCoreApplication::translate("Canonicalc", "C", nullptr));
        btnSqrt->setText(QCoreApplication::translate("Canonicalc", "\342\210\232", nullptr));
        btnMultiply->setText(QCoreApplication::translate("Canonicalc", "X", nullptr));
        btn2->setText(QCoreApplication::translate("Canonicalc", "2", nullptr));
        btn0->setText(QCoreApplication::translate("Canonicalc", "0", nullptr));
        btnAdd->setText(QCoreApplication::translate("Canonicalc", "+", nullptr));
        latestCalculation->setHtml(QCoreApplication::translate("Canonicalc", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:14pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"right\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        display->setText(QCoreApplication::translate("Canonicalc", "0", nullptr));
        historyLabel->setText(QCoreApplication::translate("Canonicalc", "History", nullptr));
        historyClear->setText(QCoreApplication::translate("Canonicalc", "C", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Canonicalc: public Ui_Canonicalc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CANONICALC_H
