#include <iostream>
#include <cstring>

using namespace std;
#include "parcial2.h"

class PuntoA{
private:
    int codigoDeCereal;
    char nombre[30];
    float tonCosechadas;
public:
    void setCodigoDeCereal(int codCereal){codigoDeCereal = codCereal;}
    void setNombre(const char* nomb){strcpy(nombre,nomb);}
    void setTonCosech(float tonCosech){tonCosechadas = tonCosech;}

    void Mostrar(){
        cout<<codigoDeCereal << " " << nombre << " " << tonCosechadas << endl;
    }
};

class ArchivoPuntoA{
private:
    char nombre[30];
public:
    ArchivoPuntoA(){
        strcpy(nombre,"PuntoA.dat");
    }

    bool escribirRegistro(PuntoA reg){
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

void solucionPuntoA(){
   ArchivoCereales archCereales;
   Cereal regCereal;
   int cantRegCereal = archCereales.contarRegistros();

   ArchivoCosecha archCosecha;
   Cosecha regCosecha;
   int cantRegCosecha = archCosecha.contarRegistros();

   ArchivoPuntoA archPA;
   PuntoA regPA;
   archPA.vaciar();

   for (int i=0 ; i<cantRegCereal ; i++ ){
       regCereal = archCereales.leerRegistro(i);
       float acumCosecha=0;

       for (int j=0 ; j< cantRegCosecha ; j++ ){
           regCosecha = archCosecha.leerRegistro(j);

           if(regCereal.getCodigoCereal() == regCosecha.getCodigoCereal()){
                acumCosecha+=regCosecha.getToneladasCosechadas();
           }
       }
       regPA.setCodigoDeCereal(regCereal.getCodigoCereal());
       regPA.setNombre(regCereal.getNombre());
       regPA.setTonCosech(acumCosecha);
       archPA.escribirRegistro(regPA);
       regPA.Mostrar();
   }

}

void solucionPuntoB(){
    ArchivoCereales archCereales;
    Cereal regCereal;
    int cantRegCereal = archCereales.contarRegistros();

    ArchivoCosecha archCosecha;
    Cosecha regCosecha;
    int cantRegCosecha = archCosecha.contarRegistros();



   for (int i=0 ; i<cantRegCereal ; i++ ){
       regCereal = archCereales.leerRegistro(i);
       float vecAcumCosecha[12]={};
       char nom[30];
       for (int j=0 ; j< cantRegCosecha ; j++ ){
           regCosecha = archCosecha.leerRegistro(j);

           if(regCereal.getCodigoCereal() == regCosecha.getCodigoCereal()){
                strcpy(nom, regCereal.getNombre());
                vecAcumCosecha[regCosecha.getFecha().getMes()-1] += regCosecha.getToneladasCosechadas();
           }
       }
       cout << "Cereal " << regCereal.getCodigoCereal() << endl;
       for (int i=0 ; i<12 ; i++ ){
            if(vecAcumCosecha[i] > 0){
                cout <<"Mes #"<<i+1<<" cosecha: " << vecAcumCosecha[i]<<endl;
            }
       }
   }

}

int main(){
    setlocale (LC_ALL, "Spanish");

    //solucionPuntoA();
    //solucionPuntoB();
    return 0;
}





