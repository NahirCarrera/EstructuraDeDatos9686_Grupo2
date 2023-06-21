/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Nombres: Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 14/06/23 18:57
 * Fecha de modificacion: 19/06/23 23:33
 * Enunciado:
 * Registro de entrada y salida de personas con listas circulares doblemente
 * enlazadas y algoritmo de búsqueda por intercambio
 *
 *******************************************************************************/ 

#ifndef MENU_H
#define MENU_H

#include "../Modelo/ListaCircularDoble.h"
#include "../Modelo/NodoDoble.h"
#include <string>
#include <windows.h>
#include <iostream>
#include <conio.h>

class Menu
{
	private:
    ListaCircularDoble<std::string> options;
    NodoDoble<std::string>* selectedOption;

	public:
    // Constructor
    
    Menu(ListaCircularDoble<std::string> opts) : options(opts) {
        selectedOption = options.getCabeza();
    }

    // Mostrar el menú en la pantalla
    void displayMenu() {
        system("cls"); // Limpiar la pantalla (Windows)

        NodoDoble<std::string>* node = options.getCabeza();
        do {
            if (node == selectedOption) {
                std::cout << "> ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Cambiar el color de fondo a blanco intenso
                std::cout << node->getDato() << std::endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED); // Restaurar el color original del texto
            } else {
                std::cout << "  " << node->getDato() << std::endl;
            }
            node = node->getSiguiente();
        } while (node != options.getCabeza());
    }

    // Mover hacia arriba en el menú
    void moveUp() {
        selectedOption = selectedOption->getAnterior();
    }

    // Mover hacia abajo en el menú
    void moveDown() {
        selectedOption = selectedOption->getSiguiente();
    }

    // Obtener la opción seleccionada
    std::string getSelectedOption() {
        return selectedOption->getDato();
    }
    
    
    static std::string correrMenu() {
		// Crear el menú con las opciones deseadas
	    ListaCircularDoble<std::string> options;
	    options.insertar("Registrar Empleado");
	    options.insertar("Registrar Entrada/Salida");
	    options.insertar("Mostrar Registro ordenado por fecha de entrada");
	    options.insertar("Mostrar Registro ordenado por fecha de salida");
	    options.insertar("Mostrar Registro individual");
	    options.insertar("Mostrar Empleados ordenado por nombre");
	    options.insertar("Mostrar Empleados ordenado por apellido");
	    options.insertar("Salir");
	    Menu menu(options);
	
	    int choice;
	    bool quit = false;
	
	    do {
	        menu.displayMenu();
	        std::cout << "\nSeleccione una opcion con las teclas de flecha y presione Enter." << std::endl;
	
	        // Leer la tecla presionada sin esperar por Enter (utilizando conio.h en Windows)
	        choice = _getch();
	
	        switch (choice) {
	            case 72: // Tecla de flecha arriba
	                menu.moveUp();
	                break;
	            case 80: // Tecla de flecha abajo
	                menu.moveDown();
	                break;
	            case 13: // Tecla Enter
	                quit = true;
	                break;
	        }
	    } while (!quit);
	
	    return menu.getSelectedOption();
	}
};

#endif