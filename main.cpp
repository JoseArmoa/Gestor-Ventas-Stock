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
    //rlutil::setBackgroundColor(rlutil::GREY);rlutil::
    //rlutil::setColor(rlutil::BLACK);
    rlutil::hidecursor();
    system("color 80");
    setlocale(LC_ALL, "");
    //cout<<rlutil::getkey();
    //system("pause");
    int op;
    while(true){
    menuPrincipal();

//    op=rlutil::getkey()
        op=rlutil::getkey();
    system("cls");

        /*switch(op){
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
        }*/


        //system("pause");
        switch(op){
    case 49: //si se apreta 1
        menuVentas();

            break;
    case 50://si se apreta 2
        menuClientes();
        system("cls");
            break;
    case 51://si se apreta 3
        MenuCelulares();
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
    default: cout<<"OPCION INVALIDA. "<<endl;
            break;

        }
    }
}
