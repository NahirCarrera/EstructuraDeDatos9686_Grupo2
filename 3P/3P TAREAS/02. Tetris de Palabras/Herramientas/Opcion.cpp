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

#include "Opcion.h"
#include <iostream>
#include <cstdlib> // para usar system("cls") y system("pause")

////////////////////////////////////////////////////////////////////////////
// Name:       Opcion::Opcion()
// Purpose:    Implementation of Opcion::Opcion()
// Parameters:
// Return:     
////////////////////////////////////////////////////////////////////////////

Opcion::Opcion() {}

////////////////////////////////////////////////////////////////////////////
// Name:       Opcion::Opcion(std::string texto, void (*funcion)())
// Purpose:    Implementation of Opcion::Opcion()
// Parameters:
// - texto
// - funcion
// Return:     
////////////////////////////////////////////////////////////////////////////

Opcion::Opcion(std::string texto, const std::function<void()>& funcion) {
	this->texto = texto;
	this->funcion = funcion;
}

////////////////////////////////////////////////////////////////////////////
// Name:       Opcion::~Opcion()
// Purpose:    Implementation of Opcion::~Opcion()
// Parameters:
// Return:     
////////////////////////////////////////////////////////////////////////////

Opcion::~Opcion() {}

////////////////////////////////////////////////////////////////////////////
// Name:       Opcion::ejecutar()
// Purpose:    Ejecutar la funcion asignada a la opcion
// Return:     void
////////////////////////////////////////////////////////////////////////////

void Opcion::ejecutar() {
    if (funcion) {    		
    	system("cls");
        funcion();
    } else {
    	std::cout << "No se ha asignado ninguna funcion." << std::endl;	
	}        
}

////////////////////////////////////////////////////////////////////////
// Name:       Opcion::setTexto(std::string texto)
// Purpose:    Implementation of Opcion::setTexto()
// Parameters:
// - texto
// Return:     void
////////////////////////////////////////////////////////////////////////

void Opcion::setTexto(std::string texto) {
    this->texto = texto;
}

////////////////////////////////////////////////////////////////////////
// Name:       Opcion::getTexto()
// Purpose:    Implementation of Opcion::getTexto()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

std::string Opcion::getTexto() const {
    return texto;
}

////////////////////////////////////////////////////////////////////////
// Name:       Opcion::setFuncion(void (*funcion)())
// Purpose:    Implementation of Opcion::setFuncion()
// Parameters:
// - funcion
// Return:     void
////////////////////////////////////////////////////////////////////////

void Opcion::setFuncion(const std::function<void()>&) {
    this->funcion = funcion;
}

std::ostream& operator<<(std::ostream& os, const Opcion& op) {
	os << op.texto;
	return os;
}

bool Opcion::operator==(Opcion& op) {
	return texto == op.texto;
}

bool Opcion::operator>(const Opcion& op) {
	return texto > op.texto;
}

bool Opcion::operator<(const Opcion& op) {
	return texto < op.texto;
}

