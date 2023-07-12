/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Nombres: Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 27/06/23 17:32
 * Fecha de modificacion: 11/07/23 22:39
 * Enunciado:
 * Proyecto transformacion de expresion infija a notacion polaca y polaca inversa
 *
 *******************************************************************************/
 
#include "../Modelo/ArbolBinario.h"
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
			} else if (valor == nodo->getDato()) {
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
// Return: retorna el nodo o nullptr si no lo encontro
//////////////////////////////////////////////////////////////////////4

template<typename T>
NodoArbol<T>* ArbolBinario<T>::buscarNodo(T valor) {
	std::function<NodoArbol<T>*(NodoArbol<T>*, T)> buscarNodoRecursivo = [&](NodoArbol<T>* nodo, T valor) {
	    if (nodo == nullptr) {
	        return nodo;
	    } else if (valor == nodo->getDato()) {
	        return nodo;
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
// Name: ArbolBinario<T>::mostrarRepetidos
// Purpose: Muestra todos los datos repetidos en el arbol segun el argumento
// Return: void
//////////////////////////////////////////////////////////////////////

template<typename T>
void ArbolBinario<T>::mostrarRepetidos(T valor) {
	
	std::function<void(NodoArbol<T>*, T)> buscarNodoRecursivo = [&](NodoArbol<T>* nodo, T valor) {
	    if (nodo == nullptr) {
	        return;
	    } else if (valor == nodo->getDato()) {
	    	std::cout << nodo->getDato() << std::endl;
	        buscarNodoRecursivo(nodo->getDerecho(), valor);
	    } else if (valor < nodo->getDato()) {
	        buscarNodoRecursivo(nodo->getIzquierdo(), valor);
	    } else {
	        buscarNodoRecursivo(nodo->getDerecho(), valor);
	    }
	};
    buscarNodoRecursivo(raiz, valor);
	
	/*
	//Funcion lambda para imprimir el árbol recursivamente
	std::function<void(NodoArbol<T>*, int)> mostrarRepetidosRecursivo = [&](NodoArbol<T>* nodo) {
	    if (nodo == nullptr) {
	        return;
	    }
	    
	    mostrarRepetidosRecursivo(nodo->getDerecho(), nivel + 1);
	    
	    if (valor == nodo->getDato()) {
	    	std::cout << nodo->getDato() << std::endl;	
		}	    
	    
	    mostrarRepetidosRecursivo(nodo->getIzquierdo(), nivel + 1);
	};
	
	std::cout<<"------------- Registros ---------------"<<std::endl;
    mostrarRepetidosRecursivo(raiz, 0);
    std::cout<<"---------------------------------------"<<std::endl;*/
}