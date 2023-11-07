#include <iostream>
#include <cstdlib>
using namespace std;
#include "Reportes.h"

void menuReporte() {
    int opcion;
    do {
        cout << "Menú de Reportes" << endl;
        cout << "----------------------------"<<endl;
        cout << "1. Reporte 1" << endl;
        cout << "2. Reporte 2" << endl;
        cout << "3. Reporte 3" << endl;
        cout << "4. Reporte 4" << endl;
        cout << "5. Reporte 5" << endl;
        cout << "6. Reporte 6" << endl;
        cout << "0. Salir" << endl;
        cout << "----------------------------"<<endl;
        cout << "Selecciona una opción: ";

        cin >> opcion;
        switch (opcion) {
            case 0:
                cout << "Saliendo del programa." << endl;
                return;
            case 1:
            //DADO UN NUMERO ENTERO, DEVOLVER PRODUCTOS CON STOCK INFERIOR A ESE NUMERE
                break;
            case 2:
                cout << "Generando Reporte 2..." << endl;
            //DADA DOS FECHAS, DEVOLVER EL TOTAL FACTURADO EN ESE RANGO DE TIEMPO
                break;
            case 3:
                cout << "Generando Reporte 3..." << endl;

                break;
            case 4:

            /*char  n[30];
            strcpy(n,r.getNombre());
            strcat(n,".dat");
            ArchivoCliente archi(n);*/
                cout << "Generando Reporte 4..." << endl;

                break;
            case 5:
                cout << "Generando Reporte 5..." << endl;

                break;
            case 6:
                cout << "Generando Reporte 6..." << endl;

                break;
        }
    } while (true);
}

