#include <iostream>
#include <cstdlib>
#include "Fecha.h"

using namespace std;

void Fecha::Cargar(){
    int dia, mes, anio;
    bool correcto = false;
    do{
    cout << "Dia: ";
    cin >> dia;
    cout << "Mes: ";
    cin >> mes;
    cout << "Año: ";
    cin >> anio;

    if (dia>0 && dia<32 && mes>0 && mes<13 && anio>0){
        _dia = dia;
        _mes = mes;
        _anio = anio;
        correcto = true;
    }
    else{
        cout << "Fecha no valida" << endl << endl;
    }

    } while (!correcto);
}

void Fecha::Mostrar(){
    cout << _dia << "/" << _mes << "/" << _anio << endl;
}

///Constructor
Fecha::Fecha(){_dia = 1; _mes = 1; _anio = 1900;}

Fecha::Fecha(int dia, int mes, int anio){
    if (dia>0 && dia<32 && mes>0 && mes<13 && anio>0){
        _dia = dia;
        _mes = mes;
        _anio = anio;
    }
}

    ///Getters
int Fecha::getDia(){return _dia;}
int Fecha::getMes(){return _mes;}
int Fecha::getAnio(){return _anio;}

///Seters
void Fecha::setDia(int dia){if(dia>0 && dia<32) _dia = dia;}
void Fecha::setMes(int mes){if(mes>0 && mes<13) _mes=mes;}
void Fecha::setAnio(int anio){if(anio>0) _anio=anio;}
