/*
 * Project:     Micha B.'s Qt examples
 * Sub-Project: returnVal
 * Purpose:     Explains how to get multiple return values from
 *              a QDialog's Widgets and how to display them in QMainWindow
 * File:        returndialog.h
 * Version:     1.0.6
 * Date:        08/31/2025
 * Author:      Michael Bergmann
 * Compatibility:  Qt5 / Qt6
 */
#ifndef RETURNDIALOG_H
#define RETURNDIALOG_H

#include <QDialog>

namespace Ui {
class returnDialog;
}

class returnDialog : public QDialog
{
    Q_OBJECT

public:
    explicit returnDialog(QWidget *parent = nullptr);
    ~returnDialog();

    // Getters for Dialog values
    QString textValue();
    bool boxValue();

private:
    Ui::returnDialog *ui;
};

#endif // RETURNDIALOG_H
