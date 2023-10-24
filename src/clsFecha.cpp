#include <iostream>
#include <ctime>
#include "clsFecha.h"


Fecha::Fecha(){
    time_t tiempo = time(nullptr);
    tm* fecha = localtime(&tiempo);

    setDia(fecha->tm_mday);
    setMes(fecha->tm_mon+1);
    setAnio(fecha->tm_year + 1900);

}

Fecha::Fecha(int d, int m, int a)
    :dia(0),mes(0),anio(0)
    {
            setDia(d);
            setMes(m);
            setAnio(a);
    }

 void Fecha::Cargar(){
    std::cout<<"DIA: ";
    std::cin>>dia;
    std::cout<<"MES: ";
    std::cin>>mes;
    std::cout<<"ANIO: ";
    std::cin>>anio;
}

void Fecha::Mostrar(){
    std::cout<<dia<<"/"<<mes<<"/"<<anio<<std::endl;
}


