/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Nombres: Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 14/06/23 18:57
 * Fecha de modificacion: 14/06/23 19:12
 * Enunciado:
 * Registro de entrada y salida de personas con listas circulares doblemente
 * enlazadas y algoritmo de búsqueda burbuja mejorado
 *
 *******************************************************************************/ 
#include <iostream>
#include <cstdlib> // para usar system("cls") y system("pause")
#include <string>
#include "ListaCircularDoble.cpp"
#include <stdlib.h>

int main() {
	ListaCircularDoble<int> lista;
	
	lista.insertar(5);
	lista.insertar(7);
	lista.insertar(3);
	lista.mostrar();
   	system("PAUSE");
    return 0;
}

