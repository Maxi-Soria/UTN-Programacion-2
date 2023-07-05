#include <iostream>
#include <cstdlib>
#include <string.h>


using namespace std;


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
    char vec_char[6];
    bool repetido = false;
    for (int i = 0; i < 10; i++) {
        cout << "Ingrese el codigo (5 digitos): " << i+1;
        cargar_cadena(vec[i].codigo, 5);
        cout << "Ingrese una descripcion (30 digitos): ";
        cargar_cadena(vec[i].descripcion, 30);
        cout << "Ingrese el precio: ";
        cin >> vec[i].precio;
        cout << "Ingrese el stock: ";
        cin >> vec[i].stock;

        repetido = false;
        for (int j = 0; j < i; j++) {
            if (strcmp(vec[j].codigo, vec[i].codigo) == 0) {
                repetido = true;
                j = i;
            }
        }
        while (repetido) {
            cout << "El codigo ya existe, por favor ingrese otro.\n";
            cargar_cadena(vec_char, 5);
            strcpy(vec[i].codigo, vec_char);
            repetido = false;
            for (int j = 0; j < i; j++) {
                if (strcmp(vec[j].codigo, vec[i].codigo) == 0) {
                    repetido = true;
                    j=i;
                }
            }
        }
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
