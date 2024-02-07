#include <iostream>
#include <cstdlib>

using namespace std;

/*
Hacer una función que reciba como parámetros un vector de enteros de 10 elementos y un número entero,
y que devuelva la posición si el número recibido existe en el vector, o -1 si no existe.
*/

int pos_en_el_vector(int vec[], int valor){
    for (int i = 0; i < 10; i++){
        if(vec[i] == valor){
            return i;
        }
    }
    return -1;
}

int main(){
    setlocale (LC_ALL, "Spanish");

    int const TAM = 10;
    int vect[TAM] = {2,-6,-12,8,0,14,3,-2,5,9};
    int val_a_buscar = -3;

    cout << "El numero "<< val_a_buscar << " esta en la posicion: " << pos_en_el_vector(vect, val_a_buscar);

    return 0;
}
