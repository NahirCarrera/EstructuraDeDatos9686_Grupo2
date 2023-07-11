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
 
#ifndef BACKUP_H
#define BACKUP_H
#include "../Modelo/Fecha.h"
#include <string>
class Backup{
	public:
		static void crearBackup();
	private:
		static bool directorioExiste(const std::string&);
		static void crearCopia(std::string, std::string);
};
#endif


