#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

template <typename T, int cap>
class Pila{
public:
    Pila();
    void Agregar(T valor);
    void Eliminar();
    T ObtenerTope() const;
    void Vaciar();
    int ObtenerTam() const;
    bool EstaVacia() const;
    bool EstaLlena() const;
    void Imprimir() const;

private:
    int tope;
    T elemento[cap];


};

#include "Pila.tpp"


#endif // PILA_H_INCLUDED
