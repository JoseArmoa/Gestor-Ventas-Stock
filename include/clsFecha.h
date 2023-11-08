#ifndef CLSFECHA_H_INCLUDED
#define CLSFECHA_H_INCLUDED
class Fecha{
    private:
        int dia, mes, anio;
    public:
        Fecha();
        Fecha(int d, int m, int a);
        bool Cargar();
        void Mostrar();

        ///sets
        void setDia(int x,int m,int a);
        void setMes(int x);
        void setAnio(int x);
        ///gets
        int getDia();
        int getMes();
        int getAnio();

        bool operator==(Fecha f);
        bool operator<(Fecha f);
        bool operator>(Fecha f);
        bool operator<=(Fecha f);
        bool operator>=(Fecha f);

};
#endif // CLSFECHA_H_INCLUDED
