#include <iostream>
#include <cstdlib>
using namespace std;
#include "funcionesCelulares.h"
#include "clsCelular.h"

void MenuCelulares(){
	int op;
    while(true){
        cout << "MENU CELULARES:" << endl;
        cout << "-------------------------------"<<endl;
		cout << "1. AGREGAR CELULAR" << endl;
		cout << "2. REPONER STOCK" << endl;
		cout << "3. MODIFICAR PRECIO" << endl;
		cout << "4. Baja de Celular" << endl;
		cout << "5. LISTAR CELULARES" << endl;
		cout << "6. AEGREGAR MARCAS" << endl;
		cout << "7. LISTAR MARCAS" << endl;
		cout << "8. DAR BAJA MARCA" << endl;
		cout << "0. SALIR DEL MENU CELULARES" << endl;
		cout << "-------------------------------"<<endl;
		cout << "ELIJA UNA OPCION: ";
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
		case 6:
            Agregar_marca();
            break;
		case 7:
            Listar_marca();
            break;
		case 8:
            bajar_marca();
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
bool Agregar_celular() {
    ArchivosCelular archi("celulares.dat");
    ArchivoMarca archi_marca("marcas.dat");
    clsCelular reg;
    char mod[30], marca[30];
    cout << "MODELO: ";
    cin.ignore();
    cin.getline(mod, 30);

    int pos = archi.buscarCelular(mod);
    if (pos >= 0) {
        reg = archi.Leer(pos);
        if (reg.getEstado()) {
            cout << "MODELO EXISTENTE" << endl;
            return false;
        } else {
            cout << "MODELO CORRESPONDE A REGISTRO DADO DE BAJA" << endl;
            cout << "PRESIONE Y PARA VOLVER A DAR DE ALTA O CUALQUIER OTRA TECLA PARA CANCELAR" << endl;
            char op;
            cin >> op;
            if (op == 'y' || op == 'Y') {
                reg.setEstado(true);
                archi.modificar_registro(pos, reg);
                return true;
            } else {
                return false;
            }
        }
    }

    cout << "MARCA: ";
    cin.getline(marca, 30);
    int pos_m = archi_marca.buscarMarca(marca);
    if (pos_m < 0) {
        cout << "¿QUIERE ESTA MARCA EN EL ARCHIVO MARCA 'marcas.dat'?" << endl;
        cout << "PRESIONE A PARA AGREGAR O CUALQUIER OTRA TECLA PARA CANCELAR" << endl;
        char op;
        cin >> op;
        if (op == 'a' || op == 'A') {
            clsMarca mar(marca);
            if (archi_marca.Cargar(mar)) {
                cout << "Marca cargada" << endl;
            } else {
                cout << "Error al cargar la marca" << endl;
                return false;
            }
        } else {
            cout << "Cargar celular cancelado" << endl;
            return false;
        }
    }
    cin.ignore();
    reg.cargar(mod, marca);
    archi.Cargar(reg);
    return true;
}

void Reponer_Stock(){
	ArchivosCelular archi("celulares.dat");
	char modelo[30];
	cout << "Ingrese el modelo (hasta 30 caracteres): ";
	cin.ignore();
	cin.getline(modelo, 30);
	int pos;
	clsCelular reg;
	pos = archi.buscarCelular(modelo);
	if (pos < 0) {
		cout << "El celular no existe" << endl;
		return;
	}
	reg = archi.Leer(pos);
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
}
void Modificar_precio(){
	ArchivosCelular archi("celulares.dat");
	char modelo[30], nombre[30];
	cout << "Ingrese el modelo (hasta 30 caracteres): ";
	cin.ignore();
	cin.getline(modelo, 30);
	int pos = archi.buscarCelular(modelo);
	clsCelular reg;
	if (pos < 0) {
		cout << "El celular no existe" << endl;
		return;
	}
	reg = archi.Leer(pos);
	float _precio;
	cout<<"Ingrese el nuevo precio: "<<endl;
	cin>>_precio;
	reg.setPrecio(_precio);
	if(archi.modificar_registro(pos,reg)){
		cout<<"El archivo fue modificado con exito"<<endl;
	} else{
		cout<<"Error, El archivo no pudo ser modificado con exito"<<endl;
	}
}
void Baja_celular(){
	ArchivosCelular archi("celulares.dat");
	char modelo[30];
	cout << "Ingrese el modelo (hasta 30 caracteres): ";
	cin.ignore();
	cin.getline(modelo, 30);
	int pos=archi.buscarCelular(modelo);
	clsCelular reg;
	if (pos < 0) {
		cout << "El celular no existe" << endl;
		return;
	}
	reg = archi.Leer(pos);
	reg.setEstado(false);
	if(archi.modificar_registro(pos,reg)){
		cout<<"El archivo fue modificado con exito"<<endl;
	} else{
		cout<<"Error, El archivo no pudo ser modificado con exito"<<endl;
	}
}
void Listar_celular(){
    clsCelular r;
    ArchivosCelular archi("celulares.dat");
    int tam = archi.contarRegistros();
    for(int i=0;i<tam;i++){
        r = archi.Leer(i);
        r.mostrar();
        cout<<endl;
    }
}
void Agregar_marca() {
    ArchivoMarca Archi("marcas.dat");
    char marca[30];
    cout << "Ingrese la marca que quiere agregar: ";
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
void bajar_marca(){
	ArchivoMarca archi("marcas.dat");
    char marca[30];
    cout << "Ingrese la marca (hasta 30 caracteres): ";
	cin.ignore();
	cin.getline(marca, 30);
	int pos=archi.buscarMarca(marca);
	if (pos < 0) {
		cout << "La marca no existe" << endl;
		return;
	}
	clsMarca reg=archi.Leer(pos);
	reg.setEstado(false);
	if (archi.modificar_registro(pos,reg)){
		cout<<"El archivo fue modificado con exito"<<endl;
	} else {
		cout<<"Error, El archivo no pudo ser modificado con exito"<<endl;
	}
}
