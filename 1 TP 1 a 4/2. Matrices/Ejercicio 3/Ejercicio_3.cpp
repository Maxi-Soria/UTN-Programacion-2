#include <iostream>
#include <cstdlib>

using namespace std;

/*
Hacer una función que reciba como parámetros una matriz de enteros de 10x10 y un número entero (entre 0 y 9),
 y devuelva la suma de todos los componentes de la columna indicada por el segundo parámetro.
*/

int suma_columna(int matriz[][4], int col){
    int suma_col = 0;
    for (int i=0 ; i<4 ; i++ ){
        suma_col += matriz[i][col];
    }
    return suma_col;
}

int main(){
    setlocale (LC_ALL, "Spanish");
    int const COL = 4;
    int const FILA = 4;

    int columna_a_sumar = 1;

    int mat[FILA][COL] = {{2,6,5,9},{9,15,-6,8},{10,12,13,11},{-9,-6,-1,-4}};

    cout << "La suma de la columna " << columna_a_sumar << " es: " << suma_columna(mat, columna_a_sumar);

    return 0;
}

