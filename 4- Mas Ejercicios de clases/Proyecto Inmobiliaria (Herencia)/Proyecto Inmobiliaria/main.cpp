#include <iostream>
#include "Inmueble.h"
#include "Casas.h"
#include "Departamento.h"
#include "Local.h"

using namespace std;

int main(){
    setlocale (LC_ALL, "Spanish");

    //Inmueble inm;
    Casas cas;
    //Departamento depto;
    //Local loc;
    cout << "CARGA INMUEBLE " << endl;
    //inm.Cargar();
    cout << endl;
    cout << "CARGA CASA " << endl;
    cas.Cargar();
    cout << endl;
    cout << "CARGA DEPARTAMENTO " << endl;
    //depto.Cargar();
    cout << endl;
    cout << "CARGA LOCAL " << endl;
    //loc.Cargar();
    cout << endl;
    //inm.Mostrar();
    cout << endl;
    cas.Mostrar();
    cout << endl;
    //depto.Mostrar();
    cout << endl;
    //loc.Mostrar();

    return 0;
}


/*
INMUEBLE
Rivadavia 1828
20
3
2020
26
4
2023
56
2
Medrano 1339
24
8
2018
26
5
2023
70
1
4
39
Rivarola 1234
3
6
2020
7
9
2023
90
1
4
0
Maipu 2020
9
9
2009
14
4
2025
75
1
2
B


*/
