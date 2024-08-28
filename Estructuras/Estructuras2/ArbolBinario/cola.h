#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

template <typename T>
class Cola{
public:
    Cola();
    ~Cola();
    Cola(const Cola<T> &c);
    operator=(const Cola<T> &c);
    void Encolar(T valor);
    void Desencolar();
    int ObtenerTam();
    T ObtenerPrimero();
    T ObtenerUltimo();
    bool EstaVacia();
    void Vaciar();
    void Imprimir();

private:
    int tam;
    struct Elemento{
        T valor;
        Elemento *siguiente;
    }*primero, *ultimo;

};

#include "cola.tpp"

#endif // COLA_H_INCLUDED
