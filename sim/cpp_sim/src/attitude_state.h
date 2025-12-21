#pragma once
#include <Eigen/Dense>
using namespace Eigen;

struct AttitudeState {
    Quaterniond q;
    Vector3d omega;
};

