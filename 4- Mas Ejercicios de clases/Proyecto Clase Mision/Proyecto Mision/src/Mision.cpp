#include <iostream>
#include <cstring>
#include "Mision.h"


Mision::Mision(){
        strcpy(_nombreMision,"Nada");
        strcpy(_nombreAstronauta,"Nada");
}

int   Mision::getNumMision() { return _numMision;}
char* Mision::getNombreMision() { return _nombreMision;}
char* Mision::getNombreAstronauta() { return _nombreAstronauta; }
Fecha Mision::getFechaInicio() { return _fechaInicio; }
Fecha Mision::getFechaFin() { return _fechaFin; }
float Mision::getPresupuesto() { return _presupuesto; }

void  Mision::setNumMision(int numMision) { _numMision = numMision; }
void  Mision::setNombreMision (char* nombreMision) { strcpy(_nombreMision,nombreMision); }
void  Mision::setNombreAstronauta (char* nombreAstronauta) {strcpy(_nombreAstronauta,nombreAstronauta); }
void  Mision::setFechaInicio (Fecha fechaInicio) { _fechaInicio = fechaInicio; }
void  Mision::setFechaFin (Fecha fechaFin) { _fechaFin = fechaFin; }
void  Mision::setPresupuesto (float presupuesto) { _presupuesto = presupuesto; }
