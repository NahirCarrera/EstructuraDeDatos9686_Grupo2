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
#include "ControladorMenu.h"
#include "GestorArchivo.h"
#include "Menu.h"
#include "Dato.h"
#include "Backup.h"
#include <string>
#include <cstdlib> // para usar system("cls") y system("pause")


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
	    
	    empleados.insertar(persona);
	    GestorArchivo::guardarListaEmpleadoComoCSV(empleados, "Empleados.csv");
	} else {
		std::cout << " Cedula ya registrada..." << std::endl;
	}
	system("pause");
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
    
    if(empleados.buscar(empleado)) {
    	empleados.eliminar(empleado);
    	
    	while(hayRegistro) {
    		hayRegistro = registros.eliminar(registro);
		}
    	
    	GestorArchivo::guardarListaEmpleadoComoCSV(empleados, "Empleados.csv");
    	GestorArchivo::guardarListaRegistroComoCSV(registros, "Registros.csv");
    	
    	std::cout << " Empleado y Registros eliminados" << std::endl;
    	
	} else {
		std::cout << " ¡¡ Cedula no registrada..." << std::endl;
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
	    
	    empleado.setNombre(nombre);
	    empleado.setApellido(apellido);
	    nodoEmpleado->setDato(empleado);
	    
	    registro = RegistroEntradaSalida(empleado, Fecha(), Fecha());
	    NodoDoble<RegistroEntradaSalida>* aux = registros.getCabeza();
		do{
			if (aux->getDato() == registro){
				registro = aux->getDato();
				registro.setEmpleado(empleado);
				aux->setDato(registro);
			}
			aux = aux->getSiguiente();
		} while (aux != registros.getCabeza());
	    
	    GestorArchivo::guardarListaEmpleadoComoCSV(empleados, "Empleados.csv");
    	GestorArchivo::guardarListaRegistroComoCSV(registros, "Registros.csv");
	    std::cout << "Nombre y Apellido modificado exitosamente..." << std::endl;
	} else {
		std::cout << "Error: Algo salio mal con la busqueda..." << std::endl;	
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
	    
	    empleado.setSueldo(sueldo);
	    nodoEmpleado->setDato(empleado);
	    
	    registro = RegistroEntradaSalida(empleado, Fecha(), Fecha());
	    NodoDoble<RegistroEntradaSalida>* aux = registros.getCabeza();
		do{
			if (aux->getDato() == registro){
				registro = aux->getDato();
				registro.setEmpleado(empleado);
				aux->setDato(registro);
			}
			aux = aux->getSiguiente();
		} while (aux != registros.getCabeza());
	    
	    GestorArchivo::guardarListaEmpleadoComoCSV(empleados, "Empleados.csv");
    	GestorArchivo::guardarListaRegistroComoCSV(registros, "Registros.csv");
	    std::cout << "Sueldo modificado exitosamente..." << std::endl;
	} else {
		std::cout << "Error: Algo salio mal con la busqueda..." << std::endl;	
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
			RegistroEntradaSalida registroNuevo(nodoEmpleado->getDato(), fechaActual, fecha);
			registros.insertar(registroNuevo);
		} else {
			// Si existe un registro con el contador en 1 es porque ya registro la salida
			// y se debe crear uno nuevo para esa cedula
			if (nodoRegistro->getDato().getContadorRegistro() == 1) {
				RegistroEntradaSalida registroNuevo(nodoEmpleado->getDato(), fechaActual, fecha);
				registros.insertar(registroNuevo);
			} else {
				// Si no es 1 es porque es 0, en este caso falta registrar la nueva salida
				RegistroEntradaSalida registroNuevo = nodoRegistro->getDato();
				registroNuevo.setFechaSalida(fechaActual);
				registroNuevo.addContadorRegistro();
				
				nodoRegistro->setDato(registroNuevo);
			}
		}
		
		GestorArchivo::guardarListaRegistroComoCSV(registros, "Registros.csv");
	} else {
		std::cout << " ¡¡ Cedula no registrada..." << std::endl;
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
    
    NodoArbol<RegistroEntradaSalida>* registro = registrosArbol.buscarNodo(RegistroEntradaSalida(empleado, fecha, fecha));
	
	if (registro != nullptr) {	
    	std::cout << registro->getDato().getEmpleado() << std::endl << std::endl;
		registrosArbol.mostrarRepetidos(RegistroEntradaSalida(empleado, fecha, fecha));
	} else {
		std::cout << " ¡¡ Cedula no registrada..." << std::endl;
	}	
	
	system("pause");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ControladorMenu::crearCopiaDeSeguridad()
// Purpose:    Generar la copia de seguridad de los archivos
// Return:     void
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ControladorMenu::crearCopiaDeSeguridad(){	
	Backup::crearBackup();
	system("pause");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ControladorMenu::generarPdf()
// Purpose:    GGenerar un archivo .pdf de los archivos de registro
// Return:     void
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ControladorMenu::generarPdf(){	
	Backup::generarPDF("Empleados.csv");	
	Backup::generarPDF("Registros.csv");
	system("pause");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ControladorMenu::crearSistemaDeAyuda()
// Purpose:    Direccionar al sistema de ayuda al usuario
// Return:     void
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ControladorMenu::crearSistemaDeAyuda(){	
	std::cout<<"Abrir sistema de ayuda :D\n";
	system("help.chm");
	system("pause");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       imprimirFoto()
// Purpose:    Pixelea una foto e imprime en consola
// Return:     void
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ControladorMenu::imprimirFoto(){	
	std::cout<<"Foto de los guapos :D\n";
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
    std::cout << "(O)===)><><><><><><><><><><><><><><><><><><><><><><><><><><><)==(O)"<<std::endl;
    system("cls");
    
    NodoDoble<Empleado>* empleado = empleados.extraerNodo(Empleado(cedula, "", "", fecha, 0));
    
    
    if(empleado != nullptr) {    	
    		Menu menu(empleado->getDato().mostrar() +"\n(O)===)> <><><><><><><><>< MENU MODIFICAR EMPLEADO ><><><><><><><><> <)==(O)"); 
			menu.insertarOpcion("                (x)===)> Modificar Nombre/Apellido      <)==(x)", [&]() { modificarNombreApellido(cedula); });
			menu.insertarOpcion("                (x)===)> Modificar Sueldo               <)==(x)", [&]() { modificarSueldo(cedula); });
			menu.insertarOpcion("                (x)===)> Regresar                       <)==(x)", [&]() { salir(); }); // Para salir del bucle siempre se debe usar esta funcion de salir()
			while (menuEjecutando) {
				menu.setTitulo(empleado->getDato().mostrar() +"\n(O)===)> <><><><><><><><>< MENU MODIFICAR EMPLEADO ><><><><><><><><> <)==(O)");
				menu.correr();
			}
			menuEjecutando = true; // Siempre que se quiera correr un menu en bucle
    	
	} else {
		std::cout << " !! Cedula no registrada..." << std::endl;
		system("pause");
	}
    
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ControladorMenu::subMenuRegistroDePersonal()
// Purpose:    Desplegar las opciones del submenú para el control de personal
// Return:     void
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ControladorMenu::subMenuRegistroDePersonal() {
	Menu menu( "(O)===)> <><><><><><><><>< Sistema de Control de Personal ><><><><><><><><> <)==(O)"); 
	menu.insertarOpcion("                (x)===)> Registrar Empleado             <)==(x)", [&]() { registrarEmpleado(); });
	menu.insertarOpcion("                (x)===)> Modificar Empleado             <)==(x)", [&]() { modificarEmpleado(); });
	menu.insertarOpcion("                (x)===)> Eliminar Empleado              <)==(x)", [&]() { eliminarEmpleado(); });	
	menu.insertarOpcion("                (x)===)> Registrar Entrada/Salida       <)==(x)", [&]() { registrarEntradaSalida(); });
	menu.insertarOpcion("                (x)===)> Mostrar Registro               <)==(x)", [&]() { mostrarRegistro(); });
	menu.insertarOpcion("                (x)===)> Mostrar Empleados              <)==(x)", [&]() { mostrarEmpleados(); });
	menu.insertarOpcion("                (x)===)> Mostrar Registro Individual    <)==(x)", [&]() { mostrarRegistroIndividual(); });
	menu.insertarOpcion("                (x)===)> Regresar al Menu Principal     <)==(x)", [&]() { salir(); }); // Para salir del bucle siempre se debe usar esta funcion de salir()
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
	menu.insertarOpcion("       (x)===)> Crear copia de seguridad  <)==(x)", [&]() { crearCopiaDeSeguridad(); });
	menu.insertarOpcion("       (x)===)> Guardar registros         <)==(x)", [&]() { generarPdf(); });
	menu.insertarOpcion("       (x)===)> Help                      <)==(x)", [&]() { crearSistemaDeAyuda(); });
	menu.insertarOpcion("       (x)===)> About us                  <)==(x)", [&]() { imprimirFoto(); });
	menu.insertarOpcion("       (x)===)> Regresar al menu inicial  <)==(x)", [&]() { salir(); }); // Para salir del bucle siempre se debe usar esta funcion de salir()
	
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
	
	GestorArchivo::cargarCSVEnListaEmpleado(empleados, "Empleados.csv");
	GestorArchivo::cargarCSVEnListaRegistro(registros, empleados, "Registros.csv");
	
	Menu menu(          "(O)===)> <><><><><><><><>< Menu Principal ><><><><><><><><> <)==(O)");
	menu.insertarOpcion("             (x)===)> Registro de Personal <)==(x)", [&]() { subMenuRegistroDePersonal(); });
	menu.insertarOpcion("             (x)===)> Extras               <)==(x)", [&]() { subMenuExtras(); });
	menu.insertarOpcion("             (x)===)> Salir                <)==(x)", [&]() { salir(); }); // Para salir del bucle siempre se debe usar esta funcion de salir()
	
	menuEjecutando = true; // Siempre que se quiera correr un menu en bucle
	while (menuEjecutando) {
		menu.correr();
	}
	std::cout << "\n(O)===)> <><><><><><><><>< Saliendo, muchas gracias por usar el programa ><><><><><><><><> <)==(O)" << std::endl;
	std::cout << "(O)===)> Att: Nahir & Stephen"<<std::endl;
	system("pause");
}