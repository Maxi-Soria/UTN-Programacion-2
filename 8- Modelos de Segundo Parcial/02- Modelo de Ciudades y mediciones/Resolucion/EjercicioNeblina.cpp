#include <iostream>
#include <cstring>
using namespace std;

#include "parcial2.h"


class PuntoA {
private:
    int codigoCiudad;
    char nombre[30];
    float promedioVisibilidad;
    bool estado;

public:
    void Mostrar() {
        cout << "Codigo de la ciudad: " << codigoCiudad << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Promedio de visibilidad: " << promedioVisibilidad << endl;
        cout << "Estado: " << (estado ? "Activo" : "Inactivo") << endl;
    }


    void setCodigoCiudad(int codigo) { codigoCiudad = codigo; }
    void setNombre(const char* n) { strcpy(nombre, n); }
    void setPromedioVisibilidad(float promedio) { promedioVisibilidad = promedio; }
    void setEstado(bool e) { estado = e; }
};

class ArchivoPuntoA {
private:
    char nombre[30];

public:
    ArchivoPuntoA() {
        strcpy(nombre, "PuntoA");
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
        if (p == NULL){return ;}
        fclose(p);
    }

    bool listarArchivo() {
        PuntoA reg;
        FILE* p = NULL;
        p = fopen(nombre, "rb");
        if (p == NULL) {return false;}
        while (fread(&reg, sizeof reg, 1, p) == 1) {
            reg.Mostrar();
            cout << endl;
        }
        fclose(p);
        return true;
    }


};



void solucionPuntoA();
void solucionPuntoB();
void solucionPuntoC(){
    int codCuidad;
    cout<<"Ingrese el codigo a buscar: ";
    cin>>codCuidad;

    ArchivoCiudades archCiud;
    Ciudades regCiud;
    int cantCiudades = archCiud.contarRegistros();

    int cont = 0;
    for (int i=0 ; i<cantCiudades ; i++ ){
        regCiud = archCiud.leerRegistro(i);
        if(regCiud.getCodigoCiudad() == codCuidad){
            cont++;
        }
    }

    Ciudades* vec = nullptr;
    vec = new Ciudades[cont];
    if(vec == nullptr){return;}

    int pos = 0;
    for (int i=0 ; i<cantCiudades ; i++ ){
        regCiud = archCiud.leerRegistro(i);
        if(regCiud.getCodigoCiudad() == codCuidad){
            vec[pos]=regCiud;
        }
    }
    for (int i=0 ; i<cont ; i++ ){
        vec[i].Mostrar();
    }
}

int main(){
    //solucionPuntoA();
    //solucionPuntoB();
    solucionPuntoC();

    //ArchivoCiudades arch;
    //arch.listarArchivo();



return 0;
}

void solucionPuntoA(){
    ArchivoCiudades archCiud;
    Ciudades regCiud;
    int cantCiud = archCiud.contarRegistros();

    ArchivoMediciones archMed;
    Mediciones regMed;
    int cantMed = archMed.contarRegistros();

    ArchivoPuntoA archPA;
    PuntoA regPA;
    archPA.vaciar();


    for (int i=0 ; i<cantCiud ; i++ ){
        regCiud = archCiud.leerRegistro(i);
        int cont = 1;
        float acum = 0;
        bool guardar = false;
        for (int j=0 ; j<cantMed; j++ ){
            regMed = archMed.leerRegistro(j);
            if(regCiud.getCodigoCiudad() == regMed.getCodigoCiudad()){
                acum += regMed.getVisibilidad();
                cont++;
                guardar = true;
            }
        }
        if(guardar){
            regPA.setCodigoCiudad(regCiud.getCodigoCiudad());
            regPA.setNombre(regCiud.getNombre());
            regPA.setPromedioVisibilidad(acum/cont);
            archPA.escribirRegistro(regPA);
        }
    }
    archPA.listarArchivo();
}

void solucionPuntoB(){
    ArchivoMediciones archMed;
    Mediciones regMed;
    int cantMed = archMed.contarRegistros();

    int mat[6][31] = {};

    for (int i=0 ; i<cantMed ; i++ ){
        regMed = archMed.leerRegistro(i);
        if(regMed.getFecha().getMes() == 5){
            mat[regMed.getVisibilidad()][regMed.getFecha().getMes()-1]++;
        }
    }
    for (int i=0 ; i<6 ; i++ ){
        cout << "Grado "<<i+1 << endl;
        for (int j=0 ; j<31 ; j++ ){
            if(mat[i][j] > 0){
                cout << " Dia "<<j+1 << " : " << mat[i][j] << endl;
            }
        }

    }
}
