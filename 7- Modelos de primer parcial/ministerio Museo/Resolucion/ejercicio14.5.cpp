#include <iostream>
#include <cstring>
using namespace std;
#include "Clases.h"
/*
1. Generar un archivo con los jefes del Área que hayan firmado contrato en el 2020,
 con el siguiente formato :
Dni, nombre y apellido

2.mostrar cuantos contratos temporarios tiene el año 2015

*/

class claseNueva{

private:
	char dni[10];
	char nombre[10];
	char apellido[10];
public:
	void set_Dni(const char* _dni){strcpy(dni,_dni);}
	void set_nombre(const char* _nom){strcpy(nombre,_nom);}
	void set_apellido(const char* _ape){strcpy(apellido,_ape);}

	const char* get_nombre(){return nombre;}
	const char* get_dni(){return dni;}
	const char* get_apellido(){return apellido;}

	void Mostrar(){
	cout << "DNI: "<< dni <<endl;
	cout << "Nombre: " << nombre <<endl;
	cout << "Apellido: "<< apellido <<endl;

	}
	void Cargar(){
	cout << "DNI: "<<endl;
	cargarCadena(dni,9);
	cout << "Nombre: " <<endl;
	cargarCadena(nombre,9);
	cout << "Apellido: "<<endl;
	cargarCadena(apellido,9);
	}
};

class archivoClaseNueva{
	private:
    char nombre[30];
public:
    archivoClaseNueva(const char *n){
        strcpy(nombre, n);
    }
    claseNueva leerRegistro(int pos){
        claseNueva reg;
        reg.set_Dni("123");
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
        return tam/sizeof(claseNueva);
    }
    int AgregarRegistro(){
	claseNueva reg;
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
    claseNueva reg;
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
	bool escribirRegistro(claseNueva reg){
            FILE *p;
            p=fopen(nombre, "ab");
            if(p==NULL) return false;
            bool escribio = fwrite(&reg, sizeof reg, 1, p);
            fclose(p);
            return escribio;
        }
};

void Punto1();
void Punto2();
int main(){

	Punto2();


	return 0;

}
void Punto1(){

	Personal perso;

	ArchivoPersonal archivoperso ("personal.dat");

	Contrato contra;

	ArchivoContrato archivoContra	("contrato.dat");

	claseNueva nuevaclase;

	archivoClaseNueva archivoNuevo ("claseNueva.dat");


	int cantRegPersonal = archivoperso.contarRegistros();
	int cantRegcontra = archivoContra.contarRegistros();

	for(int i = 0; i<cantRegPersonal; i++){
		perso = archivoperso.leerRegistro(i);
		for(int j = 0; j<cantRegcontra; j++){
			contra = archivoContra.leerRegistro(j);

			if(strcmp(perso.getDNI(),contra.getDniEmpledo())==0){

				if(perso.getCargo()==3){

			nuevaclase.set_apellido(perso.getApellido());
			nuevaclase.set_nombre(perso.getNombre());
			nuevaclase.set_Dni(perso.getDNI());
			archivoNuevo.escribirRegistro(nuevaclase);

				}

			}

		}

	}

		archivoNuevo.listarArchivo();
}
void Punto2(){

Contrato contra;
ArchivoContrato ArchivoContra ("contrato.dat");

int contador = 0;

int cantRegContrato = ArchivoContra.contarRegistros();

	for(int i=0; i<cantRegContrato; i++){

		contra = ArchivoContra.leerRegistro(i);

		if(contra.getTipoContrato()==1 && contra.getFecha()==2015){
			contador++;

		}

	}

		cout << contador << endl;
}
