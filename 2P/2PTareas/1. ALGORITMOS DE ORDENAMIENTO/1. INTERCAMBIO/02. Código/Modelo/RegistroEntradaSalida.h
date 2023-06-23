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

#if !defined(__Class_Diagram_1_RegistroEntradaSalida_h)
#define __Class_Diagram_1_RegistroEntradaSalida_h

#include "Persona.h"
#include "Fecha.h"
#include <iostream>

class RegistroEntradaSalida{
	public:
	   //Contructor
	   RegistroEntradaSalida();
	   RegistroEntradaSalida(Persona persona, Fecha fechaEntrada, Fecha fechaSalida);
	   ~RegistroEntradaSalida();
	   //Getters y Setters
	   Persona getPersona(void) const;
	   void setPersona(Persona newPersona);
	   Fecha getFechaEntrada(void) const;
	   void setFechaEntrada(Fecha newFechaEntrada);
	   Fecha getFechaSalida(void) const;
	   void setFechaSalida(Fecha newFechaSalida);
	   int getContadorRegistro(void);
	   void setContadorRegistro(int newContadorRegistro);
	   void addContadorRegistro(void);
	   //Sobrecarga de operadores
	   friend std::ostream& operator<<(std::ostream&, const RegistroEntradaSalida&);
	   bool operator==(RegistroEntradaSalida&);
	   bool operator>(const RegistroEntradaSalida&);
	   bool operator<( const RegistroEntradaSalida&);
	private:
	   Persona persona;
	   Fecha fechaEntrada;
	   Fecha fechaSalida;
	   int contadorRegistro;

};

#endif
