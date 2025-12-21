#pragma once
#include <Eigen/Dense>
class Controller{
public: 
    virtual Eigen::Vector3d calculateControlTorque();
    Eigen::Vector3d controlTorque{0.0, 0.0, 0.0}; 
};