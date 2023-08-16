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
 
#ifndef JUEGO_H
#define JUEGO_H

#include "TetrisGame.h"

class Juego
{
	public:
		Juego();
		void ejecutar(int, int);
		
	private:
		TetrisGame tetris;
		int filas;
		int columnas;
		void ocultarCursor();
		void pantallaInicio();
		void pantallaScore(int, int, Pieza);
		
};

#endif