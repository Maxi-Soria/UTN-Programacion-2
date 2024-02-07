# include<iostream>
# include<cstdlib>
# include<cstring>

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


class Direccion{
private:
    char _calle[30];
    int _numero;

public:
    Direccion(){
        strcpy(_calle,"Sin Dato");
        _numero = 0;
    }

    void Cargar();
    void Mostrar();


};

void Direccion::Cargar(){
    cout << "Calle: ";
    cargarCadena(_calle,29);
    cout << "Numero:";
    cin >> _numero;
}

void Direccion::Mostrar(){
    cout << "CALLE: " << _calle << " N°" << _numero << endl;
}




class Persona{
private:
    int DNI;
    char nombre[25];
    char apellido[25];
    Direccion _direccion;
    Fecha fechaNacimiento;///COMPOSICION: OBJETOS DE UNA CLASE COMO PROPIEDAD DE OTRA CLASE USAMOS COMPOSICIÓN
    char email[25];


public:
    Persona(){
        DNI = 0;
        strcpy(nombre,"Sin Datos");
        strcpy(apellido,"Sin Datos");
        strcpy(email,"Sin Datos");
    }
    int getDNI(){return DNI;}
    Fecha getFechaNacimiento(){return fechaNacimiento;}
    const char* getNombre(){return nombre;}
    const char* getApellido(){return apellido;}
    const char* getEmail(){return email;}

    void setDNI(const int d){DNI=d;}
    void setFechaNacimiento(Fecha f){fechaNacimiento=f;}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setApellido(const char *a){strcpy(apellido, a);}
    void setEmail(const char *e){strcpy(email,e);}


    void Cargar();
    void Mostrar();
};

void Persona::Cargar(){
    cout<<"Dni: ";
    cin>>DNI;
    cout<<"Nombre: ";
    cin>>nombre;
    cout<<"Apellido: ";
    cin>>apellido;
    cout << "Direccion" << endl;
    _direccion.Cargar();
    cout<<"Email: ";
    cin>>email;
    cout<<"Fecha Nacimiento: "<<endl;
    fechaNacimiento.Cargar();
}

void Persona::Mostrar(){
    cout<<"DNI: " << DNI<<endl;
    cout<<"NOMBRE Y APELLIDO: " <<nombre<<" "<<apellido<<endl;
    cout << "DOMICILIO: ";
    _direccion.Mostrar();
    cout<<"EMAIL: " << email<<endl;
    cout<<"FECHA DE NACIMIENTO: ";
    fechaNacimiento.Mostrar();


}



class Empleado: public Persona{
private:
    int _cargo;


public:
    Empleado(){_cargo = 0;}

    void Cargar();
    void Mostrar();

    void setCargo(int cargo){if(cargo>0 && cargo<11)_cargo =cargo;}

    int getCargo(){return _cargo;}



};

void Empleado::Cargar(){
    Persona::Cargar();
    cout << "Ingrese el Cargo: ";
    cin >> _cargo;
}

void Empleado::Mostrar(){
        Persona::Mostrar();
        cout << "CARGO: " << _cargo << endl;
    }


class ArchivoEmpleado{
private:
    char _nombre[30];
public:
    ArchivoEmpleado(const char* nombre){strcpy(_nombre,nombre);}
    bool agregarRegistro();
    void listarRegistros();
    Empleado buscarPorDni(int dni);
};

bool ArchivoEmpleado::agregarRegistro(){
    Empleado obj;
    FILE* pEmp;

    pEmp = fopen(_nombre,"ab");
    if(pEmp == NULL){
        return false;
    }
    obj.Cargar();
    fwrite(&obj,sizeof obj, 1,pEmp);
    fclose(pEmp);
    return true;
}

void ArchivoEmpleado::listarRegistros(){
    Empleado obj;
    FILE *pEmp;

	pEmp=fopen(_nombre,"rb");
	if(pEmp==NULL){
		cout << "ERROR" << endl;
	}
	else{
        while(fread(&obj, sizeof (Empleado), 1,pEmp) ==1){
            obj.Mostrar();
            cout<<endl;
        }
    }

    fclose(pEmp);

}

Empleado ArchivoEmpleado::buscarPorDni(int dni){
    Empleado obj;
    FILE *pEmp;

    obj.setDNI(-1),

	pEmp=fopen(_nombre,"rb");
	if(pEmp==NULL){
		return obj;
	}
    while(fread(&obj, sizeof (Empleado), 1,pEmp) ==1){
        if(obj.getDNI() == dni){
            fclose(pEmp);
            return obj;
        }
    }

    fclose(pEmp);
    obj.setDNI(-1);
    return obj;

}


int cargarDNI(){
    int d;
    cout << "Ingrese el dni a buscar: ";
    cin >> d;
    return d;
}

int main(){
    setlocale (LC_ALL, "Spanish");

    int opc;
    ArchivoEmpleado obj("Empleados.dat");
    Empleado aux;

    do{
        system("cls");
        cout << "           MENU" << endl;
        cout << "1- Cargar Archivos Empleado" << endl;
        cout << "2- Mostrar Archivos Empleado" << endl;
        cout << "3- Mostrar por DNI " << endl;
        cout << "0- SALIR" << endl;

        cin >> opc;
        switch (opc){
        case 1:
            if(!obj.agregarRegistro()){cout << "NO SE PUDO CREAR O AGREGAR EL REGISTRO" << endl;}
            else{cout << "REGISTRO AGREGADO!!!" << endl;}
            system("pause");
            break;
        case 2:
            obj.listarRegistros();
            system("pause");
            break;
        case 3:

            aux = obj.buscarPorDni(cargarDNI());
            if(aux.getDNI() == -1) cout << "NO SE ENCUENTRA EL DNI" << endl;
            else{
                aux.Mostrar();
            }
            system("pause");
            break;

        case 0:
            cout << "SALIR " << endl;
        default:
            break;
        }
    } while (opc != 0);

	return 0;
}


/*
12345678
Ana
Perez
Mayor
1
ana.perez@gmail.com
01
01
1990
3

23456789
Juan
Gomez
Gran Vía
10
juan.gomez@hotmail.com
15
03
1985
5

34567890
Laura
Rodriguez
San Miguel
5
laura.rodriguez@gmail.com
22
07
1995
9

45678901
Carlos
Fernandez
Alcalá
20
carlos.fernandez@yahoo.com
03
11
1982
8

56789012
Marta
Lopez
Atocha
15
marta.lopez@hotmail.com
12
05
1992
7
*/




