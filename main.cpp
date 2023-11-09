#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;
#include "funcioneGlobales.h"
#include "clsFecha.h"
#include "clsVentas.h"
#include "funcionesVentas.h"
#include "funcionesCelulares.h"
#include "Reportes.h"
#include "Configuracion.h"
#include "funcionesClientes.h"

int main(){
    setlocale(LC_ALL, "");
    int op;
    while(true){
    menuPrincipal();
    cin>>op;
    system("cls");
        switch(op){
        case 1:
            menuVentas();
            break;
		case 2:
            menuClientes();
            break;
        case 3:
        	MenuCelulares();
        	break;
		case 4:
        	menuReporte();
        	break;
		case 5:
			menuConfiguracion();
			break;
        case 0:
            return 0;
        default: cout<<"OPCION INVALIDA. "<<endl;
            break;
        }
    }
}
