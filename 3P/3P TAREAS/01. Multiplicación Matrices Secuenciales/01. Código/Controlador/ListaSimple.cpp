/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * ESTRUCTURA DE DATOS 9686
 * Nombre: Carrera Nahir
 * Fecha de creacion: 03/08/23 17:33
 * Fecha de modificacion: 04/08/23 02:26
 * Enunciado:
 * Creación del tablero de ajedrez de tamaño n generado desde archivo txt y 
 * ubicación de una reina aleatoriamente en una casilla
 *******************************************************************************/
#include "../Modelo/ListaSimple.h"
#include "../Modelo/NodoSimple.h"
#include <iostream>

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       Lista<T>::Lista()
// Purpose:    Constructor de la clase Lista
// Return:     
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
ListaSimple<T>::ListaSimple() : cabeza(nullptr) {}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ListaSimple<T>::insertarAlFinal(const T& valor)
// Purpose:    Agregar un nodo al final de la ListaSimple
// Parameters
// - valor
// Return:     void
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
void ListaSimple<T>::insertarAlFinal(const T& valor) {
    NodoSimple<T>* nuevoNodo = new NodoSimple<T>(valor);

    if (cabeza == nullptr) {
        cabeza = nuevoNodo;
    } else {
        NodoSimple<T>* temp = cabeza;
        while (temp->getSiguiente() != nullptr) {
            temp = temp->getSiguiente();
        }
        temp->setSiguiente(nuevoNodo);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ListaSimple<T>::obtenerNodoPorPosicion(int posicion)
// Purpose:    Obtener un nodo que se encuentre en una posición específica de la ListaSimple
// Parameters
// - posicion
// Return:     NodoSimple<T>*
////////////////////////////////////////////////////////////////////////////////////////////////////////


template <typename T>
bool ListaSimple<T>::estaVacia() {
    return this->cabeza == nullptr;
}

template <typename T>
void ListaSimple<T>::mostrar(){
	if (!estaVacia()){
		NodoSimple<T>* aux = this->cabeza;
		do{
			std::cout << aux->getDato() << std::endl;
			aux = aux->getSiguiente();
		} while (aux != nullptr);
		std::cout << std::endl;
	}
}

template <typename T>
int ListaSimple<T>::obtenerTamanio() const {
    int tamanio = 0;
    NodoSimple<T>* temp = cabeza;
    while (temp != nullptr) {
        tamanio++;
        temp = temp->getSiguiente();
    }
    return tamanio;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ListaSimple<T>::operator[](int posicion)
// Purpose:    Sobrecarga del operador [] para obener una dato de un nodo en una posición específica de la ListaSimple
// Parameters
// - posicion
// Return:     T&
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
int ListaSimple<T>::obtenerElementoEnPosicion(int posicion) {
    NodoSimple<T>* nodo = obtenerNodoPorPosicion(posicion);
    if (nodo != nullptr) {
        return nodo->getDato();
    } else {
        throw std::out_of_range("Posicion invalida");
    }
}

template <typename T>
T& ListaSimple<T>::operator[](int posicion) {
    NodoSimple<T>* nodo = obtenerNodoPorPosicion(posicion);
    if (nodo != nullptr) {
        return nodo->getDato();
    } else {
        throw std::out_of_range("Posicion invalida");
    }
}

template <typename T>
NodoSimple<T>* ListaSimple<T>::obtenerNodoPorPosicion(int posicion) {
    if (posicion < 0)
        return nullptr;

    NodoSimple<T>* temp = cabeza;
    int contador = 0;

    while (temp != nullptr && contador < posicion) {
        temp = temp->getSiguiente();
        contador++;
    }

    return temp;
}

template <typename T>
void ListaSimple<T>::vaciar() {
    while (cabeza != nullptr) {
        NodoSimple<T>* temp = cabeza;
        cabeza = cabeza->getSiguiente();
        delete temp;
    }
}