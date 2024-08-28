#ifndef ARISTA_H_INCLUDED
#define ARISTA_H_INCLUDED
#include <iostream>

class Vertice;

class Arista
{
    int precio;
    Arista* sig;
    Vertice* dest;

    friend class Grafo;

public:
    Arista(Vertice* _dest, int precio);
};


#endif // ARISTA_H_INCLUDED
