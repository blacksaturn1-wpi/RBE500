# urdf_sim_tutorial
See the tutorials over at http://wiki.ros.org/urdf_tutorial

http://wiki.ros.org/urdf/Tutorials


http://wiki.ros.org/urdf/Tutorials/Using%20a%20URDF%20in%20Gazebo

# Turn Head
rostopic pub /r2d2_head_controller/command std_msgs/Float64 "data: 0"

rostopic pub /r2d2_head_controller/command std_msgs/Float64 "data: -0.707"
rostopic pub /r2d2_head_controller/command std_msgs/Float64 "data: 0.707"

rostopic pub /r2d2_head_controller/command std_msgs/Float64 "data: 3.14"


# front gripper - open
rostopic pub  /r2d2_gripper_controller/command std_msgs/Float64MultiArray "layout:
  dim:
  - label: ''
    size: 3
    stride: 1
  data_offset: 0
data: [0, 0.5, 0.5]"

# front gripper - close
rostopic pub  /r2d2_gripper_controller/command std_msgs/Float64MultiArray "layout:
  dim:
  - label: ''
    size: 3
    stride: 1
  data_offset: 0
data: [-0.4, 0, 0]"


# rear gripper - open
rostopic pub  /r2d2_gripper_controller_back/command std_msgs/Float64MultiArray "layout:
  dim:
  - label: ''
    size: 3
    stride: 1
  data_offset: 0
data: [0, 0.5, 0.5]"

# rear gripper - close
rostopic pub  /r2d2_gripper_controller_back/command std_msgs/Float64MultiArray "layout:
  dim:
  - label: ''
    size: 3
    stride: 1
  data_offset: 0
data: [0.4, 0, 0]"

