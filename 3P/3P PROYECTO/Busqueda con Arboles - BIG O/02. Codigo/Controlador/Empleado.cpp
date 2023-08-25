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

std::string Empleado::mostrar() {
	std::string strEmpleado;
	strEmpleado += "     ______________________________________________________\n";
	strEmpleado += "    /                                                     /\n"; 
	strEmpleado += "(O)===)><><><><><><><><><><><><><><><><><><><><><><><><><><><)==(O)\n";
	strEmpleado += "     /''''''''''''''''''''''''''''''''''''''''''''''''''''''/\n";;
	strEmpleado += "          __________ \n";
	strEmpleado += "         |          | NOMBRE: " + getNombre()+"\n";
	strEmpleado += "         |          | APELLIDO: " + getApellido()+"\n";
	strEmpleado += "         |          | CEDULA: " + getCedula()+"\n";
	strEmpleado += "         |          | FECHA DE NACIMIENTO: " + std::to_string(getFechaNacimiento().getDia()) + "/" + std::to_string(getFechaNacimiento().getMes()) + "/" + std::to_string(getFechaNacimiento().getAnio()) + "\n";
	strEmpleado += "         |          | SUELDO: $" + std::to_string(sueldo) + "\n";
	strEmpleado += "         |__________| \n";
	strEmpleado += " \n";
	strEmpleado += "      /''''''''''''''''''''''''''''''''''''''''''''''''''''''/\n";
	strEmpleado += "(O)===)><><><><><><><><><><><><><><><><><><><><><><><><><><><)==(O)\n";
	strEmpleado += "     /______________________________________________________/\n";
  	
	return strEmpleado;
	
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

