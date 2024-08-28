#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

/**
 * @brief Implementación de una lista simple.
 *
 * @tparam T Tipo de datos de los elementos almacenados en la lista.
 */
template<typename T>
class Lista{
public:
    /**
     * @brief Constructor por defecto de la clase Lista.
     */
    Lista();

    /**
     * @brief Destructor de la clase Lista.
     */
    ~Lista();

    /**
     * @brief Constructor de copia de la clase Lista.
     *
     * @param l Lista a ser copiada.
     */
    Lista(const Lista<T> &l);

    /**
     * @brief Agrega un elemento al final de la lista.
     *
     * @param valor Valor del elemento a ser agregado.
     */
    void AgregarAlFinal(T valor);

    /**
     * @brief Elimina el primer elemento de la lista.
     */
    void EliminarDeInicio();

    /**
     * @brief Elimina el último elemento de la lista.
     */
    void EliminarDeFinal();

    /**
     * @brief Elimina el elemento en un índice específico de la lista.
     *
     * @param indice Índice del elemento a ser eliminado.
     */
    void EliminarEnIndice(int indice);

    /**
     * @brief Verifica si la lista está vacía.
     *
     * @return Verdadero si la lista está vacía, falso en caso contrario.
     */
    bool EstaVacia();

    /**
     * @brief Obtiene el tamaño de la lista.
     *
     * @return Tamaño de la lista.
     */
    int Tamano();

    /**
     * @brief Vacía la lista, eliminando todos sus elementos.
     */
    void Vaciar();

    /**
     * @brief Imprime los elementos de la lista en orden.
     */
    void Imprimir();

    T operator[](unsigned int pos) const;

    T& operator[](int unsigned pos);

    struct ListaVacia : public std::exception
    {
        const char *what() const noexcept override;
    };

    struct FueraDeRango : public std::exception
    {
        const char *what() const noexcept override;
    };

    /**
     * @brief Sobrecarga del operador de indexación [] para acceder a un elemento de la lista mediante un índice.
     * @param indice Índice del elemento a acceder.
     * @return Referencia al elemento en la posición indicada.
     */
    T& operator[](int indice);

    /**
     * @brief Sobrecarga del operador de indexación [] constante para acceder a un elemento de la lista mediante un índice.
     * @param indice Índice del elemento a acceder.
     * @return Referencia constante al elemento en la posición indicada.
     */
    const T& operator[](int indice) const;

    /**
     * @brief Sobrecarga del operador de asignación = para copiar una lista en otra.
     * @param otraLista Lista a copiar.
     * @return Referencia a la lista actual después de la copia.
     */
    Lista<T>& operator=(const Lista<T>& otraLista);

private:
    int tam;
    struct Elemento{
        T valor;
        Elemento *siguiente;
    }*primero, *ultimo;
};

#include "Lista.tpp"

#endif // LISTA_H_INCLUDED
