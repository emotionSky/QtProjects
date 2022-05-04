/**
 * @file  mainwindow.cpp
 * @brief UI对应处理
 * @details 包含程序框架、线程入口等
 * @author  emotionsky
 * @date    2022-5-4
 * @version V1.0
 * @copyright  Copyright (c) 2050
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_pMyThread = new MyThread();
    m_pQThread = new QThread(this);        ///<这里如果制定了父对象，就不需要在析构函数进行释放，会自动释放的
    m_pMyThread->moveToThread(m_pQThread); ///<将自定义的线程加入到子线程中

    /**
     * connect()第五个参数的作用，连接方式：默认、队列、直接，
     * 第五个参数在多线程中才有意义。
     * 默认链接方式：
     * 1）多线程默认使用队列方式；
     * 2）单线程默认使用直接方式。
     * 队列方式：槽函数所在的线程和接收者在同一线程。
     * 直接方式：槽函数所在的线程和发送者在同一线程。
     */
    connect(m_pMyThread, &MyThread::TimeoutSignal, this, &MainWindow::OnTimeoutSlot);
    connect(this, &MainWindow::StartSignal, m_pMyThread, &MyThread::Run);
    connect(this, &QThread::destroyed, this, &MainWindow::OnCloseSlot);

    qDebug() << "主线程号： " << QThread::currentThreadId();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButtom_clicked()
{
    if (!m_pQThread->isRunning())
    {
        m_pMyThread->Start(); ///<设置了线程函数运行的标志位，还是没有启动线程函数
        m_pQThread->start();  ///<启动了线程，但是还没有启动线程函数
        emit StartSignal();   ///<通过信号和槽的机制启动线程函数
    }
}

void MainWindow::on_stopButtom_clicked()
{
    if (m_pQThread->isRunning())
    {
        m_pMyThread->Stop(); ///<设置标志位
        m_pQThread->quit();  ///<退出线程
        m_pQThread->wait();  ///<退出线程之后必须调用这个函数，进行一些数据的清理
    }
}

void MainWindow::OnTimeoutSlot()
{
    static int i = 0;
    ++i;
    ui->lcdNumber->display(i);
}

void MainWindow::OnCloseSlot()
{
    if (m_pQThread->isRunning())
    {
        m_pQThread->quit();  ///<退出线程
        m_pQThread->wait();  ///<退出线程之后必须调用这个函数，进行一些数据的清理
    }
}
