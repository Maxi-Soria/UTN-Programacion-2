#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Articulo.h"

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


Articulo::Articulo(char* descripcion){
    strcpy(_descripcion,descripcion);
}

Articulo::Articulo(){
    strcpy(_codigo,"Null");
    strcpy(_descripcion,"Tambien Null");
    _precio = 0;
    _stock =0;
    _estado = false;
}


void Articulo::Cargar(){
    cout << "Ingrese el codigo: ";
    cargar_cadena(_codigo,6);
    cout << "Ingrese la descripcion: ";
    cargar_cadena(_descripcion, 31);
    cout << "Ingrese el precio: $";
    cin >>  _precio;
    cout << "Ingrese el stock: ";
    cin >>  _stock;
    cout << "Ingrese el estado: ";
    cin >> _estado;
}


void Articulo::Mostrar(){
    cout << "CODIGO: ";
    cout << _codigo << endl;
    cout << "DESCRIPCION: ";
    cout << _descripcion << endl;
    cout << "PRECIO: $";
    cout << _precio << endl;
    cout << "STOCK: ";
    cout << _stock << endl;
    cout << "ESTADO: ";
    cout << _estado << endl;
}

char* Articulo::getCodigo() {return _codigo;}
char* Articulo::getDescripcion() {return _descripcion;}
float Articulo::getPrecio() {return _precio;}
int Articulo::getStock() {return _stock;}
bool Articulo::getEstado() {return _estado;}

void Articulo::setCodigo(char* codigo) {strcpy(_codigo, codigo);}
void Articulo::setDescripcion(char* descripcion) {strcpy(_descripcion, descripcion);}
void Articulo::setPrecio(float precio) {_precio = precio;}
void Articulo::setStock(int stock) {_stock = stock;}
void Articulo::setEstado(bool estado) {_estado = estado;}

///PUNTO 2 a)
void cargarVector(Articulo *vec, int tam){
    for (int i=0 ; i<tam ; i++ ){
        vec[i].Cargar();
        cout << endl;
    }
}

///PUNTO 2 b)
void mostrarVector(Articulo *vec, int tam){
    for (int i=0 ; i<tam ; i++ ){
        cout << "ARTICULO " << i+1 << endl;
        vec[i].Mostrar();
        cout << endl;
    }
}

///PUNTO 2  c)
void mostrarArticulosDePreciosMayores(Articulo *vec,int tam){
    float valor;
    cout << "Ingrese el monto: ";
    cin >> valor;
    cout << "Los Articulos con precios mayores a $" << valor << " son: " << endl;
    for (int i=0 ; i<tam ; i++ ){
        if(vec[i].getPrecio() > valor){
            cout << vec[i].getCodigo() << endl;;
        }
    }

}

///PUNTO 2  d)
int  devolverPosicion(Articulo *vec,int tam, char* cod){
    for (int i=0 ; i<tam ; i++ ){
        if(strcmp(vec[i].getCodigo(),cod) == 0){
           return i+1;
           }
    }
return -1;
}

///PUNTO 2  e)
Articulo devolverArticuloQueContiene(Articulo *vec,int tam, char* cod){
    for (int i=0 ; i<tam ; i++ ){
        if(strcmp(vec[i].getCodigo(),cod) == 0){
           return vec[i];
           }
    }
    vec[0].setStock(-1);
return vec[0];
}


///PUNTO 2  f)
int cantidadConStockInferior(Articulo *vec, int tam, int stock){
    int cont = 0;
    for (int i=0 ; i<tam ; i++ ){
        if(vec[i].getStock() > stock){
            cont++;
        }
    }
return cont;
}


///PUNTO 2  g)
void aumentarPrecio(Articulo *vec, int tam, int porcAumento){
    float aumento = porcAumento/100;
    float precio;
    for (int i=0 ; i<tam ; i++ ){
        precio = vec[i].getPrecio();
        vec[i].setPrecio(precio + (precio*porcAumento/100));
    }


}

char menu(){


    char opcion;
    cout << "MENU " << endl;
    cout << "a) Cargar un vector de 10 artículos" << endl;
    cout << "b) Listar todos los artículos del vector." << endl;
    cout << "c) Listar todos los artículos cuyo precio sea mayor a un valor que se ingresa por teclado." << endl;
    cout << "d) A partir de un valor de código recibido como parámetro, devolver la posición del objeto que contiene ese código." << endl;
    cout << "   De no encontrarlo devolver -1." << endl;
    cout << "e) Igual a la función del punto anterior, pero debe devolver el objeto completo que contiene el código." << endl;
    cout << "   De no encontrar el código la función debe devolver un objeto Articulo con un valor de -1 en el stock." << endl;
    cout << "f) Dado un valor de stock que se recibe como parámetro devolver la cantidad de artículos cuyo stock sea" << endl;
    cout << "   inferior a ese valor recibido." << endl;
    cout << "g) Dado un porcentaje de incremento que se recibe como parámetro, modificar el precio unitario de todos los objetos." << endl;
    cout << "s) SALIR" << endl;
    cout << "SELECCIONE UNA LETRA _";
    cin >> opcion;

    return opcion;

}
