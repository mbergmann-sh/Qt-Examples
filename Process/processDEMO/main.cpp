/*
 * Project:     Micha B.'s Qt examples
 * Sub-Project: procDemo
 * Purpose:     Explains how to get multiple return values from
 *              a QDialog's Widgets and how to display them in QMainWindow
 * File:        main.cpp
 * Version:     1.0.6
 * Date:        08/31/2025
 * Author:      Michael Bergmann
 * Compatibility:  Qt5 / Qt6
 */
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
