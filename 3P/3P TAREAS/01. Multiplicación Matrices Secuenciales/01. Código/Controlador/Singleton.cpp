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

/*
////////////////////////////////////////////////////////////////////////
// Name:       Singleton::getRegistros()
// Purpose:    Implementation of Singleton::getRegistros()
// Return:     ListaCircularDoble<RegistroEntradaSalida>&
////////////////////////////////////////////////////////////////////////

ListaCircularDoble<RegistroEntradaSalida>& Singleton::getRegistros() {
    return registros;
}

////////////////////////////////////////////////////////////////////////
// Name:       Singleton::getEmpleados()
// Purpose:    Implementation of Singleton::getEmpleados()
// Return:     ListaCircularDoble&
////////////////////////////////////////////////////////////////////////

ListaCircularDoble<Empleado>& Singleton::getEmpleados() {
    return empleados;
}*/


