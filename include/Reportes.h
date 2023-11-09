#ifndef REPORTES_H
#define REPORTES_H
#include <cstring>
#include "clsCelular.h"
#include "clsVentas.h"
#include "clsCliente.h"

class celular_cliente{
private:
	char modelo[30];
    char nombre[30];
    int marca;
    Fecha Fecha_compra;
    float precio;
    bool estado=false;
public:
	void setModelo(char* cadena);
    void setNombre(char* cadena);
    void setMarca(int m);
    void setFecha_compra(Fecha f);
    void setPrecio(float p);
    void setEstado(bool e);

    char* getModelo(){return modelo;}
    char* getNombre(){return nombre;}
    int getMarca(){return marca;}
    Fecha getFecha_compra(){return Fecha_compra;}
    float getPrecio(){return precio;}
    bool getEstado(){return estado;}

    void mostrar();
};
void menuReporte();
void punto_1();
void punto_2();
void punto_3();
void punto_5();
void punto_4();

#endif // REPORTES_H
