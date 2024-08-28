#include <iostream>
#include <cstdlib>

template <typename T>
Pila<T>:: Pila()
{
    tope = -1;
    capacidad = 10;
    elemento = new int[capacidad];
}

template <typename T>
Pila<T>::~Pila()
{
    delete[] elemento;
}

template <typename T>
Pila<T>:: Pila(const Pila& p)
{
    elemento = NULL;
    *this = p;
}

template <typename T>
Pila<T>& Pila<T>::operator=(const Pila<T>& p)
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
}

template <typename T>
void Pila<T>::Apilar(T valor)
{
    if(EstaLlena()) Redimensionar();
    elemento[++tope] = valor;
}

template <typename T>
void Pila<T>::Desapilar()
{
    if(EstaVacia()) throw "La pila ya esta vacia.";
    tope--;

}

template <typename T>
bool Pila<T>::EstaLlena() const
{
    if(tope == capacidad-1)
    {
        return true;
    }else
    {
        return false;
    }
}

template <typename T>
bool Pila<T>::EstaVacia() const
{
    if(tope == -1)
    {
        return true;
    }else
    {
        return false;
    }
}

template <typename T>
T Pila<T>::ElementoTope() const
{
    if(EstaVacia()) throw "La pila esta vacia";
    return elemento[tope];
}

template <typename T>
void Pila<T>::Imprimir() const
{
    std::cout << "Pila: [ ";
    for (int i = tope; i >= 0; --i)
    {
        std::cout << elemento[i] << ", ";
    }
    if(!EstaVacia()) std::cout << "\b\b";
    std::cout << " ]";

}

template <typename T>
void Pila<T>::Redimensionar()
{
    int *aux= elemento;
    capacidad *= 2;
    elemento = new int [capacidad];
    for(int i = 0; i <= tope; ++i)
    {
        elemento[i] = aux[i];
    }
    delete[] aux;
}

template <typename T>
void Pila<T>::VaciarPila()
{
    tope= -1;
}

template<typename T>
int Pila<T>::ObtenerElementos()
{
    if(EstaVacia()) throw "La pila esta vacia";
    return tope + 1;
}
