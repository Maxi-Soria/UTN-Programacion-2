#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

#include "recoleccion.h"




void solucionPuntoA();

///Para cada camión, la cantidad de viajes que realizó por cada zona, cada mes del año 2011.
void solucionPuntoB();

void solucionPuntoC(){
    ArchivoCamiones archCam;
    Camion regCamion;
    int cantRegCamiones = archCam.contarRegistros();

    ArchivoCentro archCentro;
    Centro regCentro;

}


int main() {
    setlocale(LC_ALL, "Spanish");
    solucionPuntoB();








    return 0;
}



void solucionPuntoA(){
    ArchivoResiduos archRes;
    Residuo regRes;
    int cantRegResiduos = archRes.contarRegistros();

    int mayorKilo = 0;
    int mayorZona = 0;
    for (int i=0 ; i<cantRegResiduos ; i++ ){
        regRes = archRes.leerRegistro(i);
        if(regRes.getCantidadKilos()>mayorKilo){
            mayorKilo = regRes.getCantidadKilos();
            mayorZona = regRes.getCodigoZona();
        }
            regRes.Mostrar();

    }

   cout << "La zona es: " << mayorZona << " con " << mayorKilo << " kg" << endl;

}

void solucionPuntoB(){

    ArchivoResiduos archRes;
    Residuo regRes;
    int cantRegResiduos = archRes.contarRegistros();

    ArchivoCamiones archCam;
    Camion regCam;
    int cantRegCamiones = archCam.contarRegistros();

    int matrizContZonaMes[20][12] = {};
    for (int i=0 ; i<cantRegCamiones ; i++ ){
            regCam = archCam.leerRegistro(i);

        for (int j=0 ; j<cantRegResiduos ; j++ ){
            regRes = archRes.leerRegistro(j);
            if(strcmp(regCam.getCodigoCamion(), regRes.getCodigoCamion()) == 0 && regRes.getFecha().getAnio() == 2011){
                matrizContZonaMes[regRes.getCodigoZona()-1][regRes.getFecha().getMes()-1]++;
                //cout << regCam.getCodigoCamion() << endl;
            }

        }
        cout << "CAMION: " << regCam.getCodigoCamion() << endl;
        for (int i=0 ; i<20 ; i++ ){

            for (int j=0 ; j<12 ; j++ ){
                if(matrizContZonaMes[i][j] > 0){
                    cout << "Zona " << i+1 << " mes " << j+1 << " Cantidad de viajes: " << matrizContZonaMes[i][j] << endl;
                }
            }
        }
        for (int i=0 ; i<20 ; i++ ){
            for (int j=0 ; j<12 ; j++ ){matrizContZonaMes[i][j] = 0;}
            }

    }
}
