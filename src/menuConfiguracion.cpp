#include "menuConfiguracion.h"

void menuConfiguracion(){
    int op;
    while(true){
    mostrarMenuConfiguraion();
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
        system("cls");
    }
}
bool creaCopiaSeguridadStock(){
}
bool recuperarDatos(){
}
void mostrarMenuConfiguraion(){
    std::cout<<"MENU VENTAS"<<std::endl;
    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"1)CREAR COPIA SEGURIDAD"<<std::endl;
    std::cout<<"2)RECUPERAR DATOS"<<std::endl;
    std::cout<<"3)BORRAR DATOS"<<std::endl;
    std::cout<<"0)VOLVER"<<std::endl;
    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"Ingrese una opcion."<<std::endl;
}
