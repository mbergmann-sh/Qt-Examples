#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QMessageBox>
#include <QActionGroup>
#include <QList>

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

private:
    Ui::MainWindow *ui;

protected:
    void closeEvent(QCloseEvent *event) override;       // Catch QCloseEvent, alowing user-defined action on close()
private slots:
    void on_actionShow_Output_triggered();
    void on_actionHide_Output_triggered();
    void on_actionAbout_triggered();
    void on_actionAbout_Qt_triggered();
};
#endif // MAINWINDOW_H
