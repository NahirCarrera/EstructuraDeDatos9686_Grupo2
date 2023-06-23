/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Nombres: Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 14/06/23 18:57
 * Fecha de modificacion: 22/06/23 22:15
 * Enunciado:
 * Registro de entrada y salida de personas con listas circulares doblemente
 * enlazadas y algoritmo de búsqueda por intercambio
 *
 *******************************************************************************/ 
 
#include "../Controlador/ListaCircularDoble.cpp"
#include "../Controlador/NodoDoble.cpp"
#include "Menu.h"
#include <string>
#include <windows.h>
#include <iostream>
#include <conio.h>

////////////////////////////////////////////////////////////////////////////
// Name:       Menu(ListaCircularDoble<std::string> opts)
// Purpose:    Implementation of Menu(ListaCircularDoble<std::string> opts)
// Parameters:
// - opts
// Return:     
////////////////////////////////////////////////////////////////////////////

Menu::Menu(ListaCircularDoble<std::string> opts){
	this->opciones = opts;
    this->opcionSeleccionada = opciones.getCabeza();
}

////////////////////////////////////////////////////////////////////////////
// Name:       Menu::desplegarMenu()
// Purpose:    Mostrar el menú en la pantalla
// Return:     void
////////////////////////////////////////////////////////////////////////////

void Menu::desplegarMenu() {
    system("cls"); // Limpiar la pantalla (Windows)

    NodoDoble<std::string>* nodo = opciones.getCabeza();
    do {
        if (nodo == opcionSeleccionada) {
            std::cout << "> ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Cambiar el color de fondo a blanco intenso
            std::cout << nodo->getDato() << std::endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED); // Restaurar el color original del texto
        } else {
            std::cout << "  " << nodo->getDato() << std::endl;
        }
        nodo = nodo->getSiguiente();
    } while (nodo != opciones.getCabeza());
}

////////////////////////////////////////////////////////////////////////////
// Name:       Menu::moverArriba()
// Purpose:    Mover hacia arriba el menú
// Return:     void
////////////////////////////////////////////////////////////////////////////

void Menu::moverArriba() {
    opcionSeleccionada = opcionSeleccionada->getAnterior();
}

////////////////////////////////////////////////////////////////////////////
// Name:       Menu::moverAbajo()
// Purpose:    Mover hacia abajo el menú
// Return:     void
////////////////////////////////////////////////////////////////////////////

void Menu::moverAbajo() {
    opcionSeleccionada = opcionSeleccionada->getSiguiente();
}

////////////////////////////////////////////////////////////////////////////
// Name:       Menu::getOpcionSeleccionada()
// Purpose:    Obtener la opción seleccionada
// Return:     std::string
////////////////////////////////////////////////////////////////////////////

std::string Menu::getOpcionSeleccionada() {
    return opcionSeleccionada->getDato();
}

////////////////////////////////////////////////////////////////////////////////////////
// Name:       Menu::crearMenu()
// Purpose:    Crear el menú con las opciones deseadas y obtener la opcion seleccionada
// Return:     std::string
////////////////////////////////////////////////////////////////////////////////////////

std::string Menu::crearMenu(){
    ListaCircularDoble<std::string> opciones;
    opciones.insertar("Registrar Empleado                            ");
    opciones.insertar("Registrar Entrada/Salida                      ");
    opciones.insertar("Mostrar Registro ordenado por fecha de entrada");
    opciones.insertar("Mostrar Registro ordenado por fecha de salida ");
    opciones.insertar("Mostrar Registro individual                   ");
    opciones.insertar("Mostrar Empleados ordenado por nombre         ");
    opciones.insertar("Mostrar Empleados ordenado por apellido       ");
    opciones.insertar("Salir                                         ");
    Menu menu(opciones);

    int eleccion;
    bool final = false;

    do {
        menu.desplegarMenu();
        std::cout << "\nSeleccione una opcion con las teclas de flecha y presione Enter." << std::endl;

        // Leer la tecla presionada sin esperar por Enter (utilizando conio.h en Windows)
        eleccion = _getch();

        switch (eleccion) {
            case 72: // Tecla de flecha arriba
                menu.moverArriba();
                break;
            case 80: // Tecla de flecha abajo
                menu.moverAbajo();
                break;
            case 13: // Tecla Enter
                final = true;
                break;
        }
    } while (!final);

    return menu.getOpcionSeleccionada();
}