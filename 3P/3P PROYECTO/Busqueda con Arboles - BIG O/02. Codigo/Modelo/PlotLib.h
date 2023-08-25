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

#ifndef PLOTLIB_H
#define PLOTLIB_H

#include <vector>
#include <string>

class PlotLib {
private:
    int width;
    int height;
    float cotaX;
    float cotaY;

    char* toChar(float numero);
    char* stringToChar(std::string cadena);
    void drawCartesianPlane();
    void drawPoint(float x, float y, int centerX, int centerY, int size);

public:
    PlotLib(int w, int h, float cx, float cy);
    ~PlotLib();
    void drawLine(std::vector<std::pair<float, float>> points, std::string color, int style, int size);
    void iniciar();
    void terminar();
};

#endif