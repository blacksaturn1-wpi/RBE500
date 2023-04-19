#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Quaternion.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"
#include "tf2/LinearMath/Quaternion.h"
#include "string.h"
#include <tf/tf.h>

/**
 * This returns Quaternion to Euler conversion
 */
void quat_to_euler_callback(const geometry_msgs::Quaternion::ConstPtr& msg)
{
  ROS_INFO("Received Quaternion I heard: [%f] [%f] [%f] [%f]", msg->x,msg->y,msg->z,msg->w);
  tf2::Quaternion quat_tf=tf2::Quaternion(msg->x,msg->y,msg->z,msg->w);
  tf2::Matrix3x3 m(quat_tf);
  double roll, pitch, yaw;
  m.getEulerYPR(yaw,pitch, roll);
  ROS_INFO("Z / Y / X: [%f] / [%f] / [%f]", roll, pitch, yaw);
  return;
}

// Second test case not matching, may have multiple solutions (up to 12!!!)
void manual_quat_to_euler_callback(const geometry_msgs::Quaternion::ConstPtr& msg)
{
  double sqw = msg->w*msg->w;
  double sqx = msg->x*msg->x;
  double sqy = msg->y*msg->y;
  double sqz = msg->z*msg->z;
  double unit = sqx + sqy + sqz + sqw; // if normalised is one, otherwise is correction factor
	double test = msg->x*msg->y + msg->z*msg->w;
  // if (test > 0.499*unit) { // singularity at north pole
		
	// 	return;
	// }
	// if (test < -0.499*unit) { // singularity at south pole
	// 	return;
	// }

  double sinr_cosp = 2 * (msg->w * msg->x + msg->y * msg->z);
  double cosr_cosp = 1 - 2 * (msg->x * msg->x + msg->y * msg->y);

  double z = std::atan2(sinr_cosp, cosr_cosp);

  // pitch (y-axis rotation)
  double sinp = std::sqrt(1 + 2 * (msg->w * msg->y - msg->x * msg->z));
  double cosp = std::sqrt(1 - 2 * (msg->w * msg->y - msg->x * msg->z));
  double y = 2 * std::atan2(sinp, cosp) - M_PI / 2;

  // yaw (z-axis rotation)
  double siny_cosp = 2 * (msg->w * msg->z + msg->x * msg->y);
  double cosy_cosp = 1 - 2 * (msg->y * msg->y + msg->z * msg->z);
  double x = std::atan2(siny_cosp, cosy_cosp);

  ROS_INFO("Manual calculation Z / Y / X: [%f] / [%f] / [%f]", z, y, x);

  
}


void ping_callback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("quat_to_euler", 1000, quat_to_euler_callback);
  ros::Subscriber sub2 = n.subscribe("quat_ping", 1000, ping_callback);

  ros::spin();

  return 0;
}