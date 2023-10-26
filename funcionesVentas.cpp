#include "funcionesVentas.h"

void menuVentas(){
    int op;
    while(true){
    mostrarMenuVentas();
    std::cin>>op;
    system("cls");
        switch(op){
        case 1:
            break;
        case 2:
            break;
        case 0:
            return;
        default:
            break;
        }
        system("pause");
    }
}
bool cargarVentas(){}
void listarVentas(){}


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
