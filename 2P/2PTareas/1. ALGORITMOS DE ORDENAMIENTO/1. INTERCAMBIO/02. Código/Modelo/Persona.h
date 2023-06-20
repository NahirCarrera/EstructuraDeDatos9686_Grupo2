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

#if !defined(__Class_Diagram_1_Persona_h)
#define __Class_Diagram_1_Persona_h

#include <string>
#include "Fecha.h"
class Persona {
public:
   Persona();
   Persona(std::string cedula, std::string nombre, std::string apellido, Fecha fechaNacimiento);
   ~Persona();
   std::string getCedula(void);
   void setCedula(std::string newCedula);
   std::string getNombre(void);
   void setNombre(std::string newNombre);
   std::string getApellido(void);
   void setApellido(std::string newApellido);
   Fecha getFechaNacimiento(void);
   void setFechaNacimiento(Fecha);
   
   friend std::ostream& operator<<(std::ostream&, const Persona&);	
   bool operator==(Persona&);

private:
   std::string cedula;
   std::string nombre;
   std::string apellido;
   Fecha fechaNacimiento;

};

#endif
