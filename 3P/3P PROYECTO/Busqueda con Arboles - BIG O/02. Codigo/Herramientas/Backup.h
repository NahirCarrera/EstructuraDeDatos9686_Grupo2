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
 
#ifndef BACKUP_H
#define BACKUP_H
#include "../Modelo/Fecha.h"
#include <string>
#include <windows.h>
class Backup{
	public:
		static void crearBackup();
		static void generarPDF(std::string);
		static void restaurarBackups(const std::string& backupsFolderPath);
	private:
		static bool directorioExiste(const std::string&);
		static void crearCopia(std::string, std::string);
		static std::string obtenerDirectorioActual();
};
#endif


