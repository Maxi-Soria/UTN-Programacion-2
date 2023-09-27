#include <iostream>
#include <cstdlib>
#include "ModeloParcial.h"

using namespace std;

class PuntoA{
private:
    int _codigoSorteo;
    int _numeroGanador;
    int _mesSorteo;
    int _codigoProvincia;
public:
    void Mostrar(){
        cout << "Codigo de sorteo: " << _codigoSorteo << endl;
        cout << "Numero Ganador: " << _numeroGanador << endl;
        cout << "Mes del Sorteo: " << _mesSorteo << endl;
        cout << "Codigo de provincia: " << _codigoProvincia << endl;
        cout << endl;
    }

    void setCodigoSorteo(int codigoSorteo) { _codigoSorteo = codigoSorteo; }
    void setNumeroGanador(int numeroGanador) { _numeroGanador = numeroGanador; }
    void setMesSorteo(int mesSorteo) { _mesSorteo = mesSorteo; }
    void setCodigoProvincia(int codigoProvincia) { _codigoProvincia = codigoProvincia; }
};

class ArchivoPuntoA{
private:
    char _nombre[30];
public:
    ArchivoPuntoA(const char* nombre){
        strcpy(_nombre, nombre);
    }
    PuntoA leerRegistro(int pos){
        PuntoA reg;
        reg.setCodigoSorteo(-1);
        FILE *p;
        p=fopen(_nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof(PuntoA)*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

    bool escribirRegistro(PuntoA reg){
        FILE *p;
        p=fopen(_nombre, "ab");
        if(p==NULL) return false;
        bool escribio = fwrite(&reg, sizeof reg, 1, p);
        fclose(p);
        return escribio;
    }

    bool listarArchivo(){
        PuntoA reg;
        FILE *p;
        p = fopen(_nombre, "rb");
        if (p == NULL){
        cout << "No se pudo abrir " << endl;
        return false;
        }
        while (fread(&reg, sizeof reg, 1, p)==1 ){
        reg.Mostrar();
        cout << endl;
        }
        fclose(p);
        return true;
    }


};

void solucionPuntoA(){
    ArchivoSorteo archSorteo("sorteo.dat");
    Sorteo regSorteo;
    int canSorteos = archSorteo.contarRegistros();


    ArchivoBillete archBillete("billete.dat");
    Billete regBillete;
    int cantBilletes = archBillete.contarRegistros();

    ArchivoPuntoA archPuntoA("puntoA.dat");
    PuntoA regPuntoA;

    for (int i=0 ; i<canSorteos ; i++ ){
        regSorteo = archSorteo.leerRegistro(i);
        for (int j=0 ; j<cantBilletes ; j++ ){
            regBillete = archBillete.leerRegistro(j);
            if(regSorteo.getCodigoSorteo() == regBillete.getCodigoSorteo() &&  regSorteo.getNumGanador() == regBillete.getNumero()){
                regPuntoA.setCodigoSorteo(regSorteo.getCodigoSorteo());
                regPuntoA.setNumeroGanador(regSorteo.getNumGanador());
                regPuntoA.setMesSorteo(regSorteo.getMesSorteo());
                regPuntoA.setCodigoProvincia(regBillete.getCodProvincia());
                archPuntoA.escribirRegistro(regPuntoA);
            }
        }
    }

}


void solucionPuntoB(){
    int matVentas[12][24]= {};

    ArchivoBillete archBillete("billete.dat");
    Billete regBillete;
    int cantBilletes = archBillete.contarRegistros();

    for (int i=0 ; i<cantBilletes ; i++ ){
        regBillete = archBillete.leerRegistro(i);
        matVentas[regBillete.getMes()-1][regBillete.getCodProvincia()-1]++;
    }

    for (int i=0 ; i<12 ; i++ ){
        for (int j=0 ; j<24 ; j++ ){
            if(matVentas[i][j]>0){
            cout << "MES " << i+1 << " PROVINCIA " << j+1 << " VENTAS: " << matVentas[i][j] << endl;
            }
        }
    }
}

void solucionPuntoC(){
    float premio, acuVentas = 0, ganancia = 0;
    ArchivoSorteo archSorteo("sorteo.dat");
    Sorteo regSorteo;
    int canSorteos = archSorteo.contarRegistros();


    ArchivoBillete archBillete("billete.dat");
    Billete regBillete;
    int cantBilletes = archBillete.contarRegistros();



    for (int i=0 ; i<canSorteos ; i++ ){
        regSorteo = archSorteo.leerRegistro(i);
        premio = regSorteo.getImporte();
        acuVentas = 0;
        for (int j=0 ; j<cantBilletes ; j++ ){
            regBillete = archBillete.leerRegistro(j);
            if(regSorteo.getCodigoSorteo() == regBillete.getCodigoSorteo()){
                acuVentas += regBillete.getPrecio();
            }

        }

        ganancia = acuVentas-premio;
        if(ganancia >= 0){
            cout << "La ganancia del sorteo " << regSorteo.getCodigoSorteo() << " fue: $" << ganancia << endl;
        }
        else{
            cout << "La perdida del sorteo " << regSorteo.getCodigoSorteo() << " fue: $" << ganancia*-1 << endl;
        }


    }
}


int main(){
    setlocale (LC_ALL, "Spanish");

    ArchivoSorteo archSorteo("sorteo.dat");

    ArchivoBillete archBillete("billete.dat");

    cout << "ARCHIVO SORTEO " << endl;
    archSorteo.listarArchivo();
    cout << "ARCHIVO BILLETE " << endl;
    archBillete.listarArchivo();

    ///CADA VEZ QUE SE EJECUTE EL PUNTO A LUEGO HAY QUE BORRAR EL .DAT POR QUE SINO AGREGA MAS REGISTROS EN EL MISMO ARCHIVO.
    solucionPuntoA();


    ArchivoPuntoA archPuntoA("puntoA.dat");
    cout << "ARCHIVOS DEL PUNTO A " << endl;
    archPuntoA.listarArchivo();

    cout << "RESULTADOS DEL PUNTO B" << endl;
    solucionPuntoB();

    cout << endl <<  "RESULTADOS DEL PUNTO C" << endl;
    solucionPuntoC();

    return 0;
}
