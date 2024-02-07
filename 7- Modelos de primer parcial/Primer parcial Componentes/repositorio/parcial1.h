///Ejercicio: Parcial 1 de Programación II
///Autor:DEK
///Fecha:
///Comentario:

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
        cargarCadena(codigoProyecto,4);
        cargarCadena(nombre,29);
        cin>>ubicacion;
        cargarCadena(direccion,39);
        cin>>presupuesto;
        cin>>estadoDesarrollo;
        inicio.Cargar();
        activo=true;
    }

    void Mostrar(){
        cout<<codigoProyecto<<endl;
        cout<<nombre<<endl;
        cout<<ubicacion<<endl;
        cout<<direccion<<endl;
        cout<<presupuesto<<endl;
        cout<<estadoDesarrollo<<endl;
        inicio.Mostrar();
        if(!activo) cout<<"ESTA BORRADO"<<endl<<endl;
    }

    const char* getCodigoProyecto(){return codigoProyecto;}
    const char* getNombre(){return nombre;}
    const char* getDireccion(){return direccion;}
    int getUbicacion(){return ubicacion;}
    int getEstadoDesarrollo(){return estadoDesarrollo;}
    float getPresupuesto(){return presupuesto;}
    bool getActivo(){return activo;}
    Fecha getFechaInicio(){return inicio;}

    void setUbicacion(int u){ubicacion=u;}

};

class ArchivoProyecto{
private:
    char nombre[30];
public:
    ArchivoProyecto(const char *n){
        strcpy(nombre, n);
    }
    bool escribirRegistro(Proyecto reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        bool escribio = fwrite(&reg, sizeof reg, 1, p);
        fclose(p);
        return escribio;
    }
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
    int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Proyecto);
    }

};




class Componente{
private:
    int codigo;
    char nombre[30];
    char marca[30];
    int tipo;
    int origen;
    float pu;
    Fecha fechaUltimaCompra;
    bool activo;
public:
    void Cargar(){
        cout << "Codigo: ";
        cin>> codigo;
        cout << "Nombre: ";
        cargarCadena(nombre,29);
        cout << "Fecha: ";
        fechaUltimaCompra.Cargar();
        cout << "Tipo: ";
        cin>>tipo;
        cout << "Origen: ";
        cin>>origen;
        cout << "Pu: ";
        cin>>pu;
        activo=true;
    }
    void Mostrar(){

        cout<<"CODIGO: " << codigo<<endl;
        cout<<"NOMBRE: " << nombre<<endl;
        cout<<"FECHA DE ULTIMA COMPRA: ";
        fechaUltimaCompra.Mostrar();
        //cout<<"MARCA" << marca<<endl;
        cout<<"TIPO: "<< tipo<<endl;
        cout<<"ORIGEN: " << origen << endl;
        cout<<"PRECIO UNITARIO: " << pu<<endl;
        if(!activo) cout<<"ESTA BORRADO"<<endl;
    }
    int getCodigo(){return codigo;}
    int getTipo(){return tipo;}
    const char *getNombre(){return nombre;}
    const char *getMarca(){return marca;}
    int getOrigen(){return origen;}
    float getPU(){return pu;}

    bool getActivo(){return activo;}

    void setCodigo(int cm){codigo=cm;}
    void setTipo(int t){tipo=t;}
    void setNombre(const char *m){strcpy(nombre,m);}
    void setMarca(const char *m){strcpy(marca,m);}
    void setPU(float p){pu=p;}
    void setOrigen(int o){origen=o;}
    void setActivo(bool a){activo=a;}
    Fecha getFecha(){return fechaUltimaCompra;}
};


class ArchivoComponente{
private:
    char nombre[30];
public:
    ArchivoComponente(const char *n){
        strcpy(nombre, n);
    }
    bool escribirRegistro(Componente reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        bool escribio = fwrite(&reg, sizeof reg, 1, p);
        fclose(p);
        return escribio;
    }
    Componente leerRegistro(int pos){
        Componente reg;
        reg.setCodigo(-1);
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
        return tam/sizeof(Componente);
    }
        bool listarArchivo(){
        Componente reg;
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
};


class Tarea{
private:
    int codigo, numeroEmpleado, codigoComponente;
    char nombre[30];
    int codigoProyecto, categoria, tiempo;
    Fecha fechaTarea;
    bool activo;
public:
    void Cargar(){
        cin>>codigo;
        cin>>numeroEmpleado;
        cin>>codigo;
        cargarCadena(nombre,29);
        cin>>codigoProyecto;
        cin>>categoria;
        cin>>tiempo;
        fechaTarea.Cargar();
        activo=true;
    }

    void Mostrar(){
        cout<<codigo<<endl;
        cout<<numeroEmpleado<<endl;
        cout<<codigoComponente<<endl;
        cout<<nombre<<endl;
        cout<<codigoProyecto<<endl;
        cout<<categoria<<endl;
        cout<<tiempo<<endl;
        fechaTarea.Mostrar();
        cout<<endl;
        if(!activo) cout<<"ESTA BORRADO"<<endl<<endl;
    }
    int getCodigo(){return codigo;}
    int getNumeroEmpleado(){return numeroEmpleado;}
    int getCodigoComponente(){return codigoComponente;}
    const char *getNombre(){return nombre;}
    int getCodigoProyecto(){return codigoProyecto;}
    int getCategoria(){return categoria;}
    int getTiempo(){return tiempo;}
    Fecha getFechaTarea(){return fechaTarea;}
    bool getActivo(){return activo;}

    void setCodigoComponente(int c){codigoComponente=c;}


};


class ArchivoTarea{
private:
    char nombre[30];
public:
    ArchivoTarea(const char *n){
        strcpy(nombre, n);
    }
    Tarea leerRegistro(int pos){
        Tarea reg;
        reg.setCodigoComponente(-1);
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
        return tam/sizeof(Tarea);
    }
};

class Empleado{
private:
    int numero;
    char nombre[30];
    char telefono[30];
    char direccion[30];
    int provincia;
    bool activo;
public:
    void Cargar(){
        cin>>numero;
        cargarCadena(nombre,29);
        cargarCadena(telefono,29);
        cargarCadena(direccion,29);
        cin>>provincia;
        activo=true;
    }
    void Mostrar(){
        cout<<numero<<endl;
        cout<<nombre<<endl;
        cout<<telefono<<endl;
        cout<<direccion<<endl;
        cout<<provincia<<endl;
        if(!activo) cout<<"ESTA BORRADO"<<endl<<endl;
    }

    int getNumero(){return numero;}
    int getProvincia(){return provincia;}
    const char *getNombre(){return nombre;}
    const char *getTelefono(){return telefono;}
    const char *getDireccion(){return direccion;}
    bool getActivo(){return activo;}

    void setNumero(int n){numero=n;}
    void setProvincia(int np){provincia=np;}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setTelefono(const char *n){strcpy(telefono,n);}
    void setDireccion(const char *n){strcpy(direccion,n);}
    void setActivo(bool a){activo=a;}

};

class ArchivoEmpleado{
private:
    char nombre[30];
public:
    ArchivoEmpleado(const char *n){
        strcpy(nombre, n);
    }
    Empleado leerRegistro(int pos){
        Empleado reg;
        reg.setNumero(-1);
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
        return tam/sizeof(Empleado);
    }
};
