/**
 * @file  worker.cpp
 * @brief 线程工作的处理类
 * @author  emotionsky
 * @email   bitdreamsky@126.com
 * @date    2023/02/01
 * @version V1.0.0
 * @copyright  Copyright (c), emotionsky, All rights reserved.
 */

#include "worker.h"
#include <QThread>

Worker::Worker(QObject *parent) : QObject(parent), m_bRunning(false)
{

}

Worker::~Worker()
{

}

void Worker::SetRuning(bool bRun)
{
    m_bRunning = bRun;
}

void Worker::DoWork()
{
    //这里进行一些线程处理的准备工作，可能需要进行一些数据的初始化等操作。
    //如果初始化失败，可以发送初始化失败的信号并返回
#if 0
    emit DoResult(PREPARE_ERROR);
    return;
#endif

    //线程的周期处理
    while (m_bRunning)
    {
        //这里使用休眠来表示处理任务
        QThread::sleep(1);
        emit DoResult(CYCLE_RESULT);
    }

    //最后的退出
    emit DoResult(EXIT_WORKER);
}
