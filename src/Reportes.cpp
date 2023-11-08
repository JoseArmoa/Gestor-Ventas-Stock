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
    cout << "Ingrese el número entero: ";
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

}
void punto_2(){
    Fecha desde, hasta;
    clsVentas rVentas;
    ArchivosVentas archiVentas("ventas.dat");
    int tam = archiVentas.contarRegistros();
    cout<<"INGRESE DESDE: "<<endl;
    desde.Cargar();
}

void menuReporte() {
    int opcion;
    do {
        cout << "Menú de Reportes" << endl;
        cout << "----------------------------"<<endl;
        cout << "1. DADO UN NUMERO ENTERO, DEVOLVER PRODUCTOS CON STOCK INFERIOR A ESE NUMERO" << endl;
        cout << "2. MOSTRAR TOTAL FACTURADO POR PERIODO" << endl;//Recibe 2 fechas y muestra el total facturado en ese periodo.
        cout << "3. CREAR ARCHIVO CLIENTE CON LOS CELULARES QUE COMPRO" << endl;
        cout << "4. MOSTRAR CELULARES QUE COMPRO UN CLIENTE" << endl;
        cout << "5. MOSTRAR MODELO CELULAR MAYOR SE VENDE" << endl;
        cout << "6. Reporte 6" << endl;
        cout << "0. Salir" << endl;
        cout << "----------------------------"<<endl;
        cout << "Selecciona una opción: ";

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
                cout << "Generando Reporte 3..." << endl;

                break;
            case 4:

            /*char  n[30];
            strcpy(n,r.getNombre());
            strcat(n,".dat");
            ArchivoCliente archi(n);*/
                cout << "Generando Reporte 4..." << endl;

                break;
            case 5:
                cout << "Generando Reporte 5..." << endl;

                break;
            case 6:
                cout << "Generando Reporte 6..." << endl;

                break;
        }
    } while (true);
}

