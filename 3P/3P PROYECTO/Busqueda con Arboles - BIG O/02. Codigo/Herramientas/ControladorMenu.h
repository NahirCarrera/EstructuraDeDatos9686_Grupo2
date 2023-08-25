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
#ifndef CONTROLADORMENU_H
#define CONTROLADORMENU_H
#include "../Modelo/ListaCircularDoble.h"
#include <string>

class ControladorMenu{
	public:
		ControladorMenu(){};
		void correrMenu();
	private:
		//Funciones de control de personal
		void registrarEmpleado();
		void eliminarEmpleado();
		void registrarEntradaSalida();
		void mostrarRegistro();
		void mostrarEmpleados();
		void mostrarRegistroIndividual();
		void modificarNombreApellido(std::string cedula);
		void modificarSueldo(std::string cedula);
		//Funciones extras
		void crearCopiaDeSeguridad();
		void restaurarDatos();
		void generarPdf();
		void crearSistemaDeAyuda(); 
		void imprimirFoto();
		void generarDatos();
		void graficar();

		//Submenus
		void subMenuRegistroDePersonal();
		void subMenuExtras();
		void modificarEmpleado();
		//Salir
		void salir();
		bool menuEjecutando = false;
};

#endif