#include <iostream>
#include <cstdlib>

using namespace std;


struct articulo {
    char codigo[6];
    char descripcion[30];
    float precio;
    int stock;
};

///PROTOTIPOS
void cargar_cadena(char *palabra, int tam);
void cargar_registro(articulo &a);
void mostrar_registro(const articulo art);

int main(){
    setlocale (LC_ALL, "Spanish");

    articulo art;

    cargar_registro(art);
    cout << endl;
    mostrar_registro(art);

    return 0;
}

///funcion de el profe coco modificada
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

void cargar_registro(articulo &a){
    cout << "Ingrese el codigo (5 digitos): ";
    cargar_cadena(a.codigo, 5);
    cout << "Ingrese una descripcion (30 digitos): ";
    cargar_cadena(a.descripcion, 30);
    cout << "Ingrese el precio: ";
    cin >> a.precio;
    cout << "Ingrese el stock: ";
    cin >> a.stock;

}

void mostrar_registro(const articulo art){
    cout << "El codigo de articulo es: " << art.codigo<< endl;
    cout << "La descripcion " << art.descripcion << endl;
    cout << "El precio es: " << art.precio<< endl;
    cout << "El stock es: " << art.stock<< endl;
}
