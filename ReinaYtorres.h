#pragma once
#include <iostream>
using namespace std;




// Función para mostrar el tablero
void mostrarTablero(char tablero[8][8]) {
	cout << "\n   A B C D E F G H" << endl;
	cout << "  +----------------+" << endl;
	for (int i = 0; i < 8; i++) {
		cout << i + 1 << " |";
		for (int j = 0; j < 8; j++) {
			if (tablero[i][j] == 'n')
				tablero[i][j] = ' ';
			cout << tablero[i][j] << " ";
		}
		cout << "|" << endl;  // Eliminamos el número duplicado aquí	
		if (i < 7) {
			cout << "  |----------------|" << endl;
		}
	}
	cout << "  +----------------+" << endl;
}

// Función para marcar movimientos de la Reina
void marcarMovimientoReina(int filaReina, int ColumnaReina, int movR, int movC, char tablero[8][8]) {

	bool validoMovimiento = true;
	filaReina = filaReina + movR;
	ColumnaReina = ColumnaReina + movC;

	char posicion;

	if (filaReina > 7 || filaReina < 0) {
		validoMovimiento = false;
	}
	else if (ColumnaReina > 7 || ColumnaReina < 0) {
		validoMovimiento = false;
	}
	else {
		posicion = tablero[filaReina][ColumnaReina];
		switch (posicion)
		{
		case 'n':
			tablero[filaReina][ColumnaReina] = 'X';
			break;
		case ' ':
			tablero[filaReina][ColumnaReina] = 'V';
			break;
		case 'T':
			validoMovimiento = false;
			break;
		default:
			break;
		}
	}
	if (validoMovimiento == true)
		marcarMovimientoReina(filaReina, ColumnaReina, movR, movC, tablero);
}

void movimientoReina(int filaReina, int columnaReina, char tablero[8][8]) {
	
	tablero[filaReina][columnaReina] = 'R';
	//Filas y columnas
	marcarMovimientoReina(filaReina, columnaReina, 1, 0, tablero);
	marcarMovimientoReina(filaReina, columnaReina, -1,0, tablero);
	marcarMovimientoReina(filaReina, columnaReina, 0, 1, tablero);
	marcarMovimientoReina(filaReina, columnaReina, 0, -1, tablero);

	//diagonales
	marcarMovimientoReina(filaReina, columnaReina, 1, 1, tablero);
	marcarMovimientoReina(filaReina, columnaReina, 1, -1, tablero);
	marcarMovimientoReina(filaReina, columnaReina, -1, 1, tablero);
	marcarMovimientoReina(filaReina, columnaReina, -1, -1, tablero);


	
}

void marcarZonaTorre(char tablero[8][8], int filaTorre, int columnaTorre) {
	for (int i = 0; i < 8; i++)
	{
		if (tablero[filaTorre][i] == ' ')
			tablero[filaTorre][i] = 'n';
		if (tablero[i][columnaTorre] == ' ')
			tablero[i][columnaTorre] = 'n';
	}
	tablero[filaTorre][columnaTorre] = 'T';

}


void EjecutarReinaYTorres() {
	char tablero[8][8];

	int filaTorre1, columnaTorre1, filaTorre2, columnaTorre2, filaReina, columnaReina;
	bool salir = false;

	for (int i = 0; i < 8; i++)  // Inicializanddo tablero
	{
		for (int j = 0; j < 8; j++)
		{
			tablero[i][j] = ' ';
		}
	}

	while (!salir)
	{
		cout << "\nIngrese posicion de la torre 1:\n\tFila: "; filaTorre1 = recieveValidInput(1, 8, 0) - 1;
		cout << "\tcolumna (A-H como 1-8): ";
		columnaTorre1 = recieveValidInput(1, 8, 0) - 1;

		cout << "Ingrese posicion de la torre 2:\n\tFila: "; filaTorre2 = recieveValidInput(1, 8, 0) - 1;
		cout << "\tcolumna (A-H como 1-8): ";
		columnaTorre2 = recieveValidInput(1, 8, 0) - 1;

		cout << "Ingrese posicion de la reina:\n\tFila: "; filaReina = recieveValidInput(1, 8, 0) - 1;
		cout << "\tcolumna (A-H como 1-8): ";
		columnaReina = recieveValidInput(1, 8, 0) - 1;

		// Verificar restricciones
		if ((filaTorre1 == filaTorre2 && columnaTorre1 == columnaTorre2) ||
			(filaReina == filaTorre1 && columnaReina == columnaTorre1) ||
			(filaReina == filaTorre2 && columnaReina == columnaTorre2))
		{
			cout << "Posiciones ingresadas se superponen. Intente de nuevo..." << endl;
		}
		else
		{
			salir = true;
		}
	}


	marcarZonaTorre(tablero, filaTorre1, columnaTorre1);
	marcarZonaTorre(tablero, filaTorre2, columnaTorre2);
	movimientoReina(filaReina, columnaReina, tablero);
	mostrarTablero(tablero);


}


