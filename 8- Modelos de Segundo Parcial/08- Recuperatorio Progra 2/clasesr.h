#ifndef CLASESR_H_INCLUDED
#define CLASESR_H_INCLUDED



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
    void Cargar(){
        cout<<"DIA ";cin>>dia;
        cout<<"MES ";cin>>mes;
        cout<<"ANIO ";cin>>anio;
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
        int codigo;
        int categoria;
        char descripcion[40];
        float importe;
        bool estado;
    public:
        int getCodigo(){return codigo;}
        int getCategoria(){return categoria;}
        const char *getDescripcion(){return descripcion;}
        float getImporte(){return importe;}
        bool getEstado(){return estado;}

        void setCodigo(int c){codigo=c;}
        void setCategoria(int c){categoria=c;}
        void setDescripcion(const char *d){strcpy(descripcion,d);}

        void setImporte(float i){importe = i;}
        void setEstado(bool e){estado=e;}

        void Cargar(){
            cout<<"CODIGO ";cin>>codigo;
            cout<<"CATEGORIA ";cin>>categoria;
            cout<<"DESCRIPCION ";cargarCadena(descripcion,39);
            cout<<"IMPORTE ";cin>>importe;
            estado=true;
        }
        void Mostrar(){
            cout<<"CODIGO "<<codigo<<endl;
            cout<<"CATEGORIA"<<categoria<<endl;
            cout<<"DESCRIPCION "<<descripcion<<endl;
            cout<<"IMPORTE "<<importe<<endl;
            cout<<endl<<endl;
        }

};


class ArchivoProyecto{
private:
    char nombre[30];
public:
    ArchivoProyecto(const char *n){
        strcpy(nombre, n);
    }
    Proyecto leerRegistro(int pos){
        Proyecto reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Proyecto);
    }
    bool escribirRegistro(Proyecto reg) {
        FILE* p;
        p = fopen(nombre, "ab");
        if (p == NULL) return false;
        bool escribio = fwrite(&reg, sizeof reg, 1, p);
        fclose(p);
        return escribio;
    }

};


class Asignacion{
    private:
        int numero;
        int legajoProgramador;
        int codigoProyecto;
        int localidad;
        Fecha fechaAsignacion;
        bool estado;
    public:
        void setEstado(bool e){estado = e;}
        void setCodigoProyecto(int cP){codigoProyecto=cP;}

        void setNumero(int n){numero=n;}
        void setLegajoProgramador(int l){legajoProgramador=l;}
        void setLocalidad(int l){localidad=l;}
        void setFechaAsignacion(Fecha f){fechaAsignacion=f;}


        int getNumero(){return numero;}
        int getLegajoProgramador(){return legajoProgramador;}
        int getCodigoProyecto(){return codigoProyecto;}
        int getLocalidad(){return localidad;}
        Fecha getFechaAsignacion(){return fechaAsignacion;}
        bool getEstado(){return estado;}
        void Cargar(){
            cout<<"NUMERO ";cin>>numero;
            cout<<"LEGAJO ";cin>>legajoProgramador;
            cout<<"CODIGO ";cin>>codigoProyecto;
            cout<<"LOCALIDAD ";cin>>localidad;
            cout<<"FECHA "<<endl;fechaAsignacion.Cargar();
            estado=true;
        }
        void Mostrar(){
            cout<<"NUMERO "<<numero<<endl;
            cout<<"LEGAJO "<<legajoProgramador<<endl;
            cout<<"CODIGO "<<codigoProyecto<<endl;
            cout<<"LOCALIDAD "<<localidad<<endl;
            fechaAsignacion.Mostrar();
            cout<<endl;
        }
};

class ArchivoAsignacion{
private:
    char nombre[30];
public:
    ArchivoAsignacion(const char *n){
        strcpy(nombre, n);
    }
    Asignacion leerRegistro(int pos){
        Asignacion reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Asignacion);
    }

};



class Programador{
private:
        int legajo;
        char nombre[30];
        char apellido[30];
        char email[40];
        char telefono[20];
        Fecha fechaIngreso;
        int cargo;
        bool estado;
public:
    void Cargar(){
        cout<<"LEGAJO ";cin>>legajo;
        cout<<"NOMBRE ";cargarCadena(nombre,29);
        cout<<"APELLIDO ";cargarCadena(apellido,29);
        cout<<"EMAIL ";cargarCadena(email,29);
        cout<<"TELEFONO ";cargarCadena(telefono,29);
        fechaIngreso.Cargar();
        cout<<"CARGO ";cin>>cargo;
        estado=true;
    }
    void Mostrar(){
        cout<<"LEGAJO "<<legajo<<endl;
        cout<<"NOMBRE "<<nombre<<endl;
        cout<<"APELLIDO "<<apellido<<endl;
        cout<<"EMAIL "<<email<<endl;
        cout<<"TELEFONO "<<telefono<<endl;
        fechaIngreso.Mostrar();
        cout<<"CARGO "<<cargo<<endl<<endl;
    }

    int getLegajo(){return legajo;}
    int getCargo(){return cargo;}
    const char *getNombre(){return nombre;}
    const char *getApellido(){return apellido;}
    const char *getEmail(){return email;}
    const char *getTelefono(){return telefono;}
    bool getEstado(){return estado;}
    Fecha getFechaIngreso(){return fechaIngreso;}


    void setlegajo(int np){legajo=np;}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setApellido(const char *n){strcpy(apellido,n);}
    void setEmail(const char *n){strcpy(email,n);}
    void setTelefono(const char *n){strcpy(telefono,n);}
    void setCargo(int c){cargo=c;}

    void setFechaIngreso(Fecha f){fechaIngreso=f;}
    void setEstado(bool a){estado=a;}

};

class ArchivoProgramador{
private:
    char nombre[30];
public:
    ArchivoProgramador(const char *n){
        strcpy(nombre, n);
    }
    Programador leerRegistro(int pos){
        Programador reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Programador);
    }

};


#endif // CLASESR_H_INCLUDED
