#include "funcioneGlobales.h"
#include "rlutil.h"
#include <cctype>
#include <cstring>



void cargarCadena(char *palabra, int tamano){

    int i=0;

    fflush(stdin);

    for (i=0; i<tamano; i++){

        palabra[i]=std::cin.get();

        if (palabra[i]=='\n'){

            break;

        }

    }

    palabra[i]='\0';

    fflush(stdin);

}

void menuPrincipal() {

	std::cout << "MEN� PRINCIPAL" << std::endl;
	std::cout << "---------------------------------" << std::endl;
	std::cout << "1. VENTAS" << std::endl;
	std::cout << "2. CLIENTES" << std::endl;
	std::cout << "3. STOCK CELULARES" << std::endl;
	std::cout << "4. REPORTES" << std::endl;
	std::cout << "5. CONFIGURACI�N" << std::endl;
	std::cout << "0. SALIR" << std::endl;
	std::cout << "---------------------------------" << std::endl;
	std::cout << "INGRESE UNA OPCI�N: ";
}




