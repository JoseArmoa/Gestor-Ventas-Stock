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
	/*rchivosCelular archiCelulares("celularesValoresInicio.dat");

    // Definir algunas marcas
    clsMarca marcaSamsung("Samsung");
    clsMarca marcaApple("Apple");
    clsMarca marcaHuawei("Huawei");
    clsMarca marcaXiaomi("Xiaomi");
    clsMarca marcaSony("Sony");
    clsMarca marcaLG("LG");
    clsMarca marcaNokia("Nokia");
    clsMarca marcaMotorola("Motorola");
    clsMarca marcaOnePlus("OnePlus");
    clsMarca marcaGoogle("Google");

    // Crear un array de fechas de lanzamiento
    Fecha fechaLanzamiento[10];
    fechaLanzamiento[0] = Fecha(2021, 3, 15);
    fechaLanzamiento[1] = Fecha(2021, 3, 15);
    fechaLanzamiento[2] = Fecha(2021, 3, 15);
    fechaLanzamiento[3] = Fecha(2021, 3, 15);
    fechaLanzamiento[4] = Fecha(2021, 3, 15);
    fechaLanzamiento[5] = Fecha(2021, 3, 15);
    fechaLanzamiento[6] = Fecha(2021, 3, 15);
    fechaLanzamiento[7] = Fecha(2021, 3, 15);
    fechaLanzamiento[8] = Fecha(2021, 3, 15);
    fechaLanzamiento[9] = Fecha(2021, 3, 15);

    // Crear y cargar un celular para cada marca
    clsCelular celulares[10];

    celulares[0] = clsCelular("Galaxy S21", "Samsung Galaxy S21", &marcaSamsung, fechaLanzamiento[0], 899.99, 10);
	celulares[1] = clsCelular("iPhone 13", "Apple iPhone 13", &marcaApple, fechaLanzamiento[1], 999.99, 15);
	celulares[2] = clsCelular("P40", "Huawei P40", &marcaHuawei, fechaLanzamiento[2], 699.99, 8);
	celulares[3] = clsCelular("Mi 11", "Xiaomi Mi 11", &marcaXiaomi, fechaLanzamiento[3], 799.99, 12);
	celulares[4] = clsCelular("Xperia 5", "Sony Xperia 5", &marcaSony, fechaLanzamiento[4], 799.99, 7);
	celulares[5] = clsCelular("G8", "LG G8", &marcaLG, fechaLanzamiento[5], 799.99, 7);
	celulares[6] = clsCelular("Nokia 9", "Nokia 9", &marcaNokia, fechaLanzamiento[6], 699.99, 8);
	celulares[7] = clsCelular("Moto G7", "Motorola Moto G7", &marcaMotorola, fechaLanzamiento[7], 599.99, 10);
	celulares[8] = clsCelular("OnePlus 8", "OnePlus 8", &marcaOnePlus, fechaLanzamiento[8], 799.99, 12);
	celulares[9] = clsCelular("Pixel 5", "Google Pixel 5", &marcaGoogle, fechaLanzamiento[9], 699.99, 8);


    for (int i = 0; i < 10; i++) {
        archiCelulares.Cargar(celulares[i]);
    }

    // Leer y mostrar los celulares desde el archivo
    int numCelulares = archiCelulares.contarRegistros();
    for (int i = 0; i < numCelulares; i++) {
        clsCelular reg = archiCelulares.Leer(i);
        reg.mostrar();
        std::cout << "\n";
    }
	return 0;
	*/
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
        default:
            break;
        }
    }
}
