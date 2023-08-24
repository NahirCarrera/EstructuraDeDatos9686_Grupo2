/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Estructura de Datos 9686
 * Nombres: Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 12/08/23 19:40
 * Fecha de modificacion: 12/08/23 19:40
 * Enunciado:
 * Realizar el juego del tetris con palabras en consola (Solo caida horizontal)
 * EXTRA: Realizar la rotación de las piezas
 *******************************************************************************/

#include "../Modelo/Juego.h"
#include "ListaSimple.cpp"
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <Windows.h>
#include <thread>

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       Juego::ocultarCursor()
// Purpose:    Ocultar el cursor de la consola
// Return:     void
////////////////////////////////////////////////////////////////////////////////////////////////////////

void Juego::ocultarCursor() {
	//Ocular el cursor de la consola
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = false; // Oculta el cursor
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       Juego::Juego()
// Purpose:    Constructor de la clase Juego. Inicializa el juego ocultando el cursor,
//             estableciendo el número de filas y columnas, y obteniendo las piezas del Tetris.
// Return:     
////////////////////////////////////////////////////////////////////////////////////////////////////////

Juego::Juego() {
	ocultarCursor();
	this->filas = 35 + 2;
    this->columnas = 10 + 2;
	this->tetris = TetrisGame(filas, columnas);;
	tetris.obtenerPiezas();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       playTone(int frequency, int duration)
// Purpose:    Reproduce un tono utilizando el altavoz del sistema a una frecuencia y duración específicas.
// Parameters:
// - frequency: Frecuencia del tono en hercios (Hz)
// - duration: Duración del tono en milisegundos (ms)
// Return:     void
////////////////////////////////////////////////////////////////////////////////////////////////////////

void playTone(int frequency, int duration) {
    Beep(frequency, duration);
    Sleep(duration); // Pausa para permitir que el tono se reproduzca completamente
}

bool isPlayingMusic = true;

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       playTetrisTheme()
// Purpose:    Reproduce la melodía del tema de Tetris utilizando el altavoz del sistema.
//             La melodía está definida por un arreglo de frecuencias y duraciones.
//             El método continuará reproduciendo la melodía hasta que se establezca
//             isPlayingMusic como falso.
// Return:     void
////////////////////////////////////////////////////////////////////////////////////////////////////////

void playTetrisTheme() {
	isPlayingMusic = true;
	double tones[]= {659.25511, 493.8833, 523.25113, 587.32954, 523.25113, 493.8833, 440.0, 440.0, 
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
		for (int i = 0; i < sizeof(tones)/sizeof(tones[0]); i++) {
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

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       playGameOverTheme()
// Purpose:    Reproduce una secuencia de tonos que se utiliza como efecto de sonido de "Game Over".
//             La secuencia está definida por arreglos de frecuencias y duraciones.
// Return:     void
////////////////////////////////////////////////////////////////////////////////////////////////////////

void playGameOverTheme() {
    // Definir la secuencia de tonos y duraciones (frecuencia en Hz, duración en milisegundos)
    double tones[] = {440, 330, 293, 349, 293, 261};
	double durations[] = {150, 150, 150, 350, 350, 700};
    // Reproducir la secuencia de tonos
    for (int i = 0; i < sizeof(tones) / sizeof(tones[0]); i++) {
        playTone(tones[i], durations[i]);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       Juego::pantallaInstrucciones()
// Purpose:    Muestra en pantalla las instrucciones y controles del juego, así como el arte del título.
// Return:     void
////////////////////////////////////////////////////////////////////////////////////////////////////////

void Juego::pantallaInstrucciones(){
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
	std::cout << "|           FLECHA ARRIBA :       ROTAR LA PIEZA          |" << std::endl;
	std::cout << "|           SPACE         :      PAUSAR EL JUEGO          |" << std::endl;
	std::cout << "|           ESC           :    TERMINAR EL JUEGO          |" << std::endl;
	std::cout << "|---------------------------------------------------------|" << std::endl;
	std::cout << "             >>> Presiona Enter para iniciar..." << std::endl;
    std::cin.get();
    system("cls");
    pantallaInicio();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       Juego::pantallaInicio()
// Purpose:    Muestra en pantalla el arte del título durante del juego.
// Return:     void
////////////////////////////////////////////////////////////////////////////////////////////////////////

void Juego::pantallaInicio() {
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

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       Juego::pantallaScore(int nivel, int score, Pieza piezaSiguiente)
// Purpose:    Muestra en pantalla la información de nivel, puntaje y la siguiente pieza a jugar.
// Parameters:
// - nivel: Nivel actual del juego
// - score: Puntaje actual del juego
// - piezaSiguiente: Siguiente pieza que aparecerá en el juego
// Return:     void
////////////////////////////////////////////////////////////////////////////////////////////////////////

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
    std::cout << "       "<<score;
    tetris.limpiar(24,23);
	std::cout << " --------------- ";
	tetris.limpiar(24,36);
	std::cout << "|||||||||||||||||";
}

/////////////////////////////////////////////////////////////////////////////////////////////
// Name:       Juego::ejecutar(int nivel, int intervaloActualizacion)
// Purpose:    Inicia la ejecución del juego Tetris en el nivel y con el intervalo de actualización
//             especificados.
// Parameters: nivel - Nivel de dificultad del juego.
//             intervaloActualizacion - Intervalo de tiempo entre actualizaciones de la partida.
// Remarks:    Este método maneja el ciclo principal del juego. Crea una instancia de Tetris y
//             Pieza, y comienza a iterar para mover y actualizar la pieza en el tablero. Verifica
//             constantemente las teclas presionadas para mover o rotar la pieza, y controla la pausa.
//             Al finalizar el juego, muestra el puntaje y una pantalla de Game Over.
// Returns:    void
/////////////////////////////////////////////////////////////////////////////////////////////

void Juego::ejecutar(int nivel, int intervaloActualizacion) {
	srand(time(NULL));
    bool gameOver = false;
	pantallaInstrucciones();
    auto tiempoUltimaActualizacion = std::chrono::high_resolution_clock::now();
    std::thread musicThread(playTetrisTheme);
    Pieza& piezaSiguiente = tetris.getPieza();
    Pieza piezaActual;
    bool pausa = false;
    int contadorPuntajeDoble = 0;
    while (true){
    	piezaActual = piezaSiguiente; // Crear una nueva instancia de Pieza en cada iteración
    	tetris.setPieza(piezaActual);
    	piezaSiguiente = tetris.getPieza();
    	pantallaScore(nivel,tetris.getPuntaje(), piezaSiguiente);
	    int posicionAleatoria = rand() % (columnas - piezaActual.getPalabra().length() - 1) + 1;
	    int i = 1;
	    bool hayColision = false;
	    contadorPuntajeDoble++;
		while (!hayColision)
        {
    		auto tiempoActual = std::chrono::high_resolution_clock::now();
            auto duracionDesdeUltimaActualizacion = std::chrono::duration_cast<std::chrono::milliseconds>(tiempoActual - tiempoUltimaActualizacion).count();

			
			if (duracionDesdeUltimaActualizacion >= intervaloActualizacion){
                tetris.borrarPalabra(i - 1, posicionAleatoria);
                if (tetris.hayEspacioVacio(i, posicionAleatoria, gameOver)){
                    tetris.colocarPalabra(i, posicionAleatoria);
                }
                else
                {                	
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
				else if (tecla == 72) //Tecla flecha arriba (código ASCII 24)
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
				else if (tecla == 32) // Tecla espacio (código ASCII 32)
			    {	pausa = true; // Cambiar el estado de pausa al presionar la tecla de espacio
					while(pausa){	
			        	tetris.limpiar(1,15);
			        	std::cout << "------------------------------------------------------";
			        	tetris.limpiar(1, 16);
			        	std::cout << "|           MMMM   MMMM  M  M   MMMM   MMMM           |"; 
						tetris.limpiar(1, 17); 
			        	std::cout << "|           M   M  M  M  M  M  M       M              |";
			        	tetris.limpiar(1, 18);
			        	std::cout << "|           MMMM   MMMM  M  M   MMMM   MMM            |";
			        	tetris.limpiar(1, 19);
			        	std::cout << "|           M      M  M  M  M       M  M              |";
			        	tetris.limpiar(1, 20);
			        	std::cout << "|           M      M  M  MMMM   MMMM   MMMM           |";
			        	tetris.limpiar(1, 21);
			        	std::cout << "------------------------------------------------------";
			        	char tecla = _getch();
			        	if (tecla == 32) {
			        		pausa = false;
			        		system("cls");
			        		pantallaInicio();
			        		pantallaScore(nivel, tetris.getPuntaje(),piezaSiguiente);
			        		break;
						}
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