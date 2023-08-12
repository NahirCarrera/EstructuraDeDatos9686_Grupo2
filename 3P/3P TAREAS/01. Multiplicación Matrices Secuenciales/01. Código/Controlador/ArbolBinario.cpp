/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Nombres: Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 27/06/23 17:32
 * Fecha de modificacion: 27/06/23 21:07
 * Enunciado:
 * Proyecto transformacion de expresion infija a notacion polaca y polaca inversa
 *
 *******************************************************************************/
 
#include "../Modelo/ArbolBinario.h"
#include "NodoArbol.cpp"
#include <iostream>
#include <functional>


//////////////////////////////////////////////////////////////////////
// Name: ArbolBinario<T>::~ArbolBinario
// Purpose: Destruye le objeto
// Return: 
//////////////////////////////////////////////////////////////////////
template<typename T>
ArbolBinario<T>::~ArbolBinario() {
	
}

//////////////////////////////////////////////////////////////////////
// Name: ArbolBinario<T>::getRaiz
// Purpose: Obtiene el valor de la raiz
// Return: NodoArbol<T>*
//////////////////////////////////////////////////////////////////////
template<typename T>
NodoArbol<T>* ArbolBinario<T>::getRaiz() {
	return raiz;
}

//////////////////////////////////////////////////////////////////////
// Name: ArbolBinario<T>::setRaiz
// Purpose: Establece el valor de la raiz
// Parameters:
// - raiz: Valor a asignar a la raiz
// Return: void
//////////////////////////////////////////////////////////////////////

template<typename T>
void ArbolBinario<T>::setRaiz(NodoArbol<T>* raiz) {
	this->raiz = raiz;
}

///////////////////////////////////////////////////////////////////////
// Name: ArbolBinario<T>::ArbolBinario
// Purpose: Constructor de la clase ArbolBinario
// Return: 
////////////////////////////////////////////////////////////////////////

template<typename T>
ArbolBinario<T>::ArbolBinario() : raiz(nullptr) {}

//////////////////////////////////////////////////////////////////////
// Name: ArbolBinario<T>::encontrarNodoMinimo
// Purpose: Encuentra el nodo con el valor mínimo en el árbol
// Parameters:
// - nodo: Puntero al nodo desde el cual se inicia la búsqueda
// Return: Puntero al nodo con el valor mínimo encontrado
//////////////////////////////////////////////////////////////////////

template<typename T>
NodoArbol<T>* ArbolBinario<T>::encontrarNodoMinimo(NodoArbol<T>* nodo) {
    while (nodo->getIzquierdo() != nullptr) {
        nodo = nodo->getIzquierdo();
    }
    return nodo;
}

//////////////////////////////////////////////////////////////////////
// Name: ArbolBinario<T>::insertarNodo
// Purpose: Inserta un nuevo nodo con el valor dado en el árbol
// Parameters:
// - valor: Valor a insertar en el nuevo nodo
// Return: void
//////////////////////////////////////////////////////////////////////

template<typename T>
void ArbolBinario<T>::insertarNodo(T valor) {
	// función lambda recursiva para insertar el nodo
	std::function<NodoArbol<T>*(NodoArbol<T>*, T)> insertarNodoRecursivo = [&](NodoArbol<T>* nodo, T valor) -> NodoArbol<T>* {
		if (nodo == nullptr) {
			nodo = new NodoArbol<T>(valor);
		} else {
			if (valor < nodo->getDato()) {
				nodo->setIzquierdo(insertarNodoRecursivo(nodo->getIzquierdo(), valor));
			} else if (valor > nodo->getDato()) {
				nodo->setDerecho(insertarNodoRecursivo(nodo->getDerecho(), valor));
			} else if (valor == nodo->getDato()){
				nodo->setDerecho(insertarNodoRecursivo(nodo->getDerecho(), valor));
			}
		}
		return nodo;
	};

	raiz = insertarNodoRecursivo(raiz, valor);
}

//////////////////////////////////////////////////////////////////////
// Name: ArbolBinario<T>::buscarNodo
// Purpose: Busca un nodo con el valor dado en el árbol
// Parameters:
// - valor: Valor a buscar en el árbol
// Return: bool indicando si se encontró el nodo o no
//////////////////////////////////////////////////////////////////////4

template<typename T>
bool ArbolBinario<T>::buscarNodo(T valor) {
	std::function<bool(NodoArbol<T>*, T)> buscarNodoRecursivo = [&](NodoArbol<T>* nodo, T valor) {
	    if (nodo == nullptr) {
	        return false;
	    } else if (valor == nodo->getDato()) {
	        return true;
	    } else if (valor < nodo->getDato()) {
	        return buscarNodoRecursivo(nodo->getIzquierdo(), valor);
	    } else {
	        return buscarNodoRecursivo(nodo->getDerecho(), valor);
	    }
	};
    return buscarNodoRecursivo(raiz, valor);
}

//////////////////////////////////////////////////////////////////////
// Name: ArbolBinario<T>::eliminarNodo
// Purpose: Elimina un nodo con el valor dado del árbol
// Parameters:
// - valor: Valor del nodo a eliminar
// Return: void
//////////////////////////////////////////////////////////////////////

template<typename T>
void ArbolBinario<T>::eliminarNodo(T valor) {
	//Función lambda para eliminar un nodo recursivamente
	std::function<NodoArbol<T>*(NodoArbol<T>*, T)> eliminarNodoRecursivo = [&](NodoArbol<T>* nodo, T valor) {
	    if (nodo == nullptr) {
	        return nodo;
	    } else if (valor < nodo->getDato()) {
	        nodo->setIzquierdo(eliminarNodoRecursivo(nodo->getIzquierdo(), valor));
	    } else if (valor > nodo->getDato()) {
	        nodo->setDerecho(eliminarNodoRecursivo(nodo->getDerecho(), valor));
	    } else {
	        if (nodo->getIzquierdo() == nullptr && nodo->getDerecho() == nullptr) {
	            delete nodo;
	            nodo = nullptr;
	        } else if (nodo->getIzquierdo() == nullptr) {
	            NodoArbol<T>* temp = nodo;
	            nodo = temp->getDerecho();
	            delete temp;
	        } else if (nodo->getDerecho() == nullptr) {
	            NodoArbol<T>* temp = nodo;
	            nodo = temp->getIzquierdo();
	            delete temp;
	        } else {
	            NodoArbol<T>* temp = encontrarNodoMinimo(nodo->getDerecho());
	            nodo->setDato(temp->getDato());
	            nodo->setDerecho(eliminarNodoRecursivo(nodo->getDerecho(), temp->getDato()));
	        }
	    }
	    return nodo;
	};
    raiz = eliminarNodoRecursivo(raiz, valor);
}

//////////////////////////////////////////////////////////////////////
// Name: ArbolBinario<T>::mostrarArbol
// Purpose: Muestra el árbol en forma horizontal
// Return: void
//////////////////////////////////////////////////////////////////////

template<typename T>
void ArbolBinario<T>::mostrarArbol() {
	//Funcion lambda para imprimir el árbol recursivamente
	std::function<void(NodoArbol<T>*, int)> mostrarArbolRecursivo = [&](NodoArbol<T>* nodo, int nivel) {
	    if (nodo == nullptr) {
	        return;
	    }
	    
	    mostrarArbolRecursivo(nodo->getDerecho(), nivel + 1);
	    
	    for (int i = 0; i < nivel; i++) {
	        std::cout << "    ";
	    }
	    
	    std::cout << "|--" << nodo->getDato() << std::endl;
	    
	    mostrarArbolRecursivo(nodo->getIzquierdo(), nivel + 1);
	};
	std::cout<<"------------ ARBOL BINARIO ------------"<<std::endl;
    mostrarArbolRecursivo(raiz, 0);
    std::cout<<"---------------------------------------"<<std::endl;
}



//////////////////////////////////////////////////////////////////////
// Name: ArbolBinario<T>::obtenerRecorridoPreorden
// Purpose: Obtiene el recorrido del árbol en preorden
// Return: Cadena con el recorrido en preorden
//////////////////////////////////////////////////////////////////////

template<typename T>
std::string ArbolBinario<T>::obtenerRecorridoPreorden() {
    std::string recorrido;
    //función lambda recursiva para realizar el recorrido
    std::function <void(NodoArbol<T>*)> recorridoPreordenRecursivo = [&](NodoArbol<T>* nodo) {
	    if (nodo != nullptr) {
	        recorrido = recorrido + nodo->getDato() + " ";
	        recorridoPreordenRecursivo(nodo->getIzquierdo());
	        recorridoPreordenRecursivo(nodo->getDerecho());
	    }
	};
	
    recorridoPreordenRecursivo(raiz);
    return recorrido;
}

//////////////////////////////////////////////////////////////////////
// Name: ArbolBinario<T>::obtenerRecorridoInorden
// Purpose: Obtiene el recorrido del árbol en inorden
// Return: Cadena con el recorrido en inorden
//////////////////////////////////////////////////////////////////////

template<typename T>
std::string ArbolBinario<T>::obtenerRecorridoInorden() {
    std::string recorrido;
    //función lambda recursiva para realizar el recorrido
    std::function<void(NodoArbol<T>*)> recorridoInordenRecursivo = [&](NodoArbol<T>* nodo) {
	    if (nodo != nullptr) {
	        recorridoInordenRecursivo(nodo->getIzquierdo());
	        recorrido = recorrido + nodo->getDato() + " ";
	        recorridoInordenRecursivo(nodo->getDerecho());
	    }
	};
	recorridoInordenRecursivo(raiz);
    return recorrido;
}

//////////////////////////////////////////////////////////////////////
// Name: ArbolBinario<T>::obtenerRecorridoPostorden
// Purpose: Obtiene el recorrido del árbol en postorden
// Return: Cadena con el recorrido en postorden
//////////////////////////////////////////////////////////////////////

template<typename T>
std::string ArbolBinario<T>::obtenerRecorridoPostorden() {
    std::string recorrido;
    //función lambda recursiva para realizar el recorrido
    std::function <void(NodoArbol<T>*)> recorridoPostordenRecursivo = [&](NodoArbol<T>* nodo) {
	    if (nodo != nullptr) {
	        recorridoPostordenRecursivo(nodo->getIzquierdo());
	        recorridoPostordenRecursivo(nodo->getDerecho());
	        recorrido = recorrido + nodo->getDato() + " ";
	    }
	};
    
    recorridoPostordenRecursivo(raiz);
    return recorrido;
}
