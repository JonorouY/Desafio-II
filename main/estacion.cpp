#include "estacion.h"
#include "funciones.h"

Estacion::Estacion() {
    tiempoAntes=-1;
    tiempoDespues=-1;
    nombre= "";
    linea=" ";
}
Estacion::Estacion(int tiempoA, int tiempoD, string name) {

    tiempoAntes = tiempoA;
    tiempoDespues = tiempoD;
    nombre = name;
    linea = " ";
}

Estacion::Estacion(int tiempoA, int tiempoD, string name, string lineaActual) {

    tiempoAntes = tiempoA;
    tiempoDespues = tiempoD;
    nombre = name;
    linea = lineaActual;
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
string Estacion::LineaA() const{
    return linea;
}

string Estacion::getNombre(void){
    return nombre;
}

string Estacion::getLineaA(void){
    return linea;
}

void Estacion::setTiempoAntes(int tiempoA){
    tiempoAntes = tiempoA;
}

void Estacion::setTiempoDespues(int tiempoD){
    tiempoDespues = tiempoD;
}

void Estacion::operator=(const Estacion& nuevaEstacion){
    tiempoAntes = nuevaEstacion.TiempoAntes();
    tiempoDespues = nuevaEstacion.TiempoDespues();
    nombre = nuevaEstacion.Nombre();
    linea = nuevaEstacion.LineaA();
}
bool Estacion::operator==(const Estacion& nuevaEstacion){
    return((this->tiempoAntes==nuevaEstacion.TiempoAntes()) && (this->tiempoDespues==nuevaEstacion.TiempoDespues()) && (this->nombre==nuevaEstacion.Nombre())&& (this->linea==nuevaEstacion.Nombre()));
}
Estacion::~Estacion(){}
