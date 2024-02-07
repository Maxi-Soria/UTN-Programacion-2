#include <iostream>
#include <cstdlib>

using namespace std;

/*
Hacer una función que reciba como parámetros un vector de enteros de 10 elementos y un número entero,
y que devuelva la cantidad de veces que el número recibido como parámetro se repite dentro del vector.
*/

int veces_repetido(int *vec, int valor){
    int cant_repeticiones = 0;
    for (int i = 0; i < 10; i++){
        if(vec[i] == valor){
            cant_repeticiones++;
        }
    }
    return cant_repeticiones;
}

int main(){
    setlocale (LC_ALL, "Spanish");

    int const TAM = 10;
    int vect[TAM] = {2,-6,-12,8,0,14,-6,-6,5,9};
    int val_a_buscar = -6;

    cout << "El numero "<< val_a_buscar << " esta repetido " << veces_repetido(vect, val_a_buscar) << " veces";


    return 0;
}
