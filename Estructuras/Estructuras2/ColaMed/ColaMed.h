#ifndef COLAMED_H_INCLUDED
#define COLAMED_H_INCLUDED

#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <windows.h>
#include <ctime>

class Cola{
public:
    /**
     * @brief Constructor por defecto de la clase Cola.
     */
    Cola();
    /**
     * @brief Destructor de la clase Cola.
     */
    ~Cola();
    /**
     * @brief Operador de asignaci�n de la clase Cola.
     *
     * @param c Objeto de tipo Cola a asignar.
     * @return Referencia al objeto de tipo Cola.
     */
    void Encolar(std::string valor);
    /**
     * @brief Desencola el primer elemento de la cola.
     */
    void Desencolar();
    /**
     * @brief Obtiene el tama�o actual de la cola.
     *
     * @return Tama�o de la cola.
     */
    int ObtenerTam();
    /**
     * @brief Obtiene el primer elemento de la cola.
     *
     * @return Primer elemento de la cola.
     */
    std::string ObtenerPrimero();
    /**
     * @brief Verifica si la cola est� vac�a.
     *
     * @return true si la cola est� vac�a, false en caso contrario.
     */
    bool EstaVacia();
    /**
     * @brief Vac�a la cola.
     */
    void Vaciar();
    /**
     * @brief Imprime los elementos de la cola.
     */
    void Imprimir();
private:
    int tam; ///< Tama�o de la cola.
    struct Elemento{
        std::string valor; ///< Valor almacenado en el elemento.
        Elemento *siguiente; ///< Puntero al siguiente elemento.
    }*primero, *ultimo; ///< Punteros al primer y �ltimo elemento de la cola.

};


#endif // COLAMED_H_INCLUDED
