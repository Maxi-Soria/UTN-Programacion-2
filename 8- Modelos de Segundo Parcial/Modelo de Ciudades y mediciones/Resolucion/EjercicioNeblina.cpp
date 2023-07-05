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
    void Cargar() {
        cout << "Ingrese el código de la ciudad: ";
        cin >> codigoCiudad;
        cout << "Ingrese el nombre: ";
        cargarCadena(nombre, 29);
        cout << "Ingrese el promedio de visibilidad: ";
        cin >> promedioVisibilidad;
        estado = true;
    }

    void Mostrar() {
        cout << "Codigo de la ciudad: " << codigoCiudad << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Promedio de visibilidad: " << promedioVisibilidad << endl;
        cout << "Estado: " << (estado ? "Activo" : "Inactivo") << endl;
    }

    int getCodigoCiudad() { return codigoCiudad; }
    const char* getNombre() { return nombre; }
    float getPromedioVisibilidad() { return promedioVisibilidad; }
    bool getEstado() { return estado; }

    void setCodigoCiudad(int codigo) { codigoCiudad = codigo; }
    void setNombre(const char* n) { strcpy(nombre, n); }
    void setPromedioVisibilidad(float promedio) { promedioVisibilidad = promedio; }
    void setEstado(bool e) { estado = e; }
};

class ArchivoPuntoA {
private:
    char nombre[30];

public:
    ArchivoPuntoA(const char* n) {
        strcpy(nombre, n);
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

};



void solucionPuntoA();
void solucionPuntoB();

int main(){
    //solucionPuntoA();
    solucionPuntoB();


return 0;
}

void solucionPuntoA(){
    ArchivoCiudades archCiud;
    Ciudades regCiud;
    int cantCiud = archCiud.contarRegistros();

    ArchivoMediciones archMed;
    Mediciones regMed;
    int cantMed = archMed.contarRegistros();

    ArchivoPuntoA archPA("puntoA.dat");
    PuntoA regPA;
    archPA.vaciar();


    for (int i=0 ; i<cantCiud ; i++ ){
        regCiud = archCiud.leerRegistro(i);
        int cont = 0;
        float acum = 0;
        for (int j=0 ; j<cantMed; j++ ){
            regMed = archMed.leerRegistro(j);
            if(regCiud.getCodigoCiudad() == regMed.getCodigoCiudad()){
                acum += regMed.getVisibilidad();
                cont++;
            }
        }
        regPA.setCodigoCiudad(regCiud.getCodigoCiudad());
        regPA.setNombre(regCiud.getNombre());
        regPA.setPromedioVisibilidad(acum/cont);
        regPA.Mostrar();
        archPA.escribirRegistro(regPA);
    }

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
    system("pause");
    for (int i=0 ; i<6 ; i++ ){
        cout << "Grado "<<i+1 << endl;
        for (int j=0 ; j<31 ; j++ ){
            if(mat[i][j] > 0){
                cout << " Dia "<<j+1 << " : " << mat[i][j] << endl;
            }
        }

    }
}
