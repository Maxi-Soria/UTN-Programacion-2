///Ejercicio: modelo Parcial 1 de Programación II
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
        cout<<dia<<"/"<<mes<<"/"<<anio;
    }
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}

    void setDia(int d){dia=d;}
    void setMes(int m){mes=m;}
    void setAnio(int a){anio=a;}

};

class Obra{
private:
    char codigoObra[5];
    char direccion[30];
    int provincia;
    float superficie;
    int estadoEjecucion;
    bool activo;
public:
    void Cargar(){
        cargarCadena(codigoObra,4);
        cargarCadena(direccion,29);
        cin>>provincia;
        cin>>superficie;
        cin>>estadoEjecucion;
        activo=true;
    }

    void Mostrar(){

        cout<<left<<setw(6)<<codigoObra<<setw(20)<<direccion<<setw(6)<<provincia<<setw(6)<<superficie<<setw(6)<<estadoEjecucion<<setw(6)<<activo<<endl;

    }

    const char* getCodigoObra(){return codigoObra;}
    const char* getDireccion(){return direccion;}
    int getProvincia(){return provincia;}
    int getEstadoEjecucion(){return estadoEjecucion;}
    float getSuperficie(){return superficie;}
    bool getActivo(){return activo;}

    void setCodigoObra(const char *co){strcpy(codigoObra, co);}
    void setDireccion(const char *d){strcpy(direccion,d);}
    void setProvincia(int p){provincia=p;}
    void setEstadoEjecucion(int e){estadoEjecucion=e;}
    void setSuperficie(float s){superficie=s;}
    void setActivo(bool a){activo=a;}

};

class ArchivoObras{
private:
    char nombre[30];
public:
    ArchivoObras(const char *n){
        strcpy(nombre, n);
    }
    Obra leerRegistro(int pos){
        Obra reg;
        reg.setProvincia(-1);
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof(Obra)*pos,0);
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
        return tam/sizeof(Obra);
    }

    bool listarArchivo(){
        Obra reg;
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

};




class Material{
private:
    int codigoMaterial;
    char nombre[30];
    char marca[30];
    int tipo;
    float pu;
    bool activo;
public:
    void Cargar(){
        cin>>codigoMaterial;
        cargarCadena(nombre,29);
        cargarCadena(marca,29);
        cin>>tipo;
        cin>>pu;
        activo=true;
    }
    void Mostrar(){
        cout<<left<<setw(6)<<codigoMaterial<<setw(18)<<nombre<<setw(10)<<marca<<setw(6)<<tipo<<setw(6)<<pu<<setw(6)<<activo<<endl;
    }
    int getCodigoMaterial(){return codigoMaterial;}
    int getTipo(){return tipo;}
    const char *getNombre(){return nombre;}
    const char *getMarca(){return marca;}
    float getPU(){return pu;}
    bool getActivo(){return activo;}

    void setCodigoMaterial(int cm){codigoMaterial=cm;}
    void setTipo(int t){tipo=t;}
    void setNombre(const char *m){strcpy(nombre,m);}
    void setMarca(const char *m){strcpy(marca,m);}
    void setPU(float p){pu=p;}
    void setActivo(bool a){activo=a;}
};


class ArchivoMaterial{
private:
    char nombre[30];
public:
    ArchivoMaterial(const char *n){
        strcpy(nombre, n);
    }
    Material leerRegistro(int pos){
        Material reg;
        reg.setCodigoMaterial(-1);
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
        return tam/sizeof(Material);
    }
    bool listarArchivo(){
        Material reg;
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
};


class Compra{
private:
    int numeroCompra, numeroProveedor, codigoMaterial;
    char codigoObra[5];
    int cantidad;
    float importe;
    Fecha fechaCompra;
    bool activo;
public:
    void Cargar(){
        cin>>numeroCompra;
        cin>>numeroProveedor;
        cin>>codigoMaterial;
        cargarCadena(codigoObra,4);
        cin>>cantidad;
        cin>>importe;
        fechaCompra.Cargar();
        activo=true;
    }

    void Mostrar(){
        cout<<left<<setw(8)<<numeroCompra<<setw(8)<<numeroProveedor<<setw(8)<<codigoMaterial<<setw(8)<<codigoObra<<setw(8)<<cantidad<<setw(8)<<importe;
        fechaCompra.Mostrar();
        cout << "   "<< activo<<endl;
    }
    int getNumeroCompra(){return numeroCompra;}
    int getNumeroproveedor(){return numeroProveedor;}
    int getCodigoMaterial(){return codigoMaterial;}
    int getCantidad(){return cantidad;}
    float getImporte(){return importe;}
    Fecha getFechaCompra(){return fechaCompra;}
    const char *getCodigoObra(){return codigoObra;}
    bool getActivo(){return activo;}

    void setNumeroCompra(int nc){numeroCompra=nc;}
    void setNumeroproveedor(int np){numeroProveedor=np;}
    void setCodigoMaterial(int cm){codigoMaterial=cm;}
    void setCantidad(int c){cantidad=c;}
    void setImporte(float i){importe=i;}
    void setFechaCompra(Fecha f){fechaCompra=f;}
    void setCodigoObra(const char *co){strcpy(codigoObra,co);}
    void setActivo(bool a){activo=a;}

};


class ArchivoCompra{
private:
    char nombre[30];
public:
    ArchivoCompra(const char *n){
        strcpy(nombre, n);
    }
    Compra leerRegistro(int pos){
        Compra reg;
        reg.setCodigoMaterial(-1);
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
        return tam/sizeof(Compra);
    }
    bool listarArchivo(){
        Compra reg;
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
    bool escribirRegistro(Compra reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        bool escribio = fwrite(&reg, sizeof reg, 1, p);
        fclose(p);
        return escribio;
    }
};

class Proveedor{
private:
    int numeroProveedor;
    char nombre[30];
    char telefono[30];
    char direccion[30];
    int provincia;
    bool activo;
public:
    void Cargar(){
        cin>>numeroProveedor;
        cargarCadena(nombre,29);
        cargarCadena(telefono,29);
        cargarCadena(direccion,29);
        cin>>provincia;
        activo=true;
    }
    void Mostrar(){
        cout<<left<<setw(6)<<numeroProveedor<<setw(18)<<nombre<<setw(10)<<telefono<<setw(10)<<direccion<<setw(6)<<provincia<<setw(4)<<activo<<endl;

    }

    int getNumeroProveedor(){return numeroProveedor;}
    int getProvincia(){return provincia;}
    const char *getNombre(){return nombre;}
    const char *getTelefono(){return telefono;}
    const char *getDireccion(){return direccion;}
    bool getActivo(){return activo;}

    void setNumeroProveedor(int np){numeroProveedor=np;}
    void setProvincia(int np){provincia=np;}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setTelefono(const char *n){strcpy(telefono,n);}
    void setDireccion(const char *n){strcpy(direccion,n);}
    void setActivo(bool a){activo=a;}

};

class ArchivoProveedor{
private:
    char nombre[30];
public:
    ArchivoProveedor(const char *n){
        strcpy(nombre, n);
    }
    Proveedor leerRegistro(int pos){
        Proveedor reg;
        reg.setNumeroProveedor(-1);
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
        return tam/sizeof(Proveedor);
    }
    bool listarArchivo(){
        Proveedor reg;
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

};
