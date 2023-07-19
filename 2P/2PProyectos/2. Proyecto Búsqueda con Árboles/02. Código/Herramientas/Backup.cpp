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
#include "../Bibliotecas/pdf.h"
#include "Backup.h"
#include <iomanip>
#include <fstream>
#include <sys/stat.h> // Para mkdir en sistemas Unix-like
#include <iostream>
#include <sstream> 
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
				archivoPdf.showTextXY("----------------- EMPLEADOS -----------------", 50, 747 - 14 * lineas);
			}else{
				archivoPdf.showTextXY("----------------- REGISTROS -----------------", 50, 747 - 14 * lineas);
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
		    			archivoPdf.showTextXY(campo + elemento, 50, 747 - 14 * lineas);
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
	
	
	
	
	
	
	
	