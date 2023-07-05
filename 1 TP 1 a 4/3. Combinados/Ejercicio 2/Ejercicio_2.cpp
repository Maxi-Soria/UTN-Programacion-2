#include <iostream>
#include <cstdlib>

using namespace std;

/*

*/

void punto_A(float mat[][31]);
void punto_B(float mat[12][31]);

int main(){
    setlocale (LC_ALL, "Spanish");

    int mes, dia;
    float importe;

    float mat_mes_dia[12][31] = {};



    cout << "Ingrese el mes: ";
    cin >> mes;

    while (mes != 0){
    cout << "Ingrese el dia: ";
    cin >> dia;
    cout << "Ingrese el Importe: ";
    cin >> importe;


    mat_mes_dia[mes-1][dia-1] += importe;


    cout << endl;
    cout << "Ingrese el mes: ";
    cin >> mes;
    }
    cout << endl;
    punto_A(mat_mes_dia);
    cout << endl;
    punto_B(mat_mes_dia);

    return 0;
}


void punto_A(float mat[][31]){
    int acum = 0;
    cout << "Gasto total de cada mes: " << endl;
    for (int i=0 ; i<12 ; i++ ){
        acum = 0;
        cout << "Mes " << i+1;
        for (int j=0 ; j<31 ; j++ ){
            acum += mat[i][j];
        }
        cout << " gasto total: $" << acum << endl;
    }



}


void punto_B(float mat[][31]){


    cout << "El dia, de mayor gasto de cada mes fue: " << endl;
    for (int i=0 ; i<12 ; i++ ){
        float mayor_gasto = 0;
        int dia_mayor_gasto = 0;
        cout << "Mes " << i+1;
        for (int j=0 ; j<31 ; j++ ){
            if (mat[i][j] > mayor_gasto){
                mayor_gasto = mat[i][j];
                dia_mayor_gasto = j;
            }
        }
        cout << " Dia " << dia_mayor_gasto+1 << " Monto $" << mayor_gasto << endl;
    }
}
