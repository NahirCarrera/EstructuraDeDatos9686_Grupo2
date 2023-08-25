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
 
#ifndef OPERACIONARBOLES_H
#define OPERACIONARBOLES_H
#include <string>

#include "../Controlador/NodoArbol.cpp"

template <typename T>
class OperacionArboles{
	public:
		virtual void insertarNodo(T)=0;
	    virtual NodoArbol<T>* buscarNodo(T)=0;
	    virtual void eliminarNodo(T)=0;
	    virtual void mostrarArbol()=0;
	    virtual void mostrarRepetidos(T)=0;
};
#endif
