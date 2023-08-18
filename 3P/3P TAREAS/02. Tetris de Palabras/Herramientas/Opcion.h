/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Estructura de Datos 9686
 * Nombres: Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 12/08/23 19:40
 * Fecha de modificacion: 12/08/23 19:40
 * Enunciado:
 * Realizar el juego del tetris con palabras en consola (Solo caida horizontal)
 * EXTRA: Realizar la rotación de las piezas
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