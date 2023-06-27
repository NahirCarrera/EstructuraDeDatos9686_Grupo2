/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Nombres: Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 26/06/23 22:21
 * Fecha de modificacion: 26/06/23 22:21
 * Enunciado:
 * Proyecto transformacion de expresion infija a notacion polaca y polaca inversa
 *
 *******************************************************************************/ 
 
#ifndef MENU_H
#define MENU_H

#include "../Modelo/ListaCircularDoble.h"
#include "../Modelo/NodoDoble.h"
#include "Opcion.h"
#include <string>
#include <functional>

class Menu{
	public:
		//Constructor
		Menu(std::string);
		
		//Operaciones
		void desplegarMenu();
		void moverArriba();
		void moverAbajo();
		Opcion getOpcionSeleccionada(void);
		void correr();
		void insertarOpcion(std::string, const std::function<void()>&);
		
	private:
	    ListaCircularDoble<Opcion> opciones;
	    NodoDoble<Opcion>* opcionSeleccionada;
	    std::string titulo;

};

#endif