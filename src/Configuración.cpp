#include <iostream>
#include <cstdlib>
using namespace std;
#include "Configuración.h"

void menuConfiguracion() {
    int opcion;
    do {
        system("cls");
        cout << "Menu de Configuraciones" << endl;
        cout << "0. Salir" << endl;
		cout << "---------------------------------"<<endl;
        cout << "1. Guardar archivos" << endl;
        cout << "2. Restaurar archivos" << endl;
        cout << "3. Restaurar valores de inicio" << endl;
        cout << "---------------------------------"<<endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;
		system("cls");
        switch (opcion) {
			case 0:
				return;
            case 1:

                break;
            case 2:

                break;
            case 3:

                break;
        }
    } while (true);
}
void subMenuGuardar() {
    int opcion;
    do {
        system("cls");
        cout << "Sub-menu Guardar" << endl;
        cout << "0. Salir" << endl;
        cout << "------------------------------" << endl;
        cout << "1. Guardar archivos celular" << endl;
        cout << "2. Guardar archivos cliente" << endl;
        cout << "3. Guardar archivos ventas" << endl;
        cout << "4. Guardar todos los archivos" << endl;
        cout << "-------------------------------" << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;
        system("cls");
        switch (opcion) {
            case 0:
                return;
            case 1:

                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
        }
    } while (true);
}
void subMenuRestaurar() {
    int opcion;
    do {
        system("cls");
        cout << "Sub-menu restaurar" << endl;
        cout << "0. Salir" << endl;
        cout << "------------------------------" << endl;
        cout << "1. Restaurar archivos celular" << endl;
        cout << "2. Restaurar archivos cliente" << endl;
        cout << "3. Restaurar archivos ventas" << endl;
        cout << "4. Restaurar todos los archivos" << endl;
        cout << "-------------------------------" << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;
        system("cls");
        switch (opcion) {
            case 0:
                return;
            case 1:

                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
        }
    } while (true);
}


