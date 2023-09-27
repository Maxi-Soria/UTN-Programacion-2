#ifndef CLASES_H_INCLUDED
#define CLASES_H_INCLUDED

#include <iostream>
#include <cstring>
using namespace std;
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
class Personal{
private:
		char dni[10];
		char nombre[10];
		char apellido[10];
		int cargo;
		int numero;
		char localidad[20];
		char mail[20];
		int telefono;
public:
void setDni(const char* _dni){strcpy(dni,_dni);}
void setNombre(const char* nom){strcpy(nombre,nom);}
void setApellido(const char*ape){strcpy(apellido,ape);}
void setcargo(int carg){cargo=carg;}
void setNumero(int num){numero=num;}
void setLocalidad(const char* locali){strcpy(localidad,locali);}
void setMail(const char* email){strcpy(mail,email);}
void setTelefono(int tele){telefono=tele;}

const char* getDNI(){return dni;}
const char* getNombre(){return nombre;}
const char* getApellido(){return apellido;}
int getCargo(){return cargo;}
int getNumero(){return numero;}
const char* getLocalidad(){return localidad;}
const char* getMail(){return mail;}
int getTelefono(){return telefono;}

void Cargar(){
cout << "ingrese DNI: "<<endl;
cargarCadena(dni,9);
cout << "nombre: "<<endl;
cargarCadena(nombre,9);
cout << "apellido" <<endl;
cargarCadena(apellido,9);
cout << "cargo" <<endl;
cin >>cargo;
cout << "numero" <<endl;
cin>>numero;
cout << "localidad" <<endl;
cargarCadena(localidad,19);
cout << "mail" <<endl;
cargarCadena(mail,19);
cout << "telefono" <<endl;
cin>>telefono;
}

void Mostrar(){

cout << "ingrese DNI: "<< dni <<endl;
cout << "nombre: "<< nombre <<endl;
cout << "apellido" << apellido <<endl;
cout << "cargo" << cargo <<endl;
cout << "numero" << numero << endl;
cout << "localidad" << localidad <<endl;
cout << "mail" << mail << endl;
cout << "telefono" << telefono << endl;

}

};
class ArchivoPersonal{
	private:
    char nombre[30];
public:
    ArchivoPersonal(const char *n){
        strcpy(nombre, n);
    }
    Personal leerRegistro(int pos){
        Personal reg;
        reg.setNumero(-1);
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof(Personal)*pos,0);
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
        return tam/sizeof(Personal);
    }
    int AgregarRegistro(){
	Personal reg;
	FILE *p;
	p = fopen(nombre, "ab");
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
    Personal reg;
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

class Contrato{
private:

	char dniEmpleado[10];
	int numeroMuseo;
	int TipoContrato;
	int Fecha;
public:
	void setDniEmpleado(const char* dniE){strcpy(dniEmpleado,dniE);}
	void setNumeroMuseo(int numMuseo){numeroMuseo=numMuseo;}
	void setTipoContrato(int tipo){TipoContrato=tipo;}
	void ssetFecha(int fech){Fecha=fech;}

	const char* getDniEmpledo(){return dniEmpleado;}
	int getNumeroMuseo(){return numeroMuseo;}
	int getTipoContrato(){return TipoContrato;}
	int getFecha(){return Fecha;}

	void Cargar(){
	cout << "dni empleado: " <<endl;
	cargarCadena(dniEmpleado,9);
	cout << "numero de museo: " <<endl;
	cin>>numeroMuseo;
	cout << "tipo Contrato: "<< endl;
	cin>>TipoContrato;
	cout << "Fecha: " <<endl;
	cin>>Fecha;
	}
	void Mostrar(){
	cout << "dni empleado: " << dniEmpleado<<endl;

	cout << "numero de museo: " << numeroMuseo<<endl;

	cout << "tipo Contrato: "<< TipoContrato <<  endl;
	cout << "Fecha: " << Fecha<< endl;

	}


};

class ArchivoContrato{
	private:
    char nombre[30];
public:
    ArchivoContrato(const char *n){
        strcpy(nombre, n);
    }
    Contrato leerRegistro(int pos){
        Contrato reg;
        reg.setNumeroMuseo(-1);
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof(Contrato)*pos,0);
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
        return tam/sizeof(Contrato);
    }
    int AgregarRegistro(){
	Contrato reg;
	FILE *p;
	p = fopen(nombre, "ab");
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
    Contrato reg;
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
class Museo{
private:
    int numMuseo;
    int numEspecialidad; // del 1 al 8
    int anio;
    char nombre [30];
    char dniDirector [10];

public:
    void setNumMuseo(int museo){numMuseo=museo;}
    void setEspecialidad(int e){numEspecialidad = e;}
    void setAnio(int a){anio=a;}
    void setNombre (const char *n){strcpy(nombre,n);}
    void setDniDirector (const char *dni){strcpy(dniDirector,dni);}

    int getNumMuseo(){return numMuseo;}
    int getEspecialidad(){return numEspecialidad;}
    int getAnio(){return anio;}
    const char * getNombre(){return nombre;}
    const char * getDniDirector(){return dniDirector;}

    void Cargar(){
    cout << "Numero museo : " ;
    cin >> numMuseo;
    cout << "Numero especialidad : " ;
    cin >> numEspecialidad;
    cout << "Anio : " ;
    cin >> anio;
    cout << "Nombre del Museo : ";
    cargarCadena(nombre,29);
    cout << "Dni del director : " ;
    cargarCadena(dniDirector, 9);
    }

    void Mostrar(){
    cout << "Numero del museo : " << numMuseo << endl;
    cout << "Numero de especialidad : " << numEspecialidad << endl;
    cout << "Anio : " << anio << endl;
    cout << "Nombre del museo : " << nombre << endl;
    cout << "Dni del director : " << dniDirector << endl;
    }

};


class ArchivoMuseo{
private:
    char nombre[30];

public:

    ArchivoMuseo(const char *n){
        strcpy(nombre, n);
    }
    Museo leerRegistro(int pos){
        Museo reg;
        reg.setNumMuseo(-1);
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof(Museo)*pos,0);
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
        return tam/sizeof(Museo);
    }

    int AgregarRegistro(){
	Museo reg;
	FILE *p;
	p = fopen(nombre, "ab");
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
    Museo reg;
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

#endif // CLASES_H_INCLUDED
