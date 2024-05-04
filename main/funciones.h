#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "estacion.h"
#include <iostream>

using namespace std;
/*
int** aumentarLineasDeLaEstDatos(const Estacion **estructura, int primero, int segundo)
{
    //Creamos la copia
    Estacion **copiaEstructura = new Estacion *[primero];
    for(int i = 0 ; i < primero ; i++)
    {
        copiaEstructura[i] = new Estacion [segundo];
    }

    //copiemos lo que hay en la estructura anterior
    for(int i = 0 ; i < primero ; i++)
    {
        for(int j = 0 ; j < segundo ; j++)
        {
            copiaEstructura[i][j] = estructura[i][j];
        }
    }



}
*/


void limpiarPantalla();


#endif // FUNCIONES_H
