#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include <cstdlib>
#include <iostream>

template<typename T>
class ABB{

public:
    ABB();
    ~ABB();
    //ABB(const ABB & r);
    //ABB& operator=(const ABB& r);
    void Insertar(T valor);
    void Eliminar(T valor);
    bool Buscar(T valor);
    int NumNodos();
    int AlturaArbol();
    bool EstaVacio();
    void Vaciar();
    void ImprimirInOrden();
    void ImprimirInOrdenInverso();
    void ImprimirPreOrden();
    void ImprimirPreOrdenInverso();
    void ImprimirPostOrden();
    void ImprimirPostOrdenInverso();
    int BuscarMayor();
    int BuscarMenor();


private:

    struct Nodo{
    T valor;
    Nodo* hijoIzq;
    Nodo* hijoDer;
    Nodo(T v, Nodo* hIzq = NULL, Nodo* hDer = NULL);
    }*raiz;

    int numNodos;
    int altura;

    void Insertar(Nodo *& r, T valor);
    Nodo *& Eliminar(Nodo *& r, T valor);
    bool Buscar(Nodo *& r, T valor);
    Nodo *& BuscarMenor(Nodo *& r);
    Nodo *& BuscarMayor(Nodo *& r);
    int AlturaArbol(Nodo *& r);
    void ImprimirInOrden(Nodo *& r);
    void ImprimirInOrdenInverso(Nodo *& r);
    void ImprimirPostOrden(Nodo *& r);
    void ImprimirPostOrdenInverso(Nodo *& r);
    void ImprimirPreOrden(Nodo *& r);
    void ImprimirPreOrdenInverso(Nodo *& r);
    void CopiarPreOrden(Nodo *& r);
    void Podar(Nodo *& r);
    int FactorEquilibrio(Nodo * r);

};
#include "Arbol.tpp"
#endif // ARBOL_H_INCLUDED
