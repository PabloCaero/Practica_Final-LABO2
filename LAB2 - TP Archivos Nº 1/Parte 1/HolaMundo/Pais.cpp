#include "Pais.h"
#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;

void Pais::mostrar()
{
    cout << _codigo << " " << _codigo2 << " " << _nombre << " " << _continente << " " << _superficie << " ";
    cout << _poblacion << " " << _independencia << " " << _expectativaDeVida << " " << _capital << endl;
}
void Pais::setCodigo(const char *codigo)
{
    strcpy(_codigo, codigo);
}
void Pais::setCodigo2(const char *codigo2)
{
    strcpy(_codigo2, codigo2);
}
void Pais::setNombre(const char *nombre)
{
    strcpy(_nombre, nombre);
}
void Pais::setContinente(const char *continente)
{
    strcpy(_continente, continente);
}
void Pais::setSuperficie(float superficie)
{
    _superficie = superficie;
}
void Pais::setPoblacion(int poblacion)
{
    _poblacion = poblacion;
}
void Pais::setIndependencia(short independencia)
{
    _independencia = independencia;
}
void Pais::setExpectativaDeVida(float expectativa)
{
    _expectativaDeVida = expectativa;
}
void Pais::setIDCapital(int IDCapital)
{
    _capital = IDCapital;
}
char * Pais::getCodigo()
{
    return _codigo;
}
char * Pais::getCodigo2()
{
    return _codigo2;
}
char * Pais::getNombre()
{
    return _nombre;
}
char * Pais::getContinente()
{
    return _continente;
}
float Pais::getSuperficie()
{
    return _superficie;
}
int Pais::getPoblacion()
{
    return _poblacion;
}
short Pais::getIndependencia()
{
    return _independencia;
}
float Pais::getExpectativaDeVida()
{
    return _expectativaDeVida;
}
int Pais::getIDCapital()
{
    return _capital;
}

bool Pais::grabarEnDisco(int pos)
{
    bool guardo;
    FILE *p;
    p=fopen("paises.dat", "rb+") ; //LEE Y SOBRESCRIBIR
    if(p==NULL)
    {
        return false;
    }
    fseek(p, sizeof(Pais)*pos, SEEK_SET);
    guardo = fwrite(this, sizeof(Pais), 1, p);
    fclose(p);
    return guardo;
}

bool Pais::leerDeDisco(int pos)
{
    bool lectura;
    FILE *p;
    p = fopen("paises.dat", "rb");
    if (p == NULL)
    {
        return false;
    }
    fseek(p, sizeof(Pais)*pos, SEEK_SET) ;
    lectura = fread(this, sizeof(Pais), 1, p);
    fclose(p);
    return lectura;
}

bool Pais::grabarEnDisco()
{
    bool guardo;
    FILE *p; //PUNTERO FILE
    p = fopen("paises.dat", "ab"); //ab: para grabar mas de un registro
    if(p==NULL)
    {
        return false;
    }
    guardo = fwrite(this, sizeof(Pais), 1, p) ; //THIS ES LA DIRECCION DE MEMORIA QUE LLAMA A ESTE METODO
    fclose(p);
    return guardo;
}

int contarPaises()
{
    int bytes, cr;
    FILE *p;
    p=fopen("paises.dat", "rb");
    if(p==NULL)
    {
        return 0; //EL ARCHIVO EXISTE PERO NO TIENE REGISTROS
    }
    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    cr = bytes / sizeof(Pais);
    fclose(p);
    return cr;
}

void listarPaises()
{
    Pais obj;
    FILE *p;
    p = fopen("paises.dat", "rb"); //IMPORTANTISIMO CAMBIAR A "RB" SOLO LECTURA
    if(p==NULL)
    {
        cout << "NO PUEDE ABRIR EL ARCHIVO";
        return;
    }
    cout << endl;
    while(fread(&obj, sizeof(Pais), 1, p) ==1)
    {
        obj.mostrar();
        cout << endl;
    }
    fclose(p);
}

int buscarPaisxCodigo(char *cod)
{
    Pais reg;
    int i=0;
    while(reg.leerDeDisco(i))
    {
        if(strcmp(cod, reg.getCodigo())==0)
        {
            return i;
        }
        i++;
    }
    return -1;//NUNCA ENCONTRO EL REGISTRO
}

bool nuevoPais()
{
    char _codigo[4];
    char _codigo2[3];
    char _nombre[45];
    char _continente[20];
    float _superficie;
    int _poblacion;
    short _independencia;
    float _expectativaDeVida;
    int _capital;
    cout << "INGRESE EL CODIGO : ";
    cin.ignore();
    cin.getline(_codigo, 4);

    if(buscarPaisxCodigo(_codigo)>=0) //VALIDACION EN CASO DE SER REPETIDA
    {
        return false;
    }

    cout << "INGRESE CODIGO 2   : ";
    cin.getline(_codigo2, 3);
    cout << "NOMBRE             : ";
    cin.getline(_nombre, 45);
    cout << "CONTINENTE         : ";
    cin.ignore();
    cin.getline(_continente, 20);
    cout << "SUPERFICIE         : ";
    cin >> _superficie;
    cout << "POBLACION          : ";
    cin >> _poblacion;
    cout << "INDEPENDENCIA      : ";
    cin >> _independencia;
    cout << "EXPECTATIVA DE VIDA: ";
    cin >> _expectativaDeVida;
    cout << "CAPITAL            : ";
    cin >> _capital;
    cout << endl;

    Pais nuevo;
    nuevo.setCodigo(_codigo);
    nuevo.setCodigo2(_codigo2);
    nuevo.setNombre(_nombre);
    nuevo.setContinente(_continente);
    nuevo.setSuperficie(_superficie);
    nuevo.setPoblacion(_poblacion);
    nuevo.setIndependencia(_independencia);
    nuevo.setExpectativaDeVida(_expectativaDeVida);
    nuevo.setIDCapital(_capital);

    return nuevo.grabarEnDisco();
}

void leerPaises(Pais * vec, int tam)
{
    for(int i=0; i<tam; i++)
    {
        vec[i].leerDeDisco(i);
    }
}
