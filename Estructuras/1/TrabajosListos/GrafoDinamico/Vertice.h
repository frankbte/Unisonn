#ifndef VERTICE_H_INCLUDED
#define VERTICE_H_INCLUDED

#include <iostream>

class Arista;

class Vertice{
    std::string nombre;
    Vertice* sig;
    Arista* ari;

    friend class Grafo;
public:
    Vertice(std::string nombre);
};


#endif // VERTICE_H_INCLUDED
