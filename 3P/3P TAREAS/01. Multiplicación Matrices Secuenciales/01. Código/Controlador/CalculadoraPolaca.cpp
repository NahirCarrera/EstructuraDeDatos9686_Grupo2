/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Nombres: Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 27/06/23 17:32
 * Fecha de modificacion: 29/06/23 20:25
 * Enunciado:
 * Proyecto transformacion de expresion infija a notacion polaca y polaca inversa
 *
 *******************************************************************************/

#include "../Modelo/CalculadoraPolaca.h"
#include "../Controlador/ArbolBinario.cpp"
#include <iostream>
#include <stack>
#include <algorithm>

////////////////////////////////////////////////////////////////////////
// Name:       CalculadoraPolaca::CalculadoraPolaca(std::string expresionInfijo)
// Purpose:    Implementation of CalculadoraPolaca::CalculadoraPolaca()
// Parameters:
// - expresionInfijo
// Return:     
////////////////////////////////////////////////////////////////////////

CalculadoraPolaca::CalculadoraPolaca(std::string expresionInfijo) {	
	std::string expresion;
	expresion = expresionInfijo;
	
	this->expresionInfijo = expresionInfijo;
	NodoArbol<std::string>* raiz = crearArbol(expresion);
	ArbolBinario<std::string> arbol;
	arbol.setRaiz(raiz);
	
	expresion = arbol.obtenerRecorridoPostorden();
	expresion = eliminarEspaciosConsecutivos(expresion);
	this->expresionPostfijo = expresion;
		
}

////////////////////////////////////////////////////////////////////////
// Name:       CalculadoraPolaca::~CalculadoraPolaca()
// Purpose:    Implementation of CalculadoraPolaca::~CalculadoraPolaca()
// Return:     
////////////////////////////////////////////////////////////////////////

CalculadoraPolaca::~CalculadoraPolaca()
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       CalculadoraPolaca::getExpresionInfijo()
// Purpose:    Implementation of CalculadoraPolaca::getExpresionInfijo()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

std::string CalculadoraPolaca::getExpresionInfijo(void)
{
   return expresionInfijo;
}

////////////////////////////////////////////////////////////////////////
// Name:       CalculadoraPolaca::setExpresionInfijo(std::string newExpresionInfijo)
// Purpose:    Implementation of CalculadoraPolaca::setExpresionInfijo()
// Parameters:
// - newExpresionInfijo
// Return:     void
////////////////////////////////////////////////////////////////////////

void CalculadoraPolaca::setExpresionInfijo(std::string newExpresionInfijo)
{
   expresionInfijo = newExpresionInfijo;
}

////////////////////////////////////////////////////////////////////////
// Name:       CalculadoraPolaca::getExpresionPostfijo()
// Purpose:    Implementation of CalculadoraPolaca::getExpresionPostfijo()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

std::string CalculadoraPolaca::getExpresionPostfijo(void)
{
   return expresionPostfijo;
}

////////////////////////////////////////////////////////////////////////
// Name:       CalculadoraPolaca::setExpresionPostfijo(std::string newExpresionPostfijo)
// Purpose:    Implementation of CalculadoraPolaca::setExpresionPostfijo()
// Parameters:
// - newExpresionPostfijo
// Return:     void
////////////////////////////////////////////////////////////////////////

void CalculadoraPolaca::setExpresionPostfijo(std::string newExpresionPostfijo)
{
   expresionPostfijo = newExpresionPostfijo;
}

////////////////////////////////////////////////////////////////////////
// Name:       CalculadoraPolaca::removerParentesis(std::string expresion)
// Purpose:    Implementation of CalculadoraPolaca::removerParentesis()
// Parameters:
// - expresion
// Return:     std::string
////////////////////////////////////////////////////////////////////////

std::string CalculadoraPolaca::removerParentesis(std::string expresion)
{
    int indiceParA = -1;
    int indiceParB = -1;
    int indiceNumFuera = -1;
    int par = 0;
    std::string resultado;

    for (int i = 0; i < expresion.length(); i++)
    {
        if (expresion[i] == '(')
        {
            if (par == 0)
            {
                indiceParA = i;
            }
            par++;
        }
        else if (expresion[i] == ')')
        {
            par--;
            if (par == 0)
            {
                indiceParB = i;
            }
        }
        else if (expresion[i] != ' ' && par == 0)
        {
            indiceNumFuera = i;
            break; // No es necesario continuar el bucle si encontramos un número fuera de los paréntesis
        }
    }

    if (indiceNumFuera != -1)
    {
        return expresion; // Retornar la expresión original si hay algún número fuera de los paréntesis
    }

    if (indiceParA != -1 && indiceParB != -1)
    {
        expresion.erase(indiceParA, 1);
        expresion.erase(indiceParB - 1, 1);
        resultado = expresion;

        return removerParentesis(resultado); // Llamar recursivamente para seguir eliminando paréntesis
    }

    return expresion; // Retornar la expresión si no se encontraron paréntesis para eliminar
}

////////////////////////////////////////////////////////////////////////
// Name:       CalculadoraPolaca::crearArbol(std::string expresion)
// Purpose:    Implementation of CalculadoraPolaca::crearArbol()
// Parameters:
// - expresion
// Return:     Nodo*
////////////////////////////////////////////////////////////////////////

int obtenerPosicionOperador(std::string expresion) {
	// Buscar el operador de menor jerarquía más al exterior
    int nivel = 5; // Nivel más alto posible
    int pos = -1;  // Posición del operador
    int par = 0;   // Contador de paréntesis
    
	for (int i = 0; i < expresion.length(); i++)
    {
        char c = expresion[i];
        if (c == '(')
            par++; // Abrir paréntesis
        else if (c == ')')
            par--; // Cerrar paréntesis
        else if (par == 0)
        { // Fuera de paréntesis
            // Determinar el nivel del operador actual
            int niv;
            if (c == '+' || c == '-')
                niv = 1;
            else if (c == '*' || c == '/')
                niv = 2;
            else if (c == '^')
                niv = 3;
            else if (c == 's' || c == 'c' || c == 't' || c == 'r')
                niv = 4; // sin, cos o tan
            else
                niv = 5; // No es operador

            // Actualizar el nivel y la posición si es menor que el anterior
            if (niv < nivel)
            {
                nivel = niv;
                pos = i;
            }

            // Nos aseguramos de obtener el operador de mas a la derecha
            if (niv == 1 || niv == 2) {
                if (niv <= nivel)
                {
                    nivel = niv;
                    pos = i;
                }
            }
        }
    }
    
    return pos;
}

NodoArbol<std::string>* CalculadoraPolaca::crearArbol(std::string expresion)
{
    int pos;  // Posición del operador

    // eliminamos parentesis si no hay mas elementos fuera de ellos
    expresion = removerParentesis(expresion);

	pos = obtenerPosicionOperador(expresion);

    // Si no se encontró ningún operador, retornar un nodo con el valor de la expresión
    if (pos == -1)
    {
        return new NodoArbol<std::string>{expresion};
    }

    // Dividir la expresión en dos subexpresiones según el operador
    std::string izquierda, derecha;
    izquierda = expresion.substr(0, pos); // Antes del operador

    NodoArbol<std::string> *nodo = nullptr;
    // Crear un nuevo nodo con el operador como valor
    
    nodo = new NodoArbol<std::string>{expresion.substr(pos, 1)};
    derecha = expresion.substr(pos + 1); // Después del operador
    

    // Crear los nodos hijos recursivamente con las subexpresiones
    nodo->setIzquierdo(crearArbol(izquierda));
    nodo->setDerecho(crearArbol(derecha));

    // Retornar el puntero al nodo creado
    return nodo;
}


//Funciones con n parametros
Matriz multiply() {
    return Matriz();
}

template<typename T, typename... Args>
Matriz multiply(T first, Args... rest) {
    return first * multiply(rest...);
}

Matriz CalculadoraPolaca::evaluarExpresionPostfija(ListaSimple<Matriz> matrices)
{
	std::string expresion = expresionPostfijo;
    std::stack<Matriz> pila;
    char c;
    for (int i = 0; i < expresion.length(); i++)
    {
        c = expresion.at(i);
        if ( c == 'M')
        {
        	i++;
        	c = expresion.at(i);
            std::string numeroStr;
            while (isdigit(c) )
            {
                numeroStr += c;
                c = expresion.at(++i);
            }
            int numero = std::stoi(numeroStr);
            pila.push(matrices[numero]);
        }
		 else if (c == '*') {
            if (pila.size() < 2)
            {                       
                std::cout << "Error: Expresion invalida" << std::endl;
                return Matriz();                             
            } 

            Matriz matriz1 = pila.top();
            pila.pop();
            Matriz matriz2 = pila.top();
            pila.pop();

            Matriz resultado = multiply(matriz2, matriz1);

            pila.push(resultado);
                            
        }

    }

    if (pila.size() != 1)
    {
        std::cout << "Error: Expresion invalida" << std::endl;
        return Matriz();
    }

    return pila.top();
}

////////////////////////////////////////////////////////////////////////
// Name:       CalculadoraPolaca::eliminarEspaciosConsecutivos(std::string cadena)
// Purpose:    Implementation of CalculadoraPolaca::eliminarEspaciosConsecutivos()
// Parameters:
// - cadena
// Return:     std::string
////////////////////////////////////////////////////////////////////////

std::string CalculadoraPolaca::eliminarEspaciosConsecutivos(std::string cadena)
{
    std::string resultado;
    bool espacioAnterior = false;

    for (char c : cadena)
    {
        if (c == ' ')
        {
            if (!espacioAnterior)
            {
                resultado += c;
            }
            espacioAnterior = true;
        }
        else
        {
            resultado += c;
            espacioAnterior = false;
        }
    }

    return resultado;
}
