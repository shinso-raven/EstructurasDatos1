using namespace std;

#pragma region Queue
struct Nodo
{
	int dato;
	int prioridad;
	Nodo* siguiente;
};

void Enqueue(Nodo*& frente, Nodo*& final, int numero, int prioridad) {
	// Agregar un elemento al final de la cola o queue
		//Nuevo nodo que recibe los datos
	Nodo* nuevoNodo = new Nodo();
	nuevoNodo->dato = numero;
	nuevoNodo->prioridad = prioridad;
	nuevoNodo->siguiente = NULL;

	if (frente == NULL) //si la cola esta vac�a
	{
		frente = nuevoNodo;
		//Mover a ultima posicion
		final = nuevoNodo;

	}
	else
	{
		/// DEBE COLOCARSE SEGUN PRIORIDAD. Del 0 al 16, prioridad > 16 se considera default y va al final de la cola
		///!!!!!!!!
		// head y auxiliar
		Nodo* nodoDelante;

		nodoDelante = frente;

		bool terminarCiclo = false;
		int counterPrioridad = 1;

		if (prioridad == 0) {
			nuevoNodo->siguiente = frente;
			frente = nuevoNodo;
			return;
		}

		if (prioridad <= 16) {
			while (!terminarCiclo)
			{
				if (counterPrioridad < prioridad && nodoDelante->siguiente != NULL) //Para ese caso
				{
					nodoDelante = nodoDelante->siguiente;
					counterPrioridad++;
				}
				else
				{
					nuevoNodo->siguiente = nodoDelante->siguiente;
					nodoDelante->siguiente = nuevoNodo;
					terminarCiclo = true;

					if (nuevoNodo->siguiente == NULL) {
						final = nuevoNodo;
					}
				}
			}
		}
		else {
			final->siguiente = nuevoNodo;
			final = nuevoNodo;
			return;
		}
	}
}

void Dequeue(Nodo*& frente, Nodo*& final, int& numero) {

	if (frente == nullptr) {
		cout << "El queue se encuentra vacio, no hay elementos para eliminar" << endl;
		return;
	}

	// Sale el nodo que est� en frente

	numero = frente->dato; // se actualiza el dato dentro de la posicion de memoria
	Nodo* auxiliar = frente;

	if (frente == final) // Caso que hay un nodo o ninguno
	{
		frente = NULL;
		final = NULL;
	}
	else // Caso halla mas de un nodo
	{
		frente = frente->siguiente;
	}
	cout << "\nDato eliminado de cola\n" << auxiliar->dato;

	delete auxiliar;

}

void Desplegar(Nodo*& frente) {
	if (frente == nullptr) {
		cout << "El queue se encuentra vacio" << endl;
		return;
	}

	Nodo* aux = frente;
	cout << "Elementos en la cola: \n  FIRST | ";

	while (aux->siguiente != nullptr) {
		cout << aux->dato << " (Prioridad " << aux->prioridad << ")\n        | ";
		aux = aux->siguiente;
	}
	cout << aux->dato << " (Prioridad " << aux->prioridad << ") | LAST\n";



};


void ExecuteQueueProgram() {
	//Control general

	Nodo* frente = NULL;
	Nodo* final = NULL;
	int dato, prioridad, seleccion;
	bool salir = false;

	cout << "Bienvenido al programa de demostracion del Queue \n";

	// Mostrar menu
	while (!salir)
	{

		cout << "\nElija una de las siguientes opciones ingresando un numero entre 1 y 4:"
			"\n	1. Enqueue\n	2. Dequeue\n	3. Desplegar Queue\n	4. Salir del programa\n	";

		seleccion = recieveValidInput(1, 4);

		system("cls"); // Limpiar consola

		switch (seleccion)
		{
		case 1: //Enqueue
			//Recibir dato de entrada y numero de prioridad
			cout << "Ingrese un numero entero para agregarlo al nodo:\n";
			dato = recieveValidInput(0, INT_MAX);

			cout << "Ingrese el numero de prioridad entre 0 al 16. Cualquier numero mayor a 16 ser� tratado como un elemento sin prioridad\n";

			prioridad = recieveValidInput(0, INT_MAX);

			Enqueue(frente, final, dato, prioridad);

			break;
		case 2: //Dequeue
			// Realizar Dequeue y presentar dato
			Dequeue(frente, final, dato);

			break;
		case 3: //Desplegar
			// Desplegar toda la cola
			Desplegar(frente);

			break;
		case 4: // salir del programa
			salir = true;

			break;
		default:
			cout << "\nSolamente puede ingresar uno los numeros del 1 al 4 correspondientes a la selecci�n del men�.\n";
			break;
		}

	}
}
#pragma endregion

