#include <iostream>
#include <cstdlib>
using namespace std;
#include "funcionesCelulares.h"
#include "clsCelular.h"

void MenuCelulares(){
	int op;
    while(true){
        cout << "Men� de Celulares:" << endl;
        cout << "-------------------------------"<<endl;
		cout << "1. Agregar Celular" << endl;
		cout << "2. Reponer Stock" << endl;
		cout << "3. Modificar Precio" << endl;
		cout << "4. Baja de Celular" << endl;
		cout << "5. Listar" << endl;
		cout << "0. Salir del Men� de Celulares" << endl;
		cout << "-------------------------------"<<endl;
		cout << "Elija una opci�n: ";
		cin>>op;
		system("cls");
        switch(op){
        case 1:
            if(Agregar_celular()){
                cout<<"CELULAR CARGADO"<<endl;
            }else{
                cout<<"ERROR AL CARGAR CELULAR"<<endl;
            }
            break;
        case 2:
            Reponer_Stock();
            break;
		case 3:
			Modificar_precio();
			break;
		case 4:
			Baja_celular();
			break;
        case 5:
            Listar_celular();
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
bool Agregar_celular(){
	ArchivosCelular archi("Celulares.dat");
	clsCelular reg;
	char mod[30];
	cout<<"MODELO: ";
	cin.ignore();
	cin.getline(mod,30);
	if(archi.buscarCelular(mod) < 0 ){
        reg.cargar(mod);
        archi.Cargar(reg);
        return true;
	}else{
        cout<<"EL MODELO YA EXISTE"<<endl;
        return false;
	}
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
	if (archi.buscarCelular(modelo)) {
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
	if (archi.buscarCelular(modelo)) {
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
	if (archi.buscarCelular(modelo)) {
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
void Listar_celular(){
    clsCelular r;
    ArchivosCelular archi("Celulares.dat");
    int tam = archi.contarRegistros();
    for(int i=0;i<tam;i++){
        r = archi.Leer(i);
        r.mostrar();
        cout<<endl;
    }
}
