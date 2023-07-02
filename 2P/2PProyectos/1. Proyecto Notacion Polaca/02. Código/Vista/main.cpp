/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Nombres: Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 27/06/23 17:32
 * Fecha de modificacion: 27/06/23 21:07
 * Enunciado:
 * Proyecto transformacion de expresion infija a notacion polaca y polaca inversa
 *
 *******************************************************************************/
 
#include <iostream>
#include <stdlib.h>
#include <string>
#include "../Herramientas/ControladorMenu.h"
#include "../Controlador/ArbolBinario.cpp"
#include "../Herramientas/Dato.h"
int main() {
	ControladorMenu ctrlMenu;
	ctrlMenu.correrMenu();
	ArbolBinario<int> arbol;
	for(int i = 0; i <10; i++){
		int n = rand() % 40;
		std::cout<<n<< " ";
		arbol.insertarNodo(n);
	}
	std::cout<<std::endl;
	arbol.eliminarNodo(1);
	arbol.mostrarArbol();
	
    return 0;
}




	
