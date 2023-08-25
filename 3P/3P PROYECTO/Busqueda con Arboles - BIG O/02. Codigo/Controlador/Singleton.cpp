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

////////////////////////////////////////////////////////////////////////
// Name:       Singleton::getNumeroDatos()
// Purpose:    Implementation of Singleton::getNumeroDatos()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Singleton::getNumeroDatos() {
	return numeroDatos;
}

////////////////////////////////////////////////////////////////////////
// Name:       Singleton::setNumeroDatos(int numeroDatos)
// Purpose:    Implementation of Singleton::setNumeroDatos(int numeroDatos)
// Return:     void
////////////////////////////////////////////////////////////////////////

void Singleton::setNumeroDatos(int numeroDatos) {
	this->numeroDatos = numeroDatos;
}

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
}


