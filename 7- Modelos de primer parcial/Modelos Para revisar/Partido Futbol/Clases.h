#ifndef CLASES_H_INCLUDED
#define CLASES_H_INCLUDED

#include <cstring>
using namespace std;

void cargarCadena(char *pal, int tam){
  int i;
  fflush(stdin);
  for(i=0;i<tam;i++){
      pal[i]=cin.get();
	  if(pal[i]=='\n') break;
	  }
  pal[i]='\0';
  fflush(stdin);
}


class Jugador {
private:
    char CodJugador [5];
    char Nombre [20];
    int Edad;
    char CodEquipo [3];
public:
    void setCodJugador (const char *cod){strcpy(CodJugador,cod);}
    void setCodNombre (const char *nom){strcpy(Nombre,nom);}
    void setEdad (int e){Edad=e;}
    void setCodEquipo (const char *cod){strcpy(CodEquipo, cod);}

    const char *getCodJugador(){return CodJugador;}
    const char *getNombre(){return Nombre;}
    int getEdad(){return Edad;}
    const char *getCodEquipo(){return CodEquipo;}

    void cargar();
    void mostrar();

};

    void Jugador::cargar(){
    cout << "Ingrese cod Jugador : " ;
    cargarCadena(CodJugador,3);
    cout << "Ingrese Nombre : " ;
    cargarCadena (Nombre,3);
    cout << "Edad : " ;
    cin >> Edad ;
    cout << "Ingrese Cod Equipo : " ;
    cargarCadena(CodEquipo,3);
    }

    void Jugador::mostrar(){
    cout << "Cod Jugador : " << CodJugador << endl;
    cout << "Nombre : " << Nombre << endl;
    cout << "Edad : " << Edad << endl;
    cout << "Cod Equipo : " << CodEquipo << endl;
    }

class archivoJugador{
private:
	char nombre[30];
	public:
	archivoJugador(const char* n){
		strcpy(nombre,n);
	}

	Jugador leerRegistro(int pos){
    Jugador reg;
    reg.setEdad (-1);
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

    int AgregarRegistro(){
	Jugador reg;
	FILE *p;
	p = fopen(nombre, "ab");
	if(p==NULL){
	cout << "No se pudo abrir o crear el archivo" << endl;
	return -1;
    }
	reg.cargar();
	int valor = fwrite (&reg, sizeof reg, 1, p);
	fclose(p);
	return valor;
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
    reg.mostrar();
    cout << endl;
    }
    fclose(p);
    return true;
    }
};




class Partido{
private:
    char CodJugador [5];
    int dia, mes;
    int CantidadGoles;
    bool expulsado;
public:
    void setCodJugador(const char *c){strcpy(CodJugador,c);}
    void setDia(int d){dia=d;}
    void setMes(int m){mes=m;}
    void setCantidadGoles (int goles){CantidadGoles=goles;}
    void setExpulsado (bool e){expulsado=e;}

    const char *getCodJugador(){return CodJugador;}
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getCantidadGoles(){return CantidadGoles;}
    bool getExpulsado(){return expulsado;}

    void cargar();
    void mostrar();

    };

    void Partido::cargar(){
    cout << "Ingrese cod Jugador : " ;
    cargarCadena(CodJugador,3);
    cout << "Ingresar dia : " ;
    cin>>dia;
    cout << "Ingresar Mes : " ;
    cin >> mes;
    cout << "Cantidad de goles : " ;
    cin >>  CantidadGoles ;
    cout << "Expulsado 0/NO, 1/SI : " ;
    cin >> expulsado;
    }

    void Partido::mostrar(){
    cout << "Cod Jugador : " << CodJugador << endl;
    cout << "Dia: " << dia << endl;
    cout << "Mes : " << mes << endl;
    cout << "Goles : " << CantidadGoles << endl;
    cout << "Expulsado 0/NO, 1/SI : " << expulsado << endl ;
    }


class archivoPartido{
private:
	char nombre[30];
	public:
	archivoPartido(const char* n){
		strcpy(nombre,n);
	}

	Partido leerRegistro(int pos){
    Partido reg;
    reg.setCantidadGoles(-1);
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
        return tam/sizeof(Partido);
    }

    int AgregarRegistro(){
	Partido reg;
	FILE *p;
	p = fopen(nombre, "ab");
	if(p==NULL){
	cout << "No se pudo abrir o crear el archivo" << endl;
	return -1;
    }
	reg.cargar();
	int valor = fwrite (&reg, sizeof reg, 1, p);
	fclose(p);
	return valor;
    }

    bool listarArchivo(){
    Partido reg;
    FILE *p;
    p = fopen(nombre, "rb");
    if (p == NULL){
    cout << "No se pudo abrir " << endl;
    return false;
    }
    while (fread(&reg, sizeof reg, 1, p)==1 ){
    reg.mostrar();
    cout << endl;
    }
    fclose(p);
    return true;
    }

    bool escribirRegistro(archivoPartido reg){
    FILE *p;
    p=fopen(nombre, "ab");
    if(p==NULL) return false;
    bool escribio = fwrite(&reg, sizeof reg, 1, p);
    fclose(p);
    return escribio;
    }
};
#endif // CLASES_H_INCLUDED
