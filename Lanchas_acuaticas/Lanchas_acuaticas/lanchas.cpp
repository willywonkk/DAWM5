#include "Lanchas.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


Lancha::Lancha() {
    // Constructor defecto
}

//------------------CONSTRUCTOR------------------
Lancha::Lancha(int pVelocidad, string pName, int pdistRecorrida, int pNitro) {
    velocidad = pVelocidad;
    name = pName;
    distRecorrida = pdistRecorrida;
    nitro = pNitro;
}

//------------------NOMBRE------------------
string Lancha::getName() {
    return name;
}

void Lancha::setName(string pname) {
    name = pname;
}


//------------------VELOCIDAD------------------
int Lancha::getVelocidad() {
    return velocidad;
}

void Lancha::setVelocidad(int pvelocidad) {
    velocidad = pvelocidad;
}


//------------------DISTANCIA RECORRIDA------------------
int Lancha::getDistRecorrida() {
    return distRecorrida;
}


//------------------NITRO------------------
int Lancha::getNitro() {
    return nitro;
}

void Lancha::setNitro(int pNitro) {
    nitro = pNitro;
}

// Calcular nitro
void Lancha::calcularNitro() {
    srand(time(NULL));
    int probNitro = rand() % 2 + 1;

    if (probNitro == 1) {
        cout << "Has utilizado el nitro correctamente tu velocidad se multiplicara por 2\n";
        velocidad *= 2;
    }
    else {
        cout << "Has fallado el nitro tu velocidad se dividira en 2\n";
        velocidad /= 2;
    }

    nitro -= 1;
}

//------------------DADO------------------
int Lancha::dado() {
    return rand() % 6 + 1; // Número aleatorio entre 1 y 6
}

// Calcular distancia en el turno
void Lancha::calculateDistance(int pdistRecorrida, int velocidad) {
    distRecorrida = velocidad * 100;
}

// Calcular velocidad total
void Lancha::calculateVelocidad(int pvelTotal) {
    velocidad += pvelTotal;
}