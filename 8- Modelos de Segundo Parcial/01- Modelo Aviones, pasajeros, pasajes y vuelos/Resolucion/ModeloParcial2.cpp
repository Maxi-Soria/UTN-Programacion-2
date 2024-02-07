#include <iostream>
#include <cstring>

using namespace std;
#include "parcial2.h"

class Punto1 {
private:
    int numeroPasajero;
    char nombre[30];
    char telefono[30];
    char direccion[30];
    int provincia;
    bool activo;

public:
    void Cargar() {
        cout << "Número de pasajero: ";
        cin >> numeroPasajero;
        cout << "Nombre: ";
        cargarCadena(nombre, 29);
        cout << "Teléfono: ";
        cargarCadena(telefono, 29);
        cout << "Dirección: ";
        cargarCadena(direccion, 29);
        cout << "Provincia: ";
        cin >> provincia;
        cout << "Activo (1: Sí, 0: No): ";
        cin >> activo;
    }

    void Mostrar() {
        cout << numeroPasajero << "  " << nombre <<  "  " << telefono << "  " << direccion << "  " << provincia << "  " << activo;
    }

    int getNumeroPasajero() { return numeroPasajero; }
    const char* getNombre() { return nombre; }
    const char* getTelefono() { return telefono; }
    const char* getDireccion() { return direccion; }
    int getProvincia() { return provincia; }
    bool getActivo() { return activo; }

    void setNumeroPasajero(int numero) { numeroPasajero = numero; }
    void setNombre(const char* nomb) { strcpy(nombre, nomb); }
    void setTelefono(const char* tel) { strcpy(telefono, tel); }
    void setDireccion(const char* dir) { strcpy(direccion, dir); }
    void setProvincia(int prov) { provincia = prov; }
    void setActivo(bool act) { activo = act; }
};

class ArchivoPunto1 {
private:
    char nombre[30];

public:
    ArchivoPunto1() {
        strcpy(nombre, "Punto1.dat");
    }

    bool escribirRegistro(Punto1 reg) {
        FILE* p;
        p = fopen(nombre, "ab");
        if(p == NULL) return false;
        bool escribio = fwrite(&reg, sizeof reg, 1, p);
        fclose(p);
        return escribio;
    }

    Punto1 leerRegistro(int pos) {
        Punto1 reg;
        reg.setNumeroPasajero(-1);
        FILE* p;
        p = fopen(nombre, "rb");
        if (p == NULL) return reg;
        fseek(p, sizeof(Punto1) * pos, 0);
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
        return tam / sizeof(Punto1);
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

    bool modificarRegistro(Punto1 obj, int nroReg) {
        FILE* p = fopen(nombre, "rb+");
        if (p == NULL) {
            return false;
        }
        fseek(p, nroReg * sizeof(Punto1), SEEK_SET);
        bool ok = fwrite(&obj, sizeof(Punto1), 1, p);
        fclose(p);
        return ok;
    }

    void vaciar(){
        FILE *p = fopen(nombre, "wb");
        if (p == NULL){return ;}
        fclose(p);
    }
};

bool modificarRegistro(Avion obj, int nroReg) {
    FILE* p = fopen("aviones.dat", "rb+");
    if (p == NULL) {
        return false;
    }
    fseek(p, nroReg * sizeof(Avion), SEEK_SET);
    bool ok = fwrite(&obj, sizeof(Avion), 1, p);
    fclose(p);
    return ok;
}

class Punto6 {
private:
    int codigoAvion;
    int cantidadVuelos;
    char nombre[30];

public:
    void Cargar() {
        cin >> codigoAvion;
        cin >> cantidadVuelos;
        cargarCadena(nombre, 29);
    }

    void Mostrar() {
        cout << "Código de Avión: " << codigoAvion << endl;
        cout << "Cantidad de Vuelos: " << cantidadVuelos << endl;
        cout << "Nombre: " << nombre << endl;
    }


    int getCodigoAvion() {return codigoAvion;}
    int getCantidadVuelos() {return cantidadVuelos;}
    const char* getNombre() {return nombre;}

    void setCodigoAvion(int codigo) {codigoAvion = codigo;}
    void setCantidadVuelos(int cantidad) {cantidadVuelos = cantidad;}
    void setNombre(const char* nuevoNombre) {strcpy(nombre, nuevoNombre);}
};

class ArchivoPunto6 {
private:
    char nombre[30];

public:
    ArchivoPunto6() {
        strcpy(nombre, "punto6.dat");
    }

    Punto6 leerRegistro(int pos) {
        Punto6 reg;
        reg.setCodigoAvion(-1);
        FILE* p;
        p = fopen(nombre, "rb");
        if (p == NULL)
            return reg;
        fseek(p, sizeof(Punto6) * pos, 0);
        fread(&reg, sizeof reg, 1, p);
        fclose(p);
        return reg;
    }

    int contarRegistros() {
        FILE* p;
        p = fopen(nombre, "rb");
        if (p == NULL)
            return -1;
        fseek(p, 0, 2);
        int tam = ftell(p);
        fclose(p);
        return tam / sizeof(Punto6);
    }

    bool listarArchivo() {
        Punto6 reg;
        FILE* p;
        p = fopen(nombre, "rb");
        if (p == NULL) {
            cout << "No se pudo abrir el archivo" << endl;
            return false;
        }
        while (fread(&reg, sizeof reg, 1, p) == 1) {
            reg.Mostrar();
            cout << endl;
        }
        fclose(p);
        return true;
    }

    bool escribirRegistro(Punto6 reg) {
        FILE* p;
        p = fopen(nombre, "ab");
        if (p == NULL)
            return false;
        bool escribio = fwrite(&reg, sizeof reg, 1, p);
        fclose(p);
        return escribio;
    }
};




void solucionPunto1();
void solucionPunto2();
void solucionPunto3();
void solucionPunto5();
void solucionPunto6();
void solucionPunto7();
void solucionPunto10();

int main(){
    setlocale (LC_ALL, "Spanish");


    ArchivoAvion archAvion;
    ArchivoVuelo archVuelo;
    ArchivoPasajes archPasaje;

    cout << "AVION"<<endl;
    archAvion.listarArchivo();

    cout << endl <<endl;

    cout << "PASAJES"<<endl;
    archPasaje.listarArchivo();

    cout << endl <<endl;

    cout << "VUELO"<<endl;
    archVuelo.listarArchivo();


    return 0;

    cout << "PUNtO 1" << endl;
    solucionPunto1();
    /*cout << endl<< "PUNTO 2" << endl;
    //solucionPunto2();
    ArchivoAvion obj;
    obj.listarArchivo();
    cout << endl << "PUNTO 3" << endl;
    solucionPunto3();
    cout << endl << "PUNTO 5" << endl;
    solucionPunto5();
    cout << endl << "PUNTO 6" << endl;
    solucionPunto6();
    solucionPunto7();
    solucionPunto10();

*/


    return 0;
}


void solucionPunto1(){
    ArchivoPasajeros archPas("pasajeros.dat");
    Pasajero regPas;
    int cant = archPas.contarRegistros();

    ArchivoPasajes archPasaje;
    Pasaje regPasaje;
    int cantPasajes = archPasaje.contarRegistros();

    ArchivoPunto1 archP1;
    Punto1 regP1;
    archP1.vaciar();

    for (int i=0 ; i<cant ; i++ ){
        regPas = archPas.leerRegistro(i);
        bool compro = false;
        for (int j=0 ; j<cantPasajes ; j++ ){
            regPasaje = archPasaje.leerRegistro(j);
            if(regPas == regPasaje && regPasaje.getFechaCompra().getAnio() == 2022){
                compro = true;
            }

        }
        if(!compro){
            regP1.setNumeroPasajero(regPas.getNumeroPasajero());
            regP1.setNombre(regPas.getNombre());
            regP1.setTelefono(regPas.getTelefono());
            regP1.setDireccion(regPas.getDireccion());
            regP1.setProvincia(regPas.getProvincia());
            regP1.setActivo(regPas.getActivo());
            archP1.escribirRegistro(regP1);
        }
    }
    archP1.listarArchivo();
}


void solucionPunto2(){
    ArchivoAvion archAviones;
    Avion regAvion;
    int cant = archAviones.contarRegistros();
    archAviones.listarArchivo();
    cout << endl<<endl;

    for (int i=0 ; i<cant ; i++ ){
        regAvion = archAviones.leerRegistro(i);
        if(strcmp(regAvion.getMarca(),"Boeing") == 0){
            regAvion.setCantidadAsientos(regAvion.getCantidadAsientos()*0.95);
            modificarRegistro(regAvion,i);
        }
    }
    archAviones.listarArchivo();


}

void solucionPunto3(){

    ArchivoAvion archAviones;
    Avion regAviones;
    int cantRegAviones = archAviones.contarRegistros();

    int cant = 0;

    for (int i=0 ; i<cantRegAviones ; i++ ){
        regAviones = archAviones.leerRegistro(i);
        if(regAviones.getTipo() == 1){
            cant++;
        }
    }


    Avion* vec = nullptr;
    vec = new Avion[cant];
    if(vec == nullptr)return;

    int pos = 0;
    for (int i=0 ; i<cantRegAviones ; i++ ){
        regAviones = archAviones.leerRegistro(i);

        if(regAviones.getTipo() == 1){
            vec[pos].setCodigoAvion(regAviones.getCodigoAvion());
            vec[pos].setNombre(regAviones.getNombre());
            vec[pos].setMarca(regAviones.getMarca());
            pos++;

        }
    }

    for (int i=0 ; i<cant ; i++ ){
        cout << vec[i].getCodigoAvion() << "    " << vec[i].getNombre()<< "     " << vec[i].getMarca() << endl;
    }


}

void solucionPunto5(){

    ArchivoPasajeros archPas("pasajeros.dat");
    Pasajero regPas;
    int cant = archPas.contarRegistros();

    ArchivoPasajes archPasaje;
    Pasaje regPasaje;
    int cantPasajes = archPasaje.contarRegistros();

    ArchivoPasajeros archP5("Punto5.dat");
    archP5.vaciar();

    for (int i=0 ; i<cant ; i++ ){
        regPas = archPas.leerRegistro(i);
        bool comproEn2022 = false;
        for (int j=0 ; j<cantPasajes; j++ ){
            regPasaje = archPasaje.leerRegistro(j);
            if(regPas.getNumeroPasajero() == regPasaje.getNumeroPasajero() && regPasaje.getFechaCompra().getAnio() == 2022){
                comproEn2022 = true;
            }

        }
        if(comproEn2022){
            archP5.escribirRegistro(regPas);
        }
    }
    archP5.listarArchivo();

}

void solucionPunto6(){
    ArchivoAvion archAvion;
    Avion regAvion;
    int cantAviones = archAvion.contarRegistros();

    ArchivoVuelo archVuelo;
    Vuelo regVuelo;
    int cantVuelos = archVuelo.contarRegistros();

    ArchivoPasajes archPasaje;
    Pasaje regPasaje;
    int cantPasajes = archPasaje.contarRegistros();

    ArchivoPunto6 archP6;
    Punto6 regP6;

    for (int i=0 ; i<cantAviones ; i++ ){
        regAvion = archAvion.leerRegistro(i);

        int contador = 0;
        for (int j=0 ; j<cantPasajes ; j++ ){
            regPasaje = archPasaje.leerRegistro(j);
            bool band = false;
            for (int k=0 ; k<cantVuelos ; k++ ){
                regVuelo = archVuelo.leerRegistro(k);
                if(regAvion.getCodigoAvion() == regPasaje.getCodigoAvion() && strcmp(regPasaje.getCodigoVuelo(),regVuelo.getCodigoVuelo()) == 0 ){
                    band = true;
                }
            }
            if(band){
                contador++;
            }

        }
        regP6.setCodigoAvion(regAvion.getCodigoAvion());
        regP6.setNombre(regAvion.getNombre());
        regP6.setCantidadVuelos(contador);
        archP6.escribirRegistro(regP6);
    }
}


void solucionPunto7(){
    ArchivoPunto6 archP6;
    Punto6 regP6;

    int cant = archP6.contarRegistros();

    Punto6* vec = nullptr;
    vec = new Punto6[cant];
    if(vec==nullptr){return;}

    for (int i=0 ; i<cant ; i++ ){
        regP6 = archP6.leerRegistro(i);
        vec[i]=regP6;
    }

    for (int i=0 ; i<cant ; i++ ){
        vec[i].Mostrar();
    }

}

void solucionPunto10(){
    ArchivoAvion archAvion;
    Avion regAvion;
    int cant = archAvion.contarRegistros();

    int cont = 0;

    for (int i=0 ; i<cant ; i++ ){
        regAvion = archAvion.leerRegistro(i);
        if(regAvion.getTipo() == 5){
            cont++;
        }
    }

    Avion* vec = nullptr;
    vec = new Avion[cont];
    if(vec == nullptr){return;}


    int pos = 0;
    for (int i=0 ; i<cant ; i++ ){
        regAvion = archAvion.leerRegistro(i);
        if(regAvion.getTipo() == 5){
            vec[pos] = regAvion;
            pos++;
        }
    }

    for (int i=0 ; i<cont ; i++ ){
        vec[i].Mostrar();
    }
}
