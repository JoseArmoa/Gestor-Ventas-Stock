#ifndef CLSCELULAR_H
#define CLSCELULAR_H

#include "clsFecha.h"
#include "cstring"

class clsCelular{
private:
    char modelo[30];
    char nombre[30];
    int marca;
    Fecha anioLanzamiento;
    float precio;
    int stock;
    bool estado;

public:
    //SETTERS
    void setModelo(char* cadena);
    void setNombre(char* cadena);
    void setMarca(int m);
    void setAnioLanzamiento(Fecha f);
    void setPrecio(float p);
    void setStock(int s);
    void setEstado(bool e);
    //GETTERS
    char* getModelo(){return modelo;}
    char* getNombre(){return nombre;}
    int getMarca(){return marca;}
    Fecha getAnioLanzamiento(){return anioLanzamiento;}
    float getPrecio(){return precio;}
    int getStock(){return stock;}
    bool getEstado(){return estado;}
	//MOSTRAR CARGAR
	void cargar();
	void mostrar();
};

class ArchivosCelular{
private:
    char nombreArchivo[30];
public:
    ArchivosCelular(const char *v){
		strcpy(nombreArchivo,v);
    }
    bool Cargar(clsCelular r);

    clsCelular Leer(int pos){
        clsCelular reg;
        FILE *p;
        p=fopen(nombreArchivo, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof (reg)* pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros();
	bool buscarCelular(const char*,const char*,int&,clsCelular&);
	bool modificar_registro(int, clsCelular&);
};




#endif // CLSCELULAR_H
