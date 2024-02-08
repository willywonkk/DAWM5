#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Variables
int mazo[4][13] = { {1,2,3,4,5,6,7,8,9,10,11,12,13},
                    {1,2,3,4,5,6,7,8,9,10,11,12,13},
                    {1,2,3,4,5,6,7,8,9,10,11,12,13},
                    {1,2,3,4,5,6,7,8,9,10,11,12,13} 
};

int puntuacionJugador = 0;
int puntuacionCroupier = 0;
string otraCarta;
int apuesta;

//Funciones 
int valorCarta(int pCarta, int pPalo, bool pEsJugador) {
    string lvPalo;
    int lvValorFinal = 0;
    switch (pPalo) {
    case 0:
        lvPalo = "Corazones";
        break;
    case 1:
        lvPalo = "Picas";
        break;
    case 2:
        lvPalo = "Diamantes";
        break;
    case 3:
        lvPalo = "Treboles";
        break;
    }

    if (pCarta == 1) {
        //Es un AS
        int AS;
        if(pEsJugador){
            do
            {
              cout << "La carta es un AS de " << lvPalo << "\n";
              cout << "Cuanto quieres que valga (1 o 11): ";
              cin >> AS;
            } while (AS != 1 && AS != 11);
            lvValorFinal = AS;
        }
        else {
            if (puntuacionCroupier + 11 > 21)
            {
                cout << "La carta es un AS de " << lvPalo << "\n";
                lvValorFinal = 1;
            }
            else
            {
                cout << "La carta es un AS de " << lvPalo << "\n";
                lvValorFinal = 11;
            }

        }
    }
    else if (pCarta > 1 && pCarta < 11) {
        //El mismo numero
        lvValorFinal = pCarta;
        cout << "La carta es un " << lvValorFinal << " de " << lvPalo << "\n";
    }
    else if (pCarta == 11) {
        //Es una J
        lvValorFinal = 10;
        cout << "La carta es una J de " << lvPalo << "\n";
    }
    else if (pCarta == 12) {
        //Es una Q
        lvValorFinal = 10;
        cout << "La carta es una Q de " << lvPalo << "\n";
    }
    else if (pCarta == 13) {
        //Es una K
        lvValorFinal = 10;
        cout << "La carta es una K de " << lvPalo << "\n";
    }

    return lvValorFinal;
}

int repartirCarta(bool pEsJugador) {

    bool lvCartaDisponible = false;
    int lvCartaCalculada = 0;

    while (lvCartaDisponible == false) {
        //Nos da numero entre 0 y 12
        int lvCarta = rand() % 13;
        //Nos da numero entre 0 y 3
        int lvPalo = rand() % 4;
        if (mazo[lvPalo][lvCarta] > 0) {
            //La carta está disponible
            lvCartaCalculada = valorCarta(mazo[lvPalo][lvCarta], lvPalo, pEsJugador);
            lvCartaDisponible = true;
            mazo[lvPalo][lvCarta] = 0;
        }
    }
    return lvCartaCalculada;
}

int main() {
    srand(time(0)); // Semilla de números aleatorios
    
    //Apuesta
    cout << "Cuanto dinero quieres apostar?: ";
    cin >> apuesta;

    //Primeras cartas a repartir
    puntuacionJugador += repartirCarta(true);
    cout << "El jugador tiene ahora " << puntuacionJugador << " puntos\n";
    puntuacionJugador += repartirCarta(true);
    cout << "El jugador tiene ahora " << puntuacionJugador << " puntos\n";
    puntuacionCroupier += repartirCarta(false);
    cout << "El croupier tiene ahora " << puntuacionCroupier << " puntos\n";

    // Partida
    if (puntuacionJugador == 21) {
        cout << "El jugador ha conseguido 21!\n";
        
        // Repartir croupier
        while (puntuacionCroupier < 17) {
            puntuacionCroupier += repartirCarta(false);
            cout << "El croupier tiene ahora " << puntuacionCroupier << " puntos\n";
        }
        
        // RESULTADOS
        if (puntuacionCroupier > 21 || puntuacionJugador > puntuacionCroupier) {
            cout << "El jugador gana!\n";
            cout << "Has ganado " << apuesta * 1.5 << "$";
        }
        else if (puntuacionJugador == puntuacionCroupier) {
            cout << "Empate\n";
            cout << "No has perdido nada de tu apuesta de " << apuesta << "$";
        }
        else {
            cout << "El crupier gana!\n";
            cout << "Has perdido " << apuesta << "$";
        }
    }
    else {
        // Pedir cartas jugador
        do {
            cout << "Quieres otra carta? (si/no): ";
            cin >> otraCarta;
            if (otraCarta == "si") {
                puntuacionJugador += repartirCarta(true);
                cout << "El jugador tiene ahora " << puntuacionJugador << " puntos\n";
                if (puntuacionJugador > 21) {
                    cout << "El jugador se ha pasado de 21. El crupier gana!\n";
                    return 0;
                }
            }
        } while (otraCarta == "si");

        // Repartir croupier
        while (puntuacionCroupier < 17) {
            puntuacionCroupier += repartirCarta(false);
            cout << "El croupier tiene ahora " << puntuacionCroupier << " puntos\n";
        }

        // RESULTADOS
        if (puntuacionCroupier > 21 || puntuacionJugador > puntuacionCroupier) {
            cout << "El jugador gana!\n";
            cout << "Has ganado " << apuesta * 2 << "$";
        }
        else if (puntuacionJugador == puntuacionCroupier) {
            cout << "Empate\n";
            cout << "No has perdido nada de tu apuesta de " << apuesta << "$";
        }
        else {
            cout << "El crupier gana!\n";
            cout << "Has perdido " << apuesta << "$";
        }
    }
    

    return 0;
}
