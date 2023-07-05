#include <iostream>
#include <cstdlib>

using namespace std;

/*
Un comercio vende un total de 50 artículos diferentes. Para cada uno de ellos almacena la información que se detalló en el
ejercicio anterior.
Hacer un programa para cargar y mostrar por pantalla la lista de artículos. El programa debe tener un menú con funciones.
*/
struct articulo{
    char codigo[6];
    char descripcion [31];
    float precio;
    int stock;
};

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

void cargar_articulos(articulo *vec){
    for (int i=0 ; i<10 ; i++ ){
        cout << "Ingrese el codigo (5 digitos): ";
        cargar_cadena(vec[i].codigo, 5);
        //cin >> vec[i].codigo;
        cout << "Ingrese una descripcion (30 digitos): ";
        cargar_cadena(vec[i].descripcion,30);
        //cin >> vec[i].descripcion;
        cout << "Ingrese el precio: ";
        cin >> vec[i].precio;
        cout << "Ingrese el stock: ";
        cin >> vec[i].stock;
        }
}

void mostrar_articulos(articulo *vec){
    for (int i=0 ; i<10 ; i++ ){
        cout << "Codigo : " << vec[i].codigo << endl;
        cout << "Descripcion: " << vec[i].descripcion << endl;
        cout << "Ingrese el precio: " << vec[i].precio << endl;
        cout << "Ingrese el stock: " << vec[i].stock << endl;;
        cout << endl;
        }
}

int main(){
    setlocale (LC_ALL, "Spanish");

    char vec_codigo[6]={};
    articulo vec_articulos[10];

    cargar_articulos(vec_articulos);
    cout << endl;
    mostrar_articulos(vec_articulos);
    cout << endl;
    cout << vec_articulos[9].descripcion << endl;



    return 0;
}
/*
CARGA MASIVA
A2000
veinte
200
3
A1000
diez
300
5
A3000
treinta
100
6
A4000
cuarenta
200
4
A9000
noventa
300
7
A8000
ochenta
400
9
A7000
setenta
500
5
A5000
cincuenta
400
2
A6000
sesenta
200
6
10AA0
diez doble A
300
3
*/
