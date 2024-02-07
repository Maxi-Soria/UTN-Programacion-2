//Ejercicio: tipo parcial 2
//Autor:DEK
//Fecha: 19-06- 2014
//Comentario:
#include <iostream>
#include <cstdlib>
using namespace std;

class Pais{
private:
    int codigoPais;
    char nombrePais[30];
public:
    int getCodigoPais(){return codigoPais;}
    const char *getNombrePais(){return nombrePais;}
    bool leerDeDisco(int);
};

bool Pais::leerDeDisco(int pos){
    FILE *p;
    p=fopen("paises.dat","rb");
    if(p==NULL)exit(1);
    fseek(p, sizeof *this*pos,0);
    bool leyo=fread(this, sizeof *this, 1, p);
    fclose(p);
    return leyo;
}
///**********************************************************

class Jugador{
private:
    char codigoJugador[5];
    char nombreJugador[30];
    int codigoPais;
    int edad;
public:
    const char* getCodigoJugador(){return codigoJugador;}
    const char* getNombreJugador(){return nombreJugador;}
    int getCodigoPais(){return codigoPais;}
    bool leerDeDisco(int);
};
bool Jugador::leerDeDisco(int pos){
    FILE *p;
    p=fopen("jugadores.dat","rb");
    if(p==NULL)exit(1);
    fseek(p, sizeof *this*pos,0);
    bool leyo=fread(this, sizeof *this, 1, p);
    fclose(p);
    return leyo;
}
///***********************************************************

class Gol{
private:
    int codigoPartido;
    int minutos, tiempo;
    char codigoJugador[5];
    int tipo;
public:
    const char *getCodigoJugador(){return codigoJugador;}
    int getTipo(){return tipo;}
    bool leerDeDisco(int);
};

bool Gol::leerDeDisco(int pos){
    FILE *p;
    p=fopen("goles.dat","rb");
    if(p==NULL)exit(1);
    fseek(p, sizeof *this*pos,0);
    bool leyo=fread(this, sizeof *this, 1, p);
    fclose(p);
    return leyo;
}
///*************************************************************

class GolesJugador{
private:
    char codigoJugador[5];
    char nombreJugador[30];
    char nombrePais[30];
    int cantidadGoles;
public:
    void setCodigoJugador(const char*codJ){
    strcpy(codigoJugador, codJ);}
    void setNombreJugador(const char *nom){strcpy(nombreJugador,nom);}
    void setNombrePais(const char *np){strcpy(nombrePais,np);}
    void setCantidadGoles(const int cant ){cantidadGoles=cant;}

    const char *getCodigoJugador(){return codigoJugador;}
    const char *getNombreJugador(){return nombreJugador;}
    const int getCantidadGoles(){return cantidadGoles;}

    void grabarEnDisco();
    bool leerDeDisco(int p);
    void Mostrar();

    //sobrecarga para el punto b
    bool operator>(const GolesJugador &aux){
    if(this->cantidadGoles>aux.cantidadGoles) return true;
    return false;
    }
};

void GolesJugador::grabarEnDisco(){
    FILE *p;
    p=fopen("golesJuga.dat","ab");
    if(p==NULL)exit(1);
    fwrite(this, sizeof *this, 1, p);
    fclose(p);
}

bool GolesJugador::leerDeDisco(int pos){
    FILE *p;
    p=fopen("golesJuga.dat","rb");
    if(p==NULL)exit(1);
    fseek(p, sizeof *this*pos,0);
    bool leyo=fread(this, sizeof *this, 1, p);
    fclose(p);
    return leyo;
}
void GolesJugador::Mostrar(){
    cout<<"CODIGO DE JUGADOR: ";
    cout<<codigoJugador<<endl;
    cout<<"NOMBRE DE JUGADOR: ";
    cout<<nombreJugador<<endl;
    cout<<"PAIS: ";
    cout<<nombrePais<<endl;
    cout<<"CANTIDAD DE GOLES: ";
    cout<<cantidadGoles<<endl;
}
