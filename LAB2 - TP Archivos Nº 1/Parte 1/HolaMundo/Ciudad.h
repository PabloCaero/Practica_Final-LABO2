#ifndef CIUDAD_H
#define CIUDAD_H

class Ciudad
{
public:
    int getID();
    char * getIDPais();
    char * getNombre();
    int getPoblacion();
    void setID(int);
    void setIDPais(const char *);
    void setNombre(const char *);
    void setPoblacion(int);
    void mostrar();
    bool grabarEnDisco(int);
    bool leerDeDisco(int);
    bool grabarEnDisco();

private:
    int _ID;
    char _nombre[35];
    char _idpais[4];
    int _poblacion;
};

void leerCiudades(Ciudad *, int);
int contarCiudades();
void listarCiudades();
int buscarCiudadxID(int);
bool nuevaCiudad();

void listarCiudadesxIDPais();

#endif // CIUDAD_H
