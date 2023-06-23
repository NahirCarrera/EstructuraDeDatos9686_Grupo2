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
#ifndef CONTROLADORMENU_H
#define CONTROLADORMENU_H
#include "../Modelo/ListaCircularDoble.h"
#include "../Modelo/Persona.h"
#include "../Modelo/RegistroEntradaSalida.h"

class ControladorMenu{
	public:
		static void correrMenu();
	private:
		static void registrarEmpleado(ListaCircularDoble<Persona>&);
		static void registrarEntradaSalida(ListaCircularDoble<RegistroEntradaSalida>&, ListaCircularDoble<Persona>&);
		static void mostrarRegistroPorEntrada(ListaCircularDoble<RegistroEntradaSalida>&);
		static void mostrarRegistroPorSalida(ListaCircularDoble<RegistroEntradaSalida>&);
		static void mostrarRegistroIndividual(ListaCircularDoble<RegistroEntradaSalida>&, ListaCircularDoble<Persona>&);
		static void mostrarEmpleadosPorNombre(ListaCircularDoble<Persona>&);
		static void mostrarEmpleadosPorApellido(ListaCircularDoble<Persona>&);
};

#endif