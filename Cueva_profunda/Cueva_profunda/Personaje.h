#pragma once
#include <iostream>
using namespace std;

class Personaje {
private:
    int hp;
    string name;
    int attack;
    int posicionX;
    int posicionY;

public:
    // CONSTRUCTORES
    Personaje();
    Personaje(int pHp, string pName, int pAttack, int posicionX, int posicionY);

    // GETTERS
    int getHp();
    string getName();
    int getAttack();
    int getX();
    int getY();

    // SETTERS
    void setHp(int php);
    void setName(string pname);
    void setAttack(int pattack);
    void setX(int pX);
    void setY(int pY);

    // FUNCIONES
    void printStatus();
    int dadoX();
    int dadoY();
};


