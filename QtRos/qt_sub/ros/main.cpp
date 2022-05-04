/**
 * @file  main.cpp
 * @brief 程序入口
 * @author  emotionsky
 * @date    2022-5-4
 * @version V1.0
 * @copyright  Copyright (c) 2050
 */
#include <ros/ros.h>
#include <std_msgs/Int16.h>

using namespace std;

void subCallback(const std_msgs::Int16Ptr &msg)
{
	ROS_INFO("received: [%d]", msg->data); ///< 打印接收的消息
}

int main(int argc, char *argv[])
{
	ros::init(argc, argv, "qt_sub_node");
	ros::NodeHandle n;
	ros::Publisher example_pub = n.advertise<std_msgs::Int16>("/qt_ros/example1", 1); ///< 标准ros发布者初始化
	ros::Subscriber example_sub = n.subscribe("/qt_ros/example2", 1, &subCallback);	  ///< 标准ros接收者初始化
	std_msgs::Int16 msg;
	int count = 0;

	ros::Rate loop_rate(10);

	while (ros::ok())
	{
		count++;
		msg.data = count;
		example_pub.publish(msg);
		loop_rate.sleep();
		ros::spinOnce();
	}
	return 0;
}
