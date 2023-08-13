

#ifndef MATRIZCONTROLADOR_H
#define MATRIZCONTROLADOR_H

#include "ListaSimple.h"
#include "../Modelo/Matriz.h"
#include <iostream>  // Para la salida estándar
#include <limits>
#include <string>

class MatrizControlador {
	public:
		MatrizControlador(int);
		void mostrarAsociacionOptima();
		// Getters
	    int getCantidadMatrices() const;
	    int getCosto() const;
	    const int getInfinito() const;
	    const ListaSimple<int> getDimensiones() const;
	    const ListaSimple<Matriz>& getMatrices() const;
	    const ListaSimple<ListaSimple<int>>& getCostosOptimos() const;
	    const ListaSimple<ListaSimple<int>>& getPosicionesOptimas() const;
	    std::string getAsociacionOptima() const;
	private:
		int cantidadMatrices;
		int costo;
		const int infinito;
		ListaSimple<int> dimensiones;
		ListaSimple<Matriz> matrices;
	    ListaSimple<ListaSimple<int>> CostosOptimos;
		ListaSimple<ListaSimple<int>> PosicionesOptimas;
		std::string asociacionOptima;
		//Funciones
		void generarMatricesAleatorias();
		void CrearMatricesCostosYPosiciones();
	    int CalcularCostoMultiplicacion(int, int, int);
	    void CalcularOrdenOptimoMultiplicacion();
	    void guardarAsociacionOptima(int, int, ListaSimple<ListaSimple<int>>&);
	    void ImprimirMatricesCostosYPosiciones();
	};

#endif
