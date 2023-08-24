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

#if !defined(__Class_Diagram_1_RegistroEntradaSalida_h)
#define __Class_Diagram_1_RegistroEntradaSalida_h

#include "Empleado.h"
#include "Fecha.h"
#include <iostream>

class RegistroEntradaSalida{
	public:
	   //Contructor
	   RegistroEntradaSalida();
	   RegistroEntradaSalida(Empleado empleado, Fecha fechaEntrada, Fecha fechaSalida);
	   ~RegistroEntradaSalida();
	   //Getters y Setters
	   Empleado getEmpleado(void) const;
	   void setEmpleado(Empleado newEmpleado);
	   Fecha getFechaEntrada(void) const;
	   void setFechaEntrada(Fecha newFechaEntrada);
	   Fecha getFechaSalida(void) const;
	   void setFechaSalida(Fecha newFechaSalida);
	   int getContadorRegistro(void);
	   void setContadorRegistro(int newContadorRegistro);
	   void addContadorRegistro(void);
	   //Sobrecarga de operadores
	   friend std::ostream& operator<<(std::ostream&, const RegistroEntradaSalida&);
	   bool operator==(const RegistroEntradaSalida&);
	   bool operator>(const RegistroEntradaSalida&);
	   bool operator<( const RegistroEntradaSalida&);
	private:
	   Empleado empleado;
	   Fecha fechaEntrada;
	   Fecha fechaSalida;
	   int contadorRegistro;

};

#endif
