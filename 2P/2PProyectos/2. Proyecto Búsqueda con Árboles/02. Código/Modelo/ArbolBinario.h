/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Nombres: Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 27/06/23 17:32
 * Fecha de modificacion: 11/07/23 22:39
 * Enunciado:
 * Proyecto transformacion de expresion infija a notacion polaca y polaca inversa
 *
 *******************************************************************************/
 
#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H
#include "OperacionArboles.h"
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
	    NodoArbol<T>* buscarNodo(T)override;
	    void eliminarNodo(T)override;
	    void mostrarArbol()override;
	    void mostrarRepetidos(T)override;
	private:
	    NodoArbol<T>* raiz;
	    NodoArbol<T>* encontrarNodoMinimo(NodoArbol<T>*);
    
};
#endif