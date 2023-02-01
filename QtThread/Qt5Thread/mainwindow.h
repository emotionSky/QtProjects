/**
 * @file  mainwindow.h
 * @brief 主界面的类（主要给出对象和指针的两种实现方式，各有不同）
 * @author  emotionsky
 * @email   bitdreamsky@126.com
 * @date    2023/02/01
 * @version V1.0.0
 * @copyright  Copyright (c), emotionsky, All rights reserved.
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include "worker.h"

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

public:
    void OnResult(int code);

private slots:
    void on_button_clicked();

private:
    Ui::MainWindow *ui;
    Worker m_worker;
    QThread m_thread;
    int m_count;
};
#endif // MAINWINDOW_H
