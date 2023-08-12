#include "../Modelo/Matriz.h"
#include "ListaSimple.cpp"
#include <cstdlib>  // Para la generación de números aleatorios
Matriz::Matriz(){
}
Matriz::Matriz(int filas, int columnas) : filas_(filas), columnas_(columnas) {
    matriz_ = new ListaSimple<int>*[filas];
    for (int i = 0; i < filas; ++i) {
        matriz_[i] = new ListaSimple<int>();

        for (int j = 0; j < columnas; ++j) {
            matriz_[i]->insertarAlFinal(0); // Insertar un cero en la lista
        }
    }
}

Matriz::~Matriz() {
    /*for (int i = 0; i < filas_; ++i) {
        delete matriz_[i];
    }
    delete[] matriz_;*/
}
int Matriz::obtenerFilas(){
	return filas_;
}
int Matriz::obtenerColumnas(){
	return columnas_;
}
void Matriz::generarAleatorios() {
    // Establecer la semilla para la generación de números aleatorios
    for (int i = 0; i < filas_; ++i) {
        for (int j = 0; j < columnas_; ++j) {
            int aleatorio = std::rand() % (9) + 1 ; // Genera un número aleatorio del 0 al 9
            (*this)[i][j] = aleatorio; // Acceder a la celda y asignar el valor
        }
    }
}

ListaSimple<int>& Matriz::operator[](int fila) const{
    return *(matriz_[fila]);
}

std::ostream& operator<<(std::ostream& os, const Matriz& matriz) {
    for (int i = 0; i < matriz.filas_; ++i) {
        for (int j = 0; j < matriz.columnas_; ++j) {
            os << matriz[i][j] << "\t";
        }
        os << std::endl;
    }
    return os;
}

bool Matriz::operator==(const Matriz& otra) const {
    if (filas_ != otra.filas_ || columnas_ != otra.columnas_) {
        return false; // Dimensiones diferentes, no son iguales
    }

    for (int i = 0; i < filas_; ++i) {
        for (int j = 0; j < columnas_; ++j) {
            if ((*this)[i][j] != otra[i][j]) {
                return false; // Al menos un elemento es diferente
            }
        }
    }

    return true; // Las matrices son iguales
}


Matriz Matriz::multiplicar(const Matriz &otraMatriz) const {
    if (columnas_ != otraMatriz.filas_) {
        // Manejar el caso de dimensiones incompatibles
        throw std::invalid_argument("Las dimensiones de las matrices no son compatibles para la multiplicación");
    }

    Matriz resultado(filas_, otraMatriz.columnas_);
    
    for (int i = 0; i < filas_; ++i) {
        for (int j = 0; j < otraMatriz.columnas_; ++j) {
            int valor = 0;
            for (int k = 0; k < columnas_; ++k) {
                valor += (*this)[i][k] * otraMatriz[k][j];
            }
            resultado[i][j] = valor;
        }
    }
    
    return resultado;
}

Matriz Matriz::operator*(const Matriz& otraMatriz) const {
	if (columnas_ != otraMatriz.filas_) {
        // Manejar el caso de dimensiones incompatibles
        throw std::invalid_argument("Las dimensiones de las matrices no son compatibles para la multiplicación");
    }

    Matriz resultado(filas_, otraMatriz.columnas_);
    
    for (int i = 0; i < filas_; ++i) {
        for (int j = 0; j < otraMatriz.columnas_; ++j) {
            int valor = 0;
            for (int k = 0; k < columnas_; ++k) {
                valor += (*this)[i][k] * otraMatriz[k][j];
            }
            resultado[i][j] = valor;
        }
    }
    
    return resultado;
}

std::string Matriz::formatearMatriz() {
	std::string formato;
	formato += "{";
    for (int i = 0; i < filas_; ++i) {
    	formato += "{";
        for (int j = 0; j < columnas_; ++j) {
        	if (j < columnas_ - 1) {
        		formato += std::to_string((*this)[i][j]);
				formato += ",";        	
			} else {
				formato += std::to_string((*this)[i][j]);
			}
        }
        if (i < filas_ - 1) {
        	formato += "},";	
		} else {
			formato += "}}";
		}
        
    }    
    return formato;
}

/*struct AsociacionMatrices {
    int i, j, k; // Indices de las matrices involucradas
};


void Matriz::encontrarAsociacionOptima(ListaSimple<int> matrices, ListaSimple<int> dimensiones, int numMatrices) const {

    ListaSimple<AsociacionMatrices> asociaciones;

    for (int i = 0; i < matrices.obtenerTamanio(); ++i) {
	    ListaSimple<Matriz>& listaDeMatrices = matrices[i]; // Obtener la lista de matrices en la posición i
	    for (int j = 0; j < listaDeMatrices.obtenerTamanio(); ++j) {
	        Matriz matriz = listaDeMatrices[j]; // Obtener una matriz de la lista
	        int dimension = matriz[i].obtenerFilas() + matriz[i].obtenerColumnas();
	        dimensiones.insertarAlFinal(dimension);
	    }
	}


    int n = dimensiones.obtenerTamanio();

    ListaSimple<ListaSimple<int>> M;
    for (int i = 0; i <= n; ++i) {
        M.insertarAlFinal(ListaSimple<int>());
        M[i].insertarAlFinal(dimensiones[i - 1]);
    }

    ListaSimple<ListaSimple<int>> costos;
    for (int i = 0; i <= n; ++i) {
        costos.insertarAlFinal(ListaSimple<int>());
        for (int j = 0; j <= n; ++j) {
            costos[i].insertarAlFinal(0);
        }
    }

    for (int l = 2; l <= n; ++l) {
        for (int i = 1; i <= n - l + 1; ++i) {
            int j = i + l - 1;
            costos[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; ++k) {
                int q = costos[i][k] + costos[k + 1][j] + M[i].obtenerPrimero() * M[k].obtenerPrimero() * M[j].obtenerPrimero();
                if (q < costos[i][j]) {
                    costos[i][j] = q;
                    M[i][j] = k;
                }
            }
        }
    }

    // Mostrar la asociación óptima
    mostrarAsociacionOptima(M, 1, n - 1);

    // Resto del código
}

void Matriz::mostrarAsociacionOptima(const ListaSimple<ListaSimple<int>>& M, int i, int j) const {
    if (i == j) {
        std::cout << "A" << i;
    } else {
        std::cout << "(";
        mostrarAsociacionOptima(M, i, M[i][j]);
        mostrarAsociacionOptima(M, M[i][j] + 1, j);
        std::cout << ")";
    }
}*/