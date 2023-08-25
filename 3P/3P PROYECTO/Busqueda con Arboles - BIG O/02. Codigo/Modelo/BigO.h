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
 
#ifndef BIGO_H
#define BIGO_H

#include <vector>
#include <string>
#include <functional>
#include <cstdint>

class BigO {
private:
	uint64_t cycles_per_second; // Ciclos por segundo (velocidad de la CPU)

public:
	BigO();
	~BigO();
    double medirTiempoEjecucion(const std::function<void()>& funcion);
    void guardarResultadosCSV(const std::vector<std::pair<int, double>>& resultados, const std::string& nombreArchivo);
    int obtenerSaltos(int numeroDatos);
    
    
};

#endif