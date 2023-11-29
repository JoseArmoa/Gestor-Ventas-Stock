#ifndef FUNCIONESVENTAS_H_INCLUDED
#define FUNCIONESVENTAS_H_INCLUDED
#include <iostream>
#include "funcioneGlobales.h"
#include "clsCelular.h"
#include "clsVentas.h"
#include "clsCliente.h"
#include "funcionesClientes.h"
void menuVentas();
bool cargarVentas();
void listarVentas();
void mostrarMenuVentas();
void guardarVectorArchivo(vectorDinamicoCelular &,int,int);
void descontarStock(clsCelular &);
void aumentarStock(clsCelular &);
void poner_disponibilidad(clsCelular &);
bool eliminarVenta();
bool modificarFecha();
bool devolucion();

#endif // FUNCIONESVENTAS_H_INCLUDED
