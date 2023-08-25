/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Estructura de Datos 9686
 * Nombres: Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 07/07/23 21:42
 * Fecha de modificacion: 25/08/23 02:04
 * Enunciado:
 * Analisis Big-O del proyecto de Registro de Personas
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