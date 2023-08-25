#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <vector> // Para almacenar las cédulas generadas

// Función que busca de forma lineal un elemento en un vector.
bool buscarEnVector(const std::vector<std::string>& vec, const std::string& elemento) {
    for (const std::string& item : vec) {
        if (item == elemento) {
            return true; // El elemento se encuentra en el vector
        }
    }
    return false; // El elemento no se encuentra en el vector
}

std::string generarCedulaUnica(std::vector<std::string>& cedulasGeneradas) {
    std::string cedula;
    
    while (true) {
        cedula = "";
        int region = rand() % 25;
        
        if (region == 0) {
            cedula = "30";
        } else if(region < 10) {
            cedula += "0";
            cedula += std::to_string(region);
        } else {
            cedula = std::to_string(region);
        }

        // Completa los dígitos restantes de la cédula
        for (int i = 0; i < 7; i++) {
            cedula += std::to_string(rand() % 10);
        }

        // Agrupamos todos los pares y los sumamos
        int pares = std::stoi(cedula.substr(1, 1)) + std::stoi(cedula.substr(3, 1)) + std::stoi(cedula.substr(5, 1)) + std::stoi(cedula.substr(7, 1));

        // Agrupamos los impares, los multiplicamos por un factor de 2, si el número resultante es > que 9 le restamos 9 al resultante
        int numero1 = std::stoi(cedula.substr(0, 1));
        numero1 *= 2;
        if (numero1 > 9) {
            numero1 -= 9;
        }

        int numero3 = std::stoi(cedula.substr(2, 1));
        numero3 *= 2;
        if (numero3 > 9) {
            numero3 -= 9;
        }

        int numero5 = std::stoi(cedula.substr(4, 1));
        numero5 *= 2;
        if (numero5 > 9) {
            numero5 -= 9;
        }

        int numero7 = std::stoi(cedula.substr(6, 1));
        numero7 *= 2;
        if (numero7 > 9) {
            numero7 -= 9;
        }

        int numero9 = std::stoi(cedula.substr(8, 1));
        numero9 *= 2;
        if (numero9 > 9) {
            numero9 -= 9;
        }

        int impares = numero1 + numero3 + numero5 + numero7 + numero9;

        // Suma total
        int suma_total = pares + impares;

        // Extraemos el primer dígito
        std::string primer_digito_suma = std::to_string(suma_total).substr(0, 1);

        // Obtenemos la decena inmediata
        int decena = (std::stoi(primer_digito_suma) + 1) * 10;

        // Obtenemos la resta de la decena inmediata - la suma_total, esto nos da el dígito validador
        int digito_validador = decena - suma_total;

        // Si el dígito validador es igual a 10, toma el valor de 0
        if (digito_validador == 10) {
            digito_validador = 0;
        }

        cedula += std::to_string(digito_validador);

        // Verificar si la cédula ya fue generada antes
        if (!buscarEnVector(cedulasGeneradas, cedula)) {
            // La cédula es única, la agregamos al vector de cédulas generadas y la retornamos
            cedulasGeneradas.push_back(cedula);
            return cedula;
        }
        // Si la cédula ya existe, se generará una nueva en el siguiente ciclo.
    }
}

std::string generarNombreAleatorio() {
    // Genera un nombre aleatorio (puedes personalizar esta parte)
    std::string nombres[] = { 
        "JUAN", "MARIA", "PEDRO", "ANA", "LUIS", 
        "LAURA", "CARLOS", "ELENA", "JOSE", "MARTA", 
        "ANTONIO", "ISABEL", "FRANCISCO", "SOFIA", "MIGUEL", 
        "LUCIA", "MANUEL", "CARMEN", "ALEJANDRO", "EVA",
        "FERNANDO", "ROSA", "JAVIER", "BEATRIZ", "DIEGO",
        "PILAR", "ROBERTO", "MARIA TERESA", "ANDRES", "PATRICIA",
        "RAFAEL", "LORENA", "GABRIEL", "EUGENIA", "ALBERTO",
        "VICTORIA", "FELIPE", "ROCIO", "VICTOR", "CAROLINA",
        "ENRIQUE", "MONICA", "JORGE", "PAULA", "ARMANDO",
        "ELISA", "FEDERICO", "LOURDES", "GUILLERMO", "MARINA"
    };

    return nombres[rand() % 50];
}

std::string generarApellidoAleatorio() {
    // Genera un apellido aleatorio (puedes personalizar esta parte)
    std::string apellidos[] = { 
        "PEREZ", "GOMEZ", "LOPEZ", "RODRIGUEZ", "FERNANDEZ", 
        "GONZALEZ", "MARTINEZ", "SANCHEZ", "RAMIREZ", "TORRES", 
        "RODRIGUES", "FERREIRA", "SANTOS", "SILVA", "SOUSA",
        "MORENO", "CASTRO", "LIMA", "COSTA", "OLIVEIRA",
        "ALVAREZ", "VARGAS", "GARCIA", "MARTIN", "HERNANDEZ",
        "LARA", "GUTIERREZ", "JIMENEZ", "DIAZ", "CRUZ",
        "ROJAS", "FERRER", "VEGA", "CABRERA", "SOTO",
        "BLANCO", "MENDOZA", "CORTEZ", "MOLINA", "AGUILAR",
        "RIVAS", "FIGUEROA", "ORTEGA", "SUAREZ", "ROMERO",
        "NUNEZ", "BUSTAMANTE", "PINTO", "CHAVEZ", "MIRANDA"
    };

    return apellidos[rand() % 50];
}

std::string generarFechaNacimientoAleatoria() {
    // Genera una fecha de nacimiento aleatoria (puedes personalizar esta parte)
    int dia = rand() % 28 + 1;
    int mes = rand() % 12 + 1;
    int anio = rand() % 60 + 1950;

    char fecha[50];
    sprintf(fecha, "%d/%d/%d-hora:0:0:0", dia, mes, anio);

    return fecha;
}

std::string generarFechaHoraAleatoria() {
    int dia = rand() % 28 + 1;
    int mes = rand() % 12 + 1;
    int anio = rand() % 3 + 2020;
    int hora = rand() % 24;
    int minuto = rand() % 60;
    int segundo = rand() % 60;

    char fechaHora[50];
    sprintf(fechaHora, "%02d/%02d/%d-hora:%02d:%02d:%02d", dia, mes, anio, hora, minuto, segundo);

    return fechaHora;
}

std::string generarRegistrosAleatorios(const std::vector<std::string>& cedulasGeneradas) {
    std::string registro;
    
    while (true) {
        std::string cedula = cedulasGeneradas[rand() % cedulasGeneradas.size()];
        std::string horaEntrada = generarFechaHoraAleatoria();
        
        int contadorRegistro = rand() % 2; // 0 o 1
        std::string horaSalida;

        if (contadorRegistro == 0) {
            horaSalida = "0/0/0-hora:0:0:0";
        } else {
            horaSalida = generarFechaHoraAleatoria();
        }

        registro = cedula + ";" + horaEntrada + ";" + horaSalida + ";" + std::to_string(contadorRegistro);

        return registro;
    }
}

int main() {
    // Inicializar la semilla para la generación de números aleatorios
    srand(static_cast<unsigned>(time(nullptr)));
    std::vector<std::string> cedulasGeneradas; // Vector para almacenar las cédulas generadas
    
    // Crear un archivo CSV y escribir 1000 datos aleatorios
    std::ofstream archivo("EmpleadosAleatorio.csv");
    if (archivo.is_open()) {
        archivo << "CEDULA;NOMBRE;APELLIDO;FECHANACIMIENTO;SUELDO\n";
        for (int i = 0; i < 1000; i++) {
            std::string cedula = generarCedulaUnica(cedulasGeneradas);
            std::string nombre = generarNombreAleatorio();
            std::string apellido = generarApellidoAleatorio();
            std::string fechaNacimiento = generarFechaNacimientoAleatoria();
            double sueldo = (rand() % 5000 + 500) / 10.0;

            archivo << cedula << ";" << nombre << ";" << apellido << ";" << fechaNacimiento << ";" << sueldo << "\n";
        }
        archivo.close();
        std::cout << "Archivo 'datos.csv' generado con exito." << std::endl;
    } else {
        std::cerr << "Error al abrir el archivo" << std::endl;
    }

    std::ofstream registroArchivo("RegistrosAleatorio.csv");
    if (registroArchivo.is_open()) {
        registroArchivo << "CEDULA;FECHA/HORAENTRADA;FECHA/HORASALIDA;CONTADORREGISTRO\n";
        for (int i = 0; i < 1000; i++) { // Cambia 1000 al número deseado de registros
            std::string registro = generarRegistrosAleatorios(cedulasGeneradas);
            registroArchivo << registro << "\n";
        }
        registroArchivo.close();
        std::cout << "Archivo 'RegistrosAleatorio.csv' generado con exito." << std::endl;
    } else {
        std::cerr << "Error al abrir el archivo" << std::endl;
    }

    return 0;
}