#pragma once
#include <Eigen/Dense>
using namespace Eigen;

class Satellite{
public:
    Matrix3d I{{1.0, 0.0, 0.0},
                      {0.0, 2.0, 0.0},
                      {0.0, 0.0, 3.0}};
    double rwMaxRPM = 0.0;
};