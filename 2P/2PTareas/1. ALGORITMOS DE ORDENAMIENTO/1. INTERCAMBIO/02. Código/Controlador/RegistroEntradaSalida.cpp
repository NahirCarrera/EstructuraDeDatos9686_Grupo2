/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Nombres: Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 14/06/23 18:57
 * Fecha de modificacion: 22/06/23 22:15
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

Persona RegistroEntradaSalida::getPersona(void) const
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

Fecha RegistroEntradaSalida::getFechaEntrada(void) const
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

Fecha RegistroEntradaSalida::getFechaSalida(void) const
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
// Name:       RegistroEntradaSalida::getContadorRegistro()
// Purpose:    Implementation of RegistroEntradaSalida::getContadorRegistro()
// Return:     int
////////////////////////////////////////////////////////////////////////

int RegistroEntradaSalida::getContadorRegistro() {
	return contadorRegistro;
}

////////////////////////////////////////////////////////////////////////
// Name:       RegistroEntradaSalida::setContadorRegistro(int newContadorRegistro)
// Purpose:    Implementation of RegistroEntradaSalida::setContadorRegistro()
// Parameters:
// - newContadorRegistro
// Return:     void
////////////////////////////////////////////////////////////////////////

void RegistroEntradaSalida::setContadorRegistro(int newContadorRegistro) {
	contadorRegistro = newContadorRegistro;
}

////////////////////////////////////////////////////////////////////////
// Name:       RegistroEntradaSalida::addContadorRegistro()
// Purpose:    Implementation of RegistroEntradaSalida::addContadorRegistro()
// Return:     void
////////////////////////////////////////////////////////////////////////

void RegistroEntradaSalida::addContadorRegistro(void) {
	contadorRegistro++;
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
   this->contadorRegistro = 0;
}

///////////////////////////////////////////////////////////////////////////////
// Name:       RegistroEntradaSalida::RegistroEntradaSalida()
// Purpose:    Implementation of RegistroEntradaSalida::RegistroEntradaSalida()
// Return:     
///////////////////////////////////////////////////////////////////////////////

RegistroEntradaSalida::RegistroEntradaSalida()
{
}

////////////////////////////////////////////////////////////////////////////////
// Name:       RegistroEntradaSalida::~RegistroEntradaSalida()
// Purpose:    Implementation of RegistroEntradaSalida::~RegistroEntradaSalida()
// Return:     
////////////////////////////////////////////////////////////////////////////////

RegistroEntradaSalida::~RegistroEntradaSalida()
{
   // TODO : implement
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       RegistroEntradaSalida::operator <<(std::ostream& os, const RegistroEntradaSalida& registro)
// Purpose:    Implementation of RegistroEntradaSalida::operator <<(std::ostream& os, const RegistroEntradaSalida& registro)
// Parameters:
// - os
// - registro
// Return:     bool
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

std::ostream& operator<<(std::ostream& os, const RegistroEntradaSalida& registro) {
	os << "           REGISTRO DE ENTRADA Y SALIDA        "<<std::endl;
	os << "    ____________________   ____________________"<<std::endl;
	os << ".-/|                     |                     |-."<<std::endl;
	os << "|||| NOMBRE:                                   ||||"<<std::endl;
	os << "     " + registro.persona.getNombre() + " " + registro.persona.getApellido() <<std::endl;
	os << "|||| CEDULA:                                   ||||"<<std::endl;
	os << "     " + registro.persona.getCedula()<<std::endl;
	os << "|||| FECHA/HORA ENTRADA:                       ||||"<<std::endl;
  	os << "     " << registro.fechaEntrada<<std::endl;
  	os << "|||| FECHA/HORA SALIDA:                        ||||"<<std::endl;
  	if(registro.fechaSalida.getAnio() == 0){
  		os << "     NO SE REGISTRO SALIDA"<<std::endl;
	  }else{
	  	os << "     " << registro.fechaSalida<<std::endl;
	  }
	os << "||||____________________ | ____________________||||"<<std::endl;
	os << "||/===================== | ===================== ||"<<std::endl;
	os << "`----------------------~___~---------------------''"<<std::endl;
	os << " "<<std::endl;
  return os;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       RegistroEntradaSalida::operator==(RegistroEntradaSalida& registro)
// Purpose:    Implementation of RegistroEntradaSalida::operator==(RegistroEntradaSalida& registro)
// Parameters:
// - registro
// Return:     bool
///////////////////////////////////////////////////////////////////////////////////////////////////

bool RegistroEntradaSalida::operator==(RegistroEntradaSalida& registro) {
	std::string cedula1 = this->getPersona().getCedula();
	std::string cedula2 = registro.getPersona().getCedula();
	return  cedula1 == cedula2;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       RegistroEntradaSalida::operator>(const RegistroEntradaSalida& registro)
// Purpose:    Implementation of RegistroEntradaSalida::operator>(const RegistroEntradaSalida& registro)
// Parameters:
// - registro
// Return:     bool
////////////////////////////////////////////////////////////////////////////////////////////////////////

bool RegistroEntradaSalida::operator>(const RegistroEntradaSalida& registro){
	if (this->fechaEntrada.getAnio() != registro.getFechaEntrada().getAnio())
        return this->fechaEntrada.getAnio() > registro.getFechaEntrada().getAnio();
    
	if (this->fechaEntrada.getMes() != registro.getFechaEntrada().getMes())
    	return this->fechaEntrada.getMes() > registro.getFechaEntrada().getMes();
    
	if (this->fechaEntrada.getDia() != registro.getFechaEntrada().getDia())
        return this->fechaEntrada.getDia() > registro.getFechaEntrada().getDia();
    
	if (this->fechaEntrada.getHora() != registro.getFechaEntrada().getHora())
        return this->fechaEntrada.getHora() > registro.getFechaEntrada().getHora();
    
	if (this->fechaEntrada.getMinuto() != registro.getFechaEntrada().getMinuto())
        return this->fechaEntrada.getMinuto() > registro.getFechaEntrada().getMinuto();
    
    return (this->fechaEntrada.getSegundo()>registro.getFechaEntrada().getSegundo());
    //return(persona.getNombre()>registro.persona.getNombre());
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       RegistroEntradaSalida::operator<(const RegistroEntradaSalida& registro)
// Purpose:    Implementation of RegistroEntradaSalida::operator<(const RegistroEntradaSalida& registro)
// Parameters:
// - registro
// Return:     bool
////////////////////////////////////////////////////////////////////////////////////////////////////////

bool RegistroEntradaSalida::operator<( const RegistroEntradaSalida& registro){
	if (this->fechaSalida.getAnio() != registro.getFechaSalida().getAnio())
        return this->fechaSalida.getAnio() > registro.getFechaSalida().getAnio();
    
	if (this->fechaSalida.getMes() != registro.getFechaSalida().getMes())
    	return this->fechaSalida.getMes() > registro.getFechaSalida().getMes();
    
	if (this->fechaSalida.getDia() != registro.getFechaSalida().getDia())
        return this->fechaSalida.getDia() > registro.getFechaSalida().getDia();
    
	if (this->fechaSalida.getHora() != registro.getFechaSalida().getHora())
        return this->fechaSalida.getHora() > registro.getFechaSalida().getHora();
    
	if (this->fechaSalida.getMinuto() != registro.getFechaSalida().getMinuto())
        return this->fechaSalida.getMinuto() > registro.getFechaSalida().getMinuto();
    
    return (this->fechaSalida.getSegundo()>registro.getFechaSalida().getSegundo());
}


