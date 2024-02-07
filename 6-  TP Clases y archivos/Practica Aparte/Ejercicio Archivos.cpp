#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class Empresa{
private:
    int _numEmpresa;
    char _nombre[30];
    int _cantEmpleados;
    int _categoria;
    int _numMunicipio;
    bool _estado;

public:
    Empresa();

    void Cargar();
    void Mostrar();

    int getMunicipio(){return _numMunicipio;}
    int getCantidadEmpleados(){return _cantEmpleados;}
    char* getNombre(){return _nombre ;}

};

Empresa::Empresa(){
    _numEmpresa = 0;
    strcpy(_nombre,"Sin Dato");
    _cantEmpleados = 0;
    _categoria = 0;
    _numMunicipio = 0;
    _estado = false;

}

void Empresa::Cargar(){
    cout << "Numero de Empresa: ";
    cin >> _numEmpresa;
    cout << "Nombre de la Empresa: ";
    cin >> _nombre;
    cout << "Cantida de Empleados: ";
    cin >> _cantEmpleados;
    cout << "Categoria: ";
    cin >> _categoria;
    cout << "Numero de municipio: ";
    cin >> _numMunicipio;

    _estado = true;
}

void Empresa::Mostrar(){
    cout << "NUMERO DE EMPRESA: " << _numEmpresa << endl;
    cout << "NOMBRE DE LA EMPRESA: " << _nombre << endl;
    cout << "CANTIDAD DE EMPLEADOS: " << _cantEmpleados << endl;
    cout << "CATEGORIA: " << _categoria << endl;
    cout << "NUMERO DE MUNICIPIO: " <<  _numMunicipio << endl;

}


bool cargarUnArchivo(){
    Empresa reg;
    int escribio;

    FILE *pEmpresa;

    pEmpresa = fopen("empresas.dat", "wb");
    if(pEmpresa == NULL){
        return false;
    }
    for (int i=0 ; i<3 ; i++ ){
        reg.Cargar();
        cout << endl;
        escribio = fwrite(&reg, sizeof (Empresa), 1, pEmpresa);
        if(escribio == 0){
            fclose(pEmpresa);
            return 0;
        }
    }
    fclose(pEmpresa);
    return true;

}

bool mostrarArchivo(){
    Empresa reg;

    FILE* pEmpresa;
    pEmpresa = fopen("empresas.dat", "rb");
    if(pEmpresa == 0){
        return false;
    }

    while ((fread(&reg,sizeof (Empresa),1,pEmpresa)) == 1){
        reg.Mostrar();
        cout << endl;

    }

    fclose(pEmpresa);
    return true;
}

bool cargarTresRegistros(){
    Empresa vReg[3];
    int escribio;
    FILE* pEmp;

    pEmp = fopen("empresas.dat","ab");

    if(pEmp == NULL){
        return false;
    }

    for (int i=0 ; i<3 ; i++ ){
        vReg[i].Cargar();
        cout << endl;
    }

        escribio = fwrite(vReg, sizeof (Empresa), 3, pEmp);

        fclose(pEmp);
        return escribio;
}

void puntoA(){
    Empresa reg;
    int vecMuni[10] = {};

    FILE* pEmpresa;
    pEmpresa = fopen("empresas.dat", "rb");
    if(pEmpresa == 0){
        cout << "ERROR" << endl;
    }

    while ((fread(&reg,sizeof (Empresa),1,pEmpresa)) == 1){
        vecMuni[reg.getMunicipio()-1]++;
    }
    cout << "La cantidad de empresas" << endl;
    for (int i=0 ; i<10; i++ ){
        cout << "Municipio " << i+1 << " es " << vecMuni[i] << endl;
    }

    fclose(pEmpresa);


}

void puntoB(){
    Empresa reg;
    //int vecMuni[10] = {};

    FILE* pEmpresa;
    pEmpresa = fopen("empresas.dat", "rb");
    if(pEmpresa == 0){
        cout << "ERROR" << endl;
    }

    cout << "las empresas con mas de 10 empleados son: " << endl;
    while ((fread(&reg,sizeof (Empresa),1,pEmpresa)) == 1){
        if(reg.getCantidadEmpleados() > 10){
            cout << reg.getNombre() << endl;
        }

    }


    fclose(pEmpresa);


}

int main(){
    setlocale (LC_ALL, "Spanish");

    int opc;
    while (true){
        system("cls");
        cout << "MENU" << endl;
        cout << "1. CARGAR EMPRESAS DE A UN REGISTRO" << endl;
        cout << "2. CARGAR LAS 5 EMPRRESAS EN UN VECTOR" << endl;
        cout << "3. MOSTRAR EMPRESAS CARGADAS" << endl;
        cout << "4. MOSTRAR PUNTO A" << endl;
        cout << "5. MOSTRAR PUNTO B" << endl;
        cout << "0. SALIR DEL PROGRAMA" << endl;
        cout << "SELECCIONE UNA OPCION: " << endl;
        cin >> opc;
        switch (opc){
        case 1:
            cargarUnArchivo();
            break;
        case 2:
            cargarTresRegistros();
            break;
        case 3:
            mostrarArchivo();
            break;
        case 4:
            puntoA();
            break;
        case 5:
            puntoB();
            break;

        case 0:
            return 0;
            break;
        }
        system("pause");
        system("cls");
    }
    cout << endl;

    return 0;
}






