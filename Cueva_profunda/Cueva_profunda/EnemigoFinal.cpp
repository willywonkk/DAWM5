#include "EnemigoFinal.h"
#include <iostream>
using namespace std;

EnemigoFinal::EnemigoFinal(	int pHp,
							string pName,
							int pAttack,
							int posicionX,
							int posicionY,
							int pFireAttack,
							int pFrozenAttack) : Personaje(	pHp,
															pName,
															pAttack,
															posicionX,
															posicionY) {fireAttack = pFireAttack;
																		frozenAttack = pFrozenAttack;
							}

int EnemigoFinal::getFireAttack() {
    return fireAttack;
}

void EnemigoFinal::setFireAttack(int pFireAttack) {
    fireAttack = pFireAttack;
}

int EnemigoFinal::getFrozenAttack() {
    return frozenAttack;
}

void EnemigoFinal::setFrozenAttack(int pFrozenAttack) {
    frozenAttack = pFrozenAttack;
}

void EnemigoFinal::printAllStats() {
    cout << "El nombre del enemigo final es " << getName() << endl;
    cout << "La vida del enemigo final es " << getHp() << endl;
    cout << "El ataque normal del enemigo final es " << getAttack() << endl;
	cout << "En el eje X esta en el " << getX() << endl;
	cout << "En el eje Y esta en el " << getY() << endl;
    cout << "El ataque de fuego del enemigo final es " << getFireAttack() << endl;
    cout << "El ataque de hielo del enemigo final es " << getFrozenAttack() << endl;
}

