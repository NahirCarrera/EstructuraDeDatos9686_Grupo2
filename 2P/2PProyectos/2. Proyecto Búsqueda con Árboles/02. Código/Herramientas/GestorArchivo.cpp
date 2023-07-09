/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Estructura de Datos 9686
 * Nombres: Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 07/07/23 21:42
 * Fecha de modificacion: 07/07/23 21:42
 * Enunciado:
 * Registro de entrada y salida de personas con listas circulares doblemente
 * enlazadas y búsqueda con árboles binarios + Extras
 *
 *******************************************************************************/ 
#include "GestorArchivo.h"
#include "../Controlador/ListaCircularDoble.cpp"
#include <iostream>
#include <fstream>
#include <sstream>

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       GestorArchivo::extraerFecha(std::string input)
// Purpose:    Implementation of GestorArchivo::extraerFecha(std::string input)
// Parameters:
// - input
// Return:     Fecha
////////////////////////////////////////////////////////////////////////////////////////////////////////

Fecha GestorArchivo::extraerFecha(std::string input) {
	int anio, mes, dia, hora, minuto, segundo;
	std::stringstream ss(input);
    char dl;

    ss >> dia >> dl >> mes >> dl >> anio
		>> dl >> dl >> dl >> dl >> dl >> dl
		>> hora >> dl >> minuto >> dl >> segundo;
		
	return Fecha(anio, mes, dia, hora, minuto, segundo);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       GestorArchivo::guardarListaEmpleadoComoCSV(ListaCircularDoble<Empleado>& lista,std::string nombreArchivo) 
// Purpose:    Guardar los elementos de una ListaCircularDoble de empleados en un archivo CSV
// Parameters:
// - lista
// - nombreArchivo
// Return:     void
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void GestorArchivo::guardarListaEmpleadoComoCSV(ListaCircularDoble<Empleado>& lista,std::string nombreArchivo){
    std::ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        NodoDoble<Empleado>* actual = lista.getCabeza();
        if (actual != nullptr) {
        	archivo << "CEDULA" << ";"
                    << "NOMBRE" << ";"
                    << "APELLIDO" << ";"
					<< "FECHA NACIMIENTO" << ";"
					<< "SUELDO" << std::endl;
            do {
                archivo << actual->getDato().getCedula() << ";"
                        << actual->getDato().getNombre() << ";"
                        << actual->getDato().getApellido() << ";"
                        << actual->getDato().getFechaNacimiento() << ";"
                        << actual->getDato().getSueldo() << std::endl;
                actual = actual->getSiguiente();
            } while (actual != lista.getCabeza());
        }
        archivo.close();
        std::cout << "Archivo guardado correctamente." << std::endl;
    } else {
        std::cerr << "No se pudo abrir el archivo para escritura." << std::endl;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       GestorArchivo::cargarCSVEnListaEmpleado(ListaCircularDoble<Empleado>& lista, std::string nombreArchivo) 
// Purpose:    Cargar los elementos de un archivo CSV en una ListaCircularDoble de empleados
// Parameters:
// - lista
// - nombreArchivo
// Return:     void
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void GestorArchivo::cargarCSVEnListaEmpleado(ListaCircularDoble<Empleado>& lista, std::string nombreArchivo){
    std::ifstream archivo(nombreArchivo);
    Fecha fecha;
    if (archivo.is_open()) {
        std::string linea;
        std::getline(archivo, linea);
        while (std::getline(archivo, linea)) {
            std::istringstream ss(linea);
            std::string cedula, nombre, apellido, strFecha, strSueldo;
            float sueldo;
            std::getline(ss, cedula, ';');
            std::getline(ss, nombre, ';');
            std::getline(ss, apellido, ';');
            std::getline(ss, strFecha, ';');
            std::getline(ss, strSueldo, ';');
            fecha = extraerFecha(strFecha);
            sueldo = std::stof(strSueldo);
            Empleado empleado(cedula, nombre, apellido, fecha, sueldo);
            lista.insertar(empleado);
        }
        archivo.close();
        std::cout << "(O)===)> Archivo cargado correctamente." << std::endl;
    } else {
        std::cerr << "(O)===)> No se pudo abrir el archivo para lectura." << std::endl;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       GestorArchivo::guardarListaRegistroComoCSV(ListaCircularDoble<RegistroEntradaSalida>& lista, std::string nombreArchivo) 
// Purpose:    Guardar los elementos de una ListaCircularDoble de registros de entrada y salida en un archivo CSV
// Parameters:
// - lista
// - nombreArchivo
// Return:     void
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void GestorArchivo::guardarListaRegistroComoCSV(ListaCircularDoble<RegistroEntradaSalida>& lista, std::string nombreArchivo){
	std::ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        NodoDoble<RegistroEntradaSalida>* actual = lista.getCabeza();
        if (actual != nullptr) {
        	archivo << "CEDULA" << ";"
                        << "FECHA / HORA ENTRADA" << ";"
                        << "FECHA / HORA SALIDA" << ";"
                        << "CONTADOR REGISTRO" << std::endl;
            do {
                archivo << actual->getDato().getEmpleado().getCedula() << ";"
                        << actual->getDato().getFechaEntrada() << ";"
                        << actual->getDato().getFechaSalida() << ";"
                        << actual->getDato().getContadorRegistro() << std::endl;
                actual = actual->getSiguiente();
            } while (actual != lista.getCabeza());
        }
        archivo.close();
        std::cout << "(O)===)> Archivo guardado correctamente." << std::endl;
    } else {
        std::cerr << "(O)===)> No se pudo abrir el archivo para escritura." << std::endl;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:        GestorArchivo::cargarCSVEnListaRegistro(ListaCircularDoble<RegistroEntradaSalida>& listaRegistros, ListaCircularDoble<Empleado>& listaEmpleados, std::string nombreArchivo)
// Purpose:    Cargar los elementos de un archivo CSV en una ListaCircularDoble de registros de entrada y salida
// Parameters:
// - listaEmpleados
// - listaRegistros
// - nombreArchivo
// Return:     void
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void GestorArchivo::cargarCSVEnListaRegistro(ListaCircularDoble<RegistroEntradaSalida>& listaRegistros, ListaCircularDoble<Empleado>& listaEmpleados, std::string nombreArchivo){
	std::ifstream archivo(nombreArchivo);
	Empleado empleadoRegistro;
    Fecha fechaEntrada;
    Fecha fechaSalida;
    if (archivo.is_open()) {
        std::string linea;
        std::getline(archivo, linea);
        while (std::getline(archivo, linea)) {
            std::istringstream ss(linea);
            std::string cedula, strFechaEntrada, strFechaSalida, strContador;
            int contadorRegistro;
            std::getline(ss, cedula, ';');
            std::getline(ss, strFechaEntrada, ';');
            std::getline(ss, strFechaSalida, ';');
            std::getline(ss, strContador, ';');
            
            fechaEntrada = extraerFecha(strFechaEntrada);
            fechaSalida = extraerFecha(strFechaSalida);
            contadorRegistro = std::stoi(strContador);
            
            Empleado empleadoEncontrada(cedula, "", "", fechaEntrada, 0);
            empleadoRegistro = listaEmpleados.extraerDato(empleadoEncontrada);
            RegistroEntradaSalida registro(empleadoRegistro, fechaEntrada, fechaSalida);
            registro.setContadorRegistro(contadorRegistro);
            listaRegistros.insertar(registro);
        }
        archivo.close();
        std::cout << "(O)===)> Archivo cargado correctamente." << std::endl;
    } else {
        std::cerr << "(O)===)> No se pudo abrir el archivo para lectura." << std::endl;
    }
}