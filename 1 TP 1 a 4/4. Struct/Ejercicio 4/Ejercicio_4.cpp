#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;

struct articulo{
    char codigo[6];
    char descripcion [30];
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
        cout << "Ingrese una descripcion (30 digitos): ";
        cargar_cadena(vec[i].descripcion,29);
        //cin >> vec[i].descripcion;
        cout << "Ingrese el precio: ";
        cin >> vec[i].precio;
        cout << "Ingrese el stock: ";
        cin >> vec[i].stock;
        }
        cout << "------------------------" << endl;
}

articulo buscar_pos_cadena(articulo *vec, char *cadena){
    articulo art_no_encontrado = {"-1","No se encontro", -1, -1};
    int i;
    for ( i=0 ; i<10 ; i++ ){
        if(strcmp(vec[i].codigo, cadena) == 0){
            return vec[i];
        }
    }
return art_no_encontrado;
}

int main(){
    setlocale (LC_ALL, "Spanish");

    articulo vec[10];
    articulo retorno;
    char cad[6] = {'1','0','A','A','0'};
    //cargar_cadena(cad,5);

    cargar_articulos(vec);

    cout << "vector en pos 0 >> " << vec[0].codigo << endl;
    cout << "Cadena de char >> " << cad << endl;
    cout << "----------------------" << endl;

    retorno = buscar_pos_cadena(vec, cad);
    cout << "Codigo: " << retorno.codigo << endl;
    cout << "Descripcion: " << retorno.descripcion << endl;
    cout << "Precio: " << retorno.precio << endl;
    cout << "Stock: " << retorno.stock << endl;


    return 0;
}
