#include "mythread.h"
#include <QThread>
#include <QDebug>

MyThread::MyThread(QObject *parent) : QObject(parent)
{
    m_bIsRunning = true;
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
