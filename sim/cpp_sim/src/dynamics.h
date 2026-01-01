#pragma once
#include <Eigen/Geometry>
#include "attitude_state.h"
using namespace Eigen;

class Dynamics {
public:
    Quaterniond q_dot;
    Vector3d omega_body;
    AttitudeState propagate(Quaterniond q_start, Vector3d omega_start, Vector3d torque, Vector3d angAcc, double dt);
};