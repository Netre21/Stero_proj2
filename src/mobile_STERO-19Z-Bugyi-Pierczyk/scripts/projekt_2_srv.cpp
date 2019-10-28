#include "ros/ros.h"
#include "geometry_msgs/PoseStamped.h"
#include <tf2_ros/transform_listener.h>
#include <costmap_2d/costmap_2d_ros.h>
#include <stero_mobile_init/Service.h>

bool move_robot(stero_mobile_init::Service::Request &req,
				stero_mobile_init::Service::Response &res)
{
	res.result="ergergerg";
	ROS_INFO("Zakonczylem prace");
  	return true;
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "integration_node_server");
	ros::NodeHandle n;
	ros::ServiceServer service = n.advertiseService("integration_node", move_robot);
	
	tf2_ros::Buffer tfBuffer;
    tf2_ros::TransformListener tfListener(tfBuffer);
	costmap_2d::Costmap2DROS costmap("global_costmap", tfBuffer);

	ROS_INFO("Ready to move robot."); 


	ros::spin();

	return 0;
}