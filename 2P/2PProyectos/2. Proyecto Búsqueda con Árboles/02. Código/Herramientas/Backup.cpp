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

#include "../Modelo/Fecha.h"
#include "Backup.h"
#include <iomanip>
#include <fstream>
#include <sys/stat.h> // Para mkdir en sistemas Unix-like

////////////////////////////////////////////////////////////////////////
// Name:       directorioExiste(const std::string&)
// Purpose:    Verifica si un directorio existe
// Parameters:
// -rutaDirectorio
// Return:     bool   
////////////////////////////////////////////////////////////////////////

bool Backup::directorioExiste(const std::string& rutaDirectorio){
	struct stat info;
    return stat(rutaDirectorio.c_str(), &info) == 0 && (info.st_mode & S_IFDIR);
}

////////////////////////////////////////////////////////////////////////
// Name:       crearCopia(std::string, std::string)
// Purpose:    Crea una copia de un arhcivo en un directorio específico
// Parameters:
// -nombreArchivo
// - nombreCarpetaBackup
// Return:     void
////////////////////////////////////////////////////////////////////////

void Backup::crearCopia(std::string nombreArchivo, std::string nombreCarpetaBackup){
	// Copiar los archivos CSV al backup
        std::ifstream sourceFile(nombreArchivo);
        std::ofstream destinationFile(nombreCarpetaBackup + "/" + nombreArchivo);
        
        if (sourceFile && destinationFile) {
            destinationFile << sourceFile.rdbuf();
            std::cout << "Archivo CSV copiado al backup." << std::endl;
        } else {
            std::cerr << "Error al abrir los archivos." << std::endl;
        }
}

////////////////////////////////////////////////////////////////////////
// Name:       crearBackup()
// Purpose:    Crea una carpeta "backup" y crea una carpeta con fecha donde
//             guarda los archivos del proyecto
// Return:     void
////////////////////////////////////////////////////////////////////////

void Backup::crearBackup(){
	Fecha fecha;
	int result = 0;
	std::string fechaFormateada = fecha.obtenerFechaFormateada(); 
    // Ruta de la carpeta de backup
    std::string rutaCarpetaBackup = "./backup/";
	
	if (!directorioExiste(rutaCarpetaBackup) && mkdir(rutaCarpetaBackup.c_str()) != 0) {
    	result = 0;
	}
    
    if (result == 0) {
        // Ruta de la carpeta con la fecha actual
        std::string nombreCarpetaBackup = rutaCarpetaBackup + fechaFormateada + "/";
        
        // Crear la carpeta con la fecha actual
        result = mkdir(nombreCarpetaBackup.c_str()); // 0777 para permisos en sistemas Unix-like
		if (result == 0){
			std::cout << "Carpeta de backup creada: " << nombreCarpetaBackup << std::endl;
			crearCopia("Empleados.csv",nombreCarpetaBackup );
			crearCopia("Registros.csv", nombreCarpetaBackup);
		}else {
            std::cerr << "Error al crear la carpeta de backup de la versión actual" << std::endl;
        }
    } else {
        std::cerr << "Error al crear la carpeta de backup." << std::endl;
    }
	
}
	