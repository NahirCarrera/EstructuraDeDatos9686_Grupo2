/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Nombres: Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 26/06/23 22:21
 * Fecha de modificacion: 26/06/23 22:21
 * Enunciado:
 * Proyecto transformacion de expresion infija a notacion polaca y polaca inversa
 *
 *******************************************************************************/ 
 
#ifndef NODODOBLE_H
#define NODODOBLE_H

#pragma once
template <typename T>
class NodoDoble{
	public:
		//Contructor y destructor
		NodoDoble(T);
		~NodoDoble();
		//Getters y Setters
		void setDato(T);
		T getDato();
		void setSiguiente(NodoDoble*);
		NodoDoble* getSiguiente();
		void setAnterior(NodoDoble*);
		NodoDoble* getAnterior();
	private:
		T dato;
		NodoDoble<T>* siguiente;
		NodoDoble<T>* anterior;
};
#endif


