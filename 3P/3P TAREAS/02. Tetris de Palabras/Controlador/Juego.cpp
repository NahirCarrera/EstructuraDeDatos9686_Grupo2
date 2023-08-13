/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Estructura de Datos 9686
 * Nombres: Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 12/08/23 19:40
 * Fecha de modificacion: 12/08/23 19:40
 * Enunciado:
 * Realizar el juego del tetris con palabras en consola
 *
 *******************************************************************************/

#include "../Modelo/Juego.h"

#include <chrono>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <Windows.h>

void Juego::ocultarCursor() {
	//Ocular el cursor de la consola
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = false; // Oculta el cursor
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

Juego::Juego() {
	ocultarCursor();
	this->filas = 20 + 2;
    this->columnas = 10 + 2;
	this->tetris = TetrisGame(filas, columnas);;
}

void Juego::pantallaInicio() {
	std::cout << "|-----------------------------|" << std::endl;
	std::cout << "|           TETRIS            |" << std::endl;
	std::cout << "|-----------------------------|\n" << std::endl;
	std::cout << "Presiona Enter para iniciar..." << std::endl;
    std::cin.get();
    system("cls");
    std::cout << "                             |-----------------------------|" << std::endl;
	std::cout << "                             |           TETRIS            |" << std::endl;
	std::cout << "                             |-----------------------------|" << std::endl;
	std::cout << "                             |       Nahir & Stephen       |" << std::endl;
	std::cout << "                             |-----------------------------|\n" << std::endl;
}

void Juego::ejecutar() {
	srand(time(NULL));
	int intervaloActualizacion = 500; // 500 milisegundos
    bool gameOver = false;
    
    std::string palabra = "PERRO";
    

	pantallaInicio();
    auto tiempoUltimaActualizacion = std::chrono::high_resolution_clock::now();
	

    while (true)
    {

        int posicionAleatoria = rand() % (columnas - palabra.length() - 1) + 1;
        int i = 1;
        bool hayColision = false;
        while (!hayColision)
        {
            auto tiempoActual = std::chrono::high_resolution_clock::now();
            auto duracionDesdeUltimaActualizacion = std::chrono::duration_cast<std::chrono::milliseconds>(tiempoActual - tiempoUltimaActualizacion).count();

            if (duracionDesdeUltimaActualizacion >= intervaloActualizacion)
            {
                tetris.borrarPalabra(i - 1, posicionAleatoria, palabra);
                if (tetris.hayEspacioVacio(i, posicionAleatoria, palabra.length(), gameOver))
                {
                    tetris.colocarPalabra(i, posicionAleatoria, palabra);
                }
                else
                {                	
                    tetris.colocarPalabra(i, posicionAleatoria, palabra);
                    tetris.coincidenPalabras(i, posicionAleatoria, palabra);
                    hayColision = true;
                }
                tetris.imprimirTablero();

                tiempoUltimaActualizacion = std::chrono::high_resolution_clock::now();
                i++;
            }

            if (_kbhit() && !hayColision)
            {                          // Verifica si una tecla ha sido presionada
                char tecla = _getch(); // Captura la tecla sin esperar a Enter
                if (tecla == 27)
                { // Si la tecla es Esc, sale del bucle
                    gameOver = false;
                    break;
                }
                else if (tecla == 75)
                { // Tecla de flecha izquierda (código ASCII 75)
                    if (tetris.hayEspacioHorizontal(i - 1, posicionAleatoria, palabra.length(), false))
                    {
                        tetris.borrarPalabra(i - 1, posicionAleatoria, palabra);
                        posicionAleatoria--;
                        tetris.colocarPalabra(i - 1, posicionAleatoria, palabra);
                    }
                }
                else if (tecla == 77)
                { // Tecla de flecha derecha (código ASCII 77)
                    if (tetris.hayEspacioHorizontal(i - 1, posicionAleatoria, palabra.length(), true))
                    { // Verificar si no está en el borde derecho
                        tetris.borrarPalabra(i - 1, posicionAleatoria, palabra);
                        posicionAleatoria++;
                        tetris.colocarPalabra(i - 1, posicionAleatoria, palabra);
                    }
                }
                else if (tecla == 80)
                { // Tecla de flecha abajo (código ASCII 80)
                    tetris.borrarPalabra(i - 1, posicionAleatoria, palabra);
                    if (tetris.hayEspacioVacio(i, posicionAleatoria, palabra.length(), gameOver))
                    {
                        tetris.colocarPalabra(i, posicionAleatoria, palabra);
                    }
                    else
                    {
                        tetris.colocarPalabra(i, posicionAleatoria, palabra);
                        tetris.coincidenPalabras(i, posicionAleatoria, palabra);
                        hayColision = true;
                    }
                    tetris.imprimirTablero();
                    tiempoUltimaActualizacion = std::chrono::high_resolution_clock::now();
                    i++;
                }

                tetris.imprimirTablero();
            }
        }

        if (gameOver)
        {
            tetris.imprimirTablero();
            std::cout << "El juego ha terminado" << std::endl;
            break;
        }
    }
    system("pause");
}