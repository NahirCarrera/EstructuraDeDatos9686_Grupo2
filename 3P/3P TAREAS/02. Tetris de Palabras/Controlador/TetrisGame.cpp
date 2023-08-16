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

#include "../Modelo/TetrisGame.h"
#include "../Modelo/NodoSimple.h"

#include "../Modelo/Singleton.h"
#include <fstream>
#include <algorithm>

TetrisGame::TetrisGame(): filas(0), columnas(0){

}

TetrisGame::TetrisGame(int numRows, int numCols) : filas(numRows), columnas(numCols) {	
	puntaje = 0;
	acabaDeRotar = false;
	tablero = std::vector<std::vector<char>>(numRows, std::vector<char>(numCols, ' '));
    for (int i = 0; i < filas; ++i)
    {
        for (int j = 0; j < columnas; ++j)
        {
            if (i == 0 || i == filas - 1 || j == 0)
            {
                tablero[i][j] = '@';
            }
            else
            {
                if (j != columnas - 1)
                {
                    tablero[i][j] = ' ';
                }
                else
                {
                    tablero[i][j] = '@';
                }
            }
        }
    }
}


int TetrisGame::getPuntaje(){
	return puntaje;
}

Pieza& TetrisGame::getPieza() {
    Singleton* singleton = Singleton::getInstance();
    ListaSimple<Pieza>& piezas = singleton->getPiezas();
    int indiceAleatorio = rand() % 5;
    int rotacionAleatoria = (rand() % 2 == 0) ? 1 : 3; // Asigna 1 en un 50% de los casos y 3 en el otro 50%.
    int posicionAleatoria = rand() % (columnas - pieza.getPalabra().length() - 1) + 1;
    
    Pieza& piezaSeleccionada = piezas[indiceAleatorio];
    piezaSeleccionada.setRotacion(rotacionAleatoria); 
    piezaSeleccionada.setColumna(posicionAleatoria);
    pieza = piezaSeleccionada; // Obtener referencia al objeto
    std::cout << "Pieza " << pieza << std::endl;
    return pieza;
}

void TetrisGame::setPieza(Pieza piezaActual){
	pieza = Pieza(piezaActual.getPalabra());
}
void TetrisGame::aumentarPuntaje(int aumento) {
	puntaje += aumento;
}

bool TetrisGame::hayEspacioVacio(int fila, int columna, bool &gameOver){
	int longitud = pieza.getPalabra().length();
	
	if (pieza.getRotacion() == 1 || pieza.getRotacion() == 3) {
        for (int j = columna; j < columna + longitud; ++j)
	    {
	        if (tablero[fila + 1][j] != ' ')
	        {
	            if (tablero[fila + 1][j] == '@')
	            {                // Para los bordes
	                return false; // Es la ultima fila
	            }
	            else
	            {
	                if (fila == 1)
	                {
	                    gameOver = true; // Si está en el tope superior y ya no puede avanzar
	                }
	                return false; // Hay una palabra en esta posición
	            }
	        }
	    }
    	return true; // No hay palabras en la siguiente posicion
    } else if (pieza.getRotacion() == 2 || pieza.getRotacion() == 4) {
    	if (fila - 2 + longitud < filas) { // Verificar si está dentro de los límites del tablero
            if (tablero[fila - 2 + longitud][columna] == ' ') {
                return true; // Hay un espacio vacío en la posición siguiente
            } else {
                return false; // No hay espacio vacío en la posición siguiente
            }
        } else {
            return false; // Está fuera de los límites inferiores del tablero
        }
    	
    }
	return true;
}

void TetrisGame::verificarParaRecorrerTablero(int fila) {
    bool filaVacia = true; // Suponemos inicialmente que la fila está vacía
    for(int j = 1; j < columnas - 1; j++){
        if(tablero[fila][j] != ' '){
            filaVacia = false; // Si encontramos un carácter distinto de espacio, la fila no está vacía
            break;
        }
    }

    if(filaVacia){
        for(int i = fila; i > 1; i--){
            for(int j = 1; j < columnas - 1; j++){
                tablero[i][j] = tablero[i - 1][j];
            }
        }

        for(int j = 1; j < columnas - 1; j++){
            tablero[1][j] = ' '; // Rellenamos la fila superior con espacios en blanco
        }
    }
}

void TetrisGame::coincidenPalabras(int fila, int columna) {
	std::string palabra = pieza.getPalabra();
    bool coincideAbajo = true;
    bool coincideAladoIzquierda = true;
    bool coincideAladoDerecha = true;

	for (int j = columna; j < columna + palabra.length(); ++j) {
        if (tablero[fila][j] != tablero[fila + 1][j]) {
            coincideAbajo = false;
            break;
        }
    }
	
	for (int j = columna; j < columna + palabra.length(); ++j) {
        if (tablero[fila][j] != tablero[fila][j - palabra.length()]) {
            coincideAladoIzquierda = false;
            break;
        }
    }

    for (int j = columna; j < columna + palabra.length(); ++j) {
        if (tablero[fila][j] != tablero[fila][j + palabra.length()]) {
            coincideAladoDerecha = false;
            break;
        }
    }

    if (coincideAbajo) {
        borrarPalabra(fila, columna);
        borrarPalabra(fila + 1, columna);
        aumentarPuntaje(pieza.getPalabra().length());
    } else if (coincideAladoIzquierda) {
        borrarPalabra(fila, columna);
        borrarPalabra(fila, columna - pieza.getPalabra().length());
        aumentarPuntaje(pieza.getPalabra().length());
        verificarParaRecorrerTablero(fila);
    } else if (coincideAladoDerecha) {
        borrarPalabra(fila, columna);
        borrarPalabra(fila, columna +pieza.getPalabra().length());
        aumentarPuntaje(pieza.getPalabra().length());
        verificarParaRecorrerTablero(fila);
    }
}


bool TetrisGame::hayEspacioHorizontal(int fila, int columna, bool derecha) {
	int longitud = pieza.getPalabra().length();
	if(pieza.getRotacion() == 1 || pieza.getRotacion() == 3){
		if (derecha) {
			if(tablero[fila][columna + longitud] == ' ') {
				return true;
			}	
		} else {
			if(tablero[fila][columna - 1] == ' ' ) {
				return true;
			}
		}
	
	    return false; // hay palabras en la siguiente posicion
	}else if (pieza.getRotacion() == 2 || pieza.getRotacion() == 4){
		fila = fila - 2;
		columna = columna + 2;
		if(derecha){
			if(tablero[fila][columna + 1] == ' '){
				return true;
			}
		}else{
			if(tablero[fila][columna - 1] == ' '){
				return true;
			}
		}
		return false;
	}
}

void TetrisGame::colocarPalabra(int fila, int columna){
    std::string palabra = pieza.getPalabra();
    if(pieza.getRotacion() == 3 || pieza.getRotacion() == 4){
    	std::reverse(palabra.begin(), palabra.end());
	}

    if (pieza.getRotacion() == 1 || pieza.getRotacion() == 3) {
        for (int j = columna; j < columna + palabra.length(); ++j) {
            tablero[fila][j] = palabra[j - columna];
        }
    } else if (pieza.getRotacion() == 2 || pieza.getRotacion() == 4) {
        for (int i = fila - 2; i < fila + 3; ++i) {
            tablero[i][columna + 2] = palabra[i - fila + 2];
        }
    }
}

void TetrisGame::borrarPalabra(int fila, int columna) {
    std::string palabra = pieza.getPalabra();
    if (pieza.getRotacion() == 1 || pieza.getRotacion() == 3) { // Palabra de forma horizontal
        if(acabaDeRotar){
	        for (int i = fila - 2; i < fila + palabra.length() - 2; ++i) {
	            for (int j = columna; j < columna + palabra.length(); ++j) {
	                tablero[i][j] = (i == 0) ? '@' : ' '; // Reemplazar por arrobas en la primera fila de cada letra
	            }
	        }	
		}else{
			for (int j = columna; j < columna + palabra.length(); ++j) {
	            tablero[fila][j] = (fila == 0) ? '@' : ' '; // Reemplazar por arrobas en la primera fila
	        }
		}
		
    } else if (pieza.getRotacion() == 2 || pieza.getRotacion() == 4) { // Palabra de forma vertical
    	if(acabaDeRotar){
			if(columna + 2 == columnas){ //la columna es el borde derecho del tablero
	    		for(int j = columna; j < 3; j++){
	    			tablero[fila][j] = ' ';
				}
			}else if (columna + 3 == columnas){ //La columna a la derecha es el borde del tablero
				for(int j = columna; j < 3; j++){
					tablero[fila][j] = ' ';
				}
				tablero[fila][columna + 3] = ' ';
			
			}else if(columna + 1 == 1){ //la columna a la izquierda es el borde del tablero
				tablero[fila][columna + 1] = ' ';
				for(int j = columna + 3; j < 3; j++){
	    			tablero[fila][j] = ' ';
				}
			}else if (columna + 2 == 1){ //La columna es el borde izquierdo del tablero
				for(int j = columna + 3; j < 3; j++){
					tablero[fila][j] = ' ';
				}
			}else {
				for (int i = fila - 2; i < fila + palabra.length() - 2; ++i) { //
		            for (int j = columna; j < columna + palabra.length(); ++j) {
		                tablero[i][j] = (i == 0) ? '@' : ' '; // Reemplazar por arrobas en la primera fila de cada letra
		            }
		        }
			}
	    } else {
	        for (int i = fila - 2; i < fila + palabra.length() - 2; ++i) {
	            for (int j = columna; j < columna + palabra.length(); ++j) {
	                tablero[i][j] = (i == 0) ? '@' : ' '; // Reemplazar por arrobas en la primera fila de cada letra
	            }
	        }
	    }
	}

}


/*void TetrisGame::borrarPalabra(int fila, int columna) {
    std::string palabra = pieza.getPalabra();
    if (pieza.getRotacion() == 1 || pieza.getRotacion() == 3) { // Palabra de forma horizontal
        for (int j = columna; j < columna + palabra.length(); ++j) {
            tablero[fila][j] = (fila == 0) ? '@' : ' '; // Reemplazar por arrobas en la primera fila
        }
    } else if (pieza.getRotacion() == 2 || pieza.getRotacion() == 4) { // Palabra de forma vertical
    	for (int i = fila - 2; i < fila + palabra.length() - 2; ++i) { //
            for (int j = columna; j < columna + palabra.length(); ++j) {
                tablero[i][j] = (i == 0) ? '@' : ' '; // Reemplazar por arrobas en la primera fila de cada letra
            }
        }
		if(columna + 2 == columnas){ //la columna es el borde derecho del tablero
    		for(int j = columna; j < 3; j++){
    			tablero[fila][j] = ' ';
			}
			tablero[fila][columna + 3] = '@';
		}else if (columna + 3 == columnas){ //La columna a la derecha es el borde del tablero
			for(int j = columna; j < 3; j++){
				tablero[fila][j] = ' ';
			}
			tablero[fila][columna + 3] = ' ';
			tablero[fila][columna + 4] = '@';
		
		}else if(columna + 1 == 1){ //la columna a la izquierda es el borde del tablero	
			tablero[fila][columna + 1] = ' ';
			for(int j = columna + 3; j < 3; j++){
    			tablero[fila][j] = ' ';
			}
		}else if (columna + 2 == 1){ //La columna es el borde izquierdo del tablero
			for(int j = columna + 3; j < 3; j++){
				tablero[fila][j] = ' ';
			}
		}else {
			
		}
    }
}*/
void TetrisGame::rotarPalabra(int fila, int columna){
	std::string palabra = pieza.getPalabra();
	//borrarPalabra(fila - 1, columna);
	if (pieza.getRotacion() == 4){    
		pieza.setRotacion(1);
	}else{
		pieza.setRotacion(pieza.getRotacion() + 1);
	}
	
}

void TetrisGame::imprimirTablero()
{
	limpiar();
	std::cout << "> SCORE: "<<puntaje<< std::endl;
    for (int i = 0; i < filas; ++i)
    {
    	
        for (int j = 0; j < columnas; ++j)
        {
            std::cout << tablero[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
}

void TetrisGame::limpiar()
{
    COORD coord;
    coord.X = 0;
    coord.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void TetrisGame::obtenerPiezas(){
    std::ifstream archivo("Palabras.txt"); // Abre el archivo de texto
	Singleton* singleton = Singleton::getInstance();
	ListaSimple<Pieza>& piezas = singleton->getPiezas();
	
    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
    }
    
    std::string palabra;
    int contador = 0;
	
    while (std::getline(archivo, palabra) && contador < 5) {
        // Verifica si la palabra tiene 5 caracteres
        if (palabra.size() == 5) {
            piezas.insertarAlFinal(Pieza(palabra)); // Inserta la palabra en la ListaSimple

            contador++;
        } else {
            std::cout << "Palabra ignorada: " << palabra << " (no tiene 5 letras)" << std::endl;
        }
    }

    archivo.close(); // Cierra el archivo
}