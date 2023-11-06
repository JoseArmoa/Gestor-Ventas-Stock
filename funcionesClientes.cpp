#include <iostream>
#include "clsCliente.h"
using namespace std;

bool agregarCliente(){

    clsCliente r;
    ArchivoCliente archiCliente("clientes.dat");

    int dni=0;
    cout<<"DNI: "<<endl;
    cin>>dni;

    int encontro=archiCliente.leerDni(dni);

    if(encontro >=0){
        cout<<"EL CLIENTE YA EXISTE EN EL SISTEMA. "<<endl;
        return false;
    }
    else{
        r.Cargar(dni);
        archiCliente.Cargar(r);
    }


}
