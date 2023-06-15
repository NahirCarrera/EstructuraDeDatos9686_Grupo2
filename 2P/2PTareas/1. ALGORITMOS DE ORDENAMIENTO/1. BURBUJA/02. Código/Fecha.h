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

#if !defined(__Class_Diagram_1_Fecha_h)
#define __Class_Diagram_1_Fecha_h

#include <iostream>

class Fecha {
public:
   int getAnio(void);
   void setAnio(int newAnio);
   int getMes(void);
   void setMes(int newMes);
   int getDia(void);
   void setDia(int newDia);
   int getHora(void);
   void setHora(int newHora);
   int getMinuto(void);
   void setMinuto(int newMinuto);
   int getSegundo(void);
   void setSegundo(int newSegundo);
   Fecha();
   Fecha(int, int, int, int, int, int);
   ~Fecha();
   
   friend std::ostream& operator<<(std::ostream&, const Fecha&);

private:
   int mes;
   int dia;
   int anio;
   int hora;
   int minuto;
   int segundo;

};


#endif