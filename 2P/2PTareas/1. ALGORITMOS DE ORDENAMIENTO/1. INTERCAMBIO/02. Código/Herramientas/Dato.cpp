/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Nombres: Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 14/06/23 18:57
 * Fecha de modificacion: 19/06/23 23:33
 * Enunciado:
 * Registro de entrada y salida de personas con listas circulares doblemente
 * enlazadas y algoritmo de búsqueda por intercambio
 *
 *******************************************************************************/ 

#include "Dato.h"
#include "../Modelo/Fecha.h"
#include <iostream>
#include <cstdlib> //funcion atoi()
#include <conio.h> //getch()
#include <cctype>
//Ingresar numeros de menu
int Dato::ingresarMenuOpcion(char cnum1, char cnum2) {		
	char *entrada = new char[30];
	char tecla;
	int i = 0;
	
	while (true) {
		tecla = getch(); // lee la tecla ingresada por el usuario sin mostrarla en la consola
		
		if (tecla == '\r' && i==1) { // si el usuario presiona Enter
		  std::cout << std::endl;
		  break;
		} else if (tecla == '\b' && i > 0) { // si el usuario presiona Backspace y hay caracteres en la entrada			
			i--;						
			std::cout << "\b \b"; // borra el último caracter de la consola
			entrada[i] = 0; // elimina el último caracter de la entrada
		} else if (tecla >= cnum1 && tecla <= cnum2 && i<1) { // si el usuario ingresa un dígito
			  entrada[i++] = tecla;
			  std::cout << tecla; // muestra el caracter ingresado en la consola
		}
	}

	return atoi(entrada); // convierte la entrada a un número int y lo retorna
}

//Ingresar dimensiones para matrices
int Dato::ingresarDimension(char cnum1, char cnum2) {		
	char *entrada = new char[30];
	char tecla;
	int i = 0;
	int dim;
	
	while (true) {
		tecla = getch(); // lee la tecla ingresada por el usuario sin mostrarla en la consola
		
		if (tecla == '\r') { // si el usuario presiona Enter
		  dim = atoi(entrada);
		  if (dim >= 2) {
			std::cout << std::endl;
		  	break;	
		  } else {
		  	std::cout << "La dimension no puede ser menor a 2" << std::endl;
		  }
		  
		} else if (tecla == '\b' && i > 0) { // si el usuario presiona Backspace y hay caracteres en la entrada			
			i--;						
			std::cout << "\b \b"; // borra el último caracter de la consola
			entrada[i] = 0; // elimina el último caracter de la entrada
		} else if (tecla >= cnum1 && tecla <= cnum2 && i<1) { // si el usuario ingresa un dígito
			  entrada[i++] = tecla;
			  std::cout << tecla; // muestra el caracter ingresado en la consola
		}
	}

	return dim; // convierte la entrada a un número int y lo retorna
}

//Ingresar numeros enteros
int Dato::ingresarEntero() {		
	char *entrada = new char[30];
	char tecla;
	int i = 0;
	
	while (true) {
		tecla = getch(); // lee la tecla ingresada por el usuario sin mostrarla en la consola
		
		if (tecla == '\r') { // si el usuario presiona Enter
		  std::cout << std::endl;
		  break;
		} else if (tecla == '\b' && i > 0) { // si el usuario presiona Backspace y hay caracteres en la entrada			
			i--;						
			std::cout << "\b \b"; // borra el último caracter de la consola
			entrada[i] = 0; // elimina el último caracter de la entrada
		} else if (isdigit(tecla) && i<12) { // si el usuario ingresa un dígito
			  entrada[i++] = tecla;
			  std::cout << tecla; // muestra el caracter ingresado en la consola
		}
	}

	return atoi(entrada); // convierte la entrada a un número int y lo retorna
}


float Dato::ingresarFloat() {
	char *entrada = new char[30];
	char tecla;
	int i = 0;
	bool punto = false;
	int signoMenosPos = -1;
	while(true){
		tecla = getch(); // lee la tecla ingresada por el usuario sin mostrarla en la consola
		
		if (tecla == '\r') { // si el usuario presiona Enter
		  std::cout << std::endl;
		  break;
		} else if (tecla == '\b' && i > 0) { // si el usuario presiona Backspace y hay caracteres en la entrada			
			i--;						
			std::cout << "\b \b"; // borra el último caracter de la consola
			if (entrada[i] == '.') { // si se eliminó un punto, reinicia el flag de punto
				punto = false;
			}
			if (i == signoMenosPos) { // si se eliminó el signo menos, reinicia la posición del signo menos
				signoMenosPos = -1;
			}
			entrada[i] = 0; // elimina el último caracter de la entrada
		} else if (isdigit(tecla) && i < 15) { // si el usuario ingresa un dígito
			  entrada[i++] = tecla;
			  std::cout << tecla; // muestra el caracter ingresado en la consola
		} else if (tecla == '.' && !punto) { // si el usuario ingresa un punto y no se ha ingresado ya uno, o si ya se ingresó uno pero se eliminó
			  entrada[i++] = tecla;
			  punto = true; // marca que se ha ingresado un punto
			  std::cout << tecla;
		} else if (tecla == '-' && i == 0) { // si el usuario ingresa un signo menos al principio
			  entrada[i++] = tecla;
			  signoMenosPos = i - 1; // marca la posición del signo menos
			  std::cout << tecla;
		}
	}

	return atof(entrada); // convierte la entrada a un número float y lo retorna
  
}
bool Dato::validarLetra(char letra, int posicion) {
    const char* letrasPermitidas[] = {
        "ABUCHXOEWGILRVNQSPYJKTZMabuchxoewgilrvnqspyjktzm",   // Letras permitidas para la primera posición
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz", // Letras permitidas para la segunda posición
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"  // Letras permitidas para la tercera posición
    };

    return strchr(letrasPermitidas[posicion], letra) != nullptr; //Busca la primera aparición del caracter
    															// en la cadena correspondiente a la posición de la letra
}

std::string Dato::ingresarPlacaEcuador() {
	char *entrada = new char[7];
	char tecla;
	int i = 0;
	while (true) {
		tecla = getch(); // lee la tecla ingresada por el usuario sin mostrarla en la consola
		
		if (tecla == '\r'  && (i == 7 || i ==6)){ // si el usuario presiona Enter
		  std::cout << std::endl;
		  break;
		} else if (tecla == '\b' && i > 0) { // si el usuario presiona Backspace y hay caracteres en la entrada			
			i--;						
			std::cout << "\b \b"; // borra el último caracter de la consola
			entrada[i] = 0; // elimina el último caracter de la entrada
		} else if (i<3 && validarLetra(tecla, i)) { // si el usuario ingresa un caracter (3 primeros caracteres de la placa)
			tecla = toupper(tecla);
			entrada[i++] = tecla;
			std::cout << tecla; // muestra el caracter ingresado en la consola
		} else if (i>=3 && i<7 && isdigit(tecla)){ //Si el usuario ingresa un dígito (resto de caracteres de la placa)
			entrada[i++] = tecla;
			std::cout << tecla; // muestra el caracter ingresado en la consola
		}		
	}
	return entrada;
}

std::string Dato::ingresarCedulaEcuador() {
    while (true) {
        char *entrada = new char[10];
        
		char tecla;
		int i = 0;
		while (true) {
			tecla = getch(); // lee la tecla ingresada por el usuario sin mostrarla en la consola
			
			if (tecla == '\r' && i == 10) { // si el usuario presiona Enter
			  std::cout << std::endl;
			  break;
			} else if (tecla == '\b' && i > 0) { // si el usuario presiona Backspace y hay caracteres en la entrada			
				i--;						
				std::cout << "\b \b"; // borra el último caracter de la consola
				entrada[i] = 0; // elimina el último caracter de la entrada
			} else if (i<10 &&	isdigit(tecla)) { // si el usuario ingresa un caracter (3 primeros caracteres de la placa)
				entrada[i++] = tecla;
				std::cout << tecla; // muestra el caracter ingresado en la consola
			} 
		}
		entrada[i] = '\0';
		
		std::string cedula(entrada);
		
		if (cedula.length() == 10) {
        
	        // Obtenemos el digito de la region que son los dos primeros digitos
	        std::string digito_region = cedula.substr(0, 2);
	        
	        // Preguntamos si la region existe, Ecuador se divide en 24 regiones
	        if ((stoi(digito_region) >= 1 && stoi(digito_region) <= 24) || stoi(digito_region) == 30) {
	          
	            // Extraemos el ultimo digito
	            std::string ultimo_digito = cedula.substr(9, 1);
	
	            // Agrupamos todos los pares y los sumamos
	            int pares = stoi(cedula.substr(1, 1)) + stoi(cedula.substr(3, 1)) + stoi(cedula.substr(5, 1)) + stoi(cedula.substr(7, 1));
	
	            // Agrupamos los impares, los multiplicamos por un factor de 2, si el numero resultante es > que 9 le restamos 9 al resultante
	            int numero1 = stoi(cedula.substr(0, 1));
	            numero1 *= 2;
	            if (numero1 > 9) {
	                numero1 -= 9;
	            }
	
	            int numero3 = stoi(cedula.substr(2, 1));
	            numero3 *= 2;
	            if (numero3 > 9) {
	                numero3 -= 9;
	            }
	
	            int numero5 = stoi(cedula.substr(4, 1));
	            numero5 *= 2;
	            if (numero5 > 9) {
	                numero5 -= 9;
	            }
	
	            int numero7 = stoi(cedula.substr(6, 1));
	            numero7 *= 2;
	            if (numero7 > 9) {
	                numero7 -= 9;
	            }
	
	            int numero9 = stoi(cedula.substr(8, 1));
	            numero9 *= 2;
	            if (numero9 > 9) {
	                numero9 -= 9;
	            }
	
	            int impares = numero1 + numero3 + numero5 + numero7 + numero9;
	
	            // Suma total
	            int suma_total = pares + impares;
	
	            // Extraemos el primer digito
	            std::string primer_digito_suma = std::to_string(suma_total).substr(0, 1);
	
	            // Obtenemos la decena inmediata
	            int decena = (stoi(primer_digito_suma) + 1) * 10;
	
	            // Obtenemos la resta de la decena inmediata - la suma_total, esto nos da el digito validador
	            int digito_validador = decena - suma_total;
	
	            // Si el digito validador es igual a 10, toma el valor de 0
	            if (digito_validador == 10)
	                digito_validador = 0;
	
	            // Validamos que el digito validador sea igual al de la cedula
	            if (digito_validador == stoi(ultimo_digito)) {
	                return cedula;
	            } else {
	                std::cout << "La cedula: " << cedula << " es incorrecta" << std::endl;
	            }
	          
	        } else {
	            // Imprimimos en consola si la region no pertenece
	            std::cout << "Esta cedula no pertenece a ninguna region" << std::endl;
	        }
	    } else {
	        // Imprimimos en consola si la cedula tiene menos o más de 10 digitos
	        std::cout << "Esta cedula tiene menos de 10 digitos" << std::endl;
	    }
        
        delete[] entrada;
        std::cout << "Vuelva a ingresar la cedula: ";
     
	}
}
bool Dato::validarAnio(int anio){
	Fecha fechaActual;
    return (anio>= 1950 && anio<= fechaActual.getAnio());
}

int Dato::ingresarAnio(){
	Fecha fechaActual;
	
	while (true) {
	char *entrada = new char[4];
	char tecla;
	int i = 0;
	while (true) {
		tecla = getch(); // lee la tecla ingresada por el usuario sin mostrarla en la consola
		
		if (tecla == '\r' && i == 4){ // si el usuario presiona Enter
		  std::cout << std::endl;
		  break;
		} else if (tecla == '\b' && i > 0) { // si el usuario presiona Backspace y hay caracteres en la entrada			
			i--;						
			std::cout << "\b \b"; // borra el último caracter de la consola
			entrada[i] = 0; // elimina el último caracter de la entrada
		} else if (i<4 && isdigit(tecla)){ //Si el usuario ingresa un dígito (resto de caracteres de la placa)
			entrada[i++] = tecla;
			std::cout << tecla; // muestra el caracter ingresado en la consola
		}
	}
		int entrada1 = atoi(entrada);
		if(validarAnio(entrada1)){
			return entrada1;
		};
		delete[] entrada;
        std::cout << "Anio invalido. Intente nuevamente (1950-" << fechaActual.getAnio() <<"): ";
	}
}
std::string Dato::ingresarNombreSimple(){
	char *entrada = new char[15];
	char tecla;
	int i = 0;
	while (true) {
		tecla = getch(); // lee la tecla ingresada por el usuario sin mostrarla en la consola
		if (tecla == '\r' && i >0){ // si el usuario presiona Enter
		  std::cout << std::endl;
		  break;
		} else if (tecla == '\b' && i > 0) { // si el usuario presiona Backspace y hay caracteres en la entrada			
			i--;						
			std::cout << "\b \b"; // borra el último caracter de la consola
			entrada[i] = 0; // elimina el último caracter de la entrada
		} else if (i<=15 && isalpha(tecla)) { // si el usuario ingresa un caracter (3 primeros caracteres de la placa)
			tecla = toupper(tecla);
			entrada[i++] = tecla;
			std::cout << tecla; // muestra el caracter ingresado en la consola
		}		
	}
	entrada[i] = '\0';
	return entrada;
}

std::string Dato::ingresarNombreCompleto(){
	char *entrada = new char[15];
	char tecla;
	int i = 0;
	while (true) {
		tecla = getch(); // lee la tecla ingresada por el usuario sin mostrarla en la consola
		if (tecla == '\r' && i >0){ // si el usuario presiona Enter
		  std::cout << std::endl;
		  break;
		} else if (tecla == '\b' && i > 0) { // si el usuario presiona Backspace y hay caracteres en la entrada			
			i--;						
			std::cout << "\b \b"; // borra el último caracter de la consola
			entrada[i] = 0; // elimina el último caracter de la entrada
		} else if (i<=15 && (isalpha(tecla))) { // si el usuario ingresa un caracter (3 primeros caracteres de la placa)
				tecla = toupper(tecla);
				entrada[i++] = tecla;
				std::cout << tecla; // muestra el caracter ingresado en la consola
		}else if(i > 0 && tecla == ' ' && strchr(entrada, ' ') == nullptr){
				entrada[i++] = tecla;
				std::cout << tecla;
		}		
	}
	entrada[i] = '\0';
	return entrada;
}

std::string Dato::ingresarModelo(){
	char *entrada = new char[15];
	char tecla;
	int i = 0;
	bool espacio = false;
	while (true) {
		tecla = getch(); // lee la tecla ingresada por el usuario sin mostrarla en la consola
		if (tecla == '\r' && i >0){ // si el usuario presiona Enter
		  std::cout << std::endl;
		  break;
		} else if (tecla == '\b' && i > 0) { // si el usuario presiona Backspace y hay caracteres en la entrada			
			i--;						
			std::cout << "\b \b"; // borra el último caracter de la consola
			entrada[i] = 0; // elimina el último caracter de la entrada
		} else if (i<=15 && (isalpha(tecla)||isdigit(tecla))) { // si el usuario ingresa un caracter (3 primeros caracteres de la placa)
				tecla = toupper(tecla);
				entrada[i++] = tecla;
				std::cout << tecla; // muestra el caracter ingresado en la consola
		}else if(i>0 && tecla == '-' && strchr(entrada, '-') == nullptr){
				entrada[i++] = tecla;
				std::cout << tecla;
		}		
	}
	entrada[i] = '\0';
	return entrada;
}



