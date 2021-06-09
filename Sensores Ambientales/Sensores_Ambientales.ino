/****************************************************
* Práctica:  Curso avanzado de Arduino – Proyecto Final
* Autor: Carlos Pérez Pérez <carlos@atlantisnesos.com>
* Fecha: 09/12/2014
*****************************************************/

#include <DHT.h>
#include <Event.h>
#include <Timer.h>
#include <SD.h>


// Ficheros propios
#include "lecturaDatos.h"

// Variables
Timer t;
int tiempo = 10; // Tiempo en segundos para el Timer

void setup() {
  // configuramos todo
  //Faltaria una funcion para leer la configuracion desde SD si existe o inicializar con parametros generales
  Serial.begin(9600);
  iniciarSensores();
  t.every(1*tiempo*1000, leerDatos); // Cada  X segundos leemos los datos, no necesitamos tiempo real

}

void loop() {
  t.update();  // Actualizar  
}

  


