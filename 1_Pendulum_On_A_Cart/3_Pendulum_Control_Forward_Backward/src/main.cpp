# include <iostream>
# include <fstream>
# include <cmath>
# include <vector>

# include "State.hpp"
# include "PendulumModel.hpp"
# include "Integrator.hpp"
# include "BackwardPass.cpp"
# include "Matrix.cpp"

int main(){

    // 1-------- Datos del problema

    PendulumModel model;
    const LinearModel lin=model.linearize();
    const Mat4 Q=identity(); // Penalización del estado
    const double R=1.0; // Penalización del control
    const Mat4 Qf=zeros(); // Coste terminal
    const double dt=0.001; // paso del tiempo (s)
    const double T=10.0; // horizonte (s)
    const int n_steps=static_cast<int>(std::round(T/dt));

    // 2-------- BACKWARD PASS: adjunta -> K(t)

    const std::vector<Vec4> Ks=backwardPass(lin.A,lin.B,Q,R,Qf,n_steps,dt);

    // 3-------- FORWARD PASS: dinámica con u=-K(t)x

    State state;
    state.x=0.0;
    state.x_dot=0.0;
    state.theta=0.1;
    state.theta_dot=0;

    std::ofstream file("results.csv");
    if(!file.is_open()){
        std::cerr<<"ERROR: no se pudo abrir results.csv (esta abierto en Excel?)"<< std::endl;
        return 1;
    }
file<<"t,x,x_dot,theta,theta_dot,force\n";
for(int i=0;i<=n_steps;++i){
    const double t=i*dt;
        const Vec4& K = Ks[i];
        const double force = -(K[0] * state.x + K[1] * state.x_dot
                             + K[2] * state.theta + K[3] * state.theta_dot);

        file << t << "," << state.x << "," << state.x_dot << ","
             << state.theta << "," << state.theta_dot << "," << force << "\n";

        state = rk4Step(model, state, force, dt);
    }

    std::cout << "K(t=0) = [" << Ks[0][0] << ", " << Ks[0][1] << ", "
              << Ks[0][2] << ", " << Ks[0][3] << "]" << std::endl;
    std::cout << "Estado final: x=" << state.x << " theta=" << state.theta << std::endl;
    return 0;
}