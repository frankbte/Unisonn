#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

/** \class Pila
 * Plantilla de Pila que nos permite hacer pilas de distintos tipos de elementos.
 *  Es redimensionable, tiene como atributos la capacidad, tope y tiene un arreglo de elementos donde
 *  guradan todos datos de la pila.
 */

template <typename T>
class Pila{
public:
    /** \brief Constructor por default.
     */
    Pila();
    /** \brief Destructor de la Pila.
     */
    ~Pila();
    /** \brief Constructor de copias.
     */
    Pila( const Pila & p);
    Pila& operator= (const Pila& p);
    /** \brief Permite agregar un elemento a la pila
     * \param Recibe un valor de tipo entero que sera el elemento a agregar
     */
    void Apilar(T valor);
    /** \brief Permite eliminar un elemento de la pila
     * \exception lanza una excepcion cuando se quiere sacar un elemento de una pila vacia
     */
    void Desapilar();
    /** \brief Da a conocer el elemento que se encuentra en el tope de la pila
     *
     * \return El elemento en el tope
     *
     * \exception Pila::PilaVacia. Cuando la pila esta vacia
     */
    T ElementoTope() const;
    /** \brief Da a conocer el numero de elementos en la pila
     *
     */
    bool EstaLlena() const;
    /** \brief Da a conocer si la pila no tiene elementos
     *
     * \return true si la pila esta vacia; false si hay espacio en la pila
     */
    bool EstaVacia() const;
    /** \brief Elimina todos los elemtos de la pila
     *
     */
    void VaciarPila();
    /** \brief Imprime los elementos que se encuantran en la pila. Desde el tope hasta el fondo
     */
    void Imprimir() const;
    /** \brief Devuelve un entero con la cantidad de elementos en la pila
     * \return Entero con los elementos de la pila
     *
     */
    int ObtenerElementos();

private:
    int capacidad, tope;  /** Capacidad indica la capacidad base de la pila; tope indica el ultimo numero que fue agregado a la pila **/
    int  *elemento;
    /** \brief Permite añadir elementos a la pila, aunque se sobrepase del tamaño base de la pila
     */
    void Redimensionar(); /** Cambia la capacidad de la pila al doble **/
};

#include "Pila.tpp"


#endif // PILA_H_INCLUDED
