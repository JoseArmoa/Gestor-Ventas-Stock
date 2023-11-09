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
                system("cls");
                std::cout<<"VENTA EXITOSA"<<std::endl;
            }else{
                std::cout<<"VENTA CANCELADA"<<std::endl;
            }
            break;
        case 2:
            listarVentas();
            break;
        case 3:
            if(eliminarVenta()){
                std::cout<<"VENTA ELIMINADA"<<std::endl;
            }else{
                std::cout<<"NO SE ELIMINO VENTAS"<<std::endl;
            }
            break;
        case 4:
            if(modificarFecha()){
                std::cout<<"FECHA MODIFICADA"<<std::endl;
            }else{
                std::cout<<"NO SE MODIFICO FECHA"<<std::endl;
            }
            break;
        case 5:
            if(devolucion()){
                std::cout<<"DEVOLUCION EXITOSA"<<std::endl;
            }else{
                std::cout<<"NO PUDO CARGARSE DEVOLUCION"<<std::endl;
            }
            break;
        case 0:
            return;
        default: std::cout<<"OPCION INVALIDA. "<<std::endl;
            break;
        }
        system("pause");
        system("cls");
    }
}
bool cargarVentas(){
    clsVentas rVentas;
    clsCelular rCelular;
    clsCliente rCliente;
    ArchivoCliente archiCLiente("clientes.dat");
    ArchivosCelular archiCelular("celulares.dat");
    ArchivosVentas archiVentas("ventas.dat");
    ArchivoCelularVendido archiCelularVendido("vendidos.dat");
    char mod[30];
    int tam = 1, pos,cantRegistros,dni,encontro;
    float total = 0;//acumulador que ira sumando o restando el importe a medida que añadan o eliminen articulos a la venta.
    bool bandera=true;//bandera para saber si es el primer producto a agregar.

    vectorDinamicoCelular v(tam);//Inicializamos vector dinamico que contiene los productos de la venta empezando el valor en 1.
    char op;//cuando se ingrese a la funcion ventas se inicializa la opcion para automaticamente añadir un producto a la venta.
    std::cout<<"DNI: ";
    std::cin>>dni;
    encontro = archiCLiente.leerDni(dni);
    if(encontro > -1){
        rCliente = archiCLiente.leer(encontro);
    }else{
        std::cout<<"CLIENTE NO EXISTE"<<std::endl;
        std::cout<<"desea agregarlo?"<<std::endl<<std::endl;
        std::cout<<"A: AGREGAR   Q: CANCELAR";
        std::cin>>op;
        if(op=='A' || op == 'a'){
            if(agregarCliente(dni)){
                 std::cout<<"CLIENTE AGREGADO"<<std::endl;
                 rCliente = archiCLiente.leer(archiCLiente.leerDni(dni));
                 op = 'n';
                 system("pause");
                 system("cls");
            }else{
                std::cout<<"ERROR AL CARGAR CLIENTE"<<std::endl;
                op = 'q';
            }
        }
    }
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
                    if(rCelular.getDisponibilidad()){
                        total += rCelular.getPrecio();//sumamos el precio del producto en el acumulador.
                        v.agregar(rCelular);//agregamos el registro al vector dinamico.
                        bandera = false;
                    }else{
                        std::cout<<"PRODUCTO SIN STOCK O NO DISPONIBLE"<<std::endl;
                    }
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
                      if(rCelular.getDisponibilidad()){
                        total += rCelular.getPrecio();
                        tam++;//incrementamos la variable que contiene la cantidad de registros.
                        v.aumentar(tam);//incrementamos el vector dinamico
                        v.agregar(rCelular);//agregamos el nuevo registro(la funcion siempre va a carga en la ultima posicion disponible)
                      }else{
                        std::cout<<"PRODUCTO SIN STOCK O NO DISPONIBLE"<<std::endl;
                      }
                    }else{
                    std::cout<<"MODELO INCORRECTO"<<std::endl;
                    }
            }
                break;
            case 'y': case 'Y':
                cantRegistros= archiVentas.contarRegistros();
                if(cantRegistros == -1){
                    rVentas.setCodVenta(1);
                    rVentas.setDniCliente(rCliente.getDNI());
                    rVentas.setCantidad(tam);
                    rVentas.setTotal(total);
                    guardarVectorArchivo(v,tam,1);
                    archiVentas.Cargar(rVentas);
                    return true;
                }else{
                    rVentas.setCodVenta(cantRegistros+1);
                    rVentas.setDniCliente(rCliente.getDNI());
                    rVentas.setCantidad(tam);
                    rVentas.setTotal(total);
                    guardarVectorArchivo(v,tam,cantRegistros+1);
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
                    if(v.eliminar(mod)){//La funcion eliminar busca dentro del vector dinamico el modelo pasado como parametro, si lo encuentra lo elimina y modifica su tamaño, si no no hace nada.
                        total -= rCelular.getPrecio();//descuenta el precio del registro eliminado.
                        tam--;
                    }
                }
                break;
            case 'q': case 'Q':
                return false;
                break;
            default: std::cout<<"OPCION INVALIDA. "<<std::endl;
                    break;
        }
        system("cls");
        rCliente.mostrarMenos();
        std::cout<<std::endl;
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
    int tam= archi.contarRegistros();
    for(int i=0;i<tam;i++){
		clsVentas reg = archi.Leer(i);
		reg.Mostrar();
    }
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
    if(r.getStock()==0){
        r.setDisponibilidad(false);
        archiCelular.modificar_registro(pos,r);
    }else{
        archiCelular.modificar_registro(pos,r);
    }
}
bool eliminarVenta(){
    clsVentas rVentas;
    ArchivosVentas aVentas("ventas.dat");
    int cod;
    int tam = aVentas.contarRegistros();
    std::cout<<"INGRESE CODIGO DE VENTA: ";
    std::cin>>cod;
    if(cod <= tam){
        rVentas = aVentas.Leer(cod-1);
        rVentas.Mostrar();
        char op;
        std::cout<<std::endl;
        std::cout<<"DESEA ELIMINAR ESTA VENTA?"<<std::endl;
        std::cout<<"Y: CONFIRMAR  CUALQUIE TECLA: CANCELAR"<<std::endl;
        std::cin>>op;
        system("cls");
        if(op == 'y' || op == 'Y'){
            rVentas.setEstado(false);
            if(aVentas.Modificar(cod-1,rVentas)) return true;
            return false;
        }
        return false;
        }
    std::cout<<"CODIGO VENTA INCORRECTO"<<std::endl;
    return false;
    system("cls");
}
bool modificarFecha(){
    Fecha nueva;
    ArchivosVentas aVentas("ventas.dat");
    clsVentas rVentas;
    int tam = aVentas.contarRegistros();
    int cod;
    std::cout<<"INGRESE CODIGO DE VENTA: ";
    std::cin>>cod;
    if(cod <= tam){
        rVentas = aVentas.Leer(cod-1);
        rVentas.Mostrar();
        char op;
        std::cout<<std::endl;
        std::cout<<"DESEA MODIFICAR FECHA?"<<std::endl;
        std::cout<<"Y: CONFIRMAR  CUALQUIE TECLA: CANCELAR"<<std::endl;
        std::cin>>op;
        system("cls");
        if(op == 'y' || op == 'Y'){
            std::cout<<"INGRESE FECHA NUEVA: "<<std::endl;
            nueva.Cargar();
            rVentas.setFecha(nueva);
            if(aVentas.Modificar(cod-1,rVentas)) return true;
            return false;
        }
        return false;
        }

    std::cout<<"CODIGO VENTA INCORRECTO"<<std::endl;
    return false;
}
bool devolucion(){
    ArchivosVentas aVentas("ventas.dat");
    clsVentas rVentas;
    char mod[30];
    int tam = aVentas.contarRegistros();
    int cod;
    std::cout<<"INGRESE CODIGO DE VENTA ";
    std::cin>>cod;
    if(cod > 0 && cod <= tam){
        rVentas = aVentas.Leer(cod-1);
        if(rVentas.getCantidad()==1){
            rVentas.Mostrar();
            std::cout<<std::endl;
            std::cout<<"DESEA ELIMINAR ESTA VENTA?"<<std::endl;
            std::cout<<"Y: CONFIRMAR  CUALQUIE TECLA: CANCELAR"<<std::endl;
            char op;
            std::cin>>op;
            system("cls");
            if(op == 'y' || op == 'Y'){
                rVentas.setEstado(false);
                aVentas.Modificar(cod-1,rVentas);
                return true;
            }else{
                return false;
            }
        }else{
            rVentas.Mostrar();
            std::cout<<std::endl;
            std::cout<<"INGRESE MODELO A ELIMINAR ";
            std::cin.ignore();
            std::cin.getline(mod,30);
            ArchivoCelularVendido aCelularVendido("vendidos.dat");
            int pos;
            celularVendido rCelularVendido;
            rCelularVendido = aCelularVendido.LeerIndividual(cod,mod,pos);
            rCelularVendido.setEstado(false);
            aCelularVendido.modificar(pos,rCelularVendido);
            rVentas.setCantidad(rVentas.getCantidad()-1);
            if(rVentas.getCantidad()== 0){
                rVentas.setEstado(false);
                aVentas.Modificar(cod-1,rVentas);
                return true;
            }else{
                rVentas.setTotal(rVentas.getTotal()-rCelularVendido.getPrecio());
                aVentas.Modificar(cod-1,rVentas);
                return true;
            }
        }
    }else{
        std::cout<<"CODIGO INCORRECTO"<<std::endl;
    }
    return false;
}
void mostrarMenuVentas(){
    std::cout<<"MENU VENTAS"<<std::endl;
    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"1.VENTA NUEVA"<<std::endl;
    std::cout<<"2.LISTAR VENTAS"<<std::endl;
    std::cout<<"3.ELIMINAR VENTA"<<std::endl;
    std::cout<<"4.MODIFICAR FECHA VENTAS"<<std::endl;
    std::cout<<"5.DEVOLVER TELEFONO"<<std::endl;
    std::cout<<"0.VOLVER"<<std::endl;
    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"Ingrese una opcion."<<std::endl;
}
