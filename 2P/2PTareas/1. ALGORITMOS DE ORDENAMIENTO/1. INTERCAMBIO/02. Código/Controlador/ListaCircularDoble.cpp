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
#include "../Modelo/ListaCircularDoble.h"
#include <iostream>

template <typename T>
ListaCircularDoble<T>::ListaCircularDoble(){
	this->cabeza = nullptr;
	this->cola = nullptr;
}

template <typename T>
ListaCircularDoble<T>::~ListaCircularDoble(){
}

template <typename T>
bool ListaCircularDoble<T>::estaVacia() {
    return this->cabeza == nullptr;
}

template <typename T>
void ListaCircularDoble<T>::insertar(T dato){
	NodoDoble<T>* nuevo = new NodoDoble<T>(dato);
	if (estaVacia()){
		this->cabeza = nuevo;
		this->cola = nuevo;
		this->cabeza->setSiguiente(this->cola);
		this->cabeza->setAnterior(this->cola);
		this->cola->setSiguiente(this->cabeza);
		this->cola->setAnterior(this->cabeza);
	}else{
		this->cola->setSiguiente(nuevo);
		nuevo->setAnterior(this->cola);
		nuevo->setSiguiente(this->cabeza);
		this->cabeza->setAnterior(nuevo);
		this->cola = nuevo;
	}
}

template <typename T>
void ListaCircularDoble<T>::eliminar(T dato){
	if (!estaVacia()){
		if (this->cabeza->getDato() == dato){
			NodoDoble<T>* aux = this->cabeza;
			this->cabeza = this->cabeza->getSiguiente();
			this->cabeza->setAnterior(this->cola);
			this->cola->setSiguiente(this->cabeza);
			delete aux;
		}else{
			NodoDoble<T>* aux = this->cabeza;
			while (aux->getSiguiente() != this->cabeza){
				if (aux->getSiguiente()->getDato() == dato){
					NodoDoble<T>* aux2 = aux->getSiguiente();
					aux->setSiguiente(aux2->getSiguiente());
					aux2->getSiguiente()->setAnterior(aux);
					delete aux2;
					break;
				}
				aux = aux->getSiguiente();
			}
		}
	}
}

template <typename T>
void ListaCircularDoble<T>::mostrar(){
	if (!estaVacia()){
		NodoDoble<T>* aux = this->cabeza;
		do{
			std::cout << aux->getDato() << " ";
			aux = aux->getSiguiente();
		} while (aux != this->cabeza);
		std::cout << std::endl;
	}
}

template <typename T>
bool ListaCircularDoble<T>::buscar(T dato){
	if (!estaVacia()){
		NodoDoble<T>* aux = this->cabeza;
		do{
			if (aux->getDato() == dato){
				return true;
			}
			aux = aux->getSiguiente();
		} while (aux != this->cabeza);
	}
	return false;
}




