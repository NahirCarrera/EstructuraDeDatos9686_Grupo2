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
		virtual NodoDoble<T>* extraerNodo(T)=0;
		virtual void ordenarPorIntercambio(int)=0;
		virtual void mostrarRepetidos(T) = 0;
};
#endif