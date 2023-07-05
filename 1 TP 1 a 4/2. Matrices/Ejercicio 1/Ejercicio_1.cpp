#include <iostream>
#include <cstdlib>

using namespace std;

/*
Hacer una función que reciba como parámetros una matriz de enteros de 10x10 y un número entero
(entre 0 y 9), y devuelva el máximo de la fila indicada por el segundo parámetro.
*/

int maximo_de_la_fila(int matriz[][4], int fila){
    int maximo = matriz[fila][0];
    for (int i=0 ; i<4 ; i++ ){
        if(matriz[fila][i] > maximo){
            maximo = matriz[fila][i];
        }
    }
    return maximo;
}

int main(){
    setlocale (LC_ALL, "Spanish");
    int const COL = 4;
    int const FILA = 4;

    int buscar_en_fila = 1;

    int mat[FILA][COL] = {{2,6,5,9},{9,15,-6,8},{10,12,13,11},{-9,-6,-1,-4}};

    cout << "El numero maximo de la fila " << buscar_en_fila << " es: " << maximo_de_la_fila(mat, buscar_en_fila);

    return 0;
}
