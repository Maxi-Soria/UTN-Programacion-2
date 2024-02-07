#include <iostream>
#include <cstdlib>

using namespace std;

/*
Hacer una funci�n que reciba como par�metros un vector de enteros de 10 elementos y un n�mero entero,
y que devuelva la cantidad de veces que el n�mero recibido como par�metro se repite dentro del vector.
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
