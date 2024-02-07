#include <iostream>
#include <cstring>

using namespace std;

#include "parcial2.h"


class Punto1 {
private:
    int codigoRestaurante;
    char nombreRestaurante[30];
    int cantidadVentas;

public:
    Punto1(){};
    Punto1(int cod, char* nomb, int vent){
        codigoRestaurante = cod;
        strcpy(nombreRestaurante,nomb);
        cantidadVentas = vent;
    }

    void Mostrar() {
        cout << codigoRestaurante << "    " << nombreRestaurante << "    " << cantidadVentas ;
    }

    int getCodigoRestautante(){return codigoRestaurante;}

    void setCodigoRestaurante(int codigo) { codigoRestaurante = codigo; }
    void setNombreRestaurante(const char* nombre) { strcpy(nombreRestaurante, nombre); }
    void setCantidadVentas(int cantidad) { cantidadVentas = cantidad; }

    bool operator == (Punto1 obj){
        if(codigoRestaurante == obj.getCodigoRestautante()) return true;
        return false;
    }
};


class ArchivoPunto1 {
private:
    char nombre[30];

public:
    ArchivoPunto1() {
        strcpy(nombre,"Punto1.dat");
    }

    bool escribirRegistro(Punto1 reg) {
        FILE* p;
        p = fopen(nombre, "ab");
        if (p == NULL) return false;
        bool escribio = fwrite(&reg, sizeof(reg), 1, p);
        fclose(p);
        return escribio;
    }

    void vaciar(){
        FILE *p = fopen(nombre, "wb");
        if (p == NULL){return ;}
        fclose(p);
    }

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

    int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Punto1);
    }
    Punto1 leerRegistro(int pos){
        Punto1 reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof(Punto1)*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
};



void solucionPunto3(){
    ArchivoPunto1 archP1;
    int cant = archP1.contarRegistros();

    Punto1 *vec = nullptr;
    vec = new Punto1[cant]{};
    if(vec == nullptr) return;

    for (int i=0 ; i<cant ; i++ ){
        vec[i] = archP1.leerRegistro(i);
    }

    archP1.listarArchivo();






}


void solucionPunto1();
void solucionPunto2();


int main(){
    setlocale (LC_ALL, "Spanish");

    char nombre1[10] = "Maxi";
    char nombre2[10] = "coco";

    Punto1 obj(15,nombre1,6) , obj2(15, nombre2, 2);


     if(obj == obj2){
        cout << "Son el mismo" << endl;
     }else{
        cout << "Nada que ver"<< endl;
     }

    solucionPunto1();
    cout << endl;
    //solucionPunto2();
    solucionPunto3();



    return 0;
}



void solucionPunto1(){
    ArchivoRestaurantes archRest("restaurantes.dat");
    Restaurante regRest;
    int cantRest = archRest.contarRegistros();

    ArchivoVentas archVent("ventas.dat");
    Venta regVentas;
    int cantVentas = archVent.contarRegistros();

    ArchivoPunto1 archP1;
    Punto1 regP1;
    archP1.vaciar();

    for (int i=0 ; i<cantRest ; i++ ){
        regRest = archRest.leerRegistro(i);
        int contador = 0;
        for (int j=0 ; j<cantVentas ; j++ ){
            regVentas = archVent.leerRegistro(j);
            if(regRest.getCodigoRestaurante() == regVentas.getCodigoRestaurante() && regRest.getCategoria() == 1 && regVentas.getFechaReserva().getAnio() == 2023){
                contador++;

            }
        }

        regP1.setCodigoRestaurante(regRest.getCodigoRestaurante());
        regP1.setNombreRestaurante(regRest.getNombre());
        regP1.setCantidadVentas(contador);
        archP1.escribirRegistro(regP1);

    }

    archP1.listarArchivo();

}


void solucionPunto2(){
    ArchivoRestaurantes archRest("restaurantes.dat");
    Restaurante regRest;
    int cantRest = archRest.contarRegistros();

    if(cantRest != -1){
        int vecProvincias[24]={};
        int MenorCantidad = 0;
        int provinciaConMenorCantidad;
        bool primero = false;

        for (int i=0 ; i<cantRest ; i++ ){
            regRest = archRest.leerRegistro(i);
            if(regRest.getCategoria() == 1){
                vecProvincias[regRest.getProvincia()-1]++;
            }
        }


        for (int i=0 ; i<24 ; i++ ){
            if(!primero){
                MenorCantidad = vecProvincias[i];
                provinciaConMenorCantidad = i;
                primero = true;
            }
            else{
                if(vecProvincias[i]<MenorCantidad){
                    MenorCantidad = vecProvincias[i];
                    provinciaConMenorCantidad = i;
                }
            }
        }
        cout << "La provincia con menor restaurantes de la categoria uno es la provincia: "<<provinciaConMenorCantidad+1 << endl;
    }
    else{
        cout << "No hay registros cargados" << endl;
    }

}
