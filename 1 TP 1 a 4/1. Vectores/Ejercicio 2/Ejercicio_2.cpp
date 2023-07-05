#include <iostream>
#include <cstdlib>

using namespace std;

/*
Hacer una función que reciba como parámetros un vector de enteros y un número entero que indica la
cantidad de componentes del vector, y que devuelva el valor mínimo contenido en ese vector.
*/

int buscar_mayor (int *vec, int TAM){
    int maximo = vec[0];
    for (int i = 1; i < TAM; i++){
        if (vec[i] > maximo){
            maximo = vec[i];
        }
    }
    return maximo;
}

int main(){
    setlocale (LC_ALL, "Spanish");
    int const TAM = 5;
    int vect[TAM] = {2,-16,-12,8,0};

    cout << buscar_mayor(vect, TAM);


    return 0;
}
