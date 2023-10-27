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
    ArchivosCelular(const char *v);
    bool Cargar(Celular r);
    void Leer();
    int contarRegistros();

};


bool ArchivosCelular::Cargar(Celular r){
    FILE p;
    p = fopen(nombreArchivo,"ab");
    if(p==NULL){
        return false;
    }
    int escribio = fwrite(&r,sizeof(Celular),1,p);
    if(escribio == 1){
        fclose(p);
        return true;
    }
    fclose(p);
    return false;
}

void ArchivosCelular::Leer(){
    Celular r;
    FILE p;
    p = fopen(nombreArchivo,"rb");
    if(p==NULL){
        std::cout<<"ERROR ARCHIVO"<<std::endl;
    }
    while(fread(&r,sizeof(Celular),1,p)){
        r.Mostrar();
    }
    fclose(p);
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
        return cant/sizeof(Celular);
    }



#endif // CELULAR_H_INCLUDED
