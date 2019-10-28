#include "ros/ros.h"
#include "geometry_msgs/PoseStamped.h"
#include <tf/transform_listener.h>
#include <costmap_2d/costmap_2d_ros.h>

bool move_robot(geometry_msgs::PoseStamped::Request &req,
		geometry_msgs::PoseStamped::Response &res)
{
	
  	return true;
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "integration_node_server");
	ros::NodeHandle n;
	ros::ServiceServer service = n.advertiseService("integration_node", move_robot);
	ROS_INFO("Ready to move robot.");
	tf::TransformListener tf(ros::Duration(10));
	costmap_2d::Costmap2DROS costmap("my_costmap", tf);  


	ros::spin();

	return 0;
}