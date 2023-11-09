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
void menuClientes(){
	int op;
    while(true){
        cout << "MENU CLIENTE:" << endl;
        cout << "-------------------------------"<<endl;
		cout << "1. AGREGAR CLIENTE" << endl;
		cout << "2. LISTAR CLIENTE" << endl;
		cout << "3. BAJAR CLIENTE" << endl;
		cout << "0. VOLVER" << endl;
		cout << "-------------------------------"<<endl;
		cout << "Elija una opción: ";
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
        case 0:
            return;
        default:
            break;
        }
        system("pause");
        system("cls");
    }
}
