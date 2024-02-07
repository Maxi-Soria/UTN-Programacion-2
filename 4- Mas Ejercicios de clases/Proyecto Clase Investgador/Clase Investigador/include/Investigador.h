#ifndef INVESTIGADOR_H
#define INVESTIGADOR_H
#include "Fecha.h"

class Investigador{
    private:
        int _dni;
        char _nombre[30];
        char _apellido[30];
        Fecha _fechaDeNac;
        int _unidadAcad; // 1 a 30
        int _categoria; // 1 a 5
        int _especialidad; // 1 a 10

    public:
        Investigador();
        void Cargar();
        void Mostrar();

        void setDni(int dni);
        void setNombre(char* nombre);
        void setApellido(char* apellido);
        void setFechaDeNac(Fecha fechaDeNac);
        void setUnidadAcad(int unidadAcad);
        void setCategoria(int categoria);
        void setEspecialidad(int especialidad);

        int getDni();
        char* getNombre();
        char* getApellido();
        Fecha getFechaDeNac();
        int getUnidadAcad(int unidadAcad);
        int getCategoria(int categoria);
        int getEspecialidad(int especialidad);


};

#endif // INVESTIGADOR_H
