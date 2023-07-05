#include <iostream>
#include <cstdlib>

using namespace std;

/*
Hacer una función que reciba como parámetros una matriz de enteros de 10x10 y un número entero (entre 0 y 9),
y devuelva la cantidad de componentes positivos de la columna indicada por el segundo parámetro.
*/


int cantidad_de_positivos(int matriz[][4], int col){
    int cont_pos = 0;
    for (int i=0 ; i<4 ; i++ ){
        if(matriz[i][col] > 0){
            cont_pos++;
        }
    }
    return cont_pos;
}

int main(){
    setlocale (LC_ALL, "Spanish");
    int const COL = 4;
    int const FILA = 4;

    int columna_a_contar = 2;

    int mat[FILA][COL] = {{2,6,5,9},{9,15,-6,8},{10,12,13,11},{-9,-6,-1,-4}};

    cout << "La cantidad de positivos de la columna " << columna_a_contar << " es: " << cantidad_de_positivos(mat, columna_a_contar);

    return 0;
}
