#include <iostream>
#include <cstdlib>
using namespace std;
#include "funcionesCelulares.h"
#include "clsCelular.h"

void MenuCelulares(){
	int op;
    while(true){
		system("cls");
        cout << "Menú de Celulares:" << endl;
		cout << "1. Agregar Celular" << endl;
		cout << "2. Reponer Stock" << endl;
		cout << "3. Modificar Precio" << endl;
		cout << "4. Baja de Celular" << endl;
		cout << "0. Salir del Menú de Celulares" << endl;
		cout << "Elija una opción: ";
		system("cls");
		cin>>op;
        switch(op){
        case 1:
            Agregar_celular();
        case 2:
            Reponer_Stock();
            break;
		case 3:
			Modificar_precio();
			break;
		case 4:
			Baja_celular();
        case 0:
            return;
        default:
            break;
        }
        system("pause");
    }
}
void Agregar_celular(){
	ArchivosCelular archi("Celulares.dat");
	clsCelular reg;
	reg.cargar();
	if(archi.Cargar(reg)){
		cout<<"El archivo fue guardado con exito."<<endl;
	} else {
		cout<<"Error, el archivo no fue guardado."<<endl;
	}
	system("pause");
}
void Reponer_Stock(){
	ArchivosCelular archi("Celulares.dat");
	char modelo[30], nombre[30];
	cout << "Ingrese el modelo (hasta 30 caracteres): ";
	cin.ignore();
	cin.getline(modelo, 30);
	cout << "Ingrese el nombre (hasta 30 caracteres): ";
	cin.getline(nombre, 30);
	int pos;
	clsCelular reg;
	if (archi.buscarCelular(modelo, nombre, pos, reg)) {
		cout << "El celular no existe" << endl;
		return;
	}
	int stock_nuevo;
	cout<<"Ingrese el nuevo stock a reponer: ";
	cin>>stock_nuevo;
	stock_nuevo+=reg.getStock();
	reg.setStock(stock_nuevo);
	if(archi.modificar_registro(pos,reg)){
		cout<<"El archivo fue modificado con exito"<<endl;
	} else{
		cout<<"Error, El archivo no pudo ser modificado con exito"<<endl;
	}
	system("pause");
}
void Modificar_precio(){
	ArchivosCelular archi("Celulares.dat");
	char modelo[30], nombre[30];
	cout << "Ingrese el modelo (hasta 30 caracteres): ";
	cin.ignore();
	cin.getline(modelo, 30);
	cout << "Ingrese el nombre (hasta 30 caracteres): ";
	cin.getline(nombre, 30);
	int pos;
	clsCelular reg;
	if (archi.buscarCelular(modelo, nombre, pos, reg)) {
		cout << "El celular no existe" << endl;
		return;
	}
	float _precio;
	cout<<"Ingrese el nuevo precio: "<<endl;
	cin>>_precio;
	reg.setPrecio(_precio);
	if(archi.modificar_registro(pos,reg)){
		cout<<"El archivo fue modificado con exito"<<endl;
	} else{
		cout<<"Error, El archivo no pudo ser modificado con exito"<<endl;
	}
	system("pause");
}
void Baja_celular(){
	ArchivosCelular archi("Celulares.dat");
	char modelo[30], nombre[30];
	cout << "Ingrese el modelo (hasta 30 caracteres): ";
	cin.ignore();
	cin.getline(modelo, 30);
	cout << "Ingrese el nombre (hasta 30 caracteres): ";
	cin.getline(nombre, 30);
	int pos;
	clsCelular reg;
	if (archi.buscarCelular(modelo, nombre, pos, reg)) {
		cout << "El celular no existe" << endl;
		return;
	}
	reg.setEstado(false);
	if(archi.modificar_registro(pos,reg)){
		cout<<"El archivo fue modificado con exito"<<endl;
	} else{
		cout<<"Error, El archivo no pudo ser modificado con exito"<<endl;
	}
	system("pause");
}
