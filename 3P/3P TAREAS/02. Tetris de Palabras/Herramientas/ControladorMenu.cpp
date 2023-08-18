/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Estructura de Datos 9686
 * Nombres: Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 12/08/23 19:40
 * Fecha de modificacion: 12/08/23 19:40
 * Enunciado:
 * Realizar el juego del tetris con palabras en consola (Solo caida horizontal)
 * EXTRA: Realizar la rotación de las piezas
 *******************************************************************************/
 
#include "ControladorMenu.h"
#include "../Modelo/Juego.h"
#include "Menu.h"
#include <string>
#include <cstdlib> // para usar system("cls") y system("pause")
#include <iostream>

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ControladorMenu::opcion1()
// Purpose:    Ejecuta el juego Tetris con un nivel y un intervalo de actualización predefinidos.
// Parameters: Ninguno.
// Remarks:    Crea una instancia de la clase Juego y llama al método ejecutar con el nivel 1 y el
//             intervalo de actualización de 500 milisegundos.
// Returns:    void
////////////////////////////////////////////////////////////////////////////////////////////////////////

void ControladorMenu::opcion1() {
	int intervaloActualizacion = 500; // 500 milisegundos
	Juego juego;
    juego.ejecutar(1,intervaloActualizacion);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ControladorMenu::opcion2()
// Purpose:    Ejecuta el juego Tetris con un nivel y un intervalo de actualización predefinidos.
// Parameters: Ninguno.
// Remarks:    Crea una instancia de la clase Juego y llama al método ejecutar con el nivel 2 y el
//             intervalo de actualización de 200 milisegundos.
// Returns:    void
////////////////////////////////////////////////////////////////////////////////////////////////////////

void ControladorMenu::opcion2() {
	int intervaloActualizacion = 200; // 500 milisegundos
	Juego juego;
    juego.ejecutar(2,intervaloActualizacion);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ControladorMenu::opcion3()
// Purpose:    Ejecuta el juego Tetris con un nivel y un intervalo de actualización predefinidos.
// Parameters: Ninguno.
// Remarks:    Crea una instancia de la clase Juego y llama al método ejecutar con el nivel 3 y el
//             intervalo de actualización de 50 milisegundos.
// Returns:    void
////////////////////////////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ControladorMenu::correrMenu()
// Purpose:    Ejecuta un menú de opciones para el juego Tetris con diferentes niveles.
// Parameters: Ninguno.
// Remarks:    Crea una instancia de la clase Menu y agrega opciones al menú, cada una con su función
//             de acción correspondiente. Luego, ejecuta el menú en un bucle mientras la variable
//             menuEjecutando sea verdadera. Al seleccionar la opción de salir, cambia el valor de
//             menuEjecutando a falso para salir del bucle. Finaliza imprimiendo un mensaje de salida.
// Returns:    void
////////////////////////////////////////////////////////////////////////////////////////////////////////

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