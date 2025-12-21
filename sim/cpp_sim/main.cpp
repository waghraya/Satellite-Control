#include <iostream>
#include "src/attitude_state.h"
#include "src/simulation.h"
#include "src/P_2.h"
#include "src/satellite.h"
#define _USE_MATH_DEFINES
#include <math.h>
using namespace Eigen;

int main() {
    //Declare initial states
    AttitudeState initial;
    initial.q       = Quaterniond(1.0, 0.0, 0.0, 0.0);  // (w, x, y, z)
    initial.omega   = Vector3d::Zero();

    AttitudeState reference;
    //create euler angle -> quaternion conversion
    double roll     = 10.0 * M_PI / 180.0;   // φ (x-axis)
    double pitch    = 5.0  * M_PI / 180.0;   // θ (y-axis)
    double yaw      = 30.0 * M_PI / 180.0;   // ψ (z-axis)
    reference.q     = Quaterniond(1.0,0.0,0.0,0.0);
    reference.omega.setZero();

    Simulation sim;
    sim.dt          = 0.1;
    sim.totalTime   = 20;
    sim.setInitialStates(reference, initial, sim.dt, sim.totalTime);
    sim.loop();
    return 0;
}