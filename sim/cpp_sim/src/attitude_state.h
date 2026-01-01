#pragma once
#include <Eigen/Geometry>
using namespace Eigen;

struct AttitudeState {
    Quaterniond q;
    Vector3d omega;
};

