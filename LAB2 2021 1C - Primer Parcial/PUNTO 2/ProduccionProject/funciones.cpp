#include <iostream>
#include <cstring>
#include "Produccion.h"
#include "Defectuosa.h"
#include "rlutil.h"
#include "funciones.h"

using namespace std;

void punto1()
{
    int i, j;
    int piezasDefectuosas, piezasTotales;
    float porcentajeDefectuosas;
    piezasDefectuosas = piezasTotales = 0;
    porcentajeDefectuosas = 0;
    int cant = contarProducciones();

    if(cant == 0)
    {
        return;
    }


    Produccion *vec;
    vec = new Produccion[cant];
    if(vec==NULL)
    {
        return;
    }

    leerProducciones(vec, cant);
     cout << "POR CADA MAQUINA, EL PORCENTAJE DE PIEZAS DEFECTUOSAS EN RELACION AL TOTAL DE PIEZAS PRODUCIDAS" << endl;
    cout << "----------------------" << endl;
    cout << "----------------------" << endl;
    for(j=0; j<50; j++)
    {
        for(i=0; i<cant; i++)
        {
            if(j+1==vec[i].getNumeroMaquina())
            {
                piezasTotales += vec[i].getPiezasTotales();
                piezasDefectuosas += vec[i].getPiezasDefectuosas();
            }

        }

        porcentajeDefectuosas = ((float)piezasDefectuosas*100)/((float)piezasTotales);
        cout << "MAQUINA #" << j+1 << endl;
        cout << "----------------------" << endl;
        cout << "PIEZAS TOTALES    : " << piezasTotales << endl;
        cout << "PIEZAS DEFECTUOSAS: " << piezasDefectuosas << " --> % " << porcentajeDefectuosas<<endl;
        cout << "----------------------" << endl;

        piezasDefectuosas = piezasTotales = 0;
        porcentajeDefectuosas = 0;

    }

}

void punto2()
{
    int i, j;
    float porcentajeDefectuosas;
    int cant = contarProducciones();

    if(cant == 0)
    {
        return;
    }


    Produccion *vec;
    vec = new Produccion[cant];
    if(vec==NULL)
    {
        return;
    }

    leerProducciones(vec, cant);

    cout << "MESES DEL 2020 QUE NO REGISTRARON TEMPERATURAS FUERA DE LOS VALORES OPTIMOS" << endl;
    cout << "----------------------" << endl;
    cout << "----------------------" << endl;
    for(j=0; j<50; j++)
    {
        cout << "MAQUINA #" << j+1 << endl;
        cout << "----------------------" << endl;

        for(i=0; i<cant; i++)
        {
            if(vec[i].getNumeroMaquina()==j+1 && vec[i].getFecha().getAnio()==2020)
            {
                switch (vec[i].getTipo())
                {
                case 1:
                    if(vec[i].getTemperatura()>=35 &&vec[i].getTemperatura()<=38)
                    {
                    }
                    else
                    {
                        cout << vec[i].getFecha().getMes() << ", ";
                    }

                    break;
                case 2:
                    if(vec[i].getTemperatura()>=32 &&vec[i].getTemperatura()<=44)
                    {
                    }
                    else
                    {
                        cout << vec[i].getFecha().getMes() << ", ";
                    }
                    break;
                case 3:
                    if(vec[i].getTemperatura()>=35 &&vec[i].getTemperatura()<=39.5)
                    {
                    }
                    else
                    {
                        cout << vec[i].getFecha().getMes() << ", ";
                    }
                    break;
                case 4:
                    if(vec[i].getTemperatura()>=30 &&vec[i].getTemperatura()<=45)
                    {
                    }
                    else
                    {
                        cout << vec[i].getFecha().getMes() << ", ";
                    }
                    break;
                case 5:
                    if(vec[i].getTemperatura()>=28 && vec[i].getTemperatura()<=38)
                    {
                    }
                    else
                    {
                        cout << vec[i].getFecha().getMes() << ", ";
                    }
                    break;
                }
            }
        }
        cout << endl;
        cout << "----------------------" << endl;
    }
}

bool punto3()
{
    bool guardo = 0;
    int i, j;
    int piezasDefectuosas;
    float porcentajeDefectuosas;
    piezasDefectuosas = 0;

    int cant = contarProducciones();

    if(cant == 0)
    {
        return 0;
    }

    Defectuosa aux;
    Produccion *vec;
    vec = new Produccion[cant];
    if(vec==NULL)
    {
        return 0;
    }

    leerProducciones(vec, cant);

    for(j=0; j<50; j++)
    {
        for(i=0; i<cant; i++)
        {
            if(j+1==vec[i].getNumeroMaquina())
            {
                piezasDefectuosas += vec[i].getPiezasDefectuosas();
            }

        }

        aux.setNumeroMaquina(j+1);
        aux.setPiezasDefectuosas(piezasDefectuosas);
        aux.escribirEnDisco();

        piezasDefectuosas = 0;


    }

    guardo = 1;
    return guardo;

}
