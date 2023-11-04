#ifndef FUNCIONESVENTAS_H_INCLUDED
#define FUNCIONESVENTAS_H_INCLUDED
#include <iostream>
#include "clsCelular.h"
#include "clsVentas.h"
void menuVentas();
bool cargarVentas();
void listarVentas();
void mostrarMenuVentas();
void guardarVectorArchivo(vectorDinamicoCelular &,int,int);
void descontarStock(clsCelular &);

#endif // FUNCIONESVENTAS_H_INCLUDED
