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
 
#ifndef LISTACIRCULARDOBLE_H
#define LISTACIRCULARDOBLE_H
#include "NodoDoble.h"
#include "OperacionListas.h"
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
		bool eliminar(T)override;
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
	

