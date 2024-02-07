#include <iostream>
#include <cstring>

using namespace std;
void cargarCadena(char *pal, int tam){
    int i;
    fflush(stdin);
    for(i=0; i<tam; i++)
    {
        pal[i]=cin.get();
        if(pal[i]=='\n') break;
    }
    pal[i]='\0';
    fflush(stdin);
}


class Fecha{
private:
    int dia,mes, anio;
public:
    bool operator==(Fecha obj){
        if(dia != obj.dia) return false;
        if(mes != obj.mes) return false;
        if(anio != obj.anio) return false;
        return true;
    }
    void Cargar(){
        cin>>dia;
        cin>>mes;
        cin>>anio;
    }
    void Mostrar(){
        cout<<dia<<"/";
        cout<<mes<<"/";
        cout<<anio<<endl;
    }
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}

    void setDia(int d){dia=d;}
    void setMes(int m){mes=m;}
    void setAnio(int a){anio=a;}

};




class Proyecto{
private:
    char codigoProyecto[5];
    char nombre[30];
    int ubicacion;
    char direccion[40];
    float presupuesto;
    int estadoDesarrollo;
    Fecha inicio;
    bool activo;
public:
    void Cargar(){
        cout << "Ingrese Codigo de Proyecto: ";
        cargarCadena(codigoProyecto,4);
        cout << "Ingrese el nombre: ";
        cargarCadena(nombre,29);
        cout << "Ingrese la ubicacion: ";
        cin>>ubicacion;
        cout << "Ingrese la direccion: ";
        cargarCadena(direccion,39);
        cout << "Ingrese el presupuesto: ";
        cin>>presupuesto;
        cout << "Ingrese el estado de desarrollo: ";
        cin>>estadoDesarrollo;
        cout << "Ingrese la fecha: ";
        inicio.Cargar();
        activo=true;
    }

    void Mostrar(){
        cout<<codigoProyecto<<"\t";
        cout<<nombre<<"\t";
        cout<<ubicacion<<"\t";
        cout<<direccion<<"\t";
        cout<<presupuesto<<"\t";
        cout<<estadoDesarrollo<<"\t";
        inicio.Mostrar();
        if(!activo) cout<<"ESTA BORRADO"<<endl<<endl;
    }

    const char* getCodigoProyecto(){return codigoProyecto;}
    const char* getNombre(){return nombre;}
    int getUbicacion(){return ubicacion;}
    const char* getDireccion(){return direccion;}
    int getEstadoDesarrollo(){return estadoDesarrollo;}
    float getPresupuesto(){return presupuesto;}
    Fecha getFechaInicio(){return inicio;}
    bool getActivo(){return activo;}

    void setCodigoProyecto(const char *c){strcpy(codigoProyecto,c);}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setUbicacion(int u){ubicacion=u;}
    void setDireccion(const char *d){strcpy(direccion,d);}
    void setEstadoDesarrollo(int e){estadoDesarrollo=e;}
    void setPresupuesto(float p){presupuesto = p;}
    void setFechaInicio(Fecha f){inicio=f;}
    void setActivo(bool a){activo=a;}
};

class ArchivoProyecto{
private:
    char nombre[30];
public:
    ArchivoProyecto(const char *n){
        strcpy(nombre, n);
    }
    ///--------------------------------------
    Proyecto leerRegistro(int pos){
        Proyecto reg;
        reg.setUbicacion(-1);
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof(Proyecto)*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    ///---------------------------------------
    int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Proyecto);
    }
    ///---------------------------------------
    bool remplazarReg(Proyecto reg, int pos){
        FILE *p = fopen(nombre, "rb+");
        if (p == NULL){return false;}
        fseek(p, pos * sizeof(Proyecto), SEEK_SET);
        bool pudoEscribir = fwrite(&reg, sizeof(Proyecto), 1, p);
        fclose(p);
        return pudoEscribir;
    }
    ///---------------------------------------
    bool listarArchivo() {
        Proyecto reg;
        FILE* p;
        p = fopen(nombre, "rb");
        if (p == NULL) {
            cout << "No se pudo abrir el archivo." << endl;
            return false;
        }
        while (fread(&reg, sizeof reg, 1, p) == 1) {
            reg.Mostrar();
            cout << endl;
        }
        fclose(p);
        return true;
    }
    ///---------------------------------------
    bool escribirRegistro(Proyecto reg) {
        FILE* p;
        p = fopen(nombre, "ab");
        if (p == NULL) return false;
        bool escribio = fwrite(&reg, sizeof reg, 1, p);
        fclose(p);
        return escribio;
    }
    ///-------------------------------------------
    void vaciar(){
        FILE *p = fopen(nombre, "wb");
        if (p == NULL){return ;}
        fclose(p);
    }


};

///FUNCION GLOBAL PARA REMPLAZAR UN REGISTRO
bool funcionRemplazarReg(Proyecto reg, int pos){
        FILE *p = fopen("registroQueVoyaAbrir.dat", "rb+");
        if (p == NULL){return false;}
        fseek(p, pos * sizeof(Proyecto), SEEK_SET);
        bool pudoEscribir = fwrite(&reg, sizeof(Proyecto), 1, p);
        fclose(p);
        return pudoEscribir;
}

///EJEMPLO DE SOBRECARGA DE CONSTRUCTOR == sin strcmp()
/*
bool operator == (Ciudades aux){
    if(_CodigoCiudad == aux.getCodigoCiudad()){
        return true;
    }else{
    return false;}
}
*/




int main(){
    setlocale (LC_ALL, "Spanish");

    Proyecto obj;
    obj.Cargar();

    return 0;
}
