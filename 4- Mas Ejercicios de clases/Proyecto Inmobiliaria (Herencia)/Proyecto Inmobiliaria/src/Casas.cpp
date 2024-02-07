#include <iostream>
#include <cstdlib>
#include "Casas.h"

using namespace std;


Casas::Casas(){
    _cantAmbientes = 0;
    _supConstruida = 0;
}

void Casas::Cargar(){
    Inmueble::Cargar();
    cout << "Cantidad de Ambientes: ";
    cin >> _cantAmbientes;
    cout << "Superficie Construida: ";
    cin >> _supConstruida;
}

void Casas::Mostrar(){
    Inmueble::Mostrar();
    cout << "AMBIENTES: " << _cantAmbientes << endl;
    cout << "SUPERFICIE CONSTRUIDA: " << _supConstruida << endl;
}


