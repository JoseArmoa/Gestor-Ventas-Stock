#include <iostream>

using namespace std;
#include "clsCliente.h"



bool agregarCliente(){

    clsCliente r;
    ArchivoCliente archiCliente("clientes.dat");

    int dni=0;
    cout<<"DNI: "<<endl;
    cin>>dni;

    int encontro=archiCliente.leerDni(dni);

    if(encontro >=0){
        cout<<"EL CLIENTE YA EXISTE EN EL SISTEMA. "<<endl;
        return false;
    }
    else{
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
void bajaCliente(){
	ArchivoCliente archi ("clientes.dat");
	int dni;
	bool estado=false;
	cout << "Introduzca el numero de documento: ";
	cin >> dni;
	int cant=archi.contarRegistros();
	for(int i=0;i<cant;i++){
		clsCliente reg=archi.leer(i);
		if (reg.getDNI()==dni){
			reg.setEstado(false);
			estado=archi.modificarRegistro(i,reg);
		}
	}
	if (estado){
		cout << "La baja fue exitosa"<<endl;
	} else {
		cout << "Error, la baja no se pudo hacer"<<endl;
	}
}
void menuClientes(){
	int op;
    while(true){
        cout << "Menú de Celulares:" << endl;
        cout << "-------------------------------"<<endl;
		cout << "1. Agregar Cliente" << endl;
		cout << "2. Listar Cliente" << endl;
		cout << "3. Bajar cliente" << endl;
		cout << "0. Salir del Menú Clientes" << endl;
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
			bajaCliente();
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
