# Explore 1
rosrun tf2_ros static_transform_publisher 1 0 0 0 0 0 parent_link child_link

# Explore 2
rosrun tf2_ros static_transform_publisher 1 1 1 0 0 0 parent_link child_link
rosrun tf2_ros static_transform_publisher 1 0 0 0 0 0 child_link luqman

# Explore 3
rosrun tf2_ros static_transform_publisher 1 0 0 0 0 0 world robot_base
rosrun tf2_ros static_transform_publisher 1 0.5 0 0 0 0 robot_base l_wheel
rosrun tf2_ros static_transform_publisher 1 -0.5 0 0 0 0 robot_base r_wheel

# Submit for Lab 9
rosrun transforms_wiki rosrun transforms_wiki tf2_static_br.py