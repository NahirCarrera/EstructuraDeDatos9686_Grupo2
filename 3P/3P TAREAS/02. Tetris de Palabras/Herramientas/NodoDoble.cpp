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
 
#include "NodoDoble.h"

////////////////////////////////////////////////////////////////////////
// Name:       NodoDoble::NodoDoble(T dato)
// Purpose:    Implementation of NodoDoble::NodoDoble()
// Parameters:
// - dato
// Return:     
////////////////////////////////////////////////////////////////////////

template <typename T>
NodoDoble<T>::NodoDoble(T dato){
	this->dato = dato;
	this->siguiente = nullptr;
	this->anterior = nullptr;
}

////////////////////////////////////////////////////////////////////////
// Name:       NodoDoble<T>::~NodoDoble()
// Purpose:    Implementation of NodoDoble<T>::~NodoDoble()
// Return:     
////////////////////////////////////////////////////////////////////////

template <typename T>
NodoDoble<T>::~NodoDoble(){
}

////////////////////////////////////////////////////////////////////////
// Name:       NodoDoble<T>::setDato(T dato)
// Purpose:    Implementation of NodoDoble<T>::setDato(T dato)
// Parameters:
// - dato
// Return:     void
////////////////////////////////////////////////////////////////////////

template <typename T>
void NodoDoble<T>::setDato(T dato){
	this->dato = dato;
}

////////////////////////////////////////////////////////////////////////
// Name:       NodoDoble<T>::getDato()
// Purpose:    Implementation of NodoDoble<T>::getDato()
// Return:     T
////////////////////////////////////////////////////////////////////////

template <typename T>
T NodoDoble<T>::getDato(){
	return this->dato;
}

////////////////////////////////////////////////////////////////////////////////////
// Name:       NodoDoble<T>::setSiguiente(NodoDoble<T>* siguiente)
// Purpose:    Implementation of NodoDoble<T>::setSiguiente(NodoDoble<T>* siguiente)
// Parameters:
// - siguiente
// Return:     void
///////////////////////////////////////////////////////////////////////////////////

template <typename T>
void NodoDoble<T>::setSiguiente(NodoDoble<T>* siguiente){
	this->siguiente = siguiente;
}

////////////////////////////////////////////////////////////////////////
// Name:       NodoDoble<T>::getSiguiente()
// Purpose:    Implementation of  NodoDoble<T>::getSiguiente()
// Return:     NodoDoble<T>*
////////////////////////////////////////////////////////////////////////

template <typename T>
NodoDoble<T>* NodoDoble<T>::getSiguiente(){
	return this->siguiente;
}

////////////////////////////////////////////////////////////////////////////////////
// Name:       NodoDoble<T>::setAnterior(NodoDoble<T>* anterior)
// Purpose:    Implementation of NodoDoble<T>::setAnterior(NodoDoble<T>* anterior)
// Parameters:
// - anterior
// Return:     void
///////////////////////////////////////////////////////////////////////////////////

template <typename T>
void NodoDoble<T>::setAnterior(NodoDoble<T>* anterior){
	this->anterior = anterior;
}

////////////////////////////////////////////////////////////////////////
// Name:       NodoDoble<T>::getAnterior()
// Purpose:    Implementation of  NodoDoble<T>::getAnterior()
// Return:     NodoDoble<T>*
////////////////////////////////////////////////////////////////////////

template <typename T>
NodoDoble<T>* NodoDoble<T>::getAnterior(){
	return this->anterior;
}


