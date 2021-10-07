#include "Temporizador.h"

Temporizador::Temporizador(int horas, int minutos, int segundos)
{
    if(segundos >= 0 && segundos <= 59 && minutos >= 0 && minutos <= 59 && horas >= 0 )
    {
        _segundos = segundos;
    }
    else
    {
        _segundos = 0;
        _minutos = 0;
        _horas = 0;
    }
}


void Temporizador::TIC()
{
    _segundos++;
    if(_segundos == 60)
    {
        _minutos++;
        _segundos = 0;
        if(_minutos == 60)
        {
            _horas++;
            _minutos = 0;
        }
    }
}

void Temporizador::Mostrar()
{
    cout << _horas << ":" << _minutos << ":"<< _segundos << endl;
}

int Temporizador::Comparar(Temporizador obj)
{
    if(_horas == obj._horas && _minutos == obj._minutos && _segundos == obj._segundos)
    {
        return 0;
    }

    if(_horas > obj._horas && _minutos == obj._minutos && _segundos == obj._segundos)
    {
        return 0;
    }

}
