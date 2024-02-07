#include <iostream>
#include <cstdlib>
#include <cstring>
#include "parcial.h"
using namespace std;


/////////PROTOTIPO FUNCIONES GLOBALES//////////////////
void punto1();
int contarGoles(const char *);
const char *buscarNombrePais(int);
void punto2();
void punto2B();



int main(){
    punto1();
    punto2();
    system("pause");
return 0;
}


void punto1(){
    Jugador obj;
    GolesJugador aux;
    int pos=0, cantGoles;
    while(obj.leerDeDisco(pos++)){
        cantGoles=contarGoles(obj.getCodigoJugador());
        if(cantGoles>0){
            aux.setCantidadGoles(cantGoles);
            aux.setCodigoJugador(obj.getCodigoJugador());
            aux.setNombreJugador(obj.getNombreJugador());
            aux.setNombrePais(buscarNombrePais(obj.getCodigoPais()));
            aux.grabarEnDisco();
        }
    }
}


int contarGoles(const char *codigoJugador){
    Gol obj;
    int pos=0, cant=0;
    while(obj.leerDeDisco(pos++)){
    if(strcmp(codigoJugador, obj.getCodigoJugador())==0)
    if(obj.getTipo()!=2)
    cant++;
    }
return cant;
}

const char *buscarNombrePais(int cp){
    Pais obj;
    int pos=0;
    while(obj.leerDeDisco(pos++)){
    if(cp==obj.getCodigoPais())
    return obj.getNombrePais();
    }
}
// sin sobrecarga de operador >
void punto2(){
    GolesJugador obj, aux;
    int pos=0, maxGoles=0;
    while(obj.leerDeDisco(pos++)){
        if(obj.getCantidadGoles()>maxGoles){
        maxGoles=obj.getCantidadGoles();
        aux=obj;
        }
    }
    cout<<"GOLEADOR: ";
    aux.Mostrar();
}
//sobrecargando el operador > para la clase GolesJugador
void punto2B(){
    GolesJugador obj, aux;
    aux.setCantidadGoles(0);
    int pos=0;
    while(obj.leerDeDisco(pos++)){
        if(obj>aux){
            aux=obj;
        }
    }
    cout<<"GOLEADOR: ";
    aux.Mostrar();
}
