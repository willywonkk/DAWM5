#include "Personaje.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//------------------CONSTRUCTOR------------------
Personaje::Personaje() {
    hp = 100;
    name = "Default";
    attack = 10;
    posicionX = dadoX();
    posicionY = dadoY();
}

Personaje::Personaje(int pHp, string pName, int pAttack, int pX, int pY) {
    hp = pHp;
    name = pName;
    attack = pAttack;
    posicionX = pX;
    posicionY = pY;
}

//------------------NOMBRE------------------
string Personaje::getName() {
    return name;
}

void Personaje::setName(string pname) {
    name = pname;
}

//------------------VIDA------------------
int Personaje::getHp() {
    return hp;
}

void Personaje::setHp(int php) {
    hp = php;
}

//------------------ATAQUE------------------
int Personaje::getAttack() {
    return attack;
}

void Personaje::setAttack(int pattack) {
    attack = pattack;
}

//------------------POSICION-X------------------
int Personaje::getX() {
    return posicionX;
}

void Personaje::setX(int pX) {
    posicionX = pX;
}

//------------------POSICION-Y------------------
int Personaje::getY() {
    return posicionY;
}

void Personaje::setY(int pY) {
    posicionY = pY;
}

//------------------FUNCIONES------------------
void Personaje::printStatus() {
    cout << "El nombre del personaje es " << getName() << " y tiene una vida de " << getHp() << endl;
}

int Personaje::dadoX() {
    return rand() % 10; // Aleatorio entre 0 y 9
}

int Personaje::dadoY() {
    return rand() % 5; // Aleatorio entre 0 y 4
}
