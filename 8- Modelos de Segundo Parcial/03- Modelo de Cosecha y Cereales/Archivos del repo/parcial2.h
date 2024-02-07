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


class Cosecha {
private:
    int numeroCosecha;
    int codigoCereal;
    float toneladasCosechadas;
    Fecha fecha;

public:
    void Cargar() {
        cout << "Numero de cosecha: ";
        cin >> numeroCosecha;
        cout << "Codigo de cereal (1 a 20): ";
        cin >> codigoCereal;
        cout << "Toneladas cosechadas: ";
        cin >> toneladasCosechadas;
        fecha.Cargar();
    }

    void Mostrar() {
        cout << "Numero de cosecha: " << numeroCosecha << endl;
        cout << "Codigo de cereal: " << codigoCereal << endl;
        cout << "Toneladas cosechadas: " << toneladasCosechadas << endl;
        cout << "Fecha: ";
        fecha.Mostrar();
    }

    int getNumeroCosecha() { return numeroCosecha; }
    int getCodigoCereal() { return codigoCereal; }
    float getToneladasCosechadas() { return toneladasCosechadas; }
    Fecha getFecha() { return fecha; }

    void setNumeroCosecha(int n) { numeroCosecha = n; }
    void setCodigoCereal(int c) { codigoCereal = c; }
    void setToneladasCosechadas(float t) { toneladasCosechadas = t; }
    void setFecha(Fecha f) { fecha = f; }
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

    ///********************************************************
    bool listarArchivo(){
        Cosecha reg;
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

    bool escribirRegistro(Cosecha reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        bool escribio = fwrite(&reg, sizeof reg, 1, p);
        fclose(p);
        return escribio;
    }
    ///*********************************************************
};

class Cereal {
private:
    int codigoCereal;
    char nombre[30];
    float importePorTonelada;

public:
    void Cargar() {
        cout << "Codigo de cereal (1 a 20): ";
        cin >> codigoCereal;
        cout << "Nombre: ";
        cargarCadena(nombre, 29);
        cout << "Importe por tonelada ($): ";
        cin >> importePorTonelada;
    }

    void Mostrar() {
        cout << "Codigo de cereal: " << codigoCereal << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Importe por tonelada ($): " << importePorTonelada << endl;
    }

    int getCodigoCereal() { return codigoCereal; }
    const char* getNombre() { return nombre; }
    float getImportePorTonelada() { return importePorTonelada; }

    void setCodigoCereal(int c) { codigoCereal = c; }
    void setNombre(const char* n) { strcpy(nombre, n); }
    void setImportePorTonelada(float i) { importePorTonelada = i; }
};


class ArchivoCereales {
private:
    char nombre[30];

public:
    ArchivoCereales() {
        strcpy(nombre, "Cereales.dat");
    }

    Cereal leerRegistro(int pos) {
        Cereal reg;
        reg.setCodigoCereal(-1);
        FILE* p;
        p = fopen(nombre, "rb");
        if (p == NULL) return reg;
        fseek(p, sizeof(Cereal) * pos, 0);
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
        return tam / sizeof(Cereal);
    }

    ///********************************************************
    bool listarArchivo() {
        Cereal reg;
        FILE* p;
        p = fopen(nombre, "rb");
        if (p == NULL) {
            cout << "No se pudo abrir " << endl;
            return false;
        }
        while (fread(&reg, sizeof reg, 1, p) == 1) {
            reg.Mostrar();
            cout << endl;
        }
        fclose(p);
        return true;
    }

    bool escribirRegistro(Cereal reg) {
        FILE* p;
        p = fopen(nombre, "ab");
        if (p == NULL) return false;
        bool escribio = fwrite(&reg, sizeof reg, 1, p);
        fclose(p);
        return escribio;
    }
    ///*********************************************************
};

