#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Define la estructura de los personajes (heroe y enemigos)
struct Character {
    string name;
    int attackFist;
    int attackSword;
    int attackMagic;
    int hp;
    bool isAlive;
};

// Función ataques aleatorios
int getRandomAttack(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    srand(time(0)); // Semilla de numeros aleatorios

    Character hero;
    hero.attackFist = 20;       // Ataque Golpe
    hero.attackSword = 50;      // Ataque Espada
    hero.attackMagic = 0;       // Ataque Magia
    hero.hp = 500;              // Vida del Heroe
    hero.isAlive = true;        // Estado de vida

    Character enemy1;
    enemy1.name = "Hansel";     // Nombre Enemigo1
    enemy1.attackFist = 0;      // Ataque Enemigo1
    enemy1.hp = 250;            // Vida Enemigo1
    enemy1.isAlive = true;      // Estado de vida

    Character enemy2;
    enemy2.name = "Gretel";     // Nombre Enemigo2
    enemy2.attackFist = 0;      // Ataque Enemigo2
    enemy2.hp = 250;            // Vida Enemigo2
    enemy2.isAlive = true;      // Estado de vida

    int chosenEnemy;            // Variable escoger Enemigo
    int chosenAttack;           // Variable escoger Ataque
    int magicUses = 3;          // Veces que se puede usar magia

    cout << "Escribe el nombre de tu personaje\n";
    cin >> hero.name; // Para ponerle nombre al heroe

    while (hero.isAlive && (enemy1.isAlive || enemy2.isAlive)) {
        // Verifica si la salud del heroe llega a 0 o menos
        if (hero.hp <= 0) {
            hero.isAlive = false;
            break; // Sale del bucle principal
        }

        // Tabla de Vida de los Personajes
        cout << "------------------------------------------------\n";
        cout << "Estado actual:\n";
        cout << hero.name << " HP: " << hero.hp << "\n";
        if (enemy1.isAlive) {
            cout << enemy1.name << " HP: " << enemy1.hp << "\n";
        }
        if (enemy2.isAlive) {
            cout << enemy2.name << " HP: " << enemy2.hp << "\n";
        }
        cout << "------------------------------------------------\n";

        // Escoger Enemigo
        cout << "Escoje que enemigo atacar:\n";
        if (enemy1.isAlive) {
            cout << "1. " << enemy1.name << "\n";
        }
        if (enemy2.isAlive) {
            cout << "2. " << enemy2.name << "\n";
        }
        cin >> chosenEnemy;
        cout << "------------------------------------------------\n";

        // Escoger Ataque
        cout << "Escoje con que atacar:\n";
        cout << "1. Golpe (-20HP)\n";
        cout << "2. Espada (-50HP)\n";
        cout << "3. Magia (-80HP a -100HP) (Disponible " << magicUses << " veces)\n";
        cin >> chosenAttack;
        cout << "------------------------------------------------\n";

        // Variables para ataques aleatorios
        int damage = 0;
        int damageEnemy1 = 0;
        int damageEnemy2 = 0;

        // Si escojes Golpe
        if (chosenAttack == 1) {
            damage = hero.attackFist;
            cout << "Has atacado con un golpe de 20HP.\n";
        }
        // Si escojes Espada
        else if (chosenAttack == 2) {
            damage = hero.attackSword;
            cout << "Has atacado con un espadazo de 50HP.\n";
        }
        // Si escojes Magia
        else if (chosenAttack == 3) {
            if (magicUses > 0) {
                magicUses--;
                damage = getRandomAttack(80, 100);
                cout << "Has atacado con un golpe de " << damage << "HP.\n";
            }
            else {
                cout << "No tienes mas usos de magia.\n";
                continue; // Salta al siguiente bucle
            }
        }

        // Si escojes Atacar Enemigo1
        if (chosenEnemy == 1 && enemy1.isAlive) {
            enemy1.hp -= damage;
            int damageEnemy1 = getRandomAttack(25, 40);
            hero.hp -= damageEnemy1;
            cout << enemy1.name << " hizo un ataque de " << damageEnemy1 << "HP\n";

            // Verifica si el enemigo 2 esta vivo antes de atacar
            if (enemy2.isAlive) {
                int damageEnemy2 = getRandomAttack(25, 40);
                hero.hp -= damageEnemy2;
                cout << enemy2.name << " hizo un ataque de " << damageEnemy2 << "HP\n";
            }

            // Verificar si el enemigo 1 esta muerto
            if (enemy1.hp <= 0) {
                enemy1.isAlive = false;
                enemy1.hp = 0;
                cout << enemy1.name << " esta muerto.\n";
            }
        }
        // Si escojes Atacar Enemigo2
        else if (chosenEnemy == 2 && enemy2.isAlive) {
            enemy2.hp -= damage;
            int damageEnemy2 = getRandomAttack(25, 40);
            hero.hp -= damageEnemy2;
            cout << enemy2.name << " hizo un ataque de " << damageEnemy2 << "HP\n";

            // Verifica si el enemigo 1 está vivo antes de atacar
            if (enemy1.isAlive) {
                int damageEnemy1 = getRandomAttack(25, 40);
                hero.hp -= damageEnemy1;
                cout << enemy1.name << " hizo un ataque de " << damageEnemy1 << "HP\n";
            }

            // Verificar si el enemigo 2 está muerto
            if (enemy2.hp <= 0) {
                enemy2.isAlive = false;
                enemy2.hp = 0;
                cout << enemy2.name << " esta muerto.\n";
            }
        }
    }

    // Finales
    if (!hero.isAlive) {
        cout << "El heroe ha muerto. Juego terminado!\n";
    }
    else {
        cout << "Has derrotado a todos los enemigos Ganaste!\n";
    }

    return 0;
}