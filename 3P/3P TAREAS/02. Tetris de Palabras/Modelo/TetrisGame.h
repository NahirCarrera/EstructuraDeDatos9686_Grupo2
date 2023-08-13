/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Estructura de Datos 9686
 * Nombres: Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 12/08/23 19:40
 * Fecha de modificacion: 12/08/23 19:40
 * Enunciado:
 * Realizar el juego del tetris con palabras en consola
 *
 *******************************************************************************/

#ifndef TETRISGAME_H
#define TETRISGAME_H

#include <vector>
#include <string>
#include <iostream>
#include <Windows.h>

class TetrisGame
{
private:
    int filas;
    int columnas;
    int puntaje;
    std::vector<std::vector<char>> tablero;

public:
	TetrisGame();
	TetrisGame(int numRows, int numCols);
	bool hayEspacioVacio(int fila, int columna, int longitud, bool &gameOver);
	bool hayEspacioHorizontal(int fila, int columna, int longitud, bool derecha);
	void coincidenPalabras(int fila, int columna, std::string palabra);
	void aumentarPuntaje(int aumento);
	void colocarPalabra(int fila, int columna, std::string palabra);
	void borrarPalabra(int fila, int columna, std::string palabra);
	void imprimirTablero();
	void limpiar();
};

#endif