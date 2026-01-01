#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include "src/attitude_state.h"
#include "src/simulation.h"
#include "src/P_2.h"
#include "src/satellite.h"
#include "src/utils.h"
using namespace Eigen;
using namespace std;

int main() {
    //Declare initial states
    AttitudeState initial;
    initial.q       = Quaterniond(1.0, 0.0, 0.0, 0.0);  // (w, x, y, z)
    initial.omega   = Vector3d::Zero();

    AttitudeState reference;
    //create euler angle -> quaternion conversion
    double roll     = 10.0;   // φ (x-axis)
    double pitch    = 5.0;    // θ (y-axis)
    double yaw      = 30.0;   // ψ (z-axis)
    reference.q     = euler_to_quaternion(roll, pitch, yaw);
    reference.omega.setZero();

    Simulation sim;
    sim.dt          = 0.1;
    sim.totalTime   = 20;
    sim.setInitialStates(reference, initial, sim.dt, sim.totalTime);
    cout << "Initial States set . . .\n";
    cout << "Reference yaw pitch roll: [" << roll << ", " << pitch << ", " << yaw << "]\n";
    cout << "Reference quaternion: (" <<  reference.q.w() << ", " << reference.q.x() << ", " << reference.q.y() << ", " << reference.q.z() << ")\n";
    sim.loop();
    cout << "\nSimulation complete.\n";
    return 0;
}