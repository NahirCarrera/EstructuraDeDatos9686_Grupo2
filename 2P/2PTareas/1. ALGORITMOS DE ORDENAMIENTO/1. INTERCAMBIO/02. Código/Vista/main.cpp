/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Nombres: Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 14/06/23 18:57
 * Fecha de modificacion: 19/06/23 23:33
 * Enunciado:
 * Registro de entrada y salida de personas con listas circulares doblemente
 * enlazadas y algoritmo de búsqueda por intercambio
 *
 *******************************************************************************/ 
 
#include <iostream>
#include <cstdlib> // para usar system("cls") y system("pause")
#include <string>
#include "../Controlador/ListaCircularDoble.cpp"
#include "../Modelo/RegistroEntradaSalida.h"
#include "../Modelo/Fecha.h"
#include "../Modelo/Persona.h"
#include "../Herramientas/Menu.h"

void registrarEmpleado();
void registrarEntradaSalida();
void mostrarRegistroCompleto();
void mostrarRegistroIndividual();

int main() {
	std::string opcion;
	
	do {
		opcion = Menu::correrMenu();
		
		system("cls");
		
		if (opcion == "Registrar Empleado") {
			registrarEmpleado();
		}
	
		if (opcion == "Registrar Entrada/Salida") {
			registrarEntradaSalida();
		}
		
		if (opcion == "Mostrar Registro completo") {
			mostrarRegistroCompleto();
		}
		
		if (opcion == "Mostrar Registro individual") {
			mostrarRegistroIndividual();
		}
		
		if (opcion == "Salir") {
			std::cout << "Saliendo..." << std::endl;
		}	
		system("PAUSE");	
	} while (opcion != "Salir");
	
    return 0;
}


void registrarEmpleado() {
	std::cout << "registrando empleado" << std::endl;
}

void registrarEntradaSalida() {
	std::cout << "registrando entrada o salida" << std::endl;
}

void mostrarRegistroCompleto() {
	std::cout << "registro completo" << std::endl;
}

void mostrarRegistroIndividual() {
	std::cout << "registro individual" << std::endl;
}
