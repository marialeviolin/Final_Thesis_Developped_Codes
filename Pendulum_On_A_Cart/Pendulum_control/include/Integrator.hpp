#pragma once

#include "State.hpp" // Llamamos al archivo State.hpp para usar 
// Las variables de estado del pendulo
#include "PendulumModel.hpp" // Llamamos al archivo PendulumModel.hpp para usar // la clase PendulumModel y su función derivatives

// Avanza el estado del pendulo en un paso de tiempo dt usando el método de integración de Runge-Kutta de cuarto orden

State rk4Step(const PendulumModel& model, const State& state, double force, double dt);