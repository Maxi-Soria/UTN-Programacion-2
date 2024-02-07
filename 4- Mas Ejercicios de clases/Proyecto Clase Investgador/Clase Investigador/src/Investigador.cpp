#include <iostream>
#include <cstdlib>
#include "Investigador.h"
#include <cstring>
using namespace std;

void cargar_cadena(char *palabra, int tam){
    int i = 0;
    fflush(stdin);
    for (i = 0 ; i < tam ; i++ ){
        palabra[i] = cin.get();
        if(palabra[i] == '\n') break;
    }
    palabra[i] = '\0';
    fflush(stdin);
}


Investigador::Investigador(){
    setDni(100);
    setNombre(strcpy(_nombre,"sin dato"));
    setApellido(strcpy(_apellido,"sin dato"));
    //setFechaDeNac(Fecha(1,1,2023));
    setUnidadAcad(1);
    setCategoria(1);
    setEspecialidad(1);

}

void Investigador::Cargar(){
    cout << "Ingrese su Dni: ";
    cin >> _dni;
    cout << "Ingrese nombre: ";
    cargar_cadena(_nombre, 29);
    cout << "Ingrese apellido: ";
    cargar_cadena(_apellido, 29);
    cout << "Ingrese Unidad academica: ";
    cin >> _unidadAcad;
    cout << "Ingrese categoria: ";
    cin >> _categoria;
    cout << "Ingrese especialidad: ";
    cin >> _especialidad;
    cout << endl;

}

void Investigador::Mostrar(){
    cout << "DNI: " << _dni << endl;
    cout << "NOMBRE: " << _nombre << endl;
    cout << "APELLIDO: " << _apellido << endl;
    cout << "FECHA DE NACIMIENTO: ";
    _fechaDeNac.Mostrar();
    cout << "UNIDAD ACADEMICA: " << _unidadAcad << endl;
    cout << "CATEGORIA: " << _categoria << endl;
    cout << "ESPECIALIDAD: " << _especialidad << endl;
    cout << endl;

}

void Investigador::setDni(int dni){if (dni>0) _dni = dni;}
void Investigador::setNombre(char* nombre){strcpy(_nombre, nombre);}
void Investigador::setApellido(char* apellido){strcpy(_apellido, apellido);}
void Investigador::setFechaDeNac(Fecha fechaDeNac){_fechaDeNac = fechaDeNac;}
void Investigador::setUnidadAcad(int unidadAcad){if(unidadAcad>0 && unidadAcad<31) _unidadAcad = unidadAcad;}
void Investigador::setCategoria(int categoria){if(categoria>0 && categoria<6) _categoria = categoria;}
void Investigador::setEspecialidad(int especialidad){if(especialidad>0 && especialidad<11) _especialidad = especialidad;}

int Investigador::getDni(){return _dni;}
char* Investigador::getNombre(){return _nombre;}
char* Investigador::getApellido(){return _apellido;}
Fecha Investigador::getFechaDeNac(){return _fechaDeNac;}
int Investigador::getUnidadAcad(int unidadAcad){return _unidadAcad;}
int Investigador::getCategoria(int categoria){return _categoria;}
int Investigador::getEspecialidad(int especialidad){return _especialidad;}

