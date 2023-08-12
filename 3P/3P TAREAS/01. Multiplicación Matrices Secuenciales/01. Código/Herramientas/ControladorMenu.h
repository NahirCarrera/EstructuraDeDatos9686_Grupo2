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
#ifndef CONTROLADORMENU_H
#define CONTROLADORMENU_H
#include "../Modelo/CalculadoraPolaca.h"
#include "../Modelo/Matriz.h"
#include <string>

class ControladorMenu{
	public:
		ControladorMenu(){};
		void correrMenu();
	private:
		int cantidadMatrices;
		ListaSimple<Matriz> matrices;
		//Funciones de control de personal
		void ingresarMatrices();
		void multiplicarMatrices();
		void limpiarMatrices();
		void generarMatricesAleatorias();
		
		//Salir
		void salir();
		
		bool menuEjecutando = false;
};

#endif