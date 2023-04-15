#!/usr/bin/env python

from __future__ import print_function

from multiplication_in_ros.srv import MultTwoFloats,MultTwoFloatsResponse
import rospy

def handle_mult_two_floats(req):
    print("Returning [%s * %s = %s]"%(req.x, req.y, (req.x * req.y)))
    return MultTwoFloatsResponse(req.x * req.y)

def mult_two_floats_server():
    rospy.init_node('mult_two_floats_server')
    s = rospy.Service('mult_two_floats', MultTwoFloats, handle_mult_two_floats)
    print("Ready to multiply two floats.")
    rospy.spin()

if __name__ == "__main__":
    mult_two_floats_server()
