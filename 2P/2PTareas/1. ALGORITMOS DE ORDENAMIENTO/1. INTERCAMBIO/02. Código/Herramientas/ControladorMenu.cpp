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
 
#include "ControladorMenu.h"
#include "../Controlador/ListaCircularDoble.cpp"
#include "../Controlador/NodoDoble.cpp"
#include "../Modelo/RegistroEntradaSalida.h"
#include "../Modelo/Fecha.h"
#include "../Modelo/Persona.h"
#include "../Herramientas/Menu.h"
#include "../Herramientas/GestorArchivo.h"
#include "../Herramientas/Dato.h"
#include <string>
#include <cstdlib> // para usar system("cls") y system("pause")

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ControladorMenu::registrarEmpleado(ListaCircularDoble<Persona>& lista)
// Purpose:    Implementation of ControladorMenu::registrarEmpleado(ListaCircularDoble<Persona>& lista)
// Parameters:
// - lista
// Return:     void
////////////////////////////////////////////////////////////////////////////////////////////////////////

void ControladorMenu::registrarEmpleado(ListaCircularDoble<Persona>& lista) {
	std::string cedula, nombre, apellido;
    Fecha fecha;
	std::cout<< "(O)===)><><><><><><><><><><><><><><><><><><><><><><><><><><><)==(O)"<<std::endl;
	std::cout << "                      REGISTRO DE EMPLEADO" << std::endl;
	// Obtener datos para una persona
    
    std::cout << "(O)===)> Ingrese la cedula: ";
    cedula = Dato::ingresarCedulaEcuador();
    
    if (!lista.buscar(Persona(cedula, "", "", fecha))) {
    	std::cout << "(O)===)> Ingrese un nombre: ";
	    nombre = Dato::ingresarNombreSimple();
	    std::cout << "(O)===)> Ingrese un apellido: ";
	    apellido = Dato::ingresarNombreSimple();;
		std::cout << "(O)===)> Ingrese la fecha de nacimiento:\n";
		fecha = Dato::ingresarFechaCumple();
		std::cout<< "(O)===)><><><><><><><><><><><><><><><><><><><><><><><><><><><)==(O)"<<std::endl;
	    // Crear una persona con los datos ingresados
	    Persona persona(cedula, nombre, apellido, fecha);
	    
	    lista.insertar(persona);
	    GestorArchivo::guardarListaPersonaComoCSV(lista, "personas.csv");
	} else {
		std::cout << " Cedula ya registrada..." << std::endl;
	}
    
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ControladorMenu::registrarEntradaSalida(ListaCircularDoble<RegistroEntradaSalida>& listaRegistros, ListaCircularDoble<Persona>& personas)
// Purpose:    Implementation of ControladorMenu::registrarEntradaSalida(ListaCircularDoble<RegistroEntradaSalida>& listaRegistros, ListaCircularDoble<Persona>& personas)
// Parameters:
// - listaRegistros
// - personas
// Return:     void
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ControladorMenu::registrarEntradaSalida(ListaCircularDoble<RegistroEntradaSalida>& listaRegistros, ListaCircularDoble<Persona>& personas){
	std::string cedula;
	Fecha fecha(0,0,0,0,0,0);
	Fecha fechaActual;
	NodoDoble<RegistroEntradaSalida>* nodoRegistro;
	NodoDoble<Persona>* nodoPersona;
	listaRegistros = ListaCircularDoble<RegistroEntradaSalida>();
	GestorArchivo::cargarCSVEnListaRegistro(listaRegistros, personas, "registros.csv");
	
	std::cout << "(O)===)><><><><><><><><><><><><><><><><><><><><><><><><><><><)==(O)"<<std::endl;
	std::cout << "                 REGISTRO DE ENTRADA Y SALIDA" << std::endl;	
	std::cout << "(O)===)> Ingrese la cedula: ";
    cedula = Dato::ingresarCedulaEcuador();
    std::cout << "(O)===)><><><><><><><><><><><><><><><><><><><><><><><><><><><)==(O)"<<std::endl;		
	nodoPersona = personas.extraerNodo(Persona(cedula, "", "", fecha));
	
	// Primero buscamos si hay la cedula registrada
	if (nodoPersona != nullptr) {
		RegistroEntradaSalida registro(nodoPersona->getDato(), fecha, fecha);
		
		nodoRegistro = listaRegistros.extraerNodo(registro);
		
		// Si no existe un registro de esa cedula creamos uno
		if(nodoRegistro == nullptr) {
			RegistroEntradaSalida registroNuevo(nodoPersona->getDato(), fechaActual, fecha);
			listaRegistros.insertar(registroNuevo);
		} else {
			// Si existe un registro con el contador en 1 es porque ya registro la salida
			// y se debe crear uno nuevo para esa cedula
			if (nodoRegistro->getDato().getContadorRegistro() == 1) {
				RegistroEntradaSalida registroNuevo(nodoPersona->getDato(), fechaActual, fecha);
				listaRegistros.insertar(registroNuevo);
			} else {
				// Si no es 1 es porque es 0, en este caso falta registrar la nueva salida
				RegistroEntradaSalida registroNuevo = nodoRegistro->getDato();
				registroNuevo.setFechaSalida(fechaActual);
				registroNuevo.addContadorRegistro();
				
				nodoRegistro->setDato(registroNuevo);
			}
		}
		
		GestorArchivo::guardarListaRegistroComoCSV(listaRegistros, "registros.csv");
	} else {
		std::cout << " ¡¡ Cedula no registrada..." << std::endl;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ControladorMenu::mostrarRegistroPorEntrada(ListaCircularDoble<RegistroEntradaSalida>& lista)
// Purpose:    Implementation of ControladorMenu::mostrarRegistroPorEntrada(ListaCircularDoble<RegistroEntradaSalida>& lista)
// Parameters:
// - lista
// Return:     void
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ControladorMenu::mostrarRegistroPorEntrada(ListaCircularDoble<RegistroEntradaSalida>& lista){
	lista.ordenarPorIntercambio(1);
	lista.mostrar();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ControladorMenu::mostrarRegistroPorSalida(ListaCircularDoble<RegistroEntradaSalida>& lista)
// Purpose:    Implementation of ControladorMenu::mostrarRegistroPorSalida(ListaCircularDoble<RegistroEntradaSalida>& lista)
// Parameters:
// - lista
// Return:     void
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ControladorMenu::mostrarRegistroPorSalida(ListaCircularDoble<RegistroEntradaSalida>& lista){
	lista.ordenarPorIntercambio(2);
	lista.mostrar();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ControladorMenu::mostrarRegistroIndividual(ListaCircularDoble<RegistroEntradaSalida>& listaRegistros, ListaCircularDoble<Persona>& personas)
// Purpose:    Implementation of ControladorMenu::mostrarRegistroIndividual(ListaCircularDoble<RegistroEntradaSalida>& listaRegistros, ListaCircularDoble<Persona>& personas)
// Parameters:
// - listaRegistros
// - personas
// Return:     void
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ControladorMenu::mostrarRegistroIndividual(ListaCircularDoble<RegistroEntradaSalida>& listaRegistros, ListaCircularDoble<Persona>& personas){
	std::cout<< "(O)===)><><><><><><><><><><><><><><><><><><><><><><><><><><><)==(O)"<<std::endl;
	std::cout << "                      REGISTRO INDIVIDUAL" << std::endl;
	std::string cedula;
    Fecha fecha;
    
    std::cout << "(O)===)> Ingrese la cedula: ";
    cedula = Dato::ingresarCedulaEcuador();
    std::cout << "(O)===)><><><><><><><><><><><><><><><><><><><><><><><><><><><)==(O)"<<std::endl;
    system("cls");
    Persona persona(cedula, "", "", fecha);
    NodoDoble<Persona>* nodoPersona = personas.extraerNodo(persona);
    
    if (nodoPersona != nullptr) {	
    	RegistroEntradaSalida registroBusqueda(persona, fecha, fecha);
    	
    	std::cout << nodoPersona->getDato() << std::endl << std::endl;
		listaRegistros.mostrarRepetidos(registroBusqueda);
	} else {
		std::cout << " ¡¡ Cedula no registrada..." << std::endl;
	}
	
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ControladorMenu::mostrarEmpleadosPorNombre(ListaCircularDoble<Persona>& lista)
// Purpose:    Implementation of ControladorMenu::mostrarEmpleadosPorNombre(ListaCircularDoble<Persona>& lista)
// Parameters:
// - lista
// Return:     void
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ControladorMenu::mostrarEmpleadosPorNombre(ListaCircularDoble<Persona>& lista){
	lista.ordenarPorIntercambio(1);
	lista.mostrar();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ControladorMenu::mostrarEmpleadosPorApellido(ListaCircularDoble<Persona>& lista)
// Purpose:    Implementation of ControladorMenu::mostrarEmpleadosPorNombre(ListaCircularDoble<Persona>& lista)
// Parameters:
// - lista
// Return:     void
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ControladorMenu::mostrarEmpleadosPorApellido(ListaCircularDoble<Persona>& lista){
	lista.ordenarPorIntercambio(2);
	lista.mostrar();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ControladorMenu::correrMenu()
// Purpose:    Implementation of ControladorMenu::correrMenu()
// Return:     void
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ControladorMenu::correrMenu(){
	ListaCircularDoble<Persona> listaPersonas;
	ListaCircularDoble<RegistroEntradaSalida> listaRegistros;
	std::string opcion;
	
	// Cargar archivos
	GestorArchivo::cargarCSVEnListaPersona(listaPersonas, "personas.csv");
	GestorArchivo::cargarCSVEnListaRegistro(listaRegistros, listaPersonas, "registros.csv");
	
	do {
		opcion = Menu::crearMenu();
		
		system("cls");
		if (opcion == "Registrar Empleado                            ") {
			registrarEmpleado(listaPersonas);
		}
	
		if (opcion == "Registrar Entrada/Salida                      ") {
			registrarEntradaSalida(listaRegistros, listaPersonas);
		}
		
		if (opcion == "Mostrar Registro ordenado por fecha de entrada") {
			mostrarRegistroPorEntrada(listaRegistros);
		}
		
		if (opcion == "Mostrar Registro ordenado por fecha de salida ") {
			mostrarRegistroPorSalida(listaRegistros);
		}
		
		if (opcion == "Mostrar Registro individual                   ") {
			mostrarRegistroIndividual(listaRegistros, listaPersonas);
		}
		
		if (opcion == "Mostrar Empleados ordenado por nombre         ") {
			mostrarEmpleadosPorNombre(listaPersonas);
		}
		
		if (opcion == "Mostrar Empleados ordenado por apellido       ") {
			mostrarEmpleadosPorApellido(listaPersonas);
		}
		
		if (opcion == "Salir                                         ") {
			std::cout << "Saliendo..." << std::endl;
		}	
		system("PAUSE");	
	} while (opcion != "Salir                                         ");
}