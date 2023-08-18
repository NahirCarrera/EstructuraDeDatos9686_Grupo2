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


