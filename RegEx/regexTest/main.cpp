/*
 * Project:     Micha B.'s Qt examples
 * Sub-Project: regexDemo
 * Purpose:     Explains how to use regular expressions in Qt5/6
 * File:        main.cpp
 * Version:     1.0.6
 * Date:        09/31/2025
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
