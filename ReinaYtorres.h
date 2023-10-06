#pragma once
#include <iostream>
#include <vector>
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
void marcarMovimientoReina(int filaReina, int ColumnaReina, int afilaReina, int aColumnaReina, char tablero[8][8]) {

	if (afilaReina > 7 || afilaReina < 0)
	{
		
		return;
	}
	else if (aColumnaReina > 7 || aColumnaReina < 0)
	{
		
		return;

	}
	if (afilaReina == filaReina && aColumnaReina ==ColumnaReina)
	{
		tablero[afilaReina][aColumnaReina] = 'R';
	}
	else
	{
		if (tablero[afilaReina][aColumnaReina] == 'n')
		{
			tablero[afilaReina][aColumnaReina] = 'X';
		}
		else if(tablero[afilaReina][aColumnaReina] ==' ')
			tablero[afilaReina][aColumnaReina] = 'V';
	}
}

void movimientoReina(int filaReina, int columnaReina, char tablero[8][8]) {
	//Filas y columnas
	for (int i = 0; i < 8; i++)
	{
		marcarMovimientoReina(filaReina, columnaReina, filaReina, i, tablero);
		marcarMovimientoReina(filaReina, columnaReina, i,columnaReina  , tablero);
	}

	//diagonales
	for (int i = 1; i < 8; i++)
	{
		marcarMovimientoReina(filaReina, columnaReina, filaReina + i, columnaReina +i , tablero);
		marcarMovimientoReina(filaReina, columnaReina, filaReina + i, columnaReina - i, tablero);
		marcarMovimientoReina(filaReina, columnaReina, filaReina - i, columnaReina + i, tablero);
		marcarMovimientoReina(filaReina, columnaReina, filaReina - i, columnaReina - i, tablero);
	}
}

void marcarZonaTorre(char tablero[8][8], int filaTorre, int columnaTorre) {

	for (int i = 0; i < 8; i++)
	{
		tablero[filaTorre][i] = 'n';
		tablero[i][columnaTorre] = 'n';
	}

	tablero[filaTorre][columnaTorre] = 'T';

}

char tablero[8][8];

void EjecutarReinaYTorres() {
	/* Pedir posicion individualmente

		- hacer que tome numero y letra

	*/
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			tablero[i][j] = ' ';
		}
	}

	int filaTorre1, columnaTorre1, filaTorre2, columnaTorre2, filaReina, columnaReina;
	bool salir = false;
	while (!salir)
	{
		cout << "\nIngrese posicion de la torre 1:\n\tFila: "; filaTorre1 = recieveValidInput(1, 8, 0) - 1;
		cout << "\tcolumna: ";
		columnaTorre1 = recieveValidInput(65, 72, 0)-65;

		cout << "Ingrese posicion de la torre 2:\n\tFila: "; filaTorre2 = recieveValidInput(1, 8, 0) - 1;
		cout << "\tcolumna: ";
		columnaTorre2 = recieveValidInput(1, 8, 0) - 1;

		cout << "Ingrese posicion de la reina:\n\tFila: "; filaReina = recieveValidInput(1, 8, 0) - 1;
		cout << "\tcolumna: ";
		columnaReina = recieveValidInput(1, 8, 0) - 1;

		// Verificar restricciones
		if ((filaTorre1 == filaTorre2 && columnaTorre1 == columnaTorre2) ||
			(filaReina == filaTorre1 && columnaReina == columnaTorre1) ||
			(filaReina == filaTorre2 && columnaReina == columnaTorre2))
		{
			cout << "Posiciones ingresadas inválidas." << endl;

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


