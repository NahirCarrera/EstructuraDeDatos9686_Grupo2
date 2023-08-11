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
 
#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H
template <typename>
class NodoSimple;

template <typename T>
class ListaSimple {
	public:
		//Constructor
	    ListaSimple();
		//Funciones
	    void insertarAlFinal(const T& valor);
	    NodoSimple<T>* obtenerNodoPorPosicion(int posicion);
	    void mostrar(); // Declaración del método mostrar
	    bool estaVacia();
	    int obtenerTamanio() const;
	    
	    //Sobrecarca de operadores
	    T& operator[](int posicion);
	
	private:
	    NodoSimple<T>* cabeza;
};
#endif // LISTA_H
