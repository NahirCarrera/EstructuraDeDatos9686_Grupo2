#include <iostream>
#include <string>
#include <graphics.h>
#include <cmath>
#include <vector>

int width = 600; // Ancho de la ventana
int height = 600; // Alto de la ventana
int cotaX = 2500;
int cotaY = 800;

char* toChar(int numero) {
	std::string cadena = std::to_string(numero);
	char* punteroModificable = new char[cadena.length() + 1];
	strcpy(punteroModificable, cadena.c_str());
	
	return punteroModificable;
}

void drawCartesianPlane() {
    int centerX = width / 12;
    int centerY = height - height / 12;
	
	setcolor(BLACK);
    // Dibujar ejes X e Y positivos
    line(0, centerY, width, centerY); // Eje X
    line(centerX, 0, centerX, height); // Eje Y

    // Etiquetas para los ejes
    outtextxy(width - 175, centerY + 25, "Numero de datos (n)");
    outtextxy(centerX + 10, 20, "Tiempo de ejecucion (ms)");
    
    std::string numero;
    char* numChar;
	int cont = 0; 
    // Dibujar escalas en el eje X
    for (int x = 0; x < width - width / 12; x += width / 12) {
        line(centerX + x, centerY - 5, centerX + x, centerY + 5);
    	outtextxy(centerX + x - 10, centerY + 8, toChar(cont));   
		cont += cotaX/10.0; 
    }
	
	cont = cotaY;
    // Dibujar escalas en el eje Y
    for (int y = centerY - height / 12; y > 0; y -= height / 12) {
        line(centerX - 5, centerY - y, centerX + 5, centerY - y);
        outtextxy(centerX - 30, centerY - y, toChar(cont));   
		cont -= cotaY/10.0;
    }
}

void drawPoint(float x, float y, int centerX, int centerY, int size) {
	//float scaleX = width / (cotaX * 1.0);
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

void drawLine(std::vector<std::pair<float, float>> points, int centerX, int centerY) {
    if (points.size() < 2) {
        // La línea debe tener al menos dos puntos para dibujarse.
        return;
    }

    setcolor(BLUE); // Puedes cambiar el color de la línea según tus preferencias.
    setlinestyle(0, 1, 3); // El último parámetro (3) establece el grosor de la línea.

    // Dibuja la línea conectando los puntos
    for (size_t i = 1; i < points.size(); i++) {
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

int main() {

    initwindow(width, height, "Plano Cartesiano", 100, 100);

	setbkcolor(WHITE);
    cleardevice();
    int centerX = width / 12;
    int centerY = height - height / 12;

    drawCartesianPlane();

	int cuad = 700;
/*
    drawPoint(cuad, 0, centerX, centerY, 3);
    drawPoint(0, cuad, centerX, centerY, 3);
    
    for(float i = 0; i < cuad; i+=1) {
    	drawPoint(i, cuad, centerX, centerY, 2);
    	drawPoint(i, i, centerX, centerY, 2);
    	drawPoint(cuad, i, centerX, centerY, 2);
	}*/
	
	    // Ejemplo de cómo usar drawLine para dibujar una línea.
    std::vector<std::pair<float, float>> points;
    points.push_back(std::make_pair(100, 100));
    points.push_back(std::make_pair(200, 200));
    points.push_back(std::make_pair(300, 100));
    points.push_back(std::make_pair(700, 700));
    points.push_back(std::make_pair(2000, 701));

    drawLine(points, centerX, centerY);

    // Esperar a que el usuario presione una tecla
    getch();
    closegraph();
    return 0;
}

