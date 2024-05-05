#pragma once
#include <iostream>

using namespace std;

class Lancha
{
private:
	string name;
	int velocidad;
	int distRecorrida;
	int nitro;

public:
	// CONSTRUCTORES
	Lancha(int pVelocidad, string pName, int pDistRecorrida, int pNitro);
	Lancha();

	// GETTERS
	string getName();
	int getVelocidad();
	int getDistRecorrida();
	int getNitro();

	// SETTERS
	void setName(string pname);
	void setVelocidad(int pvelocidad);
	void setNitro(int pvelocidad);

	// FUNCIONES
	int dado();
	void calcularNitro();
	void calculateDistance(int pdistRecorrida, int velocidad);
	void calculateVelocidad(int pvelTotal);

};