/*
*   Enunciado: Desarrollar una Linked List simplemente enlazada utilizando punteros
*               La lista debe de estar ordenada de manera ascendente
*               Funcionalidades: Insertar, eliminar, buscar, desplegar y vaciar
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

using namespace std;

struct NodoLinkedList {
    int dato;
    NodoLinkedList* siguiente;
};

void InsertarLista(NodoLinkedList*& first, NodoLinkedList*& last) {
    int n;
    NodoLinkedList* nuevo_nodo = new NodoLinkedList();
    NodoLinkedList* aux1;
    NodoLinkedList* previo_nodo;

    cout << "Digite un numero: ";
    n = recieveValidInput(0, INT_MAX);
    nuevo_nodo->dato = n;
    aux1 = first;
    previo_nodo = nullptr;

    while ((aux1 != nullptr) && (aux1->dato < n)) {   // mientras no se nulo y el valor menor a nuevo. 
        previo_nodo = aux1;                             //hasta llegar a un nodo mayor o terminar la lista
        aux1 = aux1->siguiente;
    }
    if (first == nullptr && last == nullptr) { // lista vacia
        first = nuevo_nodo;
        last = nuevo_nodo;

    }
    else {
        if (first == aux1) { // first mayor que nuevo
            first = nuevo_nodo;
            nuevo_nodo->siguiente = aux1;
            return;
        }
        if (last == aux1) {  // Agregar nuevo al final

            last->siguiente = nuevo_nodo;
            last = nuevo_nodo;
            return;
        }
        previo_nodo->siguiente = nuevo_nodo;
        nuevo_nodo->siguiente = aux1;
    }
    nuevo_nodo->siguiente = aux1;
    cout << "Elemento " << n << " insertado correctamente" << endl;
}

void MostrarElemento(NodoLinkedList*& first) {
    NodoLinkedList* actual = first;


    while (actual != nullptr) {
        cout << actual->dato << "->";
        actual = actual->siguiente;
    }
    cout << "Vacio" << endl;
}

void BuscarNodo(NodoLinkedList*& first) {
    int n;

    bool elementoEncontrado = false;
    NodoLinkedList* actual = new NodoLinkedList();
    actual = first;

    cout << "Inserte el numero que desea buscar: \n";
    n = recieveValidInput(0, INT_MAX);

    while (actual != NULL && actual->dato <= n) {
        if (actual->dato == n) {
            elementoEncontrado = true;
        }
        actual = actual->siguiente;
    }

    if (elementoEncontrado) {
        cout << "Elemento " << n << " encontrado en la lista \n";

    }
    else {
        cout << "El elemento " << n << " no existe en la lista \n";
    }
}

void EliminarNodo(NodoLinkedList*& first, NodoLinkedList*& last) {
    int n;
    NodoLinkedList* actual;
    NodoLinkedList* aux;

    bool elementoEncontrado = false;
    bool respuestaEncontrada = false;

    actual = first;
    aux = actual;

    cout << "Inserte el numero que desea eliminar: \n";
    n = recieveValidInput(0, INT_MAX);

    while (!respuestaEncontrada) {
        if (actual == NULL) { // Elemento no existe, pero menor a elementos 
            respuestaEncontrada = true;
        }
        else {
            if (actual->dato > n) {// Elemento no existe y mayor a todo
                respuestaEncontrada = true;
            }

            if (actual->dato == n) { // Elemento encontrado
                elementoEncontrado = true;
                respuestaEncontrada = true;
                if (actual == first) {
                    first = actual->siguiente;
                }

                if (actual == last) {
                    last = aux;
                }

                aux->siguiente = actual->siguiente;
            }
            else {
                aux = actual;
                actual = actual->siguiente;
            }
        }


    }



    if (elementoEncontrado) {
        cout << "Elemento " << n << " eliminado correctamente \n";
        delete actual;
    }
    else {
        cout << "Elemento " << n << " no existe en la lista. Por lo tanto, no se puede eliminar. \n";
    }
}

void VaciarLista(NodoLinkedList*& first, NodoLinkedList*& last) {
    NodoLinkedList* actual;
    NodoLinkedList* aux;

    actual = first;
    aux = nullptr;

    while (actual != nullptr)
    {
        aux = actual;
        actual = actual->siguiente;

        first = actual;

        delete aux;

    }
    last = first;

    if (first == nullptr && last == nullptr)
    {
        cout << "Lista vacia" << endl;
    }
}

void EjecutarProgramaLinkedList() {
    NodoLinkedList* first = nullptr;
    NodoLinkedList* last = nullptr;

    int opcion, dato;
    const int salir = 6;
    do {
        cout << "\t.:MENU:.\n"
            "Escoja una opcion del 1 al 6:\n "
            "\t1. Insertar datos en la lista\n"
            "\t2. Mostrar elementos de la lista\n"
            "\t3. Buscar nodo\n"
            "\t4. Eliminar nodo\n"
            "\t5. Vaciar lista\n"
            "\t6. Salir\n";

        opcion = recieveValidInput(1, salir);
        system("cls");

        switch (opcion) {
        case 1:
            InsertarLista(first, last);
            break;

        case 2:
            MostrarElemento(first);
            break;
        case 3:
            BuscarNodo(first);
            break;
        case 4:
            EliminarNodo(first, last);
            break;
        case 5:
            VaciarLista(first, last);
            break;


        default:
            cout << "Escoja una opcion valida" << endl;
            break;
        }


    } while (opcion != salir);
}