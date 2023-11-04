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
    ArchivoCelularVendido archiCelularVendido("vendidos.dat");
    ArchivosCelular archiCelular("celulares.dat");
    ArchivosVentas archiVentas("ventas.dat");
    char mod[30];
    int tam = 1, pos,cantRegistros;
    float total = 0;//acumulador que ira sumando o restando el importe a medida que a�adan o eliminen articulos a la venta.
    bool bandera=true;//bandera para saber si es el primer producto a agregar.

    vectorDinamicoCelular v(tam);//Inicializamos vector dinamico que contiene los productos de la venta empezando el valor en 1.
    char op = 'a';//cuando se ingrese a la funcion ventas se inicializa la opcion para automaticamente a�adir un producto a la venta.
    while(true){
            switch(op){
            case 'A':case 'a':///CASO A PARA AGREGA PRODUCTO A LA VENTA
                if(bandera){
                  std::cout<<"MODELO: ";
                  std::cin.ignore();
                  std::cin.getline(mod,30);
                  pos = archiCelular.buscarCelular(mod);
                  if(pos != -1){//verifica que el modelo exista en el archivo
                    rCelular = archiCelular.Leer(pos);//lee el registro en la posicion.
                    total += rCelular.getPrecio();//sumamos el precio del producto en el acumulador.
                    v.agregar(rCelular);//agregamos el registro al vector dinamico.
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
                      tam++;//incrementamos la variable que contiene la cantidad de registros.
                      v.aumentar(tam);//incrementamos el vector dinamico
                      v.agregar(rCelular);//agregamos el nuevo registro(la funcion siempre va a carga en la ultima posicion disponible)
                    }else{
                    std::cout<<"MODELO INCORRECTO"<<std::endl;
                    }
            }
                break;
            case 'y': case 'Y':
                cantRegistros= archiVentas.contarRegistros();
                if(cantRegistros == -1){
                    rVentas.setCodVenta(1);
                    rVentas.setDniCliente(1111);
                    rVentas.setCantidad(tam);
                    rVentas.setTotal(total);
                    guardarVectorArchivo(v,tam,cantRegistros);
                    archiVentas.Cargar(rVentas);
                    return true;
                }else{
                    rVentas.setCodVenta(cantRegistros+1);
                    rVentas.setDniCliente(1111);
                    rVentas.setCantidad(tam);
                    rVentas.setTotal(total);
                    guardarVectorArchivo(v,tam,cantRegistros);
                    archiVentas.Cargar(rVentas);
                    return true;
                }
                break;
            case 'e': case 'E':
                std::cout<<"MODELO: ";
                std::cin.ignore();
                std::cin.getline(mod,30);
                pos = archiCelular.buscarCelular(mod);
                if(pos != -1){
                rCelular = archiCelular.Leer(pos);
                    if(v.eliminar(mod)){//La funcion eliminar busca dentro del vector dinamico el modelo pasado como parametro, si lo encuentra lo elimina y modifica su tama�o, si no no hace nada.
                        total -= rCelular.getPrecio();//descuenta el precio del registro eliminado.
                        tam--;
                    }
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
void guardarVectorArchivo(vectorDinamicoCelular &v,int tam, int c){
    ArchivoCelularVendido archi("vendidos.dat");

    clsCelular rCelular;
    celularVendido r;
    for(int i=0;i<tam;i++){
        rCelular = v[i];
        descontarStock(rCelular);
        r.cargar(c,rCelular);
        archi.cargar(r);
    }
}
void descontarStock(clsCelular &r){
    ArchivosCelular archiCelular("celulares.dat");
    int pos = archiCelular.buscarCelular(r.getModelo());
    r.setStock(r.getStock()-1);
    r.mostrar();
    system("pause");
    archiCelular.modificar_registro(pos, r);
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
