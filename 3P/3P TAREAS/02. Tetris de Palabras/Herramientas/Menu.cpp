/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Estructura de Datos 9686
 * Nombres: Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 12/08/23 19:40
 * Fecha de modificacion: 12/08/23 19:40
 * Enunciado:
 * Realizar el juego del tetris con palabras en consola (Solo caida horizontal)
 * EXTRA: Realizar la rotación de las piezas
 *******************************************************************************/
 
#include "ListaCircularDoble.cpp"
#include "Opcion.h"
#include "Menu.h"
#include <string>
#include <windows.h>
#include <iostream>
#include <conio.h>

////////////////////////////////////////////////////////////////////////////
// Name:       Menu::Menu()
// Purpose:    Implementation of Menu::Menu()
// Parameters:
// Return:     
////////////////////////////////////////////////////////////////////////////

Menu::Menu(std::string titulo){
	this->titulo = titulo;
	this->opciones = ListaCircularDoble<Opcion>();
    this->opcionSeleccionada = opciones.getCabeza();
}

////////////////////////////////////////////////////////////////////////////
// Name:       Menu::setTitulo(std::string newTitulo)
// Purpose:    Implementation of Menu::setTitulo(std::string newTitulo)
// Parameters:
// - newTitulo
// Return:     
////////////////////////////////////////////////////////////////////////////

void Menu::setTitulo(std::string newTitulo) {
	titulo = newTitulo;
}

////////////////////////////////////////////////////////////////////////////
// Name:       Menu::desplegarMenu()
// Purpose:    Mostrar el menú en la pantalla
// Return:     void
////////////////////////////////////////////////////////////////////////////

void Menu::desplegarMenu() {
    system("cls"); // Limpiar la pantalla (Windows)
    std::cout << titulo << std::endl;
    NodoDoble<Opcion>* nodo = opciones.getCabeza();
    do {
        if (nodo == opcionSeleccionada) {
            std::cout << "==)>     ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Cambiar el color de fondo a blanco intenso
            std::cout << nodo->getDato() << std::endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED); // Restaurar el color original del texto
        } else {
            std::cout << "         " << nodo->getDato() << std::endl;
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

Opcion Menu::getOpcionSeleccionada() {
    return opcionSeleccionada->getDato();
}

////////////////////////////////////////////////////////////////////////////////////////
// Name:       Menu::correr()
// Purpose:    Crear el menu con las opciones deseadas, permite moverse por el y ejecuta la opcion seleccionada
// Return:    void
////////////////////////////////////////////////////////////////////////////////////////

void Menu::correr(){
    int eleccion;
    bool final = false;

    do {
        desplegarMenu();
        std::cout << "\nSeleccione una opcion con las teclas de flecha y presione Enter." << std::endl;

        // Leer la tecla presionada sin esperar por Enter (utilizando conio.h en Windows)
        eleccion = _getch();

        switch (eleccion) {
            case 72: // Tecla de flecha arriba
                moverArriba();
                break;
            case 80: // Tecla de flecha abajo
                moverAbajo();
                break;
            case 13: // Tecla Enter
                final = true;
                break;
        }
    } while (!final);
    
    getOpcionSeleccionada().ejecutar();
}

////////////////////////////////////////////////////////////////////////////////////////
// Name:       Menu::insertarOpcion()
// Purpose:    inserta una nueva opcion al menu con su texto y funcion a realizar
// Parameters:
// - texto
// - funcion
// Return:     
////////////////////////////////////////////////////////////////////////////////////////

void Menu::insertarOpcion(std::string texto, const std::function<void()>& funcion) {
	Opcion opcion(texto, funcion);
	opciones.insertar(opcion);
	opcionSeleccionada = opciones.getCabeza();
}
