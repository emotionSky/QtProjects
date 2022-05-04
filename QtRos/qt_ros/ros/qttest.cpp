/**
 * @file  qttest.cpp
 * @brief UI对应处理
 * @details 包含程序框架、线程入口等
 * @author  emotionsky
 * @date    2022-5-4
 * @version V1.0
 * @copyright  Copyright (c) 2050
 */
#include "qttest.h"
#include "ui_qttest.h"

QtTest::QtTest(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::QtTest)
{
    ui->setupUi(this);
    m_pQThread = new QThread(this);
    m_pRosThread = new RosThread();
    m_pRosThread->moveToThread(m_pQThread);
    connect(m_pRosThread, &RosThread::RecvDataSignal, this, &QtTest::OnRecvDataSlots);
    connect(this, &QtTest::StartSignal, m_pRosThread, &RosThread::Run);
    connect(this, &QThread::destroyed, this, &QtTest::OnCloseSlot);

    m_pRosThread->Start();
    m_pQThread->start(); ///<启动了线程，但是还没有启动线程函数
    emit StartSignal();  ///<通过信号和槽的机制启动线程函数
}

QtTest::~QtTest()
{
    if (m_pRosThread)
    {
        delete m_pRosThread;
        m_pRosThread = nullptr;
    }
    delete ui;
}

void QtTest::on_pushButton_clicked()
{
    int data = ui->lineEdit->text().toInt();
    m_pRosThread->PublishNum(data);
}

void QtTest::OnRecvDataSlots(int data)
{
    ui->textEdit->append(QString::number(data));
}

void QtTest::OnCloseSlot()
{
    m_pQThread->quit(); ///<退出线程
    m_pQThread->wait(); ///<退出线程之后必须调用这个函数，进行一些数据的清理
}
