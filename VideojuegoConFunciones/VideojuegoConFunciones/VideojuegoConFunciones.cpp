#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Variables del héroe
string heroName;
int heroAttackFist = 20;       // Ataque Golpe
int heroAttackSword = 50;      // Ataque Espada
int damage = 0;                // Ataque Magia
int magicUses = 3;             // Veces que se puede usar magia
int heroHP = 500;              // Vida del Héroe
bool heroAlive = true;         // Está vivo al principio

// Variables del enemigo 1
string enemy1Name = "Hansel";  // Nombre Enemigo 1
int damageEnemy1 = 0;          // Ataque Enemigo 1
int enemy1HP = 2º50;            // Vida Enemigo 1
bool enemy1Alive = true;       // Está vivo al principio

// Variables del enemigo 2
string enemy2Name = "Gretel";  // Nombre Enemigo 2
int damageEnemy2 = 0;          // Ataque Enemigo 2
int enemy2HP = 250;            // Vida Enemigo 2
bool enemy2Alive = true;       // Está vivo al principio

int chosenEnemy;               // Variable escoger Enemigo
int chosenAttack;              // Variable escoger Ataque

// Declaraciones de funciones
void assignHeroName(string& heroName);
int selectEnemy();
void selectAttack();
bool attackEnemy();
int getRandomAttack(int min, int max);

// Función pedir nombre
void assignHeroName(string& heroName) {
    cout << "Escribe el nombre de tu personaje\n";
    cin >> heroName;
}

// Función escoger ataque
void selectAttack() {
    do {
    cout << "Escoje con que atacar:\n";
    cout << "1. Golpe (-20HP)\n";
    cout << "2. Espada (-50HP)\n";
    cout << "3. Magia (-80HP a -100HP) (Disponible " << magicUses << " veces)\n";
    cin >> chosenAttack;
    cout << "------------------------------------------------\n";
    } while (chosenAttack != 1 && chosenAttack != 2 && chosenAttack != 3);
}

// Función escoger Enemigo
int selectEnemy() {
    cout << "Escoje que enemigo atacar:\n";
    cout << "1. " << enemy1Name << "\n";
    cout << "2. " << enemy2Name << "\n";
    cin >> chosenEnemy;
    cout << chosenEnemy;
    cout << "------------------------------------------------\n";

    // Si no introduce 1 o 2 dependiendo de la situación
    if (enemy1Alive && enemy2Alive) {
        if (chosenEnemy == 1 || chosenEnemy == 2) {
            return chosenEnemy;
        }
        else {
            return 1;
        }
    }
    else if (!enemy1Alive && enemy2Alive) {
        return 2;
    }
    else if (enemy1Alive && !enemy2Alive) {
        return 1;
    }
    else {
        return 1;
    }

}

// Función atacar enemigo
bool attackEnemy() {
    // Si escoges Atacar Enemigo 1
    if (chosenEnemy == 1 && enemy1Alive) {
        if (enemy1HP > 1) {
            
            damageEnemy1 = getRandomAttack(25, 40);
            heroHP -= damageEnemy1;
            cout << enemy1Name << " hizo un ataque de " << damageEnemy1 << "HP\n";
            if (enemy2Alive) {
                damageEnemy2 = getRandomAttack(25, 40);
                heroHP -= damageEnemy2;
                cout << enemy2Name << " hizo un ataque de " << damageEnemy2 << "HP\n";
            }
            else if (!enemy2Alive) {
                cout << enemy2Name << " esta muerto.\n";
            }
            enemy1HP -= damage;
            cout << "Has atacado con un golpe de " << damage << "HP a " << enemy1Name << "\n";
        }
        else if (enemy1HP <= 0) {
            enemy1Alive = false;
            enemy1HP = 0;
            cout << enemy1Name << " esta muerto.\n";
        }

    }
    else if (chosenEnemy == 1 && !enemy1Alive) {
        cout << "No puedes atacar a un enemigo muerto.\n";
    }

    // Si escoges Atacar Enemigo 2
    if (chosenEnemy == 2 && enemy2Alive) {
        if (enemy2HP > 1) {
            
            damageEnemy2 = getRandomAttack(25, 40);
            heroHP -= damageEnemy2;
            cout << enemy2Name << " hizo un ataque de " << damageEnemy2 << "HP\n";
            if (enemy1Alive) {
                damageEnemy1 = getRandomAttack(25, 40);
                heroHP -= damageEnemy1;
                cout << enemy1Name << " hizo un ataque de " << damageEnemy1 << "HP\n";
            }
            else if (!enemy1Alive) {
                cout << enemy1Name << " esta muerto.\n";
            }
            enemy2HP -= damage;
            cout << "Has atacado con un golpe de " << damage << "HP a " << enemy2Name << "\n";
        }
        else if (enemy2HP <= 0) {
            enemy2Alive = false;
            enemy2HP = 0;
            cout << enemy2Name << " esta muerto.\n";
        }
    }
    else if (chosenEnemy == 2 && !enemy2Alive) {
        cout << "No puedes atacar a un enemigo muertoooooooooo.\n";
    }
    bool heroIsAlive = (heroHP > 0);
    return heroIsAlive;
}

// Función ataques aleatorios
int getRandomAttack(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    srand(time(0)); // Semilla de números aleatorios
    
    system("color f3");
    
    // Llamar función pedir nombre
    assignHeroName(heroName);
    
    while (heroAlive && (enemy1Alive || enemy2Alive)) {
        // Verifica si la salud del héroe llega a 0 o menos
        if (heroHP <= 0) {
            heroAlive = false;
            break; // Sale del bucle principal
        }
        if (enemy1HP <= 0) {
            enemy1Alive = false;
        }
        if (enemy2HP <= 0) {
            enemy2Alive = false;
        }
        if ((enemy1HP <= 0)&&(enemy2HP <= 0)) {
            break;
        }

        // Tabla de Vida de los Personajes
        cout << "------------------------------------------------\n";
        cout << "Estado actual:\n";
        cout << heroName << " HP: " << heroHP << "\n";
        if (enemy1HP > 1) {
            cout << enemy1Name << " HP: " << enemy1HP << "\n";
        }
        else {
            cout << enemy1Name << ": ESTA MUERTO\n";
        }
        if (enemy2HP > 1) {
            cout << enemy2Name << " HP: " << enemy2HP << "\n";
        }
        else {
            cout << enemy2Name << ": ESTA MUERTO\n";
        }
        cout << "------------------------------------------------\n";
        
        chosenEnemy = selectEnemy();

        selectAttack();

        // Si escoges Golpe
        if (chosenAttack == 1) {
            damage = heroAttackFist;
            attackEnemy();
        }
        // Si escoges Espada
        else if (chosenAttack == 2) {
            damage = heroAttackSword;
            attackEnemy();
        }
        // Si escoges Magia
        else if (chosenAttack == 3) {
            if (magicUses > 0) {
                magicUses--;
                damage = getRandomAttack(80, 100);
                attackEnemy();

            }
            else {
                cout << "No tienes más usos de magia.\n";
                continue; // Salta al siguiente bucle
            }
        }
        system("pause");
        system("cls");
    }

    // Finales
    if (!heroAlive) {
        cout << "El heroe ha muerto. Juego terminado!\n\n";
            cout << "                     ###################\n";
            cout << "                  ######             #######\n";
            cout << "               ####                       ####\n";
            cout << "              ###                             ##\n";
            cout << "             ##                                ##\n";
            cout << "            ##           YOU     LOSE           ##\n";
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



    }
    else {
        cout << "Has derrotado a todos los enemigos. GANASTES\n\n";
        cout << "        ##########################\n";
        cout << "        ##########################\n";
        cout << "   ####################################\n";
        cout << " #######################################\n";
        cout << "####       ####################       ####\n";
        cout << "###       ######################        ###\n";
        cout << "##        ######################         ##\n";
        cout << "###     ##########################      ###\n";
        cout << "###    ############################    ####\n";
        cout << " ###   ### #################### ###    ###\n";
        cout << " ####   ### ################## ####  ####\n";
        cout << "   ####  ########################  ####\n";
        cout << "    ######## ################ #########\n";
        cout << "      ######  ##############  #######\n";
        cout << "               ############\n";
        cout << "                 ########\n";
        cout << "                   ####\n";
        cout << "                   ####\n";
        cout << "                   ####\n";
        cout << "                   ####\n";
        cout << "               ############\n";
        cout << "            ##################\n";
        cout << "            ##################\n";
        cout << "            ###            ###\n";
        cout << "            ###  YOU  WIN  ###\n";
        cout << "            ###            ###\n";
        cout << "            ##################\n";
        cout << "            ##################\n";
        cout << "          ######################\n";
        cout << "         ########################\n";
    }
    return 0;
}