#include <iostream>
#include <cstdlib>
#include "Departamento.h"

using namespace std;

Departamento::Departamento(){
    _cantAmbientes = 0;
    _instalacionesComp = false;
}

void Departamento::Cargar(){
    Inmueble::Cargar();
    cout << "Cantidad de Ambientes: ";
    cin >> _cantAmbientes;
    cout << "Dispone de istalaciones compelementarias: ";
    cin >> _instalacionesComp;
}
void Departamento::Mostrar(){
    Inmueble::Mostrar();
    cout << "AMBIENTES: " << _cantAmbientes << endl;
    cout << "INSTALACIONES COMPLEMENTARIAS: " << _instalacionesComp << endl;
}
