#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Mutually exclude menu entries: Show/Hide Output Widget
    QActionGroup* outputActionGroup = new QActionGroup(this);
    outputActionGroup->setExclusive(true);
    // Add actions to the group
    outputActionGroup->addAction(ui->actionShow_Output);
    outputActionGroup->addAction(ui->actionHide_Output);

    ui->splitter->setOpaqueResize(false);

    // Set initial state for menu 'project' -> hide output
    on_actionHide_Output_triggered();   // Output Widget (GroupBox) will be hidden at startup
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    event->accept();
    this->close();
}

void MainWindow::on_actionShow_Output_triggered()
{
    ui->groupBox->show();
    ui->statusbar->showMessage("Output widget is now shown to you!");
}


void MainWindow::on_actionHide_Output_triggered()
{
    ui->groupBox->hide();
    ui->statusbar->showMessage("Output widget is now hidden from you!");
}


void MainWindow::on_actionAbout_triggered()
{
    ui->statusbar->showMessage("'About' message is now shown to you!");
    QString myMessage = "<b>Collapse GUI v1.0</b><br>" \
        "<br>This program demonstrates how to show and" \
        "<br>hide parts of a GUI<br>" \
        "<br>Author: Michael Bergmann (09/2025)<br>" \
        "Email: <a href='mailto://mbergmann-sh@gmx.de'>  mbergmann-sh@gmx.de</a><br>" \
        "Website: <a href='https://mbergmann-sh.de'>https://mbergmann-sh.de</a><br>" \
        "GIT: <a href='https://github.com/mbergmann-sh'>https://github.com/mbergmann-sh</a><br>";

    QMessageBox::about(this,
                       "About this program...",
                       myMessage);
    ui->statusbar->clearMessage();
}


void MainWindow::on_actionAbout_Qt_triggered()
{
    ui->statusbar->showMessage("'About Qt' message is now shown to you!");
    QMessageBox::aboutQt(this);
    ui->statusbar->clearMessage();
}

