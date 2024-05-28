#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "Personaje.h"
#include "EnemigoFinal.h"

using namespace std;

void combate(Personaje& p1, Personaje& p2) {
    cout << p1.getName() << " lucha contra " << p2.getName() << "!" << "\n";
    while (p1.getHp() > 0 && p2.getHp() > 0) {
        p1.setHp(p1.getHp() - p2.getAttack());
        p2.setHp(p2.getHp() - p1.getAttack());

        cout << p1.getName() << " recibio un ataque de " << p2.getAttack() << "\n";
        cout << p2.getName() << " recibio un ataque de " << p1.getAttack() << "\n";

        if (p1.getHp() <= 0) {
            p1.setHp(0);
        }
        if (p2.getHp() <= 0) {
            p2.setHp(0);
        }

        cout << p1.getName() << " HP: " << p1.getHp() << "\n";
        cout << p2.getName() << " HP: " << p2.getHp() << "\n";
    }
}

void combateFinal(Personaje& p1, EnemigoFinal& p2) {
    cout << p1.getName() << " lucha contra " << p2.getName() << "!" << "\n";
    while (p1.getHp() > 0 && p2.getHp() > 0) {
        
        int ataque =rand() % 6;
        
        if (ataque == 0 || ataque == 1 || ataque == 2 || ataque == 3)
        {
            p1.setHp(p1.getHp() - p2.getAttack());
            p2.setHp(p2.getHp() - p1.getAttack());

            cout << p1.getName() << " recibio un ataque de normal de " << p2.getAttack() << "\n";
            cout << p2.getName() << " recibio un ataque de " << p1.getAttack() << "\n";

            if (p1.getHp() <= 0) {
                p1.setHp(0);
            }
            if (p2.getHp() <= 0) {
                p2.setHp(0);
            }

            cout << p1.getName() << " HP: " << p1.getHp() << "\n";
            cout << p2.getName() << " HP: " << p2.getHp() << "\n";
        }
        else if (ataque == 4)
        {
            p1.setHp(p1.getHp() - p2.getFrozenAttack());
            p2.setHp(p2.getHp() - p1.getAttack());

            cout << p1.getName() << " recibio un ataque de hielo de " << p2.getFrozenAttack() << "\n";
            cout << p2.getName() << " recibio un ataque de " << p1.getAttack() << "\n";

            if (p1.getHp() <= 0) {
                p1.setHp(0);
            }
            if (p2.getHp() <= 0) {
                p2.setHp(0);
            }

            cout << p1.getName() << " HP: " << p1.getHp() << "\n";
            cout << p2.getName() << " HP: " << p2.getHp() << "\n";
        }
        else if (ataque == 5)
        {
            p1.setHp(p1.getHp() - p2.getFireAttack());
            p2.setHp(p2.getHp() - p1.getAttack());

            cout << p1.getName() << " recibio un ataque de fuego de " << p2.getFireAttack() << "\n";
            cout << p2.getName() << " recibio un ataque de " << p1.getAttack() << "\n";

            if (p1.getHp() <= 0) {
                p1.setHp(0);
            }
            if (p2.getHp() <= 0) {
                p2.setHp(0);
            }

            cout << p1.getName() << " HP: " << p1.getHp() << "\n";
            cout << p2.getName() << " HP: " << p2.getHp() << "\n";
        }
    }
}

int main() {
    srand(time(0)); // Numeros aleatorios

    // Tamaño cueva
    int width = 10;
    int height = 5;

    // Crear cueva
    char cueva[5][10];

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cueva[i][j] = '*';
        }
    }

    // Crear heroe
    Personaje heroe(1000, "Steve", 20, heroe.dadoX(), 0);

    // Crear enemigos
    Personaje enemigos[4] = {
        Personaje(10, "Zombi", 5, enemigos[0].dadoX(), 0),
        Personaje(25, "Esqueleto", 10, enemigos[1].dadoX(), 1),
        Personaje(50, "Creeper", 25, enemigos[2].dadoX(), 2),
        Personaje(100, "Enderman", 20, enemigos[3].dadoX(), 3)
    };

    // Crear enemigo final
    EnemigoFinal enemigoFinal(200, "Dragon", 30, enemigoFinal.dadoX(), 4, 50, 40);

    //----------------------------INICIO JUEGO----------------------------
    while (true) {
        system("pause");
        system("cls");
        for (int row = 0; row < height; ++row) {
            for (int col = 0; col < width; ++col) {
                if (row == heroe.getY() && col == heroe.getX()) {
                    cout << 'H';
                }
                else {
                    bool isEnemy = false;
                    for (int i = 0; i < 4; i++) {
                        if (row == enemigos[i].getY() && col == enemigos[i].getX()) {
                            cout << 'E';
                            isEnemy = true;
                            break;
                        }
                    }
                    if (!isEnemy) {
                        if (row == enemigoFinal.getY() && col == enemigoFinal.getX()) {
                            cout << 'F';
                        }
                        else {
                            cout << cueva[row][col];
                        }
                    }
                }
                cout << ' ';
            }
            cout << endl;
        }

        int movimiento = 0;
        while (movimiento != 1 && movimiento != 2 && movimiento != 3 && movimiento != 4) {
            cout << "Introduce el movimiento:\n1 - Arriba\n2 - Abajo\n3 - Izquierda\n4 - Derecha\nOpcion: ";
            cin >> movimiento;

            if (movimiento != 1 && movimiento != 2 && movimiento != 3 && movimiento != 4) {
                cout << "Movimiento no valido. Intentalo de nuevo." << endl;
            }
        }

        // Movimientos
        switch (movimiento) {
        case 1: // Arriba
            if (heroe.getY() > 0) heroe.setY(heroe.getY() - 1);
            break;
        case 2: // Abajo
            if (heroe.getY() < height - 1) heroe.setY(heroe.getY() + 1);
            break;
        case 3: // Izquierda
            if (heroe.getX() > 0) heroe.setX(heroe.getX() - 1);
            break;
        case 4: // Derecha
            if (heroe.getX() < width - 1) heroe.setX(heroe.getX() + 1);
            break;
        default:
            break;
        }

        // Interacción con los enemigos
        for (int i = 0; i < 4; i++) {
            if (heroe.getX() == enemigos[i].getX() && heroe.getY() == enemigos[i].getY()) {
                combate(heroe, enemigos[i]);
                if (heroe.getHp() <= 0) {
                    cout << "El heroe ha sido derrotado!" << endl;
                    return 0;
                }
                if (enemigos[i].getHp() <= 0) {
                    cout << enemigos[i].getName() << " ha sido derrotado!" << endl;
                    // Eliminar al enemigo del tablero
                    enemigos[i].setX(-1);
                    enemigos[i].setY(-1);
                }
                break;
            }
        }

        // Interacción con el enemigo final
        if (heroe.getX() == enemigoFinal.getX() && heroe.getY() == enemigoFinal.getY()) {
            combateFinal(heroe, enemigoFinal);
            if (heroe.getHp() <= 0) {
                cout << "\n\n\n";
                cout << "                     ###################\n";
                cout << "                  ######             #######\n";
                cout << "               ####                       ####\n";
                cout << "              ###                             ##\n";
                cout << "             ##                                ##\n";
                cout << "            ##             GAME OVER            ##\n";
                cout << "           ##                                   ##\n";
                cout << "           ## ##                             ## ##\n";
                cout << "           ## ##                             ##  #\n";
                cout << "           ## ##                             ##  #\n";
                cout << "           ## ##                             ## ##\n";
                cout << "           ##  ##                           ##  ##\n";
                cout << "            ## ##   ########     ########   ## ##\n";
                cout << "             #### ##########     ########## #####\n";
                cout << "              ### ##########     ########## ###\n";
                cout << "     ###       ##  ########       #########  ##      ####\n";
                cout << "    #####     ##   #######   ###   #######   ##     ######\n";
                cout << "   ##   ##    ##     ###    #####    ###     ##    ##   ##\n";
                cout << "  ###    ####  ##          #######          ##  ####    ###\n";
                cout << " ##         ########       #######       #########        ##\n";
                cout << " #########     ########    #######    ########      ########\n";
                cout << "   #### #####      #####              ### ##     ###### ###\n";
                cout << "           ######  ###  ##           ##  ###  ######\n";
                cout << "               ###### ## ########### ## ######\n";
                cout << "                   ## ## # # # # # # # # ##\n";
                cout << "                 ####  # # # # # # # #   #####\n";
                cout << "             ##### ##   #############   ## #####\n";
                cout << "     ##########     ##                 ##      #########\n";
                cout << "    ##           #######             ########          ##\n";
                cout << "     ###     #####     ###############     #####     ###\n";
                cout << "       ##   ###           #########           ###   ##\n";
                cout << "       ##  ##                                   ##  ##\n";
                cout << "        ####                                     #####\n";
                return 0;
            }
            if (enemigoFinal.getHp() <= 0) {
                cout << "\n\n\n";
                cout << "###    ###    ######    ##     ##      ##         ##  ##  ###     ##\n";
                cout << "###    ###   ###  ###   ##     ##      ##         ##  ##  ####    ##\n";
                cout << "###    ###  ###    ###  ##     ##      ##         ##      ## ##   ##\n";
                cout << "  ######    ##      ##  ##     ##      ##         ##  ##  ##  ##  ##\n";
                cout << "   ####     ###    ###  ##     ##      ##   ###   ##  ##  ##   ## ##\n";
                cout << "   ####      ###  ###    ##   ##        ## ## ## ##   ##  ##    ####\n";
                cout << "   ####       ######      #####          ###   ###    ##  ##     ###\n";
                return 0;
            }
        }
    }

    return 0;
}
