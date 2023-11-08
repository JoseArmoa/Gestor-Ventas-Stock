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

    void clsCelular::setMarca(const char *marca) {
		strcpy(Marca_celu,marca);
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
    void clsCelular::setDisponibilidad(bool e){
		Disponibilidad=e;
    }
	void clsCelular::cargar(const char *n,const char *m){
		if(n==nullptr){
            cout << "Ingrese el modelo (hasta 30 caracteres): ";
            cin.ignore(); // Limpia el buffer de entrada.
            cin.getline(modelo, 30);
		}else{
            strcpy(modelo,n);
		}

		cout << "Ingrese el nombre (hasta 30 caracteres): ";
		cin.getline(nombre, 30);

		if(n==nullptr){
            cout << "Ingrese el modelo (hasta 30 caracteres): ";
            cin.ignore(); // Limpia el buffer de entrada.
            cin.getline(Marca_celu, 30);
		}else{
            strcpy(Marca_celu,m);
		}


		cout<<"FECHA LANZAMIENTO: "<<endl;
		anioLanzamiento.Cargar();

		cout << "Ingrese el precio: ";
		cin >> precio;
        int s;
		cout << "Ingrese la cantidad en stock: ";
		cin >> s;
		setStock(s);
        if(s > 0){
            setDisponibilidad(true);
        }else setDisponibilidad(false);
		setEstado(true);
	}
	void clsCelular::mostrar() {
		if (getEstado()) {
			cout << "Modelo: " << modelo << endl;
			cout << "Nombre: " << nombre << endl;
			cout << "Fecha de lanzamiento: ";
			anioLanzamiento.Mostrar();
			cout << "Marca: " << Marca_celu << endl;
			cout << "Precio: " << precio << endl;
			cout << "Stock: " << stock << endl;
		}
	}

	void clsCelular::mostrarMenos() {
		if (getEstado()){
			cout << modelo <<"     " << nombre << "    $" << precio << endl;


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
		FILE* p = fopen(nombreArchivo, "rb");
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
    bool ArchivosCelular::borrar(){
        FILE* p = fopen(nombreArchivo, "wb");
		if (p == NULL) {
			cout << "ERROR AL ABRIR EL ARCHIVO" << endl;
			return false;
		}
		fclose(p);
		return true;
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
    bool vectorDinamicoCelular::eliminar(const char *n){//elimina registro del vector dado por el usuario,(esto tambien achica al vector).
        bool encontro=false;
        for(int i=0;i<tam;i++){
            if(strcmp(vectorCelular[i].getModelo(),n)==0){
                vectorCelular[i].setEstado(false);
                i=tam;
                encontro=true;
            }
        }
        if(encontro){
            clsCelular *aux;
            aux = new clsCelular[tam];
            if(aux==NULL)return false;
            for(int i=0;i<tam;i++){
                aux[i] = vectorCelular[i];
            }
            delete vectorCelular;
            tam = tam-1;
            vectorCelular = new clsCelular[tam];
            if(vectorCelular==NULL)return false;
            int cont = 0;
            for(int i=0;i<tam+1;i++){
                if(aux[i].getEstado()){
                    vectorCelular[cont] = aux[i];
                    cont++;
                }
            }
            delete aux;
            inicio--;
            return true;
        }else{
            cout<<"MODELO INCORRECTO"<<endl;
            return false;
        }
    }

    void vectorDinamicoCelular::mostrar(){
        for(int i=0;i<tam;i++){
            vectorCelular[i].mostrarMenos();
            cout<<endl;
        }
    }
    int vectorDinamicoCelular::getTam(){
        if(tam>0){
            return tam;
        }
    }
    clsCelular vectorDinamicoCelular::getElemento(int pos){
        return vectorCelular[pos];
    }
    const clsCelular& vectorDinamicoCelular::operator[](int i){
        if(i>=0 && i<tam){
            return vectorCelular[i];
        }
    }

///FUNCIONES CLASE CELULARES VENDIDOS
void celularVendido::cargar(int c,clsCelular &r){
    codVenta=c;
    strcpy(this->modelo,r.getModelo());
    strcpy(this->nombre,r.getNombre());
    precio=r.getPrecio();
    estado=true;
}

void celularVendido::setCodVenta(int p){
    codVenta=p;
}
void celularVendido::setEstado(bool e){
    estado = e;
}
int celularVendido::getCodVenta(){
    return codVenta;
}
void celularVendido::mostrar(){
    clsCelular::mostrarMenos();
    }



///FUNCIONES ARCHIVO CELULARES VENDIDOS
ArchivoCelularVendido::ArchivoCelularVendido(const char *n){
    strcpy(nombreArchivo,n);
}
bool ArchivoCelularVendido::cargar(celularVendido r){
    FILE *p=fopen(nombreArchivo,"ab");
    if(p==NULL){
        return false;
    }
    if(fwrite(&r,sizeof(celularVendido),1,p)==1){
        fclose(p);
        return true;
    }
    fclose(p);
    return false;
}

bool ArchivoCelularVendido::mostrar(){
    celularVendido r;
    FILE *p=fopen(nombreArchivo,"rb");
    if(p==NULL){
        return false;
    }
    while(fread(&r,sizeof(celularVendido),1,p)){
        r.mostrar();
    }
    fclose(p);
    return false;
}
celularVendido ArchivoCelularVendido::Leer(int pos){
    celularVendido r;
    r.setEstado(false);
    FILE *p=fopen(nombreArchivo,"rb");
    if(p==NULL){
        return r;
    }
    fseek(p,sizeof(celularVendido),0);
    if(fread(&r,sizeof(celularVendido),1,p)==1){
        fclose(p);
        return r;
    }
    fclose(p);
    return r;
}
bool ArchivoCelularVendido::LeerVenta(int c){
    celularVendido r;
    FILE *p=fopen(nombreArchivo,"rb");
    if(p==NULL){
        return false;
    }
    //REVISAR. al while le falta la condicion que seria si el fread == 1 pero creo que funciona igual. lo anoto por si acaso nomas
    while(fread(&r,sizeof(celularVendido),1,p)){
        if(r.getCodVenta()==c){
            //r.mostrar();
            //!!!!!!!!!comente el r.mostrar porque cada vez que quiero leer el archivo en otro metodo muestra todos los registros cuando no hace falta mostrarlos
        }
    }
    fclose(p);
    return false;
}

int ArchivoCelularVendido::contarRegistros(){
        FILE *p;
        p = fopen(nombreArchivo,"rb");
        if(p==NULL){
            std::cout<<"ERROR ARCHIVO"<<std::endl;
            return 0;
        }
        fseek(p,0,2);
        int cant = ftell(p);
        fclose(p);
        return cant/sizeof(celularVendido);
    }

bool ArchivoCelularVendido::borrar(){
        FILE* p = fopen("vendidos.dat", "wb");
		if (p == NULL) {
			cout << "ERROR AL ABRIR EL ARCHIVO" << endl;
			return false;
		}
		fclose(p);
		return true;
    }
