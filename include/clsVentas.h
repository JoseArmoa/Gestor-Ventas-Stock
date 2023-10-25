#ifndef CLSVENTAS_H_INCLUDED
#define CLSVENTAS_H_INCLUDED

#include "clsFecha.h"
class clsVentas
{
    private:
        int codVenta;
        int dniCliente;
        int idCelular;
        Fecha diaVenta;
        float total;
        bool estado;
    public:
        clsVentas();
    ///Metodos Set
        void setCodVenta(int c);
        void setDniCliente(int d);
        void setIdCelular(int id);
        void setFecha(Fecha f);
        void setTotal(float t);
        void setEstado(bool e);
    ///Metodos Get
        int getCodVenta();
        int getDniCliente();
        int getIdCelular();
        Fecha getFecha();
        float getTotal();
        bool getEstado();
    ///Metodos Principales
        bool Cargar(int num=-1);
        void Mostrar();
};

class ArchivosVentas{
private:
    char nombreArchivo[30];
public:
    ArchivosVentas(const char *v);
    bool Cargar(clsVentas r);
    void Leer();
    int contarRegistros();

};


#endif // CLSFVENTASH_INCLUDED
