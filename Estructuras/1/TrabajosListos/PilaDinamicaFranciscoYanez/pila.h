/**
 * \file pila.h
 * Archivo que contiene la definicion de una clase tipo Pila de valores enteros (int)
 * \author Francisco Yanez Bustamante
 * \date 2023
*/

#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED


/** \class Pila
 *
 * Estructura de datos tipo LIFO, puede contener elementos de tipo int
 * El tamaño del arreglo es redimensionable, se expande cuando se necesita.
 *
 */


class Pila{
public:
    /** \brief Constructor por default. Construye una pila vacia
     */
    Pila();
    ~Pila();
    Pila(const Pila & p);
    Pila& operator = (const Pila& p);
    /** \brief Permite agregar un nuevo elemento en la pila
     *
     * \param valor Elemento a agregar
     *
     * \exception Pila::PilaLlena. Cuando la pila esta llena
     */
    void Agregar(int valor);
    /** \brief Permite sacar un nuevo elemento en la pila
     *
     * \exception Pila::Sacar. Cuando se quieran sacar elementos y la pila este vacia
     */
    void Sacar();
    /** \brief Permite saber si la pila esta llena
     * Escepcion lanzada cuando se intente agregar elementos en una pila llena
     */
    bool EstaLlena() const;
    /** \brief  Permite saber si la pila esta vacia
     * Escepcion lanzada cuando se intente acceder a los elementos de una pila vacia
     */
    bool EstaVacia() const;
    /** \brief Permite vaciar los elementos de la pila, (eliminar todos los elementos)
     */
    void Vaciar();
    int Tam() const;
    int Tope() const;
    void Imprimir() const;
    //bool EstaBienEscrita(string expresion);

private:
    void Redimensionar();
    int capacidad, tope;
    int *elemento;


};


#endif // PILA_H_INCLUDED
