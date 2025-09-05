/*
 * Project:     Micha B.'s Qt examples
 * Sub-Project: regexDemo
 * Purpose:     Explains how to use regular expressions in Qt5/6
 * Version:     1.0.6
 * Date:        09/31/2025
 * Author:      Michael Bergmann
 * Compatibility:  Qt5 / Qt6
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QRegularExpressionMatchIterator>
#include <QRegularExpressionValidator>

#include <QDebug>

class QMainWindow;
class QComboBox;
class QLineEdit;
class QLabel;
class QButton;
class QLCDNumber;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btn_GO_clicked();
    void on_btn_Clear_clicked();
    void checkVBCC();
    void checkGCC();
    void resetOutput();

    void on_comboBox_currentIndexChanged(int index);

    void on_actionAbout_triggered();

    void on_actionAbout_Qt_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
