#include "Lista.h"

/**
 * \file pila.h
 * Archivo que contiene la definicion de una clase tipo Pila de valores enteros (int)
 * \author Francisco Yanez Bustamante
 * \date 2023
*/

#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

/** \class Pila
 * Estructura de datos tipo LIFO: ultimo en entrar, primero en salir. Puede contener elementos de tipo int.
 * Tiene un tamaño redimensionable, es decir, el arreglo se expande para aceptar nuevos elementos
 */
class Pila{
public:
    /** \brief Constructor por default. Construye una pila vacia
     */
    //Pila();
    /** \brief Destructor de la Pila.
     */
    //~Pila();
    /** \brief Constructor de copias. Construye una copia de una pila al llamarlo mediante una instancia
     */
    //Pila( const Pila & p);
    //Pila& operator= (const Pila& p);
    /** \brief Permite agregar un elemento a la pila
     * \param Recibe un valor de tipo entero que sera el elemento a agregar
     */
    void Apilar(int valor);
    /** \brief Permite eliminar un elemento de la pila
     * \exception lanza una escepcion cuando se quiere sacar un elemento de una pila vacia
     */
    void Desapilar();
    /** \brief Da a conocer el elemento que se encuentra en el tope de la pila
     *
     * \return El elemento en el tope
     *
     * \exception Pila::PilaVacia. Cuando la pila esta vacia
     */
    int ElementoTope();
    /** \brief Da a conocer el numero de elementos en la pila
     *
     */
    //bool EstaLlena() const;
    /** \brief Da a conocer si la pila no tiene elementos
     *
     * \return true si la pila esta vacia; false si hay espacio en la pila
     */
    bool EstaVacia();
    /** \brief Elimina todos los elemtos de la pila
     *
     */
    void VaciarPila();
    /** \brief Imprime los elementos que se encuantran en la pila. Desde el tope hasta el fondo
     */
    void Imprimir();

private:
    Lista contenedor;
};

#endif // PILA_H_INCLUDED
