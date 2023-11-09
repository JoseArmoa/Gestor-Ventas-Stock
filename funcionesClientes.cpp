#include <iostream>

using namespace std;
#include "clsCliente.h"



bool agregarCliente(int dni = -1){

    clsCliente r;
    ArchivoCliente archiCliente("clientes.dat");

    if(dni == -1){
        int dni=0;
        cout<<"DNI: ";
        cin>>dni;

        int encontro=archiCliente.leerDni(dni);

        if(encontro >=0){
        cout<<"EL CLIENTE YA EXISTE EN EL SISTEMA. "<<endl;
        return false;
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
	r.setEstado(false);
	return archi.modificarRegistro(pos,r);
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

    cout<<"NOMBRE COMPLETO: "<<reg.getNombre()<<" "<<reg.getApellido()<<endl;
    cout<<"EL TELEFONO ACTUAL ES: "<<reg.getTelefono()<<endl;
    cout<<"-----------------"<<endl;
    cout<<"DESEA CAMBIAR EL TELEFONO?..."<<endl;
    cout<<"Y. ACEPTAR                          Q. VOLVER"<<endl;
    char c;
    cin>>c;
    if(c=='y' || c=='Y'){

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
    else if(c=='q' || c=='Q'){
        return;
    }
    else{
        cout<<"OPCION NO VALIDA. "<<endl;
    }
}
void menuClientes(){
	int op;
    while(true){
        cout << "MENU CLIENTE:" << endl;
        cout << "-------------------------------"<<endl;
		cout << "1. AGREGAR CLIENTE" << endl;
		cout << "2. LISTAR CLIENTE" << endl;
		cout << "3. BAJAR CLIENTE" << endl;
		cout << "4. MODIFICAR TELEFONO CLIENTE" << endl;
		cout << "0. VOLVER" << endl;
		cout << "-------------------------------"<<endl;
		cout << "ELIJA UNA OPCIóN: ";
		cin>>op;
		system("cls");
        switch(op){
        case 1:
            if(agregarCliente()){
                cout<<"CLIENTE CARGADO"<<endl;
            }else{
                cout<<"ERROR AL CARGAR CLIENTE"<<endl;
            }
            break;
        case 2:
        	listarClientes();
            break;
		case 3:
			if(bajaCliente()){
                cout<<"BAJA EXITOSA"<<endl;
			}else{
                cout<<"ERROR AL DAE BAJA"<<endl;
			}
			break;
		case 4:
            Modificar_cliente();
            break;
        case 0:
            return;
        default: cout<<"OPCION INVALIDA. "<<endl;
            break;
        }
        system("pause");
        system("cls");
    }
}
