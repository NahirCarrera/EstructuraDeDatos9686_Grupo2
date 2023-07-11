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
 
#include "ControladorMenu.h"
#include "../Herramientas/Menu.h"
#include "../Herramientas/Dato.h"
#include "Backup.h"
#include <string>
#include <cstdlib> // para usar system("cls") y system("pause")


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ControladorMenu::registrarEmpleado()
// Purpose:    Generar le registro de un empleado al sistema
// Return:     void
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ControladorMenu::registrarEmpleado() {
	std::cout<<"Usted ingreso un empleado\n";
	system("pause");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ControladorMenu::registrarEntradaSalida()
// Purpose:    Registrar la entrada o salida de un empleado del sistema
// Return:     void
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ControladorMenu::registrarEntradaSalida() {
	std::cout<<"Usted registro una entrada o salida\n";
	system("pause");
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ControladorMenu::mostrarRegistro()
// Purpose:    Generar el reporte general de todas las entradas y salidas
// Return:     void
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ControladorMenu::mostrarRegistro() {
	std::cout<<"Desplegar registro completo :D\n";
	system("pause");
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ControladorMenu::mostrarEmpleados()
// Purpose:    Generar el reporte de todos los empleados del sistema
// Return:     void
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ControladorMenu::mostrarEmpleados() {
	std::cout<<"Desplegar lista de empleados :D\n";
	system("pause");
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ControladorMenu::mostrarRegistroIndividual()
// Purpose:    Generar el reporte de registros de un empleado específico
// Return:     void
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ControladorMenu::mostrarRegistroIndividual() {
	std::cout<<"Desplegar registro individual :D\n";
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
	std::cout<<"Crear el Pdf :D\n";
	system("pause");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       ControladorMenu::crearSistemaDeAyuda()
// Purpose:    Direccionar al sistema de ayuda al usuario
// Return:     void
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ControladorMenu::crearSistemaDeAyuda(){	
	std::cout<<"Abrir sistema de ayuda :D\n";
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
// Purpose:    Desplegar las opciones del submenú para el control de personal
// Return:     void
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ControladorMenu::subMenuRegistroDePersonal() {
	Menu menu( "(O)===)> <><><><><><><><>< Sistema de Control de Personal ><><><><><><><><> <)==(O)"); 
	menu.insertarOpcion("                (x)===)> Registrar Empleado             <)==(x)", [&]() { registrarEmpleado(); });
	menu.insertarOpcion("                (x)===)> Registrar Entrada/Salida       <)==(x)", [&]() { registrarEntradaSalida(); });
	menu.insertarOpcion("                (x)===)> Mostrar Registro               <)==(x)", [&]() { mostrarRegistro(); });
	menu.insertarOpcion("                (x)===)> Mostrar Empleados              <)==(x)", [&]() { mostrarEmpleados(); });
	menu.insertarOpcion("                (x)===)> Mostrar registro individual    <)==(x)", [&]() { mostrarRegistroIndividual(); });
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