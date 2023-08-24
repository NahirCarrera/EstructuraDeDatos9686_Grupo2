#include "../Modelo/BigO.h"
#include <iostream>
#include <fstream>
#include <chrono>

double BigO::medirTiempoEjecucion(const std::function<void()>& funcion) {
    auto inicio = std::chrono::high_resolution_clock::now();
    funcion(); // Ejecutar la función proporcionada
    auto fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion = fin - inicio;
    return duracion.count();
}

void BigO::guardarResultadosCSV(const std::vector<std::pair<int, double>>& resultados, const std::string& nombreArchivo) {
    std::ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        archivo << "Numero de Datos, Tiempo de Ejecucion (segundos)\n";
        for (const auto& resultado : resultados) {
            archivo << resultado.first << ", " << resultado.second << "\n";
        }
        archivo.close();
        std::cout << "Resultados guardados en " << nombreArchivo << std::endl;
    } else {
        std::cerr << "Error al abrir el archivo" << std::endl;
    }
}