#include <iostream>
#include <cstdlib>

using namespace std;

class Fecha{
private:
    int _dia, _mes, _anio;

public:
    void Cargar();
    void Mostrar();

    ///Constructor
    Fecha(){_dia = 1; _mes = 1; _anio = 2029;}

    ///Getters
    int getDia(){return _dia;}
    int getMes(){return _mes;}
    int getAnio(){return _anio;}

    ///Seters
    void setDia(int dia){if(dia>0 && dia<32) _dia = dia;}
    void setMes(int mes){if(mes>0 && mes<13) _mes=mes;}
    void setAnio(int anio){if(anio>0) _anio=anio;}


};

void Fecha::Cargar(){
    int dia, mes, anio;
    bool correcto = false;
    do{
    cout << "Ingrese el dia: ";
    cin >> dia;
    cout << "Ingrese el mes: ";
    cin >> mes;
    cout << "Ingrese el año: ";
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
    cout << "La fecha es: " << _dia << "/" << _mes << "/" << _anio << endl;
}

int main(){
    setlocale (LC_ALL, "Spanish");

    Fecha obj;

    //obj.Cargar();
    obj.Mostrar();

    return 0;
}
