#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

/**
 * @brief Implementaci�n de una lista simple.
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
     * @brief Elimina el �ltimo elemento de la lista.
     */
    void EliminarDeFinal();

    /**
     * @brief Elimina el elemento en un �ndice espec�fico de la lista.
     *
     * @param indice �ndice del elemento a ser eliminado.
     */
    void EliminarEnIndice(int indice);

    /**
     * @brief Verifica si la lista est� vac�a.
     *
     * @return Verdadero si la lista est� vac�a, falso en caso contrario.
     */
    bool EstaVacia();

    /**
     * @brief Obtiene el tama�o de la lista.
     *
     * @return Tama�o de la lista.
     */
    int Tamano();

    /**
     * @brief Vac�a la lista, eliminando todos sus elementos.
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
     * @brief Sobrecarga del operador de indexaci�n [] para acceder a un elemento de la lista mediante un �ndice.
     * @param indice �ndice del elemento a acceder.
     * @return Referencia al elemento en la posici�n indicada.
     */
    T& operator[](int indice);

    /**
     * @brief Sobrecarga del operador de indexaci�n [] constante para acceder a un elemento de la lista mediante un �ndice.
     * @param indice �ndice del elemento a acceder.
     * @return Referencia constante al elemento en la posici�n indicada.
     */
    const T& operator[](int indice) const;

    /**
     * @brief Sobrecarga del operador de asignaci�n = para copiar una lista en otra.
     * @param otraLista Lista a copiar.
     * @return Referencia a la lista actual despu�s de la copia.
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
