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
#if !defined(__Class_Diagram_1_Fecha_h)
#define __Class_Diagram_1_Fecha_h

#include <iostream>
#include <string>
class Fecha{
	public:
		//Constructor y destructor
	   Fecha();
	   Fecha(int, int, int, int, int, int);
	   Fecha(int, int, int);
	   ~Fecha();
	   //Getters y setters
	   int getAnio(void) const;
	   void setAnio(int newAnio);
	   int getMes(void) const;
	   void setMes(int newMes);
	   int getDia(void) const;
	   void setDia(int newDia);
	   int getHora(void) const;
	   void setHora(int newHora);
	   int getMinuto(void) const;
	   void setMinuto(int newMinuto);
	   int getSegundo(void) const;
	   void setSegundo(int newSegundo);
	   //Sobrecarga de operadores
	   friend std::ostream& operator<<(std::ostream&, const Fecha&);
	   bool operator==(Fecha fecha);
	   //Funciones
	   std::string obtenerFechaFormateada();
	   static Fecha obtenerFechaSimple(Fecha);
	   std::string mostrar();
	private:
	   int mes;
	   int dia;
	   int anio;
	   int hora;
	   int minuto;
	   int segundo;
};


#endif