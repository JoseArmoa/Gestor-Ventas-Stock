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
                std::cout<<"VENTA EXITOSA"<<std::endl;
            }else{
                std::cout<<"VENTA CANCELADA"<<std::endl;
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
        system("cls");
    }
}
bool cargarVentas(){
    clsVentas rVentas;
    clsCelular rCelular;
    ArchivosCelular archiCelular("celulares.dat");
    ArchivosVentas archiVentas("ventas.dat");
    char mod[30];
    int tam = 1, pos;
    float total = 0;
    bool bandera=true;
    vectorDinamicoCelular v(tam);
    char op = 'a';
    while(true){
            switch(op){
            case 'A':case 'a':
                if(bandera){
                  std::cout<<"MODELO: ";
                  std::cin.ignore();
                  std::cin.getline(mod,30);
                  pos = archiCelular.buscarCelular(mod);
                  if(pos != -1){
                    rCelular = archiCelular.Leer(pos);
                    total += rCelular.getPrecio();
                    v.agregar(rCelular);
                    bandera = false;
                  }else{
                    std::cout<<"MODELO INCORRECTO"<<std::endl;
                  }
                }else{
                    std::cout<<"MODELO: ";
                    std::cin.ignore();
                    std::cin.getline(mod,30);
                    int pos = archiCelular.buscarCelular(mod);
                    if(pos != -1){
                      rCelular = archiCelular.Leer(pos);
                      total += rCelular.getPrecio();
                      tam++;
                      v.aumentar(tam);
                      v.agregar(rCelular);
                    }else{
                    std::cout<<"MODELO INCORRECTO"<<std::endl;
                    }
            }
                break;
            case 'y': case 'Y':
                rVentas.setCodVenta(1);
                rVentas.setDniCliente(1111);
                rVentas.setCantidad(tam);
                rVentas.setVectorCelulares(&v,tam);
                rVentas.setTotal(total);
                archiVentas.Cargar(rVentas);
                return true;
                break;
            case 'e': case 'E':
                std::cout<<"MODELO: ";
                std::cin.ignore();
                std::cin.getline(mod,30);
                pos = archiCelular.buscarCelular(mod);
                if(pos != -1){
                rCelular = archiCelular.Leer(pos);
                total -= rCelular.getPrecio();
                v.eliminar(mod);
                tam--;
                }
                break;
            case 'q': case 'Q':
                return false;
                break;
        }
        system("pause");
        system("cls");
        v.mostrar();
        std::cout<<std::endl;
        std::cout<<std::endl;
        std::cout<<"TOTAL: $"<<total<<std::endl;
        std::cout<<std::endl;
        std::cout<<"Y:CONFIRMAR VENTA  A:AGREGAR PRODUCTO  E:ELIMINAR PRODUCTO Q:CANCELAR VENTA"<<std::endl;
        std::cin>>op;
    }
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
