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
 
#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H
template <typename>
class NodoSimple;

template <typename T>
class ListaSimple {
	public:
		//Constructor
	    ListaSimple();
	    //Getters
	    NodoSimple<T>* getCabeza();
		//Funciones
	    void insertarAlFinal(const T& valor);
	    NodoSimple<T>* obtenerNodoPorPosicion(int posicion);
	    void mostrar(); // Declaración del método mostrar
	    bool estaVacia();
	    int obtenerTamanio() const;
	    void vaciar();
	    //Sobrecarca de operadores
	    T& operator[](int posicion);
	
	private:
	    NodoSimple<T>* cabeza;
};
#endif // LISTA_H
