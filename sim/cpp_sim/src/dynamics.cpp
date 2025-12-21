#include "dynamics.h"
#include <Eigen/Dense>
#include "attitude_state.h"
#include "satellite.h"
using namespace Eigen;

AttitudeState Dynamics::propagate(Quaterniond q_start, Vector3d omega_start, Vector3d torque, Vector3d angAcc, double dt) {
    AttitudeState nextState;
    Satellite sat;
    // Get angular acceleration
    angAcc = sat.I.llt().solve(torque - omega_start.cross(sat.I * omega_start));
    nextState.omega = omega_start + angAcc * dt;
    //Get quaternion dynamics
    q_dot = 0.5 * (q_start.w() * nextState.omega + q_start.vec().cross(nextState.omega));
    nextState.q = q_start;
    nextState.q.coeffs() += q_dot.coeffs() * dt;
    nextState.q.normalize();
    return nextState;
}