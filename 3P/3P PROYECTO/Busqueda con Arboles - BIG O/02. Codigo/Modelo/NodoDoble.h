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


