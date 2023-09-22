#include <iostream>


using namespace std;

struct Nodo {
    int dato;
    Nodo* derecha;
    Nodo* izquierda;
    Nodo* padre;
};


void InsertarNodo(Nodo*&, int, Nodo*);
void MostrarArbol(Nodo*&, int);
bool BuscarNodoEnArbol(Nodo*, int);
void EncontrarNodoAEliminar(Nodo*&, int, Nodo*);
void ReordenarArbol(Nodo*&);
void ReemplazarNodo(Nodo*, Nodo*);
void EliminarHoja(Nodo*);
void DestruirNodo(Nodo*&, Nodo*);
void RecorridoPreOrden(Nodo*&);
void RecorridoInOrden(Nodo*&);
void RecorridoPostOrden(Nodo*&);
Nodo* EncontrarMinimo(Nodo*);
Nodo* CrearNodo(int, Nodo*);

Nodo* raiz = NULL;

void EjecutarArbolBinario()
{
    bool salir = false, parar;
    int seleccion, ValorNumero;

    cout << "Bienvenido al demo de arboles binarios \n";

    while (!salir) {

        cout <<"   1. Insertar elemento\n"
            << "   2. Eliminar elemento\n"
            << "   3. Buscar elemento\n"
            << "   4. Mostrar arbol\n"
            << "      -> Recorridos\n"
            << "         5. Realizar recorrido InOrden\n"
            << "         6. Realizar recorrido PreOrden\n"
            << "         7. Realizar recorrido PostOrden\n"
            << "   8. Salir \n"
            << "Ingrese el numero que corresponda a una de estas opciones: ";

        seleccion = recieveValidInput(0, 8, true);
        
        switch (seleccion)
        {
        case 1:
            parar = false;
            while (!parar)
            {
                
                cout << "Presione '0' para salir o \n\tIngrese el numero que desea insertar: "; 
                ValorNumero = recieveValidInput(INT_MAX * -1, INT_MAX, true); 
                if (ValorNumero == 0)
                {
                    parar = true;
                }
                else {
                    
                    InsertarNodo(raiz, ValorNumero, NULL);

                }
            }
        
            break;
        case 2:
            if (raiz != NULL) {
                MostrarArbol(raiz, 0);
                cout << "\nIngrese el numero que desea eliminar: ";
                ValorNumero = recieveValidInput(INT_MAX * -1, INT_MAX, false);
                EncontrarNodoAEliminar(raiz, ValorNumero, NULL);
                MostrarArbol(raiz, 0);
                cout << "---------------------------->\n";
            }
            else {
                cout << "El arbol se encuentra vacio. No hay elementos por eliminar\n";
            }
            break;
        case 3:
            if (raiz != NULL) {
                
                cout << "Ingrese el numero que desea buscar: ";
                ValorNumero = recieveValidInput(INT_MAX * -1, INT_MAX, true);

                if (BuscarNodoEnArbol(raiz, ValorNumero)) {
                    MostrarArbol(raiz, 0);
                    cout << "El numero " << ValorNumero << " si se encuentra dentro del arbol.\n";
                }
                else {
                    MostrarArbol(raiz, 0);
                    cout << "El numero " << ValorNumero << " no se encuentra dentro del arbol.\n";
                }
            }
            else {
                cout << "El arbol se encuentra vacio. No hay elementos para buscar\n";
            }
            break;
        case 4:
            if (raiz != NULL) {
                MostrarArbol(raiz, 0);
            }
            else {
                cout << "El arbol se encuentra vacio.\n";
            }
            break;
        
        ///  recorridos
     
        case 5:
            if (raiz != NULL) {
                MostrarArbol(raiz, 0);
                cout << "\n Recorrido InOrden:\n";
                RecorridoInOrden(raiz);
                cout << endl;
            }
            else {
                cout << "El arbol se encuentra vacio. No se puede realizar el recorrido.\n";
            }
            break;
        case 6:
            if (raiz != NULL) {
                MostrarArbol(raiz, 0);
                cout << "\n Recorrido PreOrden:\n";
                RecorridoPreOrden(raiz);
                cout << endl;
            }
            else {
                cout << "El arbol se encuentra vacio. No se puede realizar el recorrido.\n";
            }
            break;
        case 7:
            if (raiz != NULL) {
                MostrarArbol(raiz, 0);
                cout << "\n Recorrido PostOrden:\n";
                RecorridoPostOrden(raiz);
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
    nuevo_nodo->derecha = NULL;
    nuevo_nodo->izquierda = NULL;
    nuevo_nodo->padre = padre;

    return nuevo_nodo;
}

void InsertarNodo(Nodo*& arbol, int valorNuevo, Nodo* padre) {
    if (arbol == NULL) {
        Nodo* nuevo_nodo = CrearNodo(valorNuevo, padre);
        arbol = nuevo_nodo;

        /*if (raiz == NULL) {
            raiz = nuevo_nodo;
        }*/
    }
    else {
        int valorRaiz = arbol->dato;
        if (valorNuevo < valorRaiz) {
            InsertarNodo(arbol->izquierda, valorNuevo, arbol);
        }
        else {
            InsertarNodo(arbol->derecha, valorNuevo, arbol);
        }
    }
}

void MostrarArbol(Nodo*& arbol, int contador) {
    if (arbol == NULL) {
        return;
    }
    else {
        MostrarArbol(arbol->derecha, contador + 1);
        for (int i = 0; i < contador; i++) {
            cout << "    ";
        }
        cout << "[" << arbol->dato << "]" << endl;
        MostrarArbol(arbol->izquierda, contador + 1);
    }
}

bool BuscarNodoEnArbol(Nodo* arbol, int valorBuscando) {  //Encontrar existencia
    if (arbol == NULL) {
        return false;
    }
    else if (arbol->dato == valorBuscando) {
        return true;
    }
    else if (arbol->dato > valorBuscando) {
        return BuscarNodoEnArbol(arbol->izquierda, valorBuscando);
    }
    else if (arbol->dato < valorBuscando);
    {
        return BuscarNodoEnArbol(arbol->derecha, valorBuscando);
    }
}

#pragma region Eliminación de nodos en árbol




//Busca nodo a eliminar
void EncontrarNodoAEliminar(Nodo*& arbol, int n, Nodo* padre) {
    if (arbol == NULL) {
        cout << "El numero " << n << " no existe dentro del arbol.\n";
    }
    else if (n < arbol->dato) {
        EncontrarNodoAEliminar(arbol->izquierda, n, arbol);
    }
    else if (n > arbol->dato) {
        EncontrarNodoAEliminar(arbol->derecha, n, arbol);
    }
    else {
        ReordenarArbol(arbol);
    }
}

//Reorganiza el arbol basado en el nodo que se va a eliminar y en los hijos que tiene dicho nodo
void ReordenarArbol(Nodo*& arbol) {
    if (arbol->derecha != NULL && arbol->izquierda != NULL) { // Tiene 2 hijos
        Nodo* minimo = EncontrarMinimo(arbol->derecha);

        cout << "\t\t ...Reemplazando valor " << arbol->dato  << " a... ";
        arbol->dato = minimo->dato;
        cout << arbol->dato << endl;

        ReordenarArbol(minimo);
    }
    else if (arbol->izquierda != NULL) {
        Nodo* aux = arbol;
        ReemplazarNodo(arbol, arbol->izquierda);
        DestruirNodo(aux, arbol->izquierda);
    }
    else if (arbol->derecha != NULL) {
        Nodo* aux = arbol;
        ReemplazarNodo(arbol, arbol->derecha);
        DestruirNodo(aux, arbol->derecha);
    }
    else {
        Nodo* aux = arbol;
        ReemplazarNodo(arbol, NULL);
        DestruirNodo(aux, NULL);    //Borrar de memoria.
    }
}

//Encuentra el nodo minimo de nodo->der en caso de que el nodo a eliminar aun tenga ambos hijos
Nodo* EncontrarMinimo(Nodo* arbol) {
    if (arbol == NULL) {
        return NULL;
    }
    if (arbol->izquierda != NULL) {
        return EncontrarMinimo(arbol->izquierda);
    }
    else {
        return arbol;
    }
    return arbol;
}

//Determina el nodo que va a reemplazar el nodo a eliminar en caso de que se este eliminando un nodo con 1 o 0 hijos
void ReemplazarNodo(Nodo* arbol, Nodo* reemplazo) {
    if (arbol->padre != NULL) {
        if (arbol->padre->izquierda != NULL && arbol->dato == arbol->padre->izquierda->dato) {
            arbol->padre->izquierda = reemplazo;
        }
        else if (arbol->padre->derecha != NULL && arbol->dato == arbol->padre->derecha->dato) {
            arbol->padre->derecha = reemplazo;
        }
        if (reemplazo != NULL) {
            reemplazo->padre = arbol->padre;
        }
    }
}

//Elimina el nodo y configura un nuevo top en caso de que sea necesario
void DestruirNodo(Nodo*& nodo, Nodo* reemplazo) {
    if (nodo == raiz) {
        if (reemplazo != NULL) {
            raiz = reemplazo;
            reemplazo->padre = NULL;
        }
        else {
            raiz = NULL;
        }
    }
    cout << "\t\t ...Antiguo nodo " << nodo->dato << " eliminado exitosamente\n"; //EDITADO
    delete nodo;
}
#pragma endregion

#pragma region Tipos recorridos



//TIPOS DE RECORRIDOS
void RecorridoPreOrden(Nodo*& arbol) {
    if (arbol == NULL) {
        return;
    }
    else {
        cout << arbol->dato << " -> ";
        RecorridoPreOrden(arbol->izquierda);
        RecorridoPreOrden(arbol->derecha);
    }
}

void RecorridoInOrden(Nodo*& arbol) {
    if (arbol == NULL) {
        return;
    }
    else {
        RecorridoInOrden(arbol->izquierda);
        cout << arbol->dato << " -> ";
        RecorridoInOrden(arbol->derecha);
    }
}

void RecorridoPostOrden(Nodo*& arbol) {
    if (arbol == NULL) {
        return;
    }
    else {
        RecorridoPostOrden(arbol->izquierda);
        RecorridoPostOrden(arbol->derecha);
        cout << arbol->dato << " -> ";

    }
}
#pragma endregion