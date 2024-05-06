#include "estacion.h"
#include "funciones.h"

int main()
{
    cout <<"hola mundo"<<endl;
    int primero = 2;
    string *copiaEstructura = new string [primero];
    copiaEstructura[1]= "hola mundo";
    copiaEstructura = aumentarNomLineaED(copiaEstructura, primero);
    cout <<copiaEstructura[1]<< endl <<copiaEstructura[3]<< endl;

    return 0;
}
