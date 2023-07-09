/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Nombres: Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 26/06/23 22:21
 * Fecha de modificacion: 26/06/23 22:21
 * Enunciado:
 * Proyecto transformacion de expresion infija a notacion polaca y polaca inversa
 *
 *******************************************************************************/ 
 
#ifndef OPERACIONARBOLES_H
#define OPERACIONARBOLES_H
#include <string>

template <typename T>
class OperacionArboles{
	public:
		virtual void insertarNodo(T)=0;
	    virtual bool buscarNodo(T)=0;
	    virtual void eliminarNodo(T)=0;
	    virtual void mostrarArbol()=0;
	    virtual void mostrarRepetidos(T)=0;
};
#endif
