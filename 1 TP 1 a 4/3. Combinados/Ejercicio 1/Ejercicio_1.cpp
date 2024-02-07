#include <iostream>
#include <cstdlib>

using namespace std;

/*

*/
void punto_A(int matriz[][3]);
void punto_B(int matriz[][3]);


int main(){
    setlocale (LC_ALL, "Spanish");

    int num_articulo, num_sucursal, cantidad_vend;

    //Punto A y B
    int articulo_por_suc[5][3] = {};





    cout << "Ingrese el numero de Articulo: ";
    cin >> num_articulo;

    while (num_articulo != 0){
        cout << "Ingrese el numero de Sucursal: ";
        cin >> num_sucursal;
        cout << "Ingrese la Cantidad vendida: ";
        cin >> cantidad_vend;

        //Punto A
        articulo_por_suc[num_articulo-1][num_sucursal-1]++;


        cout << endl;
        cout << "Ingrese el numero de Articulo: ";
        cin >> num_articulo;
    }

    punto_A(articulo_por_suc);

    punto_B(articulo_por_suc);



    return 0;
}

void punto_A(int matriz[][3]){
    cout << endl << "             SUCURSAL 1      SUCURSAL 2      SUCURSAL 3" << endl;
    for(int x= 0; x < 5; x++){
        cout << "-----------------------------------------------------" << endl;
        cout << "ARTICULO " << x+1  ;
        for (int j = 0; j < 3; j++){
            cout << "      " << matriz[x][j] << "          " ;
        }
    cout << endl;
    }
    cout << "-----------------------------------------------------" << endl;

}

void punto_B(int matriz[][3]){
    cout << endl << endl;;
    for(int x= 0; x < 3; x++){
        int mas_ventas = 0;
        int max_suc = 0;
        cout << "El numero de articulo mas vendido de la sucursal " << x+1 << " fue: ";
        for (int j = 0; j < 5; j++){
            if(matriz[j][x] > mas_ventas){
                mas_ventas = matriz[j][x];
                max_suc = j+1;
            }
        }
        cout << max_suc << endl;
    }
}


/*
int main()
{
    int numArticulo, numSucursal, cantVendida;
    int matriz[5][3] = {};

    do
    {
        cout << "Numero de articulo: ";
        cin >> numArticulo;
        if (numArticulo != 0)
        {
            cout << "Numero de sucursal: ";
            cin >> numSucursal;
            cout << "Cantidad vendida: ";
            cin >> cantVendida;
            matriz[numArticulo-1][numSucursal-1] += cantVendida;


        }
    }
    while (numArticulo != 0);




    cout << endl << endl;;
    for(int x= 0; x < 3; x++){
        int mas_ventas = 0;
        int max_suc = 0;
        cout << "El numero de articulo mas vendido de la sucursal " << x+1 << " fue: ";
        for (int j = 0; j < 5; j++){
            if(matriz[j][x] > mas_ventas){
                mas_ventas = matriz[j][x];
                max_suc = j+1;
            }
        }
        cout << max_suc << endl;
    }



    return 0;
}*/
