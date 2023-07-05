#include <iostream>
#include <cstring>
using namespace std;

#include "parcial2.h"

class PuntoA {
private:
    char codigoEmpresa[6];
    char nombre[30];
    float cantToneladas;

public:
    void Cargar() {
        cout << "Codigo de empresa: ";
        cargarCadena(codigoEmpresa, 5);
        cout << "Nombre: ";
        cargarCadena(nombre, 29);
        cout << "Cantidad de toneladas: ";
        cin >> cantToneladas;
    }

    void Mostrar() {
        cout << codigoEmpresa <<"   "<< nombre <<"  "<< cantToneladas;
    }

    const char* getCodigoEmpresa() { return codigoEmpresa; }
    const char* getNombre() { return nombre; }
    float getCantToneladas() { return cantToneladas; }

    void setCodigoEmpresa(const char* codigo) { strcpy(codigoEmpresa, codigo); }
    void setNombre(const char* nomb) { strcpy(nombre, nomb); }
    void setCantToneladas(float cant) { cantToneladas = cant; }
};

class ArchivoPuntoA {
private:
    char nombre[30];

public:
    ArchivoPuntoA() {
        strcpy(nombre, "PuntoA.dat");
    }

    PuntoA leerRegistro(int pos) {
        PuntoA reg;
        reg.setCantToneladas(-1);
        FILE* p;
        p = fopen(nombre, "rb");
        if (p == NULL) return reg;
        fseek(p, sizeof(PuntoA) * pos, 0);
        fread(&reg, sizeof reg, 1, p);
        fclose(p);
        return reg;
    }

    int contarRegistros() {
        FILE* p;
        p = fopen(nombre, "rb");
        if (p == NULL) return -1;
        fseek(p, 0, 2);
        int tam = ftell(p);
        fclose(p);
        return tam / sizeof(PuntoA);
    }

    bool listarArchivo() {
        PuntoA reg;
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

    bool escribirRegistro(PuntoA reg) {
        FILE* p;
        p = fopen(nombre, "ab");
        if (p == NULL) return false;
        bool escribio = fwrite(&reg, sizeof reg, 1, p);
        fclose(p);
        return escribio;
    }
    void vaciar(){
        FILE *p = fopen(nombre, "wb");
        if (p == NULL)
        {
            return ;
        }
        fclose(p);
    }
};

void solucionPuntoA();
void solucionPuntoB();
void solucionPuntoC();

void solucionPuntoD(){
    ArchivoCosecha archCos;
    Cosecha regCos;
    int cantCos = archCos.contarRegistros();
    cout << endl;

    for (int i=0 ; i<cantCos ; i++ ){
        regCos = archCos.leerRegistro(i);
        float ton = regCos.getToneladasCosechadas();
        regCos.setToneladasCosechadas(ton*1000);
        archCos.remplazarReg(regCos,i);
    }



}


int main(){
    setlocale (LC_ALL, "Spanish");
    cout << "PUBNTO A" << endl;
    solucionPuntoA();
    cout << endl;
    cout << "PUBNTO B" << endl;
    solucionPuntoB();
    cout << endl;
    cout << "PUBNTO C" << endl;
    solucionPuntoC();
    cout << endl;
    cout << "PUBNTO D" << endl;
    //solucionPuntoD();
    cout << endl;

    return 0;
}

void solucionPuntoA(){
    ArchivoCosecha archCos;
    Cosecha regCos;
    int cantCos = archCos.contarRegistros();

    ArchivoEmpresa archEmp;
    Empresa regEmp;
    int cantEmp = archEmp.contarRegistros();

    ArchivoPuntoA archPA;
    PuntoA regPA;
    archPA.vaciar();

    for (int i=0 ; i<cantEmp ; i++ ){
        regEmp = archEmp.leerRegistro(i);
        float acumToneladas = 0;
        for (int j=0 ; j<cantCos ; j++ ){
            regCos = archCos.leerRegistro(j);
            if(strcmp(regEmp.getCodigoEmpresa(),regCos.getCodigoEmpresa()) == 0){
                acumToneladas += regCos.getToneladasCosechadas();
            }
        }
        regPA.setCodigoEmpresa(regEmp.getCodigoEmpresa());
        regPA.setNombre(regEmp.getNombre());
        regPA.setCantToneladas(acumToneladas);
        archPA.escribirRegistro(regPA);
    }

    archPA.listarArchivo();
}


void solucionPuntoB(){
    float toneladasPorMes[12]={};

    ArchivoCosecha archCos;
    Cosecha regCos;
    int cantCos = archCos.contarRegistros();

    for (int i=0 ; i<cantCos ; i++ ){
        regCos = archCos.leerRegistro(i);
        if(regCos.getCodigoCereal() == 10){
            toneladasPorMes[regCos.getFecha().getMes()-1]+= regCos.getToneladasCosechadas();
        }
    }

    float maxToneladas = 0;

    for (int i=0 ; i<cantCos ; i++ ){
        if(toneladasPorMes[i] > maxToneladas){
            maxToneladas = toneladasPorMes[i];
        }
    }
    cout << "El meses con mas ton del cereal tipo 10 es el mes: ";
    for (int i=0 ; i<cantCos ; i++ ){
        if(toneladasPorMes[i] == maxToneladas){
            cout << i+1 <<" ";
        }
    }
    cout << endl;
}


void solucionPuntoC(){

    ArchivoEmpresa archEmp;
    Empresa regEmp;
    int cantEmp = archEmp.contarRegistros();

    ArchivoCosecha archCos;
    Cosecha regCos;
    int cantCos = archCos.contarRegistros();

    PuntoA* vec = nullptr;
    vec = new PuntoA[cantEmp];
    if(vec == nullptr){
        return;
    }

    for (int i=0 ; i<cantEmp ; i++ ){
        regEmp = archEmp.leerRegistro(i);
        float acumToneladas = 0;
        for (int j=0 ; j<cantCos ; j++ ){
            regCos = archCos.leerRegistro(j);
            if(strcmp(regEmp.getCodigoEmpresa(),regCos.getCodigoEmpresa()) == 0){
                acumToneladas += regCos.getToneladasCosechadas();
            }
            vec[i].setCodigoEmpresa(regEmp.getCodigoEmpresa());
            vec[i].setNombre(regEmp.getNombre());
            vec[i].setCantToneladas(acumToneladas);
        }
    }

    ArchivoPuntoA archPA;
    archPA.vaciar();
    for (int i=0 ; i<cantEmp ; i++ ){
        archPA.escribirRegistro(vec[i]);
    }
    archPA.listarArchivo();


}




