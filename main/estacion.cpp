#include "estacion.h"
#include "funciones.h"

Estacion::Estacion(int tiempoA, int tiempoD, string name) {

    tiempoAntes = tiempoA; tiempoDespues = tiempoD ; nombre = name;
    cantEstaciones++;
}

Estacion::Estacion(int tiempoA, int tiempoD, string name, string lineaA) {

    tiempoAntes = tiempoA; tiempoDespues = tiempoD ; nombre = name; linea = lineaA;
}

int Estacion::getTiempoAntes(void){
    return tiempoAntes;
}

int Estacion::getTiempoDespues(void){
    return tiempoDespues;
}

int Estacion::getCantEstaciones(void){
    return cantEstaciones;
}

string Estacion::getNombre(void){
    return nombre;
}

Estacion::setTiempoAntes(int tiempoA){
    tiempoAntes = tiempoA;
}

Estacion::setTiempoDespues(int tiempoD){
    tiempoDespues = tiempoD;
}

Estacion::setCantEstaciones(int cantidad){
    cantEstaciones = cantidad;
}

Estacion::~Estacion(){};
