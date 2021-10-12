#include "Pais.h"
#include "Ciudad.h"
#include "Mundo.h"
#include <iostream>
#include "rlutil.h"
#include "funciones.h"
using namespace std;


int main()
{
    int opcion;

    do
    {
        cout << "-----ARCHIVOS PARTE 1-----" << endl;
        cout << "--------------------------" << endl;
        cout << "1 - BUSCAR PAIS POR CODIGO " << endl;
        cout << "2 - AGREGAR PAIS " << endl;
        cout << "3 - LISTADO DE PAISES " << endl;
        cout << "4 - LISTADO DE CIUDADES POR BUSQUEDA DE PAIS Y REPORTE DE LA CAPITAL" << endl;
        cout << "5 - LISTADOS DE PAISES CON NOMBRE, SUPERFICIE Y PORCENTAJE SOBRE EL TOTAL MUNDIAL " << endl;
        cout << "-----ARCHIVOS PARTE 2-----" << endl;
        cout << "--------------------------" << endl;
        cout << "6 - LISTADO DE PAISES ORDENADO POR POBLACION DE MANERA DECRECIENTE " << endl;
        cout << "7 - AGREGAR CIUDAD " << endl;
        cout << "8 - INGRESAR CIUDAD PARA INDICAR QUE POSICION UBICARIA EN EL RANKING MUNDIAL DE POBLACION " << endl;
        cout << "9 - MODIFICAR PAIS " << endl;
        cout << "10 - GENERAR ARCHIVO MUNDO.DAT " << endl;
        cout << "11 - LISTAR MUNDO.DAT " << endl;
        cout << "--------------------------" << endl;
        cout << "0 - SALIR           " << endl;
        cout << "--------------------------" << endl;
        cout << "OPCION: ";
        cin >> opcion;

        rlutil::cls();

        switch(opcion)
        {
        case 1:
            punto1();
            break;
        case 2:
            punto2();
            break;
        case 3:
            listarPaises();
            break;
        case 4:
            punto4();
            break;
        case 5:
            punto5();
            break;
        case 6:
            punto6();
            break;
        case 7:
            punto7();
            break;
        case 8:
            punto8();
            break;
        case 9:
            modificarPais();
            break;
        case 10:
            punto10();
            break;
        case 11:
            listarMundo();
            break;
        default:
            cout << ">OPCION INCORRECTA<" << endl;
            break;
        }

        rlutil::anykey();
        rlutil::cls();

    }
    while(opcion != 0);


    return 0;
}
