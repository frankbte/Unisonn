#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED


class Pila{
public:
    Pila();
    ~Pila();
    Pila(const Pila & p);
    Pila& operator = (const Pila& p);
    void Agregar(int valor);
    void Sacar();
    bool EstaLlena() const;
    bool EstaVacia() const;
    void Vaciar();
    int Tam() const;
    int Tope() const;
    void Imprimir() const;
    //bool EstaBienEscrita(string expresion);

private:
    void Redimensionar();
    int capacidad, tope;
    int *elemento;


};


#endif // PILA_H_INCLUDED
