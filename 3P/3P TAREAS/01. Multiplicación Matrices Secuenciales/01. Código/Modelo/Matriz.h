#ifndef MATRIZ_H
#define MATRIZ_H

#include "ListaSimple.h"
#include <iostream>  // Para la salida estándar
#include <string>

class Matriz {
public:
    Matriz(int filas, int columnas);
    Matriz();
    ~Matriz();
    int obtenerFilas();
    int obtenerColumnas();
 	void generarAleatorios();
    ListaSimple<int>& operator[](int fila) const;
    friend std::ostream& operator<<(std::ostream& os, const Matriz& matriz);
   	bool operator==(const Matriz& otra) const;
   	Matriz operator*(const Matriz& otra) const;
   	std::string formatearMatriz();
   	Matriz multiplicar(const Matriz &otraMatriz) const;
private:
    int filas_;
    int columnas_;
    ListaSimple<int>** matriz_;
    int* dimensiones_;
    
};

#endif
