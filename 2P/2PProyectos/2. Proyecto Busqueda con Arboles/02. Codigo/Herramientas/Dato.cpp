/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Estructura de Datos 9686
 * Nombres: Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 07/07/23 21:42
 * Fecha de modificacion: 19/07/23 12:25
 * Enunciado:
 * Registro de entrada y salida de personas con listas circulares doblemente
 * enlazadas y búsqueda con árboles binarios + Extras
 *
 *******************************************************************************/ 
#include "Dato.h"
#include "../Modelo/Fecha.h"
#include <iostream>
#include <cstdlib> //funcion atoi()
#include <conio.h> //getch()
#include <cctype>

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       Dato::ingresarMenuOpcion(char limiteInferior, char limiteSuperior)
// Purpose:    Ingresar opcion de menu utilizando limites inferior y superior de las opciones de un menu
// Parameters:
// - limiteInferior
// - limiteSuperior
// Return:     int
////////////////////////////////////////////////////////////////////////////////////////////////////////

int Dato::ingresarMenuOpcion(char limiteInferior, char limiteSuperior) {
	char tecla;
	int opcion = 0;
	bool opcionValida = false;
	
	while (!opcionValida) {
		tecla = getch();
		
		if (tecla == '\r' && opcion > 0) {
			std::cout << std::endl;
			opcionValida = true;
		} else if (tecla == '\b' && opcion > 0) {
			opcion = opcion / 10;
			std::cout << "\b \b";
		} else if (tecla >= limiteInferior && tecla <= limiteSuperior && opcion == 0) {
			opcion = tecla - '0';
			std::cout << tecla;
		}
	}
	
	return opcion;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       Dato::ingresarDimension(char filas, char columnas)
// Purpose:    Ingresar dimensiones válidas para matrices utilizando filas y columnas
// Parameters:
// - filas
// - columnas
// Return:     int
////////////////////////////////////////////////////////////////////////////////////////////////////////

int Dato::ingresarDimension(char filas, char columnas) {
	std::string entrada;
	char tecla;
	int i = 0;
	int dim = 0;

	while (true) {
		tecla = getch(); // lee la tecla ingresada por el usuario sin mostrarla en la consola

		if (tecla == '\r' && entrada.length() > 0) { // si el usuario presiona Enter
			if (i > 0) {
				dim = std::stoi(entrada); // convierte la entrada a un número int
				if (dim >= 2) {
					std::cout << std::endl;
					break; // sale del bucle si la dimensión es válida
				} else {
					std::cout << "La dimension no puede ser menor a 2" << std::endl;
				}
			}
		} else if (tecla == '\b' && i > 0) { // si el usuario presiona Backspace y hay caracteres en la entrada
			i--;
			std::cout << "\b \b"; // borra el último caracter de la consola
			entrada.pop_back(); // elimina el último caracter de la entrada
		} else if (tecla >= filas && tecla <= columnas && i < 1) { // si el usuario ingresa un dígito
			entrada.push_back(tecla); // agrega el caracter a la entrada
			std::cout << tecla; // muestra el caracter ingresado en la consola
			i++;
		}
	}

	return dim; // retorna la dimensión ingresada
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       Dato::ingresarEntero()
// Purpose:    Ingresar numeros enteros válidos de hasta 12 dígitos
// Return:     int
////////////////////////////////////////////////////////////////////////////////////////////////////////

int Dato::ingresarEntero() {
	std::string entrada;
	char tecla;
	int i = 0;

	while (true) {
		tecla = getch(); // lee la tecla ingresada por el usuario sin mostrarla en la consola

		if (tecla == '\r' && entrada.length() > 0) { // si el usuario presiona Enter
			std::cout << std::endl;
			break;
		} else if (tecla == '\b' && i > 0) { // si el usuario presiona Backspace y hay caracteres en la entrada
			i--;
			std::cout << "\b \b"; // borra el último caracter de la consola
			entrada.pop_back(); // elimina el último caracter de la entrada
		} else if (isdigit(tecla) && i < 5) { // si el usuario ingresa un dígito
			entrada.push_back(tecla); // agrega el caracter a la entrada
			std::cout << tecla; // muestra el caracter ingresado en la consola
			i++;
		}
	}

	return std::stoi(entrada); // convierte la entrada a un número int y lo retorna
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       Dato::ingresarFloat()
// Purpose:    Ingresar numeros flotantes válidos de hasta 15 dígitos
// Return:     float
////////////////////////////////////////////////////////////////////////////////////////////////////////

float Dato::ingresarFloat() {
	std::string entrada;
	char tecla;
	int i = 0;
	bool punto = false;
	int signoMenosPos = -1;

	while (true) {
		tecla = getch(); // lee la tecla ingresada por el usuario sin mostrarla en la consola

		if (tecla == '\r' && entrada.length() > 0) { // si el usuario presiona Enter
			if (entrada[0] != '.') {
				std::cout << std::endl;
				break;				
			}			
		} else if (tecla == '\b' && i > 0) { // si el usuario presiona Backspace y hay caracteres en la entrada
			i--;
			std::cout << "\b \b"; // borra el último caracter de la consola
			if (entrada[i] == '.') { // si se eliminó un punto, reinicia el flag de punto
				punto = false;
			}
			if (i == signoMenosPos) { // si se eliminó el signo menos, reinicia la posición del signo menos
				signoMenosPos = -1;
			}
			entrada.pop_back(); // elimina el último caracter de la entrada
		} else if (isdigit(tecla) && i < 15) { // si el usuario ingresa un dígito
			entrada.push_back(tecla); // agrega el caracter a la entrada
			std::cout << tecla; // muestra el caracter ingresado en la consola
			i++;
		} else if (tecla == '.' && !punto) { // si el usuario ingresa un punto y no se ha ingresado ya uno, o si ya se ingresó uno pero se eliminó
			entrada.push_back(tecla); // agrega el caracter a la entrada
			punto = true; // marca que se ha ingresado un punto
			std::cout << tecla;
			i++;
		} else if (tecla == '-' && i == 0) { // si el usuario ingresa un signo menos al principio
			entrada.push_back(tecla); // agrega el caracter a la entrada
			signoMenosPos = i; // marca la posición del signo menos
			std::cout << tecla;
			i++;
		}
	}		

	return std::stof(entrada); // convierte la entrada a un número float y lo retorna
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       Dato::validarLetra(char letra, int posicion)
// Purpose:    Validar letras para matrícula ecuatoriana por posición
// Parameters:
// - letra
// - posicion
// Return:     bool
////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Dato::validarLetraMatricula(char letra, int posicion) {
    bool esValida = false;

    if (posicion == 0) {
        esValida = (letra == 'A' || letra == 'B' || letra == 'U' || letra == 'C' || letra == 'H' || letra == 'X' ||
                    letra == 'O' || letra == 'E' || letra == 'W' || letra == 'G' || letra == 'I' || letra == 'L' ||
                    letra == 'R' || letra == 'V' || letra == 'N' || letra == 'Q' || letra == 'S' || letra == 'P' ||
                    letra == 'Y' || letra == 'J' || letra == 'K' || letra == 'T' || letra == 'Z' || letra == 'M' ||
                    letra == 'a' || letra == 'b' || letra == 'u' || letra == 'c' || letra == 'h' || letra == 'x' ||
                    letra == 'o' || letra == 'e' || letra == 'w' || letra == 'g' || letra == 'i' || letra == 'l' ||
                    letra == 'r' || letra == 'v' || letra == 'n' || letra == 'q' || letra == 's' || letra == 'p' ||
                    letra == 'y' || letra == 'j' || letra == 'k' || letra == 't' || letra == 'z' || letra == 'm');
    } else if (posicion == 1 || posicion == 2) {
        esValida = (letra >= 'A' && letra <= 'Z') || (letra >= 'a' && letra <= 'z');
    }

    return esValida;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       Dato::ingresarPlacaEcuador() 
// Purpose:    ingresar placa completa válida para Ecuador
// Parameters:
// Return:     std::string
////////////////////////////////////////////////////////////////////////////////////////////////////////

std::string Dato::ingresarPlacaEcuador() {
	std::string entrada;
	char tecla;
	int i = 0;

	while (true) {
		tecla = getch(); // lee la tecla ingresada por el usuario sin mostrarla en la consola

		if (tecla == '\r' && (i == 7 || i == 6)) { // si el usuario presiona Enter
			std::cout << std::endl;
			break;
		} else if (tecla == '\b' && i > 0) { // si el usuario presiona Backspace y hay caracteres en la entrada
			i--;
			std::cout << "\b \b"; // borra el último caracter de la consola
			entrada.pop_back(); // elimina el último caracter de la entrada
		} else if (i < 3 && validarLetraMatricula(tecla, i)) { // si el usuario ingresa un caracter (3 primeros caracteres de la placa)
			tecla = toupper(tecla);
			entrada.push_back(tecla); // agrega el caracter a la entrada
			std::cout << tecla; // muestra el caracter ingresado en la consola
			i++;
		} else if (i >= 3 && i < 7 && isdigit(tecla)) { // si el usuario ingresa un dígito (resto de caracteres de la placa)
			entrada.push_back(tecla); // agrega el caracter a la entrada
			std::cout << tecla; // muestra el caracter ingresado en la consola
			i++;
		}
	}

	return entrada;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       Dato::ingresarCedulaEcuador() 
// Purpose:    ingresar numero de cédula válido para Ecuador
// Parameters:
// Return:     std::string
////////////////////////////////////////////////////////////////////////////////////////////////////////

std::string Dato::ingresarCedulaEcuador() {
    while (true) {
        std::string entrada;
        
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
                entrada.pop_back(); // elimina el último caracter de la entrada
            } else if (i < 10 && isdigit(tecla)) { // si el usuario ingresa un dígito
                entrada.push_back(tecla); // agrega el caracter a la entrada
                std::cout << tecla; // muestra el caracter ingresado en la consola
                i++;
            }
        }

        if (entrada.length() == 10) {
            // Obtenemos el digito de la region que son los dos primeros digitos
            std::string digito_region = entrada.substr(0, 2);

            // Preguntamos si la region existe, Ecuador se divide en 24 regiones
            if ((std::stoi(digito_region) >= 1 && std::stoi(digito_region) <= 24) || std::stoi(digito_region) == 30) {

                // Extraemos el ultimo digito
                std::string ultimo_digito = entrada.substr(9, 1);

                // Agrupamos todos los pares y los sumamos
                int pares = std::stoi(entrada.substr(1, 1)) + std::stoi(entrada.substr(3, 1)) + std::stoi(entrada.substr(5, 1)) + std::stoi(entrada.substr(7, 1));

                // Agrupamos los impares, los multiplicamos por un factor de 2, si el numero resultante es > que 9 le restamos 9 al resultante
                int numero1 = std::stoi(entrada.substr(0, 1));
                numero1 *= 2;
                if (numero1 > 9) {
                    numero1 -= 9;
                }

                int numero3 = std::stoi(entrada.substr(2, 1));
                numero3 *= 2;
                if (numero3 > 9) {
                    numero3 -= 9;
                }

                int numero5 = std::stoi(entrada.substr(4, 1));
                numero5 *= 2;
                if (numero5 > 9) {
                    numero5 -= 9;
                }

                int numero7 = std::stoi(entrada.substr(6, 1));
                numero7 *= 2;
                if (numero7 > 9) {
                    numero7 -= 9;
                }

                int numero9 = std::stoi(entrada.substr(8, 1));
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
                int decena = (std::stoi(primer_digito_suma) + 1) * 10;

                // Obtenemos la resta de la decena inmediata - la suma_total, esto nos da el digito validador
                int digito_validador = decena - suma_total;

                // Si el digito validador es igual a 10, toma el valor de 0
                if (digito_validador == 10) {
                    digito_validador = 0;
                }

                // Validamos que el digito validador sea igual al de la cedula
                if (digito_validador == std::stoi(ultimo_digito)) {
                    return entrada;
                } else {
                    std::cout << "La cedula: " << entrada << " es incorrecta" << std::endl;
                }

            } else {
                // Imprimimos en consola si la region no pertenece
                std::cout << "Esta cedula no pertenece a ninguna region" << std::endl;
            }
        } else {
            // Imprimimos en consola si la cedula tiene menos o más de 10 digitos
            std::cout << "Esta cedula tiene menos de 10 digitos" << std::endl;
        }

        std::cout << "Vuelva a ingresar la cedula: ";
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       Dato::validarAnio(int anio)
// Purpose:    Validar año entre un año limite inferior  y año actual
// Parameters:
// - anio
// Return:     bool
////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Dato::validarAnio(int anio){
	Fecha fechaActual;
    return (anio>= 1950 && anio<= fechaActual.getAnio());
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       Dato::ingresarAnio()
// Purpose:    Ingresar año válido
// Return:     int
////////////////////////////////////////////////////////////////////////////////////////////////////////

int Dato::ingresarAnio() {
    Fecha fechaActual;

    while (true) {
        std::string entrada;
        char tecla;
        int i = 0;
        while (true) {
            tecla = getch(); // lee la tecla ingresada por el usuario sin mostrarla en la consola

            if (tecla == '\r' && i == 4) { // si el usuario presiona Enter
                std::cout << std::endl;
                break;
            } else if (tecla == '\b' && i > 0) { // si el usuario presiona Backspace y hay caracteres en la entrada
                i--;
                std::cout << "\b \b"; // borra el último caracter de la consola
                entrada.pop_back(); // elimina el último caracter de la entrada
            } else if (i < 4 && isdigit(tecla)) { // si el usuario ingresa un dígito
                entrada.push_back(tecla); // agrega el caracter a la entrada
                std::cout << tecla; // muestra el caracter ingresado en la consola
                i++;
            }
        }

        int entrada1 = std::stoi(entrada);
        if (validarAnio(entrada1)) {
            return entrada1;
        }

        std::cout << "Anio invalido. Intente nuevamente (1950-" << fechaActual.getAnio() << "): ";
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       Dato::ingresarNombreSimple()
// Purpose:    Ingresar un solo nombre válido
// Return:     std::string
////////////////////////////////////////////////////////////////////////////////////////////////////////

std::string Dato::ingresarNombreSimple() {
	std::string entrada;
	char tecla;
	int i = 0;
	
	while (true) {
		tecla = getch();
		
		if (tecla == '\r' && i > 0) {
			std::cout << std::endl;
			break;
		} else if (tecla == '\b' && i > 0) {
			i--;
			std::cout << "\b \b";
			entrada.pop_back();
		} else if (i < 15 && isalpha(tecla)) {
			tecla = toupper(tecla);
			entrada.push_back(tecla);
			std::cout << tecla;
			i++;
		}
	}
	
	return entrada;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       Dato::ingresarNombreCompleto()
// Purpose:    Ingresar 2 elementos (nombre y apellido) para nombre válidos
// Return:     std::string
////////////////////////////////////////////////////////////////////////////////////////////////////////

std::string Dato::ingresarNombreCompleto() {
    std::string entrada;
    char tecla;
    int i = 0;
    char ultimo;
    while (true) {
        tecla = getch(); // lee la tecla ingresada por el usuario sin mostrarla en la consola
        if (tecla == '\r' && i > 0) { // si el usuario presiona Enter
            if(ultimo != ' '){
            	std::cout << std::endl;
            	break;	
			}
            
        } else if (tecla == '\b' && i > 0) { // si el usuario presiona Backspace y hay caracteres en la entrada
            i--;
            std::cout << "\b \b"; // borra el último caracter de la consola
            entrada.pop_back(); // elimina el último caracter de la entrada
            ultimo = tecla;
        } else if (i <= 15 && isalpha(tecla)) { // si el usuario ingresa una letra
            tecla = toupper(tecla);
            entrada.push_back(tecla); // agrega el caracter a la entrada
            std::cout << tecla; // muestra el caracter ingresado en la consola
            i++;
            ultimo = tecla;
        } else if (i > 0 && tecla == ' ' && entrada.find(' ') == std::string::npos) { // si el usuario ingresa un espacio y no hay espacios en la entrada
            entrada.push_back(tecla); // agrega el caracter a la entrada
            std::cout << tecla; // muestra el caracter ingresado en la consola
            i++;
            ultimo = tecla;
        }
    }

    return entrada;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       Dato::ingresarModelo()
// Purpose:    Ingrsar modelo de vehículo válido
// Return:     std::string
////////////////////////////////////////////////////////////////////////////////////////////////////////

std::string Dato::ingresarModelo() {
    std::string entrada;
    char tecla;
    int i = 0;
    bool espacio = false;
    char ultimo = tecla;
    while (true) {
        tecla = getch(); // lee la tecla ingresada por el usuario sin mostrarla en la consola
        if (tecla == '\r' && i > 0) { // si el usuario presiona Enter
	        if(ultimo != '-'){
	        	std::cout << std::endl;
	            break;	
			} 
        } else if (tecla == '\b' && i > 0) { // si el usuario presiona Backspace y hay caracteres en la entrada
            i--;
            std::cout << "\b \b"; // borra el último caracter de la consola
            entrada.pop_back(); // elimina el último caracter de la entrada
        } else if (i <= 15 && (isalpha(tecla) || isdigit(tecla))) { // si el usuario ingresa una letra o un dígito
            tecla = toupper(tecla);
            entrada.push_back(tecla); // agrega el caracter a la entrada
            std::cout << tecla; // muestra el caracter ingresado en la consola
            i++;
            char ultimo = tecla;
        } else if (i > 0 && tecla == '-' && entrada.find('-') == std::string::npos) { // si el usuario ingresa un guion y no hay guiones en la entrada
            entrada.push_back(tecla); // agrega el caracter a la entrada
            std::cout << tecla; // muestra el caracter ingresado en la consola
            i++;
            char ultimo = tecla;
        }
    }

    return entrada;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       Dato::validarFecha(Fecha fecha)
// Purpose:    Validar una fecha de tipo Fecha
// Parameters:
// - fecha
// Return:     bool
////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Dato::validarFecha(Fecha fecha){
	Fecha fechaActual;
	int anio, mes, dia;
	int anioA, mesA, diaA;
	
	anio = fecha.getAnio();
	mes = fecha.getMes();
	dia = fecha.getDia();			
	
	anioA = fechaActual.getAnio();
	mesA = fechaActual.getMes();
	diaA = fechaActual.getDia();		
	
    bool esBisiesto = (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);

    // Verificar si el mes está dentro del rango válido (1-12)
    if (mes < 1 || mes > 12) {
    	std::cout << "Fecha no valida, vuelva a intentar" << std::endl;
        return false;
    }

    // Verificar los días según el mes
    int diasEnMes;

    switch (mes) {
        case 2:
            diasEnMes = esBisiesto ? 29 : 28;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            diasEnMes = 30;
            break;
        default:
            diasEnMes = 31;
    }

    // Verificar si el día está dentro del rango válido para el mes
    if (dia < 1 || dia > diasEnMes) {
    	std::cout << "Fecha no valida, vuelva a intentar" << std::endl;
        return false;
    }

	if (anio > anioA) {
		std::cout << "Fecha no valida, vuelva a intentar" << std::endl;
		return false;
	}
	
	if (anio == anioA && mes > mesA) {
		std::cout << "Fecha no valida, vuelva a intentar" << std::endl;
		return false;
	}
	
	if (anio == anioA && mes == mesA && dia > diaA) {
		std::cout << "Fecha no valida, vuelva a intentar" << std::endl;
		return false;
	}

    // Si pasa todas las validaciones anteriores, la fecha es valida
    return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:       Dato::ingresarFechaCumple()
// Purpose:    Ingrsar fecha de cumpleaños o nacimiento válida
// Return:     Fecha
////////////////////////////////////////////////////////////////////////////////////////////////////////

Fecha Dato::ingresarFechaCumple(){
	Fecha fecha;
	Fecha fechaActual;
	int dia, mes, anio;
	bool fechaValida = false;
	
	do {
		std::cout << "Ingrese el anio: ";
		anio = ingresarEntero();
		std::cout <<"Ingrese el mes: ";
		mes = ingresarEntero();
		std::cout << "Ingrese el dia: ";
		dia = ingresarEntero();
		
		fecha = Fecha(anio, mes, dia, 0, 0, 0);
		
		fechaValida = validarFecha(fecha);
		
		if (!fechaValida) {
			std::cout << "Fecha no valida, vuelva a intentar" << std::endl;
		} else {
			if (fechaActual.getAnio() - fecha.getAnio() < 18) {
				fechaValida = false;
				std::cout << "No puede registrar a personas menores de edad" << std::endl;
			}
		}
		
	} while (!fechaValida);
	
	return fecha;
}

