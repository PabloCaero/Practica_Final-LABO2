#include <iostream>
#include <cstring>
#include "Pais.h"
#include "Ciudad.h"

using namespace std;

#include "Mundo.h"


void Mundo::setCodigo(char *codigo)
{
    strcpy(_codigo, codigo);
}
void Mundo::setNombre(char *nombre)
{
    strcpy(_nombre, nombre);
}
void Mundo::setNombreCiudad(char *nombreCiudad)
{
    strcpy(_nombreCiudad, nombreCiudad);
}
void Mundo::setPoblacion(int poblacionCiudad)
{
    _poblacionCiudad = poblacionCiudad;
}

void Mundo::mostrar()
{
    cout << _codigo << ", " << _nombre << ", " << _nombreCiudad << ", " << _poblacionCiudad << endl;
}

bool Mundo::leerDeDisco(int pos)
{
    bool lectura;
    FILE *p;
    p = fopen("mundo.dat", "rb");
    if (p == NULL)
    {
        return false;
    }
    fseek(p, sizeof(Mundo)*pos, SEEK_SET) ;
    lectura = fread(this, sizeof(Mundo), 1, p);
    fclose(p);
    return lectura;
}

bool Mundo::grabarEnDisco()
{
    bool guardo;
    FILE *p; //PUNTERO FILE
    p = fopen("mundo.dat", "ab"); //ab: para grabar mas de un registro
    if(p==NULL)
    {
        return false;
    }
    guardo = fwrite(this, sizeof(Mundo), 1, p) ; //THIS ES LA DIRECCION DE MEMORIA QUE LLAMA A ESTE METODO
    fclose(p);
    return guardo;
}



void listarMundo()
{
    Mundo obj;
    FILE *p;
    p = fopen("mundo.dat", "rb"); //IMPORTANTISIMO CAMBIAR A "RB" SOLO LECTURA
    if(p==NULL)
    {
        cout << "NO PUEDE ABRIR EL ARCHIVO";
        return;
    }
    cout << endl;
    while(fread(&obj, sizeof(Mundo), 1, p) ==1)
    {
        obj.mostrar();
        cout << endl;
    }
    fclose(p);
}

bool generarMundo()
{

    Pais *vecPais;
    Ciudad *vecCiudad;
    int tamPaises, tamCiudades;

    tamPaises = contarPaises();
    tamCiudades = contarCiudades();

    vecPais = new Pais[tamPaises];
    vecCiudad = new Ciudad[tamCiudades];

    leerCiudades(vecCiudad, tamCiudades);
    leerPaises(vecPais, tamPaises);

    bool banderaMayor;
    char ciudadMayor[25];
    int poblacionMayor;

    for(int i=0; i<tamPaises; i++)
    {
        banderaMayor = 0;
        Mundo obj;

        for(int j=0; j<tamCiudades; j++)
        {
            if(strcmp(vecPais[i].getCodigo(), vecCiudad[j].getIDPais())==0)
            {
                if(banderaMayor == 0)
                {
                    poblacionMayor = vecCiudad[j].getPoblacion();
                    strcpy(ciudadMayor, vecCiudad[j].getNombre());
                    banderaMayor = 1;
                }
                else
                {
                    if(poblacionMayor < vecCiudad[j].getPoblacion())
                    {
                        poblacionMayor = vecCiudad[j].getPoblacion();
                        strcpy(ciudadMayor, vecCiudad[j].getNombre());
                    }
                }
            }
        }
        obj.setCodigo(vecPais[i].getCodigo());
        obj.setNombre(vecPais[i].getNombre());
        obj.setNombreCiudad(ciudadMayor);
        obj.setPoblacion(poblacionMayor);
        obj.grabarEnDisco();

    }

    delete vecCiudad;
    delete vecPais;
    return true;


}
