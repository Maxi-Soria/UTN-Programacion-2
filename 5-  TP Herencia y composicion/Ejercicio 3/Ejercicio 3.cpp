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


class Denominacion{
private:
    char _nombCient[30];
    char _nombComun[30];
    char _nombPueblo[30];
public:
    Denominacion(){strcpy(_nombCient, "Sin Nombre");strcpy(_nombComun, "Sin Nombre");strcpy(_nombPueblo, "Sin Nombre");}

    void Cargar();
    void Mostrar();
};

void Denominacion::Cargar(){
    cout << "Nombre Cientifico: ";
    cargar_cadena(_nombCient,29);
    cout << "Nombre Comun: ";
    cargar_cadena(_nombComun,29);
    cout << "Nombre de los Pueblos: ";
    cargar_cadena(_nombPueblo,29);
}

void Denominacion::Mostrar(){
    cout << "NOMBRE CIENTIFICO: " << _nombCient << endl;
    cout << "NOMBRE COMUN: " << _nombComun << endl;
    cout << "Nombre de los Pueblos: " << _nombPueblo << endl;
}


class Dimension{
private:
    int _largo;
    int _ancho;
    int _alto;

public:
    Dimension(){_largo = 0; _ancho = 0; _alto = 0;}

    void Cargar();
    void Mostrar();
};

void Dimension::Cargar(){
    cout << "Largo: ";
    cin >> _largo;
    cout << "Ancho: ";
    cin >> _ancho;
    cout << "Alto: ";
    cin >> _alto;
}

void Dimension::Mostrar(){
    cout << "Largo: " << _largo << endl;
    cout << "Ancho: " << _ancho << endl;
    cout << "Alto: " << _alto << endl;
}


class Animal{
protected:
    Denominacion _denominacion;
    int _tiempoVida;
    Dimension _dimencion;
    float _peso;
    char _habitad[30];
    char _alimentacion[30];
    int _poblacion;

public:
    Animal(){_tiempoVida = 0;_peso = 0;strcpy(_habitad,"Sin Dato");strcpy(_alimentacion,"Sin Dato");_poblacion = 0;}

    void Cargar();
    void Mostrar();

};

void Animal::Cargar(){
    _denominacion.Cargar();
    cout << "Tiempo de vida: ";
    cin >> _tiempoVida;
    _dimencion.Cargar();
    cout << "Peso: ";
    cin >> _peso;
    cout << "Habitad: ";
    cargar_cadena(_habitad,29);
    cout << "Alimentacion: ";
    cargar_cadena(_alimentacion,29);
    cout << "Poblacion: ";
    cin >> _poblacion;

}

void Animal::Mostrar(){
    _denominacion.Mostrar();
    cout << "TIEMPO DE VIDA: " << _tiempoVida << endl;
    _dimencion.Mostrar();
    cout << "PESO: " << _peso << endl;
    cout << "HABITAD: " << _habitad << endl;
    cout << "ALIMENTACION: " << _alimentacion << endl;
    cout << "POBLACION: " << _poblacion << endl;

}


class Pez: public Animal{
private:
    char _tipoAgua[10];

public:
    Pez(){strcpy(_tipoAgua, "Sin Dato");}

    void Cargar();
    void Mostrar();
};

void Pez::Cargar(){
    Animal::Cargar();
    cout << "Tipo de Agua: ";
    cargar_cadena(_tipoAgua,29);
}

void Pez::Mostrar(){
    Animal::Mostrar();
    cout << "TIPO DE AGUA: " << _tipoAgua << endl;
}


class Anfibio: public Animal{
private:
    char _color[10];

public:
    Anfibio(){strcpy(_color, "Sin Dato");}

    void Cargar();
    void Mostrar();
};

void Anfibio::Cargar(){
    Animal::Cargar();
    cout << "Color: ";
    cargar_cadena(_color,29);
}

void Anfibio::Mostrar(){
    Animal::Mostrar();
    cout << "COLOR: " << _color << endl;
}


class Ave: public Animal{
private:
    bool _vuela;

public:
    Ave(){_vuela = false;}

    void Cargar();
    void Mostrar();
};

void Ave::Cargar(){
    Animal::Cargar();
    cout << "Vuela 1-si, 0-no: ";
    cin >> _vuela;
}

void Ave::Mostrar(){
    Animal::Mostrar();
    cout << "VUELA: " << _vuela << endl;
}


class Mamifero: public Animal{
private:
    int _cantCrias;

public:
    Mamifero(){_cantCrias = 0;}

    void Cargar();
    void Mostrar();
};

void Mamifero::Cargar(){
    Animal::Cargar();
    cout << "Cantidad de Crias: ";
    cin >> _cantCrias;
}

void Mamifero::Mostrar(){
    Animal::Mostrar();
    cout << "CANTIDAD DE CRIAS: " << _cantCrias << endl;
}




int main(){
    setlocale (LC_ALL, "Spanish");


    return 0;
}
