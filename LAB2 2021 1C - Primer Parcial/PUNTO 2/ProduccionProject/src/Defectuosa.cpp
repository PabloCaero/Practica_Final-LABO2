#include <iostream>
#include <cstring>

using namespace std;

#include "Defectuosa.h"

void Defectuosa::setNumeroMaquina(int numeroMaquina)
{
    _numeroMaquina = numeroMaquina;
}

void Defectuosa::setPiezasDefectuosas(int piezasDefectuosas)
{
    _piezasDefectuosas = piezasDefectuosas;
}

void Defectuosa::mostrar()
{
    cout << "MAQUINA           : #" << _numeroMaquina << endl;
    cout << "PIEZAS DEFECTUOSAS: " << _piezasDefectuosas << endl;
}

bool Defectuosa::escribirEnDisco()
{
    bool guardo;
    FILE *p; //PUNTERO FILE
    p = fopen("defectuosas.dat", "ab"); //ab: para grabar mas de un registro
    if(p==NULL)
    {
        return false;
    }
    guardo = fwrite(this, sizeof(Defectuosa), 1, p) ; //THIS ES LA DIRECCION DE MEMORIA QUE LLAMA A ESTE METODO
    fclose(p);
    return guardo;
}

void listarDefectuosas()
{
    Defectuosa obj;
    FILE *p;
    p = fopen("defectuosas.dat", "rb"); //IMPORTANTISIMO CAMBIAR A "RB" SOLO LECTURA
    if(p==NULL)
    {
        cout << "NO PUEDE ABRIR EL ARCHIVO";
        return;
    }
    cout << endl;
    while(fread(&obj, sizeof(Defectuosa), 1, p) ==1)
    {
        obj.mostrar();
        cout << endl;
    }
    fclose(p);
}
