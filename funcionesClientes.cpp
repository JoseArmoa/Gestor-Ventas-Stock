#include <iostream>

using namespace std;
#include "clsCliente.h"
#include "rlutil.h"



bool agregarCliente(int dni = -1){

    clsCliente r;
    ArchivoCliente archiCliente("clientes.dat");

    if(dni == -1){
        int dni=0;
        cout<<"DNI: ";
        cin>>dni;

        int encontro=archiCliente.leerDni(dni);
        if(encontro >=0){
            r = archiCliente.leer(encontro);
            if(r.getEstado()){
                cout<<"EL CLIENTE YA EXISTE EN EL SISTEMA. "<<endl;
                return false;
            }else{
                cout << "DNI CORRESPONDE A CLIENTE DADO DE BAJA" << endl;
                cout << "PRESIONE Y PARA VOLVER A DAR DE ALTA O CUALQUIER OTRA TECLA PARA CANCELAR" << endl;
                int op;
                op = rlutil::getkey();
                if (op == 89 || op == 121) {
                    r.setEstado(true);
                    archiCliente.modificarRegistro(encontro,r);
                    return true;
                } else {
                    return false;
                }
            }
        }else{
        r.Cargar(dni);
        archiCliente.Cargar(r);
        return true;
        }
    }else{
        r.Cargar(dni);
        archiCliente.Cargar(r);
        return true;
    }
}
void listarClientes(){
	ArchivoCliente archi("clientes.dat");
	int cant=archi.contarRegistros();
	for(int i=0;i<cant;i++){
		clsCliente reg=archi.leer(i);
		reg.Mostrar();
		cout << "\n";
	}
}


void Modificar_cliente(){
	ArchivoCliente archi("clientes.dat");
	int dni;
	cout << "INGRESE EL DNI DEL CLIENTE: ";
	cin>>dni;
	cout<<endl;
	int pos = archi.leerDni(dni);
	clsCliente reg;
	if (pos < 0) {
		cout << "EL CLIENTE NO EXISTE" << endl;
		return;
	}

	reg = archi.leer(pos);

	if(reg.getEstado()){
        cout<<"NOMBRE COMPLETO: "<<reg.getNombre()<<" "<<reg.getApellido()<<endl;
        cout<<"EL TELEFONO ACTUAL ES: "<<reg.getTelefono()<<endl;
        cout<<"-----------------"<<endl;
        cout<<"DESEA CAMBIAR EL TELEFONO?..."<<endl;
        cout<<"Y. ACEPTAR                          Q. VOLVER"<<endl;
        int c= rlutil::getkey();
        if(c==89 || c==121){

            char telefono[30];
            cout << "INGRESE EL TELEFONO NUEVO: ";
            cin.ignore();
            cin.getline(telefono, 30);
            cout<<endl;
            reg.setTelefono(telefono);
            if(archi.modificarRegistro(pos,reg)){
            cout<<"EL ARCHIVO FUE MODIFICADO CON EXITO"<<endl;
            } else{
            cout<<"ERROR, EL ARCHIVO NO PUDO SER MODIFICADO CON EXITO"<<endl;
            }
        }
        else if(c==81 || c==113){
            return;
        }
        else{
            cout<<"OPCION NO VALIDA. "<<endl;
        }
	}else{
        cout<<"DNI CORRESPONDE A CLIENTE DADO DE BAJA"<<endl;
	}
}


bool bajaCliente(){
	clsCliente r;
	ArchivoCliente archi ("clientes.dat");
	int dni;
	cout << "INTRODUZCA EL NUMERO DE DOCUMENTO: ";
	cin >> dni;
	int pos = archi.leerDni(dni);
	if(pos > -1){
        r = archi.leer(pos);
	}
	if(r.getEstado()){
        r.setEstado(false);
        return archi.modificarRegistro(pos,r);
	}else{
        cout<<"EL REGISTRO YA ESTA DADO DE BAJA";
	}
	return false;
}

bool altaCliente(){
	clsCliente r;
	ArchivoCliente archi ("clientes.dat");
	int dni;
	cout << "INTRODUZCA EL NUMERO DE DOCUMENTO: ";
	cin >> dni;
	int pos = archi.leerDni(dni);
	if(pos > -1){
        r = archi.leer(pos);
	}
	r.setEstado(true);
	return archi.modificarRegistro(pos,r);
}

void menuClientes(){
	rlutil::setConsoleTitle("CLIENTES");
	int op;
    while(true){
        cout << "MENU CLIENTE:" << endl;
        cout << "-------------------------------"<<endl;
		cout << "1. AGREGAR CLIENTE" << endl;
		cout << "2. LISTAR CLIENTE" << endl;
		cout << "3. BAJAR CLIENTE" << endl;
		cout << "4. MODIFICAR TELEFONO DE CLIENTE" << endl;
		cout << "0. VOLVER" << endl;
		cout << "-------------------------------"<<endl;
		cout << "ELIJA UNA OPCION: ";
		op=rlutil::getkey();
		system("cls");
        switch(op){
    case 49: //si se apreta 1
            if(agregarCliente()){
                cout<<"CLIENTE CARGADO"<<endl;
            }else{
                cout<<"ERROR AL CARGAR CLIENTE"<<endl;
            }
            break;
    case 50://si se apreta 2
            listarClientes();
            break;
    case 51://si se apreta 3
            if(bajaCliente()){
                cout<<"BAJA EXITOSA"<<endl;
			}else{
                cout<<"ERROR AL DAR BAJA"<<endl;
			}
        	break;
    case 52://si se apreta 4
            if(altaCliente()){
                cout<<"ALTA EXITOSA"<<endl;
			}else{
                cout<<"ERROR AL DAR ALTA"<<endl;
			}
        	break;
	case 53://si se apreta 5
            Modificar_cliente();
        	break;

    case 48://si se apreta 0
        return;
    default: std::cout<<"OPCION INVALIDA. "<<std::endl;
            break;

        }

        system("pause");
        system("cls");
    }
}
