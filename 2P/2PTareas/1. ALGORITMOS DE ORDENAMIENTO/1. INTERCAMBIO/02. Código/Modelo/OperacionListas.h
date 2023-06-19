/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Nombres: Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 14/06/23 18:57
 * Fecha de modificacion: 14/06/23 19:12
 * Enunciado:
 * Registro de entrada y salida de personas con listas circulares doblemente
 * enlazadas y algoritmo de búsqueda burbuja mejorado
 *
 *******************************************************************************/ 
#ifndef OPERACIONLISTAS_H
#define OPERACIONLISTAS_H
template <typename T>
class OperacionListas{
	public:
		virtual bool estaVacia()=0;
		virtual void insertar(T)=0;
		virtual void eliminar(T)=0;
		virtual bool buscar(T)=0;
		virtual void mostrar()=0;
};
#endif