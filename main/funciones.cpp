#include "funciones.h"
#include <chrono>
#include <ctime>

using namespace std;

void limpiarPantalla(){
    //"Limpiamos pantalla"
    for(int i = 0 ; i < 50 ; i++)
    {
        cout << endl;
    }
}

Estacion** aumentarLineasED(Estacion **estructura, int primero, int segundo){
    //Creamos la copia
    Estacion **copiaEstructura = new Estacion *[primero];
    for(int i = 0 ; i < primero ; i++){
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


    for(int i=0;i<primero;i++)
    {
        delete[] estructura[i];
    }
    delete[] estructura;

    Estacion **estructura1 = new Estacion *[primero*2];
    for(int i = 0 ; i < (primero*2); i++){
        estructura1[i] = new Estacion [segundo];
    }
    //copiemos lo que hay en la estructura
    for(int i = 0 ; i < primero; i++)
    {
        for(int j = 0 ; j < segundo ; j++)
        {
            estructura1[i][j] = copiaEstructura[i][j];
        }
    }

    for(int i=0;i<primero;i++)
    {
        delete[] copiaEstructura[i];
    }
    delete[] copiaEstructura;

    return estructura1;

}
Estacion** aumentarEstacionED(Estacion **estructura, int primero, int segundo){
    //Creamos la copia
    Estacion **copiaEstructura = new Estacion *[primero];
    for(int i = 0 ; i < primero ; i++){
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


    for(int i=0;i<primero;i++)
    {
        delete[] estructura[i];
    }
    delete[] estructura;

    Estacion **estructura1 = new Estacion *[primero];
    for(int i = 0 ; i < (primero); i++){
        estructura1[i] = new Estacion [segundo*2];
    }
    //copiemos lo que hay en la estructura
    for(int i = 0 ; i < primero; i++)
    {
        for(int j = 0 ; j < segundo ; j++)
        {
            estructura1[i][j] = copiaEstructura[i][j];
        }
    }

    for(int i=0;i<primero;i++)
    {
        delete[] copiaEstructura[i];
    }
    delete[] copiaEstructura;

    return estructura1;

}
string* aumentarNomLineaED(string *estructura,int primero){
    string *copiaEstructura = new string [primero];

    for(int i = 0 ; i < primero ; i++)
    {
        copiaEstructura[i] = estructura[i];
    }
    //liberar el espacio de memoria
    delete[] estructura;

    //asignar el espacio de memoria
    string *estructura1 = new string [primero*2];

    //copiemos estrunctura
    for(int i = 0 ; i < primero ; i++)
    {
        estructura1[i] = copiaEstructura[i];
    }
    //liberar el espacio de memoria

    delete[] copiaEstructura;
    return estructura1;
}

Estacion** agregarEstacion(Estacion **estructura, int primero, int segundo,int lineaPosicion,int posicionAgregar,Estacion estacionAgregar,int *k){
    bool lleno=true;
    for(int i = 0 ; i < segundo; i++){
        if (estructura[lineaPosicion][i].getNombre() == ""){
            lleno=false;
            break;
        }
    }
    if (lleno){
        estructura= aumentarEstacionED(estructura,primero,segundo);
        segundo = segundo*2;
        *k = 1;
    }

    Estacion **copiaEstructura = new Estacion *[primero];
    for(int i = 0 ; i < primero ; i++){
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


    for(int i = posicionAgregar ; i < (segundo-1) ; i++)
    {
        estructura[lineaPosicion][i+1] = copiaEstructura[lineaPosicion][i];
    }

    estructura[lineaPosicion][posicionAgregar]= estacionAgregar;
    for(int i=0;i<primero;i++)
    {
        delete[] copiaEstructura[i];
    }
    delete[] copiaEstructura;

    return estructura;
}

Estacion** eliminarEstacion(Estacion **estructura, int primero, int segundo,int lineaPosicion,int posicionEliminar){

    Estacion **copiaEstructura = new Estacion *[primero];
    for(int i = 0 ; i < primero ; i++){
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


    for(int i = posicionEliminar ; i < (segundo-1) ; i++)
    {
        estructura[lineaPosicion][i] = copiaEstructura[lineaPosicion][i+1];
    }

    for(int i=0;i<primero;i++)
    {
        delete[] copiaEstructura[i];
    }
    delete[] copiaEstructura;

    return estructura;
}
Estacion** eliminarlinea(Estacion **estructura, int primero, int segundo,string *nomLineas){
    Estacion **copiaEstructura = new Estacion *[primero];
    for(int i = 0 ; i < primero ; i++){
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

    for(int i = 0 ; i < segundo ; i++){
        estructura[0][i] = copiaEstructura[1][i];
    }

    //liberar espacio de memoria

    for(int i=0;i<primero;i++)
    {
        delete[] copiaEstructura[i];
    }
    delete[] copiaEstructura;

    nomLineas[0]= "";

    return estructura;
}


tm agregarSegundos(int segundoAAgregar)
{
    // Obtener el tiempo actual en el reloj del sistema
    auto currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    // Sumar los segundos especificados a la hora actual
    currentTime += segundoAAgregar;

    // Convertir el tiempo a una estructura de tiempo local
    return *std::localtime(&currentTime);
}

void calculoTiempoLLegada(Estacion **estructura, int linea, int estacionInicio, int estacionFinal){

    int tiempoSuma = 0;

    if(estacionInicio > estacionFinal)
    {
        for(int i = estacionFinal ; i <= estacionInicio ; i++)
        {
            if(estructura[linea][i].getTiempoAntes() != -1)
            {
                tiempoSuma+= estructura[linea][i].getTiempoAntes();
            }
        }
    }
    else
    {
        for(int i = estacionInicio ; i <= estacionFinal ; i++)
        {
            if(estructura[linea][i].getTiempoDespues() != -1)
            {
                tiempoSuma+= estructura[linea][i].getTiempoDespues();
            }
        }
    }

    tm tiempoLlegada =agregarSegundos(tiempoSuma);
    //cout << "Hora actual + " << tiempoSuma << " segundos: " << endl;

    cout << "El tiempo de llegada estimado es: "<<tiempoLlegada.tm_hour << ":" << tiempoLlegada.tm_min << ":" << tiempoLlegada.tm_sec << endl;
}
