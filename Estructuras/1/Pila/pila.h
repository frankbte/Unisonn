#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#define TAM_MAX 10


class Pila{
public:
    Pila();
    void Agregar(int valor);
    void Sacar();
    bool EstaLlena() const;
    bool EstaVacia() const;
    void Vaciar();
    int Tam() const;
    int Tope();
    void Imprimir();
    //bool EstaBienEscrita(string expresion);

private:
    int tope;
    int elemento[TAM_MAX]{};





#endif // PILA_H_INCLUDED

};
