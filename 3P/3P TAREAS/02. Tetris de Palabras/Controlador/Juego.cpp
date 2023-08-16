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
#include "ListaSimple.cpp"
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
	this->filas = 34 + 2;
    this->columnas = 10 + 2;
	this->tetris = TetrisGame(filas, columnas);;
	tetris.obtenerPiezas();
}

void Juego::pantallaInicio() {
	std::cout << "|---------------------------------------------------------|" << std::endl;
	std::cout << "| ||MMMMMMM ||MMMMM ||MMMMMMM   ||MMMMMM   ||M   ||MMMMM  |" << std::endl;
	std::cout << "|    ||M    ||M        ||M      ||M   ||M  ||M  ||M       |" << std::endl;
	std::cout << "|    ||M    ||MMM      ||M      ||MMMMMM   ||M   ||MMMM   |" << std::endl;
	std::cout << "|    ||M    ||M        ||M      ||M   ||M  ||M       ||M  |" << std::endl;
	std::cout << "|    ||M    ||MMMMM    ||M      ||M   ||M  ||M   ||MMMM   |" << std::endl;
	std::cout << "|---------------------------------------------------------|" << std::endl;

	std::cout << "Presiona Enter para iniciar..." << std::endl;
	   
    std::cin.get();
    system("cls");
    std::cout << "                        |************|" << std::endl;
    std::cout << "                        | ||MMMMMMM  |" << std::endl;
	std::cout << "                        |    ||M     |" << std::endl;
	std::cout << "                        |    ||M     |" << std::endl;
	std::cout << "                        |    ||M     |" << std::endl;
	std::cout << "                        |    ||M     |" << std::endl;
	std::cout << "                        |            |" << std::endl;
	std::cout << "                        |  ||MMMMM   |" << std::endl;
	std::cout << "                        |  ||M       |" << std::endl;
	std::cout << "                        |  ||MMM     |" << std::endl;
	std::cout << "                        |  ||M       |" << std::endl;
	std::cout << "                        |  ||MMMMM   |" << std::endl;
	std::cout << "                        |            |" << std::endl;
	std::cout << "                        | ||MMMMMMM  |" << std::endl;
	std::cout << "                        |    ||M     |" << std::endl;
	std::cout << "                        |    ||M     |" << std::endl;
	std::cout << "                        |    ||M     |" << std::endl;
	std::cout << "                        |    ||M     |" << std::endl;
	std::cout << "                        |            |" << std::endl;
	std::cout << "                        | ||MMMMMM   |" << std::endl;
	std::cout << "                        | ||M   ||M  |" << std::endl;
	std::cout << "                        | ||MMMMMM   |" << std::endl;
	std::cout << "                        | ||M   ||M  |" << std::endl;
	std::cout << "                        | ||M   ||M  |" << std::endl;
	std::cout << "                        |            |" << std::endl;
	std::cout << "                        |    ||M     |" << std::endl;
	std::cout << "                        |    ||M     |" << std::endl;
	std::cout << "                        |    ||M     |" << std::endl;
	std::cout << "                        |    ||M     |" << std::endl;
	std::cout << "                        |    ||M     |" << std::endl;
	std::cout << "                        |            |" << std::endl;
	std::cout << "                        |  ||MMMMM   |" << std::endl;
	std::cout << "                        | ||M        |" << std::endl;
	std::cout << "                        |  ||MMMM    |" << std::endl;
	std::cout << "                        |       ||M  |" << std::endl;
	std::cout << "                        |  ||MMMM    |" << std::endl;
	std::cout << "                        |____________|" << std::endl;
}

void Juego::ejecutar() {
	srand(time(NULL));
	int intervaloActualizacion = 500; // 500 milisegundos
    bool gameOver = false;
	
	pantallaInicio();
    auto tiempoUltimaActualizacion = std::chrono::high_resolution_clock::now();
    while (true){
    	Pieza& piezaActual = tetris.getPieza(); // Crear una nueva instancia de Pieza en cada iteración
	    int posicionAleatoria = rand() % (columnas - piezaActual.getPalabra().length() - 1) + 1;
	    int i = 1;
	    bool hayColision = false;
	        
        while (!hayColision)
        {
            auto tiempoActual = std::chrono::high_resolution_clock::now();
            auto duracionDesdeUltimaActualizacion = std::chrono::duration_cast<std::chrono::milliseconds>(tiempoActual - tiempoUltimaActualizacion).count();

            if (duracionDesdeUltimaActualizacion >= intervaloActualizacion){
            	
                tetris.borrarPalabra(i - 1, posicionAleatoria);
                if (tetris.hayEspacioVacio(i, posicionAleatoria, gameOver)){
                	tetris.acabaDeRotar = false;
                    tetris.colocarPalabra(i, posicionAleatoria);
                }
                else
                {                	
                	tetris.acabaDeRotar = false;
                    tetris.colocarPalabra(i, posicionAleatoria);
                    tetris.coincidenPalabras(i, posicionAleatoria);
                    piezaActual.reiniciarRotacion();
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
                    gameOver = true;
                    break;
                }
                else if (tecla == 75)
                { // Tecla de flecha izquierda (código ASCII 75)
                    if (tetris.hayEspacioHorizontal(i - 1, posicionAleatoria, false))
                    {
                        tetris.borrarPalabra(i - 1, posicionAleatoria);
                        posicionAleatoria--;
                        tetris.colocarPalabra(i - 1, posicionAleatoria);
                    }
                }
                else if (tecla == 77)
                { // Tecla de flecha derecha (código ASCII 77)
                    if (tetris.hayEspacioHorizontal(i - 1, posicionAleatoria, true))
                    { // Verificar si no está en el borde derecho
                        tetris.borrarPalabra(i - 1, posicionAleatoria);
                        posicionAleatoria++;
                        tetris.colocarPalabra(i - 1, posicionAleatoria);
                    }
                }
                else if (tecla == 80)
                { // Tecla de flecha abajo (código ASCII 80)
                    tetris.borrarPalabra(i - 1, posicionAleatoria);
                    if (tetris.hayEspacioVacio(i, posicionAleatoria, gameOver))
                    {
                        tetris.colocarPalabra(i, posicionAleatoria);
                    }
                    else
                    {
                        tetris.colocarPalabra(i, posicionAleatoria);
                        tetris.coincidenPalabras(i, posicionAleatoria);
                        hayColision = true;
                    }
                    tetris.imprimirTablero();
                    tiempoUltimaActualizacion = std::chrono::high_resolution_clock::now();
                    i++;
                }
				else if (tecla == 32) //Tecla espacio (código ACII 32)
                {
                	tetris.rotarPalabra(i, posicionAleatoria);	
                	tetris.acabaDeRotar = true;
				}
				tetris.imprimirTablero();
            }
        }
        if (gameOver)
        {
            tetris.imprimirTablero();
            std::cout << std::endl;
            std::cout << "  ||MMMMMM  ||MMMMM  ||MM   MM  ||MMMMM " << std::endl;
            std::cout << " ||M        ||M ||M  ||M M M M  ||M     " << std::endl;
            std::cout << " ||M ||MMM  ||MMMMM  ||M  M  M  ||MMMM  " << std::endl;
            std::cout << " ||M   ||M  ||M ||M  ||M     M  ||M     " << std::endl;
            std::cout << "  ||MMMM    ||M ||M  ||M     M  ||MMMMM  " << std::endl;
            std::cout << std::endl;
            std::cout << "  ||MMMM   ||M   M  ||MMMMM  ||MMMMM    " << std::endl;
            std::cout << " ||M    M  ||M   M  ||M      ||M  ||M   " << std::endl;
            std::cout << " ||M    M  ||M   M  ||MMMM   ||MMMMM    " << std::endl;
            std::cout << " ||M    M  ||M   M  ||M      ||M  ||M   " << std::endl;
            std::cout << "  ||MMMM    ||MMM   ||MMMMM  ||M  ||M   "  << std::endl;
            std::cout << std::endl;
            std::cout << " || SCORE: " << tetris.getPuntaje() << std::endl;
            break;
        }
    }
    system("pause");
}