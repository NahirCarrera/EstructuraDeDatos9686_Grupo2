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
 
#include "../Controlador/ArbolBinario.cpp"
#include "../Modelo/Empleado.h"
#include "../Modelo/RegistroEntradaSalida.h"
#include "../Modelo/Fecha.h"
#include "../Modelo/Singleton.h"
#include "../Modelo/PlotLib.h"
#include "../Modelo/GeneradorDatos.h"
#include "../Modelo/BigO.h"
#include "ControladorMenu.h"
#include "GestorArchivo.h"
#include "Menu.h"
#include "Dato.h"
#include "Backup.h"
#include "Imagen.h"
#include <string>
#include <cstdlib> // para usar system("cls") y system("pause")
#include <chrono>
#include <windows.h>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ControladorMenu::registrarEmpleado()
// Purpose:    Generar le registro de un empleado al sistema
// Return:     void
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ControladorMenu::registrarEmpleado() {
	std::string cedula, nombre, apellido;
	float sueldo;
    Fecha fecha;
    
    ListaCircularDoble<Empleado>& empleados = Singleton::getInstance()->getEmpleados();
    
	std::cout<< "(O)===)><><><><><><><><><><><><><><><><><><><><><><><><><><><)==(O)"<<std::endl;
	std::cout << "                      REGISTRO DE EMPLEADO" << std::endl;
	// Obtener datos para una persona
    
    std::cout << "(O)===)> Ingrese la cedula: ";
    cedula = Dato::ingresarCedulaEcuador();
    
    if (!empleados.buscar(Empleado(cedula, "", "", fecha, 0))) {
    	std::cout << "(O)===)> Ingrese un nombre: ";
	    nombre = Dato::ingresarNombreSimple();
	    std::cout << "(O)===)> Ingrese un apellido: ";
	    apellido = Dato::ingresarNombreSimple();;
		std::cout << "(O)===)> Ingrese la fecha de nacimiento:\n";
		fecha = Dato::ingresarFechaCumple();
		std::cout << "(O)===)> Ingrese el sueldo asignado por mes (USD):";
		sueldo = Dato::ingresarFloat();
		std::cout<< "(O)===)><><><><><><><><><><><><><><><><><><><><><><><><><><><)==(O)"<<std::endl;
	    // Crear una persona con los datos ingresados
	    Empleado persona(cedula, nombre, apellido, fecha, sueldo);
	    
	    
	    ListaCircularDoble<Empleado> empleadosBigO;
	    std::vector<std::pair<int, double>> resultados;
	    int maximo = Singleton::getInstance()->getNumeroDatos();
		double tiempoEjecucion;
		int salto = BigO::obtenerSaltos(maximo);
		
		for(int i = 0; i <= maximo; i+=salto) {
			empleadosBigO = ListaCircularDoble<Empleado>();
			tiempoEjecucion = BigO::medirTiempoEjecucion([&]() {
				for(int j = 0; j < i; j++) {
					empleadosBigO.insertar(empleados.getPos(j));
				}
			    empleadosBigO.insertar(persona);
			});
			resultados.push_back(std::pair<int, double>(i, tiempoEjecucion));	
		}
		
	    BigO::guardarResultadosCSV(resultados, "resultados.csv");
	    graficar();
	    
	    
	    empleados.insertar(persona);
	    GestorArchivo::guardarListaEmpleadoComoCSV(empleados, "EmpleadosAleatorio.csv");
	    Singleton::getInstance()->setNumeroDatos(empleados.getSize());
	    std::cout << "(O)===)> Empleado registrado con exito." << std::endl;
	} else {
		std::cout << "(O)===)> Cedula ya registrada..." << std::endl;
	}
	system("pause");
}

////////////////////////////////////////////////////////////////////////
// Name:       restaurarBackups()
// Purpose:    Ubica la carpeta seleccionada por menu y restaura la
//             copia de seguridad 
// Parameters:
// - textoConfirmacion
// Return:     bool
////////////////////////////////////////////////////////////////////////

bool confirmarAccion1(std::string textoConfirmacion) {
	system("cls");
	bool seRealiza = false;
	Menu subMenuConfirmacion("(O)===)> " + textoConfirmacion);
	subMenuConfirmacion.insertarOpcion("SI                  ", [&]() {seRealiza = true;});
	subMenuConfirmacion.insertarOpcion("NO                  ", []() {});
	subMenuConfirmacion.correr();
	
	return seRealiza;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ControladorMenu::eliminarEmpleado()
// Purpose:    Elimina un empleado segun la cedula ingresada
// Return:     void
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ControladorMenu::eliminarEmpleado() {
	std::string cedula;
    Fecha fecha;
    bool hayRegistro = true;

	ListaCircularDoble<Empleado>& empleados = Singleton::getInstance()->getEmpleados();
	ListaCircularDoble<RegistroEntradaSalida>& registros = Singleton::getInstance()->getRegistros();
	
	// Pedimos al usuario que ingrese la cedula que desea buscar
	std::cout << "(O)===)><><><><><><><><><><><><><><><><><><><><><><><><><><><)==(O)"<<std::endl;
	std::cout << "                      ELIMINAR EMPLEADO" << std::endl;
    std::cout << "(O)===)> Ingrese la cedula: ";
    cedula = Dato::ingresarCedulaEcuador();
    std::cout << "(O)===)><><><><><><><><><><><><><><><><><><><><><><><><><><><)==(O)"<<std::endl;
    system("cls");
    Empleado empleado(cedula, "", "", fecha, 0);
    RegistroEntradaSalida registro(empleado, fecha, fecha);
    empleado = empleados.extraerDato(empleado);
    
    if(empleados.buscar(empleado)) {
    	if (confirmarAccion1("Esta seguro que desea eliminar el empleado:\n\n" + empleado.mostrar())) {
    		
			ListaCircularDoble<Empleado> empleadosBigO;
			ListaCircularDoble<RegistroEntradaSalida> registrosBigO;
			std::vector<std::pair<int, double>> resultados;
		    int maximo = Singleton::getInstance()->getNumeroDatos();
			double tiempoEjecucion = 1;
			int salto = BigO::obtenerSaltos(maximo);
			
			for(int i = 0; i <= maximo; i+=salto) {
				empleadosBigO = ListaCircularDoble<Empleado>();
				registrosBigO = ListaCircularDoble<RegistroEntradaSalida>();
				
				tiempoEjecucion = BigO::medirTiempoEjecucion([&]() {
				    for(int j = 0; j < i; j++) {
						empleadosBigO.insertar(empleados.getPos(j));
						registrosBigO.insertar(registros.getPos(j)); 
					}
					empleadosBigO.eliminar(empleado);
	
			    	while(hayRegistro) {
			    		hayRegistro = registrosBigO.eliminar(registro);
					}
				});	
				
							
				resultados.push_back(std::pair<int, double>(i, tiempoEjecucion));	
			}
			
		    BigO::guardarResultadosCSV(resultados, "resultados.csv");
		    graficar();
    		
    		
			empleados.eliminar(empleado);
    	
		    while(hayRegistro) {
		    	hayRegistro = registros.eliminar(registro);
			}
				
			GestorArchivo::guardarListaEmpleadoComoCSV(empleados, "EmpleadosAleatorio.csv");
	    	GestorArchivo::guardarListaRegistroComoCSV(registros, "RegistrosAleatorio.csv");
	    	Singleton::getInstance()->setNumeroDatos(empleados.getSize());
	    	std::cout << "(O)===)> Empleado y Registros eliminados" << std::endl;
	    		
		} else {
			std::cout << "(O)===)> Cancelado: No se elimino el empleado..." << std::endl;
		}

	} else {
		std::cout << "(O)===)> Cedula no registrada..." << std::endl;
	}
    
    
	system("pause");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ControladorMenu::modificarNombreApellido()
// Purpose:    Modifica el nombre y apellido de un empelado
// Parameters:
// - cedula
// Return:     void
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ControladorMenu::modificarNombreApellido(std::string cedula) {
	std::string nombre, apellido;
	Empleado empleado;
	RegistroEntradaSalida registro;
    
    ListaCircularDoble<Empleado>& empleados = Singleton::getInstance()->getEmpleados();
    ListaCircularDoble<RegistroEntradaSalida>& registros = Singleton::getInstance()->getRegistros();

	NodoDoble<Empleado>* nodoEmpleado = empleados.extraerNodo(Empleado(cedula, "", "", Fecha(), 0));
    
    if (nodoEmpleado != nullptr) {
    	empleado = nodoEmpleado->getDato();
    	std::cout<< "(O)===)><><><><><><><><><><><><><><><><><><><><><><><><><><><)==(O)"<<std::endl;
		std::cout << "             MODIFICAR NOMBRE/APELLIDO DE EMPLEADO" << std::endl;
    	std::cout << "(O)===)> Ingrese el nuevo nombre: ";
	    nombre = Dato::ingresarNombreSimple();
	    std::cout << "(O)===)> Ingrese el nuevo apellido: ";
	    apellido = Dato::ingresarNombreSimple();
	    
	    if (confirmarAccion1("Esta seguro que desea modificar el nombre y apellido del empleado?\n\n" + empleado.mostrar())) {
		    
			
			ListaCircularDoble<RegistroEntradaSalida> registrosBigO;
			std::vector<std::pair<int, double>> resultados;
		    int maximo = Singleton::getInstance()->getNumeroDatos();
			double tiempoEjecucion = 1;
			int salto = BigO::obtenerSaltos(maximo);
			
			for(int i = 0; i <= maximo; i+=salto) {
				registrosBigO = ListaCircularDoble<RegistroEntradaSalida>();
				for(int j = 0; j < i; j++) {
					registrosBigO.insertar(registros.getPos(j)); 
				}
				
				do {
					tiempoEjecucion = BigO::medirTiempoEjecucion([&]() {
				    	
					});	
				} while (tiempoEjecucion <= 0);
							
				resultados.push_back(std::pair<int, double>(i, tiempoEjecucion));	
			}
			
		    BigO::guardarResultadosCSV(resultados, "resultados.csv");
		    graficar();
			
			
			
			
			
			
			
			
			
			
			
			
			
			empleado.setNombre(nombre);
		    empleado.setApellido(apellido);
		    nodoEmpleado->setDato(empleado);
		    registro = RegistroEntradaSalida(empleado, Fecha(), Fecha());
		    NodoDoble<RegistroEntradaSalida>* aux = registros.getCabeza();
		    
		    if (aux != nullptr) {
		    	do{
					if (aux->getDato() == registro){
						registro = aux->getDato();
						registro.setEmpleado(empleado);
						aux->setDato(registro);
					}
					aux = aux->getSiguiente();
				} while (aux != registros.getCabeza());
				
				
			}
			
			
			
			GestorArchivo::guardarListaRegistroComoCSV(registros, "RegistrosAleatorio.csv");
		    GestorArchivo::guardarListaEmpleadoComoCSV(empleados, "EmpleadosAleatorio.csv");
	    	
		    std::cout << "(O)===)> Nombre y Apellido modificado exitosamente..." << std::endl;
	    
	    } else {
			std::cout << "(O)===)> Cancelado: No se modifico el empleado..." << std::endl;
		}
	} else {
		std::cout << "(O)===)> Error: Algo salio mal con la busqueda..." << std::endl;	
	}
    
	
	system("pause");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ControladorMenu::modificarSueldo()
// Purpose:    Modifica el sueldo de un empleado
// Parameters:
// - cedula
// Return:     void
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ControladorMenu::modificarSueldo(std::string cedula) {
	float sueldo;
	Empleado empleado;
	RegistroEntradaSalida registro;
    
    ListaCircularDoble<Empleado>& empleados = Singleton::getInstance()->getEmpleados();
    ListaCircularDoble<RegistroEntradaSalida>& registros = Singleton::getInstance()->getRegistros();

	NodoDoble<Empleado>* nodoEmpleado = empleados.extraerNodo(Empleado(cedula, "", "", Fecha(), 0));
    
    if (nodoEmpleado != nullptr) {
    	empleado = nodoEmpleado->getDato();
    	std::cout<< "(O)===)><><><><><><><><><><><><><><><><><><><><><><><><><><><)==(O)"<<std::endl;
		std::cout << "             MODIFICAR SUELDO DE EMPLEADO" << std::endl;
    	std::cout << "(O)===)> Ingrese el sueldo asignado por mes (USD):";
		sueldo = Dato::ingresarFloat();
	    
	    if (confirmarAccion1("Esta seguro que desea modificar el sueldo del empleado?\n\n" + empleado.mostrar())) {
	    
	    empleado.setSueldo(sueldo);
	    nodoEmpleado->setDato(empleado);
	    
	    registro = RegistroEntradaSalida(empleado, Fecha(), Fecha());
	    NodoDoble<RegistroEntradaSalida>* aux = registros.getCabeza();
	    
	    if (aux != nullptr) {
			do{
				if (aux->getDato() == registro){
					registro = aux->getDato();
					registro.setEmpleado(empleado);
					aux->setDato(registro);
				}
				aux = aux->getSiguiente();
			} while (aux != registros.getCabeza());
	    				
			GestorArchivo::guardarListaRegistroComoCSV(registros, "RegistrosAleatorio.csv");
		}
		
	    GestorArchivo::guardarListaEmpleadoComoCSV(empleados, "EmpleadosAleatorio.csv");
	    std::cout << "(O)===)> Sueldo modificado exitosamente..." << std::endl;
	    
	    } else {
			std::cout << "(O)===)> Cancelado: No se modifico el empleado..." << std::endl;
		}
	} else {
		std::cout << "(O)===)> Error: Algo salio mal con la busqueda..." << std::endl;	
	}
    
	
	system("pause");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ControladorMenu::registrarEntradaSalida()
// Purpose:    Registrar la entrada o salida de un empleado del sistema
// Return:     void
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ControladorMenu::registrarEntradaSalida() {
	std::string cedula;
	Fecha fecha(0,0,0,0,0,0);
	Fecha fechaActual;
	NodoDoble<RegistroEntradaSalida>* nodoRegistro;
	NodoDoble<Empleado>* nodoEmpleado;
	
	ListaCircularDoble<Empleado>& empleados = Singleton::getInstance()->getEmpleados();
	ListaCircularDoble<RegistroEntradaSalida>& registros = Singleton::getInstance()->getRegistros();
	
	std::cout << "(O)===)><><><><><><><><><><><><><><><><><><><><><><><><><><><)==(O)"<<std::endl;
	std::cout << "                 REGISTRO DE ENTRADA Y SALIDA" << std::endl;	
	std::cout << "(O)===)> Ingrese la cedula: ";
    cedula = Dato::ingresarCedulaEcuador();
    std::cout << "(O)===)><><><><><><><><><><><><><><><><><><><><><><><><><><><)==(O)"<<std::endl;		
	nodoEmpleado = empleados.extraerNodo(Empleado(cedula, "", "", fecha, 0));
	
	// Primero buscamos si hay la cedula registrada
	if (nodoEmpleado != nullptr) {
		RegistroEntradaSalida registro(nodoEmpleado->getDato(), fecha, fecha);
		
		nodoRegistro = registros.extraerNodo(registro);
		
		// Si no existe un registro de esa cedula creamos uno
		if(nodoRegistro == nullptr) {
			if (confirmarAccion1("Esta seguro que desea registrar la entrada con la fecha/hora: " + fechaActual.mostrar())) {
				std::cout << "(O)===)> Entrada registrada fecha/hora: " << fechaActual <<std::endl;
				RegistroEntradaSalida registroNuevo(nodoEmpleado->getDato(), fechaActual, fecha);
				registros.insertar(registroNuevo);
			} else {
				std::cout << "(O)===)> Entrada no registrada..." <<std::endl;
			}
			
		} else {
			// Si existe un registro con el contador en 1 es porque ya registro la salida
			// y se debe crear uno nuevo para esa cedula
			if (nodoRegistro->getDato().getContadorRegistro() == 1) {
				if(Fecha::obtenerFechaSimple(fechaActual) == Fecha::obtenerFechaSimple(nodoRegistro->getDato().getFechaSalida())){
					std::cout << "Este empleado ya realizo su registro completo por hoy."<<std::endl;
				} else {
					if (confirmarAccion1("Esta seguro que desea registrar la entrada con la fecha/hora: " + fechaActual.mostrar())) {
						std::cout << "(O)===)> Entrada registrada fecha/hora: " << fechaActual <<std::endl;
						RegistroEntradaSalida registroNuevo(nodoEmpleado->getDato(), fechaActual, fecha);
						registros.insertar(registroNuevo);
					} else {
						std::cout << "(O)===)> Entrada no registrada..." <<std::endl;
					}
				}
				
			} else {
				// Si no es 1 es porque es 0, en este caso falta registrar la nueva salida
				if (confirmarAccion1("Esta seguro que desea registrar la salida con la fecha/hora: " + fechaActual.mostrar())) {
					RegistroEntradaSalida registroNuevo = nodoRegistro->getDato();
					registroNuevo.setFechaSalida(fechaActual);
					registroNuevo.addContadorRegistro();
					
					nodoRegistro->setDato(registroNuevo);
					std::cout << "(O)===)> Salida registrada fecha/hora: " << fechaActual <<std::endl;
				} else {
					std::cout << "(O)===)> Salida no registrada..." <<std::endl;
				}
			}
		}
		
		GestorArchivo::guardarListaRegistroComoCSV(registros, "RegistrosAleatorio.csv");
	} else {
		std::cout << "(O)===)> Cedula no registrada..." << std::endl;
	}
	system("pause");
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ControladorMenu::mostrarRegistro()
// Purpose:    Generar el reporte general de todas las entradas y salidas
// Return:     void
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ControladorMenu::mostrarRegistro() {
	Singleton::getInstance()->getRegistros().mostrar();
	system("pause");
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ControladorMenu::mostrarEmpleados()
// Purpose:    Generar el reporte de todos los empleados del sistema
// Return:     void
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ControladorMenu::mostrarEmpleados() {
	std::cout << "NUmero de datos: " << Singleton::getInstance()->getNumeroDatos() << std::endl;
	Singleton::getInstance()->getEmpleados().mostrar();
	system("pause");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ControladorMenu::mostrarRegistroIndividual()
// Purpose:    Generar el reporte de registros de un empleado específico
// Return:     void
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ControladorMenu::mostrarRegistroIndividual() {
	std::string cedula;
    Fecha fecha;

	ListaCircularDoble<Empleado>& empleados = Singleton::getInstance()->getEmpleados();
	ListaCircularDoble<RegistroEntradaSalida>& registros = Singleton::getInstance()->getRegistros();
	
	//Insertamos los elementos de la lista en el arbol binario
	ArbolBinario<RegistroEntradaSalida> registrosArbol;
	NodoDoble<RegistroEntradaSalida>* actual;	
	actual = registros.getCabeza();
	
	if (actual != nullptr) {
		do {
			registrosArbol.insertarNodo(actual->getDato());
			actual = actual->getSiguiente();
		} while (actual != registros.getCabeza());
	}
	
	// Pedimos al usuario que ingrese la cedula que desea buscar
	std::cout << "(O)===)><><><><><><><><><><><><><><><><><><><><><><><><><><><)==(O)"<<std::endl;
	std::cout << "                      REGISTRO INDIVIDUAL" << std::endl;
    std::cout << "(O)===)> Ingrese la cedula: ";
    cedula = Dato::ingresarCedulaEcuador();
    std::cout << "(O)===)><><><><><><><><><><><><><><><><><><><><><><><><><><><)==(O)"<<std::endl;
    system("cls");
    Empleado empleado(cedula, "", "", fecha, 0);
    
    
    
    
    ArbolBinario<RegistroEntradaSalida> registrosArbolBigO;
	ListaCircularDoble<Empleado> empleadosBigO;
	std::vector<std::pair<int, double>> resultados;
    int maximo = Singleton::getInstance()->getNumeroDatos();
	double tiempoEjecucion = 1;
	int salto = BigO::obtenerSaltos(maximo);
	
	for(int i = 0; i <= maximo; i+=salto) {
		empleadosBigO = ListaCircularDoble<Empleado>();
		registrosArbolBigO = ArbolBinario<RegistroEntradaSalida>();
		for(int j = 0; j < i; j++) {
			empleadosBigO.insertar(empleados.getPos(j));
			registrosArbolBigO.insertarNodo(registros.getPos(j));
		}
		
		
		auto start = std::chrono::high_resolution_clock::now();
		NodoArbol<RegistroEntradaSalida>* registro = registrosArbolBigO.buscarNodo(RegistroEntradaSalida(empleado, fecha, fecha));
		empleados.buscar(empleado);
		auto stop = std::chrono::high_resolution_clock::now();
		std::chrono::nanoseconds duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
		
	    tiempoEjecucion = duration.count();
	    std::cout << "i: " << i << ", tamEm: " << empleadosBigO.getSize() << std::endl;
		std::cout << tiempoEjecucion << std::endl;
		//std::cout << duration.count() << std::endl;
		
		resultados.push_back(std::pair<int, double>(i, tiempoEjecucion));	
	}
	
    BigO::guardarResultadosCSV(resultados, "resultados.csv");
    graficar();
    

    
    
    NodoArbol<RegistroEntradaSalida>* registro = registrosArbol.buscarNodo(RegistroEntradaSalida(empleado, fecha, fecha));
	
	if (empleados.buscar(empleado)) {
		if (registro != nullptr) {
			std::cout << registro->getDato().getEmpleado() << std::endl << std::endl;	
			registrosArbol.mostrarRepetidos(RegistroEntradaSalida(empleado, fecha, fecha));
		} else {
			std::cout << "(O)===)> No se encontraron registros para este empleado..." << std::endl;
		}
	} else {
		std::cout << "(O)===)> Cedula no registrada..." << std::endl;
	}

	system("pause");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ControladorMenu::crearCopiaDeSeguridad()
// Purpose:    Generar la copia de seguridad de los archivos
// Return:     void
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ControladorMenu::crearCopiaDeSeguridad(){	
	std::cout << "(O)===)> <><><><><><><><>< BACKUP ><><><><><><><><> <)==(O)"<<std::endl;
	Backup::crearBackup();
	system("pause");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ControladorMenu::recuperarDatos()
// Purpose:    Restaurar la copia de seguridad de los archivos
// Return:     void
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ControladorMenu::restaurarDatos(){	
	std::cout << "(O)===)> <><><><><><><><>< RESTAURACIÓN ><><><><><><><><> <)==(O)"<<std::endl;
	Backup::restaurarBackups("backup");
	system("pause");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ControladorMenu::generarPdf()
// Purpose:    GGenerar un archivo .pdf de los archivos de registro
// Return:     void
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ControladorMenu::generarPdf(){	
	std::cout << "(O)===)> <><><><><><><><>< GUARDAR REGISTROS ><><><><><><><><> <)==(O)"<<std::endl;
	ListaCircularDoble<Empleado>& empleados = Singleton::getInstance()->getEmpleados();
	
	ListaCircularDoble<Empleado> empleadosBigO;
	std::vector<std::pair<int, double>> resultados;
    int maximo = Singleton::getInstance()->getNumeroDatos();
	double tiempoEjecucion = 1;
	int salto = BigO::obtenerSaltos(maximo);
	
	for(int i = 0; i <= maximo; i+=salto) {
		empleadosBigO = ListaCircularDoble<Empleado>();
		for(int j = 0; j < i; j++) {
			empleadosBigO.insertar(empleados.getPos(j));
		}
		
		GestorArchivo::guardarListaEmpleadoComoCSV(empleadosBigO, "EmpleadosAleatorio.csv");
		
		tiempoEjecucion = BigO::medirTiempoEjecucion([&]() {
	    	Backup::generarPDF("EmpleadosAleatorio.csv");	
		});	
		
					
		resultados.push_back(std::pair<int, double>(i, tiempoEjecucion));	
	}
	
    BigO::guardarResultadosCSV(resultados, "resultados.csv");
    graficar();
	
	GestorArchivo::guardarListaEmpleadoComoCSV(empleados, "EmpleadosAleatorio.csv");
	Backup::generarPDF("EmpleadosAleatorio.csv");	
	Backup::generarPDF("RegistrosAleatorio.csv");
	system("pause");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ControladorMenu::crearSistemaDeAyuda()
// Purpose:    Direccionar al sistema de ayuda al usuario
// Return:     void
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ControladorMenu::crearSistemaDeAyuda(){	
	std::cout << "(O)===)> <><><><><><><><>< HELP ><><><><><><><><> <)==(O)"<<std::endl;
	system("help.chm");
	system("pause");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       imprimirFoto()
// Purpose:    Pixelea una foto e imprime en consola
// Return:     void
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ControladorMenu::imprimirFoto(){	
	std::cout << "(O)===)> <><><><><><><><>< ABOUT US ><><><><><><><><> <)==(O)"<<std::endl;
	std::cout << "         Por favor, maximice el tamanio de su consola" <<std::endl;
	std::cout << "                   Att: Nahir & Stephen"<<std::endl;
	std::cout << "                  ndcarrera2@espe.edu.ec"<<std::endl;
	std::cout << "                   sddrouet@espe.edu.ec"<<std::endl;
	system("pause"); 
	Imagen imagen("ejemplo.bmp");
	imagen.imprimirImagenEnConsola();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ControladorMenu::salir()
// Purpose:    Salir del bucle actual
// Return:     void
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ControladorMenu::salir() {
	Singleton* singleton = Singleton::getInstance();
	
	ListaCircularDoble<Empleado>& empleados = singleton->getEmpleados();
	ListaCircularDoble<RegistroEntradaSalida>& registros = singleton->getRegistros();
	ListaCircularDoble<Empleado> empleadosCopia;
	ListaCircularDoble<RegistroEntradaSalida> registrosCopia;
	GestorArchivo::cargarCSVEnListaEmpleado(empleadosCopia, "EmpleadosAleatorio.csv");
	GestorArchivo::cargarCSVEnListaRegistro(registrosCopia, empleadosCopia, "RegistrosAleatorio.csv");
	empleados = empleadosCopia;
	registros = registrosCopia;
	
	menuEjecutando = false;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ControladorMenu::subMenuRegistroDePersonal()
// Purpose:    Desplegar las opciones del submenú para modificar un empleado
// Return:     void
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ControladorMenu::modificarEmpleado() {
	std::string cedula;
    Fecha fecha;

	ListaCircularDoble<Empleado>& empleados = Singleton::getInstance()->getEmpleados();
	
	// Pedimos al usuario que ingrese la cedula que desea buscar
	std::cout << "(O)===)><><><><><><><><><><><><><><><><><><><><><><><><><><><)==(O)"<<std::endl;
	std::cout << "                      MODIFICAR EMPLEADO" << std::endl;
    std::cout << "(O)===)> Ingrese la cedula: ";
    cedula = Dato::ingresarCedulaEcuador();
    system("cls");
    
    NodoDoble<Empleado>* empleado = empleados.extraerNodo(Empleado(cedula, "", "", fecha, 0));
    
    
    if(empleado != nullptr) {    	
    		Menu menu(empleado->getDato().mostrar() +"\n(O)===)> <><><><><><><><>< MENU MODIFICAR EMPLEADO ><><><><><><><><> <)==(O)"); 
			menu.insertarOpcion("      (x)===)> Modificar Nombre/Apellido      <)==(x)      ", [&]() { modificarNombreApellido(cedula); });
			menu.insertarOpcion("      (x)===)> Modificar Sueldo               <)==(x)      ", [&]() { modificarSueldo(cedula); });
			menu.insertarOpcion("      (x)===)> Regresar                       <)==(x)      ", [&]() { salir(); }); // Para salir del bucle siempre se debe usar esta funcion de salir()
			while (menuEjecutando) {
				menu.setTitulo(empleado->getDato().mostrar() +"\n(O)===)> <><><><><><><><>< MENU MODIFICAR EMPLEADO ><><><><><><><><> <)==(O)");
				menu.correr();
			}
			menuEjecutando = true; // Siempre que se quiera correr un menu en bucle
    	
	} else {
		std::cout << "(O)===)> Cedula no registrada..." << std::endl;
		system("pause");
	}
    
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ControladorMenu::graficar1()
// Purpose:    Muestra el grafico 1 de la bigO
// Return:     void
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ControladorMenu::graficar(){
	std::vector<std::pair<float, float>> points;
	points = GestorArchivo::cargarPuntos("resultados.csv");
	float maxX = 0, maxY = 0;
	
	for (int i = 0; i < points.size(); i++) {
		if (maxX < points[i].first) {
			maxX = points[i].first;
		}
		
		if (maxY < points[i].second) {
			maxY = points[i].second;
		}
	}
	
	if (maxX < 1) {
		maxX = 1;
	}
	
	if (maxY < 1) {
		maxY = 1;
	}
	
	PlotLib plotter(600, 600, maxX, maxY);


    // Llama al método ejecutarDrawLines con el vector de puntos
    plotter.iniciar();
    plotter.drawLine(points, "BLUE", 0, 3);
    plotter.terminar();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ControladorMenu::generarDatos()
// Purpose:    Genera datos Aleatorios
// Return:     void
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ControladorMenu::generarDatos() {
	std::cout << "(O)===)> <><><><><><><><>< Generador de Datos ><><><><><><><><> <)==(O)" << std::endl;
	int numeroDatos;
	Singleton* singleton = Singleton::getInstance();
	std::cout << "(O)===)> Ingrese el numero de Datos a generar: ";
	numeroDatos = Dato::ingresarEntero();
	singleton->setNumeroDatos(numeroDatos);
	GeneradorDatos::ejecutar(numeroDatos);
	
	ListaCircularDoble<Empleado>& empleados = singleton->getEmpleados();
	ListaCircularDoble<RegistroEntradaSalida>& registros = singleton->getRegistros();
	ListaCircularDoble<Empleado> empleadosCopia;
	ListaCircularDoble<RegistroEntradaSalida> registrosCopia;
	GestorArchivo::cargarCSVEnListaEmpleado(empleadosCopia, "EmpleadosAleatorio.csv");
	GestorArchivo::cargarCSVEnListaRegistro(registrosCopia, empleadosCopia, "RegistrosAleatorio.csv");
	empleados = empleadosCopia;
	registros = registrosCopia;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ControladorMenu::subMenuRegistroDePersonal()
// Purpose:    Desplegar las opciones del submenú para el control de personal
// Return:     void
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ControladorMenu::subMenuRegistroDePersonal() {
	Menu menu( "(O)===)> <><><><><><><><>< Sistema de Control de Personal ><><><><><><><><> <)==(O)"); 
	menu.insertarOpcion("        (x)===)> Registrar Empleado             <)==(x)           ", [&]() { registrarEmpleado(); });
	menu.insertarOpcion("        (x)===)> Modificar Empleado             <)==(x)           ", [&]() { modificarEmpleado(); });
	menu.insertarOpcion("        (x)===)> Eliminar Empleado              <)==(x)           ", [&]() { eliminarEmpleado(); });	
	menu.insertarOpcion("        (x)===)> Registrar Entrada/Salida       <)==(x)           ", [&]() { registrarEntradaSalida(); });
	menu.insertarOpcion("        (x)===)> Mostrar Registro               <)==(x)           ", [&]() { mostrarRegistro(); });
	menu.insertarOpcion("        (x)===)> Mostrar Empleados              <)==(x)           ", [&]() { mostrarEmpleados(); });
	menu.insertarOpcion("        (x)===)> Mostrar Registro Individual    <)==(x)           ", [&]() { mostrarRegistroIndividual(); });
	menu.insertarOpcion("        (x)===)> Regresar al Menu Principal     <)==(x)           ", [&]() { salir(); }); // Para salir del bucle siempre se debe usar esta funcion de salir()
	while (menuEjecutando) {
		menu.correr();
	}
	menuEjecutando = true; // Siempre que se quiera correr un menu en bucle
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ControladorMenu::subMenuExtras()
// Purpose:    Desplegar las opciones del submenu para actividades extras
// Return:     void
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ControladorMenu::subMenuExtras() {
	Menu menu("(O)===)> <><><><><><><><>< Extras ><><><><><><><><> <)==(O)");
	menu.insertarOpcion("(x)===)> Crear copia de seguridad  <)==(x)", [&]() { crearCopiaDeSeguridad(); });
	menu.insertarOpcion("(x)===)> Restaurar datos           <)==(x)", [&]() { restaurarDatos(); });
	menu.insertarOpcion("(x)===)> Guardar registros         <)==(x)", [&]() { generarPdf(); });
	menu.insertarOpcion("(x)===)> Help                      <)==(x)", [&]() { crearSistemaDeAyuda(); });
	menu.insertarOpcion("(x)===)> About us                  <)==(x)", [&]() { imprimirFoto(); });
	menu.insertarOpcion("(x)===)> Regresar al menu inicial  <)==(x)", [&]() { salir(); }); // Para salir del bucle siempre se debe usar esta funcion de salir()
	
	while (menuEjecutando) {
		menu.correr();
	}
	menuEjecutando = true; // Siempre que se quiera correr un menu en bucle
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ControladorMenu::correrMenu()
// Purpose:    Desplegar las opciones del menu principal
// Return:     void
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ControladorMenu::correrMenu() {
	Singleton* singleton = Singleton::getInstance();
	
	ListaCircularDoble<Empleado>& empleados = singleton->getEmpleados();
	ListaCircularDoble<RegistroEntradaSalida>& registros = singleton->getRegistros();
	
	GestorArchivo::cargarCSVEnListaEmpleado(empleados, "EmpleadosAleatorio.csv");
	GestorArchivo::cargarCSVEnListaRegistro(registros, empleados, "RegistrosAleatorio.csv");
	singleton->setNumeroDatos(empleados.getSize());
	
	Menu menu("(O)===)> <><><><><><><><>< Menu Principal ><><><><><><><><> <)==(O)");
	menu.insertarOpcion("       ( )===== Registro de Personal ====( )      ", [&]() { subMenuRegistroDePersonal(); });
	menu.insertarOpcion("       ( )===== Extras               ====( )      ", [&]() { subMenuExtras(); });
	menu.insertarOpcion("       ( )===== Generar Datos        ====( )      ", [&]() { generarDatos(); });
	menu.insertarOpcion("       ( )===== Salir                ====( )      ", [&]() { salir(); }); // Para salir del bucle siempre se debe usar esta funcion de salir()
	
	menuEjecutando = true; // Siempre que se quiera correr un menu en bucle
	while (menuEjecutando) {
		menu.correr();
	}
	std::cout << "\n(O)===)> <><><><><><><><>< Saliendo, muchas gracias por usar el programa ><><><><><><><><> <)==(O)" << std::endl;
	std::cout << "(O)===)> Att: Nahir & Stephen" << std::endl;
	system("pause");
}