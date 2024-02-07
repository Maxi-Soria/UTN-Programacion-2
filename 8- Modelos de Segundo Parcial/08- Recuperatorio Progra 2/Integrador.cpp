/*
No entiendo porque la memoria de contarRegistro en la clase ArchivoPunto1 no funciona
(no tiene memoria el puntero) . Es la mismo metodo que se usa en el 'h' del profesor,
esta modificado para que haga referencia a mi propia clase y objeto. Lo comparto con
usted por si alguno paso por el mismo error. Es raro no entiendo que pasa. Chat GPt dice
incoherencias  cuando le pregunto.
*/
# include<iostream>
# include<cstdlib>
# include<cmath>
//Las dos siguientes son para cadena de caracteres
# include<conio.h>
# include<string.h>

using namespace std;

#include "clasesr.h"

class Punto1
{
private :
    int codigo;
    char descripcion[40];
    int cantidad_de_asignaciones;
    bool estado;
public:
    Punto1(Asignacion Obj)
    {
        codigo = 0;
    }
    Punto1() {};


    int getCodigo()
    {
        return codigo;
    }
    const char *getDescripcion()
    {
        return descripcion;
    }
    int getCantidadDeAsignaciones()
    {
        return cantidad_de_asignaciones;
    }
    bool getEstado()
    {
        return estado;
    }

    void setCodigo(int c)
    {
        codigo=c;
    }
    void setDescripcion(const char *d)
    {
        strcpy(descripcion,d);
    }
    void setCantidadDeAsignaciones(int cant )
    {
        cantidad_de_asignaciones = cant;
    }
    void setEstado(bool e)
    {
        estado=e;
    }

    void Mostrar()
    {
        if(estado == 1)
        {
            cout<<"Codigo : ";
            cout<<codigo<<endl;
            cout<<"Descripcion :";
            cout<<descripcion<<endl;
            cout<<"Cantidad de asignaciones ";
            cout<<cantidad_de_asignaciones<<endl<<endl;
        }
    }



    bool operator==(Punto1 Obj)
    {
        cout<<"Ingrese una cadena para compararla (punto 3)"<<endl;
        char palabra[40];
        cargarCadena(palabra, 40);
        if(strcmp(descripcion, palabra)==0)
        {
            return true;
        }
        return false;
    }

};

void PuntoA();

class ArchivoPunto1
{
private:
    char nombre[30];

public:
    ArchivoPunto1(const char *n)
    {
        strcpy(nombre, n);
    }

    Punto1 leerRegistro(int pos)
    {
        Punto1 reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL)
        {
            cout<<"leerRegistro de ArchivoPunto1, falla"<<endl;
            return reg;
        }
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros()
    {
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL)
        {
            cout<<"contarRegistro de ArchivoPunto1, falla"<<endl;
            // fclose(p);
            return -1;
        }
        fseek(p, 0,2);
        int tam=ftell(p);

        fclose(p);
        return tam/sizeof(Punto1);
    }

    bool guardar(Punto1 reg)
    {
        FILE *p = fopen(nombre, "ab");

        if (p == NULL)
        {
            cout<<"guardar de ArchivoPunto1, falla"<<endl;
            return false;
        }

        bool pudoEscribir = fwrite(&reg, sizeof(Punto1), 1, p);
        fclose(p);
        return pudoEscribir;
    }


};

void Punto2();
void Punto5();

int main()
{
    PuntoA();
    return 0;

    ArchivoPunto1 obj("InfoPunto1.dat");
    cout << "cantidad " << obj.contarRegistros() << endl;

    return 0;


    Punto1 Obj1;
    Punto1 Obj2;
    char hola[40];

    cout<<"Ingrese la primera descripcion: ";
    cargarCadena(hola, 40);
    Obj1.setDescripcion(hola);
    cout<<endl<<endl;

    bool resultado = Obj1 == Obj2;
    cout<<"El resultado del operator == es (1=T o 0=F) :  "<<resultado<<endl<<endl;

    system("pause");
    system("cls");

    PuntoA();
    system("pause");
    system("cls");

    Punto2();
    system("pause");
    system("cls");


    Punto5();
    system("pause");
    system("cls");

    system("pause");
    return 0;
}

bool Sobreescribir ( int pos, Asignacion reg222);

bool Sobreescribir ( int pos, Asignacion reg222)
{
    ArchivoAsignacion reg("Asignaciones.dat");
    FILE *p = fopen("Asignaciones.dat", "rb+");

    if (p == NULL)
    {
        cout<<"No se pudo abrir el archivo para sobreescribirlo  "<<endl;
        system("pause");
        return false;
    }

    fseek(p, pos * sizeof(reg222), 0);


    bool modificacion = fwrite(&reg222, sizeof(reg222), 1, p);
    fclose(p);
    return modificacion;
}


void Punto2()
{

    Asignacion Responsab;
    ArchivoAsignacion ArcResponsab("Asignaciones.dat");

    int tope= ArcResponsab.contarRegistros();

    for(int i=0 ; i<tope; i++)
    {
        Responsab = ArcResponsab.leerRegistro(i);

        if(Responsab.getFechaAsignacion().getAnio() == 2022)
        {
            Responsab.setEstado(0);
///La siguiente linea de codigo la entregue compilando, es decir, sin comentar.Falta de analisis.
            // Sobreescribir( i , Responsab);


        }
///Linea de codigo agregada despues del parcial:
        if(Responsab.getFechaAsignacion().getAnio() != 2022)
        {


            Sobreescribir( i, Responsab);


        }
///Revisar el codigo con mas tiempo ya que hoy rindo estadistica
    }


    Asignacion Respons;
    ArchivoAsignacion ArcRespons("Asignaciones.dat");

    for(int k =0; k<tope ; k++)
    {
        Respons = ArcRespons.leerRegistro(k);


        if(Respons.getEstado() == true)
        {

            Respons.Mostrar();

        }

    }

}




void PuntoA()
{
    Proyecto ProyecLatinoamerica;
    ArchivoProyecto ArcProyecLatinoamerica("Proyecto.dat");

    Asignacion Responsabilidad;
    ArchivoAsignacion ArcResponsabilidad("Asignaciones.dat");

    Punto1 ObjPunto1;
    ArchivoPunto1 ArcPunto1("InfoPunto1.dat");

    int tope_Proyecto_Latinoamerica = ArcProyecLatinoamerica.contarRegistros();

    int tope_Responsabilidad = ArcResponsabilidad.contarRegistros();

    int cont_de_asignaciones=0;

    for(int i=0 ; i<tope_Proyecto_Latinoamerica ; i++)
    {
        ProyecLatinoamerica = ArcProyecLatinoamerica.leerRegistro(i);

        if(ProyecLatinoamerica.getEstado() == true)
        {
            for(int k=0 ; k <tope_Responsabilidad ; k++)
            {
                Responsabilidad = ArcResponsabilidad.leerRegistro(k);

                if(Responsabilidad.getEstado() == true  &&  Responsabilidad.getCodigoProyecto() == ProyecLatinoamerica.getCodigo() )
                {
                    cont_de_asignaciones++;

                }

            }

            ObjPunto1.setCodigo(Responsabilidad.getCodigoProyecto());
            ObjPunto1.setDescripcion(ProyecLatinoamerica.getDescripcion());
            ObjPunto1.setCantidadDeAsignaciones(cont_de_asignaciones);
            ObjPunto1.setEstado(1);

            cont_de_asignaciones=0;

            ArcPunto1.guardar(ObjPunto1);

        }


    }



    int tope_Nuevo_Archivo_p1 = ArcPunto1.contarRegistros();
    Punto1 RegMostrar;

    for(int i =0 ; i<tope_Nuevo_Archivo_p1 ; i++)
    {
        RegMostrar = ArcPunto1.leerRegistro(i);

        RegMostrar.Mostrar();



    }

}



void Punto5()
{
    ArchivoAsignacion ArcAsig("Asignaciones.dat");
    Asignacion* vPuntoE;
    int tam= ArcAsig.contarRegistros();
///vPuntoD=new vPuntoD[tam];  esta es la linea incorrecta
    vPuntoE=new Asignacion[tam];
    if(vPuntoE == NULL)
    {
        cout<<" no se pudo asignar memoria al vector de objetos"<<endl;
        return;
    }
    for(int i=0; i<tam; i++)
    {
        vPuntoE[i] =ArcAsig.leerRegistro(i);
    }

    for(int i=0; i<tam; i++)
    {
        ///Me faltaron los parentesis a vPuntoD[i].Mostrar
        if(vPuntoE[i].getEstado() ==true )
        {
            vPuntoE[i].Mostrar();
        }
    }
    delete [] vPuntoE;
}

