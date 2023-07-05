#include <iostream>
#include <cstdlib>

using namespace std;

/*
Hacer una funci�n que reciba como par�metros una matriz de enteros de 10x10 y un n�mero entero (entre 0 y 9),
y devuelva la posici�n que ocupa el m�ximo en la fila indicada por el segundo par�metro.
*/

int pos_maximo_en_fila(int matriz[][4], int fila){
    int maximo = matriz[fila][0];
    int pos_maximo = 0, i;
    for (i=0 ; i<4 ; i++ ){
        if(matriz[fila][i] > maximo){
            maximo = matriz[fila][i];
            pos_maximo = i;
        }
    }
    return pos_maximo;
}

int main(){
    setlocale (LC_ALL, "Spanish");
    int const COL = 4;
    int const FILA = 4;

    int buscar_en_fila = 3;

    int mat[FILA][COL] = {{2,6,5,9},{9,15,-6,8},{10,12,13,11},{-9,-6,-1,-4}};

    cout << "El numero maximo de la fila " << buscar_en_fila << " esta en la posicion " << pos_maximo_en_fila(mat, buscar_en_fila);

    return 0;
}
