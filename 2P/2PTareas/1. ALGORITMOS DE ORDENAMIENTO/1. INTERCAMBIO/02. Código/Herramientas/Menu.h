/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Nombres: Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 14/06/23 18:57
 * Fecha de modificacion: 22/06/23 22:15
 * Enunciado:
 * Registro de entrada y salida de personas con listas circulares doblemente
 * enlazadas y algoritmo de búsqueda por intercambio
 *
 *******************************************************************************/ 
 
#ifndef MENU_H
#define MENU_H

#include "../Modelo/ListaCircularDoble.h"
#include "../Modelo/NodoDoble.h"
#include <string>

class Menu{
	public:
		//Constructor
		Menu(ListaCircularDoble<std::string>);
		//Operaciones
		void desplegarMenu();
		void moverArriba();
		void moverAbajo();
		std::string getOpcionSeleccionada(void);
		static std::string crearMenu();
	private:
	    ListaCircularDoble<std::string> opciones;
	    NodoDoble<std::string>* opcionSeleccionada;

};

#endif