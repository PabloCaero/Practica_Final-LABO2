#ifndef TEMPORIZADOR_H
#define TEMPORIZADOR_H


class Temporizador
{
    public:
        Temporizador(int, int, int);
        void TIC();
        void Mostrar();
        int Comparar(Temporizador);

    private:
          int _segundos;
          int _minutos;
          int _horas;

};

#endif // TEMPORIZADOR_H
