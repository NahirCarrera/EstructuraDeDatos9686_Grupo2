/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Nombres: Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 27/06/23 17:32
 * Fecha de modificacion: 29/06/23 20:25
 * Enunciado:
 * Proyecto transformacion de expresion infija a notacion polaca y polaca inversa
 *
 *******************************************************************************/

#if !defined(__Class_Diagram_1_CalculadoraPolaca_h)
#define __Class_Diagram_1_CalculadoraPolaca_h

#include <string>
#include "../Modelo/ArbolBinario.h"
#include "../Controlador/ListaSimple.cpp"
#include "Matriz.h"

class CalculadoraPolaca
{
public:
   CalculadoraPolaca(std::string expresionInfijo);
   ~CalculadoraPolaca();
   std::string getExpresionInfijo(void);
   void setExpresionInfijo(std::string newExpresionInfijo);
   std::string getExpresionPostfijo(void);
   void setExpresionPostfijo(std::string newExpresionPostfijo);
   std::string removerParentesis(std::string expresion);
   NodoArbol<std::string>* crearArbol(std::string expresion);
   Matriz evaluarExpresionPostfija(ListaSimple<Matriz> matrices);
   std::string eliminarEspaciosConsecutivos(std::string cadena);

protected:
private:
   std::string expresionInfijo;
   std::string expresionPostfijo;


};

#endif