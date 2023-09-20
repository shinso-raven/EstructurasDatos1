#include <iostream>

using namespace std;

int recieveValidInput(int minNumber, int maxNumber) {
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
            system("cls");
        }
    }

    return num;
}