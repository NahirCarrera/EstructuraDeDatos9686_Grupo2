/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Estructura de Datos 9686
 * Nombres: Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 07/07/23 21:42
 * Fecha de modificacion: 11/07/23 22:39
 * Enunciado:
 * Registro de entrada y salida de personas con listas circulares doblemente
 * enlazadas y búsqueda con árboles binarios + Extras
 *
 *******************************************************************************/
 
#include "../Modelo/Singleton.h"
#include "ControladorMenu.h"
#include "Menu.h"
#include "Dato.h"
#include <string>
#include <cstdlib> // para usar system("cls") y system("pause")

void ControladorMenu::insertarMatriz() {
	std::cout << "Insertar Matriz" <<std::endl;
	system("pause");
}

void ControladorMenu::multiplicarMatrices() {
	std::cout << "Multiplicar Matrices" <<std::endl;
	system("pause");
}

void ControladorMenu::limpiarMatrices() {
	std::cout << "Limpiar Matrices" <<std::endl;
	system("pause");
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
// Name:       ControladorMenu::correrMenu()
// Purpose:    Desplegar las opciones del menu principal
// Return:     void
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ControladorMenu::correrMenu() {
	Singleton* singleton = Singleton::getInstance();
	
	Menu menu("(O)===)> <><><><><><><><>< Menu Principal ><><><><><><><><> <)==(O)");
	menu.insertarOpcion("       ( )===== Insertar Matriz          ====( )      ", [&]() { insertarMatriz(); });
	menu.insertarOpcion("       ( )===== Multiplicar Matrices     ====( )      ", [&]() { multiplicarMatrices(); });
	menu.insertarOpcion("       ( )===== Limpiar Matrices         ====( )      ", [&]() { limpiarMatrices(); });
	menu.insertarOpcion("       ( )===== Salir                    ====( )      ", [&]() { salir(); }); // Para salir del bucle siempre se debe usar esta funcion de salir()
	
	menuEjecutando = true; // Siempre que se quiera correr un menu en bucle
	while (menuEjecutando) {
		menu.correr();
	}
	std::cout << "\n(O)===)> <><><><><><><><>< Saliendo, muchas gracias por usar el programa ><><><><><><><><> <)==(O)" << std::endl;
	std::cout << "(O)===)> Att: Nahir & Stephen" << std::endl;
	system("pause");
}