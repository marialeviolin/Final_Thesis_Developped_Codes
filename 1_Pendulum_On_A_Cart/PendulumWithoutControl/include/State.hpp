#pragma once

struct State { // Definimos las variables de estado del pendulo
    double x;   
    double x_dot;

    double theta;
    double theta_dot;
};

inline State operator+(const State& a, const State& b) {
    State r;
    r.x = a.x + b.x;
    r.x_dot = a.x_dot + b.x_dot;
    r.theta = a.theta + b.theta;
    r.theta_dot = a.theta_dot + b.theta_dot;
    return r;
}

inline State operator*(double k, const State& a) {
    State r;
    r.x = k * a.x;
    r.x_dot = k * a.x_dot;
    r.theta = k * a.theta;
    r.theta_dot = k * a.theta_dot;
    return r;
}