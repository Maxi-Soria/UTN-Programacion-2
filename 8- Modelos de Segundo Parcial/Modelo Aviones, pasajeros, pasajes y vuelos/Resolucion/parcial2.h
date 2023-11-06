///Ejercicio: Parcial 2 de Programación II
///Autor:DEK
///Fecha:13/06/2022
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
        cout<<anio;
    }
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}

    void setDia(int d){dia=d;}
    void setMes(int m){mes=m;}
    void setAnio(int a){anio=a;}

};


class Vuelo{
private:
    char codigoVuelo[5];
    char nombre[30];
    int destino;
    float tiempoViaje;
    int tipoViaje;
    bool activo;
public:
    void Cargar(){
        cargarCadena(codigoVuelo,4);
        cargarCadena(nombre,29);
        cin>>destino;
        cin>>tiempoViaje;
        cin>>tipoViaje;
        activo=true;
    }

    void Mostrar(){
        cout<<codigoVuelo<<"    "<<nombre<<"    "<<destino<<"   "<<tiempoViaje<<"   "<<tipoViaje;
    }

    const char* getCodigoVuelo(){return codigoVuelo;}
    const char* getNombre(){return nombre;}
    int getDestino(){return destino;}
    float getTiempoViaje(){return tiempoViaje;}
    int getTipoViaje(){return tipoViaje;}
    bool getActivo(){return activo;}

    void setCodigoVuelo(const char *cv){strcpy(codigoVuelo, cv);}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setDestino(int d){destino=d;}
    void setTiempoViaje(float e){tiempoViaje=e;}
    void setTipoViaje(int tv){tipoViaje=tv;}
    void setActivo(bool a){activo=a;}

};

class ArchivoVuelo{
private:
    char nombre[30];
public:
    ArchivoVuelo(){strcpy(nombre,"vuelos.dat");}
    ///-----------------------------------------
    Vuelo leerRegistro(int pos){
        Vuelo reg;
        reg.setTipoViaje(-1);
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof(Vuelo)*pos,0);
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
        return tam/sizeof(Vuelo);
    }
        ///****************************
    bool listarArchivo(){
        Vuelo reg;
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
    bool escribirRegistro(Vuelo reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        bool escribio = fwrite(&reg, sizeof reg, 1, p);
        fclose(p);
        return escribio;
    }


};

class Avion{
private:
    int codigoAvion;
    char nombre[30];
    char marca[30];
    int tipo;
    int cantidadAsientos;
    bool activo;
public:
    void Cargar(){
        cin>>codigoAvion;
        cargarCadena(nombre,29);
        cargarCadena(marca,29);
        cin>>tipo;
        cin>>cantidadAsientos;
        activo=true;
    }
    void Mostrar(){
        cout<<codigoAvion<<"    "<<nombre<<"    "<<marca<<"    "<<tipo<<"   "<<cantidadAsientos;
    }
    int getCodigoAvion(){return codigoAvion;}
    int getTipo(){return tipo;}
    const char *getNombre(){return nombre;}
    const char *getMarca(){return marca;}
    int getCantidadAsientos(){return cantidadAsientos;}
    bool getActivo(){return activo;}

    void setCodigoAvion(int ca){codigoAvion=ca;}
    void setTipo(int t){tipo=t;}
    void setNombre(const char *m){strcpy(nombre,m);}
    void setMarca(const char *m){strcpy(marca,m);}
    void setCantidadAsientos(int ca){cantidadAsientos=ca;}
    void setActivo(bool a){activo=a;}


};

class ArchivoAvion{
private:
    char nombre[30];
public:
    ArchivoAvion(){strcpy(nombre, "aviones.dat");}
    ///--------------------------------------------
    Avion leerRegistro(int pos){
        Avion reg;
        reg.setCantidadAsientos(-1);
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof(Avion)*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    ///-----------------------------------------------
    int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Avion);
    }
    ///****************************
    bool listarArchivo(){
        Avion reg;
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
    bool escribirRegistro(Avion reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        bool escribio = fwrite(&reg, sizeof reg, 1, p);
        fclose(p);
        return escribio;
    }

};

class Pasaje{
private:
    int numeroPasaje, numeroPasajero, codigoAvion;
    char codigoVuelo[5];
    int cantidad;
    float importe;
    Fecha fechaCompra;
    bool activo;
public:
    void Cargar(){
        cin>>numeroPasaje;
        cin>>numeroPasajero;
        cin>>codigoAvion;
        cargarCadena(codigoVuelo,4);
        cin>>cantidad;
        cin>>importe;
        fechaCompra.Cargar();
        activo=true;
    }

    void Mostrar(){
        cout<<numeroPasaje<<"   "<<numeroPasajero<<"    "<<codigoAvion<<"   "<<codigoVuelo<<"   "<<cantidad<<"  "<<importe<<"   ";
        fechaCompra.Mostrar();
    }
    int getNumeroPasaje(){return numeroPasaje;}
    int getNumeroPasajero(){return numeroPasajero;}
    int getCodigoAvion(){return codigoAvion;}
    int getCantidad(){return cantidad;}
    float getImporte(){return importe;}
    Fecha getFechaCompra(){return fechaCompra;}
    const char *getCodigoVuelo(){return codigoVuelo;}
    bool getActivo(){return activo;}

    void setNumeroPasaje(int np){numeroPasaje=np;}
    void setNumeroPasajero(int np){numeroPasajero=np;}
    void setCodigoAvion(int ca){codigoAvion=ca;}
    void setCantidad(int c){cantidad=c;}
    void setImporte(float i){importe=i;}
    void setFechaCompra(Fecha f){fechaCompra=f;}
    void setCodigoVuelo(const char *cv){strcpy(codigoVuelo,cv);}
    void setActivo(bool a){activo=a;}

};

class ArchivoPasajes{
private:
    char nombre[30];
public:
    ArchivoPasajes(){
        strcpy(nombre,"pasajes.dat" );
    }
    ///--------------------------------
    Pasaje leerRegistro(int pos){
        Pasaje reg;
        reg.setImporte(-1);
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof(Pasaje)*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    ///-----------------------------
    int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Pasaje);
    }
        ///****************************
    bool listarArchivo(){
        Pasaje reg;
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
    bool escribirRegistro(Pasaje reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        bool escribio = fwrite(&reg, sizeof reg, 1, p);
        fclose(p);
        return escribio;
    }

};

class Pasajero{
private:
    int numeroPasajero;
    char nombre[30];
    char telefono[30];
    char direccion[30];
    int provincia;
    bool activo;
public:
    void Cargar(){
        cin>>numeroPasajero;
        cargarCadena(nombre,29);
        cargarCadena(telefono,29);
        cargarCadena(direccion,29);
        cin>>provincia;
        activo=true;
    }
    void Mostrar(){
        cout<<numeroPasajero<<"     "<<nombre<<"     "<<telefono<<"     "<<direccion<<"     "<<provincia;
    }

    int getNumeroPasajero(){return numeroPasajero;}
    int getProvincia(){return provincia;}
    const char *getNombre(){return nombre;}
    const char *getTelefono(){return telefono;}
    const char *getDireccion(){return direccion;}
    bool getActivo(){return activo;}

    void setNumeroPasajero(int np){numeroPasajero=np;}
    void setProvincia(int np){provincia=np;}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setTelefono(const char *n){strcpy(telefono,n);}
    void setDireccion(const char *n){strcpy(direccion,n);}
    void setActivo(bool a){activo=a;}

    bool operator==(Pasaje pas){
        return numeroPasajero == pas.getNumeroPasajero();

    }

};

class ArchivoPasajeros{
private:
    char nombre[30];
public:
    ArchivoPasajeros(const char* n ){
        strcpy(nombre,n);
    }
    Pasajero leerRegistro(int pos){
        Pasajero reg;
        reg.setProvincia(-1);
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof(Pasajero)*pos,0);
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
        return tam/sizeof(Pasajero);
    }
        ///****************************
    bool listarArchivo(){
        Pasajero reg;
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
    bool escribirRegistro(Pasajero reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        bool escribio = fwrite(&reg, sizeof reg, 1, p);
        fclose(p);
        return escribio;
    }
    void vaciar(){
        FILE *p = fopen(nombre, "wb");
        if (p == NULL){return ;}
        fclose(p);
    }

};

