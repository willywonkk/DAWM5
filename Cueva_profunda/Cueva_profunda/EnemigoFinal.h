#pragma once
#include "Personaje.h"
#include <iostream>
using namespace std;

class EnemigoFinal : public Personaje {
private:
    int fireAttack;
    int frozenAttack;

public:
    // Constructor
    EnemigoFinal(int pHp,
        std::string pName,
        int pAttack,
        int posicionX,
        int posicionY,
        int pFireAttack,
        int pFrozenAttack);

    // Getters
    int getFireAttack();
    int getFrozenAttack();

    // Setters
    void setFireAttack(int pFireAttack);
    void setFrozenAttack(int pFrozenAttack);

    // Funciones
    void printAllStats();
};
