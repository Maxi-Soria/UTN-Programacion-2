///Ejercicio: Parcial 2 de Programación II
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




class Cliente{
private:
    char codigoCliente[5];
    int categoria;
    char nombre[30];
    char direccion[30];
    char telefono[30];
    char email[30];
    Fecha inscripcion;
    bool estado;
public:
    void Cargar(){
        cargarCadena(codigoCliente,29);
        cin>>categoria;
        cargarCadena(nombre,29);
        cargarCadena(direccion,29);
        cargarCadena(telefono,29);
        cargarCadena(email,29);
        inscripcion.Cargar();
        estado=true;
    }
    void Mostrar(){
        cout<<codigoCliente<<endl;
        cout<<categoria<<endl;
        cout<<nombre<<endl;
        cout<<telefono<<endl;
        cout<<direccion<<endl;
        cout<<telefono<<endl;
        cout<<email<<endl;
        inscripcion.Mostrar();
        if(!estado) cout<<"ESTA BORRADO"<<endl<<endl;
    }


    void setCodigoCliente(const char *cc){strcpy(codigoCliente,cc);}
    void setCategoria(int c){categoria=c;}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setTelefono(const char *n){strcpy(telefono,n);}
    void setDireccion(const char *n){strcpy(direccion,n);}
    void setEstado(bool a){estado=a;}
    void setInscripcion(Fecha f){inscripcion=f;}

    const char *getCodigoCliente(){return codigoCliente;}
    int getCategoria(){return categoria;}
    const char *getNombre(){return nombre;}
    const char *getTelefono(){return telefono;}
    const char *getDireccion(){return direccion;}
    bool getEstado(){return estado;}
    Fecha getInscripcion(){return inscripcion;}
};

class ArchivoClientes{
private:
    char nombre[30];
public:
    ArchivoClientes(const char *n){
        strcpy(nombre, n);
    }
    Cliente leerRegistro(int pos){
        Cliente reg;
        reg.setCategoria(-1);
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
        return tam/sizeof(Cliente);
    }
    bool grabarRegistro(Cliente reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        bool escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }
};

class Guia{
private:
    int IDpersonal;
    char nombre[30];
    char telefono[30];
    char direccion[30];
    char email[30];
    bool estado;
public:
    void Cargar(){
        cin>>IDpersonal;
        cargarCadena(nombre,29);
        cargarCadena(telefono,29);
        cargarCadena(direccion,29);
        cargarCadena(email, 29);
        estado=true;
    }
    void Mostrar(){
        cout<<IDpersonal<<endl;
        cout<<nombre<<endl;
        cout<<telefono<<endl;
        cout<<direccion<<endl;
        if(!estado) cout<<"ESTA BORRADO"<<endl<<endl;
    }


    void setIDpersonal(int id){IDpersonal=id;}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setTelefono(const char *n){strcpy(telefono,n);}
    void setDireccion(const char *n){strcpy(direccion,n);}
    void setEmail(const char *e){strcpy(email, e);}
    void setEstado(bool a){estado=a;}

    int getIDpersonal(){return IDpersonal;}
    const char *getNombre(){return nombre;}
    const char *getTelefono(){return telefono;}
    const char *getDireccion(){return direccion;}
    const char *getEmail(){return email;}
    bool getEstado(){return estado;}

};

class ArchivoGuias{
private:
    char nombre[30];
public:
    ArchivoGuias(const char *n){
        strcpy(nombre, n);
    }
    Guia leerRegistro(int pos){
        Guia reg;
        reg.setEstado(0);
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
        return tam/sizeof(Guia);
    }
    bool grabarRegistro(Guia reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        bool escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }
};


class Tour{
private:
    int codigoTour, tipo;
    char nombre[30];
    bool estado;
public:
    void Cargar(){
        cin>>codigoTour;
        cargarCadena(nombre, 29);
        cin>>tipo;
        estado=true;
    }
    void Mostrar(){
        cout<<codigoTour<<endl;
        cout<<nombre<<endl;
        cout<<tipo<<endl;
        if(estado==false) cout<<"BORRADO"<<endl;
    }

    void setCodigoTour(int ct){codigoTour=ct;}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setTipo(int t){tipo=t;}
    void setEstado(bool e){estado=e;}

    int getCodigoTour(){return codigoTour;}
    const char *getNombre(){return nombre;}
    int getTipo(){return tipo;}
    bool getEstado(){return estado;}
};


class ArchivoTours{
private:
    char nombre[30];
public:
    ArchivoTours(const char *n){
        strcpy(nombre, n);
    }
    Tour leerRegistro(int pos){
        Tour reg;
        reg.setEstado(0);
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
        return tam/sizeof(Tour);
    }
    bool grabarRegistro(Tour reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        bool escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }
};

class Venta{
private:
    int numeroVenta;
    int codigoTour;
    char numeroDeCliente[5];
    int IDpersonal;
    float importe;
    Fecha fechaVenta;
    bool estado;
public:
    void Cargar(){
        cin>>numeroVenta;
        cin>>codigoTour;
        cin>>numeroDeCliente;
        cin>>IDpersonal;
        cin>>importe;
        fechaVenta.Cargar();
        estado=true;
    }
    void Mostrar(){
        cout<<numeroVenta<<endl;
        cout<<codigoTour<<endl;
        cout<<numeroDeCliente<<endl;
        cout<<IDpersonal<<endl;
        cout<<importe<<endl;
        fechaVenta.Mostrar();
        if(estado==false) cout<<"BORRADO"<<endl;
    }

    void setNumeroVenta(int nv){numeroVenta=nv;}
    void setCodigoTour(int ct){codigoTour=ct;}
    void setNumeroDeCliente(const char *nc){strcpy(numeroDeCliente,nc);}
    void setIDpersonal(int id){IDpersonal=id;}
    void setImporte(float im){importe=im;}
    void setFechaVenta(Fecha t){fechaVenta=t;};
    void setEstado(bool e){estado=e;}

    int getNumeroVenta(){return numeroVenta;}
    int getCodigoTour(){return codigoTour;}
    const char *getNumeroDeCliente(){return numeroDeCliente;}
    int getIDpersonal(){return IDpersonal;}
    float getImporte(){return importe;}
    Fecha getFechaVenta(){return fechaVenta;};
    bool getEstado(){return estado;}
};

class ArchivoVentas{
private:
    char nombre[30];
public:
    ArchivoVentas(const char *n){
        strcpy(nombre, n);
    }
    Venta leerRegistro(int pos){
        Venta reg;
        reg.setEstado(0);
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
        return tam/sizeof(Venta);
    }
    bool grabarRegistro(Venta reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        bool escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }
};
