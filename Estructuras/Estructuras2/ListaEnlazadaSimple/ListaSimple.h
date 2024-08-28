#ifndef LISTASIMPLE_H_INCLUDED
#define LISTASIMPLE_H_INCLUDED

#include <cstdlib>
#include <iostream>

class Lista{
public:
    Lista(); //ya
    ~Lista(); // ya
    Lista(const Lista &l);
    void AgregarEnInicio(int valor); // ya
    void AgregarAlFinal(int valor); // ya
    void AgregarEnIndice(int indice, int valor); // ya
    void EliminarDeInicio(); // ya
    void EliminarDeFinal(); //ya
    void EliminarEnIndice(int indice); // ya
    bool BuscarValor(int valor); //saber si está o no
    int BuscarPos(int valor); //retornar indice
    bool EstaVacia(); // ya
    int ObtenerPrimero(); // ya
    int ObtenerUltimo(); // ya
    int ObtenerValorEnIndice(int indice); // ya
    void ModificarValorEnIndice(int indice, int nuevoValor); // ya
    int Tamano(); // ya
    void Vaciar(); // ya
    void Imprimir(); // ya

private:
    int tam;
    struct Elemento{
        int valor;
        Elemento *siguiente;
    }*primero, *ultimo;
};

#endif // LISTASIMPLE_H_INCLUDED
