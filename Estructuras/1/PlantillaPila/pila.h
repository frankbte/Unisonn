#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#define TAM_MAX 10


template <typedef T>
class Pila{
public:
    Pila();
    void Agregar(const T & valor);
    void Sacar();
    bool EstaLlena() const;
    bool EstaVacia() const;
    void Vaciar();
    int Tam() const;
    const T & Tope();
    void Imprimir();
    //bool EstaBienEscrita(string expresion);

private:
    int tope;
    T elemento[TAM_MAX]{};


};


#endif // PILA_H_INCLUDED
