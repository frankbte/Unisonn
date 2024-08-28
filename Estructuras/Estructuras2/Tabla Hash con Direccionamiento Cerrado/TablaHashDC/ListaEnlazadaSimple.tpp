#include "ListaEnlazadaSimple.h"

template<typename T>
ListaEnlazadaSimple<T>::ListaEnlazadaSimple(ListaEnlazadaSimple const &c) : tam(0), ultimo(nullptr), primero(nullptr)
{
    *this = c; // Constructor de copia: se copian los elementos de la lista original en la nueva lista
}

template<typename T>
ListaEnlazadaSimple<T> &ListaEnlazadaSimple<T>::operator=(const ListaEnlazadaSimple &c)
{
    if (this == &c)
        return *this; // Comprueba si la lista es la misma que la que se est� asignando y devuelve la lista actual si es verdadero

    Vaciar(); // Vac�a la lista actual
    Elemento *actual = c.primero; // Puntero al primer elemento de la lista original
    while (actual != nullptr)
    {
        AgregarComoUltimo(actual->valor); // Agrega cada elemento de la lista original a la lista actual
        actual = actual->siguiente; // Avanza al siguiente elemento en la lista original
    }
    return *this; // Devuelve la lista actualizada
}

template<typename T>
ListaEnlazadaSimple<T>::~ListaEnlazadaSimple()
{
    Vaciar(); // Destructor: vac�a la lista
}

template<typename T>
void ListaEnlazadaSimple<T>::AgregarComoUltimo(const T valor)
{
    auto *nuevo = new Elemento(valor); // Crea un nuevo elemento con el valor dado
    if (EstaVacia())
    {
        primero = ultimo = nuevo; // Si la lista est� vac�a, el nuevo elemento se convierte en el primero y el �ltimo
    }
    else
    {
        ultimo->siguiente = nuevo; // Establece el siguiente del �ltimo elemento actual como el nuevo elemento
        ultimo = nuevo; // El nuevo elemento se convierte en el �ltimo elemento
    }
    ++tam; // Incrementa el tama�o de la lista
}

template<typename T>
void ListaEnlazadaSimple<T>::EliminarPrimerElemento()
{
    if (EstaVacia())
        throw ListaVacia(); // Lanza una excepci�n si la lista est� vac�a
    Elemento *porBorrar = primero; // Almacena el puntero al primer elemento
    if (primero == ultimo)
        primero = ultimo = nullptr; // Si la lista solo tiene un elemento, establece el primero y el �ltimo como nulos
    else
        primero = primero->siguiente; // Establece el primer elemento como el siguiente elemento
    delete porBorrar; // Libera la memoria del elemento eliminado
    --tam; // Reduce el tama�o de la lista
}

template<typename T>
void ListaEnlazadaSimple<T>::EliminarUltimoElemento()
{
    if (EstaVacia())
        throw ListaVacia(); // Lanza una excepci�n si la lista est� vac�a
    Elemento *porBorrar = ultimo; // Almacena el puntero al �ltimo elemento
    if (primero == ultimo)
    {
        primero = ultimo = nullptr; // Si la lista solo tiene un elemento, establece el primero y el �ltimo como nulos
    }
    else
    {
        Elemento *aux = primero;
        while (aux->siguiente != ultimo)
        {
            aux = aux->siguiente; // Encuentra el elemento anterior al �ltimo elemento
        }
        aux->siguiente = nullptr; // Establece el siguiente del elemento anterior al �ltimo como nulo
        ultimo = aux; // Establece el �ltimo elemento como el elemento anterior
    }
    delete porBorrar; // Libera la memoria del elemento eliminado
    --tam; // Reduce el tama�o de la lista
}

template<typename T>
void ListaEnlazadaSimple<T>::EliminarEnPosicion(const unsigned int pos)
{
    if (EstaVacia())
        throw ListaVacia(); // Lanza una excepci�n si la lista est� vac�a

    if (pos < 0 || pos >= tam)
        throw FueraDeRango(); // Lanza una excepci�n si la posici�n est� fuera de rango

    if (pos == 0)
    {
        EliminarPrimerElemento(); // Si la posici�n es 0, elimina el primer elemento
    }
    else if (pos == tam - 1)
    {
        EliminarUltimoElemento(); // Si la posici�n es igual al tama�o de la lista menos 1, elimina el �ltimo elemento
    }
    else
    {
        Elemento *ant = primero;
        for (unsigned int i = 1; i < pos; ++i)
        {
            ant = ant->siguiente; // Encuentra el elemento anterior al elemento en la posici�n dada
        }
        Elemento *porBorrar = ant->siguiente; // Almacena el puntero al elemento a eliminar
        ant->siguiente = porBorrar->siguiente; // Establece el siguiente del elemento anterior al siguiente del elemento a eliminar
        delete porBorrar; // Libera la memoria del elemento eliminado
        --tam; // Reduce el tama�o de la lista
    }
}

template<typename T>
void ListaEnlazadaSimple<T>::Vaciar()
{
    while (!EstaVacia())
        EliminarPrimerElemento(); // Elimina el primer elemento repetidamente hasta que la lista est� vac�a
}

template<typename T>
bool ListaEnlazadaSimple<T>::EstaVacia() const
{
    return primero == nullptr; // Verifica si el primer elemento es nulo para determinar si la lista est� vac�a
}

template<typename T>
T ListaEnlazadaSimple<T>::operator[](const unsigned int pos) const
{
    if (EstaVacia())
        throw ListaVacia(); // Lanza una excepci�n si la lista est� vac�a
    if (pos < 0 || pos >= tam)
        throw FueraDeRango(); // Lanza una excepci�n si la posici�n est� fuera de rango
    Elemento *actual = primero;
    for (unsigned int i = 1; i <= pos; ++i)
    {
        actual = actual->siguiente; // Avanza al siguiente elemento hasta llegar a la posici�n dada
    }
    return actual->valor; // Devuelve el valor del elemento en la posici�n dada
}

template<typename T>
T& ListaEnlazadaSimple<T>::operator[](const unsigned int pos)
{
    if (EstaVacia())
        throw ListaVacia(); // Lanza una excepci�n si la lista est� vac�a
    if (pos < 0 || pos >= tam)
        throw FueraDeRango(); // Lanza una excepci�n si la posici�n est� fuera de rango
    Elemento *actual = primero;
    for (unsigned int i = 1; i <= pos; ++i)
    {
        actual = actual->siguiente; // Avanza al siguiente elemento hasta llegar a la posici�n dada
    }
    return actual->valor; // Devuelve una referencia al valor del elemento en la posici�n dada
}

template<typename T>
unsigned int ListaEnlazadaSimple<T>::ObtenerTam() const
{
    return tam; // Devuelve el tama�o de la lista
}

template<typename T>
const char *ListaEnlazadaSimple<T>::ListaVacia::what() const noexcept
{
    return "La lista est\240 vac\241a";
}

template<typename T>
const char *ListaEnlazadaSimple<T>::FueraDeRango::what() const noexcept
{
    return "Valor fuera de rango";
}
