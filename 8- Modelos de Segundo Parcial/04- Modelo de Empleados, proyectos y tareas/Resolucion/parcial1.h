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
        cout<<setw(2)<<dia<<"/"<<setw(2)<<mes<<"/"<<setw(6)<<anio;
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
        cout<<left<<setw(6)<<codigoProyecto;
        cout<<setw(12)<<nombre;
        cout<<setw(4)<<ubicacion;
        cout<<setw(24)<<direccion;
        cout<<setw(8)<<presupuesto;
        cout<<setw(3)<<estadoDesarrollo;
        inicio.Mostrar();
        if(!activo) cout<<"ESTA BORRADO"<<endl;
    }

    const char* getCodigoProyecto(){return codigoProyecto;}
    const char* getNombre(){return nombre;}
    const char* getDireccion(){return direccion;}
    int getUbicacion(){return ubicacion;}
    int getEstadoDesarrollo(){return estadoDesarrollo;}
    float getPresupuesto(){return presupuesto;}
    bool getActivo(){return activo;}
    Fecha getFechaInicio(){return inicio;}

    void setCodigoProyecto(const char *c){strcpy(codigoProyecto,c);}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setDireccion(const char *d){strcpy(direccion,d);}
    void setEstadoDesarrollo(int e){estadoDesarrollo=e;}
    void setPresupuesto(float p){presupuesto = p;}
    void setActivo(bool a){activo=a;}
    void setFechaInicio(Fecha f){inicio=f;}
    void setUbicacion(int u){ubicacion=u;}

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
        ///****************************
    bool listarArchivo(){
        Proyecto reg;
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

    ///ESCRIBIR-------------------------------------------------
    bool escribirRegistro(Proyecto reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        bool escribio = fwrite(&reg, sizeof reg, 1, p);
        fclose(p);
        return escribio;
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
        cin>>codigo;
        cargarCadena(nombre,29);
        fechaUltimaCompra.Cargar();
        cin>>tipo;
        cin>>origen;
        cin>>pu;
        activo=true;
    }
    void Mostrar(){

        cout<<left<<setw(3)<<codigo;
        cout<<setw(28)<<nombre;
        fechaUltimaCompra.Mostrar();
        cout<<setw(4)<<tipo;
        cout<<setw(4)<<origen;
        cout<<setw(6)<<pu;
        if(!activo) cout<<"ESTA BORRADO";
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
            ///****************************
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

    ///ESCRIBIR-------------------------------------------------
    bool escribirRegistro(Componente reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        bool escribio = fwrite(&reg, sizeof reg, 1, p);
        fclose(p);
        return escribio;
    }
    ///GUARDAR---------------------------------------------------
    bool remplazarReg(Componente reg, int posicionAReemplazar){
        FILE *p = fopen(nombre, "rb+");

        if (p == NULL){return false;}

        fseek(p, posicionAReemplazar * sizeof(Componente), SEEK_SET);
        bool pudoEscribir = fwrite(&reg, sizeof(Componente), 1, p);
        fclose(p);
        return pudoEscribir;
    }


};


class Tarea{
private:
    int codigo, numeroEmpleado, codigoComponente;
    char nombre[30];
    char codigoProyecto[5];
    int categoria, tiempo;
    Fecha fechaTarea;
    bool activo;
public:
    void Cargar(){
        cout << "Codigo de tarea: ";
        cin>>codigo;
        cout << "Nombre: ";
        cargarCadena(nombre,29);
        cout << "Numero de empleado: ";
        cin>>numeroEmpleado;
        cout << "Codigo de componente: ";
        cin>>codigoComponente;
        cout << "Codigo de proyecto: ";
        cin>>codigoProyecto;
        cout << "Categoria: ";
        cin>>categoria;
        cout << "Tiempo empleado: ";
        cin>>tiempo;
        cout << "Fecha: ";
        fechaTarea.Cargar();
        activo=true;
    }

    void Mostrar(){
        cout<<left<<setw(4)<<codigo;
        cout<<setw(10)<<nombre;
        cout<<setw(6)<<numeroEmpleado;
        cout<<setw(4)<<codigoComponente;
        cout<<setw(6)<<codigoProyecto;
        cout<<setw(4)<<categoria;
        cout<< setw(6)<<tiempo;
        fechaTarea.Mostrar();
        if(!activo) cout<<"ESTA BORRADO"<<endl;
    }
    int getCodigo(){return codigo;}
    int getNumeroEmpleado(){return numeroEmpleado;}
    int getCodigoComponente(){return codigoComponente;}
    const char *getNombre(){return nombre;}
    const char *getCodigoProyecto(){return codigoProyecto;}
    int getCategoria(){return categoria;}
    int getTiempo(){return tiempo;}
    Fecha getFechaTarea(){return fechaTarea;}
    bool getActivo(){return activo;}

    void setCodigo(int c){codigo=c;}
    void setNumeroEmpleado(int n){ numeroEmpleado=n;}
    void setCodigoComponente(int c){codigoComponente=c;}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setCodigoProyecto(const char *c){ strcpy(codigoProyecto, c);}
    void setCategoria(int c){categoria = c;}
    void setTiempo(int t){tiempo = t;}
    void setFechaTarea(Fecha f){fechaTarea = f;}
    void setActivo(bool a){activo = a;}


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

    ///****************************
    bool listarArchivo(){
        Tarea reg;
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

    ///ESCRIBIR-------------------------------------------------
    bool escribirRegistro(Tarea reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        bool escribio = fwrite(&reg, sizeof reg, 1, p);
        fclose(p);
        return escribio;
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
        cout<<left<<setw(6)<<numero;
        cout<<setw(20)<<nombre;
        cout<<setw(12)<<telefono;
        cout<<setw(25)<<direccion;
        cout<<setw(4)<<provincia;
        if(!activo) cout<<"ESTA BORRADO"<<endl;
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
        ///****************************
    bool listarArchivo(){
        Empleado reg;
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

    ///ESCRIBIR-------------------------------------------------
    bool escribirRegistro(Empleado reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        bool escribio = fwrite(&reg, sizeof reg, 1, p);
        fclose(p);
        return escribio;
    }

};
