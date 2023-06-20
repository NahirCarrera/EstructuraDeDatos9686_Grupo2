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
 
/*#include <iostream>
#include <cstdlib> // para usar system("cls") y system("pause")
#include <string>
#include "../Controlador/ListaCircularDoble.cpp"
#include "../Modelo/RegistroEntradaSalida.h"
#include "../Modelo/Fecha.h"
#include "../Modelo/Persona.h"
#include "../Herramientas/Menu.h"

void registrarEmpleado();
void registrarEntradaSalida();
void mostrarRegistroCompleto();
void mostrarRegistroIndividual();

int main() {
	std::string opcion;
	
	do {
		opcion = Menu::correrMenu();
		
		system("cls");
		
		if (opcion == "Registrar Empleado") {
			registrarEmpleado();
		}
	
		if (opcion == "Registrar Entrada/Salida") {
			registrarEntradaSalida();
		}
		
		if (opcion == "Mostrar Registro completo") {
			mostrarRegistroCompleto();
		}
		
		if (opcion == "Mostrar Registro individual") {
			mostrarRegistroIndividual();
		}
		
		if (opcion == "Salir") {
			std::cout << "Saliendo..." << std::endl;
		}	
		system("PAUSE");	
	} while (opcion != "Salir");
	
    return 0;
}


void registrarEmpleado() {
	std::cout << "registrando empleado" << std::endl;
}

void registrarEntradaSalida() {
	std::cout << "registrando entrada o salida" << std::endl;
}

void mostrarRegistroCompleto() {
	std::cout << "registro completo" << std::endl;
}

void mostrarRegistroIndividual() {
	std::cout << "registro individual" << std::endl;
}*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "../Controlador/ListaCircularDoble.cpp"
#include "../Modelo/Persona.h"

// Función para guardar los elementos de una ListaCircularDoble en un archivo CSV
template <typename T>
void guardarListaComoCSV(ListaCircularDoble<T>& lista, const std::string& nombreArchivo) {
    std::ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        NodoDoble<T>* actual = lista.getCabeza();
        if (actual != nullptr) {
        	archivo << "CEDULA" << ";"
                        << "NOMBRE" << ";"
                        << "APELLIDO" << std::endl;
            do {
                archivo << actual->getDato().getCedula() << ";"
                        << actual->getDato().getNombre() << ";"
                        << actual->getDato().getApellido() << std::endl;
                actual = actual->getSiguiente();
            } while (actual != lista.getCabeza());
        }
        archivo.close();
        std::cout << "Archivo guardado correctamente." << std::endl;
    } else {
        std::cerr << "No se pudo abrir el archivo para escritura." << std::endl;
    }
}

// Función para cargar los elementos de un archivo CSV en una ListaCircularDoble
template <typename T>
void cargarCSVEnLista(ListaCircularDoble<T>& lista, const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    Fecha fecha;
    if (archivo.is_open()) {
        std::string linea;
        std::getline(archivo, linea);
        while (std::getline(archivo, linea)) {
            std::istringstream ss(linea);
            std::string cedula, nombre, apellido;
            std::getline(ss, cedula, ';');
            std::getline(ss, nombre, ';');
            std::getline(ss, apellido, ';');
            T dato(cedula, nombre, apellido, fecha);
            lista.insertar(dato);
        }
        archivo.close();
        std::cout << "Archivo cargado correctamente." << std::endl;
    } else {
        std::cerr << "No se pudo abrir el archivo para lectura." << std::endl;
    }
}

int main() {
    ListaCircularDoble<Persona> lista;
	cargarCSVEnLista(lista, "personas.csv");
    bool continuar = true;
    do {
        // Obtener datos para una persona
        std::string cedula, nombre, apellido;
        std::cout << "Ingrese la cedula: ";
        std::cin >> cedula;
        std::cout << "Ingrese el nombre: ";
        std::cin >> nombre;
        std::cout << "Ingrese el apellido: ";
        std::cin >> apellido;
		Fecha fecha;
        // Crear una persona con los datos ingresados
        Persona persona(cedula, nombre, apellido, fecha);

        // Insertar la persona en la lista
        lista.insertar(persona);

        std::cout << "¿Desea agregar otra persona? (S/N): ";
        char opcion;
        std::cin >> opcion;
        if (opcion == 'N' || opcion == 'n') {
            continuar = false;
        }
    } while (continuar);

    // Guardar la lista en un archivo CSV
    guardarListaComoCSV(lista, "personas.csv");

    // Mostrar los elementos cargados desde el archivo
    lista.mostrar();

    return 0;
}
