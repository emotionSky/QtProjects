#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), m_count(0)
{
    ui->setupUi(this);

    m_worker.moveToThread(&m_thread);

    /**
     * connect()第五个参数的作用，连接方式：默认、队列、直接，
     * 第五个参数在多线程中才有意义。
     * 默认链接方式：
     * 1）多线程默认使用队列方式；
     * 2）单线程默认使用直接方式。
     * 队列方式：槽函数所在的线程和接收者在同一线程。
     * 直接方式：槽函数所在的线程和发送者在同一线程。
     */
    connect(&m_thread, &QThread::started, &m_worker, &Worker::DoWork);
    connect(&m_worker, &Worker::DoResult, this, &MainWindow::OnResult);
    connect(&m_thread, &QThread::finished, [this]()
    {
        ui->button->setText("开始");
    });
}

MainWindow::~MainWindow()
{
    if (m_thread.isRunning())
    {
        m_worker.SetRuning(false);
        m_thread.quit();
        m_thread.wait();
    }

    delete ui;
}

void MainWindow::OnResult(int code)
{
    if (code == CYCLE_RESULT)
    {
        ++m_count;
        if (m_count >= INT_MAX)
        {
            m_count = 0;
        }
        ui->lcdNumber->display(m_count);
    }
    else if (code == EXIT_WORKER)
    {
        m_count = 0;
        ui->lcdNumber->display(m_count);
    }
    else //PREPARE_ERROR
    {
        m_worker.SetRuning(false);
        m_thread.quit();
        m_thread.wait();
        ui->lcdNumber->display(-100);
    }
}

void MainWindow::on_button_clicked()
{
    //对象形式
    if (m_thread.isRunning())
    {
        m_worker.SetRuning(false);
        m_thread.quit();
        m_thread.wait();
    }
    else
    {
        m_worker.SetRuning(true);
        m_thread.start();
        ui->button->setText("停止");
    }
}

