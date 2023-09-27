#ifndef RECOLECCION_H_INCLUDED
#define RECOLECCION_H_INCLUDED


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
        cout << "Dia: ";
        cin>>dia;
        cout << "Mes: ";
        cin>>mes;
        cout << "Anio: ";
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

    /*void setDia(int d){dia=d;}
    void setMes(int m){mes=m;}
    void setAnio(int a){anio=a;}*/

};

class Residuo {
private:
    int _codigoZona;
    char _codigoCamion[5];
    Fecha _fecha;
    float _cantidadKilos;
    int _codigoCentroRecepcion;

public:
    Residuo(){
       _codigoZona = 0;
       strcpy(_codigoCamion,"Sin Datos");
       _cantidadKilos = 0;
       _codigoCentroRecepcion = 0;
    }

    void Cargar();
    void Mostrar();

    int getCodigoZona(){ return _codigoZona;}
    const char* getCodigoCamion() { return _codigoCamion; }
    Fecha getFecha(){ return _fecha; }
    float getCantidadKilos(){ return _cantidadKilos; }
    int getCodigoCentroRecepcion(){ return _codigoCentroRecepcion; }

    void setCodigoZona(int zona) { _codigoZona = zona; }
    void setCodigoCamion(const char* camion) {strcpy(_codigoCamion,camion);}
    void setFecha(Fecha fecha) { _fecha = fecha; }
    void setCantidadKilos(float kilos) { _cantidadKilos = kilos; }
    void setCodigoCentroRecepcion(int centro) { _codigoCentroRecepcion = centro;}
};

void Residuo::Cargar() {
    cout << "Ingrese el codigo de zona: ";
    cin >> _codigoZona;
    cout << "Ingrese el codigo de camión: ";
    cin >> _codigoCamion;
    cout << "Ingrese la fecha: " << endl;
    _fecha.Cargar();
    cout << "Ingrese la cantidad de kilos recogidos: ";
    cin >> _cantidadKilos;
    cout << "Ingrese el codigo de centro de recepción: ";
    cin >> _codigoCentroRecepcion;
    cout << endl;
}

void Residuo::Mostrar() {
    cout << "Codigo de zona: " << _codigoZona << endl;
    cout << "Codigo de camion: " << _codigoCamion << endl;
    cout << "Fecha: " ;
    _fecha.Mostrar();
    cout << "Cantidad de kilos recogidos: " << _cantidadKilos << endl;
    cout << "Codigo de centro de recepción: " << _codigoCentroRecepcion << endl;
    cout << endl;
}

class ArchivoResiduos{
private:
    char _nombre[20];
public:
    ArchivoResiduos(const char* nombre){
        strcpy(_nombre, nombre);
    }
    ArchivoResiduos(){
        strcpy(_nombre,"residuos.dat");
    }
    Residuo leerRegistro(int pos){
        Residuo reg;
        FILE *p;
        p=fopen(_nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof(Residuo)*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros(){
        FILE *p;
        p=fopen(_nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Residuo);
    }
    int AgregarRegistro(){
        Residuo reg;
        FILE *p;
        p = fopen(_nombre, "ab");
        if(p==NULL){
        cout << "No se pudo abrir o crear el archivo" << endl;
        return -1;
        }
        reg.Cargar();
        int valor = fwrite (&reg, sizeof reg, 1, p);
        fclose(p);
        return valor;
    }


    bool listarArchivo(){
        Residuo reg;
        FILE *p;
        p = fopen(_nombre, "rb");
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



class Camion{
private:
    char _codigoCamion[5];
    float _cargaMaxima;
    char _codigoChofer[5];
    char _marca[15];
    char _modelo[20];

public:
    Camion() {
        strcpy(_codigoCamion, "Sin Datos");
        _cargaMaxima = 0;
        strcpy(_codigoChofer, "Sin Datos");
        strcpy(_marca, "Sin Datos");
        strcpy(_modelo, "Sin Datos");
    }
    void Cargar() ;
    void Mostrar();

    const char* getCodigoCamion() { return _codigoCamion; }
    float getCargaMaxima() { return _cargaMaxima; }
    const char* getCodigoChofer() { return _codigoChofer; }
    const char* getMarca() { return _marca; }
    const char* getModelo() { return _modelo; }

    void setCodigoCamion(const char* codigo) { strcpy(_codigoCamion, codigo); }
    void setCargaMaxima(float carga) { _cargaMaxima = carga; }
    void setCodigoChofer(const char* codigo) { strcpy(_codigoChofer, codigo); }
    void setMarca(const char* marca) { strcpy(_marca, marca); }
    void setModelo(const char* modelo) { strcpy(_modelo, modelo); }

};

void Camion::Cargar() {
    cout << "Ingrese el codigo de camion: ";
    cin >> _codigoCamion;
    cout << "Ingrese la carga maxima en kg: ";
    cin >> _cargaMaxima;
    cout << "Ingrese el codigo de chofer: ";
    cin >> _codigoChofer;
    cout << "Ingrese la marca: ";
    cin.ignore();
    cargarCadena(_marca,14);
    cout << "Ingrese el modelo: ";
    cargarCadena(_modelo,19);
    cout << endl;
}

void Camion::Mostrar() {
    cout << "Codigo de camion: " << _codigoCamion << endl;
    cout << "Carga maxima en kg: " << _cargaMaxima << endl;
    cout << "Codigo de chofer: " << _codigoChofer << endl;
    cout << "Marca: " << _marca << endl;
    cout << "Modelo: " << _modelo << endl;
    cout << endl;
}

class ArchivoCamiones{
private:
    char _nombre[20];
public:
    ArchivoCamiones(const char* nombre){
        strcpy(_nombre, nombre);
    }
    ArchivoCamiones(){
        strcpy(_nombre,"camiones.dat");
    }
    Camion leerRegistro(int pos){
        Camion reg;
        FILE *p;
        p=fopen(_nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof(Camion)*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros(){
        FILE *p;
        p=fopen(_nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Camion);
    }
    int AgregarRegistro(){
        Camion reg;
        FILE *p;
        p = fopen(_nombre, "ab");
        if(p==NULL){
        cout << "No se pudo abrir o crear el archivo" << endl;
        return -1;
        }
        reg.Cargar();
        int valor = fwrite (&reg, sizeof reg, 1, p);
        fclose(p);
        return valor;
    }


    bool listarArchivo(){
        Camion reg;
        FILE *p;
        p = fopen(_nombre, "rb");
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


class Centro {
private:
    int _codigoCentro;
    char _nombre[20];
    char _localidad[20];

public:
    Centro() {
        _codigoCentro = 0;
        strcpy(_nombre, "Sin Datos");
        strcpy(_localidad, "Sin Datos");
    }
    void Cargar();
    void Mostrar();

    int getCodigoCentro() { return _codigoCentro; }
    const char* getNombre() { return _nombre; }
    const char* getLocalidad() { return _localidad; }

    void setCodigoCentro(int codigo) { _codigoCentro = codigo; }
    void setNombre(const char* nombre) { strcpy(_nombre, nombre); }
    void setLocalidad(const char* localidad) { strcpy(_localidad, localidad); }

};


void Centro::Cargar() {
    cout << "Ingrese el código de centro de recepción: ";
    cin >> _codigoCentro;
    cout << "Ingrese el nombre: ";
    cin.ignore();
    cargarCadena(_nombre,19);
    cout << "Ingrese la localidad: ";
    cargarCadena(_localidad,19);
    cout << endl;
}

void Centro::Mostrar() {
    cout << "Código de centro de recepción: " << _codigoCentro << endl;
    cout << "Nombre: " << _nombre << endl;
    cout << "Localidad: " << _localidad << endl;
    cout << endl;
}

class ArchivoCentro{
private:
    char _nombre[20];
public:
    ArchivoCentro(const char* nombre){
        strcpy(_nombre, nombre);
    }
    ArchivoCentro(){
        strcpy(_nombre,"centro.dat");
    }
    Centro leerRegistro(int pos){
        Centro reg;
        FILE *p;
        p=fopen(_nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof(Centro)*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros(){
        FILE *p;
        p=fopen(_nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Centro);
    }
    int AgregarRegistro(){
        Centro reg;
        FILE *p;
        p = fopen(_nombre, "ab");
        if(p==NULL){
        cout << "No se pudo abrir o crear el archivo" << endl;
        return -1;
        }
        reg.Cargar();
        int valor = fwrite (&reg, sizeof reg, 1, p);
        fclose(p);
        return valor;
    }


    bool listarArchivo(){
        Camion reg;
        FILE *p;
        p = fopen(_nombre, "rb");
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


class PuntoC{
private:
    char _codigoCamion[5];
    int _codigoCentro;
    int _cantViajes;
    char _nombre[20];
    char _localidad[20];
public:
    Cargar(){
        cout << "Codigo de camion: ";
        cin >> _codigoCamion;
        cout << "Código de centro de recepción: ";
        cin >> _codigoCentro;
        cout << "Ingrese Nombre: ";
        cargarCadena(_nombre,19);
        cout << "Ingrese Localidad: ";
        cargarCadena(_localidad,19);
        cout << "Ingrese Cantidad de viajes: ";
        cin >>  _cantViajes;
        cout << endl;

    }

    Mostrar(){
        cout << "Codigo de camion: " << _codigoCamion << endl;
        cout << "Código de centro de recepción: " << _codigoCentro << endl;
        cout << "Nombre: " << _nombre << endl;
        cout << "Localidad: " << _localidad << endl;
        cout << "Cantidad de viajes: " << _cantViajes << endl;
        cout << endl;
    }

    void setCodigoCamion(const char* codigo) { strcpy(_codigoCamion, codigo); }
    void setCodigoCentro(int codigo) { _codigoCentro = codigo; }
    void setNombre(const char* nombre) { strcpy(_nombre, nombre); }
    void setLocalidad(const char* localidad) { strcpy(_localidad, localidad); }
    void setCantidadViajes(int cantViajes) {_cantViajes = cantViajes; }

};

class ArchivoPuntoC{
private:
    char _nombre[20];
public:
    ArchivoPuntoC(const char* nombre){
        strcpy(_nombre, nombre);
    }
    ArchivoPuntoC(){
        strcpy(_nombre,"puntoC.dat");
    }
    PuntoC leerRegistro(int pos){
        PuntoC reg;
        FILE *p;
        p=fopen(_nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof(PuntoC)*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros(){
        FILE *p;
        p=fopen(_nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(PuntoC);
    }
    int AgregarRegistro(){
        PuntoC reg;
        FILE *p;
        p = fopen(_nombre, "ab");
        if(p==NULL){
        cout << "No se pudo abrir o crear el archivo" << endl;
        return -1;
        }
        reg.Cargar();
        int valor = fwrite (&reg, sizeof reg, 1, p);
        fclose(p);
        return valor;
    }


    bool listarArchivo(){
        PuntoC reg;
        FILE *p;
        p = fopen(_nombre, "rb");
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


#endif // RECOLECCION_H_INCLUDED
