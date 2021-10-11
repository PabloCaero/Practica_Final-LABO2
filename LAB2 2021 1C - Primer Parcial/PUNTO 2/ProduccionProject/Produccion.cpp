#include <iostream>
using namespace std;
#include "Produccion.h"

Produccion::Produccion()
{
    //ctor
}

int Produccion::getNumeroMaquina()
{
    return _numeroMaquina;
}

void Produccion::setNumeroMaquina(int numeroMaquina)
{
    _numeroMaquina = numeroMaquina;
}

int Produccion::getTipo()
{
    return _tipo;
}

void Produccion::setTipo(int tipo)
{
    _tipo = tipo;
}

Fecha Produccion::getFecha()
{
    return _fecha;
}

void Produccion::setFecha(Fecha fecha)
{
    _fecha = fecha;
}

int Produccion::getPiezasTotales()
{
    return _piezasTotales;
}

void Produccion::setPiezasTotales(int piezasTotales)
{
    _piezasTotales = piezasTotales;
}

int Produccion::getPiezasDefectuosas()
{
    return _piezasDefectuosas;
}

void Produccion::setPiezasDefectuosas(int piezasDefectuosas)
{
    _piezasDefectuosas = piezasDefectuosas;
}

float Produccion::getTemperatura()
{
    return _temperatura;
}

void Produccion::setTemperatura(float temperatura)
{
    _temperatura = temperatura;
}

void Produccion::mostrar()
{
    cout << _numeroMaquina << ",";
    cout << _tipo << ",";
    cout << _fecha.getDia() << ",";
    cout << _fecha.getMes() << ",";
    cout << _fecha.getAnio() << ",";
    cout << _piezasTotales << ",";
    cout << _piezasDefectuosas << ",";
    cout << _temperatura << endl;
}
bool Produccion::leerDeDisco(int pos)
{
    bool lectura;
    FILE *p;
    p = fopen("produccion.dat", "rb");
    if (p == NULL)
    {
        return false;
    }
    fseek(p, sizeof(Produccion)*pos, SEEK_SET) ;
    lectura = fread(this, sizeof(Produccion), 1, p);
    fclose(p);
    return lectura;

}

bool Produccion::grabarEnDisco()
{
    bool guardo;
    FILE *p; //PUNTERO FILE
    p = fopen("produccion.dat", "ab"); //ab: para grabar mas de un registro
    if(p==NULL)
    {
        return false;
    }
    guardo = fwrite(this, sizeof(Produccion), 1, p) ; //THIS ES LA DIRECCION DE MEMORIA QUE LLAMA A ESTE METODO
    fclose(p);
    return guardo;
}

void listarDisco()
{
    Produccion obj;
    FILE *p;
    p = fopen("produccion.dat", "rb"); //IMPORTANTISIMO CAMBIAR A "RB" SOLO LECTURA
    if(p==NULL)
    {
        cout << "NO PUEDE ABRIR EL ARCHIVO";
        return;
    }
    cout << endl;
    while(fread(&obj, sizeof(Produccion), 1, p) ==1)
    {
        obj.mostrar();
        cout << endl;
    }
    fclose(p);
}



int contarProducciones()
{
    int bytes, cr;
    FILE *p;
    p=fopen("produccion.dat", "rb");
    if(p==NULL)
    {
        return 0; //EL ARCHIVO EXISTE PERO NO TIENE REGISTROS
    }
    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    cr = bytes / sizeof(Produccion);
    fclose(p);
    return cr;
}

void leerProducciones(Produccion *vec, int tam)
{
    for(int i=0; i<tam; i++)
    {
        vec[i].leerDeDisco(i);
    }
}




