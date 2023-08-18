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
	    NodoSimple* getSiguiente() const { return siguiente; }
	    void setDato(const T& nuevoDato) { dato = nuevoDato; }
	    void setSiguiente(NodoSimple* nuevoSiguiente) { siguiente = nuevoSiguiente; }
	private:
		T dato;
	    NodoSimple* siguiente;
		
};

#endif // NODOSIMPLE_H
