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
			cout << "MODELO: " << modelo << endl;
			cout << "NOMBRE: " << nombre << endl;
			cout << "MARCA: " << marca << endl;
			Fecha_compra.Mostrar();
			cout << "PRECIO: " << precio << endl;
		}
	}
void punto_1() {
    ArchivosCelular Archi("celulares.dat");
    int tam = Archi.contarRegistros();
    int num;
    cout << "INGRESE EL NUMERO ENTERO: ";
    cin >> num;
    bool estado=false;
    for (int i = 0; i < tam; i++) {
        clsCelular reg = Archi.Leer(i);
        if (reg.getStock() <= num) {
            estado = true;
            reg.mostrar();
            cout << endl;
        }
    }
    if (!estado) {
        cout << "NO HAY REGISTROS BAJO ESE STOCK" << endl;
    }
}
void punto_3(){
	ArchivosVentas archi_venta("ventas.dat");
	ArchivoCliente archi_cliente("clientes.dat");
	int pos_reg=archi_venta.contarRegistros();
	int dni;
	bool estado=false;
	cout<<"INGRESE EL DNI DEL CLIENTE: ";
	cin >> dni;
	for (int i=0;i<pos_reg;i++){
		clsVentas reg = archi_venta.Leer(i);
		if (reg.getDniCliente()==dni){
			estado=true;
			reg.Mostrar();
		}
	}
	if (!estado){
		cout <<"NO HAY ARCHIVOS"<<endl;
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
    desdeB=desde.Cargar();
    cout<<"INGRESE HASTA: "<<endl;
    hastaB=hasta.Cargar();
    if(desdeB && hastaB){//Verifico que no se carguen fechas incoherentes
        if(desde < hasta && hasta <= hoy){//Verifico que la fecha este cargada en orden y no sea mayor al dia actual.
            for(int i=0;i<tam;i++){
                rVentas = archiVentas.Leer(i);
                if(rVentas.getFecha()>= desde && rVentas.getFecha() <= hasta && rVentas.getEstado()){
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
void ponerEnCero(int *v,int tam){
    for(int i=0;i<tam;i++){
        v[i]=0;
    }
}
//MOSTRAR MODELO CELULAR MAYOR SE VENDE. mostrar modelo de celulasr mas vendido
void punto_4(){

    ArchivosCelular r1("celulares.dat");
    celularVendido r;
    clsCelular rCelular;
    ArchivoCelularVendido archiCelVendido("vendidos.dat");

    int *vecContador;

    vecContador = new int[r1.contarRegistros()];
    if(vecContador==NULL){
        cout<<"ERROR";
        system("pause");
    }
    ponerEnCero(vecContador,r1.contarRegistros());

    int pos;
    for(int i=0; i<archiCelVendido.contarRegistros(); i++){
        r = archiCelVendido.Leer(i);
        pos=r1.buscarCelular(r.getModelo());
        vecContador[pos]++;
    }

    int mayor=vecContador[0]; //guarda la cantidad de veces q se vendio un celular
    int posMayor=0; //guarda en q posicion del array se encuentra el modelo mas vendido
    for(int i=1; i<archiCelVendido.contarRegistros(); i++){
        if(vecContador[i]>mayor){
            posMayor=i;
            mayor = vecContador[i];
        }
    }
    delete [] vecContador;
    rCelular=r1.Leer(posMayor);
    cin.ignore();
    cout<<"EL MODELO MAS VENDIDO ES EL "<<rCelular.getModelo();
    cout<<" CON "<<mayor<<" VENTAS."<<endl;
}
void punto_5(){//Dada una fecha, mostrar el total facturado ese dia, informar si no se facturo nada.
    Fecha dia,hoy;
    clsVentas rVentas;
    float totalFacturado = 0;
    ArchivosVentas archiVentas("ventas.dat");
    int tam = archiVentas.contarRegistros();
    cout<<"INGRESE DIA: "<<endl;
    if(dia.Cargar()){
        if(dia <= hoy && rVentas.getEstado()){
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
        cout << "MENU REPORTES" << endl;
        cout << "----------------------------"<<endl;
        cout << "1. DADO UN NUMERO ENTERO, DEVOLVER PRODUCTOS CON STOCK INFERIOR A ESE NUMERO" << endl;
        cout << "2. MOSTRAR TOTAL FACTURADO POR PERIODO" << endl;//Recibe 2 fechas y muestra el total facturado en ese periodo.
        cout << "3. MOSTRAR CELULARES QUE COMPRO UN CLIENTE" << endl;
        cout << "4. MOSTRAR MODELO CELULAR MAYOR SE VENDE" << endl;
        cout << "5. FACTURADO POR DIA" << endl;
        cout << "0. Salir" << endl;
        cout << "----------------------------"<<endl;
        cout << "Selecciona una opción: ";

        cin >> opcion;
        switch (opcion) {
            case 0:
                system("cls");
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
                break;
            case 4:
                punto_4();
                break;
            case 5:
                punto_5();
                break;
            default: cout<<"OPCION INVALIDA. "<<endl;
                break;
        }
        system("pause");
        system("cls");
    } while (true);
}

