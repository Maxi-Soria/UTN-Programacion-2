#ifndef FECHA_H
#define FECHA_H

class Fecha{
private:
    int _dia, _mes, _anio;

public:
    void Cargar();
    void Mostrar();

    ///Constructor
    Fecha();

    ///Getters
    int getDia();
    int getMes();
    int getAnio();

    ///Seters
    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);


};


#endif // FECHA_H
