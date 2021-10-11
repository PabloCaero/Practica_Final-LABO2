#ifndef DEFECTUOSA_H
#define DEFECTUOSA_H


class Defectuosa
{
    public:
        void setNumeroMaquina(int);
        void setPiezasDefectuosas(int);

        void mostrar();

        bool escribirEnDisco();

    private:
        int _numeroMaquina;
        int _piezasDefectuosas;
};

void listarDefectuosas();
#endif // DEFECTUOSA_H
