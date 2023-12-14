/*#include <iostream>
int main()

{
    using namespace std;
        srand(time(NULL));
   
    
    //main character
    string characterName;
    int characterAttackValue = 0;
    int characterHPValue = 1000;

    //boss character
    string bossName = "Malenia";
    int bossAttackValue = 0;
    int bossHPValue = 1000;

    //Enter character name
    cout << "Escribe el nombre de tu personaje\n";
    cin >> characterName;

    //main game
    while (bossHPValue > 0 && characterHPValue > 0) {
        int characterAttackValue = rand() % 50 + 50;
        int bossAttackValue = rand() % 50 + 75;
        bossHPValue = bossHPValue - characterAttackValue;
        
        if (bossHPValue < 0){
            bossHPValue = 0;
        }
        
        cout << "Has atacado a " << bossName << " con un ataque de " << characterAttackValue << " puntos y le quedan " << bossHPValue << " puntos de vida\n";
        
        if (bossHPValue <= 0) {
            cout << "Has derrotado a " << bossName << "\n";
        }
        
        else {
            characterHPValue = characterHPValue - bossAttackValue;
            if (characterHPValue <= 0) {
                cout << bossName << " te ha dado un espadazo con un ataque de " << bossAttackValue << " puntos y te ha dado matarile\n";
            }
            else {
                cout << bossName << " te ha dado un espadazo con un ataque de " << bossAttackValue << " puntos y te quedan " << characterHPValue << " puntos de vida\n";
            }
        }
    }







    string nameAndSurname = "Guillermo Escrig";
    cout << "Hello " + nameAndSurname + "\n";
    int number1 = 21;
    int number2 = 12;
    int resultado = number1 + number2;
        cout << "La suma de " << number1 << " y " << number2 << " es " << resultado << "\n";

    int number3;
    cout << "Inserta el primer numero: ";
    cin >> number3;
    int number4;
    cout << "Inserta el segundo numero: ";
    cin >> number4;
    cout << "La suma de " << number3 << " y " << number4 << " es " << resultado << "\n";


    bool isActive = true;
    if (isActive) {
        cout << "El check esta activo\n";
    }
    else  {
        cout << "El check no esta activo\n";
    }


    int number;

    cout << "Inserta un numero: ";
    cin >> number;

    if (number > 20) {
        cout << "el numero que has insertado es mayor que 20\n";
    }
    else if (number == 20) {
        cout << "El numero que has insertado es igual a 20";
    }
    else {
        cout << "el numero que has insertado es menor que 20\n";
    }


}*/
#include <iostream>
using namespace std;
int number1 = 0;
int number2 = 4;

void showParam(int& p1, int p2) {
    p1 = 10;
    p2 = 50;
    int number1 = 0;
    int number2 = 4;
    cout << "El valor de P1 es: " << p1 << "\n";
    cout << "El valor de P2 es: " << p2 << "\n";
}

int main(){
    showParam(number1, number2);
    cout << "El valor de number1 es: " << number1 << "\n";
    cout << "El valor de number2 es: " << number2 << "\n";
}