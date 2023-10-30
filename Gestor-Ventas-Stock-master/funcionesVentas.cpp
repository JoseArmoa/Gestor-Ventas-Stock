#include "funcionesVentas.h"

void menuVentas(){
    int op;
    while(true){
    mostrarMenuVentas();
    std::cin>>op;
    system("cls");
        switch(op){
        case 1:
            if(cargarVentas()){
                std::cout<<"VENTA EXITOSA";
            }else{
                std::cout<<"VENTA CANCELADA";
            }
            break;
        case 2:
            listarVentas();
            break;
        case 0:
            return;
        default:
            break;
        }
        system("pause");
    }
}
bool cargarVentas(){
    clsVentas r;
    ArchivosVentas archi("ventas.dat");
    int tam = archi.contarRegistros();
    r.Cargar(tam +1);
    int op;
    std::cout<<"Presione 1 para confirmar... ";
    std::cin>>op;
    if(op == 1){
        archi.Cargar(r);
        return true;
    }else return false;
}
void listarVentas(){
    ArchivosVentas archi("ventas.dat");
    archi.Leer();
}


void mostrarMenuVentas(){
    std::cout<<"MENU VENTAS"<<std::endl;
    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"1)VENTA NUEVA"<<std::endl;
    std::cout<<"2)LISTAR VENTAS"<<std::endl;
    std::cout<<"3)CANCELAR VENTA"<<std::endl;
    std::cout<<"0)VOLVER"<<std::endl;
    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"Ingrese una opcion."<<std::endl;
}
