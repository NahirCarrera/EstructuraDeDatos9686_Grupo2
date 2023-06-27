/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Nombres: Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 26/06/23 22:21
 * Fecha de modificacion: 26/06/23 22:21
 * Enunciado:
 * Proyecto transformacion de expresion infija a notacion polaca y polaca inversa
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

int Dato::ingresarMenuOpcion(char limiteInferior, char limiteSuperior){		
	char *entrada = new char[30];
	char tecla;
	int i = 0;
	
	while (true) {
		tecla = getch(); // lee la tecla ingresada por el usuario sin mostrarla en la consola
		
		if (tecla == '\r' && i==1) { // si el usuario presiona Enter
		  std::cout << std::endl;
		  break;
		} else if (tecla == '\b' && i > 0) { // si el usuario presiona Backspace y hay caracteres en la entrada			
			i--;						
			std::cout << "\b \b"; // borra el último caracter de la consola
			entrada[i] = 0; // elimina el último caracter de la entrada
		} else if (tecla >= limiteInferior && tecla <= limiteSuperior && i<1) { // si el usuario ingresa un dígito
			  entrada[i++] = tecla;
			  std::cout << tecla; // muestra el caracter ingresado en la consola
		}
	}

	return atoi(entrada); // convierte la entrada a un número int y lo retorna
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       Dato::ingresarDimension(char filas, char columnas)
// Purpose:    Ingresar dimensiones válidas para matrices utilizando filas y columnas
// Parameters:
// - filas
// - columnas
// Return:     int
////////////////////////////////////////////////////////////////////////////////////////////////////////

int Dato::ingresarDimension(char filas, char columnas){		
	char *entrada = new char[30];
	char tecla;
	int i = 0;
	int dim;
	
	while (true) {
		tecla = getch(); // lee la tecla ingresada por el usuario sin mostrarla en la consola
		
		if (tecla == '\r') { // si el usuario presiona Enter
		  dim = atoi(entrada);
		  if (dim >= 2) {
			std::cout << std::endl;
		  	break;	
		  } else {
		  	std::cout << "La dimension no puede ser menor a 2" << std::endl;
		  }
		  
		} else if (tecla == '\b' && i > 0) { // si el usuario presiona Backspace y hay caracteres en la entrada			
			i--;						
			std::cout << "\b \b"; // borra el último caracter de la consola
			entrada[i] = 0; // elimina el último caracter de la entrada
		} else if (tecla >= filas && tecla <= columnas && i<1) { // si el usuario ingresa un dígito
			  entrada[i++] = tecla;
			  std::cout << tecla; // muestra el caracter ingresado en la consola
		}
	}

	return dim; // convierte la entrada a un número int y lo retorna
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       Dato::ingresarEntero()
// Purpose:    Ingresar numeros enteros válidos de hasta 12 dígitos
// Return:     int
////////////////////////////////////////////////////////////////////////////////////////////////////////

int Dato::ingresarEntero() {		
	char *entrada = new char[30];
	char tecla;
	int i = 0;
	
	while (true) {
		tecla = getch(); // lee la tecla ingresada por el usuario sin mostrarla en la consola
		
		if (tecla == '\r') { // si el usuario presiona Enter
		  std::cout << std::endl;
		  break;
		} else if (tecla == '\b' && i > 0) { // si el usuario presiona Backspace y hay caracteres en la entrada			
			i--;						
			std::cout << "\b \b"; // borra el último caracter de la consola
			entrada[i] = 0; // elimina el último caracter de la entrada
		} else if (isdigit(tecla) && i<12) { // si el usuario ingresa un dígito
			  entrada[i++] = tecla;
			  std::cout << tecla; // muestra el caracter ingresado en la consola
		}
	}

	return atoi(entrada); // convierte la entrada a un número int y lo retorna
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       Dato::ingresarFloat()
// Purpose:    Ingresar numeros flotantes válidos de hasta 15 dígitos
// Return:     float
////////////////////////////////////////////////////////////////////////////////////////////////////////

float Dato::ingresarFloat() {
	char *entrada = new char[30];
	char tecla;
	int i = 0;
	bool punto = false;
	int signoMenosPos = -1;
	while(true){
		tecla = getch(); // lee la tecla ingresada por el usuario sin mostrarla en la consola
		
		if (tecla == '\r') { // si el usuario presiona Enter
		  std::cout << std::endl;
		  break;
		} else if (tecla == '\b' && i > 0) { // si el usuario presiona Backspace y hay caracteres en la entrada			
			i--;						
			std::cout << "\b \b"; // borra el último caracter de la consola
			if (entrada[i] == '.') { // si se eliminó un punto, reinicia el flag de punto
				punto = false;
			}
			if (i == signoMenosPos) { // si se eliminó el signo menos, reinicia la posición del signo menos
				signoMenosPos = -1;
			}
			entrada[i] = 0; // elimina el último caracter de la entrada
		} else if (isdigit(tecla) && i < 15) { // si el usuario ingresa un dígito
			  entrada[i++] = tecla;
			  std::cout << tecla; // muestra el caracter ingresado en la consola
		} else if (tecla == '.' && !punto) { // si el usuario ingresa un punto y no se ha ingresado ya uno, o si ya se ingresó uno pero se eliminó
			  entrada[i++] = tecla;
			  punto = true; // marca que se ha ingresado un punto
			  std::cout << tecla;
		} else if (tecla == '-' && i == 0) { // si el usuario ingresa un signo menos al principio
			  entrada[i++] = tecla;
			  signoMenosPos = i - 1; // marca la posición del signo menos
			  std::cout << tecla;
		}
	}

	return atof(entrada); // convierte la entrada a un número float y lo retorna
  
}

