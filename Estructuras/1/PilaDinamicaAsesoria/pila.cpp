#include <iostream>
#include <cstdlib>

#include "pila.h"

using std::cout;
using std::string;

Pila:: Pila()
{
    tope = -1;
    capacidad = 10;
    elemento = new int[capacidad];
}

Pila::~Pila()
{
    delete[] elemento;
}

Pila:: Pila(const Pila& p)
{
    elemento = NULL;
    *this = p;
}
Pila& Pila::operator=(const Pila& p)
{
    if(this == &p) return *this;
    delete[] elemento;
    tope = p.tope;
    capacidad = p.capacidad;
    elemento = new int [capacidad];
    for (int i =0; i<= tope; ++i)
    {
        elemento[i] = p.elemento[i];
    }
    return *this;
}

void Pila::Apilar(int valor)
{
    if(EstaLlena()) Redimensionar();
    elemento[++tope] = valor;
}

void Pila::Desapilar()
{
    if(EstaVacia()) throw "La pila ya esta vacia.";
    tope--;

}
bool Pila::EstaLlena() const
{
    if(tope == capacidad-1)
    {
        return true;
    }else
    {
        return false;
    }
}

bool Pila::EstaVacia() const
{
    if(tope == -1)
    {
        return true;
    }else
    {
        return false;
    }
}

int Pila::ElementoTope() const
{
    if(EstaVacia()) throw "La pila esta vacia";
    return elemento[tope];
}

void Pila::Imprimir() const
{
    std::cout << "Pila: [ ";
    for (int i = tope; i >= 0; --i)
    {
        std::cout << elemento[i] << ", ";
    }
    if(!EstaVacia()) std::cout << "\b\b";
    std::cout << " ]";

}

void Pila::Redimensionar()
{
    int *aux= elemento;
    capacidad *= 2;
    elemento = new int [capacidad];
    for(int i = 0; i <= tope; ++i)
    {
        elemento[i] = aux[i];
    }
    delete[] aux;
}
void Pila::VaciarPila()
{
    tope= -1;
}
