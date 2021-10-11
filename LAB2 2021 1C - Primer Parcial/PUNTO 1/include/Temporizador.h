#ifndef TEMPORIZADOR_H
#define TEMPORIZADOR_H


class Temporizador
{
    public:
        Temporizador();
        void tic();
        void mostrar();
        int comparar(Temporizador);
        void tac();

        void setSegundos(int);
        void setMinutos(int);
        void setHoras(int);

        int getSegundos();
        int getMinutos();
        int getHoras();


    private:
        int _segundos;
        int _minutos;
        int _horas;
};

#endif // TEMPORIZADOR_H
