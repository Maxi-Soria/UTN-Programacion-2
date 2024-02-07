#include <iostream>

using namespace std;
#include "parcial1.h"

class Punto1 {
private:
    int numero;
    int legajoProgramador;
    int codigoProyecto;
    int localidad;
    bool estado;

public:
    void Mostrar() {
        cout << "Número: " << numero << endl;
        cout << "Legajo del programador: " << legajoProgramador << endl;
        cout << "Código del proyecto: " << codigoProyecto << endl;
        cout << "Localidad: " << localidad << endl;
        cout << "Estado: " << (estado ? "Activo" : "Inactivo") << endl;
    }

    // Getters y setters
    void setNumero(int n) { numero = n; }
    void setLegajoProgramador(int legajo) { legajoProgramador = legajo; }
    void setCodigoProyecto(int codigo) { codigoProyecto = codigo; }
    void setLocalidad(int loc) { localidad = loc; }
    void setEstado(bool est) { estado = est; }
};

class ArchivoPunto1 {
private:
    char nombre[30];

public:
    ArchivoPunto1(const char* n) {
        strcpy(nombre, n);
    }
    ///-------------------------------------------
    bool listarArchivo() {
        Punto1 reg;
        FILE* p;
        p = fopen(nombre, "rb");
        if (p == NULL) {
            cout << "No se pudo abrir el archivo." << endl;
            return false;
        }
        while (fread(&reg, sizeof reg, 1, p) == 1) {
            reg.Mostrar();
            cout << endl;
        }
        fclose(p);
        return true;
    }
    ///---------------------------------------
    bool escribirRegistro(Punto1 reg) {
        FILE* p;
        p = fopen(nombre, "ab");
        if (p == NULL) return false;
        bool escribio = fwrite(&reg, sizeof reg, 1, p);
        fclose(p);
        return escribio;
    }
    ///-------------------------------------------
    void vaciar(){
        FILE *p = fopen(nombre, "wb");
        if (p == NULL){return ;}
        fclose(p);
    }


};

bool darBajaLogica(Programador reg, int pos){
    FILE *p = fopen("programadores.dat", "rb+");
    if (p == NULL){return false;}
    fseek(p, pos * sizeof(Programador), SEEK_SET);
    fwrite(&reg, sizeof(Programador), 1, p);
    fclose(p);
    return true;
}

void solucionPunto1();
void solucionPunto2();

int main(){
    setlocale (LC_ALL, "Spanish");


    return 0;
}

void solucionPunto1(){
    ArchivoProyecto archProy("proyectos.dat");
    Proyecto regProy, aux;
    int cantRegProy = archProy.contarRegistros();

    ArchivoAsignacion archAsig("asignaciones.dat");
    Asignacion regAsig;
    int cantRegAsign = archAsig.contarRegistros();

    ArchivoPunto1 archP1("punto1.dat");
    Punto1 regP1;
    archP1.vaciar();

    for (int i=0 ; i<cantRegProy ; i++ ){
        regProy = archProy.leerRegistro(i);
        if(strcmp(regProy.getDescripcion(),"Gestion ventas DEK SA.") == 0){
            aux = regProy;
        }
    }

    for (int i=0 ; i<cantRegAsign ; i++ ){
        regAsig = archAsig.leerRegistro(i);
        if(regAsig.getCodigoProyecto() == aux.getCodigo()){
            regP1.setNumero(regAsig.getNumero());
            regP1.setLegajoProgramador(regAsig.getLegajoProgramador());
            regP1.setCodigoProyecto(regAsig.getCodigoProyecto());
            regP1.setLocalidad(regAsig.getLocalidad());
            regP1.setEstado(regAsig.getEstado());
            archP1.escribirRegistro(regP1);
        }
    }

}


void solucionPunto2(){
    ArchivoProgramador archProg("programadores.dat");
    Programador regProg;
    int cantRegProg = archProg.contarRegistros();

    for (int i=0 ; i<cantRegProg ; i++ ){
        regProg = archProg.leerRegistro(i);
        if(regProg.getFechaIngreso().getAnio() == 2015){
            regProg.setActivo(false);
            darBajaLogica(regProg,i);
        }
    }

    for (int i=0 ; i<cantRegProg ; i++ ){
        regProg = archProg.leerRegistro(i);
        if(regProg.getActivo() == true){
            regProg.Mostrar();
        }
    }

}
