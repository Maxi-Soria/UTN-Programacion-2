#include <iostream>
#include <cstdlib>

using namespace std;

/*

*/
void punto_A(float mat[][12]);

int main(){
    setlocale (LC_ALL, "Spanish");

    int dia, mes;
    float importe;
    char cod_vend;

    float mat_vend_mes[5][12] = {};

    cout << "Ingrese el dia: ";
    cin >> dia;

    while (dia != 0){
    cout << "Ingrese el dia: ";
    cin >> mes;
    cout << "Ingrese el importe: ";
    cin >> importe;
    cout << "Ingrese el codigo de venedor: ";
    cin >> cod_vend;

    mat_vend_mes[cod_vend-97][mes-1]+=importe;


    cout << endl;
    cout << "Ingrese el dia: ";
    cin >> dia;

    }
    cout << endl;
    punto_A(mat_vend_mes);





    return 0;
}

void punto_A(float mat[][12]){

    for (int i=0 ; i<5 ; i++ ){
        char letra = i+97;
        cout << "Vendedor " << letra << endl;
        for (int j=0 ; j<12 ; j++ ){
            if (mat[i][j] > 0){
                cout << "Mes " << j+1 << " monto: $" << mat[i][j] << endl;
            }
        }
        cout << endl;
    }

}
