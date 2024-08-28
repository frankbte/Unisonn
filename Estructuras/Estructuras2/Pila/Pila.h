#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#define MAXTAM 10

class Pila{
public:
    Pila();
    void Agregar(int valor);
    void Eliminar();
    int ObtenerTope() const;
    void Vaciar();
    int ObtenerTam() const;
    bool EstaVacia() const;
    bool EstaLlena() const;
    void Imprimir() const;

private:
    int tope;
    int elemento[MAXTAM];
    int capacidad;


};


#endif // PILA_H_INCLUDED
