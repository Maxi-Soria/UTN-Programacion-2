/**

*/



#include <iostream>
#include <cstdlib>

using namespace std;
#include "clases.h"

class JefeArea{
    private:
        int DNI;
        char nombre[30];
        char apellido [30];
    public:
        bool leyo;
        void setDNI (int d){DNI=d;}
        void setNombre (const char *n){strcpy (nombre,n);}
        void setApellido (const char *n){strcpy (apellido,n);}
        bool grabarDeDisco (){
            FILE *p;
            p=fopen("jefes2020.dat", "ab");
            if (p==NULL) return false;
            fwrite(this, sizeof (JefeArea),1,p);
            fclose(p);
            return leyo;
        }

};
void puntoA();
    bool buscarContrato(int dni);{
    }
void puntoB();

int main(){
    puntoA();
    puntoB();


cout<<endl;
system ("pause");
return 0;
}

void puntoA(){
    Empleado reg;
    JefeArea aux;
    int pos=0;
    while (reg.leerDeDisco(pos)==true){
        if(reg.getCargo()==3){
            firmo=buscarContrato(reg.getDNI());
            if(firmo==true){
                aux.setNombre(reg.GetNombre());
                aux.setApellido(reg.getApellido());
                aux.setDNI(reg.getDNI()):
                aux.grabarEnDisco();
            }
        }
        pos++;
    }

}
bool buscarContrato(int dni){
    Contrato reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==true){
        if (reg.getDNI()==dni && reg.getfechaContrato().getAnio()==2020)
            return true;
        pos++;
    }
    return false;
}

void puntoB(){
    Contrato reg;
    int vContratos[12]={};
    int pos=0;
    while(reg.leerDeDisco(pos)==true){
        if (reg.getTipoContrato()==1 && reg.getfechaContrato().getAnio()==2015){
            vContratos[reg.getFechaContato().getMes()-1]++;
        }
        pos++;
    }
    int posMax=buscarMaximo(vContratos, 12);
    cout <<"EL MESCON MAS CONTRATOS TEMPORARIOS EN 2015 FUE: "<<posMax+1<<endl;
}
