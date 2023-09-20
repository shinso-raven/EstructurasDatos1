#pragma once
using namespace std;



struct NodoB {
    int dato;
    NodoB* siguiente;
};

void InsertarLista(NodoB*& first, NodoB*& last) {
    int n;
    NodoB* nuevo_nodo = new NodoB();
    NodoB* aux1;
    NodoB* previo_nodo;

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

void MostrarElemento(NodoB*& first) {
    NodoB* actual = first;


    while (actual != nullptr) {
        cout << actual->dato << "->";
        actual = actual->siguiente;
    }
    cout << "vacio" << endl;
}

void BuscarNodo(NodoB*& first) {
    int n;

    bool elementoEncontrado = false;
    NodoB* actual = new NodoB();
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
        cout << "Elemento " << n << " encontrado en la lista";

    }
    else {
        cout << "El elemento " << n << " no existe en la lista";
    }
}

void EliminarNodo(NodoB*& first, NodoB*& last) {
    int n;
    NodoB* actual;
    NodoB* aux;

    bool elementoEncontrado = false;
    bool respuestaEncontrada = false;

    actual = first;
    aux = actual;

    cout << "Inserte el numero que desea eliminar: \n";
    n = recieveValidInput(0, INT_MAX);

    while (!respuestaEncontrada) {
        if (actual == NULL) { // elemento no existe, pero menor a elementos 
            respuestaEncontrada = true;
        }
        else {
            if (actual->dato > n) {// elemento no existe y mayor a todo
                respuestaEncontrada = true;
            }

            if (actual->dato == n) { // elemento encontrado
                elementoEncontrado = true;
                respuestaEncontrada = true;
                aux->siguiente = actual->siguiente;
            }
            else {
                aux = actual;
                actual = actual->siguiente;
            }
        }


    }

    if (elementoEncontrado) {
        cout << "Elemento " << n << " eliminado correctamente";
        delete actual;
    }
    else {
        cout << "Elemento " << n << " no existe en la lista. Por lo tanto, no se puede eliminar.";
    }
}

void VaciarLista(NodoB*& first, NodoB*& last) {
    NodoB* actual;
    NodoB* aux;

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
    NodoB* first = nullptr;
    NodoB* last = nullptr;

    int opcion, dato;
    const int salir = 6;
    do {
        cout << "\n\t.:MENU:.\n"
            "\t1. Insertar datos en la lista\n"
            "\t2. Mostrar elementos de la lista\n"
            "\t3. Buscar nodo\n"
            "\t4. Eliminar nodo\n"
            "\t5. Vaciar lista\n"
            "\t6. Salir\n"
            "Escoja una opcion del 1 al 6: ";

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