/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Estructura de Datos 9686
 * Nombres: Carrera Nahir, Drouet Stephen
 * Fecha de creacion: 07/07/23 21:42
 * Fecha de modificacion: 25/08/23 02:04
 * Enunciado:
 * Analisis Big-O del proyecto de Registro de Personas
 *
 *******************************************************************************/ 
#ifndef _METRICS_H_
#  define _METRICS_H_

#  include "pdf.h"

   class Metrics
   {
      public:

         static int *get(PDF::Font theFont);

      private:

         Metrics();
   };

#endif
