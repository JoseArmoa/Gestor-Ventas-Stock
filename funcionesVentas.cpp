#include "funcionesVentas.h"
#include "rlutil.h"

void menuVentas(){
    rlutil::setConsoleTitle("VENTAS");
    int op;
    while(true){
    mostrarMenuVentas();
    op=rlutil::getkey();
    system("cls");

        switch(op){
    case 49: //si se apreta 1
            if(cargarVentas()){
                system("cls");
                std::cout<<"VENTA EXITOSA"<<std::endl;
            }else{
                std::cout<<"VENTA CANCELADA"<<std::endl;
            }
            break;
    case 50://si se apreta 2
            listarVentas();
            break;
    case 51://si se apreta 3
            if(eliminarVenta()){
                std::cout<<"VENTA ELIMINADA"<<std::endl;
            }else{
                std::cout<<"NO SE ELIMINO VENTAS"<<std::endl;
            }
        	break;

    case 48://si se apreta 0
        return;
    default: std::cout<<"OPCIÓN INVALIDA. "<<std::endl;
            break;
        case 52:
            if(modificarFecha()){
                std::cout<<"FECHA MODIFICADA"<<std::endl;
            }else{
                std::cout<<"NO SE MODIFICÓ FECHA"<<std::endl;
            }
            break;
        case 53:
            if(devolucion()){
                std::cout<<"DEVOLUCIÓN EXITOSA"<<std::endl;
            }else{
                std::cout<<"NO PUDO CARGARSE DEVOLUCION"<<std::endl;
            }
            break;
        case 0:
            return;
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
    int op;
    std::cout<<"DNI: ";
    std::cin>>dni;
    encontro = archiCLiente.leerDni(dni);
    if(encontro > -1){
        rCliente = archiCLiente.leer(encontro);
        if(!rCliente.getEstado()){
            std::cout<<"DNI CORRESPONDE A CLIENTE DADO DE BAJA"<<std::endl;
            std::cout<<"DESEA DARLO DE ALTA?"<<std::endl<<std::endl;
            std::cout<<"Y: AGREGAR   Q: CANCELAR"<<std::endl;
            op = rlutil::getkey();
            system("cls");
            if(op==89 || op == 121){
                rCliente.setEstado(true);
                archiCLiente.modificarRegistro(encontro,rCliente);
            }else{
                return false;
            }
        }
    }else{
        std::cout<<"CLIENTE NO EXISTE"<<std::endl;
        std::cout<<"¿DESEA AGREGARLO?"<<std::endl<<std::endl;
        std::cout<<"Y: AGREGAR   Q: CANCELAR"<<std::endl;
        op = rlutil::getkey();
        system("cls");
        if(op==89 || op == 121){
            if(agregarCliente(dni)){
                 std::cout<<"CLIENTE AGREGADO"<<std::endl;
                 rCliente = archiCLiente.leer(archiCLiente.leerDni(dni));
                 system("pause");
                 system("cls");
            }else{
                std::cout<<"ERROR AL CARGAR CLIENTE"<<std::endl;
                return false;
            }
        }else {
			return false;
        }

    }
    op = 66;
    while(true){
            switch(op){
            case 65:case 97:///CASO A PARA AGREGA PRODUCTO A LA VENTA
                if(bandera){
                  std::cout<<"MODELO: ";
                  cargarCadena(mod,30);
                  pos = archiCelular.buscarCelular(mod);
                  if(pos != -1){//verifica que el modelo exista en el archivo
                    rCelular = archiCelular.Leer(pos);//lee el registro en la posicion.
                    if(rCelular.getDisponibilidad() && rCelular.getEstado()){
						///
						descontarStock(rCelular);
						///
                        total += rCelular.getPrecio();//sumamos el precio del producto en el acumulador.
                        v.agregar(rCelular);//agregamos el registro al vector dinamico.
                        bandera = false;
                    }else{
                        std::cout<<"PRODUCTO SIN STOCK O NO DISPONIBLE"<<std::endl;
                        system("pause");
                    }
                  }else{
                    std::cout<<"MODELO INCORRECTO"<<std::endl;
                    system("pause");
                  }
                }else{
                    std::cout<<"MODELO: ";
                    cargarCadena(mod,30);
                    int pos = archiCelular.buscarCelular(mod);
                    if(pos != -1){
                      rCelular = archiCelular.Leer(pos);
                      if(rCelular.getDisponibilidad()&& rCelular.getEstado()){
						///
						descontarStock(rCelular);
						///
                        total += rCelular.getPrecio();
                        tam++;//incrementamos la variable que contiene la cantidad de registros.
                        v.aumentar(tam);//incrementamos el vector dinamico
                        v.agregar(rCelular);//agregamos el nuevo registro(la funcion siempre va a carga en la ultima posicion disponible)
                      }else{
                        std::cout<<"PRODUCTO SIN STOCK O NO DISPONIBLE"<<std::endl;
                        system("pause");
                      }
                    }else{
                    std::cout<<"MODELO INCORRECTO"<<std::endl;
                    system("pause");
                    }
            }
                break;
            case 89: case 121:
                if(!bandera){
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
                }else{
                    std::cout<<"NO SE AGREGO NINGUN PRODUCTO"<<std::endl;
                    system("pause");
                }
                break;
            case 69: case 101:
                std::cout<<"MODELO: ";
                cargarCadena(mod,30);
                pos = archiCelular.buscarCelular(mod);
                if(pos >= 0){
                rCelular = archiCelular.Leer(pos);
                    if(v.eliminar(mod)){//La funcion eliminar busca dentro del vector dinamico el modelo pasado como parametro, si lo encuentra lo elimina y modifica su tamaño, si no no hace nada.
                        aumentarStock(rCelular);
                        total -= rCelular.getPrecio();//descuenta el precio del registro eliminado.
                        tam--;
                        if (tam==0){
							bandera=true;
                        }
                    }else{
                        std::cout<<"MODELO INCORRECTO"<<std::endl;
                        system("pause");
                    }
                }else{
                    std::cout<<"MODELO INCORRECTO"<<std::endl;
                    system("pause");
                }
                break;
            case 81: case 113:
                /// liberar stock al cancelar venta
                v.reponerStock();
                ///
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
        op = rlutil::getkey();
        system("cls");
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
        ///descontarStock(rCelular);
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
void aumentarStock(clsCelular &r){
    ArchivosCelular archiCelular("celulares.dat");
    int pos = archiCelular.buscarCelular(r.getModelo());
    r.setStock(r.getStock()+1);
    r.setDisponibilidad(true);
	archiCelular.modificar_registro(pos,r);
}
void poner_disponibilidad(clsCelular &r){
	ArchivosCelular archiCelular("celulares.dat");
    int pos = archiCelular.buscarCelular(r.getModelo());
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
    ArchivosCelular aCel ("celulares.dat");
    int cod;
    int tam = aVentas.contarRegistros();
    std::cout<<"INGRESE CODIGO DE VENTA: ";
    std::cin>>cod;
    if(cod <= tam){
        rVentas = aVentas.Leer(cod-1);
        if(rVentas.getEstado()){
            rVentas.Mostrar();
            std::cout<<std::endl;
            std::cout<<"¿DESEA ELIMINAR ESTA VENTA?"<<std::endl;
            std::cout<<"Y: CONFIRMAR  CUALQUIE TECLA: CANCELAR"<<std::endl;
            int op = rlutil::getkey();
            if (op == 89 || op == 121){
				clsCelular reg_c;
				ArchivoCelularVendido aCelularVendido("vendidos.dat");
				int con = aCelularVendido.contarRegistros();
				for (int i=0;i<con;i++){
					celularVendido reg=aCelularVendido.Leer(i);
					if (reg.getEstado() == true && reg.getCodVenta() == cod){
						int pos_c = aCel.buscarCelular(reg.getModelo());
						reg_c = aCel.Leer(pos_c);
						poner_disponibilidad(reg_c);
					}
				}
                rVentas.setEstado(false);
                if(aVentas.Modificar(cod-1,rVentas)) return true;
                return false;
            }
            return false;
            }else{
                std::cout<<"EL CÓDIGO PERTENECE A UN REGISTRO DADO DE BAJA"<<std::endl;
                return false;
            }
        }
    std::cout<<"CÓDIGO VENTA INCORRECTO"<<std::endl;
    return false;
    system("cls");
}
bool modificarFecha(){
    Fecha hoy, nueva;
    ArchivosVentas aVentas("ventas.dat");
    clsVentas rVentas;
    int tam = aVentas.contarRegistros();
    int cod;
    std::cout<<"INGRESE CODIGO DE VENTA: ";
    std::cin>>cod;
    if(cod <= tam && cod > 0){
        rVentas = aVentas.Leer(cod-1);
        if(rVentas.getEstado()){
            rVentas.Mostrar();
            std::cout<<std::endl;
            std::cout<<"DESEA MODIFICAR FECHA?"<<std::endl;
            std::cout<<"Y: CONFIRMAR  CUALQUIE TECLA: CANCELAR"<<std::endl;
            int op = rlutil::getkey();
            if (op == 89 || op == 121){
                std::cout<<"INGRESE FECHA NUEVA: "<<std::endl;
                ///
				while(!nueva.Cargar()){
					std::cout<<"FECHA INCORRECTA"<<std::endl;
					std::cout<<"VUELVA A INGRESAR"<<std::endl;
				}
				while(nueva > hoy){
					std::cout<<"FECHA INCORRECTA"<<std::endl;
					std::cout<<"VUELVA A INGRESAR"<<std::endl;
					nueva.Cargar();
				}
                ///
                rVentas.setFecha(nueva);
                if(aVentas.Modificar(cod-1,rVentas)) return true;
                return false;
            }
        }else{
            std::cout<<"EL CODIGO PERTENECE A UN REGISTRO DADO DE BAJA"<<std::endl;
            return false;
        }
    }
    std::cout<<"CODIGO VENTA INCORRECTO"<<std::endl;
    return false;
}
bool devolucion(){
    ArchivosVentas aVentas("ventas.dat");
    ArchivosCelular aCel ("celulares.dat");
    clsVentas rVentas;
    char mod[30];
    int pos_c;
    int cant_v;
    int tam = aVentas.contarRegistros();
    int cod;
    std::cout<<"INGRESE CODIGO DE VENTA ";
    std::cin>>cod;
    if(cod > 0 && cod <= tam){
        rVentas = aVentas.Leer(cod-1);
        if(rVentas.getEstado()){
            if(rVentas.getCantidad()==1){
                rVentas.Mostrar();
                std::cout<<std::endl;
                std::cout<<"¿DESEA ELIMINAR ESTA VENTA?"<<std::endl;
                std::cout<<"Y: CONFIRMAR  CUALQUIE TECLA: CANCELAR"<<std::endl;
                int op = rlutil::getkey();
                if (op == 89 || op == 121){
					///
					clsCelular reg_c;
					ArchivoCelularVendido aCelularVendido("vendidos.dat");
					int con = aCelularVendido.contarRegistros();
					for (int i=0;i<con;i++){
						celularVendido reg=aCelularVendido.Leer(i);
						if (reg.getEstado() == true && reg.getCodVenta() == cod){
							int pos_c = aCel.buscarCelular(reg.getModelo());
							reg_c = aCel.Leer(pos_c);
							aumentarStock(reg_c);
							break;
						}
					}
					///
                    rVentas.setEstado(false);
                    aVentas.Modificar(cod-1,rVentas);
                    return true;
				} else{
                    return false;
                }
            }else{
                rVentas.Mostrar();
                std::cout<<std::endl;
                std::cout<<"INGRESE MODELO A ELIMINAR ";
                cargarCadena(mod,30);
                ArchivoCelularVendido aCelularVendido("vendidos.dat");
                int pos;
                celularVendido rCelularVendido;
                rCelularVendido = aCelularVendido.LeerIndividual(cod,mod,pos);
                ///
                clsCelular reg_c;
                pos_c = aCel.buscarCelular(rCelularVendido.getModelo());
                reg_c = aCel.Leer(pos_c);
                aumentarStock(reg_c);
				///
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
            std::cout<<"EL CODIGO PERTENECE A UN REGISTRO DADO DE BAJA"<<std::endl;
            return false;
        }
    }else{
        std::cout<<"CODIGO INCORRECTO"<<std::endl;
    }
    return false;
}
void mostrarMenuVentas(){
    std::cout<<"MENÚ VENTAS"<<std::endl;
    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"1. VENTA NUEVA"<<std::endl;
    std::cout<<"2. LISTAR VENTAS"<<std::endl;
    std::cout<<"3. ELIMINAR VENTA"<<std::endl;
    std::cout<<"4. MODIFICAR FECHA VENTAS"<<std::endl;
    std::cout<<"5. DEVOLVER TELEFONO"<<std::endl;
    std::cout<<"0. VOLVER"<<std::endl;
    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"INGRESE UNA OPCIÓN:"<<std::endl;
}
