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

template <typename T>
NodoSimple<T>* ListaSimple<T>::getCabeza(){
	return cabeza;
}
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

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ListaSimple<T>::estaVacia()
// Purpose:    Verifica si la lista está vacía.
// Parameters: Ninguno
// Return:     bool - Verdadero si la lista está vacía, falso en caso contrario.
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
bool ListaSimple<T>::estaVacia() {
    return this->cabeza == nullptr;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ListaSimple<T>::mostrar()
// Purpose:    Muestra en la consola los elementos almacenados en la lista.
// Parameters: Ninguno
// Return:     void
////////////////////////////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ListaSimple<T>::obtenerTamanio() const
// Purpose:    Calcula y devuelve el número de elementos almacenados en la lista.
// Parameters: Ninguno
// Return:     int - Número de elementos en la lista.
////////////////////////////////////////////////////////////////////////////////////////////////////////

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
T& ListaSimple<T>::operator[](int posicion) {
    NodoSimple<T>* nodo = obtenerNodoPorPosicion(posicion);
    if (nodo != nullptr) {
        return nodo->getDato();
    } else {
        throw std::out_of_range("Posicion invalida");
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ListaSimple<T>::vaciar()
// Purpose:    Elimina todos los elementos de la lista y libera la memoria ocupada por ellos.
// Parameters: Ninguno
// Return:     void
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
void ListaSimple<T>::vaciar() {
    while (cabeza != nullptr) {
        NodoSimple<T>* temp = cabeza;
        cabeza = cabeza->getSiguiente();
        delete temp;
    }
}