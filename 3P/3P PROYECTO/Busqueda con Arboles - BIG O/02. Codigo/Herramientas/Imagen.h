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