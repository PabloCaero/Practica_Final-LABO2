#include <iostream>
#include <cstring>
#include "Ciudad.h"
#include "Pais.h"
#include "Mundo.h"
#include "rlutil.h"

using namespace std;

void punto1()
{
    char codigo[4];
    int pos;
    Pais reg;

    cout << "INGRESE EL CODIGO DE PAIS A BUSCAR: ";
    cin >> codigo;

    pos = buscarPaisxCodigo(codigo);

    if(pos>=0)
    {
        reg.leerDeDisco(pos);
        reg.mostrar();

    }
    else
    {
        cout << "NO EXISTE LO BUSCADO" << endl;
    }
    return;
}

void punto2()
{
    if(nuevoPais()==true)
    {
        cout << "PAIS CARGADO CORRECTAMENTE" << endl;
    }
    else
    {
        cout << "PAIS DE CODIGO REPETIDO" << endl;
    }

    return;
}

void punto4()
{
    listarCiudadesxIDPais();
}

void punto5()
{
    int cant, i;
    float superficieTotal, porcentaje;
    cant = contarPaises();
    Pais *vec;
    vec = new Pais[cant];

    if(vec == NULL)
    {
        return;
    }

    leerPaises(vec, cant);

    for(i=0; i<cant; i++)
    {
        superficieTotal += vec[i].getSuperficie();
    }

    cout << "---LISTADO DE PAISES---" << endl;
    cout << "-----------------------" << endl;
    for(i=0; i<cant; i++)
    {
        cout << "NOMBRE    : " << vec[i].getNombre() << endl;
        cout << "SUPERFICIE: " << vec[i].getSuperficie() << endl;

        porcentaje = (vec[i].getSuperficie()*100)/(float)superficieTotal;

        cout << "REPRESENTA EL %"<< porcentaje << endl;
        cout << "-----------------------" << endl;
        porcentaje = 0;
    }

    delete vec;
}


//REPORTE DE PAISES ORDENADO POR POBLACION DECRECIENTE

void punto6()
{
    Pais *vec;
    int cant = contarPaises();
    vec = new Pais[cant];
    if(vec == NULL)
    {
        return;
    }
    leerPaises(vec, cant); //METE EN UN VECTOR DINAMICO CADA REGISTRO DEL ARCHIVO
    ordenarPaises(vec, cant);
    cout << "PAISES ORDENADOS POR POBLACION DE MANERA DECRECIENTE" << endl;
    cout << "----------------------------------------------------" << endl;
    rlutil::locate(1, 3);
    cout << "CODIGO";
    rlutil::locate(10, 3);
    cout << "NOMBRE";
    rlutil::locate(50, 3);
    cout << "POBLACION";

    for(int i=0; i < cant; i++)
    {
        rlutil::locate(1, 4+i);
        cout << vec[i].getCodigo() << " ";
        rlutil::locate(10, 4+i);
        cout << vec[i].getNombre() << " ";
        rlutil::locate(50, 4+i);
        cout << vec[i].getPoblacion() << endl;
    }
}

void punto7()
{
    if(nuevaCiudad()==true)
    {
        cout << "CIUDAD CARGADA CORRECTAMENTE" << endl;
    }
    else
    {
        cout << "NO SE CARGO LA CIUDAD" << endl;
    }

    return;
}

void punto8()
{
    char nombre[35];
    int poblacion;
    int tam;

    cout << "INGRESE EL NOMBRE DE LA CIUDAD: ";
    cin.ignore();
    cin.getline(nombre, 35);
    cout << "INGRESE LA POBLACION: ";
    cin >> poblacion;

    tam = contarCiudades();

    Ciudad *vec;
    vec = new Ciudad[tam];

    leerCiudades(vec, tam);
    ordenarCiudades(vec, tam);

    for(int i=0; i<tam; i++)
    {

        if(vec[i].getPoblacion()==poblacion)
        {
            cout << "LA CIUDAD " << nombre << " OCUPARIA EL PUESTO #" << i << endl;
            return;
        }


    }

    cout << "NO HAY CIUDAD CON POBLACION SIMILAR" << endl;
    delete vec;
    return;

}


void punto10()
{

    if(generarMundo()==true)
    {
        cout << "MUNDO.DAT creado" << endl;
        return;
    }

}
