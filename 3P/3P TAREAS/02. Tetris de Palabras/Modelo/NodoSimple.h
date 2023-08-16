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
 
#ifndef NODOSIMPLE_H
#define NODOSIMPLE_H

template <typename T>
class NodoSimple {
	public:
	    //Constructor
	    NodoSimple(const T& valor) : dato(valor), siguiente(nullptr) {}
		//Getters y Setters
	    T getDato() const { return dato; }
	    T& getDato() {return dato;}
        //const T& getDato() const {return dato;}
	    NodoSimple* getSiguiente() const { return siguiente; }
	    void setDato(const T& nuevoDato) { dato = nuevoDato; }
	    void setSiguiente(NodoSimple* nuevoSiguiente) { siguiente = nuevoSiguiente; }
	private:
		T dato;
	    NodoSimple* siguiente;
		
};

#endif // NODOSIMPLE_H
