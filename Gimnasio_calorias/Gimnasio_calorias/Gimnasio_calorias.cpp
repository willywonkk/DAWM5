#include <iostream>
#include <ctime>
#include <cstdlib>
#include "funcion.h"

using namespace std;

// Variables
string sexo;
int edad;
int peso;
int altura;
string ejercio;
double MB;
int grado;
double actFisica[5]{ 1.2, 1.375, 1.55, 1.725, 1.9 };
double metDeportes[9]{ 9.5, 4.5, 8, 8, 9, 8, 5, 6.5, 5.5 };
int tiempo;

int main()
{
    do {
        cout << "Cual es tu genero? 'H' o 'M': ";
        cin >> sexo;
    } while (sexo != "H" && sexo != "M");

    cout << "\nCuantos años tienes?: ";
    cin >> edad;

    cout << "\nCuanto pesas?(Kg): ";
    cin >> peso;

    cout << "\nCuanto mides?(cm): ";
    cin >> altura;

    do {
        cout << "\nQue tipo de ejercicio has realizado un 'Deporte' o ejerecicio de 'Pesas': ";
        cin >> ejercio;
    } while (ejercio != "Deporte" && ejercio != "Pesas");

    cout << "\nDel 1 al 5 cual es tu actividad fisica semanal teniendo en cuanta lo siguiente:\n";
    cout << " 1 - Poco o ningun ejercicio\n";
    cout << " 2 - Ejercicio ligero / deportes 1-3 dias a la semana\n";
    cout << " 3 - Ejercicio moderado / deportes 3-5 dias a la semana\n";
    cout << " 4 - Ejercicio duro / deportes 6-7 dias a la semana\n";
    cout << " 5 - Ejercicio muy duro, trabajo fisico\n";

    do {
        cout << "Escribre tu opcion (1-5): ";
        cin >> grado;
    } while (grado < 1 || grado > 5);

    if (ejercio == "Deporte") {
        cout << "\nQue deporte has realizado:\n";
        cout << " 1 - Correr\n";
        cout << " 2 - Caminata\n";
        cout << " 3 - Ciclismo\n";
        cout << " 4 - Baloncesto\n";
        cout << " 5 - Futbol\n";
        cout << " 6 - Natacion\n";
        cout << " 7 - Voleibol\n";
        cout << " 8 - Tenis\n";
        cout << " 9 - Badminton\n";
        int dep;
        do {
            cout << "Escribre tu opcion (1-9): ";
            cin >> dep;
        } while (dep < 1 || dep > 9);

        cout << "\nDuracion del deporte realizado (min): ";
        cin >> tiempo;

        double caloriasQuemadas = calculadoraKcal::fDeporte(sexo, edad, peso, altura, tiempo, actFisica[grado - 1], metDeportes[dep - 1]);
        cout << "\n---------------------------------------------------------------------------------\n";
        cout << "Durante un tiempo de " << tiempo << "min de deporte has quemado un total de " << caloriasQuemadas << "Kcal";
        cout << "\n---------------------------------------------------------------------------------\n";
    }
    else if (ejercio == "Pesas") {
        cout << "\nQue ejercicio de pesas has realizado:\n";
        cout << " 1 - Press banca\n";
        cout << " 2 - Press militar\n";
        cout << " 3 - Peso muerto\n";
        cout << " 4 - Sentadilla\n";
        cout << " 5 - Remo\n";

        int opcion_pesas;
        do {
            cout << "Escribe tu opcion (1-5): ";
            cin >> opcion_pesas;
        } while (opcion_pesas < 1 || opcion_pesas > 5);

        cout << "\nDuracion del ejercicio de pesas realizado (min): ";
        cin >> tiempo;

        double caloriasQuemadas = calculadoraKcal::fPesas(opcion_pesas, tiempo);
        cout << "\n---------------------------------------------------------------------------------\n";
        cout << "Durante un tiempo de " << tiempo << "min de pesas has quemado un total de " << caloriasQuemadas << "Kcal";
        cout << "\n---------------------------------------------------------------------------------\n";
    }

    return 0;
}