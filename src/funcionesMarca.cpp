#include <iostream>
#include <cstdlib>
using namespace std;
#include "funcionesMarca.h"
#include "rlutil.h"

void menuMarca(){
	int op;
    while(true){
        system("cls");
        cout << "MENÚ MARCA:" << endl;
        cout << "-------------------------------"<<endl;
		cout << "1. AGREGAR MARCAS" << endl;
		cout << "2. LISTAR MARCAS" << endl;
		cout << "3. MODIFICAR MARCA" << endl;
		cout << "4. DAR BAJA MARCA" << endl;
		cout << "5. DAR ALTA MARCA" << endl;
		cout << "0. VOLVER" << endl;
		cout << "-------------------------------"<<endl;
		cout << "ELIJA UNA OPCIÓN: ";
		op =rlutil::getkey();
		system("cls");
		switch(op){
			case 49:
				Agregar_marca();
				break;
			case 50:
				Listar_marca();
				break;
			case 51:
                Modificar_marca();
				break;
			case 52:
				bajar_marca();
				break;
			case 53:
				Alta_marca();
				break;
			case 48:
				return;
			default:
			    cout<<"OPCIÓN INVALIDA"<<endl;
				break;
		}
		system("pause");
	}
}


void Agregar_marca() {
    ArchivoMarca Archi("marcas.dat");
    char marca[30];
    cout << "INGRESE LA MARCA QUE QUIERE AGREGAR: ";
    cargarCadena(marca,30);
    int pos = Archi.buscarMarca(marca);
    if (pos >= 0) {
        int po = Archi.buscarMarca(marca);
		clsMarca mar = Archi.Leer(po);
		if (mar.getEstado()==false){
			cout << "MARCA DADA DE BAJA"<<endl;
            cout << "PRESIONE 'Y' PARA VOLVER A DAR DE ALTA O CUALQUIER OTRA TECLA PARA CANCELAR" << endl;
            int op = rlutil::getkey();
            if (op == 89 || op == 121) {
                mar.setEstado(true);
                Archi.modificar_registro(pos, mar);
                clsCelular rCelular;
				ArchivosCelular archiCel("Celulares.dat");
				int cant=archiCel.contarRegistros();

				for(int i=0; i<cant; i++){
					rCelular = archiCel.Leer(i);
					if(strcmp(rCelular.getMarca(), marca)==0){
						rCelular.setEstado(false);
						archiCel.modificar_registro(i,rCelular);
					}
				}
				cout << "MARCA DADA DE ALTA" << endl;
				return;

            } else {
            	cout << "NO DIO DE ALTA LA MARCA" << endl;
                return ;
            }

			return;
		} else {
			cout << "MARCA REPETIDA, SE CANCELARA LA OPERACIÓN" << endl;
			return;
		}
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
	cout<<"NOMBRE MARCAS"<<endl;
    cout<<"-------------"<<endl;
	for (int i=0;i<tam;i++){
		clsMarca reg=Archi.Leer(i);
		reg.mostrar();
		cout<<"\n";

	}
}
void Modificar_marca(){
	ArchivoMarca archi("marcas.dat");
    char marca[30];
    cout << "INGRESE LA MARCA (HASTA 30 CARACTERES): ";
	cargarCadena(marca,30);
	int pos=archi.buscarMarca(marca);
	if (pos < 0) {
		cout << "LA MARCA NO EXISTE" << endl;
		return;
	}
	clsMarca reg=archi.Leer(pos);
	if (reg.getEstado()==false){
		cout << "LA MARCA ESTA DADA DE BAJA"<<endl;
		return;
	}

	cout << "PRESIONE 'Y' PARA MODIFICAR EL NOMBRE O CUALQUIER OTRA TECLA PARA CANCELAR" << endl;
	int op = rlutil::getkey();
	if (op == 89 || op == 121) {
		char marca_[30];
		cout<< "INGRESE EL NUEVO NOMBRE DE LA MARCA (HASTA 30 CARACTERES): "<<endl;
		cargarCadena(marca_,30);
		ArchivosCelular archiCel("Celulares.dat");

		int cant=archiCel.contarRegistros();

		for(int i=0; i<cant; i++){
			clsCelular rCelular = archiCel.Leer(i);
			if(strcmp(rCelular.getMarca(), marca)==0){
				rCelular.setMarca(marca_);
				archiCel.modificar_registro(i,rCelular);
			}
		}
		reg.setMarca(marca_);
		if (archi.modificar_registro(pos,reg)){
			cout<<"EL ARCHIVO FUE MODIFICADO CON ÉXITO"<<endl;
		} else {
			cout<<"ERROR, EL ARCHIVO NO PUDO SER MODIFICADO CON ÉXITO"<<endl;
		}
	} else {
		cout << "NO MODIFICO LA MARCA"<<endl;
		return;
	}
}

void bajar_marca(){
	ArchivoMarca archi("marcas.dat");
    char marca[30];
    cout << "INGRESE LA MARCA (HASTA 30 CARACTERES): ";
	cargarCadena(marca,30);
	int pos=archi.buscarMarca(marca);
	if (pos < 0) {
		cout << "LA MARCA NO ÉXISTE" << endl;
		return;
	}
	clsMarca reg=archi.Leer(pos);
	if (reg.getEstado()==false){
		cout << "LA MARCA YA ESTÁ DADA DE BAJA"<<endl;
		return;
	}
	cout << "PRESIONE 'Y' PARA DAR DE BAJA O CUALQUIER OTRA TECLA PARA CANCELAR" << endl;
	int op = rlutil::getkey();
	if (op == 89 || op == 121) {
		reg.setEstado(false);
		if (archi.modificar_registro(pos,reg)){
			cout<<"EL ARCHIVO FUE DADO DE BAJA CON ÉXITO"<<endl;
			clsCelular rCelular;
			ArchivosCelular archiCel("Celulares.dat");

			int cant=archiCel.contarRegistros();

			for(int i=0; i<cant; i++){
				rCelular = archiCel.Leer(i);
				if(strcmp(rCelular.getMarca(), marca)==0){
					rCelular.setEstado(false);
					archiCel.modificar_registro(i,rCelular);
				}
			}
		} else {
			cout<<"ERROR, EL ARCHIVO NO PUDO SER MODIFICADO CON ÉXITO"<<endl;
		}
	} else {
		cout << "NO DIO BAJA LA MARCA" << endl;
		return ;
	}
}
void Alta_marca(){
	ArchivoMarca archi("marcas.dat");
    char marca[30];
    cout << "INGRESE LA MARCA (HASTA 30 CARACTERES): ";
	cargarCadena(marca,30);
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
	///
	cout << "PRESIONE 'Y' PARA DAR DE ALTA O CUALQUIER OTRA TECLA PARA CANCELAR" << endl;
	int op = rlutil::getkey();
	if (op == 89 || op == 121) {
		reg.setEstado(true);
		if (archi.modificar_registro(pos,reg)){
			cout<<"EL ARCHIVO FUE DADO DE ALTA CON ÉXITO"<<endl;
			clsCelular rCelular;
			ArchivosCelular archiCel("Celulares.dat");

			int cant=archiCel.contarRegistros();

			for(int i=0; i<cant; i++){
				rCelular = archiCel.Leer(i);
				if(strcmp(rCelular.getMarca(), marca)==0){
					rCelular.setEstado(true);
					archiCel.modificar_registro(i,rCelular);
				}
			}
		} else {
			cout<<"ERROR, EL ARCHIVO NO PUDO SER MODIFICADO CON ÉXITO"<<endl;
		}
	} else {
		cout << "NO DIO ALTA A LA MARCA" << endl;
		return ;
	}
}
