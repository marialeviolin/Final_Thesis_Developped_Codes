#include "Integrator.hpp"

State rk4Step(const PendulumModel& model, const State& state, double force, double dt) {
    State k1 = model.derivatives(state, force);
    State k2 = model.derivatives(state + (0.5 * dt) * k1, force);
    State k3 = model.derivatives(state + (0.5 * dt) * k2, force);
    State k4 = model.derivatives(state + dt * k3, force);

    return state + (dt / 6.0) * (k1 + 2.0 * k2 + 2.0 * k3 + k4);
}