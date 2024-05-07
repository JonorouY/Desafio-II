#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <string>
#include "estacion.h"

Estacion** aumentarLineasED(Estacion **estructura, int primero, int segundo);
Estacion** aumentarEstacionED(Estacion **estructura, int primero, int segundo);
void limpiarPantalla();
string* aumentarNomLineaED(string *estructura,int primero);
Estacion** agregarEstacion(Estacion **estructura, int primero, int segundo,int lineaPosicion,int posicionAgregar,Estacion estacionAgregar,int *k);
Estacion** eliminarEstacion(Estacion **estructura, int primero, int segundo,int lineaPosicion,int posicionEliminar);
#endif // FUNCIONES_H
