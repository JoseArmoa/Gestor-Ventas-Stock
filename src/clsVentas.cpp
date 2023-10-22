#include "clsVentas.h"

clsVentas::clsVentas()
{
    //ctor
}
///Metodos Set
void clsVentas::setCodVenta(int c){
    codVenta = c;
}
void clsVentas::setDniCliente(int d){
    dniCliente = d;
}
void clsVentas::setIdCelular(int id){
    idCelular = id;
}
void clsVentas::setFecha(Fecha f){
    diaVenta = f;
}
void clsVentas::setTotal(float f){
    total = f;
}
void clsVentas::setEstado(bool e){
    estado = e;
}
///Metodos Get
int clsVentas::getCodVenta(){return codVenta;}
int clsVentas::getDniCliente(return dniCliente;)
int clsVentas::getIdCelular(return idCelular;)
int clsVentas::getFecha(){return diaVenta;}
float clsVentas::getTotal(){return total;}
bool clsVentas::getEstado(){return estado;}
///Metodos Principales
bool clsVentas::Cargar(int num){}
void clsVentas::Mostrar(){}
