#include "clsFecha.h"
#include <ctime>

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
    /*cout<<"DIA: "<<dia<<endl;
    cout<<"MES: "<<mes<<endl;
    cout<<"ANIO: "<<anio<<endl<<endl;*/
    cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
}
