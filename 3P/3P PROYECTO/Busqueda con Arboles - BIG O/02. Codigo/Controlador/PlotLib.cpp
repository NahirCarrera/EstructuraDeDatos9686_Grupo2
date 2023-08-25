#include "../Modelo/PlotLib.h"
#include <graphics.h>
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>


PlotLib::PlotLib(int w, int h, float cx, float cy) {
    width = w;
    height = h;
    cotaX = cx;
    cotaY = cy;
}

PlotLib::~PlotLib() {
	
}

char* PlotLib::toChar(float numero) {
	// Redondea el número a 2 decimales
    std::stringstream stream;
    if (numero < 10) {
    	stream << std::fixed << std::setprecision(2) << numero;	
	} else {
		stream << std::fixed << std::setprecision(0) << numero;
	}
    
    std::string cadena = stream.str();
    char* punteroModificable = new char[cadena.length() + 1];
    strcpy(punteroModificable, cadena.c_str());

    return punteroModificable;
}

char* PlotLib::stringToChar(std::string cadena) {
    char* punteroModificable = new char[cadena.length() + 1];
    strcpy(punteroModificable, cadena.c_str());
    return punteroModificable;
}

void PlotLib::drawCartesianPlane() {
    int centerX = width / 12;
    int centerY = height - height / 12;

    setcolor(BLACK);
    // Dibujar ejes X e Y positivos
    line(0, centerY, width, centerY); // Eje X
    line(centerX, 0, centerX, height); // Eje Y

    // Etiquetas para los ejes
    outtextxy(width - 175, centerY + 25, stringToChar("Numero de datos (n)"));
    outtextxy(centerX + 10, 20, stringToChar("Tiempo de ejecucion (ms)"));

    std::string numero;
    char* numChar;
    float cont = 0;
    // Dibujar escalas en el eje X
    for (int x = 0; x < width - width / 12; x += width / 12) {
        line(centerX + x, centerY - 5, centerX + x, centerY + 5);
        outtextxy(centerX + x - 10, centerY + 8, toChar(cont));
        cont += cotaX / 10.0;
    }

    cont = cotaY;
    // Dibujar escalas en el eje Y
    for (int y = centerY - height / 12; y > 0; y -= height / 12) {
        line(centerX - 5, centerY - y, centerX + 5, centerY - y);
        outtextxy(centerX - 30, centerY - y, toChar(cont));
        cont -= cotaY / 10.0;
    }
}

void PlotLib::drawPoint(float x, float y, int centerX, int centerY, int size) {
    float scaleX = (width / 12) / (cotaX / 10.0);
    float scaleY = (height / 12) / (cotaY / 10.0);

    // Ajustar coordenadas al sistema de coordenadas de la ventana
    int adjustedX = round(centerX + x * scaleX);
    int adjustedY = round(centerY - y * scaleY);

    for (int i = adjustedX - size; i <= adjustedX + size; i++) {
        for (int j = adjustedY - size; j <= adjustedY + size; j++) {
            putpixel(i, j, RED);
        }
    }
}

void PlotLib::drawLine(std::vector<std::pair<float, float>> points, std::string color, int style, int size) {
    int centerX = width / 12;
    int centerY = height - height / 12;

    if (points.size() < 2) {
        // La línea debe tener al menos dos puntos para dibujarse.
        return;
    }

    if (color == "BLACK") {
        setcolor(BLACK);
    } else if (color == "BLUE") {
        setcolor(BLUE);
    } else if (color == "RED") {
        setcolor(RED);
    } else if (color == "GREEN") {
        setcolor(GREEN);
    } else if (color == "YELLOW") {
        setcolor(YELLOW);
    } else {
        setcolor(BLACK); // Color por defecto si no coincide ninguno
    }

    setlinestyle(style, 1, size); // El último parámetro (3) establece el grosor de la línea.

    // Dibuja la línea conectando los puntos
    for (int i = 1; i < points.size(); i++) {
        float x1 = points[i - 1].first;
        float y1 = points[i - 1].second;
        float x2 = points[i].first;
        float y2 = points[i].second;

        int adjustedX1 = round(centerX + x1 * (width / 12) / (cotaX / 10.0));
        int adjustedY1 = round(centerY - y1 * (height / 12) / (cotaY / 10.0));
        int adjustedX2 = round(centerX + x2 * (width / 12) / (cotaX / 10.0));
        int adjustedY2 = round(centerY - y2 * (height / 12) / (cotaY / 10.0));
        line(adjustedX1, adjustedY1, adjustedX2, adjustedY2);
        drawPoint(x1, y1, centerX, centerY, 4);
        drawPoint(x2, y2, centerX, centerY, 4);
    }
}


void PlotLib::iniciar(){
	initwindow(width, height, "Plano Cartesiano", 100, 100);
    setbkcolor(WHITE);
    cleardevice();
    drawCartesianPlane();
}

void PlotLib::terminar(){
    // Esperar a que el usuario presione una tecla
    getch();
    closegraph();
}
