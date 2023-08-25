/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Estructura de Datos 9686
 * Nombres: Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 11/07/23 22:39
 * Fecha de modificacion: 11/07/23 22:39
 * Enunciado:
 * Registro de entrada y salida de personas con listas circulares doblemente
 * enlazadas y búsqueda con árboles binarios + Extras
 *
 *******************************************************************************/ 

#ifndef SINGLETON_H
#define SINGLETON_H

#include "../Controlador/ListaCircularDoble.cpp"
#include "Empleado.h"
#include "RegistroEntradaSalida.h"

class Singleton {

public:
    static Singleton* getInstance();

    ListaCircularDoble<RegistroEntradaSalida>& getRegistros();
    ListaCircularDoble<Empleado>& getEmpleados();
    int getNumeroDatos();
    void setNumeroDatos(int numeroDatos);
private:
    static Singleton* instance;
    ListaCircularDoble<RegistroEntradaSalida> registros;
    ListaCircularDoble<Empleado> empleados;
    int numeroDatos;
    Singleton();
};

#endif