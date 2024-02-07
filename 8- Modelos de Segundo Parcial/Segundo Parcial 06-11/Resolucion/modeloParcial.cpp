#include <iostream>
#include <cstring>

using namespace std;
#include "parcial2.h"

class Ventas2023{
private:
    int numVenta;
    char codigoCliente[5];
    char nombre[30];
public:

    void setNumVenta(int nv){numVenta = nv;}
    void setCodigoCliente(const char* codCli) { strcpy(codigoCliente, codCli);}
    void setNombre(const char* nom){strcpy(nombre, nom);}

    void Mostrar(){
        cout << "Numero de Venta: " << numVenta << endl;
        cout << "Codigo de cliente: " << codigoCliente << endl;
        cout << "Nombre del cliente: " << nombre << endl;

    }

    bool operator = (Cliente cli){
        strcpy(codigoCliente, cli.getCodigoCliente());
        strcpy(nombre, cli.getNombre());
        return true;
    }

};


class ArchivoVentas2023{
private:
    char nombre[30];
public:
    ArchivoVentas2023(){
        strcpy(nombre,"Ventas2023.dat");
    }

    bool escribirRegistro(Ventas2023 reg) {
        FILE* p;
        p = fopen(nombre, "ab");
        if (p == NULL) return false;
        bool escribio = fwrite(&reg, sizeof(reg), 1, p);
        fclose(p);
        return escribio;
    }

    int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Ventas2023);
    }

    Ventas2023 leerRegistro(int pos){
        Ventas2023 reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

};

void SolucionPunto1(){
    ArchivoVentas archVentas("ventas.dat");
    int cantVentas = archVentas.contarRegistros();
    Venta regVenta;

    ArchivoClientes archCli("clientes.dat");
    int cantCli = archCli.contarRegistros();
    Cliente regCliente;

    ArchivoVentas2023 archVentas2023;
    Ventas2023 reg;

    for (int i=0 ; i<cantVentas ; i++ ){
        regVenta = archVentas.leerRegistro(i);

        for (int j=0 ; j<cantCli ; j++ ){
            regCliente = archCli.leerRegistro(j);
            if(regVenta.getFechaVenta().getAnio() == 2023 && strcmp(regVenta.getNumeroDeCliente(),regCliente.getCodigoCliente()) == 0){
                reg.setNumVenta(regVenta.getNumeroVenta());
                reg = regCliente;
                /*
                reg.setCodigoCliente(regCliente.getCodigoCliente());
                reg.setNombre(regCliente.getNombre());
                */
                archVentas2023.escribirRegistro(reg);
                reg.Mostrar();

            }

        }
    }


}


void SolucionPunto2(){
    ArchivoVentas2023 arch2023;
    int cantReg = arch2023.contarRegistros();

    if(cantReg > -1){

        Ventas2023 *vec = NULL;
        vec= new Ventas2023[cantReg];
        if (vec==NULL)return;

        for(int i=0; i<cantReg;i++){
            vec[i]=arch2023.leerRegistro(i);
        }

        for(int i=0;i<cantReg;i++){
            vec[i].Mostrar();
        }

        delete []vec;




    }
    else{
        cout << "No se pudo leer" << endl;
    }

}

int main(){

    SolucionPunto1();
    SolucionPunto2();


return 0;
}





