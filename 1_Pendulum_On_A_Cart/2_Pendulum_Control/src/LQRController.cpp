#include "LQRController.hpp"

LQRController::LQRController(double k_x, double k_x_dot, double k_theta, double k_theta_dot)
    : k1(k_x), k2(k_x_dot), k3(k_theta), k4(k_theta_dot)
{
}

double LQRController::computeForce(const State& state) const
{
    return -(k1 * state.x + k2 * state.x_dot + k3 * state.theta + k4 * state.theta_dot);
}