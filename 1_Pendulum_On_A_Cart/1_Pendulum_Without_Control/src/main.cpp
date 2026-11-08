#include <iostream>
#include <fstream>
#include <cmath>

#include "State.hpp"
#include "PendulumModel.hpp"
#include "Integrator.hpp"

int main()
{
    
    State state;

    state.x = 0.0;
    state.x_dot = 0.0;
    state.theta = 0.1;
    state.theta_dot = 0.0;

    const double dt = 0.001; //pasodel tiempo
    const double t_final = 1.0;
    const double force = 0.0;
    const int n_steps= static_cast<int>(std::round(t_final/dt));

    std::ofstream file("results.csv");
    file << "t,x,x_dot,theta,theta_dot\n";
    for (int i = 0; i <= n_steps; ++i) {
        double t = i * dt;
        file << t << "," << state.x << "," << state.x_dot << "," << state.theta << "," << state.theta_dot << "\n";
        state = rk4Step(PendulumModel(), state, force, dt);
    }
    file.close();
    std::cout << "Simulation completed. Results saved to results.csv" << std::endl;
    return 0;
}