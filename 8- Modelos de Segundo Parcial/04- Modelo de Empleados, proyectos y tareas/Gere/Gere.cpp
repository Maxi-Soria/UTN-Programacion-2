#include <iostream>
using namespace std;
#include <cstring>
#include "parcial1.h"

/*
a) Generar un archivo con la cantidad de tareas para cada uno de los proyectos.
Cada registro debe tener Código de proyecto, nombre y cantidad de tareas
1) Archivos necesarios: tareas y proyectos
2) Necesito una nueva clase para darle formato al registro, y una clase para generar y manejar el archivo.
3) Empiezo por proyectos (código y el nombre), y con una función averiguo la cantidad de tareas (en el archivo tareas) que coincidan con el código de proyecto leído.
Repito por cada proyecto.

b) Generar un archivo con el tiempo trabajado por cada empleado en el mes de mayo.
Cada registro debe tener el siguiente formato
número de empleado,nombre y cantidad de horas
1) Archivos: empleados y tareas
2) Necesito una nueva clase para darle formato al registro, y una clase para generar y manejar el archivo.
3) Empiezo por empleados, y luego suma la cantidad de horas de las tareas del mes de mayo correspondientes al empleado que leí.
3 a)Empiezo por empleados. Con un vector de 60 sumo las horas del mes de mayo de cada empleado (utilizo como índice del vector el número de empleado -1.
Luego leo cada registro de empleados, y asocio la cantidad con el número de empleado leído.

c) Informar para cada uno de los empleados la cantidad total de tareas realizadas de cada categoría. Informe el nombre del empleado y la cantidad de tareas
1) Archivos: empleados y tareas.
2) No necesito una clase nueva.
3) Puedo usar un vector que inicializo en 0 con cada empleado, o podría usar (60x5) una matriz.

d) Para cada origen, informar la cantidad de componentes de cada tipo.
Archivo/s: componentes

e) Dar de baja a todos los componentes de origen europeo

f) Listar el archivo del punto a usando asignación dinámica de memoria
*/

class PuntoA
{
  private:
      char _codigoProyecto[5];
      char _nombreProyecto[30];
      int _cantidadTareas;
  public:
    void Mostrar(){
        cout << _codigoProyecto << "   " << _nombreProyecto << endl;
    }
    const char* getCodigoProyecto(){return _codigoProyecto;}
    const char* getNombreProyecto(){return _nombreProyecto;}
    int getCantidadTareas(){return _cantidadTareas;}
    void setCodigoProyecto(const char* codigoProyecto)

    {
        strcpy(_codigoProyecto,codigoProyecto);
    }
    void setNombreProyecto(const char* nombreProyecto)
    {
        strcpy(_nombreProyecto,nombreProyecto);
    }
    void setCantidadTareas(int cantidadTareas)
    {
        _cantidadTareas = cantidadTareas;
    }
    operator++(int)
    {
        _cantidadTareas++;
    }
};

class ArchivoPuntoA
{
private:
    char _nombre[30];
public:
    ArchivoPuntoA(const char* nombre)
    {
        strcpy(_nombre,nombre);
    }
    void vaciar()
    {
       FILE *p = fopen(_nombre, "wb");
        if (p == NULL)
        {
            return ;
        }
        fclose(p);
    }
    bool GuardarRegistro(PuntoA reg)
    {
        FILE *p = fopen(_nombre, "ab");

        if (p == NULL)
        {
            return false;
        }

        bool pudoEscribir = fwrite(&reg, sizeof(PuntoA), 1, p);
        fclose(p);
        return pudoEscribir;
    }
    int contarRegistros(){
        FILE *p;
        p=fopen(_nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(PuntoA);
    }

    PuntoA leerRegistro(int pos){
        PuntoA reg;
        reg.setCantidadTareas(-1);
        FILE *p;
        p=fopen(_nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof(PuntoA)*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
};

class PuntoB
{
private:
    int _numero;
    char _nombre[30];
    int _tiempo;

public:
    int getTiempo(){return _tiempo;}

    void setNombre(const char* nombre)
    {
        strcpy(_nombre,nombre);
    }
    void setNumero(int numero){_numero = numero;}
    void setTiempo(int tiempo){_tiempo = tiempo;}

    operator++(int)
    {
        _tiempo++;
    }
};

class ArchivoPuntoB
{
private:
    char _nombre[30];
public:
    ArchivoPuntoB(const char* nombre)
    {
        strcpy(_nombre,nombre);
    }
    void vaciar()
    {
       FILE *p = fopen(_nombre, "wb");
        if (p == NULL)
        {
            return ;
        }
        fclose(p);
    }
    bool GuardarRegistro(PuntoB reg)
    {
        FILE *p = fopen(_nombre, "ab");

        if (p == NULL)
        {
            return false;
        }

        bool pudoEscribir = fwrite(&reg, sizeof(PuntoB), 1, p);
        fclose(p);
        return pudoEscribir;
    }
    int contarRegistros(){
        FILE *p;
        p=fopen(_nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(PuntoB);
    }

};

void puntoA()
{
    Proyecto proyecto;
    ArchivoProyecto archProyecto("proyectos.dat");
    int cantProyectos = archProyecto.contarRegistros();
    Tarea tarea;
    ArchivoTarea archTarea("tareas.dat");
    int cantTareas = archTarea.contarRegistros();
    PuntoA reg;
    ArchivoPuntoA archPuntoA("puntoA.dat");
    archPuntoA.vaciar();

    for(int i=0; i<cantProyectos; i++)
    {
        proyecto = archProyecto.leerRegistro(i);

        reg.setCantidadTareas(0);
        for(int j=0; j<cantTareas; j++)
        {
            tarea = archTarea.leerRegistro(j);
            if(strcmp(proyecto.getCodigoProyecto(),tarea.getCodigoProyecto()) == 0)
            {
               reg++;
            }
        }
        reg.setNombreProyecto(proyecto.getNombre());
        reg.setCodigoProyecto(proyecto.getCodigoProyecto());
        archPuntoA.GuardarRegistro(reg);
        reg.Mostrar();
    }
}

void puntoB()
{
    ArchivoEmpleado archEmpleado("empleado.dat");
    int cantEmpleados = archEmpleado.contarRegistros();

    ArchivoTarea archTareas("tareas.dat");
    int cantTareas = archTareas.contarRegistros();

    ArchivoPuntoB archPuntoB("puntoB.dat");
    archPuntoB.vaciar();
    PuntoB pb;

    for(int i=0; i<cantEmpleados; i++)
    {
        Empleado emp = archEmpleado.leerRegistro(i);
        pb.setTiempo(0);
        for(int j=0; j<cantTareas; j++)
        {
            Tarea tarea = archTareas.leerRegistro(j);
            if(emp.getNumero() == tarea.getNumeroEmpleado() && tarea.getFechaTarea().getMes() == 5)
            {
                pb++;
            }
        }
        pb.setNombre(emp.getNombre());
        pb.setNumero(emp.getNumero());
        archPuntoB.GuardarRegistro(pb);
    }



}

void puntoC()
{
    const int CATEGORIAS = 6;
    ArchivoEmpleado archEmp("empleado.dat");
    int cantEmp = archEmp.contarRegistros();

    Tarea tarea;
    ArchivoTarea archTarea("tareas.dat");
    int cantTarea = archTarea.contarRegistros();

    for(int i=0; i<cantEmp; i++)
    {
        int tareas[CATEGORIAS]{};
        Empleado emp = archEmp.leerRegistro(i);

        for(int j=0; j<cantTarea; j++)
        {
            tarea = archTarea.leerRegistro(j);
            if(emp.getNumero() == tarea.getNumeroEmpleado())
            {
                tareas[tarea.getCategoria()-1]++;
            }


        }
        cout << "Empleado " << emp.getNumero() << ": " << endl;
        for(int j=0; j<CATEGORIAS; j++)
        {
            cout << "C" << j+1 << ": " << tareas[j] << " - ";
        }
        cout << endl;
    }
}

void puntoD()
{
    const int CANT_ORIGEN = 6, CANT_TIPOS = 6;
    ArchivoComponente archCom("componentes.dat");
    int cantComp = archCom.contarRegistros();
    int compSegunOrigen[CANT_ORIGEN][CANT_TIPOS]={};

    for(int i=0; i<cantComp; i++)
    {
        Componente comp = archCom.leerRegistro(i);
        compSegunOrigen[comp.getOrigen()-1][comp.getTipo()-1]++;
    }

    for(int i=0; i<CANT_ORIGEN; i++)
    {
        cout << "Origen: " << i+1 << endl;
        for(int j=0; j<CANT_TIPOS; j++)
        {
            cout << "Tipo" << j+1 << ": " << compSegunOrigen[i][j] << " ";
        }
        cout << endl;
    }
}
void puntoE()
{
    ArchivoComponente archComp("componentes.dat");
    int cantComp = archComp.contarRegistros();
    Componente comp;

    for(int i=0; i<cantComp; i++)
    {
        comp = archComp.leerRegistro(i);
        if(comp.getOrigen() == 5)
        {
            comp.setActivo(false);
            FILE *p = fopen("componentes.dat", "rb+");

            if (p == NULL)
            {
                cout << "No se pudo abrir el archivo"<<endl;
            }

            fseek(p, i * sizeof(Componente), 0);
            fwrite(&comp, sizeof(Componente), 1, p);
            fclose(p);
        }
        if(!comp.getActivo())
        {
            cout << "1" << endl;
        }
    }
}

void puntoF()
{
    ArchivoPuntoA auxArchivoPuntoA("puntoA.dat");

    int cantReg = auxArchivoPuntoA.contarRegistros();

    PuntoA *puntoA = new PuntoA[cantReg];

    for(int i=0; i<cantReg; i++)
    {
        puntoA[i] = auxArchivoPuntoA.leerRegistro(i);
    }

    for(int i=0; i<cantReg; i++)
    {
        cout << "Nombre: " << puntoA[i].getNombreProyecto() << endl;
        cout << "Codigo: " << puntoA[i].getCodigoProyecto() << endl;
        cout << "Cant Tareas: " << puntoA[i].getCantidadTareas() << endl;
        cout << "--------------------" << endl;
    }
    delete[] puntoA;
}

int main()
{
    puntoA();
   //puntoB();
    //puntoC();
    //puntoD();
    //puntoE();
    //puntoF();
    return 0;
}
