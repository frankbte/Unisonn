#include "Cola.h"
#include <cstdlib>
#include <iostream>

using namespace std;

void Encolar(Nodo *&frente, Nodo*& fin, int n)
{
    Nodo *nuevo_nodo = new Nodo();

    nuevo_nodo ->dato = n;
    nuevo_nodo ->siguiente = NULL;

    if (ColaVacia(frente)){
        frente = nuevo_nodo;
    }
    else{
        fin ->siguiente = nuevo_nodo;
    }

    fin =nuevo_nodo;

    std::cout << "Elemento " << n << " insertado correctamente.";
}

void Desencolar(Nodo *& frente, Nodo *&fin, int & n)
{
    n =frente ->dato;
    Nodo *aux = frente;

    if(frente == fin){
        frente = NULL;
        fin = NULL;
    }else{
        frente = frente ->siguiente;
    }
    delete aux;
}

bool ColaVacia(Nodo *frente)
{
    return (frente == NULL)? true : false;
}
