#include <iostream>
#include <cstring>
#include "clsVentas.h"

clsVentas::clsVentas()
{
    setCodVenta(0);
    setDniCliente(0);
    setIdCelular(0);
    setTotal(0);
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
int clsVentas::getDniCliente(){return dniCliente;}
int clsVentas::getIdCelular(){return idCelular;}
Fecha clsVentas::getFecha(){return diaVenta;}
float clsVentas::getTotal(){return total;}
bool clsVentas::getEstado(){return estado;}
///Metodos Principales
bool clsVentas::Cargar(int num){
    int d, id;
    float t;
    Fecha f;
    if(num == -1 ){
        std::cout<<"COD VENTA: ";
        std::cin>>num;
        setCodVenta(num);
    }else setCodVenta(num);
    std::cout<<"DNI CLIENTE: ";
    std::cin>>d;
    setDniCliente(d);
    std::cout<<"ID CELULAR: ";
    std::cin>>id;
    setIdCelular(id);
    std::cout<<"FECHA: ";
    f.Cargar();
    setFecha(f);
    std::cout<<"TOTAL: ";
    std::cin>>t;
    setTotal(t);
    return true;
}
void clsVentas::Mostrar(){
    std::cout<<"COD VENTA: "<<codVenta<<std::endl;
    std::cout<<"DNI CLIENTE: "<<dniCliente<<std::endl;
    std::cout<<"ID CELULAR: "<<idCelular<<std::endl;
    std::cout<<"FECHA: ";
    diaVenta.Mostrar();
    std::cout<<"TOTAL: "<<total<<std::endl<<std::endl;
}


ArchivosVentas::ArchivosVentas(const char *n){
    strcpy(nombreArchivo,n);
}

bool ArchivosVentas::Cargar(clsVentas r){
    FILE *p;
    p = fopen(nombreArchivo,"ab");
    if(p==NULL){
        return false;
    }
    int escribio = fwrite(&r,sizeof(clsVentas),1,p);
    if(escribio == 1){
        fclose(p);
        return true;
    }
    fclose(p);
    return false;
}

void ArchivosVentas::Leer(){
    clsVentas r;
    FILE *p;
    p = fopen(nombreArchivo,"rb");
    if(p==NULL){
        std::cout<<"ERROR ARCHIVO"<<std::endl;
    }
    while(fread(&r,sizeof(clsVentas),1,p)){
        r.Mostrar();
    }
    fclose(p);
    }

    int ArchivosVentas::contarRegistros(){
        FILE *p;
        p = fopen(nombreArchivo,"rb");
        if(p==NULL){
            std::cout<<"ERROR ARCHIVO"<<std::endl;
            return -1;
        }
        fseek(p,0,2);
        int cant = ftell(p);
        fclose(p);
        return cant/sizeof(clsVentas);
    }
