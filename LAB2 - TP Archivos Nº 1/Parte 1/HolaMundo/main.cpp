#include "Pais.h"
#include "Ciudad.h"
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
        cout << "1 - BUSCAR PAIS POR CODIGO " << endl;
        cout << "2 - AGREGAR PAIS " << endl;
        cout << "3 - LISTADO DE PAISES " << endl;
        cout << "4 - LISTADO DE CIUDADES POR BUSQUEDA DE PAIS " << endl;
        cout << "5 - LISTADOS DE PAISES CON NOMBRE, SUPERFICIE Y PORCENTAJE SOBRE EL TOTAL MUNDIAL " << endl;
        cout << "--------------------------" << endl;
        cout << "0 - SALIR           " << endl;
        cout << "--------------------------" << endl;
        cout << "OPCION: ";
        cin >> opcion;

        rlutil::cls();

        switch(opcion)
        {
        case 1: punto1();
            break;
        case 2: punto2();
            break;
        case 3: listarPaises();
            break;
        case 4: punto4();
            break;
        case 5: punto5();
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
