#pragma once
#include <Eigen/Dense>
#include "P_2.h"
#include "attitude_state.h"
using namespace Eigen;

class Simulation {
public:
    double dt;
    double totalTime;
    double time = 0;
    int idx     = 0;
    AttitudeState current;
    AttitudeState reference;
    AttitudeState initial;
    P_2 controller;
    void setInitialStates(AttitudeState reference_, AttitudeState initial_, double dt_, double totalTime_);
    void logStates(AttitudeState state, Vector3d torque_, int idx);
    void loop();
};