/**
 * @file  mainwindow.h
 * @brief UI对应处理
 * @details 包含程序框架、线程入口等
 * @author  emotionsky
 * @date    2022-5-4
 * @version V1.0
 * @copyright  Copyright (c) 2050
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include "mythread.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void StartSignal();
    void startThread(); // 启动子线程的信号

private slots:
    void on_startButtom_clicked();
    void on_stopButtom_clicked();
    void OnTimeoutSlot();
    void OnCloseSlot();

private:
    Ui::MainWindow *ui;
    MyThread *m_pMyThread;
    QThread *m_pQThread;
};
#endif // MAINWINDOW_H
