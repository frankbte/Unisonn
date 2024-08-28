#include <iostream>
#include <cstdlib>

#include "pila.h"

using std::cout;
using std::string;

/*Pila:: Pila()
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
}*/

void Pila::Apilar(int valor)
{
    contenedor.InsertarPrincipio(valor);

}

void Pila::Desapilar()
{
    contenedor.EliminarPrincipio();
}
/*bool Pila::EstaLlena() const
{
    if(tope == capacidad-1)
    {
        return true;
    }else
    {
        return false;
    }
}*/

bool Pila::EstaVacia()
{
    return contenedor.EstaVacia();
}

int Pila::ElementoTope()
{
    return contenedor.ObtenerPrimero();
}

void Pila::Imprimir()
{
    contenedor.Imprimir();
}

/*void Pila::Redimensionar()
{
    int *aux= elemento;
    capacidad *= 2;
    elemento = new int [capacidad];
    for(int i = 0; i <= tope; ++i)
    {
        elemento[i] = aux[i];
    }
    delete[] aux;
}*/
void Pila::VaciarPila()
{
    contenedor.Vaciar();
}
