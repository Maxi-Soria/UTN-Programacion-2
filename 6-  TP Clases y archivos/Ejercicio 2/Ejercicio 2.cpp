#include <iostream>
#include <cstring>


using namespace std;


class Investigador{
    private:
        int _dni;
        char _nombre[30];
        char _apellido[30];
        Fecha _fechaDeNac;
        int _unidadAcad; // 1 a 30
        int _categoria; // 1 a 5
        int _especialidad; // 1 a 10

    public:
        Investigador();
        void Cargar();
        void Mostrar();

        void setDni(int dni){if (dni>0) _dni = dni;}
        void setNombre(char* nombre){strcpy(_nombre, nombre);}
        void setApellido(char* apellido){strcpy(_apellido, apellido);}
        void setFechaDeNac(Fecha fechaDeNac){_fechaDeNac = fechaDeNac;}
        void setUnidadAcad(int unidadAcad){if(unidadAcad>0 && unidadAcad<31) _unidadAcad = unidadAcad;}
        void setCategoria(int categoria){if(categoria>0 && categoria<6) _categoria = categoria;}
        void setEspecialidad(int especialidad){if(especialidad>0 && especialidad<11) _especialidad = especialidad;}

        int   getDni(){return _dni;}
        char* getNombre(){return _nombre;}
        char* getApellido(){return _apellido;}
        Fecha getFechaDeNac(){return _fechaDeNac;}
        int   getUnidadAcad(){return _unidadAcad;}
        int   getCategoria(int categoria){return _categoria;}
        int   getEspecialidad(int especialidad){return _especialidad;}


};

Investigador::Investigador(){
    setDni(100);
    setNombre(strcpy(_nombre,"sin dato"));
    setApellido(strcpy(_apellido,"sin dato"));
    setFechaDeNac(Fecha(1,1,1900));
    setUnidadAcad(1);
    setCategoria(1);
    setEspecialidad(1);

}

void Investigador::Cargar(){
    cout << "Ingrese su Dni: ";
    cin >> _dni;
    cout << "Ingrese nombre: ";
    cargarCadena(_nombre, 29);
    cout << "Ingrese apellido: ";
    cargarCadena(_apellido, 29);
    cout << "Ingrese la fecha de nac: ";
    _fechaDeNac.Cargar();
    cout << "Ingrese Unidad academica: ";
    cin >> _unidadAcad;
    cout << "Ingrese categoria: ";
    cin >> _categoria;
    cout << "Ingrese especialidad: ";
    cin >> _especialidad;
    cout << endl;

}

void Investigador::Mostrar(){
    cout << "DNI: " << _dni << endl;
    cout << "NOMBRE Y APELLIDO: " << _nombre << " " << _apellido << endl;
    cout << "FECHA DE NACIMIENTO: ";
    _fechaDeNac.Mostrar();
    cout << "UNIDAD ACADEMICA: " << _unidadAcad << endl;
    cout << "CATEGORIA: " << _categoria << endl;
    cout << "ESPECIALIDAD: " << _especialidad << endl;
    cout << endl;

}

class ArchivoInvestigador{
private:
    char _nombreArchivo[20];

public:
    ArchivoInvestigador(const char* nombreArchivo){strcpy(_nombreArchivo,nombreArchivo);}
    bool agregarRegistro();
    bool listarRegistros();
    int listarPorUnidadAcademica(int unidAcad);

};

bool ArchivoInvestigador::agregarRegistro(){
    Investigador reg;

    FILE* pInv;

    pInv = fopen(_nombreArchivo, "ab");
    if(pInv == NULL){
        return false;
    }
    reg.Cargar();
    fwrite(&reg, sizeof (Investigador),1,pInv);
    fclose(pInv);
    return true;

}

bool ArchivoInvestigador::listarRegistros(){
    Investigador reg;

    FILE* pInv;

    pInv = fopen(_nombreArchivo, "rb");
    if(pInv == NULL){
        return false;
    }
    while(fread(&reg, sizeof (Investigador),1,pInv) == 1){
        reg.Mostrar();
        cout << endl;

    }
    fclose(pInv);
    return true;
}


int ArchivoInvestigador::listarPorUnidadAcademica(int unidAcad){
    Investigador reg;
    int cont = 0;
    FILE* pInv;

    pInv = fopen(_nombreArchivo, "rb");
    if(pInv == NULL){
        return -1;
    }
    while(fread(&reg, sizeof (Investigador),1,pInv) == 1){
        if(reg.getUnidadAcad() == unidAcad){
            reg.Mostrar();
            cont++;
        }

    }
    fclose(pInv);
    if(cont == 0){
        return -2;
    }
    return 1;
}




int main(){
    setlocale (LC_ALL, "Spanish");

    ArchivoInvestigador obj("Investigadores.dat");
    int opc, ret;



    do{
        system("cls");
        cout << "        MENU" << endl;
        cout << "-------------------" << endl;
        cout << "1- Agregar Registro" << endl;
        cout << "2- Listar Registros" << endl;
        cout << "3- Listar por Unidad Academica" << endl;
        cout << "0- SALIR" << endl;

        cin >> opc;
        switch (opc){
        case 1:
            system("cls");
            if(!obj.agregarRegistro()){cout << "NO SE PUDO CREAR O AGREGAR EL REGISTRO" << endl;}
            else{cout << "REGISTRO AGREGADO!!!" << endl;}
            system("pause");
            break;
        case 2:
            system("cls");
            if(!obj.listarRegistros()){cout << "NO SE PUDO LEER EL ARCHIVO" << endl;}
            system("pause");
            break;
        case 3:
            system("cls");
            ret = obj.listarPorUnidadAcademica(8);
            if(ret == -1) cout << "NO SE PUDO LEER EL REGISTRO" << endl;
            else if(ret == -2) cout << "NO EXISTEN REGISTROS CON ESE CODIGO "<< endl;
            system("pause");
            break;

        case 0:
            cout << "SALIR " << endl;
        default:
            break;
        }
    } while (opc != 0);

	return 0;
}


/*
12345678
Ana
Perez
01
01
1990
3
2
8

23456789
Juan
Gomez
15
03
1985
5
2
9

34567890
Laura
Rodriguez
22
07
1995
5
2
4

45678901
Carlos
Fernandez
03
11
1982
8
7
3

56789012
Marta
Lopez
12
05
1992
5
4
1
*/
