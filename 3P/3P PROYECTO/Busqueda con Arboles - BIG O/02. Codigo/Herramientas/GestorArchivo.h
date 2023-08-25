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
#ifndef GESTORARCHIVO_H
#define GESTORARCHIVO_H

#include "../Modelo/Empleado.h"
#include "../Modelo/RegistroEntradaSalida.h"
#include <vector>
#include <string>

template <typename T>
class ListaCircularDoble;

class GestorArchivo{
	public:
		static void guardarListaEmpleadoComoCSV(ListaCircularDoble<Empleado>&, std::string);
		static void cargarCSVEnListaEmpleado(ListaCircularDoble<Empleado>&, std::string);
		static void guardarListaRegistroComoCSV(ListaCircularDoble<RegistroEntradaSalida>&, std::string);
		static void cargarCSVEnListaRegistro(ListaCircularDoble<RegistroEntradaSalida>&, ListaCircularDoble<Empleado>&, std::string);
		static std::vector<std::pair<float, float>> cargarPuntos(std::string);
	private:
		static Fecha extraerFecha(std::string input);		
};

#endif