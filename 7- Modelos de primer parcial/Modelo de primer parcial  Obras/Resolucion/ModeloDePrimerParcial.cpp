#include <iostream>
#include <cstring>
#include <iomanip>

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
    ///VACIAR-----------------------------------------------
    void vaciar(){
        FILE *p = fopen(nombre, "wb");
        if (p == NULL){return ;}
        fclose(p);
    }
    ///REMPLAZAR UN REGISTRO(se puede usar para baja logica)---
    bool guardar(Punto1 reg, int posicionAReemplazar){
        FILE *p = fopen(nombre, "rb+");

        if (p == NULL){return false;}

        fseek(p, posicionAReemplazar * sizeof(Punto1), SEEK_SET);
        bool pudoEscribir = fwrite(&reg, sizeof(Punto1), 1, p);
        fclose(p);
        return pudoEscribir;
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
    int cantReg = archProv.contarRegistros();
    Proveedor objProv;


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

///a3) Los número de los proveedores a los que no se les compró nada el año pasado.
void SolucionPunto3(){

    bool vecProv[60] = {};

    ArchivoCompra archCp("compras.dat");
    int cantReg = archCp.contarRegistros();
    Compra reg;

    for (int i=0 ; i<cantReg ; i++ ){
        reg = archCp.leerRegistro(i);
        if(reg.getFechaCompra().getAnio() == 2022 ){
            vecProv[reg.getNumeroproveedor()-1] = true;

        }
    }

    cout << "Provedorees a los que no se les compro: " << endl;
    for (int i=0 ; i<60 ; i++ ){
        if(!vecProv[i]){
            cout << i+1<< endl;

        }
    }





}

///a4) El gasto en obra gruesa para cada uno de las obras. (analizar bien. Es el punto más complejo
///porque requiere del uso de 3 archivos)
void SolucionPunto4(){

    ArchivoObras archObra("obras.dat");
    int cantObras = archObra.contarRegistros();
    Obra regO;

    ArchivoCompra archComp("compras.dat");
    int cantCompras = archComp.contarRegistros();
    Compra regC;

    ArchivoMaterial archMat("materiales.dat");
    int cantMat = archMat.contarRegistros();
    Material regM;

    for (int i=0 ; i<cantObras ; i++ ){
            regO = archObra.leerRegistro(i);
            float gasto = 0;

        for (int j=0 ; j<cantCompras ; j++ ){
                regC = archComp.leerRegistro(j);

            for (int x=0 ; x<cantMat ; x++ ){
                regM = archMat.leerRegistro(x);

                if(strcmp(regO.getCodigoObra(),regC.getCodigoObra()) == 0 && regC.getCodigoMaterial() == regM.getCodigoMaterial()){
                    if(regM.getTipo() == 1){
                        gasto += regC.getImporte();
                    }
                }
            }

        }
        cout << "Obra " << regO.getCodigoObra() << " Gasto en obra gruesa: " << gasto << endl;
    }



}


void SolucionPunto5(){

    ArchivoProveedor archProv("proveedores.dat");
    int cant = archProv.contarRegistros();
    Proveedor reg;

    int vec[24] = {};

    for (int i=0 ; i<cant ; i++ ){
        reg = archProv.leerRegistro(i);
        int provincia = reg.getProvincia();
        vec[provincia-1]++;
    }

    for (int i=0 ; i<24 ; i++ ){
        if(vec[i] > 1){
            cout << "Privincia " << i+1 << " Proveedores " << vec[i] << endl;

        }
    }

}


bool remplazar(Compra reg, int posicionAReemplazar){
    FILE *p = fopen("compras.dat", "rb+");
    if (p == NULL){return false;}
    fseek(p, posicionAReemplazar * sizeof(Compra), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(Compra), 1, p);
    fclose(p);
    return pudoEscribir;
}


void solucionPunto6(){
    ArchivoCompra archCp("compras.dat");
    int cant = archCp.contarRegistros();
    Compra reg;

    for (int i=0 ; i<cant ; i++ ){
        reg = archCp.leerRegistro(i);
        if(reg.getFechaCompra().getAnio() == 2022){
            reg.setActivo(false);
            remplazar(reg,i);
        }
    }






}



void mostrarDat(){
    /*ArchivoObras archObras("obras.dat");
    cout << "                   OBRAS.DAT"<<endl;
    cout<<left<<setw(6)<<"Cod"<<setw(20)<<"Dir"<<setw(6)<<"Prov"<<setw(6)<<"Sup"<<setw(6)<<"EsEj"<<setw(6)<<"Estado"<<endl;
    archObras.listarArchivo();
    cout << endl;
    ArchivoMaterial archMate("materiales.dat");
    cout << "                   MATERIALES.DAT" << endl;
    cout<<left<<setw(6)<<"Cod"<<setw(18)<<"Nombre"<<setw(10)<<"Marca"<<setw(6)<<"Tipo"<<setw(6)<<"Prec"<<setw(6)<<"Estado"<<endl;
    archMate.listarArchivo();
    cout << endl;
    ArchivoCompra archComp("compras.dat");
    cout << "                   COMPRAS.DAT" << endl;
    cout<<left<<setw(8)<<"Num Cp"<<setw(8)<<"Num Pv"<<setw(8)<<"C Mat"<<setw(8)<<"C Ob"<<setw(8)<<"Cant"<<setw(8)<<"Imp"<<setw(12)<<"Fecha Comp"<<setw(3)<<"Estado"<<endl;
    archComp.listarArchivo();
    cout << endl;
    ArchivoProveedor archProv("Proveedores.dat");
    cout << "                   PROVEEDORES.DAT" << endl;
    cout<<left<<setw(6)<<"Prvd"<<setw(18)<<"Nombre"<<setw(10)<<"Telefono"<<setw(10)<<"Direccion"<<setw(6)<<"Prov"<<setw(4)<<"Estado"<<endl;
    archProv.listarArchivo();*/
    ArchivoProveedor a("Proveedores.dat");
    a.listarArchivo();
}

int main(){
    setlocale (LC_ALL, "Spanish");

    mostrarDat();

    return 0;
}




