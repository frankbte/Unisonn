#include "pila.h"
#include <iostream>


Pila:: Pila()
{
    tope = -1;
}

 void Pila::Agregar(int valor)
{
    if(EstaLlena()) throw "La pila esta llena";
    elemento[++tope] = valor;
}

void Pila:: Sacar()
{
    if(EstaVacia()) throw "La pila esta vacia";
    --tope;
}

bool Pila:: EstaLlena() const
{
    return(tope + 1 == TAM_MAX);
}

bool Pila:: EstaVacia() const
{
    return (tope == -1);
}

void Pila::Vaciar()
{
    tope = -1;
}

int Pila::Tam() const
{
    return tope +1;
}

int Pila::Tope()
{
    if(EstaVacia()) throw "La pila esta vacia";
    return elemento[tope];
}

void Pila::Imprimir()
{
    for (int i = tope; i >= 0 ; --i){
        std:: cout << "[";
        std:: cout << elemento[i];
        std:: cout << "]";
    }
}

/*bool EstaBienEscrita(string expresion)
    {
        Pila pilaChar;
        for(int i = 0; i < expresion.size(); ++i){
            if(expresion[i] == '(' || expresion[i] == '[' || expresion[i] == '{');
            if(expresion[i] == ')' || expresion[i] == ']' || expresion[i] == '}');


        }
        return;
    }
*/
