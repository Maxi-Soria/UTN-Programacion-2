#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>

using namespace std;

#include "parcial1.h"


class PuntoA{
private:
    char _codigo[5];
    char nombre[30];
    int  _cantTareas;
public:
    void setCodigo(const char* cod){strcpy(_codigo,cod);}
    void setNombre(const char* nomb){strcpy(nombre,nomb);}
    void setCantTareas(int cantTareas){_cantTareas = cantTareas;}

    void Mostrar(){
        cout << left<<setw(6)<< _codigo << setw(15)<<nombre << setw(3)<< _cantTareas<<endl ;

    }

};

class ArchivosPuntoA{
private:
    char nombre[30];
public:
    ArchivosPuntoA(const char *n){
        strcpy(nombre, n);
    }
///ESCRIBIR-------------------------------------------------
    bool escribirRegistro(PuntoA reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        bool escribio = fwrite(&reg, sizeof reg, 1, p);
        fclose(p);
        return escribio;
    }
    ///LEER -------------------------------------------------
    PuntoA  leerRegistro(int pos){
        PuntoA reg;
        reg.setCantTareas(-1);
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof(PuntoA)*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    ///LISTAR ------------------------------------------------------
    bool listarArchivo(){
        PuntoA reg;
        FILE *p;
        p = fopen(nombre, "rb");
        if (p == NULL){
        cout << "No se pudo abrir " << endl;
        return false;
        }
        while (fread(&reg, sizeof reg, 1, p)==1 ){
        reg.Mostrar();
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
        return tam/sizeof(PuntoA);
    }
    ///VACIAR-----------------------------------------------
    void vaciar(){
        FILE *p = fopen(nombre, "wb");
        if (p == NULL)
        {
            return ;
        }
        fclose(p);
    }
};



class PuntoB{
private:
    int _numeroEmp;
    char nombre[30];
    int  _cantHoras;
public:
    void setNumEmpleado(int num){_numeroEmp = num;}
    void setNombre(const char* nomb){strcpy(nombre,nomb);}
    void setCantHoras(int cantHoras){_cantHoras = cantHoras;}

    int getNumEmpleado(){return _numeroEmp;}

    void Mostrar(){
        cout << left<<setw(6)<< _numeroEmp << setw(20)<<nombre << setw(4)<< _cantHoras;

    }

};

class ArchivosPuntoB{
private:
    char nombre[30];
public:
    ArchivosPuntoB(const char *n){
        strcpy(nombre, n);
    }
///ESCRIBIR-------------------------------------------------
    bool escribirRegistro(PuntoB reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        bool escribio = fwrite(&reg, sizeof reg, 1, p);
        fclose(p);
        return escribio;
    }
    ///LEER -------------------------------------------------
    PuntoB  leerRegistro(int pos){
        PuntoB reg;
        reg.setCantHoras(-1);
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof(PuntoB)*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    ///LISTAR ------------------------------------------------------
    bool listarArchivo(){
        PuntoB reg;
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
        return tam/sizeof(PuntoB);
    }
    ///VACIAR-----------------------------------------------
    void vaciar(){
        FILE *p = fopen(nombre, "wb");
        if (p == NULL)
        {
            return ;
        }
        fclose(p);
    }
};

void SolucionPuntoA();
void SolucionPuntoB();
void SolucionPuntoC();
void SolucionPuntoD();
void SolucionPuntoE();
void SolucionPuntoF();


int main(){
    setlocale (LC_ALL, "Spanish");

    /*ArchivoComponente ob("componentes.dat");
    ob.listarArchivo();
    SolucionPuntoA();*/
    ArchivosPuntoA obj("puntoA.dat");
    obj.listarArchivo();
    cout<<endl;

    /*SolucionPuntoB();
    ArchivosPuntoB archPB("puntoB.dat");
    archPB.listarArchivo();
    cout<<endl;

    SolucionPuntoC();
    cout << endl;
    SolucionPuntoD();
    cout << endl;
    SolucionPuntoE();
    cout << endl;
    SolucionPuntoF();*/




    return 0;
}

void SolucionPuntoA(){
    ///------------------------------------------
    ArchivoProyecto archProy("proyectos.dat");
    Proyecto regProy;
    int cantRegProy = archProy.contarRegistros();


    ArchivoTarea archTarea("tareas.dat");
    Tarea regTarea;
    int cantTareas = archTarea.contarRegistros();

    ///------------------------------------------
    ArchivosPuntoA archPA("puntoA.dat");
    PuntoA objPA;
    archPA.vaciar();

    ///------------------------------------------
    for (int i=0 ; i<cantRegProy ; i++ ){
        regProy = archProy.leerRegistro(i);

        int cantProyectos = 0;
        for (int j=0 ; j<cantTareas ; j++ ){
            regTarea = archTarea.leerRegistro(j);
            if(strcmp(regProy.getCodigoProyecto(),regTarea.getCodigoProyecto()) == 0){
                cantProyectos++;
            }
        }
        objPA.setCodigo(regProy.getCodigoProyecto());
        objPA.setNombre(regProy.getNombre());
        objPA.setCantTareas(cantProyectos);
        archPA.escribirRegistro(objPA);
    }
}


void SolucionPuntoB(){

    ArchivoEmpleado archEmp("empleado.dat");
    Empleado regEmp;
    int cantRegEmp = archEmp.contarRegistros();


    ArchivoTarea archTarea("tareas.dat");
    Tarea regTarea;
    int cantTareas = archTarea.contarRegistros();


    ArchivosPuntoB archPB("puntoB.dat");
    PuntoB objPB;
    archPB.vaciar();


    for (int i=0 ; i<cantRegEmp ; i++ ){
         regEmp = archEmp.leerRegistro(i);

         int acuHoras = 0;

        for (int j=0 ; j<cantTareas ; j++ ){

            regTarea = archTarea.leerRegistro(j);
            if(regEmp.getNumero() == regTarea.getNumeroEmpleado() && regTarea.getFechaTarea().getMes() == 5){
                acuHoras += regTarea.getTiempo();
            }
        }

        objPB.setNumEmpleado(regEmp.getNumero());
        objPB.setNombre(regEmp.getNombre());
        objPB.setCantHoras(acuHoras);
        archPB.escribirRegistro(objPB);

    }
}



void SolucionPuntoC(){

    ArchivoEmpleado archEmp("empleado.dat");
    Empleado regEmp;
    int cantRegEmp = archEmp.contarRegistros();

    ArchivoTarea archTarea("tareas.dat");
    Tarea regTarea;
    int cantTareas = archTarea.contarRegistros();

    cout << "   NOMBRE          C1  C2  C3  C4  C5"<<endl;
    for (int i=0 ; i<cantRegEmp ; i++ ){
         regEmp = archEmp.leerRegistro(i);

        int vTar[5]={};

        for (int j=0 ; j<cantTareas ; j++ ){

            regTarea = archTarea.leerRegistro(j);
            if(regEmp.getNumero() == regTarea.getNumeroEmpleado()){
                vTar[regTarea.getCategoria()-1]++;
            }
        }
        cout << left<<setw(20)<<regEmp.getNombre()<<setw(4)<<vTar[0]<<setw(4)<<vTar[1]<<setw(4)<<vTar[2]<<setw(4)<<vTar[3]<<setw(4)<<vTar[4]<<endl;

    }
}


void SolucionPuntoD(){
    int mat[6][6]={};
    ArchivoComponente archComp("componentes.dat");
    Componente reg;
    int cant = archComp.contarRegistros();

    for (int i=0 ; i<cant ; i++ ){
        reg = archComp.leerRegistro(i);
        mat[reg.getOrigen()-1][reg.getTipo()-1]++;
    }

    for (int i=0 ; i<6 ; i++ ){
        cout << "Origen:" << i+1 << endl;
        for (int j=0 ; j<6 ; j++ ){
            cout << "Tipo "<<j+1<<": "<<mat[i][j]<<endl;
        }
        cout<<endl;
    }
}


void SolucionPuntoE(){

    ArchivoComponente archComp("componentes.dat");
    Componente reg;
    int cant = archComp.contarRegistros();

    for (int i=0 ; i<cant ; i++ ){
        reg = archComp.leerRegistro(i);
        if(reg.getOrigen() == 5){
            reg.setActivo(true);
        }


        archComp.remplazarReg(reg, i);

    }
        archComp.listarArchivo();

}


void SolucionPuntoF(){
    ArchivosPuntoA archPA("puntoA.dat");
    int cantReg = archPA.contarRegistros();

    PuntoA* vec = nullptr;
    vec = new PuntoA[cantReg];
    if(vec == nullptr)return;

    for (int i=0 ; i<cantReg ; i++ ){
        vec[i] = archPA.leerRegistro(i);
        vec[i].Mostrar();
    }


}










