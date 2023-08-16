#include "../Modelo/Matriz.h"
#include "ListaSimple.cpp"
#include <cstdlib>  // Para la generación de números aleatorios
#include <iomanip>

Matriz::Matriz(){
	filas_ = 0;
	columnas_ = 0;
}
Matriz::Matriz(int filas, int columnas) : filas_(filas), columnas_(columnas) {
    matriz_ = new ListaSimple<double>*[filas];
    for (int i = 0; i < filas; ++i) {
        matriz_[i] = new ListaSimple<double>();

        for (int j = 0; j < columnas; ++j) {
            matriz_[i]->insertarAlFinal(0); // Insertar un cero en la lista
        }
    }
}

Matriz::~Matriz() {

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
            double aleatorio = std::rand() % (9) + 1 ; // Genera un número aleatorio del 0 al 4
            (*this)[i][j] = aleatorio; // Acceder a la celda y asignar el valor
        }
    }
}

ListaSimple<double>& Matriz::operator[](int fila) const{
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
            double valor = 0;
            for (int k = 0; k < columnas_; ++k) {
                valor += (*this)[i][k] * otraMatriz[k][j];
            }
            resultado[i][j] = valor;
        }
    }
    
    return resultado;
}

Matriz Matriz::operator*(const Matriz& otraMatriz) const {
	if (otraMatriz.filas_ == 0) {
        return *this;  // Si la otra matriz está vacía, retorna la matriz actual
    }
	
	if (columnas_ != otraMatriz.filas_) {
        // Manejar el caso de dimensiones incompatibles
        throw std::invalid_argument("Las dimensiones de las matrices no son compatibles para la multiplicación");
    }

    Matriz resultado(filas_, otraMatriz.columnas_);
    
    for (int i = 0; i < filas_; ++i) {
        for (int j = 0; j < otraMatriz.columnas_; ++j) {
            double valor = 0;
            for (int k = 0; k < columnas_; ++k) {
                valor += (*this)[i][k] * otraMatriz[k][j];
            }
            resultado[i][j] = valor;
        }
    }
    
    return resultado;
}

std::string eliminarDecimales(const std::string &cadena) {
    size_t puntoPos = cadena.find('.');
    
    if (puntoPos != std::string::npos) {
        return cadena.substr(0, puntoPos);
    } else {
        return cadena;
    }
}

std::string Matriz::formatearMatriz() {
	std::string formato;
	formato += "{";
    for (int i = 0; i < filas_; ++i) {
    	formato += "{";
        for (int j = 0; j < columnas_; ++j) {
        	if (j < columnas_ - 1) {
        		formato += eliminarDecimales(std::to_string((*this)[i][j]));
				formato += ",";        	
			} else {
				formato += eliminarDecimales(std::to_string((*this)[i][j]));
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