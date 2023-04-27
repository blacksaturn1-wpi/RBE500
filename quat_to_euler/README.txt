catkin_create_pkg quat_to_euler std_msgs rospy roscpp
source ./devel/setup.bash
nano package.xml
roscd quat_to_euler


catkin_make
rosrun quat_to_euler quat_subscriber

rostopic pub -1 /quat_ping std_msgs/String  'Hello'

rostopic pub -1 /quat_to_euler geometry_msgs/Quaternion  "{x: .5, y: 0.5, z: 0.5, w: 0.5}"
rostopic pub -1 /quat_to_euler geometry_msgs/Quaternion  "{x: .8, y: 0.5, z: 0.5, w: 0.8}"




