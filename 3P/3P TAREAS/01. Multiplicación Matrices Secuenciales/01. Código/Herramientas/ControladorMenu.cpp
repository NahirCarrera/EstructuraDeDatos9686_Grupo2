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
    int minDimension = 1;
    int maxDimension = 8;
    int filas = std::rand() % (maxDimension) + minDimension; // Generar número aleatorio entre 1 y 8 para las filas
    int columnas = std::rand() % (maxDimension) + minDimension; // Generar número aleatorio entre 1 y 8 para las columnas
    
	for (int i = 0; i < cantidadMatrices; i++) {
        Matriz matriz(filas, columnas);
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