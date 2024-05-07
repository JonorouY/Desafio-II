#include "estacion.h"
#include "funciones.h"

int main()
{
    int lineasMax, estacionesMax;
    lineasMax = 2;
    estacionesMax = 5;

    string linea;
    string ingreso;
    string nombre;

    bool X = false;

    int ingresoInt;
    int tiempoA, tiempoD;

    unsigned short int contador;
    unsigned short int contadorLinea;

    int lleno = 0;

    //Creamos la red
    Estacion **red = new Estacion *[lineasMax];
    for(int i = 0 ; i < lineasMax ; i++){
        red[i] = new Estacion [estacionesMax];
    }

    //Creamos el nombre de las lineas
    string *nomLineas = new string [lineasMax];

    nomLineas[0] = "metro";

    red[0][0] = Estacion (-1,3,"jajaja");
    red[0][1] = Estacion (2,3,"ahsdhas");
    red[0][2] = Estacion (3,-1,"hola", "A");


    while(true)
    {
        //Opciones del programa
        while(true)
        {
            limpiarPantalla();

            cout << red[0][2].getLineaA()<< "9"<<endl;

            cout << "BIENVENIDO A LA RED METRO" << endl;
            cout << "1. Agregar estacion a una linea."<< endl << "2. Eliminar una estacion en una linea." << endl << "3. Numero de lineas en la red."<< endl << "4. Numero de estaciones en una linea."<< endl << "5. Saber si una estacion dada pertenecea una linea específica."<< endl << "6. Agregar una linea a la red."<< endl << "7. Eliminar una linea de la red."<< endl << "8. Numero de estaciones en la red."<< endl << "9. Salir."<< endl;
            cout << "Que desea hacer?" << endl;
            cin >> ingreso;

            if((ingreso == "1") || (ingreso == "2") || (ingreso == "3") || (ingreso == "4") || (ingreso == "5") || (ingreso == "6") || (ingreso == "7") || (ingreso == "8") || (ingreso == "9"))
            {
                break;
            }
        }

        //Opcion 1
        if(ingreso == "1")
        {
            //Opciones de linea
            while(true)
            {
                limpiarPantalla();

                cout << "Las lineas actuales son:" << endl;

                for(int i = 0 ; i < lineasMax ; i++)
                {
                    if(nomLineas[i] != "")
                    {
                        cout << nomLineas[i] << " | ";
                    }
                }
                cout << endl;

                cout << "En cual linea desea agregar la estacion?" << endl;
                cin >> linea;

                for(int i = 0 ; i < lineasMax ; i++)
                {
                    if(linea == nomLineas[i])
                    {
                        contadorLinea =i;
                        break;
                    }
                }

                if(linea == nomLineas[contadorLinea])
                {
                    break;
                }

                cout << "La linea ingresada no existe. Ingrese cualquier caracter para continuar" << endl;
                cin >> linea;
            }

            //Ingreso de estacion
            while(true)
            {
                limpiarPantalla();
                //Lugar donde desea agregar
                contador = 0;
                cout << "Los lugares donde puede agregar la estacion se marcaran con [#] " << linea << " son: " << endl;

                cout << "[" << contador << "] ";
                contador++;

                for(int i = 0 ; i < lineasMax ; i++)
                {
                    for(int j = 0 ; j < estacionesMax ; j++)
                    {
                        if(red[i][j].getNombre() != "")
                        {
                            cout << red[i][j].getNombre() << red[i][j].getLineaA() <<  " [" << contador << "] ";
                            contador++;
                        }
                    }
                }
                cout << endl;

                cout << "En que numero desea agregar la estacion?" << endl;
                cin >> ingreso;

                try {
                    ingresoInt = stoi(ingreso);

                    if((ingresoInt < 0) || (ingresoInt > (contador-1)))
                    {
                        cout << "El numero ingresado debe de estar entre 0 y " << contador-1 << ". Ingrese cualquier caracter para continuar " << endl;
                        cin >> ingreso;
                        break;
                    }
                } catch (const std::invalid_argument& e) {
                    cout << "EL numero ingresado no es valido. Ingrese cualquier caracter para continuar " << endl;
                    cin >> ingreso;
                    break;
                }

                //Nombre de la estacion
                cout << "Ingrese el nombre de la estacion que desea agregar(No puede ser un nombre de una estacion que ya exista) " << endl;
                cin >> nombre;

                for(int i = 0 ; i < lineasMax ; i++)
                {
                    for(int j = 0 ; j < estacionesMax; j++)
                    {
                        if(nombre == red[i][j].getNombre())
                        {
                            X = true;
                        }
                    }
                }

                if(X)
                {
                    cout << "El nombre ingresado ya existe. Ingrese cualquier caracter para continuar" << endl;
                    cin >> nombre;
                    break;
                }

                //Tiempo
                if(ingresoInt == 0)
                {
                    cout << "Ingrese el tiempo a la estacion " << red[contadorLinea][ingresoInt].getNombre() << endl;
                    cin >> ingreso;
                    try {
                        tiempoD = stoi(ingreso);
                        if((tiempoD <= 0))
                        {
                            cout << "El tiempo no puede ser negativo ni 0. Ingrese cualquier caracter para continuar " << endl;
                            cin >> ingreso;
                            break;
                        }
                    } catch (const std::invalid_argument& e) {
                        cout << "El tiempo debe ser un numero natural. Ingrese cualquier caracter para continuar " << endl;
                        cin >> ingreso;
                        break;
                    }
                    tiempoA = -1;

                    //Cambiamos tiempoA de la estacion siguiente a tiempoD de la estacion actual
                    red[contadorLinea][ingresoInt].setTiempoAntes(tiempoD);

                    //cout << red[contadorLinea][ingresoInt].getTiempoAntes()<< endl;
                }
                else if(ingresoInt == contador-1)
                {
                    cout << "Ingrese el tiempo a la estacion " << red[contadorLinea][ingresoInt-1].getNombre()<< endl;
                    cin >> ingreso;
                    try {
                        tiempoA = stoi(ingreso);

                        if((tiempoA <= 0))
                        {
                            cout << "El tiempo no puede ser negativo ni 0. Ingrese cualquier caracter para continuar " << endl;
                            cin >> ingreso;
                            break;
                        }
                    } catch (const std::invalid_argument& e) {
                        cout << "El tiempo debe ser un numero natural. Ingrese cualquier caracter para continuar " << endl;
                        cin >> ingreso;
                        break;
                    }
                    tiempoD = -1;

                    //Cambiamos tiempoA de la estacion siguiente a tiempoD de la estacion actual
                    red[contadorLinea][ingresoInt-1].setTiempoDespues(tiempoA);

                    //cout << red[contadorLinea][ingresoInt-1].getTiempoDespues()<< endl;
                }
                else
                {
                    cout << "Ingrese el tiempo a la estacion " << red[contadorLinea][ingresoInt-1].getNombre()<< endl;
                    cin >> ingreso;
                    try {
                        tiempoA = stoi(ingreso);

                        if((tiempoA <= 0))
                        {
                            cout << "El tiempo no puede ser negativo ni 0. Ingrese cualquier caracter para continuar " << endl;
                            cin >> ingreso;
                            break;
                        }
                    } catch (const std::invalid_argument& e) {
                        cout << "El tiempo debe ser un numero natural. Ingrese cualquier caracter para continuar " << endl;
                        cin >> ingreso;
                        break;
                    }
                    tiempoD = -1;

                    //Cambiamos tiempoA de la estacion siguiente a tiempoD de la estacion actual
                    red[contadorLinea][ingresoInt-1].setTiempoDespues(tiempoA);

                    cout << "Ingrese el tiempo a la estacion " << red[contadorLinea][ingresoInt].getNombre()<< endl;
                    cin >> ingreso;
                    try {
                        tiempoD = stoi(ingreso);

                        if((tiempoD <= 0))
                        {
                            cout << "El tiempo no puede ser negativo ni 0. Ingrese cualquier caracter para continuar " << endl;
                            cin >> ingreso;
                            break;
                        }
                    } catch (const std::invalid_argument& e) {
                        cout << "El tiempo debe ser un numero natural. Ingrese cualquier caracter para continuar " << endl;
                        cin >> ingreso;
                        break;
                    }
                    tiempoA = -1;

                    //Cambiamos tiempoA de la estacion siguiente a tiempoD de la estacion actual
                    red[contadorLinea][ingresoInt].setTiempoAntes(tiempoD);

                    //cout << red[contadorLinea][ingresoInt].getTiempoAntes()<< endl;
                    //cout << red[contadorLinea][ingresoInt-1].getTiempoDespues()<< endl;
                }



                //Guardamos
                agregarEstacion(red, lineasMax, estacionesMax, contadorLinea, ingresoInt, Estacion (tiempoA, tiempoD, nombre), &lleno);

                if(lleno == 1)
                {
                    estacionesMax= estacionesMax*2;
                    lleno=0;
                }

                break;
            }


        }

        //Opcion 2
        else if(ingreso == "2")
        {
            //Opciones de linea
            while(true)
            {
                limpiarPantalla();

                cout << "Las lineas actuales son:" << endl;

                for(int i = 0 ; i < lineasMax ; i++)
                {
                    if(nomLineas[i] != "")
                    {
                        cout << nomLineas[i] << " | ";
                    }
                }
                cout << endl;

                cout << "En cual linea desea eliminar la estacion?" << endl;
                cin >> linea;

                for(int i = 0 ; i < lineasMax ; i++)
                {
                    if(linea == nomLineas[i])
                    {
                        contadorLinea =i;
                        break;
                    }
                }

                if(linea == nomLineas[contadorLinea])
                {
                    break;
                }

                cout << "La linea ingresada no existe. Ingrese cualquier caracter para continuar" << endl;
                cin >> linea;
            }

            //Ingreso de estacion
            while(true)
            {
                limpiarPantalla();
                //Estacion a eliminar
                contador = 0;
                cout << "[#]Estacion de " << linea << " son: " << endl;

                for(int i = 0 ; i < lineasMax ; i++)
                {
                    for(int j = 0 ; j < estacionesMax ; j++)
                    {
                        if(red[i][j].getNombre() != "")
                        {
                            cout << " [" << contador << "]" << red[i][j].getNombre() << red[i][j].getLineaA();
                            contador++;
                        }
                    }
                }
                cout << endl;

                cout << "Cual es el numero de la estacion que desea eliminar?" << endl;
                cin >> ingreso;

                try {
                    ingresoInt = stoi(ingreso);

                    if((ingresoInt < 0) || (ingresoInt > (contador-1)))
                    {
                        cout << "El numero ingresado debe de estar entre 0 y " << contador-1 << ". Ingrese cualquier caracter para continuar " << endl;
                        cin >> ingreso;
                        break;
                    }
                } catch (const std::invalid_argument& e) {
                    cout << "EL numero ingresado no es valido. Ingrese cualquier caracter para continuar " << endl;
                    cin >> ingreso;
                    break;
                }

                if(red[contadorLinea][ingresoInt].getLineaA() != " ")
                {
                    cout << "No se puede eliminar una estacion de transferencia. Ingrese cualquier caracter para continuar" << endl;
                    cin >> ingreso;
                    break;
                }

                //Tiempo
                if(ingresoInt == 0)
                {

                    //Cambiamos el tiempoA de la estacion siguiente a -1
                    red[contadorLinea][ingresoInt+1].setTiempoAntes(-1);

                    //cout << red[contadorLinea][ingresoInt+1].getTiempoAntes()<< endl;
                }
                else if(ingresoInt == contador-1)
                {
                    //Cambiamos el tiempoD de la estacion anterior a -1
                    red[contadorLinea][ingresoInt-1].setTiempoDespues(-1);

                    cout << red[contadorLinea][ingresoInt-1].getTiempoDespues()<< endl;
                }
                else
                {
                    //Calculamos el tiempoA de la estacion siguiente, que es la suma de tiempoD de la estacion anterior y tiempoD de la estacion a eliminar
                    red[contadorLinea][ingresoInt-1].setTiempoDespues(red[contadorLinea][ingresoInt-1].getTiempoDespues() + red[contadorLinea][ingresoInt].getTiempoDespues());
                    red[contadorLinea][ingresoInt+1].setTiempoAntes(red[contadorLinea][ingresoInt+1].getTiempoAntes() + red[contadorLinea][ingresoInt].getTiempoAntes());

                    //cout << red[contadorLinea][ingresoInt+1].getTiempoAntes()<< endl;
                    //cout << red[contadorLinea][ingresoInt-1].getTiempoDespues()<< endl;
                }

                eliminarEstacion(red, lineasMax, estacionesMax, contadorLinea, ingresoInt);

                break;
            }
        }

        //Opcion 3
        else if(ingreso == "3")
        {
            limpiarPantalla();

            contador=0;
            for(int i = 0 ; i < lineasMax ; i++)
            {
                if(nomLineas[i] == "")
                {
                    break;
                }
                contador++;
            }

            cout << "La red tiene " << contador << " lineas. Ingrese cualquier caracter para continuar."<< endl;
            cin >> ingreso;
        }

        //Opcion 4
        else if(ingreso == "4")
        {
            //Opciones de linea
            while(true)
            {
                limpiarPantalla();
                contador = 0;

                cout << "Las lineas actuales son:" << endl;

                for(int i = 0 ; i < lineasMax ; i++)
                {
                    if(nomLineas[i] != "")
                    {
                        cout << nomLineas[i] << " | ";
                    }
                }
                cout << endl;

                cout << "En cual linea desea conocer el numero de estaciones?" << endl;
                cin >> linea;

                for(int i = 0 ; i < lineasMax ; i++)
                {
                    if(linea == nomLineas[i])
                    {
                        contadorLinea =i;
                        break;
                    }
                }

                if(linea == nomLineas[contadorLinea])
                {
                    break;
                }

                cout << "La linea ingresada no existe. Ingrese cualquier caracter para continuar" << endl;
                cin >> linea;
            }

            for(int i = 0; i < estacionesMax ; i++)
            {
                if(red[contadorLinea][i].getNombre() == "")
                {
                    break;
                }
                contador++;
            }
            cout << "Hay " << contador << " estaciones en " << nomLineas[contadorLinea] << " . Ingrese cualquier caracter para continuar. " << endl;
            cin >> ingreso;

        }

        //Opcion 5
        else if(ingreso == "5")
        {

        }

        //Opcion 6
        else if(ingreso == "6")
        {

        }

        //Opcion 7
        else if(ingreso == "7")
        {

        }

        //Opcion 8
        else if(ingreso == "8")
        {

        }

        //Opcion 9
        else if(ingreso == "9")
        {
            break;
        }
    }
    return 0;
}
