#include "PendulumModel.hpp"
#include <cmath>

PendulumModel::PendulumModel(){
	M=0.5;
	m=0.2;
	b=0.1;
	l=0.3;
	I=0.006;
	g=9.81;
}

State PendulumModel::derivatives(const State& state, double force) const{
	// state.theta es phi (desviación de la vertical). El ángulo real del informe es pi + phi
	const double pi = std::acos(-1.0);
	const double theta = pi + state.theta;
	const double s = std::sin(theta);
	const double c = std::cos(theta);

	const double a11 = M + m;
	const double a12 = m * l * c;
	const double a21 = m * l * c;
	const double a22 = I + m * l * l;

	const double rhs1 = m * l * s * state.theta_dot * state.theta_dot + force - b * state.x_dot;
	const double rhs2 = -m * g * l * s;

	const double det = a11 * a22 - a12 * a21;

	const double x_ddot = (a22 * rhs1 - a12 * rhs2) / det;
	const double theta_ddot = (-a21 * rhs1 + a11 * rhs2) / det;

	State d;
		d.x = state.x_dot;
		d.x_dot = x_ddot;
		d.theta = state.theta_dot;
		d.theta_dot = theta_ddot;

	return d;
}