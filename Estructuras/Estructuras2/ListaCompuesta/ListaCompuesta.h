#ifndef LISTACOMPUESTA_H_INCLUDED
#define LISTACOMPUESTA_H_INCLUDED
#include "Lista.h"

// Tarea hecha por:
// Francisco Yanez
// Luis Hiram Hernandez


/**
 * @brief Clase que representa una lista compuesta, la cual contiene una lista doblemente enlazada.
 *
 * @tparam T Tipo de datos de los elementos de la lista.
 */
template<typename T>
class ListaCompuesta {
public:
    /**
     * @brief Agrega un elemento al inicio de la lista.
     *
     * @param valor El valor del elemento a agregar.
     */
    void Agregar(T valor);

    /**
     * @brief Elimina la primera ocurrencia del elemento especificado en la lista.
     *
     * @param valor El valor del elemento a eliminar.
     */
    void Eliminar(T valor);

    /**
     * @brief Mezcla la lista actual con otra lista y devuelve la lista mezclada.
     *
     * @param l La otra lista que se va a mezclar con la lista actual.
     * @return ListaCompuesta<T> La lista resultante de la mezcla.
     */
    ListaCompuesta<T> Mezclar(ListaCompuesta<T> &l);

    /**
     * @brief Busca la primera ocurrencia del elemento especificado en la lista.
     *
     * @param valor El valor del elemento a buscar.
     * @return int El índice del elemento encontrado, o -1 si no se encuentra.
     */
    int Buscar(T valor);

    /**
     * @brief Elimina todos los elementos de la lista.
     */
    void Vaciar();

    /**
     * @brief Verifica si la lista está vacía.
     *
     * @return true Si la lista está vacía.
     * @return false Si la lista no está vacía.
     */
    bool EstaVacia();

    /**
     * @brief Obtiene el tamaño de la lista (cantidad de elementos).
     *
     * @return int El tamaño de la lista.
     */
    int Tamano();

    /**
     * @brief Imprime los elementos de la lista en orden ascendente.
     */
    void ImprimirAscendente();

    /**
     * @brief Imprime los elementos de la lista en orden descendente.
     */
    void ImprimirDescendente();

private:
    Lista<T> Lista; /**< La lista doblemente enlazada que forma parte de la lista compuesta. */
};

#include "ListaCompuesta.tpp"

#endif // LISTACOMPUESTA_H_INCLUDED
