#include <iostream>
#include <cstdlib>
using namespace std;
#include "funcionesMarca.h"

void menuMarca(){
	int op;
    while(true){
        system("cls");
        cout << "MENU MARCA:" << endl;
        cout << "-------------------------------"<<endl;
		cout << "1. AGREGAR MARCAS" << endl;
		cout << "2. LISTAR MARCAS" << endl;
		cout << "3. MODIFICAR MARCA" << endl;
		cout << "4. DAR BAJA MARCA" << endl;
		cout << "5. DAR ALTA MARCA" << endl;
		cout << "0. VOLVER" << endl;
		cout << "-------------------------------"<<endl;
		cout << "ELIJA UNA OPCION: ";
		cin>> op;
		system("cls");
		switch(op){
			case 1:
				Agregar_marca();
				break;
			case 2:
				Listar_marca();
				break;
			case 3:

				break;
			case 4:
				bajar_marca();
				break;
			case 5:
				Alta_marca();
				break;
			case 0:
				return;
			default:
				break;
		}

	}
}


void Agregar_marca() {
    ArchivoMarca Archi("marcas.dat");
    char marca[30];
    cout << "INGRESE LA MARCA QUE QUIERE AGREGAR: ";
    cin.ignore();
    cin.getline(marca, 30);
    int pos = Archi.buscarMarca(marca);
    if (pos >= 0) {
        cout << "MARCA REPETIDA, SE CANCELARÁ LA OPERACIÓN" << endl;
        return;
    }
    clsMarca reg(marca);
    if (Archi.Cargar(reg)) {
        cout << "MARCA CARGADA CON ÉXITO" << endl;
    } else {
        cout << "ERROR AL CARGAR LA MARCA" << endl;
    }
}
void Listar_marca(){
	ArchivoMarca Archi("marcas.dat");
	int tam=Archi.contarRegistros();
	for (int i=0;i<tam;i++){
		clsMarca reg=Archi.Leer(i);
		reg.mostrar();
		cout<<"\n";

	}
	return;
}
void Modificar_marca(){
	ArchivoMarca archi("marcas.dat");
    char marca[30];
    cout << "INGRESE LA MARCA (HASTA 30 CARACTERES): ";
	cin.ignore();
	cin.getline(marca, 30);
	int pos=archi.buscarMarca(marca);
	if (pos < 0) {
		cout << "LA MARCA NO EXISTE" << endl;
		return;
	}
	clsMarca reg=archi.Leer(pos);
	char marca_[30];
	cout<< "INGRESE EL NUEVO NOMBRE DE LA MARCA (HASTA 30 CARACTERES): "<<endl;
	cin.getline(marca_, 30);
	reg.setMarca(marca_);
	if (archi.modificar_registro(pos,reg)){
		cout<<"EL ARCHIVO FUE MODIFICADO CON EXITO"<<endl;
	} else {
		cout<<"ERROR, EL ARCHIVO NO PUDO SER MODIFICADO CON EXITO"<<endl;
	}
}
void bajar_marca(){
	ArchivoMarca archi("marcas.dat");
    char marca[30];
    cout << "INGRESE LA MARCA (HASTA 30 CARACTERES): ";
	cin.ignore();
	cin.getline(marca, 30);
	int pos=archi.buscarMarca(marca);
	if (pos < 0) {
		cout << "LA MARCA NO EXISTE" << endl;
		return;
	}
	clsMarca reg=archi.Leer(pos);
	if (reg.getEstado()==false){
		cout << "LA MARCA YA ESTA DADA BAJA"<<endl;
		return;
	}
	reg.setEstado(false);
	if (archi.modificar_registro(pos,reg)){
		cout<<"EL ARCHIVO FUE MODIFICADO CON EXITO"<<endl;
	} else {
		cout<<"ERROR, EL ARCHIVO NO PUDO SER MODIFICADO CON EXITO"<<endl;
	}
}
void Alta_marca(){
	ArchivoMarca archi("marcas.dat");
    char marca[30];
    cout << "INGRESE LA MARCA (HASTA 30 CARACTERES): ";
	cin.ignore();
	cin.getline(marca, 30);
	int pos=archi.buscarMarca(marca);
	if (pos < 0) {
		cout << "LA MARCA NO EXISTE" << endl;
		return;
	}
	clsMarca reg=archi.Leer(pos);
	if (reg.getEstado()==true){
		cout << "LA MARCA YA ESTA DADA ALTA"<<endl;
		return;
	}
	reg.setEstado(true);
	if (archi.modificar_registro(pos,reg)){
		cout<<"EL ARCHIVO FUE MODIFICADO CON EXITO"<<endl;
	} else {
		cout<<"ERROR, EL ARCHIVO NO PUDO SER MODIFICADO CON EXITO"<<endl;
	}
}
