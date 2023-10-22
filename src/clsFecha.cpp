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
    cout<<"DIA: ";
    cin>>dia;
    cout<<"MES: ";
    cin>>mes;
    cout<<"ANIO: ";
    cin>>anio;
}

void Fecha::Mostrar(){
    cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
}
