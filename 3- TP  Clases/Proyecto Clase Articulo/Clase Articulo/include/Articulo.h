#ifndef ARTICULO_H
#define ARTICULO_H

void cargar_cadena(char* palabra, int tam);

class Articulo {
   private:
    char _codigo[6];
    char _descripcion[31];
    float _precio;
    int _stock;
    bool _estado;

   public:
    Articulo();
    Articulo(char* descripcion);

    void Cargar();
    void Mostrar();

    char* getCodigo();
    char* getDescripcion();
    float getPrecio();
    int getStock();
    bool getEstado();

    void setCodigo(char* codigo);
    void setDescripcion(char* descripcion);
    void setPrecio(float precio);
    void setStock(int stock);
    void setEstado(bool estado);
};

void cargarVector(Articulo* vec, int tam);
void mostrarVector(Articulo* vec, int tam);
void mostrarArticulosDePreciosMayores(Articulo* vec, int tam);
int devolverPosicion(Articulo* vec, int tam, char* cod);
Articulo devolverArticuloQueContiene(Articulo* vec, int tam, char* cod);
int cantidadConStockInferior(Articulo* vec, int tam, int stock);
void aumentarPrecio(Articulo* vec, int tam, int porcAumento);
char menu();


#endif // ARTICULO_H
