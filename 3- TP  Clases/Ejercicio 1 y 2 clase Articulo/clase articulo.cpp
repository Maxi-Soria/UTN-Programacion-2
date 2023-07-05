#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

void cargar_cadena(char *palabra, int tam){
    int i = 0;
    fflush(stdin);
    for (i = 0 ; i < tam ; i++ ){
        palabra[i] = cin.get();
        if(palabra[i] == '\n') break;
    }
    palabra[i] = '\0';
    fflush(stdin);
}

class Articulo{
private:
    char _codigo[5];
    char _descripcion[31];
    float _precio;
    int _stock;
    bool _estado;
public:
    void Cargar();
    void Mostrar();

    ///CONSTRUCTOR

    Articulo(){
        strcpy(_codigo,"null");
        strcpy(_descripcion,"null");
        _precio = 0;
        _stock = 0;
        _estado = false;
    }

    Articulo(const char* codigo,const char* descripcion, float precio, int stock, bool estado){
        strcpy(_codigo,codigo);
        strcpy(_descripcion,descripcion);
        _precio = precio;
        _stock = stock;
        _estado = estado;
    }

    char* getCodigo(){return _codigo;}
    char* getDescripcion(){return _descripcion;}
    float getPrecio(){return _precio;}
    int  getStock(){return _stock;}
    bool getEstado(){return _estado;}

    void setCodigo(const char* codigo){strcpy(_codigo, codigo);}
    void setDescripcion(const char* descripcion){strcpy(_descripcion, descripcion);}
    void setPrecio(const float precio){_precio = precio;}
    void setStock(const int stock){_stock = stock;}
    void setEstado(bool estado){_estado = estado;}
};

void Articulo::Cargar(){
    cout << "Ingrese el codigo: ";
    cin >> _codigo;
    //cargar_cadena(_codigo,5);
    cout << "Ingrese la descripcion: ";
    cargar_cadena(_descripcion,30);
    cout << "Ingrese el precio: ";
    cin >> _precio;
    cout << "Ingrese el stock: ";
    cin >> _stock;
    cout << "Ingrese el estado: ";
    cin >> _estado;
    cout << endl;
}

void Articulo::Mostrar(){
    cout << "EL CODIGO ES: " << _codigo << endl;
    cout << "LA DESCRIPCION ES: " << _descripcion << endl;
    cout << "EL PRECIO ES: " << _precio << endl;
    cout << "EL STOCK ES: " << _stock << endl;
    cout << "EL ESTADO ES: " << _estado << endl;
    cout << endl;

}

char menu(){

    char opcion;
    cout << "MENU " << endl;
    cout << "a) Cargar un vector de 10 artículos" << endl;
    cout << "b) Listar todos los artículos del vector." << endl;
    cout << "c) Listar todos los artículos cuyo precio sea mayor a un valor que se ingresa por teclado." << endl;
    cout << "d) A partir de un valor de código recibido como parámetro, devolver la posición del objeto que contiene ese código." << endl;
    cout << "   De no encontrarlo devolver -1." << endl;
    cout << "e) Igual a la función del punto anterior, pero debe devolver el objeto completo que contiene el código." << endl;
    cout << "   De no encontrar el código la función debe devolver un objeto Articulo con un valor de -1 en el stock." << endl;
    cout << "f) Dado un valor de stock que se recibe como parámetro devolver la cantidad de artículos cuyo stock sea" << endl;
    cout << "   inferior a ese valor recibido." << endl;
    cout << "g) Dado un porcentaje de incremento que se recibe como parámetro, modificar el precio unitario de todos los objetos." << endl;
    cout << "s) SALIR" << endl;
    cout << "SELECCIONE UNA LETRA _";
    cin >> opcion;

    return opcion;

}

void puntoA(Articulo* vec, int tam){
    for (int i=0 ; i<tam ; i++ ){
        vec[i].Cargar();
    }

}

void puntoB(Articulo* vec, int tam){
    for (int i=0 ; i<tam ; i++ ){
        vec[i].Mostrar();
    }
}


void puntoC(Articulo* vec, int tam){
    float precio;
    cout << "Ingrese el precio: ";
    cin >> precio;

    for (int i=0 ; i<tam ; i++ ){
        if(vec[i].getPrecio() > precio){
            vec[i].Mostrar();
            cout << endl;
        }
    }
}

int buscarCodigo(Articulo* vec, int tam, char* cod){

    for (int i=0 ; i<tam ; i++ ){
        if(strcmp(vec[i].getCodigo(),cod) == 0){
            return i;
        }
    }
    return -1;

}

void puntoD(Articulo* vec, int tam){
    int pos;
    char cod[6];
    cout << "Ingrese un codigo: ";
    cargar_cadena(cod,5);


    pos = buscarCodigo(vec,tam,cod);
    if (pos == -1){
        cout << "No existe el codigo " << endl;
    }
    else{
        cout << "El codigo esta en la posicion " << pos << endl;
    }
}


Articulo buscarPuntoE(Articulo* vec, int tam, char* cod){
    Articulo aux;
    for (int i=0 ; i<tam ; i++ ){
        if(strcmp(vec[i].getCodigo(), cod)== 0){
            return vec[i];
        }
    }
    aux.setStock(-1);
    return aux;

}

void puntoE(Articulo* vec, int tam){
    Articulo aux;
    char cod[6];
    cout << "Ingrese un codigo: ";
    cargar_cadena(cod,5);
    aux = buscarPuntoE(vec, tam, cod);
    if(aux.getStock() == -1){
        cout << "Error " << endl;
    }
    else{
        aux.Mostrar();
    }

}

int contStock(Articulo* vec, int tam, int stock){
    int cont = 0;
    for (int i=0 ; i<tam ; i++ ){
        if(vec[i].getStock() < stock){
            cont++;
        }
    }
  return cont;
}

void puntoF(Articulo* vec, int tam){
    int stock;

    cout << "Ingrese el stock ";
    cin >> stock;

    cout << "El resultado es: " << contStock(vec, tam,stock) << endl;

}

void aumentarPorc(Articulo* vec, int tam, float porc){
    float precio;
    for (int i=0 ; i<tam ; i++ ){
        precio = vec[i].getPrecio();
        precio = precio + precio*porc/100;
        vec[i].setPrecio(precio);
    }

}

void puntoG(Articulo* vec, int tam){
    float porcAumento;
    cout << "Ingrese el porcentaje de aumento: ";
    cin >> porcAumento;
    aumentarPorc(vec,tam,porcAumento);
}


int main(){
    setlocale (LC_ALL, "Spanish");

    const int TAM = 4;

    ///
    Articulo obj[TAM] = {
    Articulo("A1000", "Primera Carga", 1000, 10, false),
    Articulo("A2000", "Segunda Carga", 2000, 20, true),
    Articulo("A3000", "Tercera Carga", 3000, 30, false),
    Articulo("A4000", "Cuarta Carga", 4000, 40, true)
    };

    char opcion;

        do{
        system("cls");
        opcion = menu();

        switch (opcion){
        case 'a':
                system("cls");
                puntoA(obj,TAM);
                system("pause");
            break;
        case 'b':
                system("cls");
                puntoB(obj,TAM);
                system("pause");
            break;
        case 'c':
                system("cls");
                puntoC(obj,TAM);
                system("pause");
            break;
        case 'd':
                system("cls");

                puntoD(obj,TAM);
                system("pause");
            break;
        case 'e':
                system("cls");
                puntoE(obj,TAM);
                system("pause");
            break;
        case 'f':
                system("cls");
                puntoF(obj,TAM);
                system("pause");
            break;
        case 'g':
                system("cls");
                puntoG(obj,TAM);
                system("pause");
            break;
        case 's':
                system("cls");
                cout << "Hasta pronto!!" << endl;
            break;
        }

    } while (opcion != 's');




    return 0;
}
/*
A1000
Primera Carga
1000
10
0
A2000
Segunda Carga
2000
20
1
A3000
Tercera Carga
3000
30
0
A4000
Tercera carga
4000
40
1
*/
