
/****************************************************
* Práctica:  Curso avanzado de Arduino – Proyecto Final
* Autor: Carlos Pérez Pérez <carlos@atlantisnesos.com>
* Fecha: 21/11/2014
*****************************************************/

#include <Arduino.h>
#include <SD.h>

// Funciones de guardado de datos

// Función para enviar datos a SD
void enviarSD(String Datos)
{
  // Funciones de envío por SD
 File fichero;
 const int chipSelect = 4;
 const int pinSD = 10; 
 pinMode(pinSD, OUTPUT);
 
  if (!SD.begin(chipSelect)) {
  //  Serial.println("\n No funciona la tarjeta o no esta presente");
    return; 
  }// fin if SD

  File dataFile = SD.open("datos_ambientales.txt", FILE_WRITE); // fichero en el raiz
  if (dataFile) {
    dataFile.println(Datos);
    dataFile.close();
    // print to the serial port too:
    Serial.println(Datos);
  }  
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error abriendo datalog.txt");
  }
  Serial.println("Cadena pasada: " + Datos);  
} // Fin funcion enviarSD
