#include "Lista.h"

#include <iostream>
#include <cstdlib>

ABB::ABB()
{
    raiz = NULL;
}

void ABB::Agregar(int valor)
{
    Agregar(raiz, valor);
}

void ABB::Agregar(Nodo *&r, int valor)
{
    if(r == NULL){
        r = new  Nodo(valor);
        ++numNodos;
    }else{
        if(valor < r->valor) Agregar(r->hijoIzq, valor);
        else if (valor > r->valor) Agregar(r->hijoDer, valor);
    }
}

ABB::~ABB()
{
    EliminarArbol(raiz);
}

int ABB::NumeroNodos()
{
    return numNodos;
}

int ABB::AlturaArbol()
{
    //return AlturaArbol(raiz);
}



/*void ABB::Eliminar(int valor)
{
    Eliminar(raiz, valor);
}

bool ABB::Eliminar(Nodo *&r, int valor)
{
    if(r == NULL) return false;
    else if( r->valor == valor){

        if()
    }
}*/

void ABB::EliminarArbol(Nodo *&r)
{
    if(r != nullptr){
        EliminarArbol(r->hijoIzq);
        EliminarArbol(r->hijoDer);
        delete r;
    }
}

bool ABB::Buscar(int valor)
{
    return Buscar(raiz, valor);
}

bool ABB::Buscar(Nodo*&r , int valor)
{
    if(r == nullptr){
        return false;
    }
    if(r->valor == valor){
        return true;
    }
    else if(valor < r->valor){
        return Buscar(r->hijoIzq, valor);
    }
    else{
        return Buscar(r->hijoDer, valor);
    }
}

void ABB::InOrden()
{
    InOrden(raiz);
}

void ABB::InOrden(Nodo*&r)
{
    if(r == nullptr){
        return;
    }
    InOrden(r->hijoIzq);
    std::cout << r->valor << " ";
    InOrden(r->hijoDer);
}

void ABB::Vaciar()
{
    Vaciar(raiz);
    raiz = nullptr;
}

void ABB::Vaciar(Nodo *&r)
{
    if(r == nullptr){
        return;
    }

    Vaciar(r->hijoIzq);
    Vaciar(r->hijoDer);
    delete r;
}

ABB::Nodo::Nodo(int v, Nodo* hIzq /*= NULL*/, Nodo* hDer): valor(v), hijoIzq(hIzq), hijoDer(hDer){}

