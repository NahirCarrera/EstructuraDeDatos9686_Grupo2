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
#include <string>
#include <cstdlib> // para usar system("cls") y system("pause")
#include <random>
#include <chrono>


void ControladorMenu::ingresarMatrices() {
	std::cout << "(O)===)> Ingrese la cantidad de matrices para multiplicar secuencialmente: ";
	cantidadMatrices = Dato::ingresarEntero();
	std::cout << "(O)===)> NOTA: Las matrices seran generadas con dimensiones y numeros aleatorios" <<std::endl;
	this->generarMatricesAleatorias();
	system("pause");
}

void ControladorMenu::generarMatricesAleatorias(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::string secuencia = "";
    int minDimension = 2;
    int maxDimension = 8;
    int filas = std::rand() % (maxDimension) + minDimension; // Generar número aleatorio entre 1 y 8 para las filas
    int columnas = std::rand() % (maxDimension) + minDimension; // Generar número aleatorio entre 1 y 8 para las columnas
    Matriz matriz;

	matrices = ListaSimple<Matriz>();
	for (int i = 0; i < cantidadMatrices; i++) {
        matriz = Matriz(filas, columnas);
        matriz.generarAleatorios();
        matrices.insertarAlFinal(matriz);
        std::cout << "Matriz: " << i + 1 <<" de (" << filas <<" x "<<columnas << ")" << std::endl;
        std::cout << matriz << std::endl;
        secuencia += "(" + std::to_string(filas) + " x " + std::to_string(columnas) + ")";
        // Actualizar dimensiones para la siguiente matriz
        filas = columnas;
        columnas = std::rand() % maxDimension + minDimension; // Generar nuevo número aleatorio para las columnas
    }
    std::cout<<"Matrices a multiplicar: " << secuencia << std::endl;
}

void ControladorMenu::multiplicarMatrices() {
	std::cout << "Multiplicar Matrices" <<std::endl;
	Matriz resultado;
	
	std::string expresion = "((M0*M1)*(M2*(M3*M4)))";
	std::cout << expresion <<std::endl;
	auto start = std::chrono::high_resolution_clock::now();
	CalculadoraPolaca calc(expresion);
	std::cout << "El resultado polaca es:\n" << calc.evaluarExpresionPostfija(matrices) << std::endl;
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration = end - start;
	double tiempoTranscurrido = duration.count() * 1000.0; // Convertir a milisegundos
    std::cout << "Tiempo transcurrido: " << tiempoTranscurrido << " ms" << std::endl;
    
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	
	for(int i = 0; i < matrices.obtenerTamanio(); i++) {
		std::cout << matrices[i].formatearMatriz() << "*";
	}
	std::cout << std::endl;
	start = std::chrono::high_resolution_clock::now();
	for(int i = 0; i < matrices.obtenerTamanio(); i++) {
		if (i == 0) {
			resultado = matrices[i];
		} else {
			resultado = resultado * matrices[i];
		}
	}
	std::cout << "El resultado es:\n" << resultado << std::endl;
	end = std::chrono::high_resolution_clock::now();
	duration = end - start;
	tiempoTranscurrido = duration.count() * 1000.0; // Convertir a milisegundos
    std::cout << "Tiempo transcurrido: " << tiempoTranscurrido << " ms" << std::endl;
    
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
	menu.insertarOpcion("       ( )===== Ingresar Matrices        ====( )      ", [&]() { ingresarMatrices(); });
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