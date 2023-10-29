#ifndef CLSCLIENTE_H
#define CLSCLIENTE_H
#include <iostream>
#include <cstdio>
#include <cstring>
#include "clsFecha.h"
class clsCliente
{
private:
    int dni;
    char nombre[30];
    char apellido[30];
    char telefono[30];
    Fecha fechaNacimiento;
    bool estado;
public:
    clsCliente();
        ///Metodos Set
    void setDNI(int c);
    void setNombre(const char *n);
    void setApellido(const char *n);
    void setTelefono(const char *t);
    void setFechaNacimiento(Fecha f);
    void setEstado(bool e);
    ///Metodos Get
    int getDNI();
    const char*  getNombre();
    const char* getApellido();
    const char*  getTelefono();
    Fecha getFecha();
    bool getEstado();
    ///Metodos Principales
    bool Cargar();
    void Mostrar();
};

class ArchivoCliente{
private:
    char nombreArchivo[30];
public:
    ArchivoCliente(const char *n);
    bool Cargar(clsCliente r);
    void Leer();
    int contarRegistros();
};
#endif // CLSCLIENTE_H
