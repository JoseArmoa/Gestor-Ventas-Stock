#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;
#include "rlutil.h"
#include "funcioneGlobales.h"
#include "clsFecha.h"
#include "clsVentas.h"
#include "funcionesVentas.h"
#include "funcionesCelulares.h"
#include "Reportes.h"
#include "Configuracion.h"
#include "funcionesClientes.h"


int main(){
    rlutil::setConsoleTitle("MENÚ PRINCIPAL");
    rlutil::hidecursor();
    system("color 80");
    setlocale(LC_ALL, "");
    int op;
    while(true){
    menuPrincipal();
        op=rlutil::getkey();
    system("cls");
        switch(op){
    case 49: //si se apreta 1
        menuVentas();

            break;
    case 50://si se apreta 2
        menuClientes();
        system("cls");
            break;
    case 51://si se apreta 3
			menuStocCelulares();
			system("cls");
        	break;
    case 52://si se apreta 4
        menuReporte();
        system("cls");
        	break;
    case 53://si se apreta 5
        menuConfiguracion();
        system("cls");
			break;
    case 48://si se apreta 0
        return 0;
    default: cout<<"OPCIÓN INVALIDA. "<<endl;
            break;

        }
    }
}
