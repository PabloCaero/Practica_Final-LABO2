#include "Ciudad.h"
#include "Pais.h"
#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;

int  Ciudad::getID()
{
    return _ID;
}
char * Ciudad::getNombre()
{
    return _nombre;
}
char * Ciudad::getIDPais()
{
    return _idpais;
}
int  Ciudad::getPoblacion()
{
    return _poblacion;
}
void Ciudad::setID(int val)
{
    _ID = val;
}
void Ciudad::setNombre(const char * val)
{
    strcpy(_nombre, val);
}
void Ciudad::setIDPais(const char * val)
{
    strcpy(_idpais, val);
}
void Ciudad::setPoblacion(int val)
{
    _poblacion = val;
}
void Ciudad::mostrar()
{
    cout << _ID << " " << _idpais << " " << _nombre << " " << _poblacion << endl;
}

bool Ciudad::grabarEnDisco(int pos)
{
    bool guardo;
    FILE *p;
    p=fopen("ciudades.dat", "rb+") ; //LEE Y SOBRESCRIBIR
    if(p==NULL)
    {
        return false;
    }
    fseek(p, sizeof(Ciudad)*pos, SEEK_SET);
    guardo = fwrite(this, sizeof(Ciudad), 1, p);
    fclose(p);
    return guardo;
}

bool Ciudad::leerDeDisco(int pos)
{
    bool lectura;
    FILE *p;
    p = fopen("ciudades.dat", "rb");
    if (p == NULL)
    {
        return false;
    }
    fseek(p, sizeof(Ciudad)*pos, SEEK_SET) ;
    lectura = fread(this, sizeof(Ciudad), 1, p);
    fclose(p);
    return lectura;
}

bool Ciudad::grabarEnDisco()
{
    bool guardo;
    FILE *p; //PUNTERO FILE
    p = fopen("ciudades.dat", "ab"); //ab: para grabar mas de un registro
    if(p==NULL)
    {
        return false;
    }
    guardo = fwrite(this, sizeof(Ciudad), 1, p) ; //THIS ES LA DIRECCION DE MEMORIA QUE LLAMA A ESTE METODO
    fclose(p);
    return guardo;
}

int contarCiudades()
{
    int bytes, cr;
    FILE *p;
    p=fopen("ciudades.dat", "rb");
    if(p==NULL)
    {
        return 0; //EL ARCHIVO EXISTE PERO NO TIENE REGISTROS
    }
    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    cr = bytes / sizeof(Ciudad);
    fclose(p);
    return cr;
}

void listarCiudades()
{
    Ciudad obj;
    FILE *p;
    p = fopen("ciudades.dat", "rb"); //IMPORTANTISIMO CAMBIAR A "RB" SOLO LECTURA
    if(p==NULL)
    {
        cout << "NO PUEDE ABRIR EL ARCHIVO";
        return;
    }
    cout << endl;
    while(fread(&obj, sizeof(Ciudad), 1, p) ==1)
    {
        obj.mostrar();
        cout << endl;
    }
    fclose(p);
}

int buscarCiudadxID(int cod)
{
    Ciudad reg;
    int i=0;
    while(reg.leerDeDisco(i))
    {
        if(cod == reg.getID())
        {
            return i;
        }
        i++;
    }
    return -1;//NUNCA ENCONTRO EL REGISTRO
}

bool nuevaCiudad()
{
    int _ID;
    char _nombre[35];
    char _idpais[4];
    int _poblacion;

    cout << "INGRESE EL ID      : ";
    cin >> _ID;

    if(buscarCiudadxID(_ID)>=0) //VALIDACION EN CASO DE SER REPETIDA
    {
        cout << "YA EXISTE" << endl;
        return false;
    }

    cout << "NOMBRE             : ";
    cin.ignore();
    cin.getline(_nombre, 45);
    cout << "CODIGO DE PAIS     : ";
    cin.getline(_idpais, 4);

    if(buscarPaisxCodigo(_idpais)<=0)
    {
        cout << "NO EXISTE EL CODIGO DE PAIS INGRESADO" << endl;
        return false;
    }

    cout << "POBLACION          : ";
    cin >> _poblacion;

    if(_poblacion <= 0)
    {
        cout << "LA POBLACION DEBE SER MAYOR A CERO" << endl;
        return false;
    }

    cout << endl;

    Ciudad nuevo;
    nuevo.setID(_ID);
    nuevo.setNombre(_nombre);
    nuevo.setIDPais(_idpais);
    nuevo.setPoblacion(_poblacion);

    return nuevo.grabarEnDisco();
}

void leerCiudades(Ciudad * vec, int tam)
{
    for(int i=0; i<tam; i++)
    {
        vec[i].leerDeDisco(i);
    }
}

void listarCiudadesxIDPais()
{
    int IDCapital;
    int cant = contarCiudades();
    int pos;
    char _IDPais[4];
    Pais pais;
    Ciudad *vec;
    vec = new Ciudad[cant] ;
    if(vec == NULL)
    {
        return;
    }

    leerCiudades(vec, cant);
    int i;
    cout << "INGRESE EL CODIGO DE PAIS: ";
    cin.ignore();
    cin.getline(_IDPais, 4);

    pos = buscarPaisxCodigo(_IDPais);
    if(pos>=0)
    {
        pais.leerDeDisco(pos);
        cout << "PAIS: " << pais.getNombre() << endl;
        cout << "----CIUDADES----" << endl;

        for(i=0; i<cant; i++)
        {
            if(strcmp(vec[i].getIDPais(), _IDPais)==0)
            {
                cout << "NOMBRE   : " << vec[i].getNombre() << endl;
                cout << "POBLACION: " << vec[i].getPoblacion() << endl;
                cout << "----------------" << endl;
            }

            if(pais.getIDCapital()==vec[i].getID())
            {
                IDCapital = vec[i].getID();
            }
        }

        Ciudad reg;
        pos = buscarCiudadxID(IDCapital);
        reg.leerDeDisco(pos);
        cout << "CAPITAL DEL PAIS: "  << reg.getNombre() << endl;
    }




    delete vec;
}

void ordenarCiudades(Ciudad *vec, int tam)
{
    int i, j, posMax;
    for(i=0; i<tam-1; i++) //LE RESTO
    {
        posMax = i;
        for(j=i+1; j<tam; j++)
        {
            if(vec[j].getPoblacion()>vec[posMax].getPoblacion()) //CAMBIANDO EL SIGNO ORDENAMOS DE MENOR A MAYOR
            {
                posMax = j;
            }
        }
        Ciudad aux = vec[i];
        vec[i] = vec[posMax];
        vec[posMax] = aux;
    }
}



