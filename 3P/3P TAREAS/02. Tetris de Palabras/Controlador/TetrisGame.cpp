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

#include "../Modelo/TetrisGame.h"
#include "../Modelo/NodoSimple.h"

#include "../Modelo/Singleton.h"
#include <fstream>
#include <algorithm>
#include <Windows.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       TetrisGame::TetrisGame()
// Purpose:    Constructor por defecto de la clase TetrisGame. Inicializa filas y columnas a 0.
// Parameters: Ninguno
// Return:     Ninguno
////////////////////////////////////////////////////////////////////////////////////////////////////////

TetrisGame::TetrisGame(): filas(0), columnas(0){

}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       TetrisGame::TetrisGame(int numRows, int numCols)
// Purpose:    Constructor de la clase TetrisGame que recibe el número de filas y columnas para inicializar
//             el tablero del juego y otras propiedades.
// Parameters:
// - numRows: Número de filas del tablero.
// - numCols: Número de columnas del tablero.
// Return:     Ninguno
////////////////////////////////////////////////////////////////////////////////////////////////////////

TetrisGame::TetrisGame(int numRows, int numCols) : filas(numRows), columnas(numCols) {	
	puntaje = 0;
	aumento = 5;
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


////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       TetrisGame::getPuntaje()
// Purpose:    Obtener el puntaje actual del juego.
// Parameters: Ninguno
// Return:     int - Puntaje actual del juego.
////////////////////////////////////////////////////////////////////////////////////////////////////////

int TetrisGame::getPuntaje(){
	return puntaje;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       TetrisGame::mostrarPiezaSiguiente(Pieza pieza)
// Purpose:    Mostrar en pantalla la próxima pieza que aparecerá en el juego.
// Parameters:
// - pieza: Pieza que se va a mostrar en pantalla.
// Return:     Ninguno
////////////////////////////////////////////////////////////////////////////////////////////////////////

void TetrisGame::mostrarPiezaSiguiente(Pieza pieza){
	limpiar(40,10);
    std::cout << pieza;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       TetrisGame::getPieza()
// Purpose:    Obtener una pieza aleatoria de la lista de piezas disponibles y configurar su rotación y columna.
// Parameters: Ninguno
// Return:     Pieza& - Referencia a la pieza seleccionada.
////////////////////////////////////////////////////////////////////////////////////////////////////////

Pieza& TetrisGame::getPieza() {
    Singleton* singleton = Singleton::getInstance();
    ListaSimple<Pieza>& piezas = singleton->getPiezas();
    int indiceAleatorio = rand() % 11;
    int rotacionAleatoria = (rand() % 2 == 0) ? 1 : 3; // Asigna 1 en un 50% de los casos y 3 en el otro 50%.
    int posicionAleatoria = rand() % (columnas - pieza.getPalabra().length() - 1) + 1;
    
    Pieza& piezaSeleccionada = piezas[indiceAleatorio];
    piezaSeleccionada.setRotacion(rotacionAleatoria); 
    piezaSeleccionada.setColumna(posicionAleatoria);
    return piezaSeleccionada;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       TetrisGame::setPieza(Pieza piezaActual)
// Purpose:    Configurar la pieza actual en el juego.
// Parameters:
// - piezaActual: La pieza que se va a configurar como pieza actual.
// Return:     Ninguno
////////////////////////////////////////////////////////////////////////////////////////////////////////

void TetrisGame::setPieza(Pieza piezaActual){
	pieza = piezaActual;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       TetrisGame::aumentarPuntaje()
// Purpose:    Aumentar el puntaje del juego y emitir un sonido.
// Parameters: Ninguno
// Return:     Ninguno
////////////////////////////////////////////////////////////////////////////////////////////////////////

void TetrisGame::aumentarPuntaje() {
	Beep(1500, 150);
	puntaje += aumento;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       TetrisGame::hayEspacioVacio(int fila, int columna, bool& gameOver)
// Purpose:    Verificar si hay espacio vacío en la siguiente posición para colocar una palabra.
// Parameters:
// - fila: Fila actual en el tablero.
// - columna: Columna actual en el tablero.
// - gameOver: Referencia booleana que indica si el juego ha terminado.
// Return:     bool - Indica si hay espacio vacío en la siguiente posición.
////////////////////////////////////////////////////////////////////////////////////////////////////////

bool TetrisGame::hayEspacioVacio(int fila, int columna, bool &gameOver){
	int longitud = pieza.getPalabra().length();
	
	if (pieza.getRotacion() == 1 || pieza.getRotacion() == 3) {
        for (int j = columna; j < columna + longitud; ++j)
	    {
	        if (tablero[fila + 1][j] != ' ')
	        {
	            if (tablero[fila + 1][j] == '@')// Para los bordes
	            {                
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
            if (tablero[fila - 2 + longitud][columna + 2] == ' ') {
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

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       TetrisGame::verificarParaRecorrerTablero(int fila)
// Purpose:    Verificar si una fila en el tablero está vacía y reorganizar el tablero si es necesario.
// Parameters:
// - fila: Fila a verificar en el tablero.
// Return:     void
////////////////////////////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       TetrisGame::coincidenPalabras(int fila, int columna)
// Purpose:    Verificar si las palabras adyacentes a una posición coinciden con la palabra actual y 
//             tomar medidas en consecuencia.
// Parameters:
// - fila: Fila de la posición en el tablero a verificar.
// - columna: Columna de la posición en el tablero a verificar.
// Return:     void
////////////////////////////////////////////////////////////////////////////////////////////////////////

void TetrisGame::coincidenPalabras(int fila, int columna) {
	std::string palabra = pieza.getPalabra();
    bool coincideAbajo = true;
    bool coincideAladoIzquierda = true;
    bool coincideAladoDerecha = true;
    
	if (pieza.getRotacion() == 1 || pieza.getRotacion() == 3) {
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
	        aumentarPuntaje();
	    } else if (coincideAladoIzquierda) {
	        borrarPalabra(fila, columna);
	        borrarPalabra(fila, columna - pieza.getPalabra().length());
	        aumentarPuntaje();
	        verificarParaRecorrerTablero(fila);
	    } else if (coincideAladoDerecha) {
	        borrarPalabra(fila, columna);
	        borrarPalabra(fila, columna +pieza.getPalabra().length());
	        aumentarPuntaje();
	        verificarParaRecorrerTablero(fila);
	    }
	    
	} else {
		if (fila + 2 + palabra.length() < filas) {
			for (int j = fila - 2; j < fila - 2 + palabra.length(); ++j) {
		        if (tablero[j][columna + 2] != tablero[j + palabra.length()][columna + 2]) {
		            coincideAbajo = false;
		            break;
		        }
			}
			
			if (coincideAbajo) {
		        borrarPalabra(fila, columna);
		        borrarPalabra(fila + palabra.length(), columna);
		        aumentarPuntaje();
		    }
		    
		}
			
		for (int j = fila - 2; j < fila - 2 + palabra.length(); ++j) { 
	        if (tablero[j][columna + 2] != tablero[j][columna + 1]) {
	            coincideAladoIzquierda = false;
	            break;
	        }
		}
		
		for (int j = fila - 2; j < fila - 2 + palabra.length(); ++j) { 
	        if (tablero[j][columna + 2] != tablero[j][columna + 3]) {
	            coincideAladoDerecha = false;
	            break;
	        }
		}
		
		if (coincideAladoIzquierda) {
	        borrarPalabra(fila, columna);
	        borrarPalabra(fila, columna - 1);
	        aumentarPuntaje();
	        verificarParaRecorrerTablero(fila);
	    }
		if (coincideAladoDerecha) {
	        borrarPalabra(fila, columna);
	        borrarPalabra(fila, columna + 1);
	        aumentarPuntaje();
	        verificarParaRecorrerTablero(fila);
	    }
	    	
	}
	
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       TetrisGame::hayEspacioHorizontal(int fila, int columna, bool derecha)
// Purpose:    Verificar si hay espacio horizontal disponible en la posición adyacente especificada,
//             considerando la dirección indicada (derecha o izquierda).
// Parameters:
// - fila: Fila de la posición en el tablero a verificar.
// - columna: Columna de la posición en el tablero a verificar.
// - derecha: Indicador de dirección (true para verificar hacia la derecha, false para la izquierda).
// Return:     bool - true si hay espacio disponible, false si hay palabras en la siguiente posición.
////////////////////////////////////////////////////////////////////////////////////////////////////////

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
		if(derecha) {
			for (int j = fila; j < fila + longitud; ++j) {            	
            	if(tablero[j][columna + 1] != ' '){
					return false;
				}
        	}        	        	
			
		}else {
			for (int j = fila; j < fila + longitud; ++j) {            	
            	if(tablero[j][columna - 1] != ' '){
					return false;
				}
        	}
        	        	
		}
		return true;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       TetrisGame::colocarPalabra(int fila, int columna)
// Purpose:    Colocar la palabra de la pieza actual en la posición especificada del tablero,
//             considerando su rotación. La palabra se coloca en la dirección horizontal o vertical
//             según la rotación.
// Parameters:
// - fila: Fila en la que se colocará la palabra en el tablero.
// - columna: Columna en la que se colocará la palabra en el tablero.
// Return:  void
// Remarks:    Si la rotación es 3 o 4, la palabra se invierte antes de colocarla.
////////////////////////////////////////////////////////////////////////////////////////////////////////

void TetrisGame::colocarPalabra(int fila, int columna){
    std::string palabra = pieza.getPalabra();
    if(pieza.getRotacion() == 3 || pieza.getRotacion() == 4) {
    	std::reverse(palabra.begin(), palabra.end());
	}

    if (pieza.getRotacion() == 1 || pieza.getRotacion() == 3) {
        for (int j = columna; j < columna + palabra.length(); ++j) {
            tablero[fila][j] = palabra[j - columna];
        }
    } else if (pieza.getRotacion() == 2 || pieza.getRotacion() == 4) {
        for (int i = fila - 2; i < fila + 3; i++) {
            tablero[i][columna + 2] = palabra[i - fila + 2];
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       TetrisGame::borrarPalabra(int fila, int columna)
// Purpose:    Borra la palabra de la pieza actual en la posición especificada del tablero,
//             considerando su rotación. La palabra se borra en la dirección horizontal o vertical
//             según la rotación.
// Parameters:
// - fila: Fila en la que se encuentra la palabra a borrar en el tablero.
// - columna: Columna en la que comienza la palabra a borrar en el tablero.
// Return:     void
// Remarks:    Si la rotación es 1 o 3 (horizontal), se reemplaza por espacios vacíos o arrobas en la
//             primera fila. Si la rotación es 2 o 4 (vertical), se reemplaza por espacios vacíos o arrobas
//             en la primera columna.
////////////////////////////////////////////////////////////////////////////////////////////////////////

void TetrisGame::borrarPalabra(int fila, int columna) {
    std::string palabra = pieza.getPalabra();
    if (pieza.getRotacion() == 1 || pieza.getRotacion() == 3) { // Palabra de forma horizontal
        for (int j = columna; j < columna + palabra.length(); ++j) {
            tablero[fila][j] = (fila == 0) ? '@' : ' '; // Reemplazar por arrobas en la primera fila
        }
    } else if (pieza.getRotacion() == 2 || pieza.getRotacion() == 4) { // Palabra de forma vertical
    	for (int j = fila - 2; j < fila + 3; ++j) {
            tablero[j][columna + 2] = (j == 0) ? '@' : ' '; // Reemplazar por arrobas en la primera fila
        }
		
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       TetrisGame::rotarPalabra(int fila, int columna)
// Purpose:    Intenta rotar la palabra de la pieza actual en la posición especificada del tablero,
//             considerando las limitaciones del tablero y las palabras adyacentes. La rotación puede
//             cambiar la orientación de la palabra en el tablero.
// Parameters:
// - fila: Fila en la que se encuentra la palabra a rotar en el tablero.
// - columna: Columna en la que comienza la palabra a rotar en el tablero.
// Remarks:    Se verifica si la rotación es posible sin colisionar con otras palabras en el tablero
//             y sin exceder los límites del tablero. Si la rotación es posible, se cambia la rotación
//             de la pieza actual. Se reproduce un tono de sonido si la rotación es exitosa.
// Returns:    void
////////////////////////////////////////////////////////////////////////////////////////////////////////

void TetrisGame::rotarPalabra(int fila, int columna){
	std::string palabra = pieza.getPalabra();
	//borrarPalabra(fila - 1, columna);
	bool sePuedeRotar = true;
	
	if (fila > 2 && fila < filas - 2 && columna > 0 && columna < columnas - 2) {
		for (int i = fila - 2; i < fila + 3; ++i) {
	        for (int j = columna; j < columna + palabra.length(); ++j) {
	            if (tablero[i][j] != ' ') {
	            	if (pieza.getRotacion() == 1 || pieza.getRotacion() == 3) { // Palabra de forma horizontal
						if (j == columna + 2) {
							sePuedeRotar = false;
						}
				    } else if (pieza.getRotacion() == 2 || pieza.getRotacion() == 4) { // Palabra de forma vertical
						if (i == fila) {
							sePuedeRotar = false;
						}
						
				    }
				}
	        }   	
				
	    }
	} else {
		sePuedeRotar = false;
	}
	
	if (sePuedeRotar) {
		Beep(800, 50);
		if (pieza.getRotacion() == 4){    
			pieza.setRotacion(1);
		}else{
			pieza.setRotacion(pieza.getRotacion() + 1);
		}
	}

}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       TetrisGame::imprimirTablero()
// Purpose:    Imprime en la consola el tablero de juego con las palabras colocadas y los bordes.
// Remarks:    Itera a través de cada celda en el tablero y muestra el carácter correspondiente.
// Returns:    void
////////////////////////////////////////////////////////////////////////////////////////////////////////

void TetrisGame::imprimirTablero()
{
	limpiar(0,0);
    for (int i = 0; i < filas; ++i)
    {
    	
        for (int j = 0; j < columnas; ++j)
        {
            std::cout << tablero[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       TetrisGame::limpiar(int x, int y)
// Purpose:    Limpia la consola moviendo el cursor a la posición especificada.
// Parameters: int x - Coordenada X a la que se moverá el cursor.
//             int y - Coordenada Y a la que se moverá el cursor.
// Remarks:    Utiliza la función SetConsoleCursorPosition para cambiar la posición del cursor en la consola.
// Returns:    void
////////////////////////////////////////////////////////////////////////////////////////////////////////

void TetrisGame::limpiar(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       TetrisGame::obtenerPiezas()
// Purpose:    Lee las palabras desde un archivo de texto y las agrega a la lista de piezas disponibles.
// Parameters: Ninguno.
// Remarks:    Abre el archivo "Palabras.txt" y lee cada palabra del archivo.
//             Si la palabra tiene 5 caracteres, se agrega a la lista de piezas disponibles.
//             Si la palabra tiene una longitud diferente, se muestra un mensaje de ignorar.
// Returns:    void
////////////////////////////////////////////////////////////////////////////////////////////////////////

void TetrisGame::obtenerPiezas(){
    std::ifstream archivo("Palabras.txt"); // Abre el archivo de texto
	Singleton* singleton = Singleton::getInstance();
	ListaSimple<Pieza>& piezas = singleton->getPiezas();
	
    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
    }
    
    std::string palabra;
	
    while (std::getline(archivo, palabra)) {
        // Verifica si la palabra tiene 5 caracteres
        if (palabra.size() == 5) {
            piezas.insertarAlFinal(Pieza(palabra)); // Inserta la palabra en la ListaSimple
        } else {
            std::cout << "Palabra ignorada: " << palabra << " (no tiene 5 letras)" << std::endl;
        }
    }

    archivo.close(); // Cierra el archivo
}