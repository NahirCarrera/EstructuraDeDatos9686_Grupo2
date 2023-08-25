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