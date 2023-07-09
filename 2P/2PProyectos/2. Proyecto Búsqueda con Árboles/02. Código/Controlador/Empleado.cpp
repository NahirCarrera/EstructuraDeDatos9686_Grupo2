#include "../Modelo/Empleado.h"

////////////////////////////////////////////////////////////////////////
// Name:       Empleado::Empleado(std::string cedula, std::string nombre, std::string apellido, Fecha fechaNacimiento, float sueldo)
// Purpose:    Implementation of Empleado::Empleado()
// Parameters:
// - cedula
// - nombre
// - apellido
// - fechaNacimiento
// - sueldo
// Return:     
////////////////////////////////////////////////////////////////////////

Empleado::Empleado(std::string cedula, std::string nombre, std::string apellido, Fecha fechaNacimiento, float sueldo)
    : Persona(cedula, nombre, apellido, fechaNacimiento), sueldo(sueldo) {
}

////////////////////////////////////////////////////////////////////////
// Name:       Empleado::Empleado()
// Purpose:    Implementation of Empleado::Empleado()
// Return:     
////////////////////////////////////////////////////////////////////////


Empleado::Empleado() {
}

////////////////////////////////////////////////////////////////////////
// Name:       Empleado::~Empleado()
// Purpose:    Implementation of Empleado::~Empleado()
// Return:     
////////////////////////////////////////////////////////////////////////


Empleado::~Empleado() {
}

////////////////////////////////////////////////////////////////////////
// Name:       Empleado::getSueldo()
// Purpose:    Implementation of Persona::getSueldo()
// Return:     float
////////////////////////////////////////////////////////////////////////

float Empleado::getSueldo() {
    return sueldo;
}

////////////////////////////////////////////////////////////////////////
// Name:       Empleado::setSueldo(float sueldo) 
// Purpose:    Implementation of Empleado::setSueldo()
// Parameters:
// - sueldo
// Return:     void
////////////////////////////////////////////////////////////////////////


void Empleado::setSueldo(float sueldo) {
    this->sueldo = sueldo;
}

////////////////////////////////////////////////////////////////////////
// Name:       Empleado::operator <<(std::ostream& os, const Empleado& empleado)
// Purpose:    Implementation of Persona::operator <<()
// Parameters:
// - os
// - persona
// Return:     std::ostream&
////////////////////////////////////////////////////////////////////////

std::ostream& operator <<(std::ostream& os, const Empleado& empleado) {
	 os << "     ______________________________________________________"<<std::endl;
     os << "    /                                                     /"<<std::endl; 
     os << "(O)===)><><><><><><><><><><><><><><><><><><><><><><><><><><><)==(O)"<<std::endl;
     os << "     /''''''''''''''''''''''''''''''''''''''''''''''''''''''/"<<std::endl;;
  	 os << "          __________ "<<std::endl;
     os << "         |          | NOMBRE: " + empleado.getNombre()<<std::endl;
     os << "         |          | APELLIDO: " + empleado.getApellido()<<std::endl;
     os << "         |          | CEDULA: " + empleado.getCedula()<<std::endl;
     os << "         |          | FECHA DE NACIMIENTO: " << empleado.getFechaNacimiento()<<std::endl;
     os << "         |          | SUELDO: $" << empleado.sueldo << std::endl;
     os << "         |__________| "<<std::endl;
     os << " "<<std::endl;
     os << "      /''''''''''''''''''''''''''''''''''''''''''''''''''''''/"<<std::endl;
     os << "(O)===)><><><><><><><><><><><><><><><><><><><><><><><><><><><)==(O)"<<std::endl;
     os << "     /______________________________________________________/"<<std::endl;
  return os;
}

////////////////////////////////////////////////////////////////////////
// Name:       Empleado::operator ==(Persona& empleado)
// Purpose:    Implementation of Persona::operator ==()
// Parameters:
// - empleado
// Return:     bool
////////////////////////////////////////////////////////////////////////
bool Empleado::operator==(Empleado& empleado){
	return (this->getCedula() == empleado.getCedula());
}

////////////////////////////////////////////////////////////////////////
// Name:       Empleado::operator >(Empleado& empleado)
// Purpose:    Implementation of Empleado::operator >()
// Parameters:
// - empleado
// Return:     bool
////////////////////////////////////////////////////////////////////////
bool Empleado::operator>(const Empleado& empleado){
	return (this->getNombre() > empleado.getNombre());
}

////////////////////////////////////////////////////////////////////////
// Name:       Empleado::operator <(Empleado& empleado)
// Purpose:    Implementation of Empleado::operator <()
// Parameters:
// - empleado
// Return:     bool
////////////////////////////////////////////////////////////////////////
bool Empleado::operator<(const Empleado& empleado){
	return (this->getApellido() > empleado.getApellido());
}

