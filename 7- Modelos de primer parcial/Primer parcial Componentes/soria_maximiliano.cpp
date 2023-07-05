#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

#include "parcial1.h"


class Punto1{
private:
    int _codigo;
    char nombre[30];
    Fecha _fecha;
public:
    void setCodigo(int cod){_codigo = cod;}
    void setNombre(const char* nomb){strcpy(nombre,nomb);}
    void setFecha(Fecha fecha){_fecha = fecha;}

    void Mostrar(){
        cout << "Codigo de componente: " << _codigo << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Fecha de ult compra : ";
        _fecha.Mostrar();
    }

};


class ArchivosPunto1{
private:
    char nombre[30];
public:
    ArchivosPunto1(const char *n){
        strcpy(nombre, n);
    }
///ESCRIBIR-------------------------------------------------
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
        reg.setCodigo(-1);
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

///CONSIGNA 1 Y 2 ERAN TEORICAS Y SE RESPONDIAN EL CAMPUS

///CONSIGNA 3 :
            ///GENERAR UN ARCHIVO CON LOS COMPONENTES DE TIPO DE INSTALACION COMPLEMENTATRIA QUE TENGA COMO AÑO DE FECHA
            ///DE LA ULTIMA COMPRA EL AÑO ACTUAL. CADA REGISTRO DEBE TENER EL SIGUIENTE FORMATO: cODIGO, NOMRE Y FECHA.
void SolucionPunto1();

///CONSIGNA 4:
            ///LISTAR EL PRESUPUESTO TOTAL DE LOS PROYECTOS POR CADA UNO DE LOS ESTADOS DE DESARROLLO.
void SolucionPunto2();


int main(){
    setlocale (LC_ALL, "Spanish");

        ArchivoComponente aC("componentes.dat");
        Componente objComp;

        ArchivoProyecto aP("proyectos.dat");
        Proyecto objProy;



        int opc;

    do{
        system("cls");
        cout << "MENU " << endl;
        cout << "1-SOLUCION DEL PUNTO 1 " << endl;
        cout << "2-SOLUCION DEL PUNTO 2 " << endl;
        //cout << "3-CARGAR COMPONENTES " << endl;
        cout << "4-CARGAR PROYECTOS " << endl;
        cout << "0- SALIR" << endl;
        cin >> opc;
        switch (opc){
        case 1:
            system("cls");
            SolucionPunto1();
            system("pause");
            break;
        case 2:
            system("cls");
            SolucionPunto2();
            system ("pause");
            break;
        case 3:
            system("cls");
            objComp.Cargar();

            aC.escribirRegistro(objComp);

            system ("pause");
            break;
        case 4:
            system("cls");
                objProy.Cargar();

                aP.escribirRegistro(objProy);

            system ("pause");
            break;

        case 0:

            break;
            system("pause");
        }

    } while (opc != 0);

    return 0;
}

void SolucionPunto1(){
    ///------------------------------------------
    ArchivoComponente archComp("componentes.dat");
    Componente objComp;

    int cantRegComp = archComp.contarRegistros();

    ///------------------------------------------
    ArchivosPunto1 archP1("punto1.dat");
    Punto1 objP1;

    ///------------------------------------------

    for (int i=0 ; i<cantRegComp ; i++ ){
            objComp = archComp.leerRegistro(i);
        if(objComp.getFecha().getAnio() == 2023 && objComp.getTipo() == 4){
            objP1.setCodigo(objComp.getCodigo());
            objP1.setNombre(objComp.getNombre());
            objP1.setFecha(objComp.getFecha());
            archP1.escribirRegistro(objP1);
        }
    }
   archP1.listarArchivo();
}


void SolucionPunto2(){
    float vecPresupuesto[6] = {};

///---------------------------------------------
    ArchivoProyecto archProy("proyectos.dat");
    Proyecto objProy;

    int cantProy = archProy.contarRegistros();


///---------------------------------------------

    for (int j=0 ; j<cantProy ; j++ ){
        objProy = archProy.leerRegistro(j);
        vecPresupuesto[objProy.getEstadoDesarrollo()-1] += objProy.getPresupuesto();
    }
    for (int i=0 ; i<6 ; i++ ){
        cout << "Estado de desarrollo " << i+1 << " presupuesto total: $" << vecPresupuesto[i] << endl;

    }
}

