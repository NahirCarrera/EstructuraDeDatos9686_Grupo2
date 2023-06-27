/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Nombres: Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 26/06/23 22:21
 * Fecha de modificacion: 26/06/23 22:21
 * Enunciado:
 * Proyecto transformacion de expresion infija a notacion polaca y polaca inversa
 *
 *******************************************************************************/ 
 
#ifndef OPERACIONLISTAS_H
#define OPERACIONLISTAS_H
#include "../Modelo/NodoDoble.h"

template <typename T>
class OperacionListas{
	public:
		virtual bool estaVacia()=0;
		virtual void insertar(T)=0;
		virtual void eliminar(T)=0;
		virtual bool buscar(T)=0;
		virtual void mostrar()=0;
		virtual T extraerDato(T dato)=0;
		virtual NodoDoble<T>* extraerNodo(T)=0;
		virtual void ordenarPorIntercambio(int)=0;
		virtual void mostrarRepetidos(T) = 0;
};
#endif