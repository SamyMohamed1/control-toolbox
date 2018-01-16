/**********************************************************************************************************************
This file is part of the Control Toolbox (https://adrlab.bitbucket.io/ct), copyright by ETH Zurich, Google Inc.
Authors:  Michael Neunert, Markus Giftthaler, Markus Stäuble, Diego Pardo, Farbod Farshidian
Licensed under Apache2 license (see LICENSE file in main directory)
**********************************************************************************************************************/

#include "InvertedPendulumActDynLinearizedForward.h"

namespace ct {
namespace models {
namespace InvertedPendulum {


const InvertedPendulumActDynLinearizedForward::state_matrix_t& InvertedPendulumActDynLinearizedForward::getDerivativeState(
    const state_vector_t& x,
    const control_vector_t& u,
    const double t)
{
    double* jac = dFdx_.data();
    Eigen::Matrix<double, 3 + 1, 1> x_in;
    x_in << x, u;

        jac[1] = (-180.9 - 0.248107 * 9.81 * (- cos(x_in[0]))) / 0.043045655;
    // dependent variables without operations
    jac[3] = 1;
    jac[7] = 4202.51474858496;


    return dFdx_;
}

const InvertedPendulumActDynLinearizedForward::state_control_matrix_t& InvertedPendulumActDynLinearizedForward::getDerivativeControl(
    const state_vector_t& x,
    const control_vector_t& u,
    const double t)
{
    double* jac = dFdu_.data();
    Eigen::Matrix<double, 3 + 1, 1> x_in;
    x_in << x, u;

        // dependent variables without operations
    jac[2] = 0.02;


    return dFdu_;
}
}
}
}
