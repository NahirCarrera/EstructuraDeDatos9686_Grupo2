/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Estructura de Datos 9686
 * Nombres: Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 07/07/23 21:42
 * Fecha de modificacion: 19/07/23 12:25
 * Enunciado:
 * Registro de entrada y salida de personas con listas circulares doblemente
 * enlazadas y búsqueda con árboles binarios + Extras
 *
 *******************************************************************************/ 
#include "Dato.h"
#include <iostream>
#include <cstdlib> //funcion atoi()
#include <conio.h> //getch()
#include <cctype>

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       Dato::ingresarMenuOpcion(char limiteInferior, char limiteSuperior)
// Purpose:    Ingresar opcion de menu utilizando limites inferior y superior de las opciones de un menu
// Parameters:
// - limiteInferior
// - limiteSuperior
// Return:     int
////////////////////////////////////////////////////////////////////////////////////////////////////////

int Dato::ingresarMenuOpcion(char limiteInferior, char limiteSuperior) {
	char tecla;
	int opcion = 0;
	bool opcionValida = false;
	
	while (!opcionValida) {
		tecla = getch();
		
		if (tecla == '\r' && opcion > 0) {
			std::cout << std::endl;
			opcionValida = true;
		} else if (tecla == '\b' && opcion > 0) {
			opcion = opcion / 10;
			std::cout << "\b \b";
		} else if (tecla >= limiteInferior && tecla <= limiteSuperior && opcion == 0) {
			opcion = tecla - '0';
			std::cout << tecla;
		}
	}
	
	return opcion;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       Dato::ingresarDimension(char filas, char columnas)
// Purpose:    Ingresar dimensiones válidas para matrices utilizando filas y columnas
// Parameters:
// - filas
// - columnas
// Return:     int
////////////////////////////////////////////////////////////////////////////////////////////////////////

int Dato::ingresarDimension(char filas, char columnas) {
	std::string entrada;
	char tecla;
	int i = 0;
	int dim = 0;

	while (true) {
		tecla = getch(); // lee la tecla ingresada por el usuario sin mostrarla en la consola

		if (tecla == '\r' && entrada.length() > 0) { // si el usuario presiona Enter
			if (i > 0) {
				dim = std::stoi(entrada); // convierte la entrada a un número int
				if (dim >= 2) {
					std::cout << std::endl;
					break; // sale del bucle si la dimensión es válida
				} else {
					std::cout << "La dimension no puede ser menor a 2" << std::endl;
				}
			}
		} else if (tecla == '\b' && i > 0) { // si el usuario presiona Backspace y hay caracteres en la entrada
			i--;
			std::cout << "\b \b"; // borra el último caracter de la consola
			entrada.pop_back(); // elimina el último caracter de la entrada
		} else if (tecla >= filas && tecla <= columnas && i < 1) { // si el usuario ingresa un dígito
			entrada.push_back(tecla); // agrega el caracter a la entrada
			std::cout << tecla; // muestra el caracter ingresado en la consola
			i++;
		}
	}

	return dim; // retorna la dimensión ingresada
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       Dato::ingresarEntero()
// Purpose:    Ingresar numeros enteros válidos de hasta 12 dígitos
// Return:     int
////////////////////////////////////////////////////////////////////////////////////////////////////////

int Dato::ingresarEntero() {
	std::string entrada;
	char tecla;
	int i = 0;

	while (true) {
		tecla = getch(); // lee la tecla ingresada por el usuario sin mostrarla en la consola

		if (tecla == '\r' && entrada.length() > 0) { // si el usuario presiona Enter
			std::cout << std::endl;
			break;
		} else if (tecla == '\b' && i > 0) { // si el usuario presiona Backspace y hay caracteres en la entrada
			i--;
			std::cout << "\b \b"; // borra el último caracter de la consola
			entrada.pop_back(); // elimina el último caracter de la entrada
		} else if (isdigit(tecla) && i < 5) { // si el usuario ingresa un dígito
			entrada.push_back(tecla); // agrega el caracter a la entrada
			std::cout << tecla; // muestra el caracter ingresado en la consola
			i++;
		}
	}

	return std::stoi(entrada); // convierte la entrada a un número int y lo retorna
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       Dato::ingresarFloat()
// Purpose:    Ingresar numeros flotantes válidos de hasta 15 dígitos
// Return:     float
////////////////////////////////////////////////////////////////////////////////////////////////////////

float Dato::ingresarFloat() {
	std::string entrada;
	char tecla;
	int i = 0;
	bool punto = false;
	int signoMenosPos = -1;

	while (true) {
		tecla = getch(); // lee la tecla ingresada por el usuario sin mostrarla en la consola

		if (tecla == '\r' && entrada.length() > 0) { // si el usuario presiona Enter
			if (entrada[0] != '.') {
				std::cout << std::endl;
				break;				
			}			
		} else if (tecla == '\b' && i > 0) { // si el usuario presiona Backspace y hay caracteres en la entrada
			i--;
			std::cout << "\b \b"; // borra el último caracter de la consola
			if (entrada[i] == '.') { // si se eliminó un punto, reinicia el flag de punto
				punto = false;
			}
			if (i == signoMenosPos) { // si se eliminó el signo menos, reinicia la posición del signo menos
				signoMenosPos = -1;
			}
			entrada.pop_back(); // elimina el último caracter de la entrada
		} else if (isdigit(tecla) && i < 15) { // si el usuario ingresa un dígito
			entrada.push_back(tecla); // agrega el caracter a la entrada
			std::cout << tecla; // muestra el caracter ingresado en la consola
			i++;
		} else if (tecla == '.' && !punto) { // si el usuario ingresa un punto y no se ha ingresado ya uno, o si ya se ingresó uno pero se eliminó
			entrada.push_back(tecla); // agrega el caracter a la entrada
			punto = true; // marca que se ha ingresado un punto
			std::cout << tecla;
			i++;
		}
	}		

	return std::stof(entrada); // convierte la entrada a un número float y lo retorna
}

