/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout;
    QAction *actionAbout_Qt;
    QAction *actionExit;
    QWidget *centralWidget;
    QGridLayout *gridLayout_4;
    QLabel *label;
    QLineEdit *lineEdit_Searchstring;
    QPushButton *btn_Clear;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QComboBox *comboBox;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_3;
    QLabel *label_4;
    QLCDNumber *lcdNumber_Line;
    QLabel *label_5;
    QLCDNumber *lcdNumber_Column;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLineEdit *lineEdit_Filepath;
    QGridLayout *gridLayout_2;
    QLabel *label_6;
    QLabel *label_MessageType;
    QLabel *label_7;
    QLabel *label_MessageNumber;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_GO;
    QMenuBar *menuBar;
    QMenu *menuProject;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(646, 318);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionAbout_Qt = new QAction(MainWindow);
        actionAbout_Qt->setObjectName(QString::fromUtf8("actionAbout_Qt"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_4 = new QGridLayout(centralWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_4->addWidget(label, 0, 0, 1, 1);

        lineEdit_Searchstring = new QLineEdit(centralWidget);
        lineEdit_Searchstring->setObjectName(QString::fromUtf8("lineEdit_Searchstring"));

        gridLayout_4->addWidget(lineEdit_Searchstring, 0, 1, 1, 1);

        btn_Clear = new QPushButton(centralWidget);
        btn_Clear->setObjectName(QString::fromUtf8("btn_Clear"));

        gridLayout_4->addWidget(btn_Clear, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(136, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 1, 1, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_4->addWidget(label_2, 1, 2, 1, 1);

        comboBox = new QComboBox(centralWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout_4->addWidget(comboBox, 1, 3, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_5 = new QGridLayout(groupBox);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_3->addWidget(label_4, 0, 0, 1, 1);

        lcdNumber_Line = new QLCDNumber(groupBox);
        lcdNumber_Line->setObjectName(QString::fromUtf8("lcdNumber_Line"));
        lcdNumber_Line->setMaximumSize(QSize(50, 16777215));

        gridLayout_3->addWidget(lcdNumber_Line, 0, 1, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_3->addWidget(label_5, 1, 0, 1, 1);

        lcdNumber_Column = new QLCDNumber(groupBox);
        lcdNumber_Column->setObjectName(QString::fromUtf8("lcdNumber_Column"));
        lcdNumber_Column->setMaximumSize(QSize(50, 16777215));

        gridLayout_3->addWidget(lcdNumber_Column, 1, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout_3, 2, 0, 2, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        lineEdit_Filepath = new QLineEdit(groupBox);
        lineEdit_Filepath->setObjectName(QString::fromUtf8("lineEdit_Filepath"));

        gridLayout->addWidget(lineEdit_Filepath, 0, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout, 1, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 0, 0, 1, 1);

        label_MessageType = new QLabel(groupBox);
        label_MessageType->setObjectName(QString::fromUtf8("label_MessageType"));

        gridLayout_2->addWidget(label_MessageType, 0, 1, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_2->addWidget(label_7, 1, 0, 1, 1);

        label_MessageNumber = new QLabel(groupBox);
        label_MessageNumber->setObjectName(QString::fromUtf8("label_MessageNumber"));

        gridLayout_2->addWidget(label_MessageNumber, 1, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout_2, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox, 2, 0, 1, 4);

        horizontalSpacer_2 = new QSpacerItem(229, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 3, 0, 1, 2);

        btn_GO = new QPushButton(centralWidget);
        btn_GO->setObjectName(QString::fromUtf8("btn_GO"));
        btn_GO->setAutoDefault(true);

        gridLayout_4->addWidget(btn_GO, 3, 3, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 646, 22));
        menuProject = new QMenu(menuBar);
        menuProject->setObjectName(QString::fromUtf8("menuProject"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuProject->menuAction());
        menuProject->addAction(actionAbout);
        menuProject->addAction(actionAbout_Qt);
        menuProject->addSeparator();
        menuProject->addAction(actionExit);

        retranslateUi(MainWindow);
        QObject::connect(actionExit, SIGNAL(triggered()), MainWindow, SLOT(close()));

        btn_GO->setDefault(true);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About...", nullptr));
#if QT_CONFIG(statustip)
        actionAbout->setStatusTip(QCoreApplication::translate("MainWindow", "Show information about this app...", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        actionAbout->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+H", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAbout_Qt->setText(QCoreApplication::translate("MainWindow", "About Qt...", nullptr));
#if QT_CONFIG(statustip)
        actionAbout_Qt->setStatusTip(QCoreApplication::translate("MainWindow", "Show information about Qt version...", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        actionAbout_Qt->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+H", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
#if QT_CONFIG(statustip)
        actionExit->setStatusTip(QCoreApplication::translate("MainWindow", "Quit this app!", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        actionExit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        label->setText(QCoreApplication::translate("MainWindow", "Search string: ", nullptr));
        lineEdit_Searchstring->setText(QCoreApplication::translate("MainWindow", "error 0 in line 25 of \"/home/bergmann/jumptest.c\": declaration expected'; ", nullptr));
#if QT_CONFIG(statustip)
        btn_Clear->setStatusTip(QCoreApplication::translate("MainWindow", "Clear input widget...", nullptr));
#endif // QT_CONFIG(statustip)
        btn_Clear->setText(QCoreApplication::translate("MainWindow", "&Clear", nullptr));
#if QT_CONFIG(shortcut)
        btn_Clear->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        label_2->setText(QCoreApplication::translate("MainWindow", "Compiler:", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "VBCC", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "GCC", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "G++", nullptr));

#if QT_CONFIG(statustip)
        comboBox->setStatusTip(QCoreApplication::translate("MainWindow", "Select C/C++ Compiler that causes the message...", nullptr));
#endif // QT_CONFIG(statustip)
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Matches", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Line:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Column:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "File:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Message type:", nullptr));
        label_MessageType->setText(QCoreApplication::translate("MainWindow", "not computed yet...", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Error number:", nullptr));
        label_MessageNumber->setText(QCoreApplication::translate("MainWindow", "not computed yet...", nullptr));
#if QT_CONFIG(statustip)
        btn_GO->setStatusTip(QCoreApplication::translate("MainWindow", "Parse an error message or warning...", nullptr));
#endif // QT_CONFIG(statustip)
        btn_GO->setText(QCoreApplication::translate("MainWindow", "&GO!", nullptr));
#if QT_CONFIG(shortcut)
        btn_GO->setShortcut(QCoreApplication::translate("MainWindow", "Shift+G", nullptr));
#endif // QT_CONFIG(shortcut)
        menuProject->setTitle(QCoreApplication::translate("MainWindow", "Project", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
