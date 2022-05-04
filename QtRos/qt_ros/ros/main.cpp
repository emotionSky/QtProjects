/**
 * @file  main.cpp
 * @brief 程序入口
 * @author  emotionsky
 * @date    2022-5-4
 * @version V1.0
 * @copyright  Copyright (c) 2050
 */
#include "qttest.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "qt_ros_node");
    QApplication a(argc, argv); ///< 参照qt界面标准写法
    QtTest w;
    w.show();

    return a.exec();
}
