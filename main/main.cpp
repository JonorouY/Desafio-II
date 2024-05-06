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
    Estacion numero1(5,3,"Juan");
    Estacion numero2(5,3,"Juan");
    if (numero1==numero2){
        cout <<"efectivamente"<< endl;
    }

    return 0;
}
