/****************************************************
* Práctica: Práctica 2 Curso avanzado de Arduino
* Autor: Carlos Pérez Pérez <carlos@atlantisnesos.com>
* Fecha: 21/11/2014
*****************************************************/

#include <Arduino.h>
#include <SPI.h>
//#include <Ethernet.h>
//#include <EthernetUdp.h>
#include "DHT.h" // Para usar sensores de DHT de temp y humedad

#include "guardarDatos.h"

// Pines utilizados
//#define pinHumedad A1
//#define pinTemp A4
#define pinLluvia A0
#define pinGases A2
#define pinViento A3
#define DHTPIN 7
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

int valorTemp=0;
int valorHumedad=0;
int valorLluvia=0;
int valorGases=0;
int valorViento=0;

void iniciarSensores()
{
//  pinMode(pinHumedad, INPUT);
//  pinMode(pinTemp, INPUT);
  pinMode(pinLluvia, INPUT);
  pinMode(pinGases, INPUT);
  pinMode(pinViento, INPUT);
  dht.begin(); // Iniciar sensor DHT para temp y humedad
  
} // Fin iniciar sensores


void leerDatos()
{
  // Leer los datos desde pines
  //Este código es susceptible de cambiar por lectura de puertos
  // Añadir condiciones de error
  String Datos = "DATA;T:";
  
   float h = dht.readHumidity();
   float t = dht.readTemperature();
   // Transform to String
   String valorTemp = String((int) t);
   String valorHumedad = String((int) h);
  
  // valorTemp=analogRead(pinTemp);
  Datos += valorTemp;
  //  valorHumedad=analogRead(pinHumedad);
  Datos = Datos + ";H:";
  Datos = Datos + valorHumedad; 
  valorLluvia=analogRead(pinLluvia);
  Datos = Datos + ";LL:";
  Datos = Datos + valorLluvia;
  valorGases=analogRead(pinGases);
  Datos = Datos + ";G:";
  Datos = Datos + valorGases;
  valorViento=analogRead(pinViento);
  Datos = Datos + ";V:" ;
  Datos = Datos + valorViento;
  enviarSD(Datos);//Enviamos los datos a la tarjeta SD
  Serial.print(Datos); // Imprimir a Serial para uso con Xbee y control desde ordenador
} // Fin fucnion leeDatos()
