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


