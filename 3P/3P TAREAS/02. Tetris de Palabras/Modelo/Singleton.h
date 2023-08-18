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

#ifndef SINGLETON_H
#define SINGLETON_H

#include "../Controlador/ListaSimple.cpp"
#include "Pieza.h"
class Singleton {

public:
    static Singleton* getInstance();
    ListaSimple<Pieza>& getPiezas();
private:
    static Singleton* instance;
    ListaSimple<Pieza> piezas;
    Singleton();
};

#endif