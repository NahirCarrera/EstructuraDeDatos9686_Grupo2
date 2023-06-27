/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Nombres: Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 26/06/23 22:21
 * Fecha de modificacion: 26/06/23 22:21
 * Enunciado:
 * Proyecto transformacion de expresion infija a notacion polaca y polaca inversa
 *
 *******************************************************************************/ 
 
#ifndef LISTACIRCULARDOBLE_H
#define LISTACIRCULARDOBLE_H

#pragma once
#include "../Modelo/OperacionListas.h"
#include "NodoDoble.h"

template <typename T>
class ListaCircularDoble:public OperacionListas<T>{
	public:
		//Contructor y destructor
		ListaCircularDoble();
		~ListaCircularDoble();
		//Getters y Setters
		NodoDoble<T>* getCabeza();
		NodoDoble<T>* getCola();
		void setCabeza(NodoDoble<T>*);
		void setCola(NodoDoble<T>*);
		//Operaciones
		bool estaVacia()override;
		void insertar(T)override ;
		void eliminar(T)override;
		bool buscar(T)override;
		void mostrar()override;
		void mostrarRepetidos(T) override;
		T extraerDato(T)override;
		NodoDoble<T>* extraerNodo(T)override;
		void ordenarPorIntercambio(int)override;
	private:
		NodoDoble<T>* cabeza;
		NodoDoble<T>* cola;
};                        
#endif
	

