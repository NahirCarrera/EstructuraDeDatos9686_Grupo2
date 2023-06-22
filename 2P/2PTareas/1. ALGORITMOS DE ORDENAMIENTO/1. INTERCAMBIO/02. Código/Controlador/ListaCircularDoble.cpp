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
void ListaCircularDoble<T>::mostrarRepetidos(T dato) {
	if (!estaVacia()){
		NodoDoble<T>* aux = this->cabeza;
		do{
			if (aux->getDato() == dato) {
				std::cout << aux->getDato() << " ";
			}			
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

template <typename T>
T ListaCircularDoble<T>::extraer(T dato){
	if (!estaVacia()){
		NodoDoble<T>* aux = this->cabeza;
		do{
			if (aux->getDato() == dato){
				return aux->getDato();
			}
			aux = aux->getSiguiente();
		} while (aux != this->cabeza);
	}
	return dato;
}

template <typename T>
NodoDoble<T>* ListaCircularDoble<T>::extraerNodo(T dato){
	if (!estaVacia()){
		NodoDoble<T>* aux = this->cola;
		do{
			if (aux->getDato() == dato){
				return aux;
			}
			aux = aux->getAnterior();
		} while (aux != this->cola);
	}
	
	return nullptr;
}

template <typename T>
void  ListaCircularDoble<T>::ordenarPorIntercambio(int criterio){
	if (!estaVacia()){ //Si la lista no está vacía 
		NodoDoble<T>* nodoActual = this->cabeza->getSiguiente(); // Nodo que va a recorrer la lista
		NodoDoble<T>* nodoComparado; // Nodo para comparar
		T datoTemporal; //Variable para no perder el dato del nodo a comparar en el cambio
		bool condicion; //Variable para definir la operacion a realizar según el criterio por el cual se quiera ordenar
		
		do{
			nodoComparado = this->cabeza; //El nodo a comparar inicia siendo la cabeza
			
			do{
				
				switch(criterio){
				case 1: 
					condicion = (nodoComparado->getDato() > nodoComparado->getSiguiente()->getDato());
					break;
				case 2:
					condicion = (nodoComparado->getDato() < nodoComparado->getSiguiente()->getDato());
					break;
				}
				if(condicion) {
					datoTemporal = nodoComparado->getDato();                          //Guarda el dato del nodo a comparar en el temporal
					nodoComparado->setDato(nodoComparado->getSiguiente()->getDato()); //Cambia el dato del nodo a comparar por el anexo
					nodoComparado->getSiguiente()->setDato(datoTemporal);             //Cambia el dato del anexo por el temporal
				}
				
				nodoComparado = nodoComparado->getSiguiente(); /*Avanza el nodo a comparar, debe comparar hasta el nodo
				                                               n - 1 de la lista por eso el ciclo se repite mientras 
				                                               el nodo a comparar sea diferente de la cola*/
			} while (nodoComparado != this->cola);
			
			nodoActual = nodoActual->getSiguiente(); /*Como es una lista circular entonces en algún
			                                         momento el nodo actual apuntará a la cabeza entonces ahí
			                                         termina el ciclo*/
			} while (nodoActual != this->cabeza);
	}
	
}

template <typename T>
NodoDoble<T>* ListaCircularDoble<T>::getCabeza() {
	return cabeza;
}

template <typename T>
NodoDoble<T>* ListaCircularDoble<T>::getCola() {
	return cola;
}

template <typename T>
void ListaCircularDoble<T>::setCabeza(NodoDoble<T>* newCabeza) {
	this->cabeza = newCabeza;
}

template <typename T>
void ListaCircularDoble<T>::setCola(NodoDoble<T>* newCola) {
	this->cola = newCola;
}