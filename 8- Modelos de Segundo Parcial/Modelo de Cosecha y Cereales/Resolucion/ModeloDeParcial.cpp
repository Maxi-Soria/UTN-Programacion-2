#include <iostream>
#include <cstring>

using namespace std;
#include "parcial2.h"


int main(){
    setlocale (LC_ALL, "Spanish");

    ArchivoCosecha obj;
    Cosecha reg;
    /*for (int i=0 ; i<20 ; i++ ){
        reg.Cargar();
        obj.escribirRegistro(reg);
    }*/
    obj.listarArchivo();

    return 0;
}
