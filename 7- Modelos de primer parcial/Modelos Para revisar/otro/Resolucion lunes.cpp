#include <iostream>
#include <cstring>

using namespace std;

class JefeDeArea2020{
    private:
        int dni;
        char nombre[30];
        char apellido[30];
    public:
        void setDni(int d){dni=d;}
        void setNombre(const char *n){strcpy(nombre, n);}
        void setApellido(const char *a){strcpy(apellido,a);}
        bool grabarEnDisco(){
            FILE *p=fopen("jefesarea2020.dat", "ab");
            if(p==NULL) return false;
            bool escribio=fwrite(this, sizeof *this, 1, p);
            fclose(p);
            return escribio;
        }
};

void punto1();
bool firmo2020(int d);
void punto2();
int buscarMaximo(int *v, int tam);

int main(){
    punto1();
    punto2();
    return 0;
}

///Generar un archivo con los Jefes de Área que hayan firmado contrato en el 2020 con el siguiente formato de registro:
///DNI, nombre y apellido.

void punto1(){
    int Empleado;
    Empleado reg;
    JefeDeArea2020 aux;
    int pos=0;
    while(reg.leerDeDisco(pos++)){
        if(reg.getCargo()==3){
            if(firmo2020(reg.getDni())){
                aux.setDni(reg.getDni());
                aux.setNombre(reg.getNombre());
                aux.setApellido(reg.getApellido());
                aux.grabarEnDisco();
            }
        }
    }
}

bool firmo2020(int d){
    Contrato reg;
    int pos=0;
    while(reg.leerDeDisco(pos++)){
        if(reg.getDni()==d && reg.getFechaContrato().getAnio() == 2020){
            return true;
        }
    }
    return false;
}

///Listar el mes con más contratos temporarios del año 2015.

void punto2(){
    Contrato reg;
    int pos=0, vMes[12]={};
    while(reg.leerDeDisco(pos++)){
        if(reg.getFechaContrato().getAnio()==2015 && reg.getTipoContrato()==1){
            vMes[reg.getFechaContrato().getMes()-1]++;
        }
    }
    cout<<"EL MES CON MAS CONTRATOS TEMPORARIOS DEL 2015 FUE: "<<buscarMaximo(vMes,12)+1;
}

int buscarMaximo(int *v, int tam){
    int posMax=0;
    for(int i=1; i<tam; i++){
        if(v[i]>v[posMax]){
            posMax=i;
        }
    }
    return posMax;
}
