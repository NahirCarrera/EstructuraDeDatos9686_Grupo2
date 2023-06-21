/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Nombres: Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 14/06/23 18:57
 * Fecha de modificacion: 20/06/23 18:49
 * Enunciado:
 * Registro de entrada y salida de personas con listas circulares doblemente
 * enlazadas y algoritmo de búsqueda por intercambio
 *
 *******************************************************************************/ 

#include "GestorArchivo.h"
#include "../Controlador/ListaCircularDoble.cpp"
#include <iostream>
#include <fstream>
#include <sstream>

GestorArchivo::GestorArchivo() {
}

GestorArchivo::~GestorArchivo() {
}

Fecha GestorArchivo::extraerFecha(std::string input) {
	int anio, mes, dia, hora, minuto, segundo;
	std::stringstream ss(input);
    char dl;

    ss >> anio >> dl >> mes >> dl >> dia
		>> dl >> dl >> dl >> dl >> dl >> dl
		>> hora >> dl >> minuto >> dl >> segundo;
		
	return Fecha(anio, mes, dia, hora, minuto, segundo);
}

// Función para guardar los elementos de una ListaCircularDoble en un archivo CSV
void GestorArchivo::guardarListaPersonaComoCSV(ListaCircularDoble<Persona>& lista,std::string nombreArchivo) {
    std::ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        NodoDoble<Persona>* actual = lista.getCabeza();
        if (actual != nullptr) {
        	archivo << "CEDULA" << ";"
                        << "NOMBRE" << ";"
                        << "APELLIDO" << ";"
						<< "FECHA NACIMIENTO" <<std::endl;
            do {
                archivo << actual->getDato().getCedula() << ";"
                        << actual->getDato().getNombre() << ";"
                        << actual->getDato().getApellido() << ";"
                        << actual->getDato().getFechaNacimiento() << std::endl;
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
void GestorArchivo::cargarCSVEnListaPersona(ListaCircularDoble<Persona>& lista, std::string nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    Fecha fecha;
    if (archivo.is_open()) {
        std::string linea;
        std::getline(archivo, linea);
        while (std::getline(archivo, linea)) {
            std::istringstream ss(linea);
            std::string cedula, nombre, apellido, strFecha;
            std::getline(ss, cedula, ';');
            std::getline(ss, nombre, ';');
            std::getline(ss, apellido, ';');
            std::getline(ss, strFecha, ';');
            fecha = extraerFecha(strFecha);
            Persona persona(cedula, nombre, apellido, fecha);
            lista.insertar(persona);
        }
        archivo.close();
        std::cout << "Archivo cargado correctamente." << std::endl;
    } else {
        std::cerr << "No se pudo abrir el archivo para lectura." << std::endl;
    }
}

void GestorArchivo::guardarListaRegistroComoCSV(ListaCircularDoble<RegistroEntradaSalida>& lista, std::string nombreArchivo){
	std::ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        NodoDoble<RegistroEntradaSalida>* actual = lista.getCabeza();
        if (actual != nullptr) {
        	archivo << "CEDULA" << ";"
                        << "FECHA / HORA ENTRADA" << ";"
                        << "FECHA / HORA SALIDA" << std::endl;
            do {
                archivo << actual->getDato().getPersona().getCedula() << ";"
                        << actual->getDato().getFechaEntrada() << ";"
                        << actual->getDato().getFechaSalida() << std::endl;
                actual = actual->getSiguiente();
            } while (actual != lista.getCabeza());
        }
        archivo.close();
        std::cout << "Archivo guardado correctamente." << std::endl;
    } else {
        std::cerr << "No se pudo abrir el archivo para escritura." << std::endl;
    }
}

void GestorArchivo::cargarCSVEnListaRegistro(ListaCircularDoble<RegistroEntradaSalida>& listaRegistros, ListaCircularDoble<Persona>& listaPersonas, std::string nombreArchivo){
	std::ifstream archivo(nombreArchivo);
	Persona personaRegistro;
    Fecha fechaEntrada;
    Fecha fechaSalida;
    if (archivo.is_open()) {
        std::string linea;
        std::getline(archivo, linea);
        while (std::getline(archivo, linea)) {
            std::istringstream ss(linea);
            std::string cedula, strFechaEntrada, strFechaSalida;
            std::getline(ss, cedula, ';');
            std::getline(ss, strFechaEntrada, ';');
            std::getline(ss, strFechaSalida, ';');
            fechaEntrada = extraerFecha(strFechaEntrada);
            fechaSalida = extraerFecha(strFechaSalida);
            Persona personaEncontrada(cedula, "", "", fechaEntrada);
            personaRegistro = listaPersonas.extraer(personaEncontrada);
            RegistroEntradaSalida registro(personaRegistro, fechaEntrada, fechaSalida);
            listaRegistros.insertar(registro);
        }
        archivo.close();
        std::cout << "Archivo cargado correctamente." << std::endl;
    } else {
        std::cerr << "No se pudo abrir el archivo para lectura." << std::endl;
    }
}