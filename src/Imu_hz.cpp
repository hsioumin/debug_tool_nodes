#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sys/time.h>
#include <iostream>
#include <ctime>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <pthread.h>

#define n 1000000

using namespace std;


publish_Imu()
{
	struct timeval detail_time1, detail_time2;

	gettimeofday(&detail_time1, NULL);
	printf("%ld\n", detail_time1.tv_usec); //microseconds

	usleep(n);

	gettimeofday(&detail_time2, NULL);
	printf("%ld\n", detail_time2.tv_usec); //microseconds

	//previous time - now
	printf("%06ld\n", detail_time2.tv_usec - detail_time1.tv_usec);

	//compute hz here
}


void rplidarCallback(const std_msgs::sensor_msgs::Imu) //change message type 
{ 
	//count data(?)
	;
}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "Imu_hz");

  ros::NodeHandle n;

	ros::Subscriber sub_imu = n.subscribe("/rplidar_ros/rplidarNode", 1000, rplidarCallback);

	//duration();

  ros::spin();

  return 0;
}
