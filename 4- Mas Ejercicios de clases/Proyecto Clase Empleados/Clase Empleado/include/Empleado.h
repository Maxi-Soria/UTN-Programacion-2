#ifndef EMPLEADO_H
#define EMPLEADO_H
#include "Fecha.h"
#include <cstring>


class Empleado{
    private:
        int _dni;
        char _nombre[30];
        char _apellido[30];
        char _domicilio[30];
        char _email[30];
        Fecha _feDeNac;
        int _cargo;

    public:
        Empleado();
        Empleado(int dni);
        void Mostrar();

        ///sets
        void setDni(int dni);
        void setNombre(char* nombre);
        void setApelido(char* apellido);
        void setDomicilio(char* domicilio);
        void setFeDeNac(Fecha feDeNac );
        void setCargo(int cargo);

        ///gets
        int getDni();
        char* getNombre();
        char* getApelido();
        char* getDomicilio();
        char* getEmail();
        Fecha getFeDeNac();
        int getCargo();

};

#endif // EMPLEADO_H
