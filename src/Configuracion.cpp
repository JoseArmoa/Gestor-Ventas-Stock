#include <iostream>
#include <cstdlib>
using namespace std;
#include "Configuracion.h"
#include "rlutil.h"

void Guardar() {
    int resultado_1 = system("copy celulares.dat celulares.bkp");
    int resultado_2 = system("copy clientes.dat clientes.bkp");
    int resultado_3 = system("copy ventas.dat ventas.bkp");
    int resultado_4 = system("copy vendidos.dat vendidos.bkp");
    int resultado_5 = system("copy marcas.dat marcas.bkp");

    if (resultado_1 == 0 && resultado_2 == 0 && resultado_3 == 0 && resultado_4 == 0 && resultado_5 == 0) {
        cout << "ARCHIVOS COPIADOS EXITOSAMENTE." << endl;
    } else {
        cout << "ERROR AL COPIAR LOS ARCHIVOS." << endl;
    }
}

void Restaurar() {
	int resultado_1 = system("copy celulares.bkp celulares.dat");
    int resultado_2 = system("copy clientes.bkp clientes.dat");
    int resultado_3 = system("copy ventas.bkp ventas.dat");
    int resultado_4 = system("copy vendidos.bkp vendidos.dat");
    int resultado_5 = system("copy marcas.bkp marcas.dat");

    if (resultado_1 == 0 && resultado_2 == 0 && resultado_3 == 0 && resultado_4 == 0 && resultado_5 == 0) {
        cout << "ARCHIVOS RESTAURADOS EXITOSAMENTE." << endl;
    } else {
        cout << "ERROR AL RESTAURAR LOS ARCHIVOS." << endl;
    }
}
bool borrarTodo(){
    ArchivoCelularVendido archiVendido("vendidos.dat");
    ArchivoCliente archiCliente("clientes.dat");
    ArchivosCelular archiCelular("celulares.dat");
    ArchivosVentas archiVentas("ventas.dat");
    ArchivoMarca archiMarca("marcas.dat");
    if(archiVendido.borrar() && archiCliente.borrar() && archiCelular.borrar() && archiVentas.borrar() && archiMarca.borrar()){
        return true;
    }
    return false;
}
void ValoresInicio(){

	///
	int resultado_1 = system("copy marcasValoresInicio.dat marcas.dat");
	int resultado_2 = system("copy clientesValoresInicio.dat clientes.dat");
	int resultado_3 = system("copy celularesValoresInicio.dat celulares.dat");
	int resultado_4 = system("copy vendidosValoresInicio.dat vendidos.dat");
	int resultado_5 = system("copy ventasValoresInicio.dat ventas.dat");

	if (resultado_1 == 0 && resultado_2 == 0 && resultado_3 == 0 && resultado_4 == 0 && resultado_5 == 0 ) {
        cout << "ARCHIVOS RESTAURADOS EXITOSAMENTE." << endl;
    } else {
        cout << "ERROR AL RESTAURAR LOS ARCHIVOS." << endl;
    }
}
void menuConfiguracion() {
    rlutil::setConsoleTitle("CONFIGURACION");
    int opcion;
    do {
        system("cls");
        cout << "MENU CONFIGURACION" << endl;
		cout << "---------------------------------"<<endl;
        cout << "1. CREAR COPIA" << endl;
        cout << "2. RESTAURAR COPIA" << endl;
        cout << "3. VALORES DE INICIO" << endl;
        cout << "4. BORRAR TODO" << endl;
        cout << "---------------------------------"<<endl;
        cout << "0. SALIR" << endl;
        cout << "Ingrese su opcion: ";
        opcion=rlutil::getkey();
		system("cls");
        switch(opcion){
            case 49: //si se apreta 1
                    Guardar();
            break;
            case 50://si se apreta 2
                    Restaurar();
            break;
            case 51://si se apreta 3
                    ValoresInicio();
        	break;
            case 52://si se apreta 4
                    if (borrarTodo()) {
                    cout << "ARCHIVOS ELIMINADOS EXITOSAMENTE." << endl;
                } else {
                    cout << "ERROR AL ELIMINAR ARCHIVOS." << endl;
                }
                break;
            case 48://si se apreta 0
        return;
            default: std::cout<<"OPCION INVALIDA. "<<std::endl;
            break;

        }
        system("pause");
    } while (true);
}



