/**
 * @file  mythread.cpp
 * @brief 线程处理类
 * @details 线程的基本实现
 * @author  emotionsky
 * @date    2022-5-4
 * @version V1.0
 * @copyright  Copyright (c) 2050
 */
#include "mythread.h"
#include <QThread>
#include <QDebug>

MyThread::MyThread(QObject *parent) : QObject(parent)
{
    m_bIsRunning = false;
}

void MyThread::Run()
{
    while (m_bIsRunning)
    {
        QThread::sleep(1);
        emit TimeoutSignal();
        qDebug() << "子线程ID = " << QThread::currentThreadId();
    }
}

void MyThread::Start()
{
    m_bIsRunning = true;
}

void MyThread::Stop()
{
    m_bIsRunning = false;
}

bool MyThread::GetRunningFlag()
{
    return m_bIsRunning;
}
