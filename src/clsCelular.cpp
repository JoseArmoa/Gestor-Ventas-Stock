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
	void clsCelular::cargar(const char *n){
		if(n==nullptr){
            cout << "Ingrese el modelo (hasta 30 caracteres): ";
            cin.ignore(); // Limpia el buffer de entrada.
            cin.getline(modelo, 30);
		}else{
            strcpy(modelo,n);
		}

		cout << "Ingrese el nombre (hasta 30 caracteres): ";
		cin.getline(nombre, 30);

		cout << "Ingrese la marca (un número entero): ";
		cin >> marca;


		cout<<"FECHA LANZAMIENTO: "<<endl;
		anioLanzamiento.Cargar();

		cout << "Ingrese el precio: ";
		cin >> precio;

		cout << "Ingrese la cantidad en stock: ";
		cin >> stock;

		setEstado(true);
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
	void clsCelular::mostrarMenos() {
		if (getEstado()){
			cout << "Modelo: " << modelo << endl;
			cout << "Nombre: " << nombre << endl;
			cout << "Precio: " << precio << endl;
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

	bool ArchivosCelular::modificar_registro(int pos,clsCelular& reg){
		FILE* p = fopen(nombreArchivo, "rb+");
		if (p == NULL) {
			cout << "ERROR DE ARCHIVO" << endl;
			return false;
		}

		fseek(p, sizeof(clsCelular) * pos, 0);
		int escritos = fwrite(&reg, sizeof(clsCelular), 1, p);
		fclose(p);

		return escritos;
	}

	int ArchivosCelular::buscarCelular(const char* _modelo) {
		clsCelular reg;
		FILE* p = fopen("Celulares.dat", "rb");
		if (p == NULL) {
			cout << "ERROR AL ABRIR EL ARCHIVO" << endl;
			return -2;
		}
		int pos = 0;
		while(fread(&reg,sizeof(clsCelular),1,p)){
				if(strcmp(reg.getModelo(),_modelo)==0){
                    fclose(p);
                    return pos;
				}
				pos++;
			}
        fclose(p);
		return -1;
    }

	///Funciones para manejar un vector dinamico con registros tipo clsCelular.
    vectorDinamicoCelular::vectorDinamicoCelular(int t = 0){//constructor del vector dinamico
        if(t>0){
            tam = t;
            vectorCelular = new clsCelular[tam];
            if(vectorCelular==NULL)cout<<"error";
            inicio = 0;
        }
    }
    vectorDinamicoCelular::~vectorDinamicoCelular(){
        delete vectorCelular;
    }
    bool vectorDinamicoCelular::agregar(clsCelular r){//Agrega registro de celulares a una posicion del vector.
        vectorCelular[inicio]=r;
        inicio++;
        return true;
    }
    void vectorDinamicoCelular::aumentar(int t){//incrementa en el tamaño del vector, teniendo como parametro un numero entero mayor al tamaño actual del vector.
        if(t>tam){
            clsCelular *aux;
            aux =new clsCelular[tam];
            if(aux==NULL)cout<<"error"<<endl;
            for(int i=0;i<tam;i++){
                aux[i]=vectorCelular[i];
            }
            delete vectorCelular;
            tam = t;
            vectorCelular = new clsCelular[tam];
            if(vectorCelular==NULL)cout<<"error"<<endl;
            for(int i=0;i<tam;i++){
                vectorCelular[i]=aux[i];
            }
            delete aux;
        }
    }
    void vectorDinamicoCelular::eliminar(const char *n){//elimina registro del vector dado por el usuario,(esto tambien achica al vector).
        clsCelular *aux;
        aux = new clsCelular[tam];
        for(int i=0;i<tam;i++){
            aux[i] = vectorCelular[i];
        }
        delete vectorCelular;
        for(int i=0;i<tam;i++){
            if(strcmp(aux[i].getModelo(),n)==0){
                aux[i].setEstado(false);
                i=tam;
            }
        }
        tam = tam-1;
        vectorCelular = new clsCelular[tam];
        int cont = 0;
        for(int i=0;i<tam+1;i++){
            if(aux[i].getEstado()){
                vectorCelular[cont] = aux[i];
                cont++;
            }
        }
        delete aux;
        inicio--;
    }

    void vectorDinamicoCelular::mostrar(){
        for(int i=0;i<tam;i++){
            vectorCelular[i].mostrarMenos();
            cout<<endl;
        }
    }
