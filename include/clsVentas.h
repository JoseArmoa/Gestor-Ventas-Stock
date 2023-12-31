#ifndef CLSVENTAS_H_INCLUDED
#define CLSVENTAS_H_INCLUDED
#include <iostream>
#include <cstring>
#include "clsFecha.h"
#include "clsCelular.h"
class clsVentas
{
    private:
        int codVenta;
        int dniCliente;
        int cant;
        Fecha diaVenta;
        float total;
        bool estado;
    public:
        clsVentas();
        //~clsVentas();
    ///Metodos Set
        void setCodVenta(int c);
        void setDniCliente(int d);
        void setCantidad(int d);
        void setFecha(Fecha f);
        void setTotal(float t);
        void setEstado(bool e);
    ///Metodos Get
        int getCodVenta();
        int getDniCliente();
        int getIdCelular();
        Fecha getFecha();
        int getCantidad();
        float getTotal();
        bool getEstado();
    ///Metodos Principales
        bool Cargar(int);
        void Mostrar();
};



class ArchivosVentas{
private:
    char nombreArchivo[30];
public:
    ArchivosVentas(const char *v);
    bool Cargar(clsVentas r);
    clsVentas Leer(int);
    bool Modificar(int,clsVentas);
    int contarRegistros();
    bool borrar();
};


#endif // CLSFVENTASH_INCLUDED
