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
 
#ifndef MENU_H
#define MENU_H

#include "ListaCircularDoble.h"
#include "Opcion.h"
#include <string>
#include <functional>
template <typename T>
class NodoDoble;

class Menu{
	public:
		//Constructor
		Menu(std::string);
		
		//Operaciones
		void setTitulo(std::string newTitulo);
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