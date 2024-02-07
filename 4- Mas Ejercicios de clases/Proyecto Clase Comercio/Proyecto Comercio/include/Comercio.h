#ifndef COMERCIO_H
#define COMERCIO_H
#include "Fecha.h"


class Comercio{
private:
    int _numCompra;
    Fecha _fecha;
    char _nombre[30];
    int _tipo; //entero entre 1 y 15
    int _formaPago; // 1 a 5
    float _importeTotal;

public:
    Comercio ();

    ///set
    void setNumCompra(int numCompra);
    void setFecha(Fecha fecha);
    void setNombre(char* nombre);
    void setTipo(int tipo);
    void setFormaPago(int formaPago);
    void setImporteTotal(float importeTotal);

    ///get
    int getNumCompra();
    Fecha getFecha();
    char* getNombre();
    int getTipo();
    int getFormaPago();
    float getImporteTotal();
};

#endif // COMERCIO_H
