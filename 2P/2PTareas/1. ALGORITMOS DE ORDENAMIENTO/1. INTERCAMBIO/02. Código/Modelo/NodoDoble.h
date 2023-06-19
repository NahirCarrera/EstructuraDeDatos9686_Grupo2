/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Nombres: Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 14/06/23 18:57
 * Fecha de modificacion: 14/06/23 19:12
 * Enunciado:
 * Registro de entrada y salida de personas con listas circulares doblemente
* enlazadas y algoritmo de búsqueda por intercambio
 *
 *******************************************************************************/ 
#ifndef NODODOBLE_H
#define NODODOBLE_H

#pragma once
template <typename T>
class NodoDoble{
private:
	T dato;
	NodoDoble<T>* siguiente;
	NodoDoble<T>* anterior;
public:
	NodoDoble(T);
	~NodoDoble();
	void setDato(T);
	T getDato();
	void setSiguiente(NodoDoble*);
	NodoDoble* getSiguiente();
	void setAnterior(NodoDoble*);
	NodoDoble* getAnterior();
};
#endif


