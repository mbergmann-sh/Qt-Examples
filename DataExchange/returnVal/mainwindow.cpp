/*
 * Project:     Micha B.'s Qt examples
 * Sub-Project: returnVal
 * Purpose:     Explains how to get multiple return values from
 *              a QDialog's Widgets and how to display them in QMainWindow
 * File:        mainwindow.cpp
 * Version:     1.0.6
 * Date:        08/31/2025
 * Author:      Michael Bergmann
 * Compatibility:  Qt5 / Qt6
 */
#include "mainwindow.h"
#include "returndialog.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAbout_triggered()
{
    QString myMessage = "<b>Qt GUI with arguments Example</b><br>" \
        "<br>This program shows you how to read and use<br>" \
        "multiple return values from a QDialog in MainWindow<br>" \
        "<br>Author: Michael Bergmann (09/2025)<br>" \
        "Email: <a href='mailto://mbergmann-sh@gmx.de'>  mbergmann-sh@gmx.de</a><br>" \
        "Website: <a href='https://mbergmann-sh.de'>https://mbergmann-sh.de</a><br>" \
        "GIT: <a href='https://github.com/mbergmann-sh'>https://github.com/mbergmann-sh</a><br>";
    QString aboutMessage = myMessage;
    QMessageBox::about(this,
                       "About this program...",
                       aboutMessage);
}


void MainWindow::on_actionAbout_Qt_triggered()
{
    QMessageBox::aboutQt(this);
}


void MainWindow::on_actionOpen_Dialog_triggered()
{
    returnDialog *dialog = new returnDialog;
    dialog->exec();
    if(dialog->result() == QDialog::Accepted)
    {
        qDebug() << "Accepted!";
        // Let's get QDialog's return values:
        m_text = dialog->textValue();
        m_box = dialog->boxValue();
        // Now set them values in QMainWindow:
        ui->leMainText->setText(m_text);
        ui->cbMainCheck->setChecked(m_box);

    }
    if(dialog->result() == QDialog::Rejected)
    {
        qDebug() << "Rejected!";
        ui->leMainText->setText("Dialog window was cancelled.");
    }
}


void MainWindow::on_btnOpenDialog_clicked()
{
    on_actionOpen_Dialog_triggered();
}

