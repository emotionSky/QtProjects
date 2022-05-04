/**
 * @file  main.cpp
 * @brief 程序入口
 * @author  emotionsky
 * @date    2022-5-4
 * @version V1.0
 * @copyright  Copyright (c) 2050
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
