#ifndef TABLAHASHDC_H_INCLUDED
#define TABLAHASHDC_H_INCLUDED

#include <iostream>
#include <string>
#include "ListaEnlazadaSimple.h"
#include "utilerias.h"

/**
 * \class TablaHashDC
 * \brief Clase que representa una tabla hash con resoluci�n de colisiones mediante direccionamiento cerrado.
 *
 * La clase TablaHashDC implementa una tabla hash utilizando el m�todo de direccionamiento cerrado.
 * Cuando se produce una colisi�n, los elementos con el mismo �ndice se acomodan en una lista enlazada.
 * Esto permite almacenar m�ltiples elementos en la misma posici�n de la tabla, evitando colisiones y
 * garantizando un acceso eficiente a los elementos.
 *
 * La clase TablaHashDC permite insertar y eliminar elementos, buscar elementos por su clave, obtener el n�mero
 * de elementos almacenados y m�s. Adem�s, proporcionaoperaciones de redimensionamiento de la tabla para mantener
 * un factor de carga adecuado y un acceso eficiente a los elementos.
 *
 */


/**
 * \struct Elemento
 * \brief Estructura que representa un elemento de la tabla hash.
 */
struct Elemento
{
    std::string Nombre; /**< Nombre del elemento */
    int Id; /**< Identificador del elemento */
};

/**
 * \class TablaHashDC
 * \brief Clase que representa una tabla hash con resoluci�n de colisiones mediante direccionamiento abierto y doble dispersi�n.
 */
class TablaHashDC
{
public:
    /**
     * \brief Constructor de la clase TablaHashDC.
     * \param capacidad La capacidad inicial de la tabla hash.
     */
    TablaHashDC(int capacidad);

    /**
     * \brief Constructor de copia de la clase TablaHashDC.
     * \param otraTabla La tabla hash a copiar.
     */
    TablaHashDC(const TablaHashDC& otraTabla);

    /**
     * \brief Operador de asignaci�n de la clase TablaHashDC.
     * \param otraTabla La tabla hash a asignar.
     * \return Una referencia a la tabla hash actualizada.
     */
    TablaHashDC& operator=(const TablaHashDC& otraTabla);

    /**
     * \brief Destructor de la clase TablaHashDC.
     */
    ~TablaHashDC();

    /**
     * \brief Inserta un elemento en la tabla hash.
     * \param elemento El elemento a insertar.
     */
    void InsertarElemento(const Elemento& elemento);

    /**
     * \brief Elimina un elemento de la tabla hash por su matr�cula.
     * \param matricula La matr�cula del elemento a eliminar.
     */
    void EliminarElemento(int matricula);

    /**
     * \brief Vac�a la tabla hash, eliminando todos los elementos.
     */
    void VaciarTabla();

    /**
     * \brief Imprime los elementos de la tabla hash.
     */
    void ImprimirTabla() const;

    /**
     * \brief Obtiene el nombre de un elemento por su matr�cula.
     * \param matricula La matr�cula del elemento.
     * \return El nombre del elemento.
     */
    std::string ObtenerNombreElemento(int matricula) const;

    /**
     * \brief Obtiene el n�mero de elementos en la tabla hash.
     * \return El n�mero de elementos.
     */
    int ObtenerNumeroDeElementos() const;

    /**
     * \brief Verifica si la tabla hash est� vac�a.
     * \return true si la tabla est� vac�a, false en caso contrario.
     */
    bool EstaVacia() const;

    /**
     * \brief Busca un elemento en la tabla hash por su matr�cula.
     * \param matricula La matr�cula del elemento a buscar.
     * \return true si el elemento se encuentra en la tabla, false en caso contrario.
     */
    bool Buscar(int matricula) const;

    /**
     * \brief Obtiene la capacidad actual de la tabla hash.
     * \return La capacidad de la tabla hash.
     */
    int ObtenerCapacidad() const;

    /**
     * \brief Obtiene la lista enlazada correspondiente a un �ndice de la tabla hash.
     * \param indice El �ndice de la tabla hash.
     * \return Una referencia constante a la lista enlazada.
     */
    const ListaEnlazadaSimple<Elemento>& ObtenerListaEnlazada(int indice) const;

private:
    /**
     * \brief Calcula la funci�n hash para una matr�cula.
     * \param matricula La matr�cula del elemento.
     * \return El valor hash calculado.
     */
    int FuncionHash(int matricula) const;

    /**
     * \brief Calcula la segunda funci�n hash para una matr�cula y una capacidad dada.
     * \param matricula La matr�cula del elemento.
     * \param capacidad La capacidad de la tabla hash.
     * \return El valor hash calculado.
     */
    int FuncionHash(int matricula, int capacidad) const;

    /**
     * \brief Redimensiona la tabla hash cuando se alcanza la capacidad m�xima.
     */
    void RedimensionarTabla();

    ListaEnlazadaSimple<Elemento>* tabla; /**< Array de listas enlazadas que almacena los elementos de la tabla hash */
    int Capacidad; /**< Capacidad actual de la tabla hash */
    int CapacidadMaxima; /**< Capacidad m�xima de la tabla hash */
    int NumeroDeElementos; /**< N�mero de elementos en la tabla hash */
};

#endif // TABLAHASHDC_H_INCLUDED
