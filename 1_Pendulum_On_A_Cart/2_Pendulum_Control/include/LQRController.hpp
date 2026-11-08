#pragma once

#include "State.hpp"

// Controlador por realimentación de estado: F = -K * x
class LQRController {
    public:
        LQRController(double k_x, double k_x_dot, double k_theta, double k_theta_dot);
        double computeForce(const State& state) const;

    private:
        double k1, k2, k3, k4; // ganancias asociadas a x, x_dot, theta, theta_dot
};