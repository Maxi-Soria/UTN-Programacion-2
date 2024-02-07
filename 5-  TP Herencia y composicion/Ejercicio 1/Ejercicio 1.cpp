# include<iostream>
# include<cstdlib>
# include<cstring>

using namespace std;


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


class Persona{
private:
    int DNI;
    Fecha fechaNacimiento;///COMPOSICION: OBJETOS DE UNA CLASE COMO PROPIEDAD DE OTRA CLASE USAMOS COMPOSICIÓN
    char nombre[25];
    char apellido[25];
    char email[25];
    char telefono[20];

public:
    Persona(){
        DNI = 0;
        strcpy(nombre,"Sin Datos");
        strcpy(apellido,"Sin Datos");
        strcpy(email,"Sin Datos");
        strcpy(telefono,"Sin Datos");
    }
    int getDNI(){return DNI;}
    Fecha getFechaNacimiento(){return fechaNacimiento;}
    const char* getNombre(){return nombre;}
    const char* getApellido(){return apellido;}
    const char* getEmail(){return email;}
    const char* getTelefono(){return telefono;}

    void setDNI(const int d){DNI=d;}
    void setFechaNacimiento(Fecha f){fechaNacimiento=f;}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setApellido(const char *a){strcpy(apellido, a);}
    void setEmail(const char *e){strcpy(email,e);}
    void setTelefono(const char *t){strcpy(telefono,t);}

    void Cargar();
    void Mostrar();
};

void Persona::Cargar(){
    cout<<"Dni: ";
    cin>>DNI;
    cout<<"Fecha Nacimiento: "<<endl;
    fechaNacimiento.Cargar();
    cout<<"Nombre: ";
    cin>>nombre;
    cout<<"Apellido: ";
    cin>>apellido;
    cout<<"Email: ";
    cin>>email;
    cout<<"Telefono: ";
    cin>>telefono;
}

void Persona::Mostrar(){
    cout<<"DNI: ";
    cout<<DNI<<endl;
    cout<<"FECHA DE NACIMIENTO: ";
    fechaNacimiento.Mostrar();
    cout<<"NOMBRE: ";
    cout<<nombre<<endl;
    cout<<"APELLIDO: ";
    cout<<apellido<<endl;
    cout<<"EMAIL: ";
    cout<<email<<endl;
    cout<<"TELEFONO: ";
    cout<<telefono<<endl;

}


///PUNTO A
class Empleado: public Persona{
private:
    int _categoria;
    float _sueldo;
    Fecha _fechaDeIngreso;

public:
    Empleado(){_categoria = 0;_sueldo = 0;_fechaDeIngreso = Fecha();}

    void Cargar();
    void Mostrar();

    void setCategoria(int categoria){if(categoria>0 && categoria<6)_categoria =categoria;}
    void setSueldo(float sueldo){if(sueldo>0)_sueldo = sueldo;}
    void setFechaDeIngreso(Fecha fechaDeIngreso){_fechaDeIngreso = fechaDeIngreso;}

    int getCategoria(){return _categoria;}
    float getSueldo(){return _sueldo;}
    Fecha getFechaDeIngreso(){return _fechaDeIngreso;}


};

void Empleado::Cargar(){
    Persona::Cargar();
    cout << "Ingrese la categoria: ";
    cin >> _categoria;
    cout << "Ingrese el sueldo: ";
    cin >> _sueldo;
    cout << "Ingrese la fecha de Ingreso: " << endl;
    _fechaDeIngreso.Cargar();
}

void Empleado::Mostrar(){
        Persona::Mostrar();
        cout << "CATEGORIA: " << _categoria << endl;
        cout << "SUELDO: " << _sueldo << endl;
        cout << "FECHA DE INGRESO: ";
        _fechaDeIngreso.Mostrar();
    }


///PUNTO B
class Proveedor:public Persona{
private:
    char _cuil[20];
    int _tipoProducto;
    char _condicionPago;

public:
    Proveedor(){strcpy(_cuil,"Sin dato"); _tipoProducto = 0; _condicionPago = 'X';}

    void Cargar();
    void Mostrar();

    void setCuil(const char* cuil){strcpy(_cuil,cuil);}
    void setTipoProducto(int tipoProd){if(tipoProd > 0 && tipoProd < 11)_tipoProducto = tipoProd;}
    void setCondicionPago(char condP){if(condP == 'a' || condP == 'b'||condP == 'c')_condicionPago = condP;}

    const char* getCuil(){return _cuil;}
    int getTipoProducto(){return _tipoProducto;}
    char getCondicionPago(){return _condicionPago;}
};

void Proveedor::Cargar(){
    Persona::Cargar();
    cout << "Ingrese el cuil: ";
    cin >> _cuil;
    cout << "Ingrese el tipo de producto: ";
    cin >> _tipoProducto;
    cout << "Ingrese la condicion de pago: ";
    cin >> _condicionPago;
}

void Proveedor::Mostrar(){
        Persona::Mostrar();
        cout << "CUIL: " << _cuil << endl;
        cout << "TIPO DE PRODUCTO: " << _tipoProducto << endl;
        cout << "CONDICION DE PAGO: " << _condicionPago << endl;

    }


///PUNTO C

class Docente:public Persona{
private:
    int _legajo;
    char _cargo[15];
    Fecha _fechaDeIngreso;

public:
    Docente(){_legajo = 0; strcpy(_cargo,"Sin Dato");}

    void Cargar();
    void Mostrar();

    void setLegajo(int legajo){_legajo = legajo;}
    void setCargo(const char* cargo){strcpy(_cargo,cargo);}
    void setFechaDeIngreso(Fecha fechaDeIngreso){_fechaDeIngreso = fechaDeIngreso;}

    int getLegajo(){return _legajo;}
    const char* getCargo(){return _cargo;}
    Fecha getFechaDeIngreso(){return _fechaDeIngreso;}

};

void Docente::Cargar(){
    Persona::Cargar();
    cout << "Ingrese el legajo: ";
    cin >> _legajo;
    cout << "Ingrese el cargo: ";
    cin >> _cargo;
    cout << "Fecha de ingreso: ";
    _fechaDeIngreso.Cargar();
}

void Docente::Mostrar(){
    Persona::Mostrar();
    cout << "LEGAJO: " << _legajo << endl;
    cout << "CARGO: " << _cargo << endl;
    cout << "FECHA DE INGRESO: ";
    _fechaDeIngreso.Mostrar();
}






int main(){

    Docente obj;
    obj.Cargar();


	system("pause");
	return 0;
}
