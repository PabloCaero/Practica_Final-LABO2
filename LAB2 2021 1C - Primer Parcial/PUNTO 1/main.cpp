#include <iostream>
#include <Temporizador.h>
#include "rlutil.h"

using namespace std;

int main()
{
    int opcion;
    cout << "TEMPORIZADOR 1" << endl;
    Temporizador a;
    cout << "------------------------" << endl;
    cout << "TEMPORIZADOR 2" << endl;
    Temporizador b;
    rlutil::cls();
    do
    {
        cout << "TEMPORIZADOR 1: ";
        a.mostrar();
        cout << "1 - TIC " << endl;
        cout << "2 - TOC " << endl;
        cout << "------------------------" << endl;
        cout << "TEMPORIZADOR 2: ";
        b.mostrar();
        cout << endl;
        cout << "3 - TIC " << endl;
        cout << "4 - TOC " << endl;
        cout << "------------------------" << endl;
        if(a.comparar(b)==0)
        {
            cout << "TEMPORIZADOR 1 = TEMPORIZADOR 2" << endl;
        }
        if(a.comparar(b)==1)
        {
            cout << "TEMPORIZADOR 1 > TEMPORIZADOR 2" << endl;
        }
        if(a.comparar(b)==-1)
        {
            cout << "TEMPORIZADOR 1 < TEMPORIZADOR 2" << endl;
        }
        cout << "------------------------" << endl;
        cout << "0 - SALIR           " << endl;
        cout << "------------------------" << endl;
        cout << "OPCION: ";
        cin >> opcion;

        rlutil::cls();

        switch(opcion)
        {
        case 1:
            a.tic();
            break;
        case 2:
            a.tac();
            break;
        case 3:
            b.tic();
            break;
        case 4:
            b.tac();
            break;
        default:
            cout << ">OPCION INCORRECTA<" << endl;
            break;
        }



        rlutil::cls();

    }
    while(opcion != 0);


    return 0;
}
