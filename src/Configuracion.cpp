#include <iostream>
#include <cstdlib>
using namespace std;
#include "Configuracion.h"

void Guardar() {
    int resultado_1 = system("copy celulares.dat celulares.bkp");
    int resultado_2 = system("copy clientes.dat clientes.bkp");
    int resultado_3 = system("copy ventas.dat ventas.bkp");
    int resultado_4 = system("copy vendidos.dat vendidos.bkp");
    int resultado_5 = system("copy marcas.dat marcas.bkp");

    if (resultado_1 == 0 && resultado_2 == 0 && resultado_3 == 0 && resultado_4 == 0 && resultado_5 == 0) {
        cout << "Archivos copiados exitosamente." << endl;
    } else {
        cout << "Error al copiar los archivos." << endl;
    }
    system("pause");
}

void Restaurar() {
	int resultado_1 = system("copy celulares.bkp celulares.dat");
    int resultado_2 = system("copy clientes.bkp clientes.dat");
    int resultado_3 = system("copy ventas.bkp ventas.dat");
    int resultado_4 = system("copy vendidos.bkp vendidos.dat");
    int resultado_5 = system("copy marcas.bkp marcas.dat");

    if (resultado_1 == 0 && resultado_2 == 0 && resultado_3 == 0 && resultado_4 == 0 && resultado_5 == 0) {
        cout << "Archivos restaurados exitosamente." << endl;
    } else {
        cout << "Error al restaurar los archivos." << endl;
    }
    system("pause");
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
	int resultado_1 = system("copy marcasValoresInicio.dat marcas.dat");
	int resultado_2 = system("copy clientesValoresInicio.dat clientes.dat");
	int resultado_3 = system("copy celularesValoresInicio.dat celulares.dat");
	if (resultado_1 == 0 && resultado_2 == 0 && resultado_3 == 0 ) {
        cout << "Archivos restaurados exitosamente." << endl;
    } else {
        cout << "Error al restaurar los archivos." << endl;
    }
}
void menuConfiguracion() {
    int opcion;
    do {
        system("cls");
        cout << "Menu de Configuraciones" << endl;
        cout << "0. Salir" << endl;
		cout << "---------------------------------"<<endl;
        cout << "1. Guardar archivos" << endl;
        cout << "2. Restaurar archivos" << endl;
        cout << "3. Valores de inicio" << endl;
        cout << "4. Borrar todo" << endl;
        cout << "---------------------------------"<<endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;
		system("cls");
        switch (opcion) {
			case 0:
				return;
            case 1:
				Guardar();
                break;
            case 2:
				Restaurar();
                break;
			case 3:ValoresInicio();
				break;
			case 4:
                if (borrarTodo()) {
                    cout << "Archivos eliminados exitosamente." << endl;
                } else {
                    cout << "Error al eliminar archivos." << endl;
                }
                break;
        }
        system("pause");
    } while (true);
}



