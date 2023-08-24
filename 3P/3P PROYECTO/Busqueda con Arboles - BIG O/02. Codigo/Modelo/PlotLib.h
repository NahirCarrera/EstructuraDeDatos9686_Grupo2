#ifndef PLOTLIB_H
#define PLOTLIB_H

#include <vector>
#include <string>

class PlotLib {
private:
    int width;
    int height;
    int cotaX;
    int cotaY;

    char* toChar(int numero);
    char* stringToChar(std::string cadena);
    void drawCartesianPlane();
    void drawPoint(float x, float y, int centerX, int centerY, int size);
    void drawLine(std::vector<std::pair<float, float>> points, int centerX, int centerY);

public:
    PlotLib(int w, int h, int cx, int cy);
    ~PlotLib();
    void ejecutarDrawLines(std::vector<std::pair<float, float>> points);
};

#endif