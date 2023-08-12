#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <cstdlib> // Necesario para usar funciones de generación de números aleatorios	
#include <ctime>   // Necesario para obtener el tiempo actual
class TetrisGame {
private:
    const int filas;
    const int columnas;
    std::vector<std::vector<char>> tablero;

public:
    TetrisGame(int numRows, int numCols) : filas(numRows), columnas(numCols) {
        tablero = std::vector<std::vector<char>>(numRows, std::vector<char>(numCols, ' '));
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                if (i == 0 || i == filas - 1 || j == 0) {
                    tablero[i][j] = '@';
                } else {
                    if (j != columnas - 1) {
                        tablero[i][j] = '.';
                    } else {
                        tablero[i][j] = '@';
                    }
                }
            }
        }
    }

    bool hayEspacioVacio(int fila, int columna, int longitud, bool& gameOver) {
		for (int j = columna; j < columna + longitud; ++j) {
            if (tablero[fila+1][j] != '.') {
            	if(tablero[fila+1][j] == '@'){ //Para los bordes
            		return true; //Es la ultima fila
				}else{
					if(fila == 1){
						gameOver = true; // Si está en el tope superior y ya no puede avanzar	
					}
					return false; // Hay una palabra en esta posición
				}
                
            }
        }
        return true; // No hay palabras en la siguiente posicion
    }

    void colocarPalabra(int fila, int columna, std::string palabra) {
        for (int j = columna; j < columna + palabra.length(); ++j) {
            tablero[fila][j] = palabra[j - columna];
        }
    }

    void borrarPalabra(int fila, int columna, std::string palabra) {
        for (int j = columna; j < columna + palabra.length(); ++j) {
            tablero[fila][j] = (fila == 0) ? '@' : '.'; // Reemplazar por arrobas en la primera fila
        }
    }

    void imprimirTablero() {
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                std::cout << tablero[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    srand(time(NULL)); // Inicializar la semilla con el tiempo actual
    
    // Definir las dimensiones del tablero aquí
    int filas = 20 + 2; // + 2 Por los bordes
    int columnas = 10 + 2; // + 2 Por los bordes
    int tiempoDePausa = 200; //Tiempo en Milisegundos
    TetrisGame juego(filas, columnas);
	bool gameOver = false;
	
    std::cout << "Presiona Enter para iniciar..." << std::endl;
    std::cin.get(); // Espera a que el usuario presione Enter para comenzar

    while (true) {
        int posicionAleatoria = rand() % (columnas - 6) + 1; // Genera una posición aleatoria entre 1 y las columnas - 5
        for (int i = 1; i < filas - 1; i++) {
            juego.borrarPalabra(i - 1, posicionAleatoria, "DATOS"); // Borra la palabra anterior
            if (juego.hayEspacioVacio(i, posicionAleatoria, 5, gameOver)) {
                juego.colocarPalabra(i, posicionAleatoria, "DATOS"); // Coloca la nueva palabra
            } else {
                juego.colocarPalabra(i, posicionAleatoria, "DATOS"); // Coloca la nueva palabra
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
                i = filas - 2;
                break;
            }
            juego.imprimirTablero();
            std::this_thread::sleep_for(std::chrono::milliseconds(tiempoDePausa)); // Para dar una pausa entre impresiones
            if (i <= filas - 2) {
                system("cls"); // Para limpiar la pantalla (en Windows)
            }
        }
        if(gameOver){
        	juego.imprimirTablero();
        	std::cout<<"El juego ha terminado"<<std::endl;
        	break; //Para cortar el ciclo si una palabra está en el tope y no puede avanzar
		}
    }
	system("pause");
    return 0;
}