#include <iostream>
#include <cstdlib>

using namespace std;

void cargarCadena(char *pal, int tam) {
    int i;
    fflush(stdin);
    for(i=0; i<tam; i++) {
        pal[i]=cin.get();
        if(pal[i]=='\n') break;
    }
    pal[i]='\0';
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


class Comercio{
private:
    int _numCompra;
    Fecha _fecha;
    char _nombre[30];
    int _tipo; //entero entre 1 y 15
    int _formaPago; // 1 a 5
    float _importeTotal;

public:
    Comercio ();

    ///set
    void setNumCompra(int numCompra){_numCompra = numCompra;}
    void setFecha(Fecha fecha){_fecha = fecha;}
    void setNombre(const char* nombre){strcpy(_nombre,nombre);}
    void setTipo(int tipo){if (tipo > 0  && tipo > 16) _tipo = tipo;}
    void setFormaPago(int formaPago){if (formaPago > 0 && formaPago < 6) _formaPago = formaPago;}
    void setImporteTotal(float importeTotal){if (importeTotal > 0) _importeTotal = importeTotal;}

    ///get
    int getNumCompra(){return _numCompra;}
    Fecha getFecha(){return _fecha;}
    char* getNombre(){return _nombre;}
    int getTipo(){return _tipo;}
    int getFormaPago(){return _formaPago;}
    float getImporteTotal(){return _importeTotal;}
};

Comercio::Comercio(){
    _numCompra = 0;
    _fecha;
    strcpy(_nombre,"Sin nombre");
    _tipo = 0;
    _formaPago = 0;
    _importeTotal = 0;
}








int main(){
    setlocale (LC_ALL, "Spanish");


    return 0;
}
