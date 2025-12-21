#pragma once
#include <Eigen/Dense>
#include "attitude_state.h"
using namespace Eigen;

class Dynamics {
public:
    Quaterniond q_dot;
    Vector3d omega_body;
    AttitudeState Dynamics::propagate(Quaterniond q_start, Vector3d omega_start, Vector3d torque, Vector3d angAcc, double dt);
};