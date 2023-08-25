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

#if !defined(__Class_Diagram_1_Persona_h)
#define __Class_Diagram_1_Persona_h

#include <string>
#include "Fecha.h"
class Persona{
	public:
	   //Constructor y destructor
	   Persona();
	   Persona(std::string cedula, std::string nombre, std::string apellido, Fecha fechaNacimiento);
	   ~Persona();
	   //Setters y getters
	   std::string getCedula(void) const;
	   void setCedula(std::string newCedula);
	   std::string getNombre(void) const;
	   void setNombre(std::string newNombre);
	   std::string getApellido(void) const;
	   void setApellido(std::string newApellido);
	   Fecha getFechaNacimiento(void) const;
	   void setFechaNacimiento(Fecha);
	   //Sibrecarga de operadores
	   friend std::ostream& operator<<(std::ostream&, const Persona&);	
	   bool operator==(Persona&);
	   bool operator>(const Persona&);
	   bool operator<(const Persona&);
	private:
	   std::string cedula;
	   std::string nombre;
	   std::string apellido;
	   Fecha fechaNacimiento;
};

#endif
