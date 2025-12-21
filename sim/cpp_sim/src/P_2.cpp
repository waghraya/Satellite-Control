#include "P_2.h"

Eigen::Vector3d P_2::calculateControlTorque() {
    omega_err = reference.omega - current.omega;
    q_err = reference.q * current.q.inverse();
    this->controlTorque = -omega_err * kw - q_err.vec() * kq;
    return this->controlTorque;
}