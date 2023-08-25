#ifndef GENERADORDATOS_H
#define GENERADORDATOS_H

#include <string>
#include <vector> // Para almacenar las cédulas generadas

class GeneradorDatos
{
	private:
		GeneradorDatos();
		~GeneradorDatos();
		static bool buscarEnVector(const std::vector<std::string>& vec, const std::string& elemento);
		static std::string generarCedulaUnica(std::vector<std::string>& cedulasGeneradas);
		static std::string generarNombreAleatorio();
		static std::string generarApellidoAleatorio();
		static std::string generarFechaNacimientoAleatoria();
		static std::string generarFechaHoraAleatoria();
		static std::string generarRegistrosAleatorios(const std::vector<std::string>& cedulasGeneradas);
		
	public:
		static void ejecutar(int cantidad);
};

#endif