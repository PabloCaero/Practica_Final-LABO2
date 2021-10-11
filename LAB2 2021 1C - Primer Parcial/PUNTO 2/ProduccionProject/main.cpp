#include "Produccion.h"
#include "Defectuosa.h"
#include <iostream>
#include "rlutil.h"
#include "funciones.h"
using namespace std;


int main()
{
    int opcion;
    bool generarDefectuosas = 0;
    do
    {
        cout << "-----PROBLEMA 2-----" << endl;
        cout << "1 - REPORTE PUNTO 1 " << endl;
        cout << "2 - REPORTE PUNTO 2 " << endl;
        cout << "3 - GENERAR DEFECTUOSAS.DAT " << endl;
        cout << "4 - LISTAR DEFECTUOSAS.DAT " << endl;
        cout << "--------------------" << endl;
        cout << "0 - SALIR           " << endl;
        cout << "--------------------" << endl;
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
            if(generarDefectuosas == 0)
            {
                generarDefectuosas = punto3();
                cout << "DEFECTUOSAS.DAT GENERADO" << endl;
            }
            else
            {
                cout << "DEFECTUOSAS.DAT YA GENERADO" << endl;
            }
            break;
        case 4:
            listarDefectuosas();
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
