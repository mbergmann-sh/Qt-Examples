/*
 * Project:     Micha B.'s Qt examples
 * Sub-Project: procDemo
 * Purpose:     Explains how to get multiple return values from
 *              a QDialog's Widgets and how to display them in QMainWindow
 * File:        mainwindow.cpp
 * Version:     1.0.6
 * Date:        08/31/2025
 * Author:      Michael Bergmann
 * Compatibility:  Qt5 / Qt6
 */
#include "mainwindow.h"
#include "build/Desktop_Qt_6_9_2_special-Release/ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cmd = new QProcess(this);
    cmd->setProcessChannelMode(QProcess::MergedChannels);
    //button clicks:
    connect(ui->btnSavePrefs, SIGNAL (clicked()), this, SLOT (savePrefs()));
    connect(ui->btnRun, SIGNAL (clicked()), this, SLOT (runCommand()));
    // process has some data to read
    connect(cmd, SIGNAL (readyRead()), this, SLOT (readCommand()));
    //process finished
    connect(cmd, SIGNAL (finished(int, QProcess::ExitStatus)), this, SLOT (stopCommand(int, QProcess::ExitStatus)));

    // look for existing prefs file:
    getPrefs();

    // Show source file in QTextBrowser
    showFile();
}

MainWindow::~MainWindow()
{
    delete ui;
    //cmd->close(); //? how to do it right?
    cmd->terminate();
    delete cmd;
}


void MainWindow::runCommand()
{
    QString command;
    QStringList arguments;

    // Empty output widget
    ui->output->clear();
    // Give message about started process:
    ui->output->append("Run process...\nCompiler started:\n");

    // select compiler to use:
    if(ui->comboBoxCompiler->currentIndex() == 0)
    {
        command = p_VCexe;
        arguments << "-O2" << "-size" << "-v" << p_FILEexe << "-lamiga" << "-o" << "test_vc ";
    }
    else
    {
        command = p_GCCexe;
        arguments << "-Wall" << "-O2" << "-s" << "-noixemul" << p_FILEexe << "-lamiga" << "-o" << "test_gcc ";
    }

    // fire up our process:
    cmd->start(command, arguments);
}

void MainWindow::readCommand(){
    ui->output->append(cmd->readAll()); //output is QTextBrowser
}
void MainWindow::stopCommand(int exitCode, QProcess::ExitStatus exitStatus){
    ui->output->append(cmd->readAll());
    ui->output->append("cmd finished");
    ui->output->append(QString::number(exitCode));
    qDebug() << "exitCode: " << QString::number(exitCode);
    if(QString::number(exitCode) == "0")
    {
        ui->statusBar->showMessage(tr("File compiled."));
    }
    else {
        ui->statusBar->showMessage(tr("There where errors!"));
    }
}

void MainWindow::error(QProcess::ProcessError error)
{
       qDebug() << "Error" << error;
}

void MainWindow::stateChanged(QProcess::ProcessState state)
{
    qDebug() << "Process::stateChanged" << state;
}

void MainWindow::on_btnGetVC_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Path to vc"), nullptr,
                                                    tr("All files (*)"));
    ui->leVCpath->setText(fileName);
    p_VCexe = fileName;
}

void MainWindow::on_btnGetGCC_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Path to vc"), nullptr,
                                                    tr("All files (*)"));
    ui->leGCCpath->setText(fileName);
    p_GCCexe = fileName;
}

void MainWindow::on_btnGetFile_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Path to vc"), nullptr,
                                                    tr("All files (*)"));
    ui->leFilepath->setText(fileName);
    p_FILEexe = fileName;

    // Show file in Window!
    showFile();
}

void MainWindow::savePrefs()
{
    qDebug() <<"savePrefs() called...";

    // Check if all prefs fields are filled:
    if(!(ui->leVCpath->text().isEmpty()) || (ui->leGCCpath->text().isEmpty()) || (ui->leFilepath->text().isEmpty()))
    {
        // construct prefs contents:
        myPrefs << ui->leVCpath->text() << ui->leGCCpath->text() << ui->leFilepath->text();
        QString str = myPrefs.join(", ");

        // construct filepath and -name to save to:
        QString savename = QDir::homePath();
        savename.append(QDir::separator());
        savename.append("processdemo.prefs");
        qDebug() << "Home Folder: " << savename;

        // stream prefsfile to disk:
        QFile file(savename);
        if(file.open(QIODevice::ReadWrite))
        {
            QTextStream stream(&file);
            stream << str << Qt::endl;

            file.close();
            qDebug() << "Prefs saved.";
        }
        else
        {
            qDebug() << "ERROR while saving prefs!";
        }
    }
    else
    {
        (void) QMessageBox::warning(this, tr("Process DEMO"),
                             tr("Please populate ALL pathes!\n"
                             "This app will not work if parameters are missing."),
                QMessageBox::Ok);
    }

}

void MainWindow::getPrefs()
{
    QString line;
    QStringList fields;

    // construct filepath and -name to load from:
    QString loadname = QDir::homePath();
    loadname.append(QDir::separator());
    loadname.append("processdemo.prefs");

    // stream prefsfile to disk:
    QFile file(loadname);
    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream in(&file);
        while(!in.atEnd())
        {
            line = in.readLine();
            fields = line.split(", ");
        }
        file.close();

        // write back values to the interface:
        ui->leVCpath->setText(fields[0]);
        p_VCexe = fields[0];
        ui->leGCCpath->setText(fields[1]);
        p_GCCexe = fields[1];
        ui->leFilepath->setText(fields[2]);
        p_FILEexe = fields[2];
    }
    else
    {
        qDebug() << "ERROR while loading prefs!";
        (void) QMessageBox::warning(this, tr("Process DEMO"),
                             tr("There are no usable prefs to load!\n"
                             "Please fill in ALL pathes and save prefs first."),
                QMessageBox::Ok);
    }
}

void MainWindow::showFile()
{
    QFile file(p_FILEexe);
    QString line;

    if(!(file.exists()))
    {
        qDebug() << "File not found!";
    }
    else
    {
        qDebug() << "Now opening " << p_FILEexe;

        ui->output->clear();
        if(file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream stream(&file);
            while(!(stream.atEnd()))
            {
                line = stream.readLine();
                ui->output->setText(ui->output->toPlainText() + line + "\n");
            }
            file.close();
        }
    }


}


void MainWindow::on_actionRun_Compiler_triggered()
{
    runCommand();
}


void MainWindow::on_actionSave_Prefs_triggered()
{
    savePrefs();
}


void MainWindow::on_btnSavePrefs_clicked()
{
    savePrefs();
}


void MainWindow::on_actionAbout_triggered()
{
    QString myMessage = "<b>processDemo v1.0</b><br>" \
        "<br>This program demonstrates how to use a<br>" \
        "QProcess in order to launch a shell task and<br>" \
        " display its output in a QTextEdit.<br><br>" \
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

// Catch CloseEvent and react according to user's demand...
void MainWindow::closeEvent( QCloseEvent *event )
{
    int result = 1;

    QMessageBox exitBox;
    exitBox.setIcon(QMessageBox::Icon::Question);
    exitBox.setWindowTitle(tr("About to quit"));
    exitBox.setText(tr("Do you really want to quit processDemo v1.0?"));
    exitBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
    exitBox.setDefaultButton(QMessageBox::No);

    // Open quitting dialog
    result = exitBox.exec();

    // React on user input:
    // Manage close-Event
    if (result == QMessageBox::Yes)
    {
        // Event must be accepted in order to close down!
        // Close the App:
        event->accept();
    }
    else if (result == QMessageBox::Cancel)
    {
        event->ignore();
    }
}

