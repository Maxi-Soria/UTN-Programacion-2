#include <iostream>
#include <cstring>

using namespace std;

#include "parcialm1.h"

class Punto1{
private:
    char _codigoObra[5];
    char _direccion[30];
    int _provincia;
public:
    Punto1(){strcpy(_codigoObra, "NULL"); strcpy(_direccion,"NULL"); _provincia = 0;}

    void setCodigoObra(const char* codObra){strcpy(_codigoObra, codObra);}
    void setDireccion (const char* direccion){strcpy(_direccion,direccion);}
    void setProvincia(int provincia){_provincia = provincia;}

    void Mostrar(){
    cout << "Codigo de Obra: " << _codigoObra << endl;
    cout << "Direciion: " << _direccion << endl;
    cout << "Provincia : " << _provincia << endl;

    }
};

class ArchivosPunto1{
private:
    char nombre[30];
public:
        ArchivosPunto1(const char *n){
        strcpy(nombre, n);
    }
    ///ESCRIBIR EN EL ARCHIVO---------------------------------
    bool escribirRegistro(Punto1 reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        bool escribio = fwrite(&reg, sizeof reg, 1, p);
        fclose(p);
        return escribio;
    }
    ///LEER -------------------------------------------------
    Punto1  leerRegistro(int pos){
        Punto1 reg;
        reg.setProvincia(-1);
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof(Punto1)*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    ///LISTAR ------------------------------------------------------
    bool listarArchivo(){
        Punto1 reg;
        FILE *p;
        p = fopen(nombre, "rb");
        if (p == NULL){
        cout << "No se pudo abrir " << endl;
        return false;
        }
        while (fread(&reg, sizeof reg, 1, p)==1 ){
        reg.Mostrar();
        cout << endl;
        }
        fclose(p);
        return true;
        }
    ///CONTAR -------------------------------------------
    int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Punto1);
    }
};


///Generar un archivo con el código de obra, la dirección y la provincia, de las obras cuyo estado de ejecución sea "en ejecución".
void SolucionPunto1(){

    ArchivosPunto1 archP1("Punto1.dat");
    Punto1 objP1;


    ArchivoObras archObra("obras.dat");
    Obra objObra;
    int cantRegObras = archObra.contarRegistros();

    for (int i=0 ; i<cantRegObras ; i++ ){
        objObra = archObra.leerRegistro(i);
 ;
        if(objObra.getEstadoEjecucion() == 3){
            objP1.setCodigoObra(objObra.getCodigoObra());
            objP1.setDireccion(objObra.getDireccion());
            objP1.setProvincia(objObra.getProvincia());
            archP1.escribirRegistro(objP1);

        }
    }
    archP1.listarArchivo();
}

///La provincia con menos proveedores (ignorando las provincias sin proveedores).
void SolucionPunto2(){

    bool band = false;
    int vecCantProvedoresPorProv[24] = {};
    int menorCantProv;

    ArchivoProveedor archProv("proveedores.dat");
    Proveedor objProv;

    int cantReg = archProv.contarRegistros();

    for (int i=0 ; i<cantReg ; i++ ){
        objProv = archProv.leerRegistro(i);
        vecCantProvedoresPorProv[objProv.getProvincia()-1]++;
    }


    menorCantProv = vecCantProvedoresPorProv[0];
    for (int i=1 ; i<24 ; i++ ){
        if(vecCantProvedoresPorProv[i] > 0 ){
            if( !band ){
                menorCantProv = vecCantProvedoresPorProv[i];
                band = true;
            }
            else{
                if(vecCantProvedoresPorProv[i] < menorCantProv){
                    menorCantProv = vecCantProvedoresPorProv[i];
                }
            }
        }
    }

    cout << "La menor cantidad de provedores es " << menorCantProv << " y las provincias con esa cantidad son: ";
    for (int i=0 ; i<24 ; i++ ){
        if(vecCantProvedoresPorProv[i] == menorCantProv){
            cout << i+1 << " ";
        }
    }



}


int main(){
    setlocale (LC_ALL, "Spanish");
    cout << "PUNTO 1 " << endl;
    SolucionPunto1();
    cout << endl;
    cout << "PUNTO 2" << endl;
    SolucionPunto2();
    cout << endl << endl;

    return 0;
}
