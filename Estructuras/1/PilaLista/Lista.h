#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <cstdlib>
#include <iostream>

class Lista{
public:
    Lista();
    ~Lista();
    void InsertarPrincipio(int valor);
    void InsertarFinal(int valor);
    void InsertarEnIndice(int indice, int valor);
    void Imprimir();
    void ImprimirReversa();
    int Tam() const;
    void EliminarPrincipio();
    void EliminarFinal();
    void EliminarEnIndice(int indice);
    bool EstaVacia();
    void Vaciar();
    void Modificar(int indice, int valor);
    int BuscarValor(int valor);
    int ObtenerPrimero();

private:
    int tam;
    struct Elemento{
        int valor;
        Elemento *sig;
        Elemento *prev;
        Elemento(int v, Elemento * s = NULL, Elemento * p = NULL);
    } *primero, *ultimo;

};

#endif // LISTA_H_INCLUDED
