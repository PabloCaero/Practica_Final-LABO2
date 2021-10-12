#ifndef MUNDO_H
#define MUNDO_H


class Mundo
{
    public:
        void setCodigo(char *);
        void setNombre(char *);
        void setNombreCiudad(char *);
        void setPoblacion(int );

        void mostrar();

        bool leerDeDisco(int);
        bool grabarEnDisco();


    private:
        char _codigo[4];
        char _nombre[35];
        char _nombreCiudad[35];
        int _poblacionCiudad;

};

void listarMundo();
bool generarMundo();

#endif // MUNDO_H
