#include "utils.h"
using namespace Eigen;
#define _USE_MATH_DEFINES
#include <math.h>
/*
Roll pitch and yaw inputted in DEGREES returns normalized quaternion.
Convention: ZYX (yaw-pitch-roll) intrinsic rotations
- Roll (φ): rotation about body x-axis
- Pitch (θ): rotation about body y-axis  
- Yaw (ψ): rotation about body z-axis
*/
Quaterniond euler_to_quaternion(double roll, double pitch, double yaw){
    // Convert degrees to radians
    roll    = roll * M_PI / 180.0;
    pitch   = pitch * M_PI / 180.0;
    yaw     = yaw * M_PI / 180.0;
    
    // Compute half angles
    double cr = cos(roll * 0.5);
    double sr = sin(roll * 0.5);
    double cp = cos(pitch * 0.5);
    double sp = sin(pitch * 0.5);
    double cy = cos(yaw * 0.5);
    double sy = sin(yaw * 0.5);
    
    // Compute quaternion components (w, x, y, z)
    double qw = cr * cp * cy + sr * sp * sy;
    double qx = sr * cp * cy - cr * sp * sy;
    double qy = cr * sp * cy + sr * cp * sy;
    double qz = cr * cp * sy - sr * sp * cy;
    
    // Create and return normalized quaternion
    Quaterniond q(qw, qx, qy, qz);
    q.normalize();
    
    return q;
}