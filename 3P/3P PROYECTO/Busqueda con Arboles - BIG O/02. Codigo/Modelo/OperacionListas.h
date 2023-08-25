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
 
#ifndef OPERACIONLISTAS_H
#define OPERACIONLISTAS_H

template <typename T>
class OperacionListas{
	public:
		virtual bool estaVacia()=0;
		virtual void insertar(T)=0;
		virtual bool eliminar(T)=0;
		virtual bool buscar(T)=0;
		virtual void mostrar()=0;
		virtual T extraerDato(T dato)=0;
		virtual T getPos(int)=0;
		virtual NodoDoble<T>* extraerNodo(T)=0;
		virtual void ordenarPorIntercambio(int)=0;
		virtual void mostrarRepetidos(T) = 0;
};
#endif