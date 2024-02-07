#ifndef CASAS_H
#define CASAS_H
#include "Inmueble.h"



class Casas:public Inmueble{
    private:
        int _cantAmbientes;
        float _supConstruida;
    public:
        Casas();

        void Cargar();
        void Mostrar();

};

#endif // CASAS_H
