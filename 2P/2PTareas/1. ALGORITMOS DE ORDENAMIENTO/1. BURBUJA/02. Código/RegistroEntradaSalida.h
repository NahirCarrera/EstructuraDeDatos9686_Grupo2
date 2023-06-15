/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Nombres: Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 14/06/23 18:57
 * Fecha de modificacion: 14/06/23 22:40
 * Enunciado:
 * Registro de entrada y salida de personas con listas circulares doblemente
 * enlazadas y algoritmo de búsqueda burbuja mejorado
 *
 *******************************************************************************/ 



#if !defined(__Class_Diagram_1_RegistroEntradaSalida_h)
#define __Class_Diagram_1_RegistroEntradaSalida_h

#include "Persona.h"
#include "Fecha.h"
#include <iostream>

class RegistroEntradaSalida
{
public:
   Persona getPersona(void);
   void setPersona(Persona newPersona);
   Fecha getFechaEntrada(void);
   void setFechaEntrada(Fecha newFechaEntrada);
   Fecha getFechaSalida(void);
   void setFechaSalida(Fecha newFechaSalida);
   RegistroEntradaSalida();
   RegistroEntradaSalida(Persona persona, Fecha fechaEntrada, Fecha fechaSalida);
   ~RegistroEntradaSalida();
   
   friend std::ostream& operator<<(std::ostream&, const RegistroEntradaSalida&);
   bool operator==(RegistroEntradaSalida&);

private:
   Persona persona;
   Fecha fechaEntrada;
   Fecha fechaSalida;


};

#endif
