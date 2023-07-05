#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

void cargar_cadena(char *palabra, int tam){
    int i = 0;
    fflush(stdin);
    for (i = 0 ; i < tam ; i++ ){
        palabra[i] = cin.get();
        if(palabra[i] == '\n') break;
    }
    palabra[i] = '\0';
    fflush(stdin);
}

class Fecha{
private:
    int _dia, _mes, _anio;

public:
    void Cargar();
    void Mostrar();

    ///Constructor
    Fecha(){_dia = 1; _mes = 1; _anio = 2029;}
    Fecha(int dia, int mes, int anio){
        if (dia>0 && dia<31 && mes>0 && mes<13 && anio>1600){
            _dia = dia;
            _mes = mes;
            _anio = anio;
        }else{
            _dia = 1;
            _mes = 1;
            _anio = 1600;
        }
    }



    ///Getters
    int getDia(){return _dia;}
    int getMes(){return _mes;}
    int getAnio(){return _anio;}

    ///Seters
    void setDia(int dia){if(dia>0 && dia<32) _dia = dia;}
    void setMes(int mes){if(mes>0 && mes<13) _mes=mes;}
    void setAnio(int anio){if(anio>0) _anio=anio;}


};

void Fecha::Cargar(){
    int dia, mes, anio;
    bool correcto = false;
    do{
    cout << "Ingrese el dia: ";
    cin >> dia;
    cout << "Ingrese el mes: ";
    cin >> mes;
    cout << "Ingrese el año: ";
    cin >> anio;

    if (dia>0 && dia<32 && mes>0 && mes<13 && anio>0){
        _dia = dia;
        _mes = mes;
        _anio = anio;
        correcto = true;
    }
    else{
        cout << "Fecha no valida" << endl << endl;
    }

    } while (!correcto);
}

void Fecha::Mostrar(){
    cout << _dia << "/" << _mes << "/" << _anio << endl;
}



class Cliente{
private:
    int _dni;
    Fecha _fechaDeNac;
    char _nombre[20];
    char _apellido[20];
    char _email[20];
    char _telefono[10];
public:
    void Cargar();
    void Mostrar();

    Cliente(){
        _dni = 0;
        _fechaDeNac.setDia(1);
        _fechaDeNac.setMes(1);
        _fechaDeNac.setAnio(1900);
        strcpy(_nombre,"null");
        strcpy(_apellido,"null");
        strcpy(_email,"null");
        strcpy(_telefono,"null");
    }

    Cliente(int dni, Fecha fechaDeNac, const char* nombre, const char* apellido, const char* email, const char* telefono){
        strcpy(_nombre, nombre);
        _dni = dni;
        _fechaDeNac = fechaDeNac;
        strcpy(_apellido,apellido);
        strcpy(_email,email);
        strcpy(_telefono,telefono);

    }


    ///gets
    int getDni(){return _dni;}
    Fecha getFechaDeNac(){return _fechaDeNac;}
    char* getNombre(){return _nombre;}
    char* getApellido(){return _apellido;}
    char* getEmail(){return _email;}
    char* getTelefono(){return _telefono;}

    ///sets
    void setDni(int dni){_dni=dni;}
    void setFechaDeNac(Fecha fechaDeNac){_fechaDeNac = fechaDeNac;}
    void setNombre(char* nombre){strcpy(_nombre,nombre);}
    void setApellido(char* apellido){strcpy(_apellido,apellido);}
    void setEmail(char* email){strcpy(_email, email);}
    void setTelefono(char* telefono){strcpy(_telefono,telefono);}

};

void Cliente::Cargar(){
    cout << "Ingrese su DNI: ";
    cin >> _dni;
    cout << "ingrese su fecha de nacimiento " << endl;
    _fechaDeNac.Cargar();
    cout << "Ingrese su nombre: ";
    cargar_cadena(_nombre,19);
    cout << "Ingrese su Apellido: ";
    cargar_cadena(_apellido,19);
    cout << "Ingrese su email: ";
    cargar_cadena(_email,19);
    cout << "Ingrese su telefono: ";
    cargar_cadena(_telefono,14);
    cout << endl;
}

void Cliente::Mostrar(){
    cout << "SU DNI ES: " << _dni << endl;;
    cout << "FECHA DE NACIMIENTO: ";
    _fechaDeNac.Mostrar();
    cout << "NOMBRE: " << _nombre << endl;
    cout << "APELLIDO: " << _apellido << endl;
    cout << "EMAIL: " << _email << endl;
    cout << "TELEFONO: " << _telefono << endl;
    cout << endl;
}

char menu(){
    char opc;

    cout << "SELECCIONE UNA LETRA" << endl;
    cout << "a) Cargar un vector de 10 clientes " << endl;
    cout << "b) Listar todos los artículos del vector. " << endl;
    cout << "c) Listar todos los clientes cuyo DNI sea mayor a un valor que se ingresa por teclado. " << endl;
    cout << "d) A partir de un valor de DNI recibido como parámetro, devolver la posición del objeto que contiene ese DNI.\n   De no encontrarlo devolver -1. " << endl;
    cout << "e) Igual a la función del punto anterior, pero debe devolver el objeto completo que contiene el DNI.\n   De no encontrar el código la función debe devolver un objeto Cliente con un valor de -1 en el DNI. " << endl;
    cout << "f) Dado una fecha que se recibe como parámetro devolver la cantidad de clientes cuyo nacimiento sea anterior a ese valor recibido. " << endl;
    cout << "s) SALIR " << endl;
    cout << "Su eleccion >_";
    cin >> opc;
    return opc;
}

void puntoA(Cliente* vec, int tam){
    for (int i=0 ; i<tam ; i++ ){
        vec[i].Cargar();
    }
}

void puntoB(Cliente* vec, int tam){
    for (int i=0 ; i<tam ; i++ ){
        vec[i].Mostrar();
    }
}

void puntoC(Cliente* vec, int tam){
    int val;
    cout << "Ingrese un valor";
    cin >> val;
    for (int i=0 ; i<tam ; i++ ){
        if(vec[i].getDni() > val){
            vec[i].Mostrar();
        }
    }
}

int  puntoD(Cliente* vec, int tam, int val){

    for (int i=0 ; i<tam ; i++ ){
        if(vec[i].getDni() == val){
            return i;
        }
    }
    return -1;
}

Cliente puntoE(Cliente* vec, int tam, int val){
    Cliente aux;
    for (int i=0 ; i<tam ; i++ ){
        if(vec[i].getDni() == val){
            return vec[i];
        }
    }
    aux.setDni(-1);
    return aux;
}

int puntoF(Cliente* vec, int tam, Fecha obj){
    int cont = 0;
    for (int i=0 ; i<tam ; i++ ){
        if (vec[i].getFechaDeNac().getAnio() < obj.getAnio()){
            cont++;
        }
        else{
            if (vec[i].getFechaDeNac().getAnio() == obj.getAnio() && vec[i].getFechaDeNac().getMes() < obj.getMes()){
                cont++;
            }
            else{
                if(vec[i].getFechaDeNac().getMes() == obj.getMes() && vec[i].getFechaDeNac().getDia() < obj.getDia()){
                    cont++;
                }
            }
        }
    }

    return cont;
}


int main(){
    setlocale (LC_ALL, "Spanish");

    Fecha objFecha(15,12,1989);
    int valor = 23456789;
    objFecha.Mostrar();
    char opc;
    const int TAM = 4;

    Cliente vecCli[TAM] = {
    };
    Cliente aux;

    do{
        system("cls");
        opc = menu();

        switch (opc){
        case 'a':
                system("cls");
                puntoA(vecCli, TAM);
                system("pause");
            break;
        case 'b':
                system("cls");
                puntoB(vecCli, TAM);
                system("pause");
            break;
        case 'c':
                system("cls");
                puntoC(vecCli, TAM);
                system("pause");
            break;
        case 'd':
                system("cls");
                cout << "El cliente con ese DNI se encuentra en la posicion: " << puntoD(vecCli, TAM, valor) << endl;
                system("pause");
            break;
        case 'e':
                system("cls");
                aux = puntoE(vecCli, TAM, valor);
                aux.Mostrar();
                system("pause");
            break;
        case 'f':
                system("cls");
                cout << "Cantidad: " << puntoF(vecCli, TAM, objFecha) << endl;
                system("pause");
            break;
        case 's':

            break;
        }

    } while (opc != 's');



    return 0;
}
/*
CLIENTE 1
12345678
1
12
1989
Ana
Garcia
ana.garcia@example.com
55512345678

CLIENTE 2
23456789
22
05
1985
Luis
Perez
luis.perez@example.com
55523456789

CLIENTE 3
34567890
05
12
1989
María
Fernandez
maria.fernandez@example.com
55534567890

CLIENTE 4
45678901
18
08
1995
Jorge
Gonzalez
jorge.gonzalez@example.com
55545678901
*/
/*

12345678
1
12
1989
Ana
Garcia
ana.garcia@example.com
55512345678
23456789
22
05
1985
Luis
Perez
luis.perez@example.com
55523456789
34567890
05
12
1989
Maria
Fernandez
maria.fernandez@example.com
55534567890
45678901
18
08
1995
Jorge
Gonzalez
jorge.gonzalez@example.com
55545678901
*/
