#ifndef INMUEBLE_H
#define INMUEBLE_H
#include "Fecha.h"


class Inmueble{
    protected:
        char _direccion[30];
        Fecha _fechaIngreso;
        Fecha _fechaOperacion;
        float _supTotal;
        int _tipo;

    public:
        Inmueble();

        void Cargar();
        void Mostrar();

};

#endif // INMUEBLE_H
