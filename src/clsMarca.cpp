#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cstring>
using namespace std;
#include "clsMarca.h"
#include "funcioneGlobales.h"

clsMarca::clsMarca(const char* m) {
    strcpy(Marca, m);
    estado = true;
}
clsMarca::clsMarca() {
    const char* m = "Sin Marca";
    strcpy(Marca, m);
    estado = false;
}


void clsMarca::setMarca(const char* m) {
    strcpy(Marca, m);
}

void clsMarca::setEstado(bool e) {
    estado = e;
}

const char* clsMarca::getMarca() {
    return Marca;
}

bool clsMarca::getEstado() {
    return estado;
}

void clsMarca::mostrar() {
    if (getEstado()){
		cout<<Marca<<endl;
	}
}
void clsMarca::cargar() {
    cout << "INGRESE LA MARCA: ";
    cargarCadena(Marca, 30);

    // Verifica si la cadena est� completamente en blanco
    while ( esCadenaEnBlanco(Marca)) {
        cout << "LA MARCA NO PUEDE IR SIN NADA" << endl;
        cout << "INGRESE LA MARCA: ";
        cargarCadena(Marca, 30);
    }

    setEstado(true);
}
bool esCadenaEnBlanco(const char* cadena) {
    // Verifica si la cadena est� completamente en blanco
    size_t longitud = strlen(cadena);
    for (size_t i = 0; i < longitud; ++i) {
        if (!std::isspace(static_cast<unsigned char>(cadena[i]))) {
            return false;
        }
    }
    return true;
}



	bool ArchivoMarca::Cargar(clsMarca r){
		FILE* p;
		p = fopen(nombreArchivo,"ab");
		if(p==NULL){
			return false;
		}
		int escribio = fwrite(&r,sizeof(clsMarca),1,p);
		if(escribio == 1){
			fclose(p);
			return true;
		}
		fclose(p);
		return false;
	}


    int ArchivoMarca::contarRegistros(){
        FILE *p;
        p = fopen(nombreArchivo,"rb");
        if(p==NULL){
            std::cout<<"ERROR ARCHIVO"<<std::endl;
            return 0;
        }
        fseek(p,0,2);
        int cant = ftell(p);
        fclose(p);
        return cant/sizeof(clsMarca);
    }

	bool ArchivoMarca::modificar_registro(int pos,clsMarca& reg){
		FILE* p = fopen(nombreArchivo, "rb+");
		if (p == NULL) {
			cout << "ERROR DE ARCHIVO" << endl;
			return false;
		}

		fseek(p, sizeof(clsMarca) * pos, 0);
		int escritos = fwrite(&reg, sizeof(clsMarca), 1, p);
		fclose(p);

		return escritos;
	}

	int ArchivoMarca::buscarMarca(const char* _marca) {
		clsMarca reg;
		FILE* p = fopen(nombreArchivo, "rb");
		if (p == NULL) {
			cout << "ERROR AL ABRIR EL ARCHIVO" << endl;
			return -2;
		}
		int pos = 0;
		while (fread(&reg, sizeof(clsMarca), 1, p)) {
			if (strcmp(reg.getMarca(), _marca) == 0) {
				fclose(p);
				return pos;
			}
			pos++;
		}
		fclose(p);
		return -1;
	}

    bool ArchivoMarca::borrar(){
        FILE* p = fopen(nombreArchivo, "wb");
		if (p == NULL) {
			cout << "ERROR AL ABRIR EL ARCHIVO" << endl;
			return false;
		}
		fclose(p);
		return true;
    }

