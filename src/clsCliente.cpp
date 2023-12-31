#include "clsCliente.h"
using namespace std;
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
bool clsCliente::Cargar(int d=-1){

        cout<<"------AGREGAR CLIENTE------"<<endl;
        if(d==-1){
			cout<<"DNI: ";
			cin>>dni;
        }
        else {
            dni=d;
        }
        cout<<"NOMBRE: ";
        cargarCadena(nombre,30);
        cout<<"APELLIDO: ";
        cargarCadena(apellido,30);
        cout<<"TELEFONO: ";
        cargarCadena(telefono,30);
        cout<<"FECHA DE NACIMIENTO: "<<endl;
        Fecha nac;
        while(!nac.Cargar()){
            cout<<"FECHA INCORRECTA"<<endl;
        }

        Fecha hoy;
        int edad = nac - hoy;
        if(edad< 18){
            cout<<"DEBE SER MAYOR DE 18 A�OS PARA COMPRAR"<<endl;
            return false;
        }
        setFechaNacimiento(nac);
        estado = true;
        return true;
}

void clsCliente::Mostrar(){
        if(estado){
            cout<<left;
            cout<<setw(10)<<dni;
            cout<<setw(10)<<nombre;
            cout<<setw(12)<<apellido;
            cout<<setw(13)<<telefono;
            cout<<right;
            cout<<setw(2)<<fechaNacimiento.getDia()<<"/";
            cout<<setw(2)<<fechaNacimiento.getMes()<<"/";
            cout<<setw(4)<<fechaNacimiento.getAnio()<<endl;
        }
}
void clsCliente::mostrarMenos(){
    cout<<"DNI: "<<dni<<" NOMBRE: "<<nombre<<endl;
    cout<<"    APELLIDO: "<<apellido<<" TELEFONO: "<<telefono;
}

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

clsCliente ArchivoCliente::leer(int pos){
    clsCliente r;
    r.setEstado(false);
    FILE *p;
    p=fopen(nombreArchivo, "rb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return r;
    }

    fseek(p, (sizeof(clsCliente)*pos), 0);
    if(fread(&r, sizeof(clsCliente), 1, p)==1){
        fclose(p);
        return r;
    }

    r.setEstado(false);
    fclose(p);
    return r;

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

int ArchivoCliente::leerDni(int dni){

    clsCliente r;
    FILE *p;
    p=fopen(nombreArchivo, "rb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -2;
    }
    int posicion=0;
    while(fread(&r, sizeof(clsCliente),1,p)==1){
        if(r.getDNI()== dni){
           fclose(p);
           return posicion;
        }
        posicion++;
    }

    fclose(p);
    return -1;

}

bool ArchivoCliente::modificarRegistro(int pos, const clsCliente &r){

    FILE *p;
    p=fopen(nombreArchivo, "rb+");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }

    fseek(p, (sizeof(clsCliente)*pos), 0);

    if(fwrite(&r, sizeof(clsCliente), 1, p)== 1){
        fclose(p);
        return true;
    }
    fclose(p);
    return false;
}
bool ArchivoCliente::borrar(){
        FILE* p = fopen(nombreArchivo, "wb");
		if (p == NULL) {
			cout << "ERROR AL ABRIR EL ARCHIVO" << endl;
			return false;
		}
		fclose(p);
		return true;
    }

