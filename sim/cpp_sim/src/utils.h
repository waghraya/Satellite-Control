#pragma once
#include <Eigen/Dense>
using namespace Eigen;

Quaterniond euler_to_quaternion(double roll, double pitch, double yaw);
Vector3d quaternion_to_euler(Quaterniond q);