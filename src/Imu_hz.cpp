#include "ros/ros.h"
#include "std_msgs/String.h"

using namespace std;

void rplidarCallback(const std_msgs::String::ConstPtr& msg)
{ 
 ;
}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "Imu_hz");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);

	ros::Subscriber sub_imu = n.subscribe("/rplidar_ros/rplidarNode", 1000, rplidarCallback);

  ros::spin();

  return 0;
}
