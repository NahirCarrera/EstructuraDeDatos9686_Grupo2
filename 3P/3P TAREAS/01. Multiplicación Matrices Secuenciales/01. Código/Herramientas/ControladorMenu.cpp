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
#include "Menu.h"
#include "Dato.h"
#include "../Modelo/Singleton.h"
#include "../Modelo/MatrizControlador.h"
#include <string>
#include <cstdlib> // para usar system("cls") y system("pause")
#include <random>
#include <chrono>


void ControladorMenu::ingresarMatrices() {
	int dimMax, dimMin;
	std::cout << "(O)===)> Ingrese la cantidad de matrices para multiplicar secuencialmente: ";
	cantidadMatrices = Dato::ingresarEntero();
	std::cout << "(O)===)> Ingrese la dimension minima de las matrices: ";
	dimMin = Dato::ingresarEntero();
	do {
		std::cout << "(O)===)> Ingrese la dimension maxima de las matrices: ";
		dimMax = Dato::ingresarEntero();
		if (dimMax < dimMin) {
			std::cout << "La dimension Maxima debe ser mayor a la minima" << std::endl;	
		}
	} while (dimMax < dimMin);
	
	std::cout << "\n(O)===)> NOTA: Las matrices seran generadas con dimensiones y numeros aleatorios\n" <<std::endl;
	MatrizControlador controlador(cantidadMatrices);
	controlador.mostrarAsociacionOptima(dimMin, dimMax);
	matrices = controlador.getMatrices();
	expresion = controlador.getAsociacionOptima();
	system("pause");
}



void ControladorMenu::multiplicarMatrices() {
	std::cout << "Multiplicar Matrices" <<std::endl;
	Matriz resultado;
	
	std::cout << "Expresion para ingresar en Wolfram: " <<std::endl;
	for(int i = 0; i < matrices.obtenerTamanio(); i++) {
		std::cout << matrices[i].formatearMatriz() << "*";
	}
	std::cout << "\b \b";
	
	std::cout << "\n\nExpresion orden de multiplicacion: " <<std::endl;
	std::cout << expresion <<std::endl;
	CalculadoraPolaca calc(expresion);
	auto start = std::chrono::high_resolution_clock::now();
	resultado = calc.evaluarExpresionPostfija(matrices);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration = end - start;
	double tiempoTranscurrido = duration.count() * 1000.0; // Convertir a milisegundos
	std::cout << "\nEl resultado es:\n" << resultado << std::endl;
    std::cout << "Tiempo transcurrido: " << tiempoTranscurrido << " ms" << std::endl;

    
	system("pause");
}

void ControladorMenu::verOptimizacion() {
	std::cout << "Tiempo al multiplicar las matrices" <<std::endl;
	Matriz resultado;
	
	std::cout << expresion <<std::endl;
	auto start = std::chrono::high_resolution_clock::now();
	CalculadoraPolaca calc(expresion);
	calc.evaluarExpresionPostfija(matrices);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration = end - start;
	double tiempoTranscurrido = duration.count() * 1000.0; // Convertir a milisegundos
	std::cout << "\nMULTIPLICACION EN ORDEN OPTIMIZADO" <<std::endl;
    std::cout << "Tiempo transcurrido: " << tiempoTranscurrido << " ms" << std::endl;
    
	std::cout << std::endl;
	start = std::chrono::high_resolution_clock::now();
	for(int i = 0; i < matrices.obtenerTamanio(); i++) {
		if (i == 0) {
			resultado = matrices[i];
		} else {
			resultado = resultado * matrices[i];
		}
	}
	end = std::chrono::high_resolution_clock::now();
	duration = end - start;
	tiempoTranscurrido = duration.count() * 1000.0; // Convertir a milisegundos
	std::cout << "\nMULTIPLICACION EN ORDEN SIN OPTIMIZAR" <<std::endl;
    std::cout << "Tiempo transcurrido: " << tiempoTranscurrido << " ms" << std::endl;
    
	system("pause");
}

void ControladorMenu::mostrarMatrices() {
	std::cout << "MATRICES ALMACENADAS\n" <<std::endl;
	for(int i = 0; i < matrices.obtenerTamanio(); i++) {
	    std::cout << "Matriz: " << i <<" de (" << matrices[i].obtenerFilas() <<" x "<< matrices[i].obtenerColumnas() << ")" << std::endl;
        std::cout << matrices[i] << std::endl;
	}
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
	menu.insertarOpcion("       ( )===== Ingresar Matrices        ====( )      ", [&]() { ingresarMatrices(); });
	menu.insertarOpcion("       ( )===== Ver Resultado            ====( )      ", [&]() { multiplicarMatrices(); });
	menu.insertarOpcion("       ( )===== Ver Optimizacion         ====( )      ", [&]() { verOptimizacion(); });
	menu.insertarOpcion("       ( )===== Mostrar Matrices         ====( )      ", [&]() { mostrarMatrices(); });
	menu.insertarOpcion("       ( )===== Salir                    ====( )      ", [&]() { salir(); }); // Para salir del bucle siempre se debe usar esta funcion de salir()
	
	menuEjecutando = true; // Siempre que se quiera correr un menu en bucle
	while (menuEjecutando) {
		menu.correr();
	}
	std::cout << "\n(O)===)> <><><><><><><><>< Saliendo, muchas gracias por usar el programa ><><><><><><><><> <)==(O)" << std::endl;
	std::cout << "(O)===)> Att: Nahir & Stephen" << std::endl;
	system("pause");
}