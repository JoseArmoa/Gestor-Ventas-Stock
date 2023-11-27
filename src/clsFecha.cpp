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
    if(dia == -1 || anio == -1 || mes == -1)return false;
    return true;
}

void Fecha::Mostrar(){
    std::cout<<dia<<"/"<<mes<<"/"<<anio<<std::endl;
}

void Fecha::setDia(int x, int m, int a){
    if(a%4 == 0){
        switch(m){
            case 1:
                if(x > 0 && x < 32) dia = x;
                else dia = -1;
                break;
            case 2:
                if(x > 0 && x < 30) dia = x;
                else dia = -1;
                break;
            case 3:
                if(x > 0 && x < 32) dia = x;
                else dia = -1;
                break;
            case 4:
                if(x > 0 && x < 31) dia = x;
                else dia = -1;
                break;
            case 5:
                if(x > 0 && x < 32) dia = x;
                else dia = -1;
                break;
            case 6:
                if(x > 0 && x < 31) dia = x;
                else dia = -1;
                break;
            case 7:
                if(x > 0 && x < 32) dia = x;
                else dia = -1;
                break;
            case 8:
                if(x > 0 && x < 32) dia = x;
                else dia = -1;
                break;
            case 9:
                if(x > 0 && x < 31) dia = x;
                else dia = -1;
                break;
            case 10:
                if(x > 0 && x < 32) dia = x;
                else dia = -1;
                break;
            case 11:
                if(x > 0 && x < 31) dia = x;
                else dia = -1;
                break;
            case 12:
                if(x > 0 && x < 32) dia = x;
                else dia = -1;
                break;
        }
    }else{
        switch(m){
            case 1:
                if(x > 0 && x < 32) dia = x;
                else dia = -1;
                break;
            case 2:
                if(x > 0 && x < 29) dia = x;
                else dia = -1;
                break;
            case 3:
                if(x > 0 && x < 32) dia = x;
                else dia = -1;
                break;
            case 4:
                if(x > 0 && x < 31) dia = x;
                else dia = -1;
                break;
            case 5:
                if(x > 0 && x < 32) dia = x;
                else dia = -1;
                break;
            case 6:
                if(x > 0 && x < 31) dia = x;
                else dia = -1;
                break;
            case 7:
                if(x > 0 && x < 32) dia = x;
                else dia = -1;
                break;
            case 8:
                if(x > 0 && x < 32) dia = x;
                else dia = -1;
                break;
            case 9:
                if(x > 0 && x < 31) dia = x;
                else dia = -1;
                break;
            case 10:
                if(x > 0 && x < 32) dia = x;
                else dia = -1;
                break;
            case 11:
                if(x > 0 && x < 31) dia = x;
                else dia = -1;
                break;
            case 12:
                if(x > 0 && x < 32) dia = x;
                else dia = -1;
                break;
        }
    }
}
void Fecha::setMes(int x){
    if(x>0 && x<13){
        mes=x;
    }else{
    mes = -1;
    }
}
void Fecha::setAnio(int x){
    if(x > 1900){
        anio = x;
    }
}

int Fecha::getDia(){return dia;}
int Fecha::getMes(){return mes;}
int Fecha::getAnio(){return anio;}

bool Fecha::operator==(Fecha &f){
    if(dia == f.getDia() && mes == f.getMes() && anio == f.getAnio()) return true;
    return false;
}
bool Fecha::operator<(Fecha &f){
    if(anio < f.getAnio()) return true;
    else if(anio == f.getAnio() && mes < f.getMes())return true;
    else if(anio == f.getAnio() && mes == f.getMes() && dia < f.getDia())return true;
    return false;
}
bool Fecha::operator>(Fecha &f){
    if(anio > f.getAnio()) return true;
    else if(anio == f.getAnio() && mes > f.getMes())return true;
    else if(anio == f.getAnio() && mes == f.getMes() && dia > f.getDia())return true;
    return false;
}
bool Fecha::operator<=(Fecha &f){
    if(dia == f.getDia() && mes == f.getMes() && anio == f.getAnio()) return true;
    if(anio < f.getAnio()) return true;
    else if(anio == f.getAnio() && mes < f.getMes())return true;
    else if(anio == f.getAnio() && mes == f.getMes() && dia < f.getDia())return true;
    return false;
}
bool Fecha::operator>=(Fecha &f){
    if(dia == f.getDia() && mes == f.getMes() && anio == f.getAnio()) return true;
    if(anio > f.getAnio()) return true;
    else if(anio == f.getAnio() && mes > f.getMes())return true;
    else if(anio == f.getAnio() && mes == f.getMes() && dia > f.getDia())return true;
    return false;
}
int  Fecha::operator-(Fecha &f){
    int edad = 0;
    if(this->anio < f.getAnio()){
        if(this->mes <= f.getMes()){
            if(this->dia <= f.getDia()){
                edad = f.getAnio() - this->anio ;
            }
        }else{
            edad = (f.getAnio()-this->anio)-1;
        }
    }
    return edad;
}


