/**
 * @file  rosthread.cpp
 * @brief 线程处理
 * @details 简单的线程处理，处理ROS事务。
 * @author  emotionsky
 * @date    2022-5-4
 * @version V1.0
 * @copyright  Copyright (c) 2050
 */
#include "rosthread.h"
#include <QThread>
#include <QDebug>

RosThread::RosThread(QObject *parent) : QObject(parent)
{
    m_bIsRunning = false;
    m_sub = m_node.subscribe("/qt_ros/example1", 1, &RosThread::MsgCallback, this); ///< 标准ros接收者初始化
    m_pub = m_node.advertise<std_msgs::Int16>("/qt_ros/example2", 1);               ///< 标准ros发布者初始化
}

void RosThread::Run()
{
    unsigned long duration = 1000;
    while (m_bIsRunning)
    {
        ros::spinOnce();           ///< 调用ros服务
        QThread::usleep(duration); ///<周期的保证
    }
}

void RosThread::Start()
{
    m_bIsRunning = true;
}

void RosThread::Stop()
{
    m_bIsRunning = false;
}

bool RosThread::GetRunningFlag()
{
    return m_bIsRunning;
}

void RosThread::PublishNum(int num)
{
    std_msgs::Int16 info;
    info.data = num;            ///< 类型转换和赋值
    example_pub_.publish(info); ///< 发布消息
}

void RosThread::MsgCallback(const std_msgs::Int16Ptr &msg)
{
    emit RecvDataSignal(msg->data);
}