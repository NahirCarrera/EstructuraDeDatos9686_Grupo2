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

#include "../Modelo/Singleton.h"

Singleton* Singleton::instance = nullptr;

////////////////////////////////////////////////////////////////////////
// Name:       Singleton::Singleton()
// Purpose:    Implementation of Singleton::Singleton()
// Return:     
////////////////////////////////////////////////////////////////////////

Singleton::Singleton() {}

////////////////////////////////////////////////////////////////////////
// Name:       Singleton::getInstance()
// Purpose:    Implementation of Singleton::getInstance()
// Return:     Singleton*
////////////////////////////////////////////////////////////////////////

Singleton* Singleton::getInstance() {
    if (instance == nullptr) {
        instance = new Singleton();
    }
    return instance;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       Singleton::getPiezas()
// Purpose:    Obtener una referencia a la lista de piezas almacenada en el Singleton.
// Parameters: Ninguno
// Return:     ListaSimple<Pieza>& - Referencia a la lista de piezas.
////////////////////////////////////////////////////////////////////////////////////////////////////////

ListaSimple<Pieza>& Singleton::getPiezas() {
    return piezas;
}

