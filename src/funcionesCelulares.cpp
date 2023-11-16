#include <iostream>
#include <cstdlib>
using namespace std;
#include "funcionesCelulares.h"
#include "clsCelular.h"
#include "rlutil.h"


void menuStocCelulares(){
	rlutil::setConsoleTitle("CELULARES");
	int op;
    while(true){
        system("cls");
        cout << "MENU STOCK CELULARES:" << endl;
        cout << "-------------------------------"<<endl;
		cout << "1. MENU CELULAR" << endl;
		cout << "2. MENU MARCA" << endl;
		cout << "0. VOLVER" << endl;
		cout << "-------------------------------"<<endl;
		cout << "ELIJA UNA OPCION: ";
		op = rlutil::getkey();
		system("cls");
		switch(op){
			case 49:
				MenuCelulares();
				break;
			case 50:
				menuMarca();
				break;
			case 48:
				return;
			default:
			    cout<<"OPCION INVALIDA"<<endl;
				break;
		}

	}
}

void MenuCelulares(){
	int op;
    while(true){
        cout << "MENU CELULARES:" << endl;
        cout << "-------------------------------"<<endl;
		cout << "1. AGREGAR CELULAR" << endl;
		cout << "2. LISTAR CELULARES" << endl;
		cout << "3. REPONER STOCK" << endl;
		cout << "4. MODIFICAR PRECIO" << endl;
		cout << "5. BAJA CELULAR" << endl;
		cout << "6. ALTA CELULAR" << endl;
		cout << "0. VOLVER" << endl;
		cout << "-------------------------------"<<endl;
		cout << "ELIJA UNA OPCION: ";
		op=rlutil::getkey();
		system("cls");
        switch(op){
    case 49: //si se apreta 1
            if(Agregar_celular()){
                cout<<"CELULAR CARGADO"<<endl;
            }else{
                cout<<"ERROR AL CARGAR CELULAR"<<endl;
            }
            break;
    case 50://si se apreta 2
            Listar_celular();
            break;
    case 51://si se apreta 3
			Reponer_Stock();
        	break;
    case 52://si se apreta 4
			Modificar_precio();
        	break;
    case 53://si se apreta 5
			Baja_celular();
			break;
    case 54://6
			Alta_celular();
            break;
    case 55://7

            break;
    case 56: //8

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
bool Agregar_celular() {
    ArchivosCelular archi("celulares.dat");
    ArchivoMarca archi_marca("marcas.dat");
    clsCelular reg;
    char mod[30], marca[30];
    cout << "MODELO: ";
    cargarCadena(mod,30);
    int pos = archi.buscarCelular(mod);
    if (pos >= 0) {
        reg = archi.Leer(pos);
        if (reg.getEstado()) {
            cout << "MODELO EXISTENTE" << endl;
            return false;
        } else {
            cout << "MODELO CORRESPONDE A REGISTRO DADO DE BAJA" << endl;
            cout << "PRESIONE Y PARA VOLVER A DAR DE ALTA O CUALQUIER OTRA TECLA PARA CANCELAR" << endl;
            int op = rlutil::getkey();
            if (op == 89 || op == 121) {
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
        cout << "�QUIERE ESTA MARCA EN EL ARCHIVO MARCA 'marcas.dat'?" << endl;
        cout << "PRESIONE A PARA AGREGAR O CUALQUIER OTRA TECLA PARA CANCELAR" << endl;
        int op = rlutil::getkey();
        if (op == 65|| op == 97) {
            clsMarca mar(marca);
            if (archi_marca.Cargar(mar)) {
                cout << "MARCA CARGADA" << endl;
            } else {
                cout << "ERROR AL CARGAR LA MARCA" << endl;
                return false;
            }
        } else {
            cout << "CARGAR CELULAR CANCELADO" << endl;
            return false;
        }
    }
    reg.cargar(mod, marca);
    archi.Cargar(reg);
    return true;
}

void Reponer_Stock(){
	ArchivosCelular archi("celulares.dat");
	char modelo[30];
	cout << "INGRESE EL MODELO (HASTA 30 CARACTERES): ";
	cargarCadena(modelo,30);
	int pos;
	clsCelular reg;
	pos = archi.buscarCelular(modelo);
	if (pos < 0) {
		cout << "EL CELULAR NO EXISTE" << endl;
		return;
	}
	reg = archi.Leer(pos);
	int stock_nuevo;
	cout<<"INGRESE EL NUEVO STOCK A REPONER: ";
	cin>>stock_nuevo;
	stock_nuevo+=reg.getStock();
	reg.setStock(stock_nuevo);
	if(archi.modificar_registro(pos,reg)){
		cout<<"EL ARCHIVO FUE MODIFICADO CON EXITO"<<endl;
	} else{
		cout<<"ERROR, EL ARCHIVO NO PUDO SER MODIFICADO CON EXITO"<<endl;
	}
}
void Modificar_precio(){
	ArchivosCelular archi("celulares.dat");
	char modelo[30];
	cout << "INGRESE EL MODELO (HASTA 30 CARACTERES): ";
	cargarCadena(modelo,30);
	int pos = archi.buscarCelular(modelo);
	clsCelular reg;
	if (pos < 0) {
		cout << "EL CELULAR NO EXISTE" << endl;
		return;
	}
	reg = archi.Leer(pos);
	float _precio;
	cout<<"INGRESE EL NUEVO PRECIO: "<<endl;
	cin>>_precio;
	reg.setPrecio(_precio);
	if(archi.modificar_registro(pos,reg)){
		cout<<"EL ARCHIVO FUE MODIFICADO CON EXITO"<<endl;
	} else{
		cout<<"ERROR, EL ARCHIVO NO PUDO SER MODIFICADO CON EXITO"<<endl;
	}
}
void Baja_celular(){
	ArchivosCelular archi("celulares.dat");
	char modelo[30];
	cout << "INGRESE EL MODELO (HASTA 30 CARACTERES): ";
	cargarCadena(modelo,30);
	int pos=archi.buscarCelular(modelo);
	clsCelular reg;
	if (pos < 0) {
		cout << "EL CELULAR NO EXISTE" << endl;
		return;
	}
	reg = archi.Leer(pos);
	if (!reg.getEstado()){
		cout << "EL CELULAR YA ESTA DADO BAJA"<<endl;
		return;
	}
	reg.setEstado(false);
	if(archi.modificar_registro(pos,reg)){
		cout<<"EL ARCHIVO FUE MODIFICADO CON EXITO"<<endl;
	} else{
		cout<<"ERROR, EL ARCHIVO NO PUDO SER MODIFICADO CON EXITO"<<endl;
	}
}
void Listar_celular(){
    clsCelular r;
    ArchivosCelular archi("celulares.dat");
    int tam = archi.contarRegistros();
    cout << left;
    cout << setw(7)  << "MODELO";
    cout << setw(7) << "NOMBRE";
    cout << setw(18) << "         FECHA LANZ.";
    cout << setw(6)  << "  MARCA";
    cout << setw(7)  << "     PRECIO";
    cout << setw(6) << "    STOCK" << endl;
    cout<<"-------------------------------------------------------------"<<endl;

    for(int i=0;i<tam;i++){
        r = archi.Leer(i);
        r.mostrar();
    }
}
void Alta_celular(){
	ArchivosCelular archi("celulares.dat");
	char modelo[30];
	cout << "INGRESE EL MODELO (HASTA 30 CARACTERES): ";
	cargarCadena(modelo,30);
	int pos=archi.buscarCelular(modelo);
	clsCelular reg;
	if (pos < 0) {
		cout << "EL CELULAR NO EXISTE" << endl;
		return;
	}
	reg = archi.Leer(pos);
	if (reg.getEstado()==true){
		cout << "EL CELULAR YA ESTA DADO ALTA"<<endl;
		return;
	}
	reg.setEstado(true);
	if(archi.modificar_registro(pos,reg)){
		cout<<"EL ARCHIVO FUE MODIFICADO CON EXITO"<<endl;
	} else{
		cout<<"ERROR, EL ARCHIVO NO PUDO SER MODIFICADO CON EXITO"<<endl;
	}
}

