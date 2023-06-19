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
#ifndef LISTACIRCULARDOBLE_H
#define LISTACIRCULARDOBLE_H

#pragma once
#include "../Modelo/OperacionListas.h"
#include "../Controlador/NodoDoble.cpp"

template <typename T>
class ListaCircularDoble:public OperacionListas<T>{
private:
	NodoDoble<T>* cabeza;
	NodoDoble<T>* cola;
public:
	ListaCircularDoble();
	~ListaCircularDoble();
	bool estaVacia()override;
	void insertar(T)override ;
	void eliminar(T)override;
	bool buscar(T)override;
	void mostrar()override;
};                        
#endif
	

