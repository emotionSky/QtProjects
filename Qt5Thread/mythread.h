/**
 * @file  mythread.h
 * @brief 线程处理类
 * @details 线程的基本实现
 * @author  emotionsky
 * @date    2022-5-4
 * @version V1.0
 * @copyright  Copyright (c) 2050
 */
#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>

class MyThread : public QObject
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = nullptr);
    void Run();
    void Start();
    void Stop();
    bool GetRunningFlag();

signals:
    void TimeoutSignal();

private:
    bool m_bIsRunning;
};

#endif // MYTHREAD_H
