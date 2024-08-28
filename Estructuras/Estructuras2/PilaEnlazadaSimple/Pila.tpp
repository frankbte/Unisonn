#include <iostream


template<typename T>
Pila<T>::Pila(): tam(0), tope(nullptr)
{

}

template<typename T>
Pila<T>::~Pila()
{

}

template<typename T>
Pila<T>::Pila(const Pila *p)
{

}

template<typename T>
Pila<T>::&Pila operator=(const Pila*p)
{

}

template<typename T>
void Pila<T>::Agregar(T valor)
{
    nuevo  = new Elemento;
    nuevo ->valor = valor;
    nuevo ->siguiente = tope;

}

template<typename T>
void Pila<T>::Eliminar()
{

}

template<typename T>
bool Pila<T>::EstaVacia() const
{

}

template<typename T>
void Pila<T>::Vaciar()
{

}

template <typename T>
int Pila<T>::ObtenerTam() const
{

}

template<typename T>
T Pila<T>::ObtenerTope() const
{

}

template<typename T>
void Pila<T>::Imprimir() const
{


}
