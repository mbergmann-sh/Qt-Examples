/*
 * Project:     Micha B.'s Qt examples
 * Sub-Project: returnVal
 * Purpose:     Explains how to get multiple return values from
 *              a QDialog's Widgets and how to display them in QMainWindow
 * File:        returndialog.cpp
 * Version:     1.0.6
 * Date:        08/31/2025
 * Author:      Michael Bergmann
 * Compatibility:  Qt5 / Qt6
 */
#include "returndialog.h"
#include "ui_returndialog.h"

returnDialog::returnDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::returnDialog)
{
    ui->setupUi(this);
}

returnDialog::~returnDialog()
{
    delete ui;
}

// Getter: QLineEdit
QString returnDialog::textValue()
{
    // Getter value will be examined by MainWindow!
    return ui->leDialogText->text();
}

// Getter: QCheckBox
bool returnDialog::boxValue()
{
    // Getter value will be examined by MainWindow!
    return ui->cbDialogCheck->isChecked();
}
