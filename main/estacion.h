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
    Estacion();
    Estacion(int tiempoA, int tiempoD, string name);
    Estacion(int tiempoA, int tiempoD, string name, string lineaA);

    int getTiempoAntes(void);
    int getTiempoDespues(void);
    int getCantEstaciones(void);
    string getNombre(void);

    void setTiempoAntes(int tiempoA);
    void setTiempoDespues(int tiempoD);
    void setCantEstaciones(int cantidad);

    //sobrecarga de metodos
    int TiempoAntes() const;
    int TiempoDespues() const;
    string Nombre() const;

    void operator=(const Estacion& nuevaEstacion);
    bool operator==(const Estacion& nuevaEstacion);


    ~Estacion();
};

#endif // ESTACION_H
