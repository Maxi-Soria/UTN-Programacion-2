#ifndef PARCIAL1L_H_INCLUDED
#define PARCIAL1L_H_INCLUDED

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
        cout<<setw(2)<<dia<<"/"<<setw(2)<<mes<<"/"<<setw(4)<<anio<<"    ";
    }
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}

    void setDia(int d){dia=d;}
    void setMes(int m){mes=m;}
    void setAnio(int a){anio=a;}

};

class Jugador{
private:
    int DNI, claustro, idDeporte, idEquipo;
    char nombre[25], apellido[30];
    char email[30];
    int telefono;
    Fecha inscripcion;
    float matricula;
    bool estado;
public:
   int getDNI(){return DNI;}
   int getClaustro(){return claustro;}
   int getIdDeporte(){return idDeporte;}
   int getIdEquipo(){return idEquipo;}
   const char *getNombre(){return nombre;}
   const char *getApellido(){return apellido;}
   bool getEstado(){return estado;}
   Fecha getFechaInscirpcion(){return inscripcion;}

   void setEstado(bool e){estado=e;}

   void Cargar(){
       cout << "DNI: ";
       cin>>DNI;
       cout << "NOMBRE: ";
       cargarCadena(nombre,24);
       cout << "APELLIDO: ";
       cargarCadena(apellido,29);
       cout << "EMAIL: ";
       cargarCadena(email,29);
       cout << "TELEFONO: ";
       cin>>telefono;
       cout << "CLAUSTRO: ";
       cin>>claustro;
       cout << "ID DEPORTE: ";
       cin>>idDeporte;
       cout << "NUM EQUIPO: ";
       cin>>idEquipo;
       cout << "FECHA INSCR: "<<endl;;
       inscripcion.Cargar();
       cout << "MATRICULA: ";
       cin>>matricula;
       cout << "ESTADO: ";
       cin>>estado;
   }
   void Mostrar(){
       cout <<left<<setw(6)<<DNI<<setw(12)<<nombre<<setw(12)<< apellido<<setw(22)<<email<<setw(10)<< telefono<<setw(6)<<claustro<<setw(6)<<idDeporte<<setw(6)<<idEquipo;
       inscripcion.Mostrar();
       cout <<setw(10)<<matricula<<setw(4)<<estado;

   }

} ;

class Deporte{
private:
    int idDeporte, anioOrigen, idCategoria;
    char nombre[30];
    bool estado;
public:
   int getIdDeporte(){return idDeporte;}
   int getIdCtegoria(){return idCategoria;}
   const char *getNombre(){return nombre;}
   bool getEstado(){return estado;}

   void setEstado(bool e){estado=e;}
   void Cargar(){
        cout << "ID deporte: ";
        cin >> idDeporte;
        cout << "Nombre: ";
        cargarCadena(nombre,29);
        cout << "Id Categoria: ";
        cin >> idCategoria;
        cout << "Anio: ";
        cin >> anioOrigen;
        cout << "Estado: ";
        cin >> estado;

   }
   void Mostrar(){
        cout <<left << setw(4)<<idDeporte<<setw(11)<< nombre<<setw(6)<<idCategoria<<setw(6)<<anioOrigen<<setw(4)<<estado;
   }

};

class Equipo{
private:
    int IdEquipo, nivel;
    char nombre[30];
    bool estado;
public:
    int getIdEquipo(){return IdEquipo;}
    int getNivel(){return nivel;}
    const char *getNombre(){return nombre;}
    bool getEstado(){return estado;}

    void setEstado(bool e){estado=e;}
    void Cargar(){
        cout << "Numero: ";
        cin >> IdEquipo;
        cout <<"Nombre: ";
        cargarCadena(nombre,29);
        cout << "Nivel: ";
        cin >> nivel;
        cout << "Estado: ";
        cin >> estado;
    }
    void Mostrar(){
        cout <<left<<setw(4)<<IdEquipo<<setw(22)<<nombre<<setw(4)<<nivel<<setw(4)<<estado;
   }
};

class ArchivoJugadores{
private:
    char nombre[30];
public:
    ArchivoJugadores(const char *n){
        strcpy(nombre, n);
    }
    Jugador leerRegistro(int pos){
        Jugador reg;
        reg.setEstado(false);
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
        return tam/sizeof(Jugador);
    }
    bool grabarRegistro(Jugador reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        int escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }
    bool listarArchivo(){
        Jugador reg;
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

    bool reemplazar(Jugador reg, int posicionAReemplazar){
        FILE *p = fopen(nombre, "rb+");

        if (p == NULL){return false;}

        fseek(p, posicionAReemplazar * sizeof(Jugador), SEEK_SET);
        bool pudoEscribir = fwrite(&reg, sizeof(Jugador), 1, p);
        fclose(p);
        return pudoEscribir;
    }
};


class ArchivoDeportes{
private:
    char nombre[30];
public:
    ArchivoDeportes(const char *n){
        strcpy(nombre, n);
    }
    Deporte leerRegistro(int pos){
        Deporte reg;
        reg.setEstado(false);
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
        return tam/sizeof(Deporte);
    }
    bool grabarRegistro(Deporte reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        int escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }
    bool listarArchivo(){
        Deporte reg;
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

class ArchivoEquipos{
private:
    char nombre[30];
public:
    ArchivoEquipos(const char *n){
        strcpy(nombre, n);
    }
    Equipo leerRegistro(int pos){
        Equipo reg;
        reg.setEstado(false);
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
        return tam/sizeof(Equipo);
    }
    bool grabarRegistro(Equipo reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        int escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }
    bool listarArchivo(){
        Equipo reg;
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

#endif // PARCIAL1L_H_INCLUDED
