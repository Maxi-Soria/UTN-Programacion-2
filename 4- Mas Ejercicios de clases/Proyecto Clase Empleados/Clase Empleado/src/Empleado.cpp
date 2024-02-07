#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Empleado.h"

using namespace std;


Empleado::Empleado(){
    _dni = 0;
    strcpy(_nombre,"Sin nombre");
    strcpy(_apellido,"Sin Apellido");
    strcpy(_domicilio,"Sin domiclio");
    strcpy(_email, "Sin email");
    _feDeNac.setAnio(1800);
    _cargo = 0;
}

Empleado::Empleado(int dni){
    _dni = dni;
    strcpy(_nombre,"Sin nombre");
    strcpy(_apellido,"Sin Apellido");
    strcpy(_domicilio,"Sin domiclio");
    strcpy(_email, "Sin email");
    _feDeNac.setAnio(1800);
    _cargo = 0;
}

void Empleado::Mostrar(){
    cout << "EL DNI ES: " << _dni << endl;
    cout << "EL NOMBRE ES: " << _nombre << endl;
    cout << "EL APELLIDO ES: " << _apellido << endl;
    cout << "EL DOMICILIO ES: " << _domicilio << endl;
    cout << "EL EMAIL ES: " << _email << endl;
    cout << "LA FECHA DE NAC: ";
    _feDeNac.Mostrar();
    cout << "EL CARGO ES:" << _cargo << endl;
    cout << endl;
}

///sets
void Empleado::setDni(int dni){_dni = dni;}
void Empleado::setNombre(char* nombre){strcpy(_nombre, nombre);}
void Empleado::setApelido(char* apellido){strcpy(_apellido,apellido );}
void Empleado::setDomicilio(char* domicilio){strcpy(_domicilio,domicilio);}
void Empleado::setFeDeNac(Fecha feDeNac ){_feDeNac = feDeNac;}
void Empleado::setCargo(int cargo){if(cargo>0 && cargo<11) _cargo = cargo;}

///gets
int Empleado::getDni(){return _dni;}
char* Empleado::getNombre(){return _nombre;}
char* Empleado::getApelido(){return _apellido;}
char* Empleado::getDomicilio(){return _domicilio;}
char* Empleado::getEmail(){return _email;}
Fecha Empleado::getFeDeNac(){return _feDeNac;}
int Empleado::getCargo(){return _cargo;}

