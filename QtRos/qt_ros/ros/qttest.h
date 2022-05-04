/**
 * @file  qttest.h
 * @brief UI对应处理
 * @details 包含程序框架、线程入口等
 * @author  emotionsky
 * @date    2022-5-4
 * @version V1.0
 * @copyright  Copyright (c) 2050
 */
#ifndef QTTEST_H
#define QTTEST_H

#include <QMainWindow>
#include <QThread>
#include <ros/ros.h>
#include <std_msgs/Int16.h>
#include "rosthread.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class QtTest;
}
QT_END_NAMESPACE

class QtTest : public QMainWindow
{
    Q_OBJECT

public:
    QtTest(QWidget *parent = nullptr);
    ~QtTest();

signals:
    void StartSignal();

private slots:
    void on_pushButton_clicked();
    void OnRecvDataSlots(int data);
    void OnCloseSlot();

private:
    Ui::QtTest *ui;
    QThread *m_pQThread;
    RosThread *m_pRosThread;
};
#endif // QTTEST_H
