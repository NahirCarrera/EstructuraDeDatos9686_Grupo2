/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Nombres: Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 27/06/23 17:32
 * Fecha de modificacion: 27/06/23 21:07
 * Enunciado:
 * Proyecto transformacion de expresion infija a notacion polaca y polaca inversa
 *
 *******************************************************************************/
 
#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H
#include "OperacionArboles.h"
#include "../Controlador/NodoArbol.cpp"
#include <string>

template <typename T>
class ArbolBinario: public OperacionArboles<T>{
	public:
		//Constructor
	    ArbolBinario();
	    ~ArbolBinario();
	    
	    //Getter y Setter
	    NodoArbol<T>* getRaiz();
	    void setRaiz(NodoArbol<T>*);
	    
	    //Operaciones
	    void insertarNodo(T)override;
	    bool buscarNodo(T)override;
	    void eliminarNodo(T)override;
	    void mostrarArbol()override;
	    void mostrarRepetidos(T)override;
	private:
	    NodoArbol<T>* raiz;
	    NodoArbol<T>* encontrarNodoMinimo(NodoArbol<T>*);
    
};
#endif