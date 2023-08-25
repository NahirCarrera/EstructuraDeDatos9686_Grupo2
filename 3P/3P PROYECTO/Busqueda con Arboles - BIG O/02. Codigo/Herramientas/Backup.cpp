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

#include "../Modelo/Fecha.h"
#include "../Bibliotecas/pdf.h"
#include "../Modelo/Singleton.h"
#include "GestorArchivo.h"
#include "Menu.h"
#include "Backup.h"
#include <iomanip>
#include <fstream>
#include <sys/stat.h> // Para mkdir en sistemas Unix-like
#include <iostream>
#include <sstream> 
#include <string>
#include <windows.h>
#include <Shlwapi.h>
#include <filesystem>
#include <functional>
#pragma comment(lib, "Shlwapi.lib")

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

std::string Backup::obtenerDirectorioActual(){
    char buffer[MAX_PATH];
    GetModuleFileName(NULL, buffer, MAX_PATH);
    std::string::size_type pos = std::string(buffer).find_last_of("\\/");
    return std::string(buffer).substr(0, pos);
}

////////////////////////////////////////////////////////////////////////
// Name:       restaurarBackups()
// Purpose:    Ubica la carpeta seleccionada por menu y restaura la
//             copia de seguridad 
// Parameters:
// - textoConfirmacion
// Return:     bool
////////////////////////////////////////////////////////////////////////

bool confirmarAccion(std::string textoConfirmacion) {
	bool seRealiza = false;
	Menu subMenuConfirmacion("(O)===)> " + textoConfirmacion);
	subMenuConfirmacion.insertarOpcion("SI                  ", [&]() {seRealiza = true;});
	subMenuConfirmacion.insertarOpcion("NO                  ", []() {});
	subMenuConfirmacion.correr();
	
	return seRealiza;
}

////////////////////////////////////////////////////////////////////////
// Name:       restaurarBackups()
// Purpose:    Ubica la carpeta seleccionada por menu y restaura la
//             copia de seguridad 
// Return:     void
////////////////////////////////////////////////////////////////////////

void Backup::restaurarBackups(const std::string& rutaCarpetaBackups) {
    std::string rutaCompletaBackups = obtenerDirectorioActual() + "\\" + rutaCarpetaBackups;
    std::string rutaBusqueda = rutaCompletaBackups + "\\*";
    WIN32_FIND_DATA datosArchivo;
    HANDLE hBusqueda = FindFirstFile(rutaBusqueda.c_str(), &datosArchivo);

    if (hBusqueda == INVALID_HANDLE_VALUE) {
        std::cout << "Error: No se pudo abrir la carpeta de backups." << std::endl;
        return;
    }

    Menu subMenuBackup("(O)===)> <><><><><><><><>< BACKUP ><><><><><><><><> <)==(O)\n(O)===)> Carpetas con backups disponibles:");
    auto noHaceNada = []() {}; // Función lambda que no hace nada

    do {
        if (datosArchivo.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            std::string nombreCarpeta = datosArchivo.cFileName;
            if (nombreCarpeta != "." && nombreCarpeta != "..") {
                subMenuBackup.insertarOpcion(nombreCarpeta, noHaceNada);
            }
        }
    } while (FindNextFile(hBusqueda, &datosArchivo) != 0);

    FindClose(hBusqueda);
    
	subMenuBackup.correr();
    std::string carpetaSeleccionada = subMenuBackup.getOpcionSeleccionada().getTexto();
    std::string rutaCarpetaSeleccionada = rutaCompletaBackups + "\\" + carpetaSeleccionada;


	if(confirmarAccion("Esta seguro que desea restaurar los datos del sistema? Esta accion podria ocasionar perdida de informacion.")){
		DWORD atributosCarpeta = GetFileAttributesA(rutaCarpetaSeleccionada.c_str());
	    if (atributosCarpeta == INVALID_FILE_ATTRIBUTES || !(atributosCarpeta & FILE_ATTRIBUTE_DIRECTORY)) {
	        std::cout << "La carpeta seleccionada no existe o no es una carpeta válida." << std::endl;
	        return;
	    }
	    std::string rutaOrigen = rutaCarpetaSeleccionada + "\\*";
	    std::string rutaDestino = obtenerDirectorioActual();
	
	    hBusqueda = FindFirstFile(rutaOrigen.c_str(), &datosArchivo);
	    if (hBusqueda == INVALID_HANDLE_VALUE) {
	        std::cout << "(x)===)> Error: No se pudo abrir la carpeta de backups seleccionada." << std::endl;
	        return;
	    }
	
	    do {
	        if (!(datosArchivo.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
	            std::string archivoOrigen = rutaCarpetaSeleccionada + "\\" + datosArchivo.cFileName;
	            std::string archivoDestino = rutaDestino + "\\" + datosArchivo.cFileName;
	
	            if (CopyFileA(archivoOrigen.c_str(), archivoDestino.c_str(), FALSE) == 0) {
	                DWORD codigoError = GetLastError();
	                std::cout << "(x)===)> Error al restaurar el archivo " << datosArchivo.cFileName << ": Código de error " << codigoError << std::endl;
	            } else {
	                std::cout << "(O)===)> Archivo " << datosArchivo.cFileName << " restaurado." << std::endl;
	            }
	        }
	    } while (FindNextFile(hBusqueda, &datosArchivo) != 0);
		
		
	    FindClose(hBusqueda);
	
	    std::cout << "(O)===)> Backups restaurados con exito <===(O)" << std::endl;
	    
	}else{
		std::cout<<"(x)===)> Cancelado: Backups no restaurados"<<std::endl;
	}
} 
////////////////////////////////////////////////////////////////////////
// Name:       generarPDF()
// Purpose:    Crea un pdf por arhivo con la información del mismo.
// Parameters:
// - nombreArchivoCsv
// Return:     void
////////////////////////////////////////////////////////////////////////

void Backup::generarPDF(std::string nombreArchivoCsv){
	std::fstream reporte;
	std::ostringstream out;
	PDF archivoPdf;
	std::string titulo;
	std::string palabraActual;
	std::string nombreArchivoPdf;
	std::string nombreArchivo;
	string mensajeDeError;
	int maxLineasPorPagina = 40;  // Número máximo de líneas por página
	int lineas = 0;  // Contador de líneas en la página actual
	int contador = 1;
	nombreArchivo = (nombreArchivoCsv == "Empleados.csv") ? "ReporteEmpleados" : "ReporteRegistros";
	out << nombreArchivo<<".pdf";
	nombreArchivoPdf = out.str();

	std::cout << "-----------------------------------------" << "\n";
	std::cout << "Creando archivo: [" << nombreArchivoPdf << "]"<< "\n";
	std::cout << "-----------------------------------------" << "\n";

	archivoPdf.setFont(PDF::COURIER_BOLD, 14);
	
	titulo = (nombreArchivoCsv == "Empleados.csv") ? "Reporte de Empleados" : "Reporte de Registros";
	
	archivoPdf.showTextXY(titulo,110,762);
	archivoPdf.setFont(PDF::COURIER, 12);
	reporte.open(nombreArchivoCsv, std::ios::in);
	
	while (reporte >> palabraActual) {
		if(palabraActual!= "CEDULA;NOMBRE;APELLIDO;FECHANACIMIENTO;SUELDO" && palabraActual!= "CEDULA;FECHA/HORAENTRADA;FECHA/HORASALIDA;CONTADORREGISTRO"){
			contador = 1;
			std::stringstream ss(palabraActual);
		    std::string elemento;
		    std::string campo;
			lineas++;
			
			if(nombreArchivoCsv == "Empleados.csv"){
				archivoPdf.showTextXY("----------------- EMPLEADO -----------------", 50, 747 - 14 * lineas);
			}else{
				archivoPdf.showTextXY("----------------- REGISTRO -----------------", 50, 747 - 14 * lineas);
			}
		    while (std::getline(ss, elemento, ';')) {
		    	lineas++;
		    	switch(contador){
		    		case 1:
		    			archivoPdf.showTextXY("CEDULA: " + elemento, 50, 747 - 14 * lineas);
		    			break;
		    		case 2:
		    			campo = (nombreArchivoCsv == "Empleados.csv") ? "NOMBRE: " : "ENTRADA: ";
		    			archivoPdf.showTextXY(campo + elemento, 50, 747 - 14 * lineas);
		    			break;
					case 3:
					    campo = (nombreArchivoCsv == "Empleados.csv") ? "APELLIDO: " : "SALIDA: ";
					    if(elemento == "0/0/0-hora:0:0:0"){
							archivoPdf.showTextXY(campo + "NO SE REGISTRO SALIDA", 50, 747 - 14 * lineas);
						}else{
							archivoPdf.showTextXY(campo + elemento, 50, 747 - 14 * lineas);
						}
		    			
		    			break;
					case 4:
						if(nombreArchivoCsv == "Empleados.csv"){
							archivoPdf.showTextXY("FECHA DE NACIMIENTO: "+ elemento, 50, 747 - 14 * lineas);
						}
				    	break;
				    case 5:
				        archivoPdf.showTextXY("SUELDO $: "+ elemento, 50, 747 - 14 * lineas);
				    	break;	
				}
				contador++;
		    }
		    lineas++;
		    archivoPdf.showTextXY("--------------------------------------------", 50, 747 - 14 * lineas);
		    
		    // Si la página actual se ha llenado, agregar una nueva página y reiniciar el contador de líneas
		    if (lineas >= maxLineasPorPagina) {
				archivoPdf.newPage();
		        lineas = 0;
		        archivoPdf.setFont(PDF::COURIER, 12);
		    }
		}
	}
	std::cout<<"Numero de paginas de " << nombreArchivoPdf << " : " << archivoPdf.getCurrentPage() + 1 <<std::endl;
	reporte.close();
	
	mensajeDeError = "Lo sentimos ha ocurrido un error...";
	if(!archivoPdf.writeToFile(nombreArchivoPdf, mensajeDeError))
	{
		std::cout << mensajeDeError << std::endl;
	}
	else
	{
		std::cout << "(Se ha creado el PDF)" << std::endl;
	}
}
	
	
	
	
	
	
	
	