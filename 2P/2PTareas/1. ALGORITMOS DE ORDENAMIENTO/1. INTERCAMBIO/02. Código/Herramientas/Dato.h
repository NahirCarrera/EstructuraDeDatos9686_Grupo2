/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Nombres: Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 14/06/23 18:57
 * Fecha de modificacion: 19/06/23 23:33
 * Enunciado:
 * Registro de entrada y salida de personas con listas circulares doblemente
 * enlazadas y algoritmo de búsqueda por intercambio
 *
 *******************************************************************************/ 

#ifndef DATO_H
#define DATO_H
#include <string>
class Dato
{
	public:
		static int ingresarMenuOpcion(char, char);
		static int ingresarEntero(void);
   		static float ingresarFloat(void);
   		static int ingresarDimension(char cnum1, char cnum2);
   		static bool validarLetra(char letra, int posicion);
   		static std::string ingresarPlacaEcuador();
   		static std::string ingresarCedulaEcuador();
   		static bool validarAnio(int);
   		static int ingresarAnio();
   		static std::string ingresarNombreSimple();
   		static std::string ingresarNombreCompleto();
   		static std::string ingresarModelo();
	protected:
};

#endif