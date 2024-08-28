#ifndef COLAM_H_INCLUDED
#define COLAM_H_INCLUDED
#include <string>


/**
 * @brief Clase para representar una cola.
 *
 * @tparam T Tipo de datos almacenados en la cola.
 */
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
     * @brief Constructor de copia de la clase Cola.
     *
     * @param c Objeto de tipo Cola a copiar.
     */
    Cola(const Cola &c);
    /**
     * @brief Operador de asignación de la clase Cola.
     *
     * @param c Objeto de tipo Cola a asignar.
     * @return Referencia al objeto de tipo Cola.
     */
    operator=(const Cola &c);
    /**
     * @brief Encola un valor en la cola.
     *
     * @param valor Valor a encolar.
     */
    void Encolar(std::string valor);
    /**
     * @brief Desencola el primer elemento de la cola.
     */
    void Desencolar();
    /**
     * @brief Obtiene el tamaño actual de la cola.
     *
     * @return Tamaño de la cola.
     */
    int ObtenerTam();
    /**
     * @brief Obtiene el primer elemento de la cola.
     *
     * @return Primer elemento de la cola.
     */
    std::string ObtenerPrimero();
    /**
     * @brief Obtiene el último elemento de la cola.
     *
     * @return Último elemento de la cola.
     */
    std::string ObtenerUltimo();
    /**
     * @brief Verifica si la cola está vacía.
     *
     * @return true si la cola está vacía, false en caso contrario.
     */
    bool EstaVacia();
    /**
     * @brief Vacía la cola.
     */
    void Vaciar();
    /**
     * @brief Imprime los elementos de la cola.
     */
    void Imprimir();
private:
    int tam; ///< Tamaño de la cola.
    struct Elemento{
        std::string valor; ///< Valor almacenado en el elemento.
        Elemento *siguiente; ///< Puntero al siguiente elemento.
    }*primero, *ultimo; ///< Punteros al primer y último elemento de la cola.

};


#endif // COLAM_H_INCLUDED
