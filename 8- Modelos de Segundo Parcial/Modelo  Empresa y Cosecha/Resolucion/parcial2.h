
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

    void setDia(int d){dia=d;}
    void setMes(int m){mes=m;}
    void setAnio(int a){anio=a;}

};

class Empresa {
private:
    char codigoEmpresa[6];
    char nombre[30];
    char direccion[30];
    int tipoEmpresa;

public:
    void Cargar() {
        cout << "Codigo de empresa: ";
        cargarCadena(codigoEmpresa, 5);
        cout << "Nombre: ";
        cargarCadena(nombre, 29);
        cout << "Direccion: ";
        cargarCadena(direccion, 29);
        cout << "Tipo de empresa (1: local; 2: prov; 3: nac; 4: internac): ";
        cin >> tipoEmpresa;
    }

    void Mostrar() {
        cout << "Codigo de empresa: " << codigoEmpresa << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Direccion: " << direccion << endl;
        cout << "Tipo de empresa: " << tipoEmpresa << endl;
    }

    const char* getCodigoEmpresa() { return codigoEmpresa; }
    const char* getNombre() { return nombre; }
    const char* getDireccion() { return direccion; }
    int getTipoEmpresa() { return tipoEmpresa; }

    void setCodigoEmpresa(const char* c) { strcpy(codigoEmpresa, c); }
    void setNombre(const char* n) { strcpy(nombre, n); }
    void setDireccion(const char* d) { strcpy(direccion, d); }
    void setTipoEmpresa(int t) { tipoEmpresa = t; }

    /*///Sobre carga de operador == del punto E
    bool operator == (Cosecha reg){
        if(strcmp(codigoEmpresa,reg.getCodigoEmpresa())== 0){
            return true;
        }
        return false
    }*/
};

class ArchivoEmpresa {
private:
    char nombre[30];

public:
    ArchivoEmpresa() {
        strcpy(nombre, "Empresa.dat");
    }

    Empresa leerRegistro(int pos) {
        Empresa reg;
        reg.setTipoEmpresa(-1);
        FILE* p;
        p = fopen(nombre, "rb");
        if (p == NULL) return reg;
        fseek(p, sizeof(Empresa) * pos, 0);
        fread(&reg, sizeof reg, 1, p);
        fclose(p);
        return reg;
    }

    int contarRegistros() {
        FILE* p;
        p = fopen(nombre, "rb");
        if (p == NULL) return -1;
        fseek(p, 0, 2);
        int tam = ftell(p);
        fclose(p);
        return tam / sizeof(Empresa);
    }


};

class Cosecha {
private:
    int numeroCosecha;
    char codigoEmpresa[6];
    int codigoCereal;
    float toneladasCosechadas;
    Fecha fecha;

public:
    void Cargar() {
        cout << "Numero de cosecha: ";
        cin >> numeroCosecha;
        cout << "Codigo de empresa: ";
        cargarCadena(codigoEmpresa, 5);
        cout << "Codigo de cereal (1 a 20): ";
        cin >> codigoCereal;
        cout << "Toneladas cosechadas: ";
        cin >> toneladasCosechadas;
        fecha.Cargar();
    }

    void Mostrar() {
        cout << "Numero de cosecha: " << numeroCosecha << endl;
        cout << "Codigo de empresa: " << codigoEmpresa << endl;
        cout << "Codigo de cereal: " << codigoCereal << endl;
        cout << "Toneladas cosechadas: " << toneladasCosechadas << endl;
        cout << "Fecha: ";
        fecha.Mostrar();
    }

    int getNumeroCosecha() { return numeroCosecha; }
    const char* getCodigoEmpresa() { return codigoEmpresa; }
    int getCodigoCereal() { return codigoCereal; }
    float getToneladasCosechadas() { return toneladasCosechadas; }
    Fecha getFecha() { return fecha; }

    void setNumeroCosecha(int n) { numeroCosecha = n; }
    void setCodigoEmpresa(const char* c) { strcpy(codigoEmpresa, c); }
    void setCodigoCereal(int c) { codigoCereal = c; }
    void setToneladasCosechadas(float t) { toneladasCosechadas = t; }
    void setFecha(Fecha f) { fecha = f; }

    ///Sobrecarga
    bool operator == (Empresa reg){
        if(strcmp(codigoEmpresa, reg.getCodigoEmpresa()) == 0) return true;
        return false;
    }
};

class ArchivoCosecha {
private:
    char nombre[30];

public:
    ArchivoCosecha() {
        strcpy(nombre, "Cosecha.dat");
    }

    Cosecha leerRegistro(int pos) {
        Cosecha reg;
        reg.setNumeroCosecha(-1);
        FILE* p;
        p = fopen(nombre, "rb");
        if (p == NULL) return reg;
        fseek(p, sizeof(Cosecha) * pos, 0);
        fread(&reg, sizeof reg, 1, p);
        fclose(p);
        return reg;
    }

    int contarRegistros() {
        FILE* p;
        p = fopen(nombre, "rb");
        if (p == NULL) return -1;
        fseek(p, 0, 2);
        int tam = ftell(p);
        fclose(p);
        return tam / sizeof(Cosecha);
    }

    bool escribirRegistro(Cosecha reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        bool escribio = fwrite(&reg, sizeof reg, 1, p);
        fclose(p);
        return escribio;
    }
    bool listarArchivo() {
        Cosecha reg;
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

};


