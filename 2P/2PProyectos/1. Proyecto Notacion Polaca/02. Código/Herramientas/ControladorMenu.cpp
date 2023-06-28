/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Nombres: Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 26/06/23 22:21
 * Fecha de modificacion: 26/06/23 22:21
 * Enunciado:
 * Proyecto transformacion de expresion infija a notacion polaca y polaca inversa
 *
 *******************************************************************************/ 
 
#include "ControladorMenu.h"
#include "../Controlador/ListaCircularDoble.cpp"
#include "../Controlador/NodoDoble.cpp"
#include "../Herramientas/Menu.h"
#include "../Herramientas/Dato.h"
#include <string>
#include <cstdlib> // para usar system("cls") y system("pause")


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ControladorMenu::operarPosfijo(std::string infijo)
// Purpose:    Muestra la expreio
// Parameters:
// - infijo
// Return:     void
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ControladorMenu::operarPostfijo(std::string infijo) {
	std::cout << "Expresion Infijo: " << std::endl;
	std::cout << infijo << std::endl;
	std::cout << "Expresion Posfijo: " << std::endl;
	std::cout << infijo << std::endl;
	std::cout << "\nResultado: " << 0 << std::endl;
	system("pause");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ControladorMenu::operarPrefijo(std::string infijo)
// Purpose:    Transforma de infijo a Prefijo
// - infijo
// Return:     void
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ControladorMenu::operarPrefijo(std::string infijo) {
	std::cout << "Expresion Infijo: " << std::endl;
	std::cout << infijo << std::endl;
	std::cout << "Expresion Prefijo: " << std::endl;
	std::cout << infijo << std::endl;
	std::cout << "\nResultado: " << 0 << std::endl;
	system("pause");
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ControladorMenu::ingresarInfijo()
// Purpose:    ingresa la expresion en infijo
// Parameters:
// Return:     void
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ControladorMenu::ingresarInfijo() {
	std::string infijo;
	std::cout << "Ingrese la expresion Infijo: " << std::endl;
	std::getline(std::cin, infijo);
	
	subMenuPolaca(infijo);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ControladorMenu::salir()
// Purpose:    Salir del bucle actual
// Return:     void
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ControladorMenu::salir() {
	menuEjecutando = false;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ControladorMenu::subMenuPolaca(std::string infijo)
// Purpose:    Mostrar submenu
// Return:     void
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ControladorMenu::subMenuPolaca(std::string infijo) {
	std::string titulo = "\n-----------Menu Operaciones-------------\nExpresion infijo: " +  infijo + "\n";
	Menu menu(titulo);
	
	menu.insertarOpcion("Mostrar notacion Polaca (prefija)", [&]() { operarPrefijo(infijo); });
	menu.insertarOpcion("Mostrar notacion Polaca Inversa (postfija)", [&]() { operarPostfijo(infijo); });
	menu.insertarOpcion("Regresar a insertar expresion", [&]() { salir(); }); // Para salir del bucle siempre se debe usar esta funcion de salir()
	
	while (menuEjecutando) {
		menu.correr();
	}
	menuEjecutando = true; // Siempre que se quiera correr un menu en bucle
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ControladorMenu::correrMenu()
// Purpose:    Implementation of ControladorMenu::correrMenu()
// Return:     void
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ControladorMenu::correrMenu() {	
	Menu menu("\n-----------Menu Principal-------------\n");
	menu.insertarOpcion("Ingresar expresion Infijo", [&]() { ingresarInfijo(); });
	menu.insertarOpcion("Salir", [&]() { salir(); }); // Para salir del bucle siempre se debe usar esta funcion de salir()
	
	menuEjecutando = true; // Siempre que se quiera correr un menu en bucle
	while (menuEjecutando) {
		menu.correr();
	}
	std::cout << "\nSaliendo...\n" << std::endl;
	system("pause");
}