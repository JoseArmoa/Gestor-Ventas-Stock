#include <iostream>
#include <ctime>
#include "clsFecha.h"


Fecha::Fecha(){
    time_t tiempo = time(nullptr);
    tm* fecha = localtime(&tiempo);

    dia=fecha->tm_mday;
    mes=fecha->tm_mon+1;
    anio= fecha->tm_year+ 1900;

}

Fecha::Fecha(int d, int m, int a)
    :dia(0),mes(0),anio(0)
    {

    }

 bool Fecha::Cargar(){
     int d,m,a;
    std::cout<<"DIA: ";
    std::cin>>d;
    std::cout<<"MES: ";
    std::cin>>m;
    setMes(m);
    std::cout<<"ANIO: ";
    std::cin>>a;
    setAnio(a);
    setDia(d,m,a);
    if(dia==-1)return false;
    return true;
}

void Fecha::Mostrar(){
    std::cout<<dia<<"/"<<mes<<"/"<<anio<<std::endl;
}

void Fecha::setDia(int x, int m, int a){
    if(a%4 == 0){
        if(m%2 == 0 && m!=2){
            if(x>0 && x<31)dia=x;
            else dia=-1;
    }else if(m==2){
            if(x>0 && x<30)dia=x;
            else dia=-1;
    }else{
        if(x>0 && x<32)dia=x;
        else dia=-1;
    }
    }else{
        if(m%2 == 0 && m!=2){
        if(x>0 && x<31)dia=x;
        else dia=-1;
    }else if(m==2){
        if(x>0 && x<29)dia=x;
        else dia=-1;
    }else{
        if(x>0 && x<32)dia=x;
        else dia=-1;
    }
    }
    }
void Fecha::setMes(int x){if(x>0 && x<13)mes=x;}
void Fecha::setAnio(int x){anio=x;}

int Fecha::getDia(){return dia;}
int Fecha::getMes(){return mes;}
int Fecha::getAnio(){return anio;}
