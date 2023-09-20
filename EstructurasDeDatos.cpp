#include "Input.h"
#include "Stack.h"
#include "Queue.h"
#include "LinkList.h"

using namespace std;

/*
*   Enunciado: Desarrollar un Stack y un Queue con prioridad utilizando punteros
*
*   Participantes
    Leonardo Perozo - 1116588
    Jos� Ram�rez - 1115411
    Radhames Ventura - 1116252
    Juan Lopera -  1116184
    Mario Senra - 1116742
    Manuel Pucheu - 1115846
    �ngel Soriano - 1107555

    Fecha de entrega:
    8/24/2023
*/


int main() {

    int userSelection;
    bool exitProgram = false;

    while (!exitProgram) {
        cout << "DEMO: Estructuras de Datos - Stack y Queue\n\nIngrese la opcion que desea ejecutar:\n"
            "1. Ejecutar Demo Stack\n"<<
            "2. Ejecutar Demo Queue\n"<< 
            "3. Ejecutar Demo lista simplemente enlazada\n"<<
            "4. Salir del programa.\n";
        userSelection = recieveValidInput(1, 4);
        system("cls");

        switch (userSelection)
        {
        case 1:
            ExecuteStackProgram();
            break;
        case 2:
            ExecuteQueueProgram();
            break;
        case 3:
            EjecutarProgramaLinkedList();
            break;
        case 4:
            exitProgram = true;
        default:
            break;
        }
    }



    return 0;
}
