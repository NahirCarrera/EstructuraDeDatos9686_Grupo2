/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Estructura de Datos 9686
 * Nombres: Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 07/07/23 21:42
 * Fecha de modificacion: 25/08/23 02:04
 * Enunciado:
 * Analisis Big-O del proyecto de Registro de Personas
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
					<< "FECHANACIMIENTO" << ";"
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
    } else {
        std::cerr << "No se pudo abrir el archivo para escritura." << std::endl;
    }
}

std::vector<std::pair<float, float>> GestorArchivo::cargarPuntos(std::string nombreArchivo) {
	std::vector<std::pair<float, float>> puntos;

    // Abrir el archivo CSV
    std::ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo: " << nombreArchivo << std::endl;
        return puntos;
    }

    std::string linea;
    bool primeraLinea = true;

    while (std::getline(archivo, linea)) {
        if (primeraLinea) {
            // Ignorar la primera línea (encabezado)
            primeraLinea = false;
            continue;
        }

        std::istringstream stream(linea);
        std::string valor1, valor2;

        if (std::getline(stream, valor1, ';') && std::getline(stream, valor2, ';')) {
            float x = std::stof(valor1);
            float y = std::stof(valor2);
            puntos.emplace_back(x, y);
        }
    }

    archivo.close();

    return puntos;
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
                        << "FECHA/HORAENTRADA" << ";"
                        << "FECHA/HORASALIDA" << ";"
                        << "CONTADORREGISTRO" << std::endl;
            do {
                archivo << actual->getDato().getEmpleado().getCedula() << ";"
                        << actual->getDato().getFechaEntrada() << ";"
                        << actual->getDato().getFechaSalida() << ";"
                        << actual->getDato().getContadorRegistro() << std::endl;
                actual = actual->getSiguiente();
            } while (actual != lista.getCabeza());
        }
        archivo.close();
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
    } else {
        std::cerr << "(O)===)> No se pudo abrir el archivo para lectura." << std::endl;
    }
}