#ifndef PILA_H
#define PILA_H

template<typename T>
class pila
{
public:
    pila();
    ~pila();
    pila(const pila& p);
    pila<T>& operator=(const pila<T>& p);
    void Agregar(T valor);
    void Eliminar();
    T ObtenerTope() const;
    void Vaciar();
    int OntenerTam() const;
    bool EstaVacia() const;
    void Imprimir() const;
private:
    int tam;
    struct Elemento{
        T valor;
        Elemento *siguiente;
    }*tope;
};

#include "../pila.tpp"

#endif // PILA_H
