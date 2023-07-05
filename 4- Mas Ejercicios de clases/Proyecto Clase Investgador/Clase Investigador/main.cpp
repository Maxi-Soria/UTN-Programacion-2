#include <iostream>
#include "Investigador.h"
#include <cstring>

using namespace std;

int main(){

    Investigador obj;
    obj.Mostrar();
    char ape[20];
    strcpy(ape,"Soria");
    obj.setApellido(ape);
    obj.setDni(42194122);
    obj.Mostrar();

}


/*
12332123
Docente
Apellido docente
5
2
9

*/
