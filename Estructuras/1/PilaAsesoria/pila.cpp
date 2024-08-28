#include <iostream>
#include <cstdlib>

#include "pila.h"

using std::cout;
using std::string;

Pila:: Pila()
{
    tope = -1;
}

void Pila::Apilar(char letra)
{
    if(EstaLlena()) throw "La pila esta llena.";
    elemento[++tope] = letra;
}

void Pila::Desapilar()
{
    if(EstaVacia()) throw "La pila ya esta vacia.";
    tope--;

}
bool Pila::EstaLlena() const
{
    if(tope == MaxTam-1)
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

char Pila::ElementoTope() const
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
void Pila::VaciarPila()
{
    tope= -1;
}

