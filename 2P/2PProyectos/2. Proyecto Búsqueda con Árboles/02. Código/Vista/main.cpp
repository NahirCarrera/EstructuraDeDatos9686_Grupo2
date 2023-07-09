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
#include "../Controlador/ListaCircularDoble.cpp"
#include "../Controlador/ArbolBinario.cpp"
#include <string>
#include "../Modelo/Empleado.h"
#include "../Modelo/RegistroEntradaSalida.h"
#include "../Modelo/Fecha.h"
#include "../Herramientas/GestorArchivo.h"


void registrarEntradaSalida(ListaCircularDoble<RegistroEntradaSalida>& listaRegistros, ListaCircularDoble<Empleado>& empleados, std::string cedula){
	Fecha fecha(0,0,0,0,0,0);
	Fecha fechaActual;
	NodoDoble<RegistroEntradaSalida>* nodoRegistro;
	NodoDoble<Empleado>* nodoEmpleado;
	nodoEmpleado = empleados.extraerNodo(Empleado(cedula, "", "", fecha, 0));
	
	// Primero buscamos si hay la cedula registrada
	if (nodoEmpleado != nullptr) {
		RegistroEntradaSalida registro(nodoEmpleado->getDato(), fecha, fecha);
		
		nodoRegistro = listaRegistros.extraerNodo(registro);
		
		// Si no existe un registro de esa cedula creamos uno
		if(nodoRegistro == nullptr) {
			RegistroEntradaSalida registroNuevo(nodoEmpleado->getDato(), fechaActual, fecha);
			listaRegistros.insertar(registroNuevo);
		} else {
			// Si existe un registro con el contador en 1 es porque ya registro la salida
			// y se debe crear uno nuevo para esa cedula
			if (nodoRegistro->getDato().getContadorRegistro() == 1) {
				RegistroEntradaSalida registroNuevo(nodoEmpleado->getDato(), fechaActual, fecha);
				listaRegistros.insertar(registroNuevo);
			} else {
				// Si no es 1 es porque es 0, en este caso falta registrar la nueva salida
				RegistroEntradaSalida registroNuevo = nodoRegistro->getDato();
				registroNuevo.setFechaSalida(fechaActual);
				registroNuevo.addContadorRegistro();
				
				nodoRegistro->setDato(registroNuevo);
			}
		}
	} else {
		std::cout << " ¡¡ Cedula no registrada..." << std::endl;
	}
}

void insertarEmpleado(ListaCircularDoble<Empleado>& empleados, std::string cedula, std::string nombre, std::string apellido, Fecha fecha, float sueldo) {
	Empleado empleado(cedula, nombre, apellido, fecha, sueldo);
	empleados.insertar(empleado);
}

void insertarRegistroArbol(ArbolBinario<RegistroEntradaSalida>& registrosArbol, ListaCircularDoble<RegistroEntradaSalida>& registros) {	
	NodoDoble<RegistroEntradaSalida>* actual;	
	actual = registros.getCabeza();
	
	if (actual != nullptr) {
		do {
			registrosArbol.insertarNodo(actual->getDato());
			actual = actual->getSiguiente();
		} while (actual != registros.getCabeza());
	}		
}

int main() {
	ListaCircularDoble<RegistroEntradaSalida> registros;
	ListaCircularDoble<Empleado> empleados;
	ArbolBinario<RegistroEntradaSalida> registrosArbol;
	
	GestorArchivo::cargarCSVEnListaEmpleado(empleados, "Empleados.csv");
	GestorArchivo::cargarCSVEnListaRegistro(registros, empleados, "Registros.csv");
	
	insertarRegistroArbol(registrosArbol, registros);
	//registrosArbol.mostrarArbol();
	registrosArbol.mostrarRepetidos(RegistroEntradaSalida(Empleado("1726952946", "", "", Fecha(), 0), Fecha(), Fecha()));
    //registros.mostrar();

	/*
	insertarEmpleado(empleados, "1726952946", "David", "Drouet",
					Fecha(2000, 4, 17, 0, 0, 0), 540.44f);
	insertarEmpleado(empleados, "1752235943", "Nahir", "Carrera",
					Fecha(2002, 10, 31, 0, 0, 0), 1024.48f);
	insertarEmpleado(empleados, "1710708973", "Nora", "Navarrete",
					Fecha(1966, 10, 31, 0, 0, 0), 950.31f);		
	
	registrarEntradaSalida(registros, empleados, "1726952946");
	registrarEntradaSalida(registros, empleados, "1752235943");
	registrarEntradaSalida(registros, empleados, "1726952946");
	registrarEntradaSalida(registros, empleados, "1726952946");
	registrarEntradaSalida(registros, empleados, "1752235943");
	registrarEntradaSalida(registros, empleados, "1710708973");	
	
	GestorArchivo::guardarListaEmpleadoComoCSV(empleados, "Empleados.csv");
	GestorArchivo::guardarListaRegistroComoCSV(registros, "Registros.csv");
	
	empleados.mostrar();
	registros.mostrar();
	*/
	
	return 0;
}