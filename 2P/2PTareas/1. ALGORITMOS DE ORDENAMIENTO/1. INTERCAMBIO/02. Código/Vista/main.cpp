/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Nombres: Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 14/06/23 18:57
 * Fecha de modificacion: 14/06/23 22:40
 * Enunciado:
 * Registro de entrada y salida de personas con listas circulares doblemente
 * enlazadas y algoritmo de búsqueda por intercambio
 *
 *******************************************************************************/ 
 
#include <iostream>
#include <cstdlib> // para usar system("cls") y system("pause")
#include <string>
#include "../Controlador/ListaCircularDoble.cpp"
#include "../Modelo/RegistroEntradaSalida.h"
#include "../Modelo/Fecha.h"
#include "../Modelo/Persona.h"
#include <stdlib.h>

int main() {
	Persona persona("1726952946", "Stephen", "Drouet");
	Fecha fechaEntrada;
	Fecha fechaSalida(2023, 6, 14, 23, 59, 11);
	RegistroEntradaSalida registro1(persona, fechaEntrada, fechaSalida);
	
	Persona persona2("1710708973", "Nahir", "Carrera");
	Fecha fechaEntrada2(2023, 6, 14, 8, 0, 15);;
	Fecha fechaSalida2(2023, 6, 14, 14, 30, 12);
	RegistroEntradaSalida registro2(persona2, fechaEntrada2, fechaSalida2);
	
	ListaCircularDoble<RegistroEntradaSalida> listaRegistro;
	/*
	ListaCircularDoble<int> lista;
	
	lista.insertar(5);
	lista.insertar(7);
	lista.insertar(3);
	lista.mostrar();*/
	
	listaRegistro.insertar(registro1);
	listaRegistro.insertar(registro2);
	listaRegistro.mostrar();
   	system("PAUSE");
    return 0;
}

