#pragma once
#include <iostream>
#include <vector>
using namespace std;




// Función para mostrar el tablero
void mostrarTablero(char tablero[8][8]) {
    cout << "   A B C D E F G H" << endl;
    cout << "  +----------------+" << endl;
    for (int i = 0; i < 8; i++) {
        cout << i + 1 << " |";
        for (int j = 0; j < 8; j++) {
            cout << tablero[7 - i][j] << "|";
        }
        cout << "|";  // Eliminamos el número duplicado aquí
        cout << endl;
        if (i < 7) {
            cout << "  |----------------|" << endl;
        }
    }
    cout << "  +----------------+" << endl;
}

// Función para marcar movimientos de la Reina
void marcarMovimientosReina(char tablero[8][8], int filaReina, int columnaReina) {
    

    for (int i = 0; i < 8; i++) {
        // Marcar filas y columnas
        tablero[filaReina][i] = 'X';
        tablero[i][columnaReina] = 'X';
    }

    // Marcar diagonales
    for (int i = 1; i < 8; i++) {
        if (filaReina + i < 8 && columnaReina + i < 8) 
            tablero[filaReina + i][columnaReina + i] = 'X';
        if (filaReina + i < 8 && columnaReina - i >= 0) 
            tablero[filaReina + i][columnaReina - i] = 'X';
        if (filaReina - i >= 0 && columnaReina + i < 8) 
            tablero[filaReina - i][columnaReina + i] = 'X';
        if (filaReina - i >= 0 && columnaReina - i >= 0) 
            tablero[filaReina - i][columnaReina - i] = 'X';
    }

    // Marcar posición de la Reina
    tablero[filaReina][columnaReina] = 'R';
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

    */
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            tablero[i][j] = ' ';
        }
    }


    int filaTorre1, columnaTorre1, filaTorre2, columnaTorre2, filaReina, columnaReina;

    cout << "Ingrese la posición de la Torre 1 (fila columna): ";
    cin >> filaTorre1 >> columnaTorre1;
    cout << "Ingrese la posición de la Torre 2 (fila columna): ";
    cin >> filaTorre2 >> columnaTorre2;
    cout << "Ingrese la posición de la Reina (fila columna): ";
    cin >> filaReina >> columnaReina;

    // Verificar restricciones
    if (filaTorre1 < 0 || filaTorre1 >= 8 || columnaTorre1 < 0 || columnaTorre1 >= 8 ||
        filaTorre2 < 0 || filaTorre2 >= 8 || columnaTorre2 < 0 || columnaTorre2 >= 8 ||
        filaReina < 0 || filaReina >= 8 || columnaReina < 0 || columnaReina >= 8 ||
        (filaTorre1 == filaTorre2 && columnaTorre1 == columnaTorre2) ||
        (filaReina == filaTorre1 && columnaReina == columnaTorre1) ||
        (filaReina == filaTorre2 && columnaReina == columnaTorre2))
    {
        cout << "Posiciones ingresadas inválidas." << endl;

    }

    marcarZonaTorre(tablero, filaTorre1, columnaTorre1);
    marcarZonaTorre(tablero, filaTorre2, columnaTorre2);
    marcarMovimientosReina(tablero, filaReina, columnaReina);



    mostrarTablero(tablero);


}


