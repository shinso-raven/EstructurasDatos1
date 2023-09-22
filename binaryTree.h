#include <iostream>


using namespace std;

struct Nodo {
    int dato;
    Nodo* der;
    Nodo* izq;
    Nodo* padre;
};


void InsertarNodo(Nodo*&, int, Nodo*);
void MostrarArbol(Nodo*&, int);
bool BuscarNodo(Nodo*, int);
void EncontrarNodoAEliminar(Nodo*&, int, Nodo*);
void ReordenarArbol(Nodo*&);
void ReemplazarNodo(Nodo*, Nodo*);
void EliminarHoja(Nodo*);
void DestruirNodo(Nodo*&, Nodo*);
void PreOrden(Nodo*&);
void InOrden(Nodo*&);
void PostOrden(Nodo*&);
Nodo* EncontrarMinimo(Nodo*);
Nodo* CrearNodo(int, Nodo*);

Nodo* top = NULL;

void EjecutarArbolBinario()
{
    

    bool salir = false;
    int seleccion;

    cout << "Bienvenido al demo de arboles binarios \n";

    while (!salir) {

        cout << "   1. Insertar elemento\n"
            << "   2. Eliminar elemento\n"
            << "   3. Buscar elemento\n"
            << "   4. Mostrar arbol\n"
            << "   5. Realizar recorrido InOrden\n"
            << "   6. Realizar recorrido PreOrden\n"
            << "   7. Realizar recorrido PostOrden\n"
            << "   8. Salir \n"
            << "Ingrese el numero que corresponda a una de estas opciones: ";

        seleccion = recieveValidInput(0, 8);
        int num;

        switch (seleccion)
        {
        case 1:
            cout << "Ingrese el numero que desea insertar: ";
            num = recieveValidInput(INT_MAX * -1, INT_MAX);

            InsertarNodo(top, num, NULL);

            break;
        case 2:
            if (top != NULL) {
                cout << "Ingrese el numero que desea eliminar: ";
                num = recieveValidInput(INT_MAX * -1, INT_MAX);

                EncontrarNodoAEliminar(top, num, NULL);
            }
            else {
                cout << "El arbol se encuentra vacio. No hay elementos por eliminar\n";
            }
            break;
        case 3:
            if (top != NULL) {
                cout << "Ingrese el numero que desea buscar: ";
                num = recieveValidInput(INT_MAX * -1, INT_MAX);

                if (BuscarNodo(top, num)) {
                    cout << "El numero " << num << " si se encuentra dentro del arbol.\n";
                }
                else {
                    cout << "El numero " << num << " no se encuentra dentro del arbol.\n";
                }
            }
            else {
                cout << "El arbol se encuentra vacio. No hay elementos para buscar\n";
            }
            break;
        case 4:
            if (top != NULL) {
                MostrarArbol(top, 0);
            }
            else {
                cout << "El arbol se encuentra vacio.\n";
            }
            break;
        case 5:
            if (top != NULL) {
                MostrarArbol(top, 0);
                InOrden(top);
                cout << endl;
            }
            else {
                cout << "El arbol se encuentra vacio. No se puede realizar el recorrido.\n";
            }
            break;
        case 6:
            if (top != NULL) {
                MostrarArbol(top, 0);
                PreOrden(top);
                cout << endl;
            }
            else {
                cout << "El arbol se encuentra vacio. No se puede realizar el recorrido.\n";
            }
            break;
        case 7:
            if (top != NULL) {
                MostrarArbol(top, 0);
                PostOrden(top);
                cout << endl;
            }
            else {
                cout << "El arbol se encuentra vacio. No se puede realizar el recorrido.\n";
            }
            break;
        case 8:
            salir = true;
            break;
        default:
            break;
        }
    }
}

Nodo* CrearNodo(int n, Nodo* padre) {
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->der = NULL;
    nuevo_nodo->izq = NULL;
    nuevo_nodo->padre = padre;

    return nuevo_nodo;
}

void InsertarNodo(Nodo*& arbol, int n, Nodo* padre) {
    if (arbol == NULL) {
        Nodo* nuevo_nodo = CrearNodo(n, padre);
        arbol = nuevo_nodo;

        if (top == NULL) {
            top = nuevo_nodo;
        }
    }
    else {
        int valorRaiz = arbol->dato;
        if (n < valorRaiz) {
            InsertarNodo(arbol->izq, n, arbol);
        }
        else {
            InsertarNodo(arbol->der, n, arbol);
        }
    }
}

void MostrarArbol(Nodo*& arbol, int contador) {
    if (arbol == NULL) {
        return;
    }
    else {
        MostrarArbol(arbol->der, contador + 1);
        for (int i = 0; i < contador; i++) {
            cout << "    ";
        }
        cout << arbol->dato << endl;
        MostrarArbol(arbol->izq, contador + 1);
    }
}

bool BuscarNodo(Nodo* arbol, int n) {
    if (arbol == NULL) {
        return false;
    }
    else if (arbol->dato == n) {
        return true;
    }
    else if (arbol->dato > n) {
        return BuscarNodo(arbol->izq, n);
    }
    else if (arbol->dato < n);
    {
        return BuscarNodo(arbol->der, n);
    }
}

//Busca nodo a eliminar
void EncontrarNodoAEliminar(Nodo*& arbol, int n, Nodo* padre) {
    if (arbol == NULL) {
        cout << "El numero " << n << " no existe dentro del arbol.\n";
    }
    else if (n < arbol->dato) {
        EncontrarNodoAEliminar(arbol->izq, n, arbol);
    }
    else if (n > arbol->dato) {
        EncontrarNodoAEliminar(arbol->der, n, arbol);
    }
    else {
        ReordenarArbol(arbol);
    }
}

//Reorganiza el arbol basado en el nodo que se va a eliminar y en los hijos que tiene dicho nodo
void ReordenarArbol(Nodo*& arbol) {
    if (arbol->der != NULL && arbol->izq != NULL) {
        Nodo* minimo = EncontrarMinimo(arbol->der);
        arbol->dato = minimo->dato;
        ReordenarArbol(minimo);
    }
    else if (arbol->izq != NULL) {
        Nodo* aux = arbol;
        ReemplazarNodo(arbol, arbol->izq);
        DestruirNodo(aux, arbol->izq);
    }
    else if (arbol->der != NULL) {
        Nodo* aux = arbol;
        ReemplazarNodo(arbol, arbol->der);
        DestruirNodo(aux, arbol->der);
    }
    else {
        Nodo* aux = arbol;
        ReemplazarNodo(arbol, NULL);
        DestruirNodo(aux, NULL);
    }
}

//Encuentra el nodo minimo de nodo->der en caso de que el nodo a eliminar aun tenga ambos hijos
Nodo* EncontrarMinimo(Nodo* arbol) {
    if (arbol == NULL) {
        return NULL;
    }
    if (arbol->izq != NULL) {
        return EncontrarMinimo(arbol->izq);
    }
    else {
        return arbol;
    }
    return arbol;
}

//Determina el nodo que va a reemplazar el nodo a eliminar en caso de que se este eliminando un nodo con 1 o 0 hijos
void ReemplazarNodo(Nodo* arbol, Nodo* reemplazo) {
    if (arbol->padre != NULL) {
        if (arbol->padre->izq != NULL && arbol->dato == arbol->padre->izq->dato) {
            arbol->padre->izq = reemplazo;
        }
        else if (arbol->padre->der != NULL && arbol->dato == arbol->padre->der->dato) {
            arbol->padre->der = reemplazo;
        }
        if (reemplazo != NULL) {
            reemplazo->padre = arbol->padre;
        }
    }
}

//Elimina el nodo y configura un nuevo top en caso de que sea necesario
void DestruirNodo(Nodo*& nodo, Nodo* reemplazo) {
    if (nodo == top) {
        if (reemplazo != NULL) {
            top = reemplazo;
            reemplazo->padre = NULL;
        }
        else {
            top = NULL;
        }
    }

    cout << "Numero " << nodo->dato << " eliminado exitosamente\n";
    delete nodo;
}

void PreOrden(Nodo*& arbol) {
    if (arbol == NULL) {
        return;
    }
    else {
        cout << arbol->dato << " -> ";
        PreOrden(arbol->izq);
        PreOrden(arbol->der);
    }
}

void InOrden(Nodo*& arbol) {
    if (arbol == NULL) {
        return;
    }
    else {
        InOrden(arbol->izq);
        cout << arbol->dato << " -> ";
        InOrden(arbol->der);
    }
}

void PostOrden(Nodo*& arbol) {
    if (arbol == NULL) {
        return;
    }
    else {
        PostOrden(arbol->izq);
        PostOrden(arbol->der);
        cout << arbol->dato << " -> ";

    }
}