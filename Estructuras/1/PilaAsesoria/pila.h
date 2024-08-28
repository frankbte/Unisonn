#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#define MaxTam 10

class Pila{
public:
    Pila();
    //~Pila();
    void Apilar(char letra);
    void Desapilar();
    char ElementoTope() const;
    bool EstaLlena() const;
    bool EstaVacia() const;
    void VaciarPila();
    void Imprimir() const;

private:
    int tope;
    char elemento[MaxTam];
};

#endif // PILA_H_INCLUDED
