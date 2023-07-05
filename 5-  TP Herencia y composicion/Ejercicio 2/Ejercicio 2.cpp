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

class Fecha{
    private:///todo lo que se defina acá sólo va a ser accesible dentro de la clase
        int dia, mes, anio;
    public:
        Fecha(int d=0, int m=0, int a=1600){
            dia=d;
            mes=m;
            anio=a;
        }
        void Cargar();
        void Mostrar();
        ///sets
        void setDia(int x){if(x>0 && x<32) dia=x;}
        void setMes(int x){if(x>0 && x<13)mes=x;}
        void setAnio(int x){anio=x;}
        ///gets
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}
};

void Fecha::Cargar(){///método o función de la clase
    cout<<"DIA: ";
    cin>>dia;
    cout<<"MES: ";
    cin>>mes;
    cout<<"ANIO: ";
    cin>>anio;
}

void Fecha::Mostrar(){///método o función de la clase

    cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
}


///DIRECCION (CLASE PRINCIPAL)
class Direccion{
private:
    char _calle[30];
    int _numero;
    int _codPostal;
    char _localidad[30];
    int _piso;

public:
    Direccion(){
        strcpy(_calle,"Sin Dato");
        _numero = 0;
        _codPostal = 0;
        strcpy(_localidad,"Sin Dato");
        _piso = 0;
    }

    void Cargar();
    void Mostrar();


};

void Direccion::Cargar(){
    cout << "Calle: ";
    cargar_cadena(_calle,29);
    cout << "Numero:";
    cin >> _numero;
    cout << "Codigo Postal: ";
    cin >> _codPostal;
    cout << "Localidad: ";
    cargar_cadena(_localidad,29);
}

void Direccion::Mostrar(){
    cout << "CALLE: " << _calle << endl;
    cout << "NUMERO: " << _numero << endl;
    cout << "CODIGO POSTAL: " << _codPostal << endl;
    cout << "LOCALIDAD: " << _localidad << endl;
}


///INMUEBLE
class Inmueble{
    protected:
        Direccion _direccion;
        Fecha _fechaIngreso;
        Fecha _fechaOperacion;
        float _supTotal;
        int _tipo;

    public:
        Inmueble(){_supTotal = 0;_tipo = 0;}

        void Cargar();
        void Mostrar();

};

void Inmueble::Cargar(){
    cout << "Direccion " << endl;
    _direccion.Cargar();
    cout << "Fecha de Ingreso: " << endl;;
    _fechaIngreso.Cargar();
    cout << "Fecha de Operacion: " << endl;
    _fechaOperacion.Cargar();
    cout << "Superficie Total: ";
    cin >> _supTotal;
    cout << "Tipo: ";
    cin >> _tipo;
}

void Inmueble::Mostrar(){
    cout << "DIRECCION " << endl;
    _direccion.Mostrar();
    cout << "FECHA DE INGRESO: ";
    _fechaIngreso.Mostrar();
    cout << "FECHA DE OPERCION: ";
    _fechaOperacion.Mostrar();
    cout << "SUPERFICIE TOTAL: " << _supTotal << endl;
    cout << "TIPO: " << _tipo << endl;
}


///CASA
class Casa:public Inmueble{
    private:
        int _cantAmbientes;
        float _supConstruida;
    public:
        Casa(){_cantAmbientes = 0;_supConstruida = 0;}

        void Cargar();
        void Mostrar();

};

void Casa::Cargar(){
    Inmueble::Cargar();
    cout << "Cantidad de Ambientes: ";
    cin >> _cantAmbientes;
    cout << "Superficie Construida: ";
    cin >> _supConstruida;
}

void Casa::Mostrar(){
    Inmueble::Mostrar();
    cout << "AMBIENTES: " << _cantAmbientes << endl;
    cout << "SUPERFICIE CONSTRUIDA: " << _supConstruida << endl;
}


///DEPARTAMENTO
class Departamento :public Inmueble{
    private:
        int _cantAmbientes;
        bool _instalacionesComp;

    public:
        Departamento(){_cantAmbientes = 0;_instalacionesComp = false;}

        void Cargar();
        void Mostrar();

};

void Departamento::Cargar(){
    Inmueble::Cargar();
    cout << "Cantidad de Ambientes: ";
    cin >> _cantAmbientes;
    cout << "Dispone de istalaciones compelementarias: ";
    cin >> _instalacionesComp;
}

void Departamento::Mostrar(){
    Inmueble::Mostrar();
    cout << "AMBIENTES: " << _cantAmbientes << endl;
    cout << "INSTALACIONES COMPLEMENTARIAS: " << _instalacionesComp << endl;
}


///LOCAL
class Local :public Inmueble{
    private:
        int _zona;
        char _mejoras;

    public:
        Local(){_zona = 0;_mejoras = 'A';}

        void Cargar();
        void Mostrar();

};

void Local::Cargar(){
    Inmueble::Cargar();
    cout << "Zona 1-Comercial 2-Mixta 3-Industrial: ";
    cin >> _zona;
    cout << "Mejoras: A-Sin mejoras B-Asfalto C-todos los servicios ";
    cin >> _mejoras;
}

void Local::Mostrar(){
    Inmueble::Mostrar();
    cout << "ZONA: " << _zona << endl;
    cout << "MEJORAS: " << _mejoras << endl;
}



int main(){


return 0;
}
