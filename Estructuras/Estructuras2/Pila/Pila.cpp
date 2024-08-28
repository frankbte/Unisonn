#include <iostream>
#include "Pila.h"
#include <iostream>

Pila::Pila()
{
    tope = -1;
}

void Pila::Agregar(int valor)
{
    if(EstaLlena()) throw "La pila esta llena...";
    elemento[++tope] = valor;
}

void Pila::Eliminar()
{
    if(EstaVacia()) throw "La pila esta vacia...";
    --tope;
}

int Pila::ObtenerTope() const
{
    if(EstaVacia()) throw "...";
    return elemento[tope];
}

void Pila::Vaciar()
{
    tope = -1;
}

int Pila::ObtenerTam() const
{
    if(EstaVacia()) return 0;
    return tope +1;
}

bool Pila::EstaVacia() const
{
    return tope == -1;
}

bool Pila::EstaLlena() const
{
    return tope == MAXTAM -1;
}

void Pila::Imprimir() const
{
    if(EstaVacia()) return;
    std:: cout << "[ ";
    for (int i = 0; i <= tope ; ++i){
        std:: cout << elemento[i] << ", ";
    }
    std:: cout << "]";
}
