#include <iostream>
#include <cstdlib>
using namespace std;
#include "Reportes.h"
#include "rlutil.h"


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
	cout << left;
	cout << setw(7)  << "MODELO";
	cout << setw(7) << "NOMBRE";
	cout << setw(18) << "         FECHA LANZ.";
	cout << setw(6)  << "  MARCA";
	cout << setw(7)  << "     PRECIO";
	cout << setw(6) << "    STOCK" << endl;
	cout<<"-------------------------------------------------------------"<<endl;
    for (int i = 0; i < tam; i++) {
        clsCelular reg = Archi.Leer(i);
        if (reg.getStock() <= num && reg.getEstado()) {
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
	system("cls");
	for (int i=0;i<pos_reg;i++){
		clsVentas reg = archi_venta.Leer(i);
		if (reg.getDniCliente()==dni && reg.getEstado()){
			if (!estado){
				cout<<"-------------------------------------------------------------"<<endl;
			}
			cout <<"\n";
			estado=true;
			reg.Mostrar();
			cout<<"-------------------------------------------------------------"<<endl;
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
                cout<<"TOTAL FACTURADO EN EL PERIODO INGRESADO: $"<<totalFacturado<<endl;
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
        if(r.getEstado()){
        pos=r1.buscarCelular(r.getModelo());
        vecContador[pos]++;
        }
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
    cout<<"EL MODELO M�S VENDIDO ES EL "<<rCelular.getModelo();
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
                if(rVentas.getFecha() == dia && rVentas.getEstado()){
                    totalFacturado += rVentas.getTotal();
                }
            }
            if(totalFacturado>0){
                cout<<"TOTAL FACTURA: $"<<totalFacturado<<endl;
            }else{
                cout<<"NO SE REGISTRA FACTURACION"<<endl;
            }
        }else{
            cout<<"FECHA INVALIDA"<<endl;
        }
    }else{
        cout<<"FECHA INVALIDA"<<endl;
    }
}
void menuReporte() {
    rlutil::setConsoleTitle("REPORTES");
    int opcion;
    system("cls");
    while(true){
        cout << "MEN� REPORTES" << endl;
        cout << "----------------------------"<<endl;
        cout << "1. DADO UN NUMERO ENTERO, DEVOLVER PRODUCTOS CON STOCK INFERIOR O IGUAL A ESE NUMERO" << endl;
        cout << "2. MOSTRAR TOTAL FACTURADO POR PERIODO" << endl;//Recibe 2 fechas y muestra el total facturado en ese periodo.
        cout << "3. MOSTRAR CELULARES QUE COMPRO UN CLIENTE" << endl;
        cout << "4. MOSTRAR MODELO CELULAR MAYOR SE VENDE" << endl;
        cout << "5. FACTURADO POR DIA" << endl;
        cout << "0. SALIR" << endl;
        cout << "----------------------------"<<endl;
        cout << "SELECCIONA UNA OPCI�N: ";
        opcion=rlutil::getkey();
       system("cls");
        switch(opcion){
    case 49: //si se apreta 1
            punto_1();
            break;
    case 50://si se apreta 2
            punto_2();
            break;
    case 51://si se apreta 3
            punto_3();
        	break;
    case 52://si se apreta 4
			punto_4();
        	break;
    case 53://si se apreta 5
            punto_5();
		break;
    case 48://si se apreta 0
        return;
    default: std::cout<<"OPCI�N INVALIDA. "<<std::endl;
            break;
        }
       system("pause");
       system("cls");
    }
}

