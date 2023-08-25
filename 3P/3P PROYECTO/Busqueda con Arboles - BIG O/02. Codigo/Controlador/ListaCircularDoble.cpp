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
 
#include "../Modelo/ListaCircularDoble.h"
#include "../Controlador/NodoDoble.cpp"
#include <iostream>

////////////////////////////////////////////////////////////////////////
// Name:       ListaCircularDoble<T>::ListaCircularDoble()
// Purpose:    Implementation of ListaCircularDoble<T>::ListaCircularDoble()
// Return:     
////////////////////////////////////////////////////////////////////////

template <typename T>
ListaCircularDoble<T>::ListaCircularDoble(){
	this->cabeza = nullptr;
	this->cola = nullptr;
	this->size = 0;
}

////////////////////////////////////////////////////////////////////////
// Name:       ListaCircularDoble<T>::~ListaCircularDoble()
// Purpose:    Implementation of ListaCircularDoble<T>::~ListaCircularDoble()
// Return:     
////////////////////////////////////////////////////////////////////////

template <typename T>
ListaCircularDoble<T>::~ListaCircularDoble(){
}

////////////////////////////////////////////////////////////////////////
// Name:       ListaCircularDoble<T>::getSize()
// Purpose:    Implementation of ListaCircularDoble<T>::getSize()
// Return:     NodoDoble<T>*
////////////////////////////////////////////////////////////////////////

template <typename T>
int ListaCircularDoble<T>::getSize() {
	return size;
}

////////////////////////////////////////////////////////////////////////
// Name:       ListaCircularDoble<T>::getCabeza()
// Purpose:    Implementation of ListaCircularDoble<T>::getCabeza()
// Return:     NodoDoble<T>*
////////////////////////////////////////////////////////////////////////

template <typename T>
NodoDoble<T>* ListaCircularDoble<T>::getCabeza() {
	return cabeza;
}

////////////////////////////////////////////////////////////////////////
// Name:       ListaCircularDoble<T>::getCola()
// Purpose:    Implementation of ListaCircularDoble<T>::getCola()
// Return:     NodoDoble<T>*
////////////////////////////////////////////////////////////////////////

template <typename T>
NodoDoble<T>* ListaCircularDoble<T>::getCola(){
	return cola;
}

////////////////////////////////////////////////////////////////////////
// Name:       ListaCircularDoble<T>::setCabeza(NodoDoble<T>* newCabeza)
// Purpose:    Implementation of ListaCircularDoble<T>::setCabeza(NodoDoble<T>* newCabeza)
// Parameters:
// - newCabeza
// Return:     void
////////////////////////////////////////////////////////////////////////

template <typename T>
void ListaCircularDoble<T>::setCabeza(NodoDoble<T>* newCabeza) {
	this->cabeza = newCabeza;
}

////////////////////////////////////////////////////////////////////////
// Name:       ListaCircularDoble<T>::setCola(NodoDoble<T>* newCola)
// Purpose:    Implementation of ListaCircularDoble<T>::setCola(NodoDoble<T>* newCola)
// Parameters:
// - newCola
// Return:     void
////////////////////////////////////////////////////////////////////////

template <typename T>
void ListaCircularDoble<T>::setCola(NodoDoble<T>* newCola) {
	this->cola = newCola;
}

////////////////////////////////////////////////////////////////////////
// Name:       ListaCircularDoble<T>::estaVacia()
// Purpose:    Verificar si la cabeza de la lista es nula
// Return:     bool
////////////////////////////////////////////////////////////////////////

template <typename T>
bool ListaCircularDoble<T>::estaVacia() {
    return this->cabeza == nullptr;
}

////////////////////////////////////////////////////////////////////////
// Name:       ListaCircularDoble<T>::insertar(T dato)
// Purpose:    Inserta un dato a final de la lista
// Parameters:
// - dato
// Return:     void
////////////////////////////////////////////////////////////////////////

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
	size++;
}

////////////////////////////////////////////////////////////////////////
// Name:       ListaCircularDoble<T>::eliminar(T dato)
// Purpose:    Elimina la primera coincidencia del dato
// Parameters:
// - dato
// Return:     void
////////////////////////////////////////////////////////////////////////

template <typename T>
bool ListaCircularDoble<T>::eliminar(T dato){
	if (!estaVacia()) {
	    if (this->cabeza->getDato() == dato) {
	        NodoDoble<T>* aux = this->cabeza;
	        if (this->cabeza == this->cola) {
	            // Caso especial: solo hay un elemento en la lista
	            this->cabeza = this->cola = nullptr;
	        } else {
	            this->cabeza = this->cabeza->getSiguiente();
	            this->cabeza->setAnterior(this->cola);
	            this->cola->setSiguiente(this->cabeza);
	        }
	        delete aux;
	        size--;
	        return true;
	    } else {
	        NodoDoble<T>* aux = this->cabeza;
	        while (aux->getSiguiente() != this->cabeza) {
	            if (aux->getSiguiente()->getDato() == dato) {
	                NodoDoble<T>* aux2 = aux->getSiguiente();
	                aux->setSiguiente(aux2->getSiguiente());
	                aux2->getSiguiente()->setAnterior(aux);
	                if (aux2 == this->cola) {
	                    this->cola = aux;
	                }
	                delete aux2;
	                size--;
	                return true;
	            }
	            aux = aux->getSiguiente();
	        }
	    }
	}
	return false;	
}

////////////////////////////////////////////////////////////////////////
// Name:       ListaCircularDoble<T>::mostrar()
// Return:     void
////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////
// Name:       ListaCircularDoble<T>::getPos(int pos)
// Return:     void
////////////////////////////////////////////////////////////////////////
template <typename T>
T ListaCircularDoble<T>::getPos(int pos) {
	int cont = 0;
	if (!estaVacia()){
		NodoDoble<T>* aux = this->cabeza;
		do{
			if (pos == cont) {
				return aux->getDato();
			}
			aux = aux->getSiguiente();
			cont++;
		} while (aux != this->cabeza);
	}
	
	return this->cabeza->getDato();
}

////////////////////////////////////////////////////////////////////////
// Name:       ListaCircularDoble<T>::mostrarRepetidos(T dato)
// Purpose:    Imprime todos los datos de una lista que tienen un dato especfífico en común
// Parameters:
// - dato
// Return:     void
////////////////////////////////////////////////////////////////////////

template <typename T>
void ListaCircularDoble<T>::mostrarRepetidos(T dato){
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

////////////////////////////////////////////////////////////////////////
// Name:       ListaCircularDoble<T>::buscar(T dato)
// Purpose:    Busca un dato específico dentro de la lista, devuelve la primera coincidecia
// Parameters:
// - dato
// Return:     
////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////
// Name:       ListaCircularDoble<T>::extraerDato(T dato)
// Purpose:    busca un dato específico en la lista y devuelve el dato}
// Parameters:
// - dato
// Return:     
////////////////////////////////////////////////////////////////////////

template <typename T>
T ListaCircularDoble<T>::extraerDato(T dato){
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

////////////////////////////////////////////////////////////////////////
// Name:       ListaCircularDoble<T>::extraerNodo(T dato)
// Purpose:    Busca un dato específico en la lista y devuelve el nodo
// Parameters:
// - dato
// Return:     NodoDoble<T>*
////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////
// Name:       ListaCircularDoble<T>::ordenarPorIntercambio(int criterio)
// Purpose:    Ordena una lista por intercambio según un criterio específico
// Parameters:
// - criterio
// Return:     void
////////////////////////////////////////////////////////////////////////

template <typename T>
void  ListaCircularDoble<T>::ordenarPorIntercambio(int criterio){
	if (!estaVacia()){ //Si la lista no está vacía 
		NodoDoble<T>* nodoActual = this->cabeza; // Nodo que va a recorrer la lista
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

