#ifndef CLSCELULAR_H
#define CLSCELULAR_H

#include "clsFecha.h"
#include <cstring>
#include "clsMarca.h"

class clsCelular{
protected:
    char modelo[30];
    char nombre[30];
    char Marca_celu[30];
    Fecha anioLanzamiento;
    float precio;
    int stock;
    bool Disponibilidad;
    bool estado = false;

public:
    //CONSTRUCTOR
    clsCelular(const char* _modelo, const char* _nombre, const char* _marca, const Fecha& _anioLanzamiento, float _precio, int _stock) {
        strncpy(modelo, _modelo, sizeof(modelo) - 1);
        strncpy(nombre, _nombre, sizeof(nombre) - 1);
        strcpy(Marca_celu,_marca);
        anioLanzamiento = _anioLanzamiento;
        precio = _precio;
        stock = _stock;
        if ( stock>0){
			Disponibilidad=true;
		} else {Disponibilidad=true; }
        estado=true;
    }
    clsCelular() {

        modelo[0] = '\0';
        nombre[0] = '\0';
        strcpy(Marca_celu,"vacio");
        precio = 0.0;
        stock = 0;
        Disponibilidad = false;
        estado = false;
    }
    //clsCelular();
    //SETTERS
    void setModelo(char* cadena);
    void setNombre(char* cadena);
    void setMarca(const char* marca);
    void setAnioLanzamiento(Fecha f);
    void setPrecio(float p);
    void setStock(int s);
    void setEstado(bool e);
    void setDisponibilidad(bool);
    //GETTERS
    const char* getModelo(){return modelo;}
    const char* getNombre(){return nombre;}
    const char* getMarca(){return Marca_celu;}
    Fecha getAnioLanzamiento(){return anioLanzamiento;}
    float getPrecio(){return precio;}
    int getStock(){return stock;}
    bool getEstado(){return estado;}
    bool getDisponibilidad(){return Disponibilidad;}
	//MOSTRAR CARGAR
	void cargar(const char *,const char *);
	void mostrar();
	void mostrarMenos();//Este metodo solo muestra las propiedades modelo, nombre, y precio.
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
	int buscarCelular(const char* _modelo);
	bool modificar_registro(int, clsCelular&);
	bool borrar();
};
///clase para crear vector dinamico de celulares para clase venta
class vectorDinamicoCelular{
private:
    clsCelular *vectorCelular;
    int tam;
    int inicio;
public:
    vectorDinamicoCelular(int t);
    ~vectorDinamicoCelular();
    bool agregar(clsCelular r);
    void aumentar(int t);
    bool eliminar(const char *n);
    void mostrar();
    int getTam();
    clsCelular getElemento(int);
    const clsCelular& operator[](int);
    vectorDinamicoCelular& operator=(const clsCelular& );
};

///CLASE PARA GUARDAR EN UN ARCHIVO LOS CELULARES VENDIDOS INDIVIDUALMENTE CON SU CODIGO DE VENTA
class celularVendido:clsCelular{
private:
    int codVenta;
public:
    void cargar(int,clsCelular &);
    void setCodVenta(int);
    void setEstado(bool);
    int getCodVenta();
    float getPrecio();
    bool getEstado();
    void mostrar();
    const char* getModelo();
    celularVendido& operator=(const vectorDinamicoCelular &r);
};

class ArchivoCelularVendido{
private:
    char nombreArchivo[30];
public:
    ArchivoCelularVendido(const char *);
    celularVendido LeerIndividual(int ,const char *,int &);
    bool cargar(celularVendido);
    bool mostrar();
    bool modificar(int, celularVendido);
    bool LeerVenta(int);
    int contarRegistros();
    bool borrar();
    celularVendido Leer(int pos);
};

#endif // CLSCELULAR_H
