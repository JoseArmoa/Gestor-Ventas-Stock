#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;
#include "funcioneGlobales.h"
#include "clsFecha.h"
#include "clsVentas.h"
#include "funcionesVentas.h"
#include "funcionesCelulares.h"
#include "Reportes.h"
#include "Configuración.h"
#include "funcionesClientes.h"

int main()
{
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
        default:
            break;
        }
    }
}
