#include "../Modelo/MatrizControlador.h"
#include "ListaSimple.cpp"
#include "../Modelo/Matriz.h"
#include <random>

MatrizControlador::MatrizControlador(int cantidadMatrices)
    : infinito(std::numeric_limits<int>::max()),cantidadMatrices(cantidadMatrices), asociacionOptima(""), dimensiones() {
    // Resto del constructor
}

int MatrizControlador::getCantidadMatrices() const {
    return cantidadMatrices;
}

int MatrizControlador::getCosto() const {
    return costo;
}

const int MatrizControlador::getInfinito() const {
    return infinito;
}

const ListaSimple<int> MatrizControlador::getDimensiones() const {
    return dimensiones;
}

const ListaSimple<Matriz>& MatrizControlador::getMatrices() const {
    return matrices;
}

const ListaSimple<ListaSimple<int>>& MatrizControlador::getCostosOptimos() const {
    return CostosOptimos;
}

const ListaSimple<ListaSimple<int>>& MatrizControlador::getPosicionesOptimas() const {
    return PosicionesOptimas;
}

std::string MatrizControlador::getAsociacionOptima() const {
    return asociacionOptima;
}
void MatrizControlador::generarMatricesAleatorias(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::string secuencia = "";
    int minDimension = 2;
    int maxDimension = 8;
    int filas = std::rand() % (maxDimension) + minDimension; // Generar número aleatorio entre 1 y 8 para las filas
    int columnas = std::rand() % (maxDimension) + minDimension; // Generar número aleatorio entre 1 y 8 para las columnas
    Matriz matriz;
    dimensiones.vaciar();
	dimensiones.insertarAlFinal(filas);
	dimensiones.insertarAlFinal(columnas);
	matrices = ListaSimple<Matriz>();
	for (int i = 0; i < cantidadMatrices; i++) {
        matriz = Matriz(filas, columnas);
        matriz.generarAleatorios();
        matrices.insertarAlFinal(matriz);
        std::cout << "Matriz: " << i <<" de (" << filas <<" x "<<columnas << ")" << std::endl;
        std::cout << matriz << std::endl;
        secuencia += "(" + std::to_string(filas) + " x " + std::to_string(columnas) + ")";
        // Actualizar dimensiones para la siguiente matriz
        filas = columnas;
        columnas = std::rand() % maxDimension + minDimension; // Generar nuevo número aleatorio para las columnas
		if(i < cantidadMatrices - 1){
			dimensiones.insertarAlFinal(columnas);
		}
    }
    std::cout<<"Matrices a multiplicar: " << secuencia << std::endl;
}

void MatrizControlador::CrearMatricesCostosYPosiciones() {
    for (int i = 0; i < cantidadMatrices; i++) {
        ListaSimple<int> filaCostos;
        ListaSimple<int> filaPosiciones;

        for (int j = 0; j < cantidadMatrices; j++) {
            filaCostos.insertarAlFinal(-1);
            filaPosiciones.insertarAlFinal(-1);
        }

        CostosOptimos.insertarAlFinal(filaCostos);
        PosicionesOptimas.insertarAlFinal(filaPosiciones);
    }
}

int MatrizControlador::CalcularCostoMultiplicacion(int i, int k, int j) {
    return dimensiones[i] * dimensiones[k + 1] * dimensiones[j + 1];
}

void MatrizControlador::CalcularOrdenOptimoMultiplicacion() {
    for (int i = 0; i < cantidadMatrices; i++)
        CostosOptimos[i][i] = 0;

    for (int longitud = 2; longitud <= cantidadMatrices; longitud++) {
        for (int i = 0; i < (cantidadMatrices - longitud + 1); i++) {
            int j = i + longitud - 1;
            CostosOptimos[i][j] = infinito;
            for (int k = i; k <= j - 1; k++) {
                int costoActual = CostosOptimos[i][k] + CostosOptimos[k + 1][j] +
                                 CalcularCostoMultiplicacion(i, k, j);
                if (costoActual < CostosOptimos[i][j]) {
                    CostosOptimos[i][j] = costoActual;
                    PosicionesOptimas[i][j] = k;
                }
            }
        }
    }

    costo = CostosOptimos[0][cantidadMatrices - 1]; // Actualiza la variable costo
}


void MatrizControlador::guardarAsociacionOptima(int i, int j, ListaSimple<ListaSimple<int>>& posicionesOptimas) {
    if (j > i) {
        asociacionOptima += "(";
        guardarAsociacionOptima(i, posicionesOptimas[i][j], posicionesOptimas);
        asociacionOptima +=  "*";
        guardarAsociacionOptima(posicionesOptimas[i][j] + 1, j, posicionesOptimas);
        asociacionOptima +=  ")";
    } else {
        asociacionOptima +=  "M" + std::to_string(i);
    }
}

void MatrizControlador::ImprimirMatricesCostosYPosiciones() {
    std::cout << "Matrices de Costos Optimos = " << std::endl;
    for (int fila = 0; fila < cantidadMatrices; fila++) {
        for (int columna = 0; columna < cantidadMatrices; columna++)
            std::cout << CostosOptimos[fila][columna] << " ";
        std::cout << std::endl;
    }

    std::cout << "Matrices de Posiciones Optimas = " << std::endl;
    for (int fila = 0; fila < cantidadMatrices; fila++) {
        for (int columna = 0; columna < cantidadMatrices; columna++)
            std::cout << PosicionesOptimas[fila][columna] << " ";
        std::cout << std::endl;
    }
    
    int operaciones = CostosOptimos[0][cantidadMatrices - 1];
    std::cout << std::endl;
    std::cout << "Numero total de operaciones realizadas en la solucion optima: " << operaciones << std::endl;
}

void MatrizControlador::mostrarAsociacionOptima(){
	generarMatricesAleatorias();
	CrearMatricesCostosYPosiciones();
    CalcularOrdenOptimoMultiplicacion();
    guardarAsociacionOptima(0, cantidadMatrices - 1, PosicionesOptimas);
    std::cout << asociacionOptima << " en "<< costo << " operaciones" << std::endl;
}