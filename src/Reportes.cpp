#include <iostream>
#include <cstdlib>
using namespace std;
#include "Reportes.h"


	void celular_cliente::setModelo(char* cadena){
        strcpy(modelo, cadena);
    }

    void celular_cliente::setNombre(char* cadena){
        strcpy(nombre, cadena);
    }
    void celular_cliente::setMarca(int m){
        marca=m;
    }
    void celular_cliente::setFecha_compra(Fecha f){
        Fecha_compra=f;
    }
    void celular_cliente::setPrecio(float p){
        precio=p;
    }
    void celular_cliente::setEstado(bool e){
		estado=e;
    }
	void celular_cliente::mostrar() {
		if (getEstado()){
			cout << "Modelo: " << modelo << endl;
			cout << "Nombre: " << nombre << endl;
			cout << "Marca: " << marca << endl;
			Fecha_compra.Mostrar();
			cout << "Precio: " << precio << endl;
		}
	}
void punto_1() {
    ArchivosCelular Archi("celulares.dat");
    int tam = Archi.contarRegistros();
    int num;
    cout << "Ingrese el n�mero entero: ";
    cin >> num;
    bool estado=false;
    for (int i = 0; i < tam; i++) {
        clsCelular reg = Archi.Leer(i);
        if (reg.getStock() <= num) {
            estado = true;
            reg.mostrar();
        }
    }
    if (!estado) {
        cout << "No hay registros bajo ese stock" << endl;
    }
}
void punto_3(){
	ArchivosVentas archi_venta("ventas.dat");
	ArchivoCliente archi_cliente("clientes.dat");
	int pos_reg=archi_venta.contarRegistros();
	int dni;
	bool estado=false;
	cout<<"Ingrese el dni del cliente";
	cin >> dni;
	for (int i=0;i<pos_reg;i++){
		clsVentas reg = archi_venta.Leer(i);
		if (reg.getDniCliente()==dni){
			estado=true;
			reg.Mostrar();
		}
	}
	if (!estado){
		cout <<"No hay archivos"<<endl;
	}
}
void punto_2(){
    Fecha desde, hasta,hoy;
    clsVentas rVentas;
    float totalFacturado = 0;
    ArchivosVentas archiVentas("ventas.dat");
    int tam = archiVentas.contarRegistros();
    bool desdeB, hastaB;
    cout<<"INGRESE DESDE: "<<endl;
    desde.Cargar();
    cout<<"INGRESE HASTA: "<<endl;
    hasta.Cargar();
    if(desdeB && hastaB){//Verifico que no se carguen fechas incoherentes
        if(desde < hasta && hasta <= hoy){//Verifico que la fecha este cargada en orden y no sea mayor al dia actual.
            for(int i=0;i<tam;i++){
                rVentas = archiVentas.Leer(i);
                if(rVentas.getFecha()>= desde && rVentas.getFecha() <= hasta){
                    totalFacturado += rVentas.getTotal();
                }
            }
            if(totalFacturado > 0){
                cout<<"TOTAL FACTURA EN EL PERIODO INGRESADO: $"<<totalFacturado<<endl;
            }else{
                cout<<"NO SE REGISTRA FACTURACION"<<totalFacturado<<endl;
            }
        }else{
            cout<<"EL PERIODO DE TIEMPO ES INCORRECTO"<<endl;
        }
    }else{
        cout<<"FECHAS INVALIDAS"<<endl;
    }
}

//MOSTRAR MODELO CELULAR MAYOR SE VENDE. mostrar modelo de celulasr mas vendido
void punto_5(){

    ArchivosCelular r1("Celulares.dat");
    celularVendido r;
    ArchivoCelularVendido archiCelVendido("vendidos.dat");

    int *vecContador;

    vecContador = new int[r1.contarRegistros()];
    vecContador = {};

    int pos;
    for(int i=0; i<archiCelVendido.contarRegistros(); i++){
        r = archiCelVendido.Leer(i);
        pos=r1.buscarCelular(r.getModelo());
        vecContador[pos]++;
    }

    int mayor=0; //guarda la cantidad de veces q se vendio un celular
    int posMayor=0; //guarda en q posicion del array se encuentra el modelo mas vendido

    for(int i=0; i<archiCelVendido.contarRegistros(); i++){
        if(vecContador[i]>mayor){
            posMayor=i;
        }
    }

    r=archiCelVendido.Leer(posMayor);
    cout<<"EL MODELO MAS VENDIDO ES EL "<<r.getModelo()<<endl;



    delete [] vecContador;
    vecContador=NULL;
    //tendria q hacer una enumerador con los modelos y q un numero represente a cada modelo o agregarle a la clase celular un codigo para cada modelo


}
void punto_6(){//Dada una fecha, mostrar el total facturado ese dia, informar si no se facturo nada.
    Fecha dia,hoy;
    clsVentas rVentas;
    float totalFacturado = 0;
    ArchivosVentas archiVentas("ventas.dat");
    int tam = archiVentas.contarRegistros();
    cout<<"INGRESE DIA: "<<endl;
    if(dia.Cargar()){
        if(dia <= hoy){
            for(int i=0;i<tam;i++){
                rVentas = archiVentas.Leer(i);
                if(rVentas.getFecha() == dia){
                    totalFacturado += rVentas.getTotal();
                }
            }
            if(totalFacturado>0){
                cout<<"TOTAL FACTURA: $"<<totalFacturado<<endl;
            }else{
                cout<<"NO SE REGISTRA FACTURACION"<<endl;
            }
        }
    }else{
        cout<<"FECHA INVALIDA"<<endl;
    }
}
void menuReporte() {
    int opcion;
    do {
        cout << "Men� de Reportes" << endl;
        cout << "----------------------------"<<endl;
        cout << "1. DADO UN NUMERO ENTERO, DEVOLVER PRODUCTOS CON STOCK INFERIOR A ESE NUMERO" << endl;
        cout << "2. MOSTRAR TOTAL FACTURADO POR PERIODO" << endl;//Recibe 2 fechas y muestra el total facturado en ese periodo.
        cout << "3. MOSTRAR CELULARES QUE COMPRO UN CLIENTE" << endl;
        cout << "5. MOSTRAR MODELO CELULAR MAYOR SE VENDE" << endl;
        cout << "6. FACTURADO POR DIA" << endl;
        cout << "0. Salir" << endl;
        cout << "----------------------------"<<endl;
        cout << "Selecciona una opci�n: ";

        cin >> opcion;
        switch (opcion) {
            case 0:
                cout << "Saliendo del programa." << endl;
                return;
            case 1:
				punto_1();
                break;
            case 2:
                punto_2();
            //DADA DOS FECHAS, DEVOLVER EL TOTAL FACTURADO EN ESE RANGO DE TIEMPO
                break;
            case 3:
            	punto_3();
				break;
            /*char  n[30];
            strcpy(n,r.getNombre());
            strcat(n,".dat");
            ArchivoCliente archi(n);*/
                cout << "Generando Reporte 4..." << endl;

                break;
            case 5:
                punto_5();
                break;
            case 6:
                punto_6();
                cout << "Generando Reporte 6..." << endl;

                break;
        }
        system("pause");
        system("cls");
    } while (true);
}

