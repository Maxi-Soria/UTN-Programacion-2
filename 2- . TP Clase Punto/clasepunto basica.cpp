# include<iostream>
# include<cstdlib>
# include<cstdio>
# include<cstring>
#include <windows.h>
#include <ctime>
#include <unistd.h>
#include <conio.h>

using namespace std;


///DEFINICIONES DE CONSTANTES Y FUNCIONES QUE SON UTILIZADAS POR LA CLASE PUNTO
enum Color{
    cNEGRO=0,
    cAZUL=1,
    cVERDE=2,
    cCIAN=3,
    cROJO=4,
    cMAGENTA=5,
    cMARRON=6,
    cGRIS_CLARO=7,
    cGRIS=8,
    cAZUL_CLARO=9,
    cVERDE_CLARO=10,
    cCIAN_CLARO=11,
    cROJO_CLARO=12,
    cMAGENTA_CLARO=13,
    cAMARILLO=14,
    cBLANCO=15
};
/// Se definen una serie de constantes que asumen el valor que se le asignó.
/// Es más fácil usar cBLANCO para setear el color a blanco, que acordarse el número 15

void ocultarCursor(){
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void mostrarCursor(){
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 10;
   info.bVisible = TRUE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void gotoxy(short x, short y){ ///UBICA EL CURSOR EN LA POSICIÓN x,y DE LA PANTALLA
    COORD a;
    a.X = x;
    a.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),a);
}
///ASIGNA COLORES AL TEXTO Y AL FONDO DEL TEXTO
void textcolor(int colorTexto=15, int colorFondo=0){
    int color = colorTexto + colorFondo * 16;
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE), color);
}

///**FIN FUNCIONES


///CLASE PUNTO
class Punto {
    private:
        int x;
        int y;
        int color;
    public:
        Punto(int a=0, int b=0, int nuevoColor=cNEGRO){ ///Punto b)4 y 5 modificar el constructor
            if(color < 0){
                color = rand()%16;
            }
            else{
                if (a < 0){
                    x = rand()%81;
                    y = rand()%25;
                    color = rand()%16;
                }
                else{
                    x=a;
                    y=b;
                    color=nuevoColor;
                }
            }
        }
        ///Segundo constructor
        Punto(char *cadena){
            if(strcmp(cadena, "fin")==0){
                x=75;
                y=0;
                color=cNEGRO;
            }
            else{
                if(strcmp(cadena, "medio")==0){
                    x = 38;
                    y = 0;
                    color = cROJO;
                }
                else{
                    if(strcmp(cadena, "principio")==0){
                        x = 0;
                        y = 0;
                        color = cNEGRO;
                    }
                    else{
                        if(strcmp(cadena, "aleatorio")==0){
                            x = rand()%81;
                            y = rand()%25;
                            color = rand()%16;
                       }
                    }
                }
            }
        }

        void Mostrar(){
            textcolor(color, 15);
            gotoxy(x,y);
            cout<<(char)42;
        }

        void MostrarValores();
        void Ocultar(){
            gotoxy(x,y);
            cout<<" ";
        }

        //b) 1***************************
        //recibe un tiempo en milisegundos para parpadear
        void Parpadear(int espera){
            for (int i=0 ; i< 10 ; i++ ){
                Ocultar();
                usleep(espera);
                Mostrar();
                usleep(espera);
            }
        }

        //********************************
        //b) 2****************************
        //
        void Mover(char direccion, int desplazamiento){
            if(direccion == 'x'){
                Ocultar();
                setX(getX() + desplazamiento);
            }
            else{
                if(direccion == 'y'){
                    Ocultar();
                    setY(getY() + desplazamiento);
                }
            }
        }
        //**************************************
        //b) 3**********************************
        void setXY(){
            if(x>=0 && x <= 25 && y >= 0 && y <= 80){
                int aux;
                aux = x;
                x = y;
                y = aux;
            }
        }


        void setX(int valor){
            if(valor>=0 && valor<=75)  x=valor;  ///Punto d
        }

        void setY(int valor){
            if(valor>=0 && valor <= 30)  y=valor; ///Punto d
        }

        void setColor(int nuevo){
            if(nuevo>0 && nuevo<=15){
                color=nuevo;
            }
        }

        int getX(){return x;}
        int getY(){return y;}
        int getColor(){return color;}
        ~Punto(){///DESTRUCTOR: se ejecuta cuando el objeto cae fuera de su alcance.
            textcolor(cNEGRO,cBLANCO);

        }
};

void Punto::MostrarValores(){
        cout<< "x= " << x<<endl;
        cout<< "y= " << y<<endl;
        cout<< "Color: " << color<<endl;
    }


//*******************
void punto1();
void punto2();
void punto3();
void punto4();
void punto5();
void punto6();
void punto7();
void punto8();
void punto9();
void punto10();
void punto11();
void punto12();
void punto13();
//*********************

int main() {
    srand(time(NULL));
    ocultarCursor();
    textcolor(0,15);
    int opc;
    while(true){
        system("cls");
        cout<<"----------MENU------------"<<endl;
        cout<<"1. DIBUJAR UN PUNTO EN LA POSICION QUE EL USUARIO PIDA POR TECLADO"<<endl;
        cout<<"2. DIBUJAR UNA LINEA DE PUNTOS HORIZONTAL EN UNA POSICION DEL EJE Y DEFINIDA"<<endl;
        cout<<"3. DIBUJAR UNA LINEA DE PUNTOS VERTICAL EN UNA POSICION DEL EJE X DEFINIDA"<<endl;
        cout<<"4. DIBUJAR UNA LINEA DE PUNTOS HORIZONTAL QUE ALTERNE 2 COLORES"<<endl;
        cout<<"5. DIBUJAR UNA LINEA DE PUNTOS VERTICAL QUE ALTERNE 2 COLORES"<<endl;
        cout<<"6. DIBUJAR 2 LINEAS HORIZONTALES QUE NAZCAN EN AMBOS EXTREMOS DE LA PANTALLA "<<endl;
        cout<<" Y SE ENCUENTREN EN EL CENTRO DE LA PANTALLA. DEBEN SER DE DISTINTOS COLORES "<<endl;
        cout<<"7. DIBUJAR 2 LINEAS HORIZONTALES QUE NAZCAN EN AMBOS EXTREMOS DE LA PANTALLA "<<endl;
        cout<<" Y SE ENCUENTREN EN EL CENTRO DE LA PANTALLA. DEBEN SER DE DISTINTOS COLORES "<<endl;
        cout<<" AL ENCONTRARSE DEBEN LAS LINEAS DEBEN SUBIR HASTA LA POSICIÓN 0 DE Y "<<endl;
        cout<<"8. HACER UN PUNTO QUE PARPADEE EN LA PANTALLA EN UNA POSICION DADA"<<endl;
        cout<<"9. HACER UN RECTANGULO A PARTIR DE DOS VALORES DE 2 LADOS"<<endl;
        cout<<"10. HACER UN PUNTO QUE CAMINE POR LA PANTALLA DE MANERA HORIZONTAL"<<endl;
        cout<<"11. HACER UN PUNTO QUE SE DESPLAZE POR LA PANTALLA DE MANERA VERTICAL"<<endl;
        cout<<"12. DIBUJAR UNA LLUVIA DE PUNTOS"<<endl;
        cout<<"13. DIBUJAR UNA LLUVIA DE PUNTOS HASTA QUE SE PRESIONA UNA TECLA"<<endl;
        cout<<"OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                punto1();
                break;
            case 2:
                punto2();
                break;
            case 3:
                punto3();
                break;
            case 4:
                punto4();
                break;
            case 5:
                punto5();
                break;
            case 6:
                punto6();
                break;
            case 7:
                punto7();
                break;
            case 8:
                punto8();
                break;
            case 9:
                punto9();
                break;
            case 10:
                punto10();
                break;
            case 11:
                punto11();
                break;
            case 12:
                punto12();
                break;
            case 13:
                punto13();
                break;
            case 0:
                return 0;

        }
        system("pause>nul");

    }
    return 0;
}
void punto1(){
    //char vec[10] = {"aleatorio"};
    Punto obj(0,0,3);

    int x, y;
    cout << "Ingrese la cordenada X: ";
    cin >> x;
    cout << "Ingrese la cordenada y: ";
    cin >> y;
    obj.setX(x);
    obj.setY(y);
    system("cls");
//    obj.MostrarValores();
    obj.Mostrar();

    /* Pruebas punto b)2
    sleep(2);
    obj.Mover('x',10);
    obj.Mostrar();
    sleep(2);
    obj.Mover('y',5);
    obj.Mostrar();
    */
    //obj.setXY();
    //obj.MostrarValores();

}

void punto2(){
    Punto obj(0,0,cROJO);
    obj.setY(20);
    system("cls");
    for (int i=0 ; i<50 ; i++ ){
        obj.setX(i);
        obj.Mostrar();
    }
}

void punto3(){
    Punto obj(0,0,cROJO);
    obj.setX(20);
    system("cls");
    for (int i=0 ; i<10 ; i++ ){
        obj.setY(i);
        obj.Mostrar();
    }
}

void punto4(){
    Punto obj(0,0,cNEGRO);
    obj.Mostrar();
    obj.setY(20);
    system("cls");
    for (int i=0 ; i<30; i++ ){
        obj.setX(i);
        if(i%2 != 0) obj.setColor(cROJO_CLARO);

        else obj.setColor(cAZUL_CLARO);

        obj.Mostrar();
    }

}

void punto5(){
    Punto obj(0,0,cNEGRO);
    obj.Mostrar();
    obj.setX(20);
    system("cls");
    for (int i=0 ; i<15; i++ ){
        obj.setY(i);
        if(i%2 != 0) obj.setColor(cROJO_CLARO);

        else obj.setColor(cAZUL_CLARO);

        obj.Mostrar();
    }

}

void punto6(){

    Punto obj(0,5,cROJO);
    system("cls");
    for (int i=0 ; i<=166 ; i++ ){
        obj.setX(i);
        if(i<=83){
            obj.setColor(cVERDE);
        }
        else{
            obj.setColor(cAZUL);
        }
        obj.Mostrar();
    }


    /*Punto objIzq(0,10,cROJO), objDer(74,10,cAZUL);
    int posIzq = objIzq.getX();
    int posDer = objDer.getX();

    objDer.Mostrar();
    objIzq.Mostrar();

    while (posDer != posIzq){

        objIzq.setX(posIzq++);
        objDer.setX(posDer--);

        objDer.Mostrar();
        objIzq.Mostrar();
        usleep(50000);

    }*/
}


void punto7(){
    Punto objIzq(0,20,cROJO), objDer(76,20,cAZUL);
    int posIzq = objIzq.getX();
    int posDer = objDer.getX();
    int pos_Y = objIzq.getY();

    while (pos_Y >= 0){

        if(posIzq != posDer){
            objIzq.setX(posIzq);
            objDer.setX(posDer);

            objDer.Mostrar();
            objIzq.Mostrar();

            posIzq++;
            posDer--;
        }
        else{
            pos_Y--;
            objDer.setY(pos_Y);
            objIzq.setY(pos_Y);

            objDer.Mostrar();
            objIzq.Mostrar();
        }
        usleep(50000);
    }
}

void punto8(){
    Punto obj(38,12, cAZUL);

    //obj.Parpadear(500000); //resuelto con el metodo parpadea

      for (int i=0 ; i<10; i++ ){
          usleep(500000);
          obj.Ocultar();
          usleep(500000);
          obj.Mostrar();
      }
}


void punto9(){
    Punto obj(26,14,cVERDE);
    obj.Mostrar();

    int largo = 21, alto = 10;
    alto = alto/2;

    int pos_X = obj.getX();
    int pos_Y = obj.getY();

    for (int i=0 ; i<largo ; i++ ){
        obj.setX(pos_X+i);
        obj.Mostrar();
        usleep(50000);
    }

    for (int i=0 ; i<alto ; i++ ){
        obj.setY(pos_Y-i);
        obj.Mostrar();
        usleep(50000);
    }

    pos_X = obj.getX();
    pos_Y = obj.getY();

    for (int i=0 ; i<largo; i++ ){
        obj.setX(pos_X-i);
        obj.Mostrar();
        usleep(50000);
    }

    for (int i=0 ; i<alto ; i++ ){
        obj.setY(pos_Y+i);
        obj.Mostrar();
        usleep(50000);
    }

}

void punto10(){
    Punto obj(10,0,cROJO);
    obj.setY(20);
    system("cls");
    int pos_X = obj.getX();

    for (int i=0 ; i<20 ; i++ ){
        obj.setX(pos_X+i);
        obj.Mostrar();
        usleep(50000);
        obj.Ocultar();
    }
    obj.Mostrar();
}

void punto11(){

    Punto obj(20,0,cROJO);
    system("cls");

    for (int i=0 ; i<25; i++ ){
        obj.setY(i);
        obj.Mostrar();
        usleep(50000);
        obj.Ocultar();
    }
}

void punto12(){
    int aleatorio;

    Punto obj;

    for (int i=0 ; i<10; i++ ){

        aleatorio = rand() % 80;
        obj.setX(aleatorio);


        for (int j=0 ; j<25; j++ ){
            obj.setY(j);
            obj.Mostrar();
            usleep(5000);
            obj.Ocultar();
        }
    }

}

void punto13(){
    int aleatorio;

    Punto obj;

    while (true) { // Bucle infinito
        aleatorio = rand() % 80;
        obj.setX(aleatorio);

        for (int j=0 ; j<25; j++ ){
            obj.setY(j);
            obj.Mostrar();
            usleep(10000);
            obj.Ocultar();


        }
        if (_kbhit()) {
            return ;
        }

    }
}






