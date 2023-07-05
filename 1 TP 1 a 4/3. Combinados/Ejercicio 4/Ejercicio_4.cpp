#include <iostream>
#include <cstdlib>

using namespace std;

/*

*/

int engranajesMasProducido(int mat[][15]);
int  maquina_menos_produjo (int mat[][15]);
void punto_C(int mat[][15]);

int main(){
    setlocale (LC_ALL, "Spanish");

    int dia, tipo_eng, num_maq, cant_prod;

    int const ENGRANAJES = 20, MAQUINAS = 15;

    int mat_engranaje_maquina[ENGRANAJES][MAQUINAS] = {};



    cout << "Ingrese el dia: ";
    cin >> dia;

    while (dia != 32){
    cout << "Ingrese el tipo de engranaje: ";
    cin >> tipo_eng;
    cout << "Ingrese el numero de maquina: ";
    cin >> num_maq;
    cout << "Ingrese la cantidad producida: ";
    cin >> cant_prod;

    mat_engranaje_maquina[tipo_eng-1][num_maq-1] += cant_prod;

    cout << endl;
    cout << "Ingrese el dia: ";
    cin >> dia;

    }

    cout << "EL engranaje mas producio es: " << engranajesMasProducido(mat_engranaje_maquina);
    cout << endl;
    cout << "La maquina que menos produjo entre las que poducieron es la maquina: " << maquina_menos_produjo(mat_engranaje_maquina);
    cout << endl;
    punto_C(mat_engranaje_maquina);



    return 0;
}

int engranajesMasProducido(int mat[][15]){
    int mayor_prod = 0;
    int engra_mas_prod = 0;

    for (int i=0 ; i<20 ; i++ ){
        int acum_prod = 0;
        for (int j=0 ; j<15 ; j++ ){
            acum_prod += mat[i][j];
        }
        if(acum_prod > mayor_prod){
            mayor_prod = acum_prod;
            engra_mas_prod = i;
        }
    }
    return engra_mas_prod+1;
}

int  maquina_menos_produjo (int mat[][15]){
    bool band_prim = false;
    int acu_prod, menor_prod, j;
    int maq_men_prod = 0;

    for (int i=0 ; i<15 ; i++ ){
        acu_prod = 0;
        for (j=0 ; j<20 ; j++ ){
            acu_prod += mat[j][i];
        }
        //cout <<">> " <<  acu_prod << endl;
        if(acu_prod > 0){
            if(!band_prim){
                menor_prod = acu_prod;
                maq_men_prod = i;
                band_prim = true;
            }
            else{
                if(acu_prod < menor_prod){
                    menor_prod = acu_prod;
                    maq_men_prod = i;
                }
            }
        }
    }
    return maq_men_prod+1;

}

void punto_C(int mat[][15]){
    cout << "Tipo de eng   N° Maquina   Cantidad prod" << endl;
    for (int i=0 ; i<20 ; i++ ){

        for (int j=0 ; j<15 ; j++ ){
            if(mat[i][j] > 0){
                cout << "   " << i+1 << "              " << j+1 << "               " << mat[i][j] << endl;
            }
        }
    }

}


