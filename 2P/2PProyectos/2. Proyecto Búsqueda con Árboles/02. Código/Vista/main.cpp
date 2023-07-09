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
#include <string>
#include "../Modelo/Empleado.h"
#include "../Modelo/Fecha.h"


int main() {
	std::string cedula, nombre, apellido;
	Fecha fecha;
	
	ListaCircularDoble<Empleado>* empleados = new ListaCircularDoble<Empleado>();
	
	fecha = Fecha(2000, 4, 17, 0, 0, 0);
	cedula = "1726952946"; nombre = "David"; apellido = "Drouet";
	Empleado empleado1(cedula, nombre, apellido, fecha, 540.44f);
	empleados->insertar(empleado1);
	
	fecha = Fecha(2002, 10, 31, 0, 0, 0);
	cedula = "1752235943"; nombre = "Nahir"; apellido = "Carrera";
	Empleado empleado2(cedula, nombre, apellido, fecha, 1255.62f);
	empleados->insertar(empleado2);
	
	empleados->mostrar();
	
	
	return 0;
}