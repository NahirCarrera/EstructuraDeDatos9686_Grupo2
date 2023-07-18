/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Estructura de Datos 9686
 * Nombres: Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 07/07/23 21:42
 * Fecha de modificacion: 07/07/23 21:42
 * Enunciado:
 * Registro de entrada y salida de personas con listas circulares doblemente
 * enlazadas y búsqueda con árboles binarios + Extras
 *
 *******************************************************************************/
 
#ifndef MENU_H
#define MENU_H

#include "../Modelo/ListaCircularDoble.h"
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