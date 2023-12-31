#ifndef CLSCLIENTE_H
#define CLSCLIENTE_H
#include <iomanip>
#include <iostream>
#include <cstdio>
#include <cstring>
#include "funcioneGlobales.h"
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
    clsCliente(int _dni, const char* _nombre, const char* _apellido, const char* _telefono, const Fecha& _fechaNacimiento, bool _estado) {
		dni = _dni;
		strncpy(nombre, _nombre, sizeof(nombre) - 1);
		strncpy(apellido, _apellido, sizeof(apellido) - 1);
		strncpy(telefono, _telefono, sizeof(telefono) - 1);
		fechaNacimiento = _fechaNacimiento;
		estado = _estado;
	}
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
    bool Cargar(int);
    void Mostrar();
    void mostrarMenos();
};

class ArchivoCliente{
private:
    char nombreArchivo[30];
public:
    ArchivoCliente(const char *n);
    bool Cargar(clsCliente r);
    clsCliente leer(int pos);
    int contarRegistros();
    int leerDni(int dni);
    bool modificarRegistro(int pos, const clsCliente &r);
    bool borrar();
};
#endif // CLSCLIENTE_H
