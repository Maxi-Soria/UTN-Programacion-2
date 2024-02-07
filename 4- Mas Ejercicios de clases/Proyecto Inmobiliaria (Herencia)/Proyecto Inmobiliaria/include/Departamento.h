#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H
#include "Inmueble.h"


class Departamento :public Inmueble{
    private:
        int _cantAmbientes;
        bool _instalacionesComp;

    public:
        Departamento();

        void Cargar();
        void Mostrar();

};

#endif // DEPARTAMENTO_H
