#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <cstdlib>
#include <iostream>

class ColaM{
public:


    ColaM();
    ~ColaM();
    void InsertarPrincipio(int valor);
    void InsertarFinal(int valor);
    void InsertarEnIndice(int indice, int valor);
    void Imprimir();
    int Tam() const;
    void EliminarPrincipio();
    void EliminarFinal();
    void EliminarEnIndice(int indice);
    bool EstaVacia();
    void Vaciar();
    void Modificar(int indice, int valor);
    int BuscarValor(int valor);

private:
    int tam;
    class Persona{
        std:: string nombre;
        Persona *sig;
        Persona(const std:: string& nombre, Persona * s = NULL);
    } *primero, *ultimo;

};

#endif // LISTA_H_INCLUDED
