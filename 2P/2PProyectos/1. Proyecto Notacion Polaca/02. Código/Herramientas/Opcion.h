/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Nombres: Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 26/06/23 22:21
 * Fecha de modificacion: 26/06/23 22:21
 * Enunciado:
 * Proyecto transformacion de expresion infija a notacion polaca y polaca inversa
 *
 *******************************************************************************/ 

#ifndef OPCION_H
#define OPCION_H

#include <string>
#include <functional>

class Opcion
{
	public:
		Opcion(std::string texto, const std::function<void()>&);
		Opcion();
		~Opcion();
		
		void setTexto(std::string);
	    std::string getTexto() const;
	    void setFuncion(const std::function<void()>&);
		
		void ejecutar();
		
		friend std::ostream& operator<<(std::ostream&, const Opcion&);
		bool operator==(Opcion&);
	    bool operator>(const Opcion&);
	    bool operator<(const Opcion&);
		
	private:
		std::string texto;
		std::function<void()> funcion;
		
};

#endif