#include "P_2.h"
#include "simulation.h"
#include "dynamics.h"
using namespace Eigen;

void Simulation::setInitialStates(AttitudeState reference_, AttitudeState initial_, double dt_, double totalTime_) {
    this->reference     = reference_;
    this->initial       = initial_;
    this->dt            = dt_;
    this->totalTime     = totalTime_;
}

void Simulation::logStates (AttitudeState state, Vector3d torque_, int idx) {
    // Time, qw qx qy qz, omega_x omega_y omega_z (Inertial Frame), torque_x torque_y torque_z (Inertial Frame)
}

void Simulation::loop() {
    Dynamics dyn;
    Vector3d torque = Vector3d::Zero();
    Vector3d angAcc = Vector3d::Zero();
    while (this->time < this->totalTime) {
        this->current = dyn.propagate(this->initial.q, this->initial.omega, torque, angAcc, this->dt);
        logStates(this->current, torque, idx);
        this->time += this->dt;
        idx += 1;
    }
}