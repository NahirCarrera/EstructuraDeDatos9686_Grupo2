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
#include <thread>

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
	this->filas = 35 + 2;
    this->columnas = 10 + 2;
	this->tetris = TetrisGame(filas, columnas);;
	tetris.obtenerPiezas();

}

void playTone(int frequency, int duration) {
    Beep(frequency, duration);
    Sleep(duration); // Pausa para permitir que el tono se reproduzca completamente
}
bool isPlayingMusic = true;

void playTetrisTheme() {
	isPlayingMusic = true;
    double tones[] = {659.25511, 493.8833, 523.25113, 587.32954, 523.25113, 493.8833, 440.0, 440.0, 
    523.25113, 659.25511, 587.32954, 523.25113, 493.8833, 523.25113, 587.32954, 
    659.25511, 523.25113, 440.0, 440.0, 440.0, 493.8833, 523.25113, 587.32954, 
    698.45646, 880.0, 783.99087, 698.45646, 659.25511, 523.25113, 659.25511, 
    587.32954, 523.25113, 493.8833, 493.8833, 523.25113, 587.32954, 659.25511, 
    523.25113, 440.0, 440.0};

    double durations[] = {203.125, 101.563, 101.563, 203.125, 101.563, 101.563, 203.125, 101.563,
                          101.563, 203.125, 101.563, 101.563, 304.688, 101.563, 203.125, 203.125,
                          203.125, 203.125, 101.563, 101.563, 101.563, 101.563, 304.688, 101.563,
                          203.125, 101.563, 101.563, 304.688, 101.563, 203.125, 101.563, 101.563,
                          203.125, 101.563, 101.563, 203.125, 203.125, 203.125, 203.125, 203.125};
	while(isPlayingMusic){
		for (int i = 0; i < sizeof(tones) / sizeof(tones[0]); ++i) {
	        if(!isPlayingMusic){
	        	break;
			}
			if (tones[i] != 0) {
	            playTone(tones[i], durations[i]);
	        } else {
	            Sleep(durations[i]); // Pausa para los silencios
	        }
	    }
	}
}

void playGameOverTheme() {
    // Definir la secuencia de tonos y duraciones (frecuencia en Hz, duración en milisegundos)
    int tones[] = {440, 330, 293, 349, 293, 261};
    int durations[] = {150, 150, 150, 350, 350, 700};


    // Reproducir la secuencia de tonos
    for (int i = 0; i < sizeof(tones) / sizeof(tones[0]); ++i) {
        playTone(tones[i], durations[i]);
    }
}

void Juego::pantallaInicio() {
	std::cout << "|---------------------------------------------------------|" << std::endl;
	std::cout << "| ||MMMMMMM ||MMMMM ||MMMMMMM   ||MMMMMM   ||M   ||MMMMM  |" << std::endl;
	std::cout << "|    ||M    ||M        ||M      ||M   ||M  ||M  ||M       |" << std::endl;
	std::cout << "|    ||M    ||MMM      ||M      ||MMMMMM   ||M   ||MMMM   |" << std::endl;
	std::cout << "|    ||M    ||M        ||M      ||M   ||M  ||M       ||M  |" << std::endl;
	std::cout << "|    ||M    ||MMMMM    ||M      ||M   ||M  ||M   ||MMMM   |" << std::endl;
	std::cout << "|---------------------------------------------------------|" << std::endl;
	std::cout << "|                     <<< CONTROLES >>>                   |" << std::endl;
	std::cout << "|           FLECHA <- IZ  : MOVER A LA IZQUIERDA          |" << std::endl;
	std::cout << "|           FLECHA -> DER :   MOVER A LA DERECHA          |" << std::endl;
	std::cout << "|           FLECHA ABAJO  :      CAER MAS RAPIDO          |" << std::endl;
	std::cout << "|           SPACE         :       ROTAR LA PIEZA          |" << std::endl;
	std::cout << "|           ESC           :    TERMINAR EL JUEGO          |" << std::endl;
	std::cout << "|---------------------------------------------------------|" << std::endl;
	std::cout << "             >>> Presiona Enter para iniciar..." << std::endl;
    std::cin.get();
    system("cls");
    int columna = 42; // Variable para definir la columna
	int fila = 0; // Variable para definir la fila
	tetris.limpiar(columna, fila);
	std::cout << "||||||||||||||";
	tetris.limpiar(columna, fila + 1);
	std::cout << "| ||MMMMMMM  |";
	tetris.limpiar(columna, fila + 2);
	std::cout << "|    ||M     |";
	tetris.limpiar(columna, fila + 3);
	std::cout << "|    ||M     |";
	tetris.limpiar(columna, fila + 4);
	std::cout << "|    ||M     |";
	tetris.limpiar(columna, fila + 5);
	std::cout << "|    ||M     |";
	tetris.limpiar(columna, fila + 6);
	std::cout << "|            |";
	tetris.limpiar(columna, fila + 7);
	std::cout << "|  ||MMMMM   |";
	tetris.limpiar(columna, fila + 8);
	std::cout << "|  ||M       |";
	tetris.limpiar(columna, fila + 9);
	std::cout << "|  ||MMM     |";
	tetris.limpiar(columna, fila + 10);
	std::cout << "|  ||M       |";
	tetris.limpiar(columna, fila + 11);
	std::cout << "|  ||MMMMM   |";
	tetris.limpiar(columna, fila + 12);
	std::cout << "|            |";
	tetris.limpiar(columna, fila + 13);
	std::cout << "| ||MMMMMMM  |";
	tetris.limpiar(columna, fila + 14);
	std::cout << "|    ||M     |";
	tetris.limpiar(columna, fila + 15);
	std::cout << "|    ||M     |";
	tetris.limpiar(columna, fila + 16);
	std::cout << "|    ||M     |";
	tetris.limpiar(columna, fila + 17);
	std::cout << "|    ||M     |";
	tetris.limpiar(columna, fila + 18);
	std::cout << "|            |";
	tetris.limpiar(columna, fila + 19);
	std::cout << "| ||MMMMMM   |";
	tetris.limpiar(columna, fila + 20);
	std::cout << "| ||M   ||M  |";
	tetris.limpiar(columna, fila + 21);
	std::cout << "| ||MMMMMM   |";
	tetris.limpiar(columna, fila + 22);
	std::cout << "| ||M   ||M  |";
	tetris.limpiar(columna, fila + 23);
	std::cout << "| ||M   ||M  |";
	tetris.limpiar(columna, fila + 24);
	std::cout << "|            |";
	tetris.limpiar(columna, fila + 25);
	std::cout << "|    ||M     |";
	tetris.limpiar(columna, fila + 26);
	std::cout << "|    ||M     |";
	tetris.limpiar(columna, fila + 27);
	std::cout << "|    ||M     |";
	tetris.limpiar(columna, fila + 28);
	std::cout << "|    ||M     |";
	tetris.limpiar(columna, fila + 29);
	std::cout << "|    ||M     |";
	tetris.limpiar(columna, fila + 30);
	std::cout << "|            |";
	tetris.limpiar(columna, fila + 31);
	std::cout << "|  ||MMMMM   |";
	tetris.limpiar(columna, fila + 32);
	std::cout << "| ||M        |";
	tetris.limpiar(columna, fila + 33);
	std::cout << "|  ||MMMM    |";
	tetris.limpiar(columna, fila + 34);
	std::cout << "|       ||M  |";
	tetris.limpiar(columna, fila + 35);
	std::cout << "|  ||MMMM    |";
	tetris.limpiar(columna, fila + 36);
	std::cout << "||||||||||||||";
}
void Juego::pantallaScore(int nivel, int score, Pieza piezaSiguiente) {
	tetris.limpiar(24,0);
	std::cout << "|||||||||||||||||";
	tetris.limpiar(24,10);
	std::cout << " --------------- ";
	tetris.limpiar(24,11);
	std::cout << "|     LEVEL     |";
	tetris.limpiar(24,12);
    std::cout << "|       "<<nivel <<"       |";
    tetris.limpiar(24,13);
	std::cout << " --------------- ";
	tetris.limpiar(24,15);
	std::cout << " --------------- ";
	tetris.limpiar(24,16);
	std::cout << "|     NEXT:     |";
	tetris.limpiar(24,17);
    std::cout << "|     "<<piezaSiguiente <<"     |";
    tetris.limpiar(24,18);
	std::cout << " --------------- ";
	tetris.limpiar(24,20);
	std::cout << " --------------- ";
	tetris.limpiar(24,21);
	std::cout << "|     SCORE     |";
	tetris.limpiar(24,22);
    std::cout << "        "<<score;
    tetris.limpiar(24,23);
	std::cout << " --------------- ";
	tetris.limpiar(24,36);
	std::cout << "|||||||||||||||||";
	
}
void Juego::ejecutar(int nivel, int intervaloActualizacion) {
	srand(time(NULL));
	
    bool gameOver = false;
	
	pantallaInicio();
    auto tiempoUltimaActualizacion = std::chrono::high_resolution_clock::now();
    std::thread musicThread(playTetrisTheme);
    Pieza& piezaSiguiente = tetris.getPieza();
    Pieza piezaActual;
    while (true){
    	piezaActual = piezaSiguiente; // Crear una nueva instancia de Pieza en cada iteración
    	tetris.setPieza(piezaActual);
    	piezaSiguiente = tetris.getPieza();
    	pantallaScore(nivel,tetris.getPuntaje(), piezaSiguiente);
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
                	tetris.borrarPalabra(i - 1, posicionAleatoria);
                	tetris.rotarPalabra(i - 1, posicionAleatoria);
                	tetris.colocarPalabra(i - 1, posicionAleatoria);
                	
					if (!tetris.hayEspacioVacio(i - 1, posicionAleatoria, gameOver))
                    {
                    	tetris.coincidenPalabras(i - 1, posicionAleatoria);
                        hayColision = true;
                    }
                    
				}
				tetris.imprimirTablero();
            }
        }
        
        if (gameOver)
        {
        	isPlayingMusic = false;
        	musicThread.join();
        	std::thread gameOverMusicThread(playGameOverTheme);
            gameOverMusicThread.join();
            tetris.imprimirTablero();
            std::cout << std::endl;
            std::cout << "        ||MMMMMM  ||MMMMM  ||MM   MM  ||MMMMM " << std::endl;
            std::cout << "       ||M        ||M ||M  ||M M M M  ||M     " << std::endl;
            std::cout << "       ||M ||MMM  ||MMMMM  ||M  M  M  ||MMMM  " << std::endl;
            std::cout << "       ||M   ||M  ||M ||M  ||M     M  ||M     " << std::endl;
            std::cout << "        ||MMMM    ||M ||M  ||M     M  ||MMMMM  " << std::endl;
            std::cout << std::endl;
            std::cout << "        ||MMMM   ||M   M  ||MMMMM  ||MMMMM    " << std::endl;
            std::cout << "       ||M    M  ||M   M  ||M      ||M  ||M   " << std::endl;
            std::cout << "       ||M    M  ||M   M  ||MMMM   ||MMMMM    " << std::endl;
            std::cout << "       ||M    M  ||M   M  ||M      ||M  ||M   " << std::endl;
            std::cout << "        ||MMMM    ||MMM   ||MMMMM  ||M  ||M   "  << std::endl;
            std::cout << std::endl;
            std::cout << "                 ||SCORE: " << tetris.getPuntaje() << std::endl;
            break;
        }
    }
    system("pause");
}