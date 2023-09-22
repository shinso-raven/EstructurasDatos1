#include "Input.h"
#include "Stack.h"
#include "Queue.h"
#include "LinkList.h"

using namespace std;

/*
*   Enunciado: Desarrollar un Stack utilizando punteros
*              Desarrollar un Queue con prioridad utilizando punteros
*              Desarrollar una Linked List simplemente enlazada utilizando punteros
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
    9/8/2023
*/


int main() {

    int userSelection;
    bool exitProgram = false;

    while (!exitProgram) {
        cout << "DEMO: Estructuras de Datos - Stack, Queue y Linked List\n\nIngrese la opcion que desea ejecutar:\n"
            "1. Ejecutar Demo Stack\n2. Ejecutar Demo Queue\n3. Ejecutar Demo lista simplemente enlazada\n4. Salir del programa.\n";
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
