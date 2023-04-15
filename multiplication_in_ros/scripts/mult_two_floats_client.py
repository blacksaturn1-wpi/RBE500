#!/usr/bin/env python

from __future__ import print_function

import sys
import rospy
from multiplication_in_ros.srv import *

def mult_two_floats_client(x, y):
    rospy.wait_for_service('mult_two_floats')
    try:
        mult_two_floats = rospy.ServiceProxy('mult_two_floats', MultTwoFloats)
        resp1 = mult_two_floats(x, y)
        return resp1.product
    except rospy.ServiceException as e:
        print("Service call failed: %s"%e)

def usage():
    return "USAGE: %s [x y]"%sys.argv[0]

if __name__ == "__main__":
    if len(sys.argv) == 3:
        x = float(sys.argv[1])
        y = float(sys.argv[2])
    else:
        print(usage())
        sys.exit(1)
    print("Requesting %s*%s"%(x, y))
    print("%s * %s = %s"%(x, y, mult_two_floats_client(x, y)))