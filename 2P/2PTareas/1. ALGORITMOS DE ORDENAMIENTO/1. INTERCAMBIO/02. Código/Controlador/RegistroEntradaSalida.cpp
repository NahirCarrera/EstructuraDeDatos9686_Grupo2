/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Nombres: Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 14/06/23 18:57
 * Fecha de modificacion: 14/06/23 22:40
 * Enunciado:
 * Registro de entrada y salida de personas con listas circulares doblemente
 * enlazadas y algoritmo de búsqueda por intercambio
 *
 *******************************************************************************/ 

#include "../Modelo/RegistroEntradaSalida.h"

////////////////////////////////////////////////////////////////////////
// Name:       RegistroEntradaSalida::getPersona()
// Purpose:    Implementation of RegistroEntradaSalida::getPersona()
// Return:     Persona
////////////////////////////////////////////////////////////////////////

Persona RegistroEntradaSalida::getPersona(void)
{
   return persona;
}

////////////////////////////////////////////////////////////////////////
// Name:       RegistroEntradaSalida::setPersona(Persona newPersona)
// Purpose:    Implementation of RegistroEntradaSalida::setPersona()
// Parameters:
// - newPersona
// Return:     void
////////////////////////////////////////////////////////////////////////

void RegistroEntradaSalida::setPersona(Persona newPersona)
{
   persona = newPersona;
}

////////////////////////////////////////////////////////////////////////
// Name:       RegistroEntradaSalida::getFechaEntrada()
// Purpose:    Implementation of RegistroEntradaSalida::getFechaEntrada()
// Return:     Fecha
////////////////////////////////////////////////////////////////////////

Fecha RegistroEntradaSalida::getFechaEntrada(void)
{
   return fechaEntrada;
}

////////////////////////////////////////////////////////////////////////
// Name:       RegistroEntradaSalida::setFechaEntrada(Fecha newFechaEntrada)
// Purpose:    Implementation of RegistroEntradaSalida::setFechaEntrada()
// Parameters:
// - newFechaEntrada
// Return:     void
////////////////////////////////////////////////////////////////////////

void RegistroEntradaSalida::setFechaEntrada(Fecha newFechaEntrada)
{
   fechaEntrada = newFechaEntrada;
}

////////////////////////////////////////////////////////////////////////
// Name:       RegistroEntradaSalida::getFechaSalida()
// Purpose:    Implementation of RegistroEntradaSalida::getFechaSalida()
// Return:     Fecha
////////////////////////////////////////////////////////////////////////

Fecha RegistroEntradaSalida::getFechaSalida(void)
{
   return fechaSalida;
}

////////////////////////////////////////////////////////////////////////
// Name:       RegistroEntradaSalida::setFechaSalida(Fecha newFechaSalida)
// Purpose:    Implementation of RegistroEntradaSalida::setFechaSalida()
// Parameters:
// - newFechaSalida
// Return:     void
////////////////////////////////////////////////////////////////////////

void RegistroEntradaSalida::setFechaSalida(Fecha newFechaSalida)
{
   fechaSalida = newFechaSalida;
}

////////////////////////////////////////////////////////////////////////
// Name:       RegistroEntradaSalida::RegistroEntradaSalida(Persona persona, Fecha fechaEntrada, Fecha fechaSalida)
// Purpose:    Implementation of RegistroEntradaSalida::RegistroEntradaSalida()
// Parameters:
// - persona
// - fechaEntrada
// - fechaSalida
// Return:     
////////////////////////////////////////////////////////////////////////

RegistroEntradaSalida::RegistroEntradaSalida(Persona persona, Fecha fechaEntrada, Fecha fechaSalida)
{
   this->persona = persona;
   this->fechaEntrada = fechaEntrada;
   this->fechaSalida = fechaSalida;
}

////////////////////////////////////////////////////////////////////////
// Name:       RegistroEntradaSalida::RegistroEntradaSalida()
// Purpose:    Implementation of RegistroEntradaSalida::RegistroEntradaSalida()
// Return:     
////////////////////////////////////////////////////////////////////////

RegistroEntradaSalida::RegistroEntradaSalida()
{
}

////////////////////////////////////////////////////////////////////////
// Name:       RegistroEntradaSalida::~RegistroEntradaSalida()
// Purpose:    Implementation of RegistroEntradaSalida::~RegistroEntradaSalida()
// Return:     
////////////////////////////////////////////////////////////////////////

RegistroEntradaSalida::~RegistroEntradaSalida()
{
   // TODO : implement
}

std::ostream& operator<<(std::ostream& os, const RegistroEntradaSalida& registro) {
	os << "Registro: -> {" << registro.persona
  		<< ", Fecha/hora Entrada: " << registro.fechaEntrada
		<< ", Fecha/hora Salida: "<< registro.fechaSalida << "}"<< std::endl;
  return os;
}

bool RegistroEntradaSalida::operator==(RegistroEntradaSalida& registro) {
	std::string cedula1 = this->getPersona().getCedula();
	std::string cedula2 = registro.getPersona().getCedula();
	return  cedula1 == cedula2;
}
