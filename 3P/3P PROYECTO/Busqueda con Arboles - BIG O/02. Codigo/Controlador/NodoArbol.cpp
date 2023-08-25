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
  
#include "../Modelo/NodoArbol.h"

//////////////////////////////////////////////////////////////////////
// Name: NodoArbol<T>::NodoArbol
// Purpose: Constructor de la clase NodoArbol
// Parameters:
// - valor: Valor a asignar al nodo
// Return: 
//////////////////////////////////////////////////////////////////////

template<typename T>
NodoArbol<T>::NodoArbol(T valor) : dato(valor), izquierdo(nullptr), derecho(nullptr) {}

//////////////////////////////////////////////////////////////////////
// Name: NodoArbol<T>::setDato
// Purpose: Establece el valor del nodo
// Parameters:
// - _dato: Valor a asignar al nodo
// Return: void
//////////////////////////////////////////////////////////////////////

template<typename T>
void NodoArbol<T>::setDato(T _dato){
    this->dato = _dato;
}
 
//////////////////////////////////////////////////////////////////////
// Name: NodoArbol<T>::setIzquierdo
// Purpose: Establece el nodo izquierdo del nodo actual
// Parameters:
// - _izquierdo: Puntero al nodo izquierdo a asignar
// Return: void
//////////////////////////////////////////////////////////////////////

template<typename T>
void NodoArbol<T>::setIzquierdo(NodoArbol<T>*_izquierdo){
    izquierdo = _izquierdo;
}
 
//////////////////////////////////////////////////////////////////////
// Name: NodoArbol<T>::setDerecho
// Purpose: Establece el nodo derecho del nodo actual
// Parameters:
// - _derecho: Puntero al nodo derecho a asignar
// Return: void
//////////////////////////////////////////////////////////////////////

template<typename T>
void NodoArbol<T>::setDerecho(NodoArbol<T>* _derecho){
    derecho = _derecho;
}

//////////////////////////////////////////////////////////////////////
// Name: NodoArbol<T>::getDato
// Purpose: Obtiene el valor almacenado en el nodo
// Return: Valor del nodo
//////////////////////////////////////////////////////////////////////

template<typename T>
T NodoArbol<T>::getDato(){
    return dato;
}

//////////////////////////////////////////////////////////////////////
// Name: NodoArbol<T>::getIzquierdo
// Purpose: Obtiene el puntero al nodo izquierdo del nodo actual
// Return: Puntero al nodo izquierdo
//////////////////////////////////////////////////////////////////////

template<typename T>
NodoArbol<T>*& NodoArbol<T>::getIzquierdo(){
    return izquierdo;
}

//////////////////////////////////////////////////////////////////////
// Name: NodoArbol<T>::getDerecho
// Purpose: Obtiene el puntero al nodo derecho del nodo actual
// Return: Puntero al nodo derecho
//////////////////////////////////////////////////////////////////////

template<typename T>
NodoArbol<T>*& NodoArbol<T>::getDerecho(){
    return derecho;
}