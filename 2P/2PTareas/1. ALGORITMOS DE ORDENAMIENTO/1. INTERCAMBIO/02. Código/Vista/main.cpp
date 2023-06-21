/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Nombres: Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 14/06/23 18:57
 * Fecha de modificacion: 20/06/23 18:49
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
#include "../Herramientas/GestorArchivo.h"
#include "../Herramientas/Dato.h"

void registrarEmpleado(ListaCircularDoble<Persona>&);
void registrarEntradaSalida(ListaCircularDoble<RegistroEntradaSalida>&);
void mostrarRegistroCompleto(ListaCircularDoble<RegistroEntradaSalida>&);
void mostrarRegistroIndividual();

int main() {
	ListaCircularDoble<Persona> listaPersonas;
	ListaCircularDoble<RegistroEntradaSalida> listaRegistros;
	std::string opcion;
	
	// Cargar archivos
	GestorArchivo::cargarCSVEnListaPersona(listaPersonas, "personas.csv");
	GestorArchivo::cargarCSVEnListaRegistro(listaRegistros, listaPersonas, "registros.csv");
	
	do {
		opcion = Menu::correrMenu();
		
		system("cls");
		
		if (opcion == "Registrar Empleado") {
			registrarEmpleado(listaPersonas);
		}
	
		if (opcion == "Registrar Entrada/Salida") {
			registrarEntradaSalida(listaRegistros);
		}
		
		if (opcion == "Mostrar Registro completo") {
			mostrarRegistroCompleto(listaRegistros);
		}
		
		if (opcion == "Mostrar Registro individual") {
			mostrarRegistroIndividual();
		}
		
		if (opcion == "Mostrar Empleados") {
			listaPersonas.mostrar();
		}
		
		if (opcion == "Salir") {
			std::cout << "Saliendo..." << std::endl;
		}	
		system("PAUSE");	
	} while (opcion != "Salir");
	
    return 0;
}


void registrarEmpleado(ListaCircularDoble<Persona>& lista) {
	std::string cedula, nombre, apellido;
    Fecha fecha;
	
	std::cout << "registrando empleado" << std::endl;
	// Obtener datos para una persona
    
    std::cout << "Ingrese la cedula: ";
    cedula = Dato::ingresarCedulaEcuador();
    
    if (!lista.buscar(Persona(cedula, "", "", fecha))) {
    	std::cout << "Ingrese un nombre: ";
	    nombre = Dato::ingresarNombreSimple();
	    std::cout << "Ingrese un apellido: ";
	    apellido = Dato::ingresarNombreSimple();;
		std::cout << "Ingrese la fecha de nacimiento:\n";
		fecha = Dato::ingresarFechaCumple();
		
	    // Crear una persona con los datos ingresados
	    Persona persona(cedula, nombre, apellido, fecha);
	    
	    lista.insertar(persona);
	    GestorArchivo::guardarListaPersonaComoCSV(lista, "personas.csv");
	} else {
		std::cout << "Cedula ya registrada..." << std::endl;
	}
    
}

void registrarEntradaSalida(ListaCircularDoble<RegistroEntradaSalida>& listaRegistros) {
	std::cout << "registrando entrada o salida" << std::endl;
	Fecha fecha;
	Persona persona("1752235943", "", "", fecha);
	RegistroEntradaSalida registro(persona, fecha, fecha);
	listaRegistros.insertar(registro);
	GestorArchivo::guardarListaRegistroComoCSV(listaRegistros, "registros.csv");
}

void mostrarRegistroCompleto(ListaCircularDoble<RegistroEntradaSalida>& listaRegistros) {
	std::cout << "registro completo" << std::endl;
	listaRegistros.mostrar();
}

void mostrarRegistroIndividual() {
	std::cout << "registro individual" << std::endl;
}
