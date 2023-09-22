#include <iostream>

using namespace std;

/*
* Funci�n RecieveValidInput
* Modulo para ser reutilizado en todos los programas
*/

int recieveValidInput(int minNumber, int maxNumber, bool limpiarPantalla) {
    int num;
    bool validInput = false;

    while (!validInput) {

        if (!(cin >> num) || num  < minNumber || num > maxNumber) {
            cout << "Entrada invalida. Debe de ingresar un numero entre " << minNumber << " y " << maxNumber << endl;
            cin.clear();
            cin.ignore(100000, '\n');
        }
        else {
            validInput = true;

            if (limpiarPantalla)
            {
                system("cls");
            }
        }
    }

    return num;
}