#include "Temporizador.h"
#include <iostream>

using namespace std;

Temporizador::Temporizador()
{
    int horas, minutos, segundos;
    cout << "HORAS   : ";
    cin >> horas;
    cout << "MINUTOS : ";
    cin >> minutos;
    cout << "SEGUNDOS: ";
    cin >> segundos;
    if(horas >= 0 && minutos >=0 && minutos <=59 && segundos >=0 & segundos <=59)
    {
        _horas = horas;
        _minutos = minutos;
        _segundos = segundos;
    }
    else
    {
        cout << "FORMATO INCORRECTO, " <<endl;
        _horas = 0;
        _minutos = 0;
        _segundos = 0;
        cout << "HORAS   : " << _horas << endl;
        cout << "MINUTOS : " << _minutos << endl;
        cout << "SEGUNDOS: " << _segundos << endl;;
    }
}

void Temporizador::tic()
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

void Temporizador::mostrar()
{
    cout << _horas << ":" << _minutos << ":" << _segundos << endl;
}

int Temporizador::comparar(Temporizador obj)
{
    //COMPARA SI SON IGUALES
    if(_horas==obj._horas && _minutos==obj._minutos && _segundos == obj._segundos)
    {
        return 0;
    }

    //COMPARA SI EL OBJETO RECIBIDO COMO PARAMETRO ES MENOR AL TEMPORIZADOR
    if(_horas > obj._horas)
    {
        return 1;
    }

    if(_horas == obj._horas && _minutos > obj._minutos)
    {
        return 1;
    }

    if(_horas == obj._horas && _minutos == obj._minutos && _segundos > obj._segundos)
    {
        return 1;
    }

    //COMPARA SI EL OBJETO RECIBIDO COMO PARAMETRO ES MAYOR AL TEMPORIZADOR
    if(_horas < obj._horas)
    {
        return -1;
    }

    if(_horas == obj._horas && _minutos < obj._minutos)
    {
        return -1;
    }

    if(_horas == obj._horas && _minutos == obj._minutos && _segundos < obj._segundos)
    {
        return -1;
    }
}

void Temporizador::tac()
{
    tic();
}

