#ifndef LISTAENLAZADA_H_INCLUDED
#define LISTAENLAZADA_H_INCLUDED

#include <iostream>

template<typename T>
class ListaEnlazada
{
public:
    ListaEnlazada() : tam(0), ultimo(nullptr), primero(nullptr)
    {}; // ya
    ~ListaEnlazada(); //ya
    ListaEnlazada(const ListaEnlazada &l);
    ListaEnlazada &operator=(const ListaEnlazada &l);
    void AgregarEnInicio(T valor); //ya
    void AgregarAlFinal(T valor); // ya
    void AgregarEnIndice(unsigned int pos, T valor); //ya
    void EliminarEnInicio();
    void EliminarDelFinal();
    void EliminarEnIndice(unsigned int pos);
    void Eliminar(T valor);
    void EliminarTodos(T valor);
    void Vaciar(); //ya
    bool EstaVacia(); //ya
    T ObtenerPrimero(); //ya
    T ObtenerUltimo(); //ya
    T ObtenerEnPosicion(int pos);
    void ModificarEnPos(int pos, T valor);
    T operator[](unsigned int pos) const;
    T& operator[](unsigned int pos);
    void Imprimir(); //ya
    int ObtenerTam(); //ya
    bool Encontarvalor(T valor);

private:
    unsigned int tam;

    struct Elemento
    {
        Elemento(T v, Elemento *sig = nullptr) : valor(v), siguiente(sig){};
        T valor;
        Elemento * siguiente = nullptr;
    } *ultimo, *primero;

};

#include "ListaEnlazada.tpp"

#endif // LISTAENLAZADA_H_INCLUDED
