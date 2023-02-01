/**
 * @file  worker.h
 * @brief 线程工作的处理类
 * @author  emotionsky
 * @email   bitdreamsky@126.com
 * @date    2023/02/01
 * @version V1.0.0
 * @copyright  Copyright (c), emotionsky, All rights reserved.
 */

#ifndef WORKER_H
#define WORKER_H

#include <QObject>

enum WorkResult
{
    CYCLE_RESULT = 0,
    EXIT_WORKER,
    PREPARE_ERROR,
};

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);
    virtual ~Worker();

    void SetRuning(bool bRun);
    void DoWork();

signals:
    void DoResult(int code);

private:
    bool m_bRunning;
};

#endif // WORKER_H
