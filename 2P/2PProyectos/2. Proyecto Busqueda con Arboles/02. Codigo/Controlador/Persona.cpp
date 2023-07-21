/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Estructura de Datos 9686
 * Nombres: Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 07/07/23 21:42
 * Fecha de modificacion: 07/07/23 21:42
 * Enunciado:
 * Registro de entrada y salida de personas con listas circulares doblemente
 * enlazadas y búsqueda con árboles binarios + Extras
 *
 *******************************************************************************/  

#include "../Modelo/Persona.h"
#include <iostream>
////////////////////////////////////////////////////////////////////////
// Name:       Persona::Persona(std::string cedula, std::string nombre, std::string apellido)
// Purpose:    Implementation of Persona::Persona()
// Parameters:
// - cedula
// - nombre
// - apellido
// - fechaNacimiento
// Return:     
////////////////////////////////////////////////////////////////////////

Persona::Persona(std::string cedula, std::string nombre, std::string apellido, Fecha fechaNacimiento)
{
    this->nombre = nombre;
    this->apellido = apellido;
    this->cedula = cedula;
    this->fechaNacimiento = fechaNacimiento;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::Persona()
// Purpose:    Implementation of Persona::Persona()
// Return:     
////////////////////////////////////////////////////////////////////////

Persona::Persona()
{
    this->nombre = "";
    this->apellido = "";
    this->cedula = "";
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::~Persona()
// Purpose:    Implementation of Persona::~Persona()
// Return:     
////////////////////////////////////////////////////////////////////////

Persona::~Persona()
{
   // TODO : implement
}
////////////////////////////////////////////////////////////////////////
// Name:       Persona::getCedula()
// Purpose:    Implementation of Persona::getCedula()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

std::string Persona::getCedula(void) const
{
   return cedula;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::setCedula(std::string newCedula)
// Purpose:    Implementation of Persona::setCedula()
// Parameters:
// - newCedula
// Return:     void
////////////////////////////////////////////////////////////////////////

void Persona::setCedula(std::string newCedula)
{
   cedula = newCedula;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::getNombre()
// Purpose:    Implementation of Persona::getNombre()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

std::string Persona::getNombre(void) const
{
   return nombre;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::setNombre(std::string newNombre)
// Purpose:    Implementation of Persona::setNombre()
// Parameters:
// - newNombre
// Return:     void
////////////////////////////////////////////////////////////////////////

void Persona::setNombre(std::string newNombre)
{
   nombre = newNombre;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::getApellido()
// Purpose:    Implementation of Persona::getApellido()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

std::string Persona::getApellido(void) const
{
   return apellido;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::setApellido(std::string newApellido)
// Purpose:    Implementation of Persona::setApellido()
// Parameters:
// - newApellido
// Return:     void
////////////////////////////////////////////////////////////////////////

void Persona::setApellido(std::string newApellido)
{
   apellido = newApellido;
}
////////////////////////////////////////////////////////////////////////
// Name:       Persona::getFechaNacimiento()
// Purpose:    Implementation of Persona::getFechaNacimiento()
// Return:     Fecha
////////////////////////////////////////////////////////////////////////

Fecha Persona::getFechaNacimiento(void) const
{
   return fechaNacimiento;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::setFechaNacimiento(Fecha newFechaNacimiento)
// Purpose:    Implementation of Persona::setFechaNacimiento()
// Parameters:
// - newFechaNacimiento
// Return:     void
////////////////////////////////////////////////////////////////////////

void Persona::setFechaNacimiento(Fecha newFechaNacimiento)
{
   fechaNacimiento = newFechaNacimiento;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::operator <<(std::ostream& os, const Persona& persona)
// Purpose:    Implementation of Persona::operator <<()
// Parameters:
// - os
// - persona
// Return:     std::ostream&
////////////////////////////////////////////////////////////////////////

std::ostream& operator <<(std::ostream& os, const Persona& persona) {
	 os << "     ______________________________________________________"<<std::endl;
     os << "    /                                                     /"<<std::endl; 
     os << "(O)===)><><><><><><><><><><><><><><><><><><><><><><><><><><><)==(O)"<<std::endl;
     os << "     /''''''''''''''''''''''''''''''''''''''''''''''''''''''/"<<std::endl;;
  	 os << "          __________ "<<std::endl;
     os << "         |          | NOMBRE: " + persona.nombre<<std::endl;
     os << "         |          | APELLIDO: " + persona.apellido<<std::endl;
     os << "         |          | CEDULA: " + persona.cedula<<std::endl;
     os << "         |          | FECHA DE NACIMIENTO: " << persona.fechaNacimiento<<std::endl;
     os << "         |__________| "<<std::endl;
     os << " "<<std::endl;
     os << "      /''''''''''''''''''''''''''''''''''''''''''''''''''''''/"<<std::endl;
     os << "(O)===)><><><><><><><><><><><><><><><><><><><><><><><><><><><)==(O)"<<std::endl;
     os << "     /______________________________________________________/"<<std::endl;
  return os;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::operator ==(Persona& persona)
// Purpose:    Implementation of Persona::operator ==()
// Parameters:
// - persona
// Return:     bool
////////////////////////////////////////////////////////////////////////
bool Persona::operator==(Persona& persona){
	return (this->cedula == persona.cedula);
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::operator >(Persona& persona)
// Purpose:    Implementation of Persona::operator >()
// Parameters:
// - persona
// Return:     bool
////////////////////////////////////////////////////////////////////////
bool Persona::operator>(const Persona& persona){
	return (this->nombre > persona.nombre);
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::operator <(Persona& persona)
// Purpose:    Implementation of Persona::operator <()
// Parameters:
// - persona
// Return:     bool
////////////////////////////////////////////////////////////////////////
bool Persona::operator<(const Persona& persona){
	return (this->apellido > persona.apellido);
}

