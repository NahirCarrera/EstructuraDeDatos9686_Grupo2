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