#include <iostream>


template<typename T, int cap>
Pila<T, cap>::Pila()
{
    tope = -1;
}

template<typename T, int cap>
void Pila<T, cap>::Agregar(T valor)
{
    if(EstaLlena()) throw "La pila esta llena...";
    elemento[++tope] = valor;
}

template<typename T, int cap>
void Pila<T, cap>::Eliminar()
{
    if(EstaVacia()) throw "La pila esta vacia...";
    --tope;
}

template<typename T, int cap>
T Pila<T, cap>::ObtenerTope() const
{
    if(EstaVacia()) throw "...";
    return elemento[tope];
}

template<typename T, int cap>
void Pila<T, cap>::Vaciar()
{
    tope = -1;
}

template<typename T, int cap>
int Pila<T, cap>::ObtenerTam() const
{
    if(EstaVacia()) return 0;
    return tope +1;
}

template<typename T, int cap>
bool Pila<T, cap>::EstaVacia() const
{
    return tope == -1;
}

template<typename T, int cap>
bool Pila<T, cap>::EstaLlena() const
{
    return tope == cap -1;
}

template<typename T, int cap>
void Pila<T, cap>::Imprimir() const
{
    if(EstaVacia()) return;
    std:: cout << "[ ";
    for (int i = 0; i <= tope ; ++i){
        std:: cout << elemento[i] << ", ";
    }
    std:: cout << "]";
}
