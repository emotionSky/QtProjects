/**
 * @file  rosthread.h
 * @brief 线程处理
 * @details 简单的线程处理，处理ROS事务。
 * @author  emotionsky
 * @date    2022-5-4
 * @version V1.0
 * @copyright  Copyright (c) 2050
 */
#ifndef __ROS_THREAD_H__
#define __ROS_THREAD_H__

#include <QObject>

#include <ros/ros.h>
#include <std_msgs/Int16.h>

class RosThread : public QObject
{
    Q_OBJECT
public:
    explicit RosThread(QObject *parent = nullptr);
    void Run();
    void Start();
    void Stop();
    bool GetRunningFlag();
    void PublishNum(int num);
    void MsgCallback(const std_msgs::Int16Ptr &msg); ///< 消息回调函数

signals:
    void RecvDataSignal(int data);

private:
    bool m_bIsRunning;      ///<线程运行的标志位（可有可无，只不过为了可能中途终端线程函数而使用）
    ros::NodeHandle m_node; ///< ros节点对象
    ros::Subscriber m_sub;  ///<接收者
    ros::Publisher m_pub;   ///<发布者
};

#endif // !__ROS_THREAD_H__