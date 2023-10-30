#include "clsCliente.h"

clsCliente::clsCliente(){
    dni = 0;
    strcpy(nombre,"vacio");
    strcpy(apellido,"vacio");
    strcpy(telefono,"vacio");
    estado=true;
}

///Metodos Set
void clsCliente::setDNI(int c){dni=c;}
void clsCliente::setNombre(const char *n){strcpy(nombre,n);}
void clsCliente::setApellido(const char *n){strcpy(apellido,n);}
void clsCliente::setTelefono(const char *t){strcpy(telefono,t);}
void clsCliente::setFechaNacimiento(Fecha f){fechaNacimiento = f;}
void clsCliente::setEstado(bool e){estado=e;}
///Metodos Get
int clsCliente::getDNI(){return dni;}
const char*  clsCliente::getNombre(){return nombre;}
const char* clsCliente::getApellido(){return apellido;}
const char*  clsCliente::getTelefono(){return telefono;}
Fecha clsCliente::getFecha(){return fechaNacimiento;}
bool clsCliente::getEstado(){return estado;}
///Metodos Principales
bool clsCliente::Cargar(){}
void clsCliente::Mostrar(){}

ArchivoCliente::ArchivoCliente(const char *n){
    strcpy(nombreArchivo,n);
}

bool ArchivoCliente::Cargar(clsCliente r){
    FILE *p;
    p = fopen(nombreArchivo,"ab");
    if(p==NULL){
        return false;
    }
    int escribio = fwrite(&r,sizeof(clsCliente),1,p);
    if(escribio == 1){
        fclose(p);
        return true;
    }
    fclose(p);
    return false;
}

void ArchivoCliente::Leer(){
    clsCliente r;
    FILE *p;
    p = fopen(nombreArchivo,"rb");
    if(p==NULL){
        std::cout<<"ERROR ARCHIVO"<<std::endl;
    }
    while(fread(&r,sizeof(clsCliente),1,p)){
        r.Mostrar();
    }
    fclose(p);
    }

    int ArchivoCliente::contarRegistros(){
        FILE *p;
        p = fopen(nombreArchivo,"rb");
        if(p==NULL){
            std::cout<<"ERROR ARCHIVO"<<std::endl;
            return 0;
        }
        fseek(p,0,2);
        int cant = ftell(p);
        fclose(p);
        return cant/sizeof(clsCliente);
    }

