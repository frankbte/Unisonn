#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED
#include "Persona.h"
#include <string>

class Cola{
public:
    Cola();
    ~Cola();
    void Encolar(std::string valor, bool esNoble);
    void Desencolar();
    int ObtenerTam();
    Persona ObtenerPrimero();
    bool EstaVacia();
    void Vaciar();
    void Imprimir();

private:
    int tam;
    struct Elemento{
        std::string valor;
        bool esNoble;
        Elemento *siguiente;
    }*primero, *ultimo;

};

#include "cola.tpp"

#endif // COLA_H_INCLUDED
