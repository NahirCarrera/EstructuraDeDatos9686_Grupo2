/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Nombres: Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 26/06/23 22:21
 * Fecha de modificacion: 26/06/23 22:21
 * Enunciado:
 * Proyecto transformacion de expresion infija a notacion polaca y polaca inversa
 *
 *******************************************************************************/ 
#ifndef CONTROLADORMENU_H
#define CONTROLADORMENU_H
#include "../Modelo/ListaCircularDoble.h"
#include "../Modelo/CalculadoraPolaca.h"
#include <string>


class ControladorMenu{
	public:
		ControladorMenu(){};
		void correrMenu();
	private:		
		bool menuEjecutando = false;
		void operarPostfijo(CalculadoraPolaca calculadora);
		void operarPrefijo(CalculadoraPolaca calculadora);
		void ingresarInfijo();
		void subMenuPolaca(std::string infijo);
		void salir();
};

#endif