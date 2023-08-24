#ifndef BIGO_H
#define BIGO_H

#include <vector>
#include <string>
#include <functional>

class BigO {
public:
    static double medirTiempoEjecucion(const std::function<void()>& funcion);
    static void guardarResultadosCSV(const std::vector<std::pair<int, double>>& resultados, const std::string& nombreArchivo);
};

#endif
