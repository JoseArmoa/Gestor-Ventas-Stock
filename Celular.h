#ifndef CELULAR_H_INCLUDED
#define CELULAR_H_INCLUDED

class Celular{
private:
    char modelo[30];
    char nombre[30];
    int marca;
    Fecha anioLanzamiento;
    float precio;
    int stock;
    bool estado;

public:
    //GETTERS
    char* getModelo(){return modelo;}
    char* getNombre(){return nombre;}
    int getMarca(){return marca;}
    Fecha getAnioLanzamiento(){return anioLanzamiento;}
    float getPrecio(){return precio;}
    int getStock(){return stock;}
    bool getEstado(){return estado;}

    //SETTERS
    void setModelo(char* cadena);
    void setNombre(char* cadena);
    void setMarca(int m);
    void setAnioLanzamiento(Fecha f);
    void setPrecio(float p);
    void setStock(int s);
    void setEstado(bool e);


};
    void Celular::setModelo(char* cadena){
        strcpy(modelo, cadena);
    }

    void Celular::setNombre(char* cadena){
        strcpy(nombre, cadena);
    }

    void Celular::setMarca(int m){
        marca=m;
    }

    void Celular::setAnioLanzamiento(Fecha f){
        anioLanzamiento=f;
    }

    void Celular::setPrecio(float p){
        precio=p;
    }

    void Celular::setStock(int s){
        stock=s;
    }

    void Celular::setEstado(bool e){
        estado=e;
    }


class ArchivosCelular{
private:
    char nombreArchivo[30];
public:
    ArchivosCelular(const char *v){

    }
    bool Cargar(Celular r);
    void Leer();
    int contarRegistros();

};




#endif // CELULAR_H_INCLUDED
