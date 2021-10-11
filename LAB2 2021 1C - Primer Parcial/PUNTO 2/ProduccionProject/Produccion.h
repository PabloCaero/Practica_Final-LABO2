#ifndef PRODUCCION_H
#define PRODUCCION_H
#include "Fecha.h"

class Produccion
{
    private:
        int _numeroMaquina;
        int _tipo;
        Fecha _fecha;
        int _piezasTotales;
        int _piezasDefectuosas;
        float _temperatura;
    public:
        Produccion();
        int getNumeroMaquina();
        void setNumeroMaquina(int numeroMaquina);
        int getTipo();
        void setTipo(int tipo);
        Fecha getFecha();
        void setFecha(Fecha fecha);
        int getPiezasTotales();
        void setPiezasTotales(int piezasTotales);
        int getPiezasDefectuosas() ;
        void setPiezasDefectuosas(int piezasDefectuosas);
        float getTemperatura();
        void setTemperatura(float temperatura);
        bool grabarEnDisco();
        bool leerDeDisco(int pos);
        void mostrar();
};

void listarDisco();
void leerProducciones(Produccion*, int);
int contarProducciones();


#endif // PRODUCCION_H
