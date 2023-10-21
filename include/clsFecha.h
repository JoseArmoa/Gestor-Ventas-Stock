#ifndef CLSFECHA_H_INCLUDED
#define CLSFECHA_H_INCLUDED
#include <iostream>
using namespace std;

class Fecha{
    private:
        int dia, mes, anio;
    public:
        Fecha();
        Fecha(int d, int m, int a);
        void Cargar();
        void Mostrar();

        ///sets
        void setDia(int x){if(x>0 && x<32) dia=x;}
        void setMes(int x){if(x>0 && x<13)mes=x;}
        void setAnio(int x){anio=x;}
        ///gets
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}

};



#endif // CLSFECHA_H_INCLUDED
