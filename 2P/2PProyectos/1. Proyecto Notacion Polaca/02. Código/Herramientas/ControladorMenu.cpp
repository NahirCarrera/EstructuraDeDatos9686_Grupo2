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
// Name:       ControladorMenu::operarPosfijo(CalculadoraPolaca calculadora)
// Purpose:    Muestra la expresion
// Parameters:
// - calculadora
// Return:     void
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ControladorMenu::operarPostfijo(CalculadoraPolaca calculadora) {
	std::cout << "Expresion Infijo: " << std::endl;
	std::cout << calculadora.getExpresionInfijo() << std::endl;
	std::cout << "Expresion Posfijo: " << std::endl;
	std::cout << calculadora.getExpresionPostfijo() << std::endl;
	std::cout << "\nResultado: " << calculadora.evaluarExpresionPostfija() << std::endl;
	system("pause");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ControladorMenu::operarPrefijo(CalculadoraPolaca calculadora)
// Purpose:    Muestra los valores de la notacio prefijo
// - calculadora
// Return:     void
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ControladorMenu::operarPrefijo(CalculadoraPolaca calculadora) {
	std::cout << "Expresion Infijo: " << std::endl;
	std::cout << calculadora.getExpresionInfijo() << std::endl;
	std::cout << "Expresion Prefijo: " << std::endl;
	std::cout << calculadora.getExpresionPrefijo() << std::endl;
	std::cout << "\nResultado: " << calculadora.evaluarExpresionPrefija() << std::endl;
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
	infijo = Dato::ingresarExpresion();
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
	CalculadoraPolaca calculadora(infijo);	
	
	std::string titulo = "\n-----------Menu Operaciones-------------\nExpresion infijo:\n" +  calculadora.getExpresionInfijo() + "\n\n";
	
	Menu menu(titulo);
	menu.insertarOpcion("Mostrar notacion Polaca (prefija)", [&]() { operarPrefijo(calculadora); });
	menu.insertarOpcion("Mostrar notacion Polaca Inversa (postfija)", [&]() { operarPostfijo(calculadora); });
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