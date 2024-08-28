#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <cstdlib>
#include <iostream>

class ABB{
public:
    ABB();
    ~ABB();
    ABB(const ABB * r);
    void Agregar(int valor);
    bool Buscar(int valor);
    void InOrden();
    void Podar(int valor);
    void Vaciar();
    int NumeroNodos();
    int AlturaArbol();
private:
    int numNodos;

    struct Nodo{
        int valor;
        Nodo *hijoDer;
        Nodo *hijoIzq;
        Nodo(int v, Nodo* hIzq = NULL, Nodo* hDer = NULL);
        bool EsHoja();
        bool TieneHijoIzq();
        bool TieneHijoDer();
        bool TieneAmbosHijos();
    }*raiz;

    void Agregar(Nodo *&r, int valor);
    bool Eliminar(Nodo *&r, int valor);
    bool Buscar(Nodo*&r, int valor);
    void InOrden(Nodo*&r);
    void Vaciar(Nodo *&r);
    void EliminarArbol(Nodo*&r);
    int AlturaArbol(Nodo*&r);


    //void AgregarPrivado(Nodo *& r, int valor);
    //void Podar(Nodo* &r);
    //void ImprimirInOrden(Nodo* r);
    //Nodo*& BuscarMinimo(Nodo*& r);
    //bool Eliminar(Nodo*& r, int valor);
};

#endif // LISTA_H_INCLUDED
