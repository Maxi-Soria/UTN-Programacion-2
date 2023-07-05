#include <iostream>
#include <cstdlib>

using namespace std;

/*
Hacer una función que reciba como parámetros una matriz de enteros de 10x10,
 y devuelva la suma de todos los componentes de la matriz.
*/

int sumar_matriz(int mat[][4]){
    int acum = 0;
    for (int i=0 ; i<4 ; i++ ){
        for (int j=0 ; j<4 ; j++ ){
            acum +=  mat[i][j];
        }
    }
    return acum;
}

int main(){
    setlocale (LC_ALL, "Spanish");

    int const COL = 4;
    int const FILA = 4;

    int mat[FILA][COL] = {{2,6,5,9},{9,15,-6,8},{10,12,13,11},{-9,-6,-1,-4}};

    cout << "La suma de todos los elementos de la matriz es: " << sumar_matriz(mat);


    return 0;
}
