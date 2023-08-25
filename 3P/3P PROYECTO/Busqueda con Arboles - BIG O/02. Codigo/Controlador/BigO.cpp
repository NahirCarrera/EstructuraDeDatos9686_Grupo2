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
 
#include "../Modelo/BigO.h"
#include <iostream>
#include <fstream>
#include <functional>
#include <cstdint>

// Función para obtener el valor de RDTSC
inline uint64_t rdtsc() {
    uint32_t lo, hi;
    asm volatile (
        "rdtsc"
        : "=a" (lo), "=d" (hi)
    );
    return ((uint64_t)hi << 32) | lo;
}

BigO::BigO() {
	uint64_t start, end;
    
    // Mide la velocidad de la CPU (ciclos por segundo)
    start = rdtsc();
    sleep(1); // Espera 1 segundo (puedes ajustar el tiempo según tus necesidades)
    end = rdtsc();
    cycles_per_second = end - start;
}

BigO::~BigO() {
	
}

double BigO::medirTiempoEjecucion(const std::function<void()>& funcion) {
    uint64_t start, end, cycles;
    double milliseconds;
    
    // Realiza la tarea que deseas medir
    start = rdtsc();
    
    funcion(); // Ejecutar la función proporcionada

	end = rdtsc();
	cycles = end - start; // Ciclos transcurridos durante la tarea
    milliseconds = static_cast<double>(cycles) * 1000.0 / static_cast<double>(cycles_per_second);

    return milliseconds;
}

void BigO::guardarResultadosCSV(const std::vector<std::pair<int, double>>& resultados, const std::string& nombreArchivo) {
    std::ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        archivo << "Numero de Datos;Tiempo de Ejecucion (ms)\n";
        for (const auto& resultado : resultados) {
            archivo << resultado.first << ";" << resultado.second << "\n";
        }
        archivo.close();
        std::cout << "Resultados guardados en " << nombreArchivo << std::endl;
    } else {
        std::cerr << "Error al abrir el archivo" << std::endl;
    }
}

int BigO::obtenerSaltos(int numeroDatos) {
	int saltos;
	
	if(numeroDatos <= 20) {
		saltos = 1;
	} else {
		saltos = numeroDatos / 10;
	}
	
	return saltos;
}