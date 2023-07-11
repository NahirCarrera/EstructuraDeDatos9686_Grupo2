#ifndef EMPLEADO_H
#define EMPLEADO_H
#pragma once
#include "Persona.h"

class Empleado : public Persona
{
	public:
		Empleado(std::string, std::string, std::string, Fecha, float);
		Empleado();
		~Empleado();
		float getSueldo();
		void setSueldo(float);
		
		friend std::ostream& operator<<(std::ostream&, const Empleado&);	
	   bool operator==(Empleado&);
	   bool operator>(const Empleado&);
	   bool operator<(const Empleado&);
				
	private:
		float sueldo;
};

#endif