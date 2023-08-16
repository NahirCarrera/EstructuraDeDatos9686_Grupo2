#include "../Modelo/Pieza.h"
#include <algorithm>
Pieza::Pieza(){
	
}
Pieza::Pieza(std::string palabra_){
	palabra = palabra_;
	rotacion = 0;
	fila = 1;
	columna = 1;
}

std::string Pieza::getPalabra() const{
	return palabra;
}
int Pieza::getRotacion()const{
	return rotacion;
}

int Pieza::getFila()const{
	return fila;
}

int Pieza::getColumna() const{
	return columna;
}

void Pieza::setRotacion(int newRotacion){
	rotacion = newRotacion;
}

void Pieza::setFila(int newFila){
	fila = newFila;
}

void Pieza::setColumna(int newColumna){
	columna = newColumna;
}

void Pieza::reiniciarRotacion(){
	rotacion = 1;
}

std::ostream& operator<<(std::ostream& os, const Pieza& pieza) {
	std::string palabra = pieza.getPalabra();
    if(pieza.getRotacion() == 3 || pieza.getRotacion() == 4) {
    	std::reverse(palabra.begin(), palabra.end());
	}
	os << palabra;
    return os;
}







