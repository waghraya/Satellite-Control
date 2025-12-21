#pragma once
#include <Eigen/Dense>
#include "controller.h"
#include "attitude_state.h"
using namespace Eigen;

class P_2 : public Controller {
public:
    P_2 () : current(), reference() {}
    Vector3d calculateControlTorque() override;

    void setCurrentState(const AttitudeState& state) {current = state;}
    void setReferenceState(const AttitudeState& state) {reference = state;}

private:
    double kq = 20;
    double kw = 4;
    Quaterniond q_err;
    Vector3d omega_err;
    AttitudeState current;
    AttitudeState reference;
};