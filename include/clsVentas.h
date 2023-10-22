
class clsVentas
{
    private:
        int codVenta;
        int dniCliente;
        int idCelular;
        Fecha diaVenta;
        float total;
        bool estado;
    public:
        clsVentas();
    ///Metodos Set
        void setCodVenta(int c);
        void setDniCliente(int d);
        void setIdCelular(int id);
        void setFecha(Fecha f);
        void setTotal(float t);
        void setEstado(bool e);
    ///Metodos Get
        int getCodVenta();
        int getDniCliente();
        int getIdCelular();
        int getFecha();
        float getTotal();
        bool getEstado();
    ///Metodos Principales
        bool Cargar(int num);
        void Mostrar();
};


