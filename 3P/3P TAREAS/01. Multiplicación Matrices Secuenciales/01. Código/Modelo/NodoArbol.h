/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Nombres: Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 27/06/23 17:32
 * Fecha de modificacion: 27/06/23 21:07
 * Enunciado:
 * Proyecto transformacion de expresion infija a notacion polaca y polaca inversa
 *
 *******************************************************************************/
 
#ifndef NODOARBOL_H
#define NODOARBOL_H

#include <iostream>
#include <stdio.h>

template <typename T>
class NodoArbol{
	public:
		//Constructor
		NodoArbol(T);
		//Getters
		T getDato();
		NodoArbol<T>*& getDerecho();
		NodoArbol<T>*& getIzquierdo();
		//Setters
		void setDato(T);
		void setDerecho(NodoArbol<T>*);
		void setIzquierdo(NodoArbol<T>*);
	private:
		T dato;
		NodoArbol<T>* derecho;
		NodoArbol<T>* izquierdo;
};
#endif