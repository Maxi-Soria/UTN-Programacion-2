#include <iostream>
#include <cstdlib>

using namespace std;

/*
Hacer una funci�n que reciba como par�metros un vector de enteros y un n�mero entero que indica la cantidad de
componentes del vector, y que devuelva la posici�n que ocupa el valor m�nimo contenido en ese vector.
*/

int buscar_pos_minimo (int vec[], int TAM){
    int pos_minimo = 0;
    int minimo = vec[0];
    for (int i = 1; i < TAM; i++){
        if (vec[i] < minimo){
            minimo = vec[i];
            pos_minimo = i;
        }
    }
    return pos_minimo;
}

int main(){

    setlocale (LC_ALL, "Spanish");
    int const TAM = 5;
    int vect[TAM] = {2,-6,10,8,0};

    cout << buscar_pos_minimo(vect, TAM);


    return 0;
}
