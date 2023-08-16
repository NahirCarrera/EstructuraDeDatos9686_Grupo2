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
 
#include "ControladorMenu.h"
#include "../Modelo/Juego.h"
#include "Menu.h"
#include <string>
#include <cstdlib> // para usar system("cls") y system("pause")
#include <iostream>
void ControladorMenu::opcion1() {
	int intervaloActualizacion = 500; // 500 milisegundos
	Juego juego;
    juego.ejecutar(1,intervaloActualizacion);
}

void ControladorMenu::opcion2() {
	int intervaloActualizacion = 200; // 500 milisegundos
	Juego juego;
    juego.ejecutar(2,intervaloActualizacion);
}

void ControladorMenu::opcion3() {
	int intervaloActualizacion = 50; // 500 milisegundos
	Juego juego;
    juego.ejecutar(3,intervaloActualizacion);
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
	std::string tituloMenu;
	tituloMenu += "|---------------------------------------------------------|\n";
	tituloMenu += "| ||MMMMMMM ||MMMMM ||MMMMMMM   ||MMMMMM   ||M   ||MMMMM  |\n";
	tituloMenu += "|    ||M    ||M        ||M      ||M   ||M  ||M  ||M       |\n";
	tituloMenu += "|    ||M    ||MMM      ||M      ||MMMMMM   ||M   ||MMMM   |\n";
	tituloMenu += "|    ||M    ||M        ||M      ||M   ||M  ||M       ||M  |\n";
	tituloMenu += "|    ||M    ||MMMMM    ||M      ||M   ||M  ||M   ||MMMM   |\n";
    tituloMenu += "|---------------------------------------------------------|\n";
	Menu menu(tituloMenu);
	menu.insertarOpcion(" ( )=====       NIVEL 1       ====( )      ", [&]() { opcion1(); });
	menu.insertarOpcion(" ( )=====       NIVEL 2       ====( )      ", [&]() { opcion2(); });
	menu.insertarOpcion(" ( )=====       NIVEL 3       ====( )      ", [&]() { opcion3(); });
	menu.insertarOpcion(" ( )=====       SALIR         ====( )      ", [&]() { salir(); }); // Para salir del bucle siempre se debe usar esta funcion de salir()
	
	menuEjecutando = true; // Siempre que se quiera correr un menu en bucle
	while (menuEjecutando) {
		menu.correr();
	}
	std::cout << "\n(O)===)> <><><><><><><><>< Saliendo, muchas gracias por usar el programa ><><><><><><><><> <)==(O)" << std::endl;
	std::cout << "(O)===)> Att: Nahir & Stephen" << std::endl;
	system("pause");
}