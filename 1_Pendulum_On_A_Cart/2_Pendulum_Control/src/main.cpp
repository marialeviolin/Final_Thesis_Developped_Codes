#include <iostream>
#include <fstream>
#include <cmath>

#include "State.hpp"
#include "PendulumModel.hpp"
#include "Integrator.hpp"
#include "Riccati.hpp"
#include "LinearModel.hpp"
#include "LQRController.hpp"
#include "Matrix.hpp"

int main()
{
    PendulumModel model;
    // Linealizamos y calculamos K
    const LinearModel lin=model.linearize();
    const Mat4 Q=identity();
    const double R=1.0;
    const Vec4 K=computeLQRGain(lin.A, lin.B,Q,R);
    std::cout<<"K=["<<K[0]<<", "<<K[1]<<", "<<K[2]<<", "<<K[3]<<"]"<<std::endl;
    LQRController controller(K[0],K[1],K[2],K[3]);


    State state;

    state.x = 0.0;
    state.x_dot = 0.0;
    state.theta = 1;
    state.theta_dot = 0.0;

    const double dt = 0.001; //pasodel tiempo
    const double t_final = 10.0;
    const int n_steps= static_cast<int>(std::round(t_final/dt));



    std::ofstream file("results.csv");
    if (!file.is_open()) {
        std::cerr << "ERROR: no se pudo abrir results.csv (¿esta abierto en Excel?)" << std::endl;
    return 1;
}
    file << "t,x,x_dot,theta,theta_dot,force\n";



std::cout << "F(0) = " << controller.computeForce(state) << std::endl;
for (int i = 0; i <= n_steps; ++i)
{
    const double t = i * dt;
    const double force = controller.computeForce(state);   // F = -K x, se recalcula en cada paso


 if (i % 10 == 0) {   
    file << t << "," << state.x << "," << state.x_dot << ","
         << state.theta << "," << state.theta_dot << "," << force << "\n";}

    state = rk4Step(model, state, force, dt);
}
   file.close();
    std::cout << "Estado final: x=" << state.x << " theta=" << state.theta << std::endl;
    return 0;
}