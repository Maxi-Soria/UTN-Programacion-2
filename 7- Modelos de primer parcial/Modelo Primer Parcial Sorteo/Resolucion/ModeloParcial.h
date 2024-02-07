#ifndef MODELOPARCIAL_H_INCLUDED
#define MODELOPARCIAL_H_INCLUDED
#include <iostream>
#include <cstring>

using namespace std;

class Sorteo{
private:
    int _codigoSorteo;
    int _numGanador;
    float _importe;
    int _diaSorteo;
    int _mesSorteo;
public:
    Sorteo(){_codigoSorteo = 0; _numGanador = 0; _importe = 0; _diaSorteo = 0; _mesSorteo = 0;}
    void Cargar();
    void Mostrar();

    void setCodigoSorteo(int codigoSorteo) { _codigoSorteo = codigoSorteo; }
    void setNumGanador(int numGanador) { _numGanador = numGanador; }
    void setImporte(float importe) { _importe = importe; }
    void setDiaSorteo(int diaSorteo) { _diaSorteo = diaSorteo; }
    void setMesSorteo(int mesSorteo) { _mesSorteo = mesSorteo; }

    int getCodigoSorteo() { return _codigoSorteo; }
    int getNumGanador() { return _numGanador; }
    float getImporte() { return _importe; }
    int getDiaSorteo() { return _diaSorteo; }
    int getMesSorteo() { return _mesSorteo; }
};

void Sorteo::Cargar(){
        cout << "Ingrese el codigo del sorteo: ";
        cin >> _codigoSorteo;
        cout << "Ingrese el numero del ganador: ";
        cin >> _numGanador;
        cout << "Ingrese el importe: ";
        cin >> _importe;
        cout << "Ingrese el dia del sorteo: ";
        cin >> _diaSorteo;
        cout << "Ingrese el mes del sorteo: ";
        cin >> _mesSorteo;
}

void Sorteo::Mostrar() {
        cout << "Codigo del sorteo: " << _codigoSorteo << endl;
        cout << "Numero del ganador: " << _numGanador << endl;
        cout << "Importe: " << _importe << endl;
        cout << "Dia del sorteo: " << _diaSorteo << endl;
        cout << "Mes del sorteo: " << _mesSorteo << endl;
}

class ArchivoSorteo{
private:
    char _nombre[20];
public:
    ArchivoSorteo(const char* nombre){
        strcpy(_nombre, nombre);
    }
    Sorteo leerRegistro(int pos){
        Sorteo reg;
        reg.setCodigoSorteo(-1);
        FILE *p;
        p=fopen(_nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof(Sorteo)*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros(){
        FILE *p;
        p=fopen(_nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Sorteo);
    }
    int AgregarRegistro(){
        Sorteo reg;
        FILE *p;
        p = fopen(_nombre, "ab");
        if(p==NULL){
        cout << "No se pudo abrir o crear el archivo" << endl;
        return -1;
        }
        reg.Cargar();
        int valor = fwrite (&reg, sizeof reg, 1, p);
        fclose(p);
        return valor;
    }


    bool listarArchivo(){
        Sorteo reg;
        FILE *p;
        p = fopen(_nombre, "rb");
        if (p == NULL){
        cout << "No se pudo abrir " << endl;
        return false;
        }
        while (fread(&reg, sizeof reg, 1, p)==1 ){
        reg.Mostrar();
        cout << endl;
        }
        fclose(p);
        return true;
    }

};



class Billete {
private:
    int _codigoSorteo;
    int _numero;
    int _codProvincia;
    float _precioBillete;
    int _dia, _mes;

public:
    void setCodigoSorteo(int codigo) { _codigoSorteo = codigo; }
    void setNumero(int numero) { _numero = numero; }
    void setCodigoProvincia(int codProvincia) { _codProvincia = codProvincia; }
    void setPrecioBillete(float precio) { _precioBillete = precio; }
    void setDia(int dia) { _dia = dia; }
    void setMes(int mes) { _mes = mes; }

    int getCodigoSorteo() { return _codigoSorteo; }
    int getNumero() { return _numero; }
    int getCodProvincia() { return _codProvincia; }
    float getPrecio() { return _precioBillete; }
    int getDia() { return _dia; }
    int getMes() { return _mes; }

    void Cargar();
    void Mostrar();
};

void Billete::Cargar() {
    cout << "Ingrese codigo de sorteo: ";
    cin >> _codigoSorteo;
    cout << "Ingrese numero: ";
    cin >> _numero;
    cout << "Ingrese codigo de provincia: ";
    cin >> _codProvincia;
    cout << "Ingrese precio de Billete: ";
    cin >> _precioBillete;
    cout << "Ingrese dia: "; cin >>
    _dia;
    cout << "Ingrese mes: "; cin >>
    _mes;
}

void Billete::Mostrar() {
    cout << "Codigo de sorteo: " << _codigoSorteo << endl;
    cout << "Numero: " << _numero << endl;
    cout << "Provincia: " << _codProvincia << endl;
    cout << "Precio de Billete: " << _precioBillete << endl;
    cout << "Dia y Mes: " << _dia << "/" << _mes << endl;
    cout << endl;
}

class ArchivoBillete{
private:
    char _nombre[30];
public:
    ArchivoBillete(const char *nombre){
        strcpy(_nombre, nombre);
    }

    Billete leerRegistro(int pos){
        Billete reg;
        reg.setCodigoSorteo(-1);
        FILE *p;
        p=fopen(_nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof(Billete)*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

    int contarRegistros(){
        FILE *p;
        p=fopen(_nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Billete);
    }

    int AgregarRegistro(){
        Billete reg;
        FILE *p;
        p = fopen(_nombre, "ab");
        if(p==NULL){
        cout << "No se pudo abrir o crear el archivo" << endl;
        return -1;
        }
        reg.Cargar();
        int valor = fwrite (&reg, sizeof reg, 1, p);
        fclose(p);
    return valor;
	}

    bool listarArchivo(){
        Billete reg;
        FILE *p;
        p = fopen(_nombre, "rb");
        if (p == NULL){
        cout << "No se pudo abrir " << endl;
        return false;
        }
        while (fread(&reg, sizeof reg, 1, p)==1 ){
        reg.Mostrar();
        cout << endl;
        }
        fclose(p);
        return true;
    }

};

#endif // MODELOPARCIAL_H_INCLUDED
