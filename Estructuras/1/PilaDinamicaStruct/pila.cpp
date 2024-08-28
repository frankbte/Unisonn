#include "pila.h"
#include <iostream>


Pila:: Pila()
{
    tope = -1;
    capacidad = 10;
    elemento = new int[capacidad];
}

Pila:: ~Pila()
{
    delete[] elemento;
}

Pila:: Pila(const Pila &p)
{
    elemento = NULL;
    *this = p;
}
Pila &Pila::operator=(const Pila& p)
{
    if(this == &p) return *this;
    delete[] elemento;
    tope = p.tope;
    capacidad = p.capacidad;
    elemento=  new int[capacidad];
    for(int i =0; i<= tope; ++i){
        elemento[i] =p.elemento[i];
    }
    return *this;
}

void Pila::Redimensionar()
{
    int *aux = elemento;
    capacidad *= 2;
    elemento = new int[capacidad];
    for(int i = tope; i <= 0; i--){
        elemento [i] = aux[i];
    }
    delete[] aux;
}




 void Pila::Agregar(int valor)
{
    if(EstaLlena()) Redimensionar();
    elemento[++tope] = valor;
}

void Pila:: Sacar()
{
    if(EstaVacia()) throw "La pila esta vacia";
    --tope;
}

bool Pila:: EstaLlena() const
{
    return(tope + 1 == capacidad);
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

int Pila::Tope() const
{
    if(EstaVacia()) throw "La pila esta vacia";
    return elemento[tope];
}

void Pila::Imprimir() const
{
    std:: cout << "[ ";
    for (int i = tope; i >= 0 ; --i){
        std:: cout << elemento[i] << ", ";
    }
    if(!EstaVacia()) std:: cout << "\b\b ";
    std:: cout << "]";

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
