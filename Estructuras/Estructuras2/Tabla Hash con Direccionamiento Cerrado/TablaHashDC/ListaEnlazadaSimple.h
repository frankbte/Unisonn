#ifndef LISTAENLAZADASIMPLE_H_INCLUDED
#define LISTAENLAZADASIMPLE_H_INCLUDED

#include <iostream>

/**
 * \brief Clase de una lista enlazada simple.
 *
 * Esta clase representa una lista enlazada simple que almacena elementos de tipo gen�rico T.
 * La lista proporciona operaciones para agregar, eliminar, obtener y modificar elementos en diferentes posiciones.
 * Tambi�n ofrece funcionalidades para verificar si la lista est� vac�a, obtener el tama�o de la lista, buscar elementos y m�s.
 *
 * \tparam T El tipo de datos de los elementos almacenados en la lista.
 */

template<typename T>

class ListaEnlazadaSimple
{
public:

    /** \brief Constructor de la lista enlazada simple
     *
     *  Crea una lista enlazada simple vac�a.
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


    /** \brief Operador de asignaci�n de la lista enlazada simple
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


    /** \brief Elimina el �ltimo elemento de la lista enlazada simple
     *
     *  Elimina el �ltimo elemento de la lista enlazada simple y libera la memoria correspondiente.
     *
     * \return void
     *
     */
    void EliminarUltimoElemento();



    /** \brief Elimina el elemento en la posici�n indicada de la lista enlazada.
     *
     * \param pos int - La posici�n del elemento a eliminar.
     * \return void
     *
     */
    void EliminarEnPosicion(unsigned int pos);

    /** \brief Vac�a la lista enlazada.
     *
     * \return void
     *
     */
    void Vaciar();


    /** \brief Verifica si la lista enlazada est� vac�a.
     *
     * \return bool - true si la lista est� vac�a, false en caso contrario.
     *
     */
    bool EstaVacia() const;


    /** \brief Sobrecarga del operador [] para obtener el elemento en la posici�n dada
     *
     * \param pos int, posici�n del elemento a obtener
     * \return T, el elemento en la posici�n dada
     *
     */
    T operator[](unsigned int pos) const;


    /** \brief Sobrecarga del operador [] para obtener una referencia al elemento en la posici�n dada
     *
     * \param pos int, posici�n del elemento a obtener
     * \return T&, referencia al elemento en la posici�n dada
     *
     */
    T& operator[](int unsigned pos);


    /** \brief Imprime en consola los elementos de la lista
     *
     * \return void
     *
     */
    void Imprimir() const;


    /** \brief Obtiene el tama�o actual de la lista
     *
     * \return unsigned int, el tama�o actual de la lista
     *
     */
    unsigned int ObtenerTam() const;

    /** \brief Excepci�n lanzada cuando se intenta realizar una operaci�n en una lista vac�a
     *
     */
    struct ListaVacia : public std::exception
    {
        const char *what() const noexcept override;
    };


    /** \brief Excepci�n lanzada cuando se intenta acceder a un elemento fuera del rango de la lista
     *
     */
    struct FueraDeRango : public std::exception
    {
        const char *what() const noexcept override;
    };

private:
    /**
     * Tama�o de la lista
     */
    unsigned int tam;

    /**
     * Puntero al �ltimo y primer elemento de la lista, ambos est�n enlazados y tienen valores
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
