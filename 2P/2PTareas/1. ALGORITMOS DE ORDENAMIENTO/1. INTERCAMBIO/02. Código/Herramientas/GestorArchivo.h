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
#ifndef GESTORARCHIVO_H
#define GESTORARCHIVO_H

#include "../Modelo/Persona.h"
#include "../Modelo/RegistroEntradaSalida.h"
#include <string>

template <typename T>
class ListaCircularDoble;

class GestorArchivo{
	public:
		static void guardarListaPersonaComoCSV(ListaCircularDoble<Persona>&, std::string);
		static void cargarCSVEnListaPersona(ListaCircularDoble<Persona>&, std::string);
		static void guardarListaRegistroComoCSV(ListaCircularDoble<RegistroEntradaSalida>&, std::string);
		static void cargarCSVEnListaRegistro(ListaCircularDoble<RegistroEntradaSalida>&, ListaCircularDoble<Persona>&, std::string);
	private:
		static Fecha extraerFecha(std::string input);		
};

#endif