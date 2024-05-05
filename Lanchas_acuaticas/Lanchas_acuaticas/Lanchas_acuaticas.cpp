#include "Lanchas.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(NULL)); // Numeros aleatorios

    // Crear lancha 1
    string nombreLancha1;
    cout << "Ingresa el nombre de la lancha 1: ";
    cin >> nombreLancha1;
    Lancha lancha1(0, nombreLancha1, 0, 1);

    // Crear lancha 2
    string nombreLancha2;
    cout << "Ingresa el nombre de la lancha 2: ";
    cin >> nombreLancha2;
    Lancha lancha2(0, nombreLancha2, 0, 1);

    system("cls");

    // Comenzar la carrera
    for (int i = 0; i < 5; ++i) {
        cout << "--------------\n";
        cout << "|  TURNO " << i + 1 << "   |\n";
        cout << "--------------\n";


        // Jugador 1
        cout << "\nTurno de " << lancha1.getName() << "\n";
        system("pause");


        int dado1 = lancha1.dado(); // Lanzar el dado
        cout << "La lancha de " << lancha1.getName() << " lanzo un dado y obtuvo: " << dado1 << endl;
        lancha1.calculateVelocidad(dado1); // Calcular velocidad
        lancha1.calculateDistance(lancha1.getDistRecorrida(), lancha1.getVelocidad());
        cout << "Distancia recorrida: " << lancha1.getDistRecorrida() << "m" << endl;
        

        // Preguntar si quiere usar nitro si no se ha utilizado ya
        char respuesta;
        if (lancha1.getNitro() == 1) {
            char respuesta;
            cout << "Quieres usar nitro en la lancha " << lancha1.getName() << "? (s/n): ";
            cin >> respuesta;
            if (respuesta == 's') {
                lancha1.calcularNitro();
                cout << "Distancia recorrida: " << lancha1.getVelocidad() * 100 << endl;
                lancha1.setNitro(0); //Nitro pasa a 0
            }
        }

        // Jugador 2
        cout << "\nTurno de " << lancha2.getName() << "\n";
        system("pause");


        int dado2 = lancha2.dado();
        cout << "La lancha de " << lancha2.getName() << " lanzo un dado y obtuvo: " << dado2 << endl;
        lancha2.calculateVelocidad(dado2);
        lancha2.calculateDistance(lancha2.getDistRecorrida(), lancha2.getVelocidad());
        cout << "Distancia recorrida: " << lancha2.getDistRecorrida() << "m" << endl;
        

        // Preguntar si quiere usar nitro
        if (lancha2.getNitro() == 1) {
            char respuesta;
            cout << "Quieres usar nitro en la lancha " << lancha2.getName() << "? (s/n): ";
            cin >> respuesta;
            if (respuesta == 's') {
                lancha2.calcularNitro();
                cout << "Distancia recorrida: " << lancha2.getVelocidad() * 100 << endl;
                lancha2.setNitro(0); //Nitro pasa a 0
            }
        }

        cout << endl;
        system("pause");
        system("cls");
    }

    // Mostrar resultado de la carrera
    cout << "Resultado de la carrera:" << endl;
    if (lancha1.getDistRecorrida() > lancha2.getDistRecorrida()) {
        cout << "La lancha " << lancha1.getName() << " ha ganado la carrera!\n\n";
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
        cout << "            ###  " << lancha1.getName() << "  ###\n";
        cout << "            ###            ###\n";
        cout << "            ##################\n";
        cout << "            ##################\n";
        cout << "          ######################\n";
        cout << "         ########################\n\n\n";
    }
    else if (lancha1.getDistRecorrida() < lancha2.getDistRecorrida()) {
        cout << "La lancha " << lancha2.getName() << " ha ganado la carrera!\n\n";
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
        cout << "            ###  " << lancha2.getName() << "  ###\n";
        cout << "            ###            ###\n";
        cout << "            ##################\n";
        cout << "            ##################\n";
        cout << "          ######################\n";
        cout << "         ########################\n\n\n";
    }
    else {
        cout << "Ha habido un empate!\n\n\n";
    }

    return 0;
}
