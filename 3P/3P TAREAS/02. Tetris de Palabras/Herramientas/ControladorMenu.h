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
 
#ifndef CONTROLADORMENU_H
#define CONTROLADORMENU_H
#include "ListaCircularDoble.h"
#include <string>

class ControladorMenu{
	public:
		ControladorMenu(){};
		void correrMenu();
	private:
		//Funciones de control de personal
		void opcion1();
		void opcion2();
		void opcion3();
		
		//Salir
		void salir();
		
		bool menuEjecutando = false;
};

#endif