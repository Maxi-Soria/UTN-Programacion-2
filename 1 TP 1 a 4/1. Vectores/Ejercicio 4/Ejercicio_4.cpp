#include <iostream>
#include <cstdlib>

using namespace std;

/*
Hacer una función que reciba como parámetros un vector de enteros y un número entero que indica la cantidad de
componentes del vector, y que devuelva la posición que ocupa el valor máximo contenido en ese vector.
*/

int buscar_pos_maximo (int vec[], int TAM){
    int pos_maximo = 0;
    int maximo = vec[0];
    for (int i = 1; i < TAM; i++){
        if (vec[i] > maximo){
            maximo = vec[i];
            pos_maximo = i;
        }
    }
    return pos_maximo;
}

int main(){

    setlocale (LC_ALL, "Spanish");
    int const TAM = 5;
    int vect[TAM] = {2,-6,10,8,0};

    cout << buscar_pos_maximo(vect, TAM);


    return 0;
}
