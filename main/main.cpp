#include "estacion.h"
#include "funciones.h"

int main()
{
    //Espacio inicial del programa
    int lineasMax, estacionesMax;
    lineasMax = 2;
    estacionesMax = 5;

    //Creamos la red
    Estacion **red = new Estacion *[lineasMax];
    for(int i = 0 ; i < lineasMax ; i++){
        red[i] = new Estacion [estacionesMax];
    }

    //Creamos el nombre de las lineas
    string *nomLineas = new string [lineasMax];
/*
    //El nombre de las lineas no se puede modificar
    nomLineas[0] = "lineaA";
    nomLineas[1] = "lineaB";

    //Si una estacion está en un extremo porfavor poner -1, y si es de transferencia poner el caracter de la linea a la cual corresponde

    red[0][0] = Estacion (-1,600,"El Carmen");
    red[0][1] = Estacion (700,3000,"Rio Negro");
    red[0][2] = Estacion (2800,-1,"Medellin", "A");
    red[1][0] = Estacion (-1,2800,"Medellin", "B");
    red[1][1] = Estacion (2800,-1,"Barbosa");
*/
    string linea;
    string ingreso;
    string nombre;

    bool X = false;

    int ingresoInt;
    int ingresoInt2;
    int tiempoA, tiempoD;

    unsigned short int contador;
    unsigned short int contadorLinea;

    int lleno = 0;



    //Simulacion red metro
    while(true)
    {
        //Opciones del programa
        while(true)
        {
            limpiarPantalla();

            cout << "BIENVENIDO A LA RED METRO" << endl;
            cout << "1. Agregar estacion a una linea."<< endl << "2. Eliminar una estacion en una linea." << endl << "3. Numero de lineas en la red."<< endl << "4. Numero de estaciones en una linea."<< endl << "5. Saber si una estacion dada pertenecea una linea especifica."<< endl << "6. Agregar una linea a la red."<< endl << "7. Eliminar una linea de la red."<< endl << "8. Numero de estaciones en la red."<< endl << "9. Salir."<< endl;
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
            //Verificar que si exista una linea en que agregar
            if(nomLineas[0] == "")
            {
                limpiarPantalla();
                cout << "No existe una linea. Ingrese cualquier caracter para continuar " << endl;
                cin >> ingreso;
            }
            else
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


                    for(int j = 0 ; j < estacionesMax ; j++)
                    {
                        if(red[contadorLinea][j].getNombre() != "")
                        {
                            cout << red[contadorLinea][j].getNombre() << red[contadorLinea][j].getLineaA() <<  " [" << contador << "] ";
                            contador++;
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
                        //Si estamos creando la primera estacion
                        if(red[contadorLinea][ingresoInt].getNombre() != "")
                        {
                            cout << "Ingrese el tiempo de la estacion " << red[contadorLinea][ingresoInt].getNombre() << " a la estacion " << nombre <<endl;
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

                            //Cambiamos tiempoA de la estacion siguiente a tiempoD de la estacion actual
                            red[contadorLinea][ingresoInt].setTiempoAntes(tiempoD);

                            cout << "Ingrese el tiempo de la estacion " << nombre << " a la estacion "<< red[contadorLinea][ingresoInt].getNombre()<< endl;
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


                            //cout << red[contadorLinea][ingresoInt].getTiempoAntes()<< endl;
                        }
                        else
                        {
                            tiempoD = -1;
                            tiempoA = -1;
                        }
                    }
                    else if(ingresoInt == contador-1)
                    {
                        cout << "Ingrese el tiempo de la estacion " << red[contadorLinea][ingresoInt-1].getNombre() << " a la estacion " << nombre <<endl;
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

                        //Cambiamos tiempoA de la estacion siguiente a tiempoD de la estacion actual
                        red[contadorLinea][ingresoInt-1].setTiempoDespues(tiempoA);

                        cout << "Ingrese el tiempo de la estacion " << nombre << " a la estacion "<< red[contadorLinea][ingresoInt-1].getNombre()<< endl;
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



                        //cout << red[contadorLinea][ingresoInt-1].getTiempoDespues()<< endl;

                        tiempoD=-1;

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


        }

        //Opcion 2
        else if(ingreso == "2")
        {
            //Verificar que si exista algo que eliminar
            if(nomLineas[0] == "")
            {
                limpiarPantalla();
                cout << "No existe una linea. Ingrese cualquier caracter para continuar " << endl;
                cin >> ingreso;
            }
            else
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


                    for(int j = 0 ; j < estacionesMax ; j++)
                    {
                        if(red[contadorLinea][j].getNombre() != "")
                        {
                            cout << " [" << contador << "]" << red[contadorLinea][j].getNombre() << red[contadorLinea][j].getLineaA();
                            contador++;
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
                    }
                    catch (const std::invalid_argument& e) {
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
            bool salir=false;
            int i,j;

            while(true){
                limpiarPantalla();

                cout << "Ingresa el nombre una la estacion" << endl;
                cin >> nombre;

                for(i = 0 ; i < lineasMax ; i++)
                {
                    for(j = 0 ; j < estacionesMax ; j++)
                    {
                        if(red[i][j].getNombre()== nombre){
                            //verificar si nombre esta en alguna linea

                            if(red[i][j].getLineaA() != " ")
                            {
                                for(int x = 0 ; x < lineasMax ; x++)
                                {
                                    for(int y = 0 ; y < estacionesMax ; y++)
                                    {
                                        if(red[x][y].getNombre() == nombre)
                                        {
                                            cout << "La estacion: "<< nombre << " pertenece a: " << nomLineas[x] << endl;
                                        }
                                    }
                                }
                                cout << "Ingresa cualquier caracter para continuar." << endl;
                                cin >> linea;
                                salir = true;
                            }
                            else
                            {
                                cout << "La estacion: "<< nombre << " pertenece a: " << nomLineas[i] << endl;
                                cout << "Ingresa cualquier caracter para continuar." << endl;
                                cin >> linea;
                                salir = true;
                            }
                            break;
                        }
                    }
                    if (salir){
                        break;
                    }
                }
                if (salir){
                    break;
                }
                cout << "La estacion ingresada no pertenece a ninguna linea. Ingresa cualquier caracter para continuar" << endl;
                cin >> linea;
                break;
            }
        }

        //Opcion 6
        else if(ingreso == "6")
        {
            if(nomLineas[0] == "")
            {
                nomLineas[0] = "lineaA";

                cout << "Cual es el nombre de la estacion de transferencia?" << endl;
                cin >> ingreso;

                red[0][0] = Estacion (-1,-1,ingreso,"A");
            }
            else
            {
                string nombreLinea = "linea";
                int ubicacionLinea;
                char letra;
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

                    cout << "En cual linea desea agregar la estacion de transferencia?" << endl;
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
                    cout << "[#]Estacion de la linea: " << linea << " : " << endl;


                    for(int j = 0 ; j < estacionesMax ; j++)
                    {
                        if(red[contadorLinea][j].getNombre() != "")
                        {
                            cout << " [" << contador << "]" << red[contadorLinea][j].getNombre() << red[contadorLinea][j].getLineaA();
                            contador++;
                        }
                    }

                    cout << endl;

                    cout << "Cual es el numero de la estacion de transferencia?" << endl;
                    cin >> ingreso;

                    try {
                        ingresoInt = stoi(ingreso);

                        if((ingresoInt < 0) || (ingresoInt > (contador-1)))
                        {
                            cout << "El numero ingresado debe de estar entre 0 y " << contador-1 << ". Ingrese cualquier caracter para continuar " << endl;
                            cin >> ingreso;
                            break;
                        }
                    }
                    catch (const std::invalid_argument& e) {
                        cout << "EL numero ingresado no es valido. Ingrese cualquier caracter para continuar " << endl;
                        cin >> ingreso;
                        break;
                    }
                    int linea1;
                    for (int i=0; i< lineasMax ;i++){
                        if(nomLineas[i]==linea){
                            linea1 = i;
                        }
                    }
                    int estacion = std::stoi(ingreso);
                    int mayor = 0;
                    string k = "";

                    //buscar el valor de get.lineaA

                    if(red[linea1][estacion].getLineaA() == " ")
                    {
                        red[linea1][estacion].getLineaA()="A";
                        X=true;
                    }
                    else{
                        for(int i = 0;i < lineasMax; i++)
                        {
                            for (int j = 0; j < estacionesMax; j++)
                            {

                                if(red[i][j].getNombre() == red[linea1][estacion].getNombre())
                                {
                                    char letra = red[i][j].getLineaA()[0];

                                    int codigo_ascii = static_cast<int>(letra);
                                    if(codigo_ascii > mayor)
                                    {
                                        mayor = codigo_ascii;
                                    }
                                }
                            }
                        }
                        mayor += 1;
                        char codigo_ascii = static_cast<char>(mayor);
                        k += codigo_ascii;
                    }

                    //aumentar tamaño de lineas
                    if(!(nomLineas[(lineasMax-1)]== "")){
                        red=aumentarLineasED(red,lineasMax,estacionesMax);
                        nomLineas=aumentarNomLineaED(nomLineas,lineasMax);
                        lineasMax = lineasMax*2;
                    }
                    //nombre de la linea

                    int numAscii = 65;
                    ubicacionLinea = 0;
                    for (int i = 0; i < lineasMax; i++)
                    {
                        if(nomLineas[i]== ""){
                            char codigo_ascii1 = static_cast<char>(numAscii);
                            nombreLinea += codigo_ascii1;
                            nomLineas[i]= nombreLinea;
                            ubicacionLinea = i;

                            break;
                        }
                        numAscii++;
                    }

                    string nombre1 =red[linea1][estacion].getNombre();

                    if(X){
                        red[ubicacionLinea][0]= Estacion (-1,-1,nombre1,"B");
                    }
                    else{
                        red[ubicacionLinea][0]= Estacion (-1,-1,nombre1,k);
                    }

                    break;
                }
            }

        }

        //Opcion 7
        else if(ingreso == "7")
        {
            int cantidadLinea = 0;
            int cantidadEst=0;
            for(int i=0; i<lineasMax;i++){
                if(!(nomLineas[i]== "")){
                    cantidadLinea++;
                }
            }
            if(cantidadLinea == 1){
                while(true){
                    limpiarPantalla();

                    cout << "Hay una linea, desea eliminarla?" << endl;
                    cout << "1. Si. " << endl << "2. No." << endl;
                    cin >> linea;

                    if(linea == "1" || linea == "2"){
                        break;
                    }
                }


                if(linea == "1"){
                    red = eliminarlinea(red,lineasMax,estacionesMax,nomLineas);
                    for (int i = 0; i < estacionesMax; ++i) {
                        if(!(red[0][i].getNombre()== "")){
                            cantidadEst++;
                        }
                    }
                    if (cantidadEst == 0){
                        limpiarPantalla();
                        cout << "La linea  se ha eliminado correctamente. Ingresa cualquier caracter para continuar" << endl;
                        cin >> linea;
                    }
                    else{
                        limpiarPantalla();
                        cout << "La linea  no se ha eliminado correctamente. Ingresa cualquier caracter para continuar" << endl;
                        cin >> linea;
                    }
                }
            }
            else{
                limpiarPantalla();
                cout << "La red metro tiene: " << cantidadLinea <<" linea, por lo cual no se pueden eliminar lineas. Ingresa cualquier caracter para continuar" << endl;
                cin >> linea;
            }
        }

        //Opcion 8
        else if(ingreso == "8")
        {
            bool salir=false;
            int numero_estaciones = 0;

            limpiarPantalla();
            for(int i = 0 ; i < lineasMax ; i++)
            {
                for(int j = 0 ; j < estacionesMax ; j++)
                {
                    if(!(red[i][j].getNombre()== "")){
                        numero_estaciones++;
                    }
                }
            }
            for(int i=1; i<lineasMax;i++){
                if(!(nomLineas[i]== "")){
                    numero_estaciones--;
                }
            }
            cout << "La cantidad de estaciones en la red metro es: " << numero_estaciones << " ." << "Ingresa cualquier caracter para continuar" << endl;
            cin >> linea;
        }

        //Opcion 9
        else if(ingreso == "9")
        {
            break;
        }
    }

    //Opciones del programa
    while(true)
    {
        limpiarPantalla();

        cout << "Antes de salir, desea calcular el tiempo que toma ir de una estacion a otra?" << endl;
        cout << "1. Si."<< endl << "2. No." << endl;
        cout << "Que desea hacer?" << endl;
        cin >> ingreso;

        if((ingreso == "1") || (ingreso == "2"))
        {
            break;
        }
    }

    if(ingreso == "1")
    {
        //Calculo tiempo de llegada
        while(true)
        {
            //Opciones del programa
            while(true)
            {
                limpiarPantalla();

                cout << "BIENVENIDO" << endl;
                cout << "1. Calcular tiempo de llegada."<< endl << "2. Salir." << endl;
                cout << "Que desea hacer?" << endl;
                cin >> ingreso;

                if((ingreso == "1") || (ingreso == "2"))
                {
                    break;
                }
            }

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

                    cout << "En cual linea se encuentra la estacion?" << endl;
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
                    //Estacion de partida
                    contador = 0;
                    cout << "[#]Estacion de " << linea << " son: " << endl;


                    for(int j = 0 ; j < estacionesMax ; j++)
                    {
                        if(red[contadorLinea][j].getNombre() != "")
                        {
                            cout << " [" << contador << "]" << red[contadorLinea][j].getNombre() << red[contadorLinea][j].getLineaA();
                            contador++;
                        }
                    }

                    cout << endl;

                    cout << "Cual es el numero de la estacion de partida?" << endl;
                    cin >> ingreso;

                    try {
                        ingresoInt = stoi(ingreso);

                        if((ingresoInt < 0) || (ingresoInt > (contador-1)))
                        {
                            cout << "El numero ingresado debe de estar entre 0 y " << contador-1 << ". Ingrese cualquier caracter para continuar " << endl;
                            cin >> ingreso;
                            break;
                        }
                    }
                    catch (const std::invalid_argument& e) {
                        cout << "EL numero ingresado no es valido. Ingrese cualquier caracter para continuar " << endl;
                        cin >> ingreso;
                        break;
                    }

                    //Estacion destino

                    limpiarPantalla();
                    //Estacion a eliminar
                    contador = 0;
                    cout << "[#]Estacion de " << linea << " son: " << endl;


                    for(int j = 0 ; j < estacionesMax ; j++)
                    {
                        if(red[contadorLinea][j].getNombre() != "")
                        {
                            if(j == ingresoInt)
                            {
                                cout << " [USTED ESTA ACA] ";
                                contador++;
                            }
                            else{
                                cout << " [" << contador << "]" << red[contadorLinea][j].getNombre() << red[contadorLinea][j].getLineaA();
                                contador++;
                            }
                        }
                    }

                    cout << endl;

                    cout << "Cual es el numero de la estacion destino?" << endl;
                    cin >> ingreso;

                    try {
                        ingresoInt2 = stoi(ingreso);

                        if((ingresoInt2 < 0) || (ingresoInt2 > (contador-1)))
                        {
                            cout << "El numero ingresado debe de estar entre 0 y " << contador-1 << ". Ingrese cualquier caracter para continuar " << endl;
                            cin >> ingreso;
                            break;
                        }
                        else if(ingresoInt == ingresoInt2)
                        {
                            cout << "La estacion de partida no puede ser la estacion destino. Ingrese cualquier caracter para continuar " << endl;
                            cin >> ingreso;
                            break;
                        }
                    }
                    catch (const std::invalid_argument& e) {
                        cout << "EL numero ingresado no es valido. Ingrese cualquier caracter para continuar " << endl;
                        cin >> ingreso;
                        break;
                    }
                    calculoTiempoLLegada(red, contadorLinea, ingresoInt, ingresoInt2);

                    cin >> ingreso;
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }

    for(int i=0;i<lineasMax;i++)
    {
        delete[] red[i];
    }
    delete[] red;

    return 0;
}
