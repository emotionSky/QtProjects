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
