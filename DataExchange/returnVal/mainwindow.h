/*
 * Project:     Micha B.'s Qt examples
 * Sub-Project: returnVal
 * Purpose:     Explains how to get multiple return values from
 *              a QDialog's Widgets and how to display them in QMainWindow
 * File:        mainwindow.h
 * Version:     1.0.6
 * Date:        08/31/2025
 * Author:      Michael Bergmann
 * Compatibility:  Qt5 / Qt6
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QCheckBox>
#include <QMessageBox>
#include <QCloseEvent>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionAbout_triggered();
    void on_actionAbout_Qt_triggered();
    void on_actionOpen_Dialog_triggered();

    void on_btnOpenDialog_clicked();

private:
    Ui::MainWindow *ui;
    QString m_text; // takes QDialog's QLineEdit value
    bool m_box;     // takes QDialog's QCheckBox value
};
#endif // MAINWINDOW_H
