#include "clsVentas.h"

clsVentas::clsVentas()
{   Fecha hoy;
    setCodVenta(0);
    setDniCliente(0);
    setTotal(0);
    setFecha(hoy);
    estado = true;
}
/*clsVentas::~clsVentas(){
    delete vectorCelulares;
}*/
///Metodos Set
void clsVentas::setCodVenta(int c){
    codVenta = c;
}
void clsVentas::setDniCliente(int d){
    dniCliente = d;
}
void clsVentas::setCantidad(int d){
    cant = d;
}
/*void clsVentas::setVectorCelulares(vectorDinamicoCelular &v,int t){
    vectorCelulares = new clsCelular[t];
    if(vectorCelulares==NULL)return;
    for(int i=0;i<t;i++){
        vectorCelulares[i]=v[i];
    }
}*/
/*void clsVentas::mostrarArticulos(){
    for(int i=0;i<cant;i++){
        vectorCelulares[i].mostrarMenos();
    }
}*/
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
Fecha clsVentas::getFecha(){return diaVenta;}
float clsVentas::getTotal(){return total;}
bool clsVentas::getEstado(){return estado;}
///Metodos Principales

void clsVentas::Mostrar(){

    std::cout<<"COD VENTA: "<<codVenta<<std::endl;
    std::cout<<"DNI CLIENTE: "<<dniCliente<<std::endl;
    std::cout<<"CANTIDAD ARTICULOS: "<<cant<<std::endl;
    std::cout<<"FECHA: ";
    diaVenta.Mostrar();
    std::cout<<"ARTICULOS: "<<std::endl;
    ArchivoCelularVendido archi("vendidos.dat");
    archi.LeerVenta(this->codVenta);
    std::cout<<"TOTAL: "<<total<<std::endl<<std::endl;
}



///FUNCIONES ARCHIVO VENTAS
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
            return 0;
        }
        fseek(p,0,2);
        int cant = ftell(p);
        fclose(p);
        return cant/sizeof(clsVentas);
    }
