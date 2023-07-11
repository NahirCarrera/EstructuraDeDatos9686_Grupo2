/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Estructura de Datos 9686
 * Nombres: Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 07/07/23 21:42
 * Fecha de modificacion: 07/07/23 21:42
 * Enunciado:
 * Registro de entrada y salida de personas con listas circulares doblemente
 * enlazadas y búsqueda con árboles binarios + Extras
 *
 *******************************************************************************/  

#include "../Modelo/Fecha.h"
#include <ctime>
#include <locale>
#include <iostream>

////////////////////////////////////////////////////////////////////////
// Name:       Fecha::Fecha()
// Purpose:    Implementation of Fecha::Fecha()
// Return:     
////////////////////////////////////////////////////////////////////////

Fecha::Fecha()
{
   	// Establece la configuración regional en español
    setlocale(LC_ALL, "es_ES.UTF-8");

    // Obtiene el tiempo actual del sistema
    std::time_t tiempoActual = std::time(nullptr);

    // Convierte el tiempo en una estructura tm
    std::tm* tiempoLocal = std::localtime(&tiempoActual);

    // Obtiene los componentes de fecha y hora
	this->dia = tiempoLocal->tm_mday;
	this->mes = tiempoLocal->tm_mon+1;
    this->anio = tiempoLocal->tm_year + 1900;
    this->hora = tiempoLocal->tm_hour;
    this->minuto = tiempoLocal->tm_min;
    this->segundo = tiempoLocal->tm_sec;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fecha::~Fecha()
// Purpose:    Implementation of Fecha::~Fecha()
// Return:     
////////////////////////////////////////////////////////////////////////

Fecha::~Fecha()
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Fecha::Fecha(int anio, int mes, int dia, int hora, int minuto, int segundo)
// Purpose:    Implementation of Fecha::Fecha()
// Parameters:
// - anio
// - mes
// - dia
// - hora
// - minuto
// - segundo
// Return:     
////////////////////////////////////////////////////////////////////////

Fecha::Fecha(int anio, int mes, int dia, int hora, int minuto, int segundo) {
	this->dia = dia;
	this->mes = mes;
    this->anio = anio;
    this->hora = hora;
    this->minuto = minuto;
    this->segundo = segundo;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fecha::getAnio()
// Purpose:    Implementation of Fecha::getAnio()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Fecha::getAnio(void) const
{
   return anio;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fecha::setAnio(int newAnio)
// Purpose:    Implementation of Fecha::setAnio()
// Parameters:
// - newAnio
// Return:     void
////////////////////////////////////////////////////////////////////////

void Fecha::setAnio(int newAnio)
{
   anio = newAnio;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fecha::getMes()
// Purpose:    Implementation of Fecha::getMes()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Fecha::getMes(void) const
{
   return mes;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fecha::setMes(int newMes)
// Purpose:    Implementation of Fecha::setMes()
// Parameters:
// - newMes
// Return:     void
////////////////////////////////////////////////////////////////////////

void Fecha::setMes(int newMes)
{
   mes = newMes;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fecha::getDia()
// Purpose:    Implementation of Fecha::getDia()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Fecha::getDia(void) const
{
   return dia;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fecha::setDia(int newDia)
// Purpose:    Implementation of Fecha::setDia()
// Parameters:
// - newDia
// Return:     void
////////////////////////////////////////////////////////////////////////

void Fecha::setDia(int newDia)
{
   dia = newDia;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fecha::getHora()
// Purpose:    Implementation of Fecha::getHora()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Fecha::getHora(void) const
{
   return hora;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fecha::setHora(int newHora)
// Purpose:    Implementation of Fecha::setHora()
// Parameters:
// - newHora
// Return:     void
////////////////////////////////////////////////////////////////////////

void Fecha::setHora(int newHora)
{
   hora = newHora;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fecha::getMinuto()
// Purpose:    Implementation of Fecha::getMinuto()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Fecha::getMinuto(void) const
{
   return minuto;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fecha::setMinuto(int newMinuto)
// Purpose:    Implementation of Fecha::setMinuto()
// Parameters:
// - newMinuto
// Return:     void
////////////////////////////////////////////////////////////////////////

void Fecha::setMinuto(int newMinuto)
{
   minuto = newMinuto;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fecha::getSegundo()
// Purpose:    Implementation of Fecha::getSegundo()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Fecha::getSegundo(void) const
{
   return segundo;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fecha::setSegundo(int newSegundo)
// Purpose:    Implementation of Fecha::setSegundo()
// Parameters:
// - newSegundo
// Return:     void
////////////////////////////////////////////////////////////////////////

void Fecha::setSegundo(int newSegundo)
{
   segundo = newSegundo;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fecha::operator <<(std::ostream& os, const Fecha& fechaActual)
// Purpose:    Implementation of Fecha::operator <<()
// Parameters:
// - os
// - fechaActual
// Return:     std::ostream&
////////////////////////////////////////////////////////////////////////

std::ostream& operator <<(std::ostream& os, const Fecha& fechaActual){
	os<<std::to_string(fechaActual.dia) + "/"+std::to_string(fechaActual.mes)+"/"+std::to_string(fechaActual.anio)+" - hora: "+
	std::to_string(fechaActual.hora)+":"+std::to_string(fechaActual.minuto)+":"+std::to_string(fechaActual.segundo);
	return os;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fecha::obtenerFechaFormateada()
// Purpose:    Crea una cadena con la fecha formateada AAMMDDHHMMSS
// Return:     std::string
////////////////////////////////////////////////////////////////////////

std::string Fecha::obtenerFechaFormateada(){
	return (std::to_string(anio) + std::to_string(mes) + std::to_string(dia) + std::to_string(hora) + std::to_string(minuto) + std::to_string(segundo));
}



