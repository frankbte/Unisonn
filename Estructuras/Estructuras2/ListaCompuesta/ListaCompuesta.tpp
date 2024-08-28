#include "ListaCompuesta.h"

template<typename T>
void ListaCompuesta<T>::Agregar(T valor)
{
    Lista.AgregarEnInicio(valor);
    Lista.OrdenarAscendente();
}

template<typename T>
void ListaCompuesta<T>::Eliminar(T valor)
{
    Lista.EliminarPrimeraOcurrencia(valor);
}

template<typename T>
int ListaCompuesta<T>::Buscar(T valor)
{
    return Lista.BuscarPos(valor);
}

template<typename T>
void ListaCompuesta<T>::Vaciar()
{
    Lista.Vaciar();
}

template<typename T>
bool ListaCompuesta<T>::EstaVacia()
{
    return Lista.EstaVacia();
}

template<typename T>
int ListaCompuesta<T>::Tamano()
{
    return Lista.Tamano();
}

template<typename T>
void ListaCompuesta<T>::ImprimirAscendente()
{
    Lista.Imprimir();
}

template<typename T>
void ListaCompuesta<T>::ImprimirDescendente()
{
    Lista.ImprimirReversa();
}

template<typename T>
ListaCompuesta<T> ListaCompuesta<T>::Mezclar(ListaCompuesta<T>& l)
{
    ListaCompuesta<T> lista3 = *this;

    int tamano_l = l.Tamano();
    for(int i = 0; i < tamano_l; ++i) {
        T valor = l.Lista.BuscarPos(i);
        lista3.Agregar(valor);
    }
    return lista3;
}



