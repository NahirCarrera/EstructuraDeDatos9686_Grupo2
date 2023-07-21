/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Estructura de Datos 9686
 * Nombres: Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 07/07/23 21:42
 * Fecha de modificacion: 18/07/23 19:52
 * Enunciado:
 * Registro de entrada y salida de personas con listas circulares doblemente
 * enlazadas y búsqueda con árboles binarios + Extras
 *
 *******************************************************************************/ 
#ifndef IMAGEN_H
#define IMAGEN_H
#include <string>
#include <windows.h>
#include "../Bibliotecas/EasyBMP.h"
class Imagen{
	public:
		//Constuctor
		Imagen(std::string);
		//Setters y Getters
		void setArchivo (std::string);
		std::string getArchivo();
		//Funciones
		int imprimirImagenEnConsola();
	private:
		void dibujarImagen(std::string, HDC*);
		std::string archivo;
};
#endif