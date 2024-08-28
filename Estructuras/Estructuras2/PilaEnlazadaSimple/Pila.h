#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

template<typename T>
class PILA{
public:
    Pila();
    ~Pila();
    Pila(const Pila & p);
    Pila<T>& operator=(const Pila& p);
    void Agregar(T valor);
    void Eliminar();
    bool EstaVacia() const;
    void Vaciar();
    int ObtenerTam() const;
    T ObtenerTope() const;
    void Imprimir() const;

private:
    int tam;
    struct Elemento{
    T valor;
    Elemento *sig;
    }*tope;

};

#include "Pila.tpp"
#endif // PILA_H_INCLUDED
