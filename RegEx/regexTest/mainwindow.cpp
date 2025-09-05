/*
 * Project:     Micha B.'s Qt examples
 * Sub-Project: regexDemo
 * Purpose:     Explains how to use regular expressions in Qt5/6
 * File:        mainwindow.cpp
 * Version:     1.0.6
 * Date:        09/31/2025
 * Author:      Michael Bergmann
 * Compatibility:  Qt5 / Qt6
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Compiler RegEX Error Line Finder");
    ui->centralWidget->activateWindow();
    ui->comboBox->setCurrentIndex(0);
    ui->lcdNumber_Column->setDisabled(true);
    ui->btn_GO->setFocus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_GO_clicked()
{
    resetOutput();
    switch(ui->comboBox->currentIndex())
    {
        case 0:
            checkVBCC();
            break;

        case 1:
        case 2:
            checkGCC();
            break;
    }    
}

void MainWindow::on_btn_Clear_clicked()
{    
    ui->lineEdit_Searchstring->clear();
    resetOutput();
    ui->lineEdit_Searchstring->setFocus();
}

void MainWindow::checkVBCC()
{
    QString search ="error 0 in line 25 of \"~/jumptest.c\": declaration expected'; ";
    QString re1="((?:[a-z][a-z]+))";	// Word 1
    QString re2=".*?";	//# Non-greedy match on filler
    QString re3="(?:[a-z][a-z]+)";	//# Uninteresting: word
    QString re4=".*?";	//# Non-greedy match on filler
    QString re5="((?:[a-z][a-z]+))";	//# Word 2
    QString re6=".*?";	//# Non-greedy match on filler
    QString re7="(\\d+)";	// # Integer Number 1
    QString re8=".*?";	//# Non-greedy match on filler
    QString re9="((?:\\/[\\w\\.\\-]+)+)";	//# Unix Path 1
    QStringList strlist;
    strlist << re1 << re2 << re3 << re4 << re5 << re6 << re7 << re8 << re9;
    QString reg = re1 + re2 + re3 + re4 + re5 + re6 + re7 + re8 + re9;

    ui->lcdNumber_Column->setDisabled(true);
    qDebug() << "Compiler selection index: " << ui->comboBox->currentIndex();
    qDebug() << "checkVBCC() called";

    QString str_to_search = ui->lineEdit_Searchstring->text();
    if(!(str_to_search.isEmpty()))
    {
        QRegularExpression rx_line("(\\d+)");                       // check for line (and column, if available)
        QRegularExpression rx_words("((?:\"[a-z][a-z]+\\.c)\")");   // check for ALL strings starting with \", containing .c, ending with \"
        QRegularExpression rx_file("((?:\\/[\\w\\.\\-]+)+)");       // unix path
        QRegularExpression rx_messagetype("(error)");               // check if error or warning


        QList<int> list;    // List to hold search results (integer values)
        QStringList list1;  // List to hold string-type results

        //
        // check if error or warning
        //
        QRegularExpressionMatchIterator i = rx_messagetype.globalMatch(str_to_search);
        while (i.hasNext())
        {
            QRegularExpressionMatch match = i.next();
            QString word = match.captured(1);
            list1 << word;
        }

        if(!(list1.isEmpty()))
        {
            if(list1[0] == "error")
            {
                ui->label_MessageType->setText("Error");
            }
            else
            {
                ui->label_MessageType->setText("unknown");
            }

            qDebug() << "List entries: " << list1 << "List count: " << list1.count();

        }
        else
        {
            ui->label_MessageType->setText("Warning");
            qDebug() << "No matches!";
        }

        //
        // check for simple filename
        //
        list1.clear();
        QRegularExpressionMatchIterator w = rx_words.globalMatch(str_to_search);
        while (w.hasNext())
        {
            QRegularExpressionMatch match = w.next();
            QString word = match.captured(1);
            list1 << word;
        }

        if(!(list1.isEmpty()))
        {
            qDebug() << "List entries: " << list1 << "List count: " << list1.count();
            ui->lineEdit_Filepath->setText(list1[0]);
        }
        else
            qDebug() << "no simple filename";


        //
        // check for unix path
        //
        list1.clear();
        QRegularExpressionMatchIterator f = rx_file.globalMatch(str_to_search);
        while (f.hasNext())
        {
            QRegularExpressionMatch match = f.next();
            QString word = match.captured(1);
            list1 << word;
        }

        if(!(list1.isEmpty()))
        {
            qDebug() << "List entries: " << list1 << "List count: " << list1.count();
            ui->lineEdit_Filepath->setText(list1[0]);
        }
        else
            qDebug() << "no unix path!";



        //
        // check for line and column
        //
        QRegularExpressionMatchIterator lc = rx_line.globalMatch(str_to_search);
        while (lc.hasNext())
        {
            QRegularExpressionMatch match = lc.next();
            QString word = match.captured(1);
            list << word.toInt();
        }

        if(!(list.isEmpty()))
        {
            int index = 0;
            qDebug() << "List entries: " << list << "List count: " << list.count();
            if(index <= list.count() -1)
                ui->label_MessageNumber->setText(QString::number(list[index]));

            ++index;

            if(index <= list.count() -1)
                ui->lcdNumber_Line->display(QString::number(list[index]));

        }
        else
            qDebug() << "WTF!";

    } // END str_to_search.isEmpty()
}

void MainWindow::checkGCC()
{
    ui->lcdNumber_Column->setDisabled(false);
    qDebug() << "Compiler selection index: " << ui->comboBox->currentIndex();
    qDebug() << "checkGCC() called";

    QString search ="error 0 in line 25 of \"~/jumptest.c\": declaration expected'; ";
    QString re1="((?:[a-z][a-z]+))";	// Word 1
    QString re2=".*?";	//# Non-greedy match on filler
    QString re3="(?:[a-z][a-z]+)";	//# Uninteresting: word
    QString re4=".*?";	//# Non-greedy match on filler
    QString re5="((?:[a-z][a-z]+))";	//# Word 2
    QString re6=".*?";	//# Non-greedy match on filler
    QString re7="(\\d+)";	// # Integer Number 1
    QString re8=".*?";	//# Non-greedy match on filler
    QString re9="((?:\\/[\\w\\.\\-]+)+)";	//# Unix Path 1
    QStringList strlist;
    strlist << re1 << re2 << re3 << re4 << re5 << re6 << re7 << re8 << re9;
    QString reg = re1 + re2 + re3 + re4 + re5 + re6 + re7 + re8 + re9;

    ui->lcdNumber_Column->setDisabled(true);
    qDebug() << "Compiler selection index: " << ui->comboBox->currentIndex();
    qDebug() << "checkVBCC() called";

    QString str_to_search = ui->lineEdit_Searchstring->text();
    if(!(str_to_search.isEmpty()))
    {
        QRegularExpression rx_line("(\\d+)");                       // check for line (and column, if available)
        QRegularExpression rx_words("((?:[a-z][a-z]+\\.c))");       // check for ALL strings containing .c
        QRegularExpression rx_file("((?:\\/[\\w\\.\\-]+)+)");       // unix path
        QRegularExpression rx_messagetype("(error)");               // check if error or warning


        QList<int> list;    // List to hold search results (integer values)
        QStringList list1;  // List to hold string-type results

        //
        // check if error or warning
        //
        QRegularExpressionMatchIterator i = rx_messagetype.globalMatch(str_to_search);
        while (i.hasNext())
        {
            QRegularExpressionMatch match = i.next();
            QString word = match.captured(1);
            list1 << word;
        }

        if(!(list1.isEmpty()))
        {
            if(list1[0] == "error")
            {
                ui->label_MessageType->setText("Error");
            }
            else
            {
                ui->label_MessageType->setText("Warning");
            }

            qDebug() << "List entries: " << list1 << "List count: " << list1.count();

        }
        else
        {
            ui->label_MessageType->setText("Warning");
            qDebug() << "No matches!";
        }

        //
        // check for simple filename
        //
        list1.clear();
        QRegularExpressionMatchIterator w = rx_words.globalMatch(str_to_search);
        while (w.hasNext())
        {
            QRegularExpressionMatch match = w.next();
            QString word = match.captured(1);
            list1 << word;
        }

        if(!(list1.isEmpty()))
        {
            qDebug() << "List entries: " << list1 << "List count: " << list1.count();
            ui->lineEdit_Filepath->setText(list1[0]);
        }
        else
            qDebug() << "WTF!";

        //
        // check for unix path
        //
        list1.clear();
        QRegularExpressionMatchIterator f = rx_file.globalMatch(str_to_search);
        while (f.hasNext())
        {
            QRegularExpressionMatch match = f.next();
            QString word = match.captured(1);
            list1 << word;
        }

        if(!(list1.isEmpty()))
        {
            qDebug() << "List entries: " << list1 << "List count: " << list1.count();
            ui->lineEdit_Filepath->setText(list1[0]);
        }
        else
            qDebug() << "WTF!";

        //
        // check for line and column
        //
        QRegularExpressionMatchIterator lc = rx_line.globalMatch(str_to_search);
        while (lc.hasNext())
        {
            QRegularExpressionMatch match = lc.next();
            QString word = match.captured(1);
            list << word.toInt();
        }

        if(!(list.isEmpty()))
        {
            int index = 0;
            qDebug() << "List entries: " << list << "List count: " << list.count();
            if(index <= list.count() -1)
            {
                ui->label_MessageNumber->setText("gcc/g++ is unaware of error numbers!");
                ui->lcdNumber_Line->display(QString::number(list[index]));
            }


            ++index;

            if(index <= list.count() -1)
                ui->lcdNumber_Column->display(QString::number(list[index]));

        }
        else
            qDebug() << "WTF!";

    } // END str_to_search.isEmpty()
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    qDebug() << "Index: " << index;
    resetOutput();
    switch(index)
    {
        case 0:
            ui->lineEdit_Searchstring->setText("error 0 in line 25 of \"~/jumptest.c\": declaration expected'; ");
            break;
        case 1:
            ui->lineEdit_Searchstring->setText("jumptest.c:38:9: error: expected expression before ')' token");
            break;
        case 2:
            ui->lineEdit_Searchstring->setText("jumptest.c:38:9: warning: expected expression before ')' token");
            break;
    }
}

//
// HELPER: reset all output
//
void MainWindow::resetOutput()
{
    ui->label_MessageType->setText("not computed yet..");
    ui->label_MessageNumber->setText("not computed yet..");
    ui->lineEdit_Filepath->clear();
    ui->lcdNumber_Column->display(0);
    ui->lcdNumber_Line->display(0);
    ui->btn_GO->setFocus();
}

void MainWindow::on_actionAbout_triggered()
{
    QString myMessage = "<b>regexDemo v1.0</b><br>" \
        "<br>This program demonstrates how to use<br>" \
        "regular expressions in Qt<br><br>" \
        "<br>Author: Michael Bergmann (09/2025)<br>" \
        "Email: <a href='mailto://mbergmann-sh@gmx.de'>  mbergmann-sh@gmx.de</a><br>" \
        "Website: <a href='https://mbergmann-sh.de'>https://mbergmann-sh.de</a><br>" \
        "GIT: <a href='https://github.com/mbergmann-sh'>https://github.com/mbergmann-sh</a><br>";

    QMessageBox::about(this,
                       "About this program...",
                       myMessage);
}


void MainWindow::on_actionAbout_Qt_triggered()
{
    QMessageBox::aboutQt(this);
}

