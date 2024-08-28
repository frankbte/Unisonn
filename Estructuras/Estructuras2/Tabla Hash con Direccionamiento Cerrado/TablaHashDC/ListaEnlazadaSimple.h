#ifndef LISTAENLAZADASIMPLE_H_INCLUDED
#define LISTAENLAZADASIMPLE_H_INCLUDED

#include <iostream>

/**
 * \brief Clase de una lista enlazada simple.
 *
 * Esta clase representa una lista enlazada simple que almacena elementos de tipo genérico T.
 * La lista proporciona operaciones para agregar, eliminar, obtener y modificar elementos en diferentes posiciones.
 * También ofrece funcionalidades para verificar si la lista está vacía, obtener el tamaño de la lista, buscar elementos y más.
 *
 * \tparam T El tipo de datos de los elementos almacenados en la lista.
 */

template<typename T>

class ListaEnlazadaSimple
{
public:

    /** \brief Constructor de la lista enlazada simple
     *
     *  Crea una lista enlazada simple vacía.
     *
     * \param nullptr
     * \return explicit ListaEnlazadaSimple() : tam(0), ultimo(nullptr), primero(nullptr)
     *
     */
    explicit ListaEnlazadaSimple() : tam(0), ultimo(nullptr), primero(nullptr)
    {};


    /** \brief Constructor de copia de la lista enlazada simple
     *
     *  Crea una nueva lista enlazada simple a partir de otra ya existente.
     *
     * \param c const ListaEnlazadaSimple&
     *
     */
    ListaEnlazadaSimple(const ListaEnlazadaSimple &c);


    /** \brief Operador de asignación de la lista enlazada simple
     *
     *  Asigna el valor de una lista enlazada simple a otra ya existente.
     *
     * \param c const ListaEnlazadaSimple&
     * \return ListaEnlazadaSimple&
     *
     */
    ListaEnlazadaSimple &operator=(const ListaEnlazadaSimple &c);


    /** \brief Destructor de la lista enlazada simple
     *
     *  Libera la memoria reservada por los elementos de la lista enlazada simple.
     *
     *
     */
    ~ListaEnlazadaSimple();

    /** \brief Agrega un elemento al final de la lista enlazada simple
     *
     *  Crea un nuevo elemento con el valor proporcionado y lo agrega al final de la lista enlazada simple.
     *
     * \param valor T
     * \return void
     *
     */
    void AgregarComoUltimo(T valor);

    /** \brief Elimina el primer elemento de la lista enlazada simple
     *
     *  Elimina el primer elemento de la lista enlazada simple y libera la memoria correspondiente.
     *
     * \return void
     *
     */
    void EliminarPrimerElemento();


    /** \brief Elimina el último elemento de la lista enlazada simple
     *
     *  Elimina el último elemento de la lista enlazada simple y libera la memoria correspondiente.
     *
     * \return void
     *
     */
    void EliminarUltimoElemento();



    /** \brief Elimina el elemento en la posición indicada de la lista enlazada.
     *
     * \param pos int - La posición del elemento a eliminar.
     * \return void
     *
     */
    void EliminarEnPosicion(unsigned int pos);

    /** \brief Vacía la lista enlazada.
     *
     * \return void
     *
     */
    void Vaciar();


    /** \brief Verifica si la lista enlazada está vacía.
     *
     * \return bool - true si la lista está vacía, false en caso contrario.
     *
     */
    bool EstaVacia() const;


    /** \brief Sobrecarga del operador [] para obtener el elemento en la posición dada
     *
     * \param pos int, posición del elemento a obtener
     * \return T, el elemento en la posición dada
     *
     */
    T operator[](unsigned int pos) const;


    /** \brief Sobrecarga del operador [] para obtener una referencia al elemento en la posición dada
     *
     * \param pos int, posición del elemento a obtener
     * \return T&, referencia al elemento en la posición dada
     *
     */
    T& operator[](int unsigned pos);


    /** \brief Imprime en consola los elementos de la lista
     *
     * \return void
     *
     */
    void Imprimir() const;


    /** \brief Obtiene el tamaño actual de la lista
     *
     * \return unsigned int, el tamaño actual de la lista
     *
     */
    unsigned int ObtenerTam() const;

    /** \brief Excepción lanzada cuando se intenta realizar una operación en una lista vacía
     *
     */
    struct ListaVacia : public std::exception
    {
        const char *what() const noexcept override;
    };


    /** \brief Excepción lanzada cuando se intenta acceder a un elemento fuera del rango de la lista
     *
     */
    struct FueraDeRango : public std::exception
    {
        const char *what() const noexcept override;
    };

private:
    /**
     * Tamaño de la lista
     */
    unsigned int tam;

    /**
     * Puntero al último y primer elemento de la lista, ambos están enlazados y tienen valores
     */
    struct Elemento
    {
        explicit Elemento(T v, Elemento *sig = nullptr) : valor(v), siguiente(sig)
        {};
        T valor;
        Elemento *siguiente = nullptr;
    } *ultimo, *primero;
};

#include "ListaEnlazadaSimple.tpp"

#endif // LISTAENLAZADASIMPLE_H_INCLUDED
