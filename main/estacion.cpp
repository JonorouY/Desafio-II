#include "estacion.h"
#include "funciones.h"

Estacion::Estacion() {
    tiempoAntes=-1;
    tiempoDespues=-1;
    nombre= "";
}
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

int Estacion::TiempoAntes() const{
    return tiempoAntes;
}

int Estacion::TiempoDespues() const{
    return tiempoDespues;
}
string Estacion::Nombre() const{
    return nombre;
}


int Estacion::getCantEstaciones(void){
    return cantEstaciones;
}

string Estacion::getNombre(void){
    return nombre;
}

void Estacion::setTiempoAntes(int tiempoA){
    tiempoAntes = tiempoA;
}

void Estacion::setTiempoDespues(int tiempoD){
    tiempoDespues = tiempoD;
}

void Estacion::setCantEstaciones(int cantidad){
    cantEstaciones = cantidad;
}

void Estacion::operator=(const Estacion& nuevaEstacion){
    tiempoAntes = nuevaEstacion.TiempoAntes();
    tiempoDespues = nuevaEstacion.TiempoDespues();
    nombre = nuevaEstacion.Nombre();
}
bool Estacion::operator==(const Estacion& nuevaEstacion){
    return((this->tiempoAntes==nuevaEstacion.TiempoAntes()) && (this->tiempoDespues==nuevaEstacion.TiempoDespues()) && (this->nombre==nuevaEstacion.Nombre()));
}
Estacion::~Estacion(){}
