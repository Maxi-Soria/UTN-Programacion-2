#include <iostream>
#include "Articulo.h"

using namespace std;

int main(){
    setlocale (LC_ALL, "Spanish");

    char opcion;
    int const TAM_VEC=3;
    Articulo vecObj[TAM_VEC], obj;

    char codigoBuscado[6]={"A2000"};
    int pos;
    int valor = 45;


    do{
        system("cls");
        opcion = menu();

        switch (opcion){
        case 'a':
                system("cls");
                cargarVector(vecObj, TAM_VEC);
                system("pause");
            break;
        case 'b':
                system("cls");
                mostrarVector(vecObj, TAM_VEC);
                system("pause");
            break;
        case 'c':
                system("cls");
                mostrarArticulosDePreciosMayores(vecObj,TAM_VEC);
                system("pause");
            break;
        case 'd':
                system("cls");
                cout << "Ingrese codigo a buscar: " << endl;
                cargar_cadena(codigoBuscado,5);
                cout << "El codigo buscado se encuentr a en la posicion " << devolverPosicion(vecObj,TAM_VEC,codigoBuscado) << endl;
                system("pause");
            break;
        case 'e':
                system("cls");
                cout << "Ingrese codigo a buscar: " << endl;
                cargar_cadena(codigoBuscado,5);
                obj = devolverArticuloQueContiene(vecObj,TAM_VEC,codigoBuscado);
                cout << "ARTICULO: " << endl;
                obj.Mostrar();
                system("pause");
            break;
        case 'f':
                system("cls");
                cout << "Ingrese el stock deseado: ";
                cin >> valor;
                cout << "El total de articulos superiores al stock recibido es: " << cantidadConStockInferior(vecObj,TAM_VEC,valor) << endl;
                system("pause");
            break;
        case 'g':
                system("cls");
                cout << "Ingrese el porcentaje de aumento: ";
                cin >> valor;
                aumentarPrecio(vecObj,TAM_VEC,valor);
                mostrarVector(vecObj,TAM_VEC);
                system("pause");
            break;
        case 's':
                system("cls");
                cout << "Hasta pronto!!" << endl;
            break;
        }

    } while (opcion != 's');


    return 0;
}
