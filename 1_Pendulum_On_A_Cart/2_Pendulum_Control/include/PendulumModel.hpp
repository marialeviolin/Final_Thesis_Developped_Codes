#pragma once

#include "State.hpp"
#include "LinearModel.hpp"

class PendulumModel{
	public:
		PendulumModel();
		State derivatives(const State& state, double force) const;
		LinearModel linearize() const; // Linealización en el equilibrio vertical (phi = 0)

	private:
		double M;
		double m;
		double b;
		double l;
		double I;
		double g;
};