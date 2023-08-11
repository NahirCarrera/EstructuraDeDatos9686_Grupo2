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
 
#include "../Herramientas/ControladorMenu.h"
#include <iostream>
#include <ctime>    // Para la semilla aleatoria
int main() {
	srand(time(NULL)); // Inicializar la semilla con el tiempo actual
	ControladorMenu ctrlMenu;
	ctrlMenu.correrMenu();
	return 0;
}