using namespace std;

struct Node {

    int data;
    Node* nodeBelow;

};

Node* top;

void addStack(Node*& top, int n) {

    Node* New_node = new Node();
    New_node->data = n;
    New_node->nodeBelow = top;
    top = New_node;

    cout << "Elemento agregado" << endl;

};

void popStack(Node*& top) {
    Node* aux = top;

    if (aux != NULL) {
        cout << "Numero " << aux->data << " eliminado" << endl;
        top = top->nodeBelow;
        delete aux;
    }
    else {
        cout << "El stack esta vacio, no hay elementos para eliminar" << endl;
    }

}

void emptyStack() {

    if (top == nullptr) {
        cout << "El stack esta vacio, no se puede vaciar el stack" << endl;
        return;
    }
    while (top != nullptr) {
        popStack(top);
    }
    return;

}

void printStack() {
    if (top == nullptr) {
        cout << "El stack se encuentra vacio" << endl;
        return;
    }

    Node* aux = top;
    cout << "Elementos en la pila: \n  TOP | ";
    while (aux->nodeBelow != nullptr) {
        cout << aux->data << "\n      | ";

        aux = aux->nodeBelow;
    }
    cout << aux->data << "\n";
}



void ExecuteStackProgram() {
    const int opcionSalir = 5;

    int answer;
    top = nullptr;

    cout << "Bienvenido al programa demo de Stack\n";

    do {
        cout << "\nSeleccione una de las Siguientes opciones: \n1. Add\n2. Pop\n3. Vaciar Pila\n4. Imprimir stack \n5. Salir" << endl;

        answer = recieveValidInput(1, 5);

        system("cls");

        switch (answer)
        {
        case 1:
            int num;
            cout << "Digite un numero: " << endl;
            num = recieveValidInput(0, INT_MAX);
            addStack(top, num);
            break;
        case 2:
            popStack(top);
            break;
        case 3:
            emptyStack();
            break;
        case 4:
            printStack();
            break;
        case opcionSalir:
            break;
        default:
            cout << "Opcion invalida. Debe ingresar un numero entre 1 y 5" << endl;
            break;
        }
    } while (answer != opcionSalir);
}