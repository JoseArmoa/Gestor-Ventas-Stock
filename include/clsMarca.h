#ifndef CLSMARCA_H
#define CLSMARCA_H

#include <cstring>

class clsMarca {
private:
    char Marca[30];
    bool estado;

public:
    clsMarca(const char* m);
    clsMarca();

    void setMarca(const char*);

    void setEstado(bool);

    const char* getMarca();

    bool getEstado();

    void mostrar();

    void cargar();
};

class ArchivoMarca {
private:
    char nombreArchivo[30];

public:
    ArchivoMarca(const char *v) {
        strcpy(nombreArchivo, v);
    }

    bool Cargar(clsMarca r);

    clsMarca Leer(int pos) {
        clsMarca reg;
        FILE *p;
        p = fopen(nombreArchivo, "rb");
        if (p == NULL) return reg;
        fseek(p, sizeof(reg) * pos, 0);
        fread(&reg, sizeof reg, 1, p);
        fclose(p);
        return reg;
    }

    int contarRegistros();
    int buscarMarca(const char* _marca);
    bool modificar_registro(int, clsMarca&);
    bool borrar();
};


#endif // CLSMARCA_H

