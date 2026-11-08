#pragma once

#include "State.hpp" // Llamamos al archivo State.hpp para usar 
// Las variables de estado del pendulo

class PendulumModel{
	public: 

		PendulumModel(); // Constructor de la clase PendulumModel
		State derivatives(const State& state, double force) const; // Creamos la función derivatives que calcula las derivadas de las variables de estado del pendulo
		
	private: // Definimos variables físicas del pendulo. Estas son privadas para que no puedan ser modificadas desde fuera de la clase
		double M;
		double m;
		double b;
		double l;
		double I;
		double g;
		   };