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
#include "../Herramientas/Matematica.h"
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
	expresion = agregarCeroAntesDelMenos(expresionInfijo);
	
	this->expresionInfijo = expresionInfijo;
	NodoArbol<std::string>* raiz = crearArbol(expresion);
	ArbolBinario<std::string> arbol;
	arbol.setRaiz(raiz);
	
	expresion = arbol.obtenerRecorridoPostorden();
	expresion = eliminarEspaciosConsecutivos(expresion);
	this->expresionPostfijo = expresion;
	
	expresion = arbol.obtenerRecorridoPreorden();
	expresion = eliminarEspaciosConsecutivos(expresion);
	this->expresionPrefijo = expresion;
	
	arbol.mostrarArbol();
	
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
// Name:       CalculadoraPolaca::getExpresionPrefijo()
// Purpose:    Implementation of CalculadoraPolaca::getExpresionPrefijo()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

std::string CalculadoraPolaca::getExpresionPrefijo(void)
{
   return expresionPrefijo;
}

////////////////////////////////////////////////////////////////////////
// Name:       CalculadoraPolaca::setExpresionPrefijo(std::string newExpresionPrefijo)
// Purpose:    Implementation of CalculadoraPolaca::setExpresionPrefijo()
// Parameters:
// - newExpresionPrefijo
// Return:     void
////////////////////////////////////////////////////////////////////////

void CalculadoraPolaca::setExpresionPrefijo(std::string newExpresionPrefijo)
{
   expresionPrefijo = newExpresionPrefijo;
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
    
    // Si nos encontramos con una raiz
    if (expresion[pos] == 'r')
    {
        nodo = new NodoArbol<std::string>{expresion.substr(pos, 4)};
        derecha = expresion.substr(pos + 4); // Después del operador
    }// Si nos encontramos con un sin, cos o tan
    else if (expresion[pos] == 's' || expresion[pos] == 'c' || expresion[pos] == 't')
    {
        nodo = new NodoArbol<std::string>{expresion.substr(pos, 3)};
        derecha = expresion.substr(pos + 3); // Después del operador
    }
    else
    { //cualquier otro operador
        nodo = new NodoArbol<std::string>{expresion.substr(pos, 1)};
        derecha = expresion.substr(pos + 1); // Después del operador
    }

    // Crear los nodos hijos recursivamente con las subexpresiones
    nodo->setIzquierdo(crearArbol(izquierda));
    nodo->setDerecho(crearArbol(derecha));

    // Retornar el puntero al nodo creado
    return nodo;
}

////////////////////////////////////////////////////////////////////////
// Name:       CalculadoraPolaca::operar(double numero1, double numero2, char operador)
// Purpose:    Implementation of CalculadoraPolaca::operar()
// Parameters:
// - numero1
// - numero2
// - operador
// Return:     double
////////////////////////////////////////////////////////////////////////

double CalculadoraPolaca::operar(double numero1, double numero2, char operador)
{
	Matematica mat;
    double resultado;
    switch (operador)
    {
    case '+':
        return numero1 + numero2;
    case '-':
        return numero1 - numero2;
    case '*':
        return numero1 * numero2;
    case '/':
        if (numero2 == 0) {        	
            std::cout << "Error: No se puede dividir para cero" << std::endl;
            return 0.0/0.0;
        }
        return numero1 / numero2;
    case '^':
        resultado = mat.pow(numero1, numero2);
        if (mat.isNaN(resultado)) {
            std::cout << "Error: Potencia (" << numero1 << ")^(" << numero2 << ") no valida" << std::endl;
        }
        return resultado;
    default:
        return 0.0f; // Operador inválido
    }
}

////////////////////////////////////////////////////////////////////////
// Name:       CalculadoraPolaca::evaluarExpresionPostfija()
// Purpose:    Implementation of CalculadoraPolaca::evaluarExpresionPostfija()
// Return:     double
////////////////////////////////////////////////////////////////////////

double CalculadoraPolaca::evaluarExpresionPostfija()
{
	Matematica mat;
	std::string expresion = expresionPostfijo;
    std::stack<double> pila;
    char c;
    for (int i = 0; i < expresion.length(); i++)
    {
        c = expresion[i];
        if (isdigit(c) || c == '.')
        {
            std::string numeroStr;
            while (isdigit(c) || c == '.')
            {
                numeroStr += c;
                c = expresion[++i];
            }
            double numero = std::stod(numeroStr);
            pila.push(numero);
        }
        else if (c == 'p' && expresion[i + 1] == 'i')
        {
            // Si el numero leido es pi
            double numeroPi = 3.14159265358979323846;
            pila.push(numeroPi);
            i += 2;
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        {
            if (pila.size() < 2)
            {                       
                std::cout << "Error: Expresion invalida" << std::endl;
                return 0.0/0.0;                             
            } 

            double num2 = pila.top();
            pila.pop();
            double num1 = pila.top();
            pila.pop();

            double resultado = operar(num1, num2, c);
            if (mat.isNaN(resultado)) {
                return resultado;
            }
            pila.push(resultado);
                            
        }
        else
        {
            // Funciones (sin, cos, tan)
            if (c == 'r' && expresion[i + 1] == 'a' && expresion[i + 2] == 'i' && expresion[i + 3] == 'z')
            {
                double num = pila.top();
                pila.pop();
                if (num < 0) {
                    std::cout << "Error: raiz cuadrada de numero negativo" << std::endl;
                    return 0.0/0.0;
                }
                double resultado = mat.sqrt(num);
                pila.push(resultado);
                i += 3;
            }

            // Funciones (sin, cos, tan)
            if (c == 's' && expresion[i + 1] == 'i' && expresion[i + 2] == 'n')
            {
                double num = pila.top();
                pila.pop();
                double resultado = mat.sin(num);
                pila.push(resultado);
                i += 2;
            }
            
            if (c == 'c' && expresion[i + 1] == 'o' && expresion[i + 2] == 's')
            {
                double num = pila.top();
                pila.pop();
                double resultado = mat.cos(num);
                pila.push(resultado);
                i += 2;
            }
        
            if (c == 't' && expresion[i + 1] == 'a' && expresion[i + 2] == 'n')
            {
                double numeroPi = 3.14159265358979323846;
                double num = pila.top();
                pila.pop();
                if (num == numeroPi/2) {
                    std::cout << "Error: tan(pi/2) no valido" << std::endl;
                    return 0.0/0.0;
                }

                double resultado = mat.tan(num);
                pila.push(resultado);
                i += 2;
            }
            
        }
    }

    if (pila.size() != 1)
    {
        std::cout << "Error: Expresion invalida" << std::endl;
        return 0.0f;
    }

    return pila.top();
}

////////////////////////////////////////////////////////////////////////
// Name:       CalculadoraPolaca::evaluarExpresionPrefija()
// Purpose:    Implementation of CalculadoraPolaca::evaluarExpresionPrefija()
// Return:     double
////////////////////////////////////////////////////////////////////////

double CalculadoraPolaca::evaluarExpresionPrefija()
{
	Matematica mat;
	std::string expresion = expresionPrefijo;
    std::stack<double> pila;
    char c;
    for (int i = expresion.length() - 1; i >= 0; i--)
    {
        // Crear una copia de la pila
        std::stack<double> pilaCopia = pila;

        c = expresion[i];
        if (isdigit(c) || c == '.')
        {
            std::string numeroStr;
            while (isdigit(c) || c == '.')
            {
                numeroStr += c;
                i--;
                c = expresion[i];
            }
            std::reverse(numeroStr.begin(), numeroStr.end());
            double numero = std::stod(numeroStr);
            pila.push(numero);
        }
        else if (c == 'i' && expresion[i - 1] == 'p')
        {
            // Si el numero leido es pi
            double numeroPi = 3.14159265358979323846;
            pila.push(numeroPi);
            i -= 2;
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        {
            if (pila.size() < 2)
            {
                std::cout << "Error: Expresion invalida" << std::endl;
                return 0.0f;
            }
            double num1 = pila.top();
            pila.pop();
            double num2 = pila.top();
            pila.pop();
    
            double resultado = operar(num1, num2, c);
            if (mat.isNaN(resultado)) {
                return resultado;
            }
            pila.push(resultado);
        }
        else
        {
            // Funciones (sin, cos, tan, raiz)
            if (c == 'z' && expresion[i - 1] == 'i' && expresion[i - 2] == 'a' && expresion[i - 3] == 'r')
            {
                double num = pila.top();
                pila.pop();
                if (num < 0) {
                    std::cout << "Error: raiz cuadrada de numero negativo" << std::endl;
                    return 0.0/0.0;
                }
                double resultado = mat.sqrt(num);
                pila.push(resultado);
                i -= 3;
            }

            if (c == 'n' && expresion[i - 1] == 'i' && expresion[i - 2] == 's')
            {
                double num = pila.top();
                pila.pop();
                double resultado = mat.sin(num);
                pila.push(resultado);
                i -= 2;
            }

            if (c == 's' && expresion[i - 1] == 'o' && expresion[i - 2] == 'c')
            {
                double num = pila.top();
                pila.pop();
                double resultado = mat.cos(num);
                pila.push(resultado);
                i -= 2;
            }
            
            if (c == 'n' && expresion[i - 1] == 'a' && expresion[i - 2] == 't')
            {
                double numeroPi = 3.14159265358979323846;
                double num = pila.top();
                pila.pop();
                if (num == numeroPi/2) {
                    std::cout << "Error: tan(pi/2) no valido" << std::endl;
                    return 0.0/0.0;
                }
                double resultado = mat.tan(num);
                pila.push(resultado);
                i -= 2; 
            }
            
        }
        
    }

    if (pila.size() != 1)
    {
        std::cout << "Error: Expresion invalida" << std::endl;
        return 0.0f;
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

////////////////////////////////////////////////////////////////////////
// Name:       CalculadoraPolaca::agregarCeroAntesDelMenos(std::string expresion)
// Purpose:    Implementation of CalculadoraPolaca::agregarCeroAntesDelMenos()
// Parameters:
// - expresion
// Return:     std::string
////////////////////////////////////////////////////////////////////////

std::string CalculadoraPolaca::agregarCeroAntesDelMenos(std::string expresion)
{
   std::string resultado;
    char caracterAnterior = ' ', caracterActual;    
    
    for (int i = 0; i < expresion.length(); ++i) {
        caracterActual = expresion[i];
        if (caracterActual == '-' && (caracterAnterior == '(' || caracterAnterior == ' ')) {
            resultado += "0";
        }
        if (expresion[i] != ' ') {
            caracterAnterior = expresion[i];
        }
        resultado += caracterActual;
    }
  
    return resultado;
}