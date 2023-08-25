/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Estructura de Datos 9686
 * Nombres: Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 07/07/23 21:42
 * Fecha de modificacion: 25/08/23 02:04
 * Enunciado:
 * Analisis Big-O del proyecto de Registro de Personas
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