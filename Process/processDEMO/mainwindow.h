/*
 * Project:     Micha B.'s Qt examples
 * Sub-Project: procDemo
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
#include <QMessageBox>
#include <QString>
#include <QStyle>
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QTextStream>
#include <QStatusBar>
#include <QLabel>
#include <QLCDNumber>
#include <QComboBox>
#include <QStatusTipEvent>
#include <QCloseEvent>
#include <QMouseEvent>
#include <QAction>
#include <QActionGroup>
#include <QActionEvent>
#include <QPoint>
#include <QProcess>

#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QProcess *cmd;
    QString p_VCexe;
    QString p_GCCexe;
    QString p_FILEexe;
    QStringList myPrefs;

signals:
    void proccessFinished(int exitCode, QProcess::ExitStatus status);

public slots:
    void runCommand();
    void readCommand();
    void stopCommand(int exitCode, QProcess::ExitStatus exitStatus);

//private or public?
private slots:
    void error(QProcess::ProcessError error);
    void stateChanged(QProcess::ProcessState state);

    void on_btnGetVC_clicked();
    void on_btnGetGCC_clicked();
    void on_btnGetFile_clicked();
    void savePrefs();
    void getPrefs();
    void showFile();
    void on_actionRun_Compiler_triggered();
    void on_actionSave_Prefs_triggered();
    void on_btnSavePrefs_clicked();
    void on_actionAbout_triggered();
    void on_actionAbout_Qt_triggered();

protected:
    void closeEvent(QCloseEvent *event) override;       // Catch QCloseEvent, alowing user-defined action on close()
};

#endif // MAINWINDOW_H
