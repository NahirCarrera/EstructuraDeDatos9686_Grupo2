/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Estructura de Datos 9686
 * Nombres: Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 12/08/23 19:40
 * Fecha de modificacion: 12/08/23 19:40
 * Enunciado:
 * Realizar el juego del tetris con palabras en consola (Solo caida horizontal)
 * EXTRA: Realizar la rotación de las piezas
 *******************************************************************************/

#ifndef TETRISGAME_H
#define TETRISGAME_H
#include "ListaSimple.h"
#include "Pieza.h"
#include <vector>
#include <string>
#include <iostream>
#include <Windows.h>
#include <string>

class TetrisGame
{
public:
	//Constructor
	TetrisGame();
	TetrisGame(int numRows, int numCols);
	//Getters y Setters
	int getPuntaje();
	Pieza& getPieza();
	ListaSimple<std::string> getPiezas();
	void setPieza(Pieza);
	void setPuntaje(int);
	//Funciones
	void mostrarPiezaSiguiente(Pieza pieza);
	void rotarPalabra(int fila, int columna);
	bool hayEspacioVacio(int fila, int columna, bool &gameOver);
	bool hayEspacioHorizontal(int fila, int columna, bool derecha);
	void coincidenPalabras(int fila, int columna);
	void aumentarPuntaje();
	void colocarPalabra(int fila, int columna);
	void verificarParaRecorrerTablero(int);
	void borrarPalabra(int fila, int columna);
	void imprimirTablero();
	void limpiar(int, int);
	void obtenerPiezas();
private:
    int filas;
    int columnas;
    int puntaje;
    int aumento;
    Pieza pieza;
    std::vector<std::vector<char>> tablero;
};

#endif