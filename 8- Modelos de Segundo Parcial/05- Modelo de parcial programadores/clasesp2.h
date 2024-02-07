

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

        void setImporte(float i){importe = i;}
        void setEstado(bool e){estado=e;}
        void setCategoria(int c){categoria=c;}
        void setDescripcion(const char *d){strcpy(descripcion,d);}
        void setCodigo(int c){codigo=c;}

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
            cout<<endl;
        }

        int leerDeDisco(int pos){
            FILE *p;
            p=fopen("proyectos.dat", "rb");
            if(p==NULL) return -1;
            fseek(p, sizeof *this*pos,0);
            int leyo=fread(this, sizeof *this,1, p);
            fclose(p);
            return leyo;
    }

    int grabarEnDisco(){
        FILE *p;
        p=fopen("proyectos.dat", "ab");
        if(p==NULL) return -1;
        int grabo=fwrite(this, sizeof *this,1, p);
        fclose(p);
        return grabo;
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
        void setLegajoProgramador(int lP){legajoProgramador=lP;}
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
        }
        void Mostrar(){
            cout<<"NUMERO "<<numero<<endl;
            cout<<"LEGAJO "<<legajoProgramador<<endl;
            cout<<"CODIGO "<<codigoProyecto<<endl;
            cout<<"LOCALIDAD "<<localidad<<endl;
            fechaAsignacion.Mostrar();
            cout<<endl;
        }
        int leerDeDisco(int pos){
            FILE *p;
            p=fopen("asignaciones.dat", "rb");
            if(p==NULL) return -1;
            fseek(p, sizeof *this*pos,0);
            int leyo=fread(this, sizeof *this,1, p);
            fclose(p);
            return leyo;
        }

        int grabarEnDisco(){
            FILE *p;
            p=fopen("asignaciones.dat", "ab");
            if(p==NULL) return -1;
            int grabo=fwrite(this, sizeof *this,1, p);
            fclose(p);
            return grabo;
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
        bool activo;
public:
    void Cargar(){
        cout<<"LEGAJO ";cin>>legajo;
        cout<<"NOMBRE ";cargarCadena(nombre,29);
        cout<<"APELLIDO ";cargarCadena(apellido,29);
        cout<<"EMAIL ";cargarCadena(email,29);
        cout<<"TELEFONO ";cargarCadena(telefono,29);
        fechaIngreso.Cargar();
        cout<<"CARGO ";cin>>cargo;
        activo=true;
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
    bool getActivo(){return activo;}
    Fecha getFechaIngreso(){return fechaIngreso;}

    void setActivo(bool a){activo=a;}
    void setCargo(int c){cargo=c;}
    void setlegajo(int np){legajo=np;}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setApellido(const char *a){strcpy(apellido,a);}
    void setEmail(const char *e){ strcpy(email,e);}
    void setTelefono(const char *t){strcpy(telefono,t);}
    void setFechaIngreso(Fecha f){fechaIngreso=f;}

    int leerDeDisco(int pos){
        FILE *p;
        p=fopen("programadores.dat", "rb");
        if(p==NULL) return -1;
        fseek(p, sizeof *this*pos,0);
        int leyo=fread(this, sizeof *this,1, p);
        fclose(p);
        return leyo;
    }

    int grabarEnDisco(){
        FILE *p;
        p=fopen("programadores.dat", "ab");
        if(p==NULL) return -1;
        int grabo=fwrite(this, sizeof *this,1, p);
        fclose(p);
        return grabo;
    }
};

