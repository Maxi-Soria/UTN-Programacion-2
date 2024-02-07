#ifndef CLASEID_H_INCLUDED
#define CLASEID_H_INCLUDED

class Fecha{
    private:
        int dia, mes, anio;
    public:
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}

        void setDia(int d){dia=d;}
        void setMes(int m){mes=m;}
        void setAnio(int a){anio=a;}

        void Cargar(){
            cout<<"DIA: ";
            cin>>dia;
            cout<<"MES: ";
            cin>>mes;
            cout<<"ANIO: ";
            cin>>anio;
        }
        void Mostrar(){
        cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
        }
};

class Restaurante{
    private:
        int codigoRestaurante;
        char nombre[30];
        int provincia;
        char nombreGerente[30];
        int categoriaRestaurante;
        bool estado;
    public:
        int getCodigoRestaurante(){return codigoRestaurante;}
        const char *getNombre(){return nombre;}
        int getProvincia(){return provincia;}
        const char *getNombreGerente(){return nombreGerente;}
        int getCategoriaRestaurante(){return categoriaRestaurante;}
        bool getEstado(){return estado;}

        void setCodigoRestaurante(int cR){codigoRestaurante=cR;}
        void setNombre(const char *n){strcpy(nombre,n);}
        void setProvincia(int p){provincia=p;}
        void setNombreGerente(const char *nG){strcpy(nombreGerente,nG);}
        void setCategoriaRestaurante(int cR){categoriaRestaurante=cR;}
        void setEstado(bool e){estado=e;}

        bool leerDeDisco(int pos){
            FILE *p;
            p=fopen("restaurantes.dat","rb");
            if(p==NULL) return false;
            fseek(p,pos*sizeof *this, 0);
            bool leyo=fread(this, sizeof *this, 1, p);
            fclose(p);
            return leyo;
        }
        bool grabarEnDisco(){
            FILE *p;
            p=fopen("restaurantes.dat","ab");
            if(p==NULL) return false;
            bool escribio=fwrite(this, sizeof *this, 1, p);
            fclose(p);
            return escribio;
        }
        void Cargar(){
            cout<<"CODIGO: ";
            cin>>codigoRestaurante;
            cout<<"NOMBRE: ";
            cin>>nombre;
            cout<<"PROVINCIA: ";
            cin>>provincia;
            cout<<"GERENTE: ";
            cin>>nombreGerente;
            cout<<"CATEGORIA: ";
            cin>>categoriaRestaurante;
            estado=true;
        }
        void Mostrar(){
            cout<<"CODIGO: "<<codigoRestaurante<<endl;
            cout<<"NOMBRE: "<<nombre<<endl;
            cout<<"PROVINCIA: "<<provincia<<endl;
            cout<<"GERENTE: "<<nombreGerente<<endl;
            cout<<"CATEGORIA: "<<categoriaRestaurante<<endl;
        }
};

class Reserva{
    private:
        int codigoRestaurante;
        int DNI;
        Fecha fechaReserva;
        int hora;
        bool estado;

    public:
        bool leerDeDisco(int pos){
            FILE *p;
            p=fopen("reservas.dat","rb");
            if(p==NULL) return false;
            fseek(p,pos*sizeof *this, 0);
            bool leyo=fread(this, sizeof *this, 1, p);
            fclose(p);
            return leyo;
        }

        int getCodigoRestaurante(){return codigoRestaurante;}
        int getDNI(){return DNI;}
        Fecha getFechaReserva(){return fechaReserva;}
        int getHora(){return hora;}
        bool getEstado(){return estado;}

        void setCodigoRestaurante(int cR){codigoRestaurante=cR;}
        void setDNI(int d){DNI=d;}
        void setFechaReserva(Fecha fR){fechaReserva=fR;}
        void setHora(int h){hora=h;}
        void setEstado(bool e){estado=e;}

        bool grabarEnDisco(){
            FILE *p;
            p=fopen("reservas.dat","ab");
            if(p==NULL) return false;
            bool escribio=fwrite(this, sizeof *this, 1, p);
            fclose(p);
            return escribio;
        }
        void Cargar(){
            cout<<"CODIGO: ";
            cin>>codigoRestaurante;
            cout<<"DNI: ";
            cin>>DNI;
            cout<<"FECHA RESERVA: ";
            fechaReserva.Cargar();
            cout<<"HORA: ";
            cin>>hora;
            estado=true;
        }
        void Mostrar(){
        cout<<"CODIGO: "<<codigoRestaurante<<endl;
        cout<<"DNI: "<<DNI<<endl;
        fechaReserva.Mostrar();
        cout<<"HORA: "<<hora<<endl;
        }
};

class Cliente{
   private:
        int DNI;
        char nombre [30];
        int medioPago, tipoCliente, edad;
        bool estado;
    public:
        ///gets() y sets()
        int getDNI(){return DNI;}
        const char *getNombre(){return nombre;}
        int getMedioPago(){return medioPago;}
        int getTipoCliente(){return tipoCliente;}
        int getEdad(){return edad;}
        bool getEstado(){return estado;}

        void setDNI(int d){DNI=d;}
        void setNombre(const char *n){strcpy(nombre,n);}
        void setMedioPago(int mP){medioPago=mP;}
        void setTipoCliente(int tC){tipoCliente=tC;}
        void setEdad(int e){edad=e;}
        void setEstado(bool e){estado=e;}

        bool grabarEnDisco(){
            FILE *p;
            p=fopen("clientes.dat","ab");
            if(p==NULL) return false;
            bool escribio=fwrite(this, sizeof *this, 1, p);
            fclose(p);
            return escribio;
        }
        void Cargar(){
            cout<<"DNI: ";
            cin>>DNI;
            cout<<"NOMBRE: ";
            cin>>nombre;
            cout<<"MEDIO DE PAGO: ";
            cin>>medioPago;
            cout<<"TIPO DE CLIENTE: ";
            cin>>tipoCliente;
            cout<<"EDAD: ";
            cin>>edad;
            estado=true;
        }
        void Mostrar(){
        cout<<"DNI: "<<DNI<<endl;
        cout<<"NOMBRE: "<<nombre<<endl;
        cout<<"MEDIO DE PAGO: "<<medioPago<<endl;
        cout<<"TIPO DE CLIENTE: "<<tipoCliente<<endl;
        cout<<"EDAD: "<<edad<<endl;
        }

        bool leerDeDisco(int pos){
            FILE *p;
            p=fopen("clientes.dat","rb");
            if(p==NULL) return false;
            fseek(p,pos*sizeof *this, 0);
            bool leyo=fread(this, sizeof *this, 1, p);
            fclose(p);
            return leyo;
        }
};



#endif // CLASES_H_INCLUDED
