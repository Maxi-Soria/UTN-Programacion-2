#ifndef MISION_H
#define MISION_H
#include "Fecha.h"
#include <cstring>


class Mision{
    private:
        int _numMision;
        char _nombreMision[30];
        char _nombreAstronauta[30];
        Fecha _fechaInicio;
        Fecha _fechaFin;
        float _presupuesto;

    public:
        Mision();

        int getNumMision();
        char* getNombreMision();
        char* getNombreAstronauta();
        Fecha getFechaInicio();
        Fecha getFechaFin();
        float getPresupuesto();

        void setNumMision(int numMision);
        void setNombreMision (char* nombreMision);
        void setNombreAstronauta (char* nombreAstronauta);
        void setFechaInicio (Fecha fechaInicio);
        void setFechaFin (Fecha fechaFin);
        void setPresupuesto (float presupuesto);
};

#endif // MISION_H
