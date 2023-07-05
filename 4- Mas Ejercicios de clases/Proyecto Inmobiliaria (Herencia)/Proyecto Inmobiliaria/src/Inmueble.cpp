#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Inmueble.h"
#include "funciones.h"

using namespace std;


Inmueble::Inmueble(){
    strcpy(_direccion, "Sin Direccion");
    _supTotal = 0;
    _tipo = 0;
}

void Inmueble::Cargar(){
    cout << "Direccion: ";
    cargar_cadena(_direccion,29);
    cout << "Fecha de Ingreso: " << endl;
    _fechaIngreso.Cargar();
    cout << "Fecha de Operacion: " << endl;
    _fechaOperacion.Cargar();
    cout << "Superficie total m2: ";
    cin >> _supTotal;
    cout << "Tipo de Operacion 1-Venta / 2-Alquiler: ";
    cin >> _tipo;
}

void Inmueble::Mostrar(){
    cout << "DIRECCION: " << _direccion << endl;
    cout << "FECHA DE INGRESO: ";
    _fechaIngreso.Mostrar();
    cout << "FECHA DE OPERACION: ";
    _fechaOperacion.Mostrar();
    cout << "SUPERFICIE TOTAL m2: " << _supTotal << endl;
    cout << "TIPO DE OPERACIO: " << _tipo << endl;
}



