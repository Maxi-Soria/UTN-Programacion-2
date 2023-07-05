#include <iostream>
#include <cstdlib>

using namespace std;

/*
Hacer una funci�n que reciba como par�metros un vector de enteros y un n�mero entero que indica la
cantidad de componentes del vector, y que devuelva el valor m�nimo contenido en ese vector.
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
