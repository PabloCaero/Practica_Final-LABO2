#include <iostream>
#include <cstring>
#include "Ciudad.h"
#include "Pais.h"

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
