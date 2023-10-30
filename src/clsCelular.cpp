#include <iostream>
#include <cstdlib>
using namespace std;
#include "clsCelular.h"



	void clsCelular::setModelo(char* cadena){
        strcpy(modelo, cadena);
    }

    void clsCelular::setNombre(char* cadena){
        strcpy(nombre, cadena);
    }

    void clsCelular::setMarca(int m){
        marca=m;
    }

    void clsCelular::setAnioLanzamiento(Fecha f){
        anioLanzamiento=f;
    }

    void clsCelular::setPrecio(float p){
        precio=p;
    }

    void clsCelular::setStock(int s){
        stock=s;
    }
    void clsCelular::setEstado(bool e){
		estado=e;
    }
	void clsCelular::cargar() {
		cout << "Ingrese el modelo (hasta 30 caracteres): ";
		cin.ignore(); // Limpia el buffer de entrada.
		cin.getline(modelo, 30);

		cout << "Ingrese el nombre (hasta 30 caracteres): ";
		cin.getline(nombre, 30);

		cout << "Ingrese la marca (un número entero): ";
		cin >> marca;

		int dia, mes, anio;
		cout << "Ingrese el día de lanzamiento: ";
		cin >> dia;

		cout << "Ingrese el mes de lanzamiento: ";
		cin >> mes;

		cout << "Ingrese el año de lanzamiento: ";
		cin >> anio;

		Fecha fechaLanzamiento(dia, mes, anio);
		anioLanzamiento = fechaLanzamiento;

		cout << "Ingrese el precio: ";
		cin >> precio;

		cout << "Ingrese la cantidad en stock: ";
		cin >> stock;

		estado = true;
	}
	void clsCelular::mostrar() {
		if (getEstado()){
			cout << "Modelo: " << modelo << endl;
			cout << "Nombre: " << nombre << endl;
			cout << "Marca: " << marca << endl;
			anioLanzamiento.Mostrar();
			cout << "Precio: " << precio << endl;
			cout << "Stock: " << stock << endl;
		}
	}

	bool ArchivosCelular::Cargar(clsCelular r){
		FILE* p;
		p = fopen(nombreArchivo,"ab");
		if(p==NULL){
			return false;
		}
		int escribio = fwrite(&r,sizeof(clsCelular),1,p);
		if(escribio == 1){
			fclose(p);
			return true;
		}
		fclose(p);
		return false;
	}


    int ArchivosCelular::contarRegistros(){
        FILE *p;
        p = fopen(nombreArchivo,"rb");
        if(p==NULL){
            std::cout<<"ERROR ARCHIVO"<<std::endl;
            return 0;
        }
        fseek(p,0,2);
        int cant = ftell(p);
        fclose(p);
        return cant/sizeof(clsCelular);
    }
    bool ArchivosCelular::buscarCelular (const char* _modelo, const char* _nombre, int& posAct, clsCelular& _reg) {
		FILE* p = fopen("Celulares.dat", "rb");
		bool estado = false;
		if (p == NULL) {
			cout << "ERROR AL ABRIR EL ARCHIVO" << endl;
			return estado;
		}
		int registros = contarRegistros();
		for (int i = 0; i < registros; i++) {
			clsCelular reg = Leer(i);
			if (strcmp(reg.getModelo(), _modelo) == 0 && strcmp(reg.getNombre(), _nombre) == 0) {
				posAct = i;
				_reg = reg;
				estado = true;
				break;
			}
		}
		fclose(p);
		return estado;
	}
	bool ArchivosCelular::modificar_registro(int pos,clsCelular& reg){
		FILE* p = fopen(nombreArchivo, "rb+");
		if (p == NULL) {
			cout << "ERROR DE ARCHIVO" << endl;
			return false;
		}

		fseek(p, sizeof(clsCelular) * pos, 0);
		int escritos = fwrite(&reg, sizeof(clsCelular), 1, p);
		fclose(p);

		return escritos == 1;
	}
