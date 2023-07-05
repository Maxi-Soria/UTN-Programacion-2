#ifndef LOCAL_H
#define LOCAL_H
#include "Inmueble.h"


class Local :public Inmueble{
    private:
        int _zona;
        char _mejoras;

    public:
        Local();
        void Cargar();
        void Mostrar();

};

#endif // LOCAL_H
