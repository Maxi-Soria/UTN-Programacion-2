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
    system("cls");
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
    system("pause");
}

void mostrar_articulos(articulo *vec){
    system("cls");
    for (int i=0 ; i<10 ; i++ ){
        cout << "Codigo : " << vec[i].codigo << endl;
        cout << "Descripcion: " << vec[i].descripcion << endl;
        cout << "Ingrese el precio: " << vec[i].precio << endl;
        cout << "Ingrese el stock: " << vec[i].stock << endl;;
        cout << endl;
    }
    system("pause");
}

void ventas(articulo *vec){
    system("cls");
    char cod_art[6];
    int cant_art;
    float importe = 0;
    bool cod_existe = false;

    cout << "Ingrese el codigo del articulo que desea: ";
    cargar_cadena(cod_art, 5);
    cout << "Cuantas unidades desea comprar?: ";
    cin >> cant_art;

    for (int i=0 ; i<10; i++ ){
        if(strcmp(vec[i].codigo, cod_art) == 0){
            cod_existe = true;

            if (vec[i].stock >= cant_art){
                importe = vec[i].precio * cant_art;
                i = 9;
            }else{
                cout << "No hay stock " << endl;
            }
        }
    }
    if (!cod_existe){
        cout << "El codigo no existe " << endl;
    }

  cout << "El importe a abonar es: $" << importe << endl;;
  system("pause");
}


int menu (){
    int opc;
    cout << "ELIJA UNA OPCION DEL SIGUIENTE MENU " << endl;
    cout << "1- Cargar Articulos" << endl;
    cout << "2- Mostrar Articulos" << endl;
    cout << "3- Venta" << endl;
    cout << "4- Salir" << endl;
    cout << ">_";
    cin >> opc;
    return opc;
}

int main(){
    setlocale (LC_ALL, "Spanish");

    int opc;
    char vec_codigo[6]={};
    articulo vec_articulos[10];

    do{
    system("cls");

    opc = menu();
    switch (opc){
    case 1:
        cargar_articulos(vec_articulos);
    break;
    case 2:
        mostrar_articulos(vec_articulos);
    break;
    case 3:
        ventas(vec_articulos);
    break;

    default:
        break;
    }

    } while (opc!=4);





    return 0;
}
