#include <iostream>
#include "Fecha.h"

using namespace std;

int main(){
    setlocale (LC_ALL, "Spanish");

    Fecha obj;

    obj.Cargar();
    obj.Mostrar();

    return 0;
}
