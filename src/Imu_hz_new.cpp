#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sys/time.h>
#include <iostream>
#include <ctime>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <pthread>

using namespace std;

publish_Imu()
{
	struct timeval current_time, prev_time, c;
	gettimeofday(&current_time,NULL) ;

	usleep(5*n);
	
	gettimeofday(&prev_time,NULL);


	int64_t A = ((int64_t)current_time.tv_sec)*1000000 + (int64_t)current_time.tv_usec;
	int64_t B = ((int64_t)prev_time.tv_sec)*1000000 + (int64_t)prev_time.tv_usec;
	int64_t C = B - A;
	c.tv_sec = C/1000000;
	c.tv_usec = C%1000000;




	ros::Publisher imu_pub = n.advertise<std_msgs::sensor_msgs>("Imu_hz", 1000); 
    
  while(ros::ok())
	{ 
		std_msgs::sensor_msgs imu;
		imu_pub.publish(imu / c.tv_usec);

    ros::spin();
			  
		++count;
	}
}


void imu_Callback(const std_msgs::sensor_msgs::Imu) 	//change message type
{
	++count;
}

subscribe_Imu()
{
	ros::init(argc, argv, "Imu_hz");

  ros::NodeHandle n;

	ros::Subscriber sub_imu = n.subscribe("/razor_imu_9dof/imu_node", 1000, imu_Callback);

	ros::spin();

	publish_Imu();
}

int main(int argc, char **argv)
{
	pthread_t thread1_sub;
	pthread_t threea2_pub;

	pthread_create(&thread1_sub, NULL, &subscribe_Imu());
	pthread_create(&thread2_pub, NULL, &publish_Imu());

	pthread_join(thread1_sub, NULL);
	pthread_join(thread2_pub, NULL);

	return 0;
}

