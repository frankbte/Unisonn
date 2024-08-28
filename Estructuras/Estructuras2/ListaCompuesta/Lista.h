#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

//Francisco Yanez
//Luis Hiram Hernandez

/**
 * @brief Implementación de una lista doblemente enlazada.
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
     * @brief Agrega un elemento al inicio de la lista.
     *
     * @param valor Valor del elemento a ser agregado.
     */
    void AgregarEnInicio(T valor);

    /**
     * @brief Agrega un elemento al final de la lista.
     *
     * @param valor Valor del elemento a ser agregado.
     */
    void AgregarAlFinal(T valor);

    /**
     * @brief Agrega un elemento en un índice específico de la lista.
     *
     * @param indice Índice en el que se desea agregar el elemento.
     * @param valor Valor del elemento a ser agregado.
     */
    void AgregarEnIndice(int indice, T valor);

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
     * @brief Elimina todas las ocurrencias de un valor específico en la lista.
     *
     * @param valor Valor a ser eliminado de la lista.
     */
    void EliminarPrimeraOcurrencia(T valor);

    /**
     * @brief Busca un valor en la lista y devuelve verdadero si se encuentra, falso en caso contrario.
     *
     * @param valor Valor a ser buscado en la lista.
     * @return Verdadero si el valor se encuentra en la lista, falso en caso contrario.
     */
    bool BuscarValor(T valor);

    /**
     * @brief Busca un valor en la lista y devuelve su índice si se encuentra, -1 en caso contrario.
     *
     * @param valor Valor a ser buscado en la lista.
     * @return Índice del valor si se encuentra, -1 en caso contrario.
     */
    int BuscarPos(T valor);

    /**
     * @brief Verifica si la lista está vacía.
     *
     * @return Verdadero si la lista está vacía, falso en caso contrario.
     */
    bool EstaVacia();

    /**
     * @brief Obtiene el primer elemento de la lista.
     *
     * @return Valor del primer elemento de la lista.
     */
    T ObtenerPrimero();

    /**
     * @brief Obtiene el último elemento de la lista.
     *
     * @return Valor del último elemento de la lista.
     */
    T ObtenerUltimo();

    /**
     * @brief Obtiene el valor del elemento en un índice específico de la lista.
     *
     * @param indice Índice del elemento a ser obtenido.
     * @return Valor del elemento en el índice especificado.
     */
    T ObtenerValorEnIndice(int indice);

    /**
     * @brief Modifica el valor del elemento en un índice específico de la lista.
     *
     * @param indice Índice del elemento a ser modificado.
     * @param nuevoValor Nuevo valor del elemento.
     */
    void ModificarValorEnIndice(int indice, T nuevoValor);

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

    /**
     * @brief Imprime los elementos de la lista en orden inverso.
     */
    void ImprimirReversa();

    /**
     * @brief Ordena los elementos de la lista en orden ascendente.
     */
    void OrdenarAscendente();

    /**
     * @brief Intercambia todos los elementos entre la lista que llama al método y otra lista.
     *
     * @param otraLista Otra lista con la que se intercambiarán los elementos.
     */
    void Intercambiar(Lista<T>& otraLista);

    /**
     * @brief Intercambia los elementos entre dos rangos de índices de la lista que llama al método y otra lista.
     *
     * @param indiceInicio Índice de inicio del rango en la lista que llama al método.
     * @param indiceFin Índice de fin del rango en la lista que llama al método.
     * @param
/**
     * @brief Intercambia los elementos entre dos listas a partir de los índices dados.
     * @param indiceInicio Índice de inicio en la lista actual.
     * @param indiceFin Índice de fin en la lista actual.
     * @param otraLista Otra lista con la cual intercambiar los elementos.
     * @param indiceInicioOtraLista Índice de inicio en la otra lista.
     * @param indiceFinOtraLista Índice de fin en la otra lista.
     */
    void IntercambiarElementos(int indiceInicio, int indiceFin, Lista<T>& otraLista, int indiceInicioOtraLista, int indiceFinOtraLista);

    /**
     * @brief Intercambia los elementos a partir de un índice dado con otra lista.
     * @param indiceInicio Índice de inicio en la lista actual.
     * @param otraLista Otra lista con la cual intercambiar los elementos.
     * @param indiceInicioOtraLista Índice de inicio en la otra lista.
     */
    void IntercambiarElementos2(int indiceInicio, Lista<T>& otraLista, int indiceInicioOtraLista);

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
        Elemento *anterior;
    }*primero, *ultimo;
};

#include "Lista.tpp"

#endif // LISTA_H_INCLUDED
