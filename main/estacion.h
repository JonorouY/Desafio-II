#ifndef ESTACION_H
#define ESTACION_H
#include <iostream>
#include <string>

using namespace std;

class Estacion
{
private:
    int tiempoAntes, tiempoDespues;
    int cantEstaciones = 0;
    string nombre, linea;


public:

    Estacion(int tiempoA, int tiempoD, string name);
    Estacion(int tiempoA, int tiempoD, string name, string lineaA);

    int getTiempoAntes(void);
    int getTiempoDespues(void);
    int getCantEstaciones(void);
    string getNombre(void);

    setTiempoAntes(int tiempoA);
    setTiempoDespues(int tiempoD);
    setCantEstaciones(int cantidad);

    ~Estacion();
};

#endif // ESTACION_H
