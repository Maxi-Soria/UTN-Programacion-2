#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Comercio.h"

using namespace std;


Comercio::Comercio(){
    _numCompra = 0;
    _fecha;
    strcpy(_nombre,"Sin nombre");
    _tipo = 0;
    _formaPago = 0;
    _importeTotal = 0;
}

void Comercio::setNumCompra(int numCompra){_numCompra = numCompra;}
void Comercio::setFecha(Fecha fecha){_fecha = fecha;}
void Comercio::setNombre(char* nombre){strcpy(_nombre,nombre);}
void Comercio::setTipo(int tipo){if (tipo > 0  && tipo > 16) _tipo = tipo;}
void Comercio::setFormaPago(int formaPago){if (formaPago > 0 && formaPago < 6) _formaPago = formaPago;}
void Comercio::setImporteTotal(float importeTotal){if (importeTotal > 0) _importeTotal = importeTotal;}

int Comercio::getNumCompra(){return _numCompra;}
Fecha Comercio::getFecha(){return _fecha;}
char* Comercio::getNombre(){return _nombre;}
int Comercio::getTipo(){return _tipo;}
int Comercio::getFormaPago(){return _formaPago;}
float Comercio::getImporteTotal(){return _importeTotal;}
