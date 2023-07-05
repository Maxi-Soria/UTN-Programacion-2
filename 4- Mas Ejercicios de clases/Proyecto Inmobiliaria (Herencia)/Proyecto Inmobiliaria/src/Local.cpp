#include <iostream>
#include <cstdlib>
#include "Local.h"

using namespace std;


Local::Local(){
    _zona = 0;
    _mejoras = 'A';
}

void Local::Cargar(){
    Inmueble::Cargar();
    cout << "Zona 1-Comercial 2-Mixta 3-Industrial: ";
    cin >> _zona;
    cout << "Mejoras: A-Sin mejoras B-Asfalto C-todos los servicios ";
    cin >> _mejoras;
}

void Local::Mostrar(){
    Inmueble::Mostrar();
    cout << "ZONA: " << _zona << endl;
    cout << "MEJORAS: " << _mejoras << endl;
}
