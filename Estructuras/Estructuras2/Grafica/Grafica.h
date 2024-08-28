#ifndef GRAFICA_H_INCLUDED
#define GRAFICA_H_INCLUDED

/**
 * @brief Clase que representa una estructura de datos de gráfica no dirigida.
 */
class Grafica{
public:
    /**
     * @brief Constructor por defecto. Crea una gráfica vacía.
     */
    Grafica();
    /**
     * @brief Constructor de copia. Crea una nueva gráfica copiando los nodos y aristas de otra gráfica.
     * @param g Referencia a la gráfica que se va a copiar.
     */
    Grafica(const Grafica &g);
    /**
     * @brief Destructor. Libera la memoria de todos los nodos y aristas de la gráfica.
     */
    ~Grafica();
    /**
     * @brief Operador de asignación. Asigna los nodos y aristas de otra gráfica a esta gráfica.
     * @param g Referencia a la gráfica que se va a asignar.
     * @return Referencia a esta gráfica después de la asignación.
     */
    Grafica& operator=(const Grafica &g);
    /**
     * @brief Agrega un nodo con el nombre especificado a la gráfica.
     * @param nombre El nombre del nodo a agregar.
     */
    void AgregarNodo(char nombre);
    /**
     * @brief Elimina un nodo con el nombre especificado de la gráfica, junto con todas las aristas que lo conectan.
     * @param nom El nombre del nodo a eliminar.
     */
    void EliminarNodo(char nom);
     /**
     * @brief Elimina todas las aristas adyacentes al nodo con el nombre especificado.
     * @param nom El nombre del nodo cuyas aristas se van a eliminar.
     */
    void VaciarNodo(char nom);
    /**
     * @brief Devuelve el número de nodos en la gráfica.
     * @return El número de nodos en la gráfica.
     */
    int NumNodos();
    /**
     * @brief Busca un nodo con el nombre especificado en la gráfica.
     * @param nom El nombre del nodo a buscar.
     * @return true si se encuentra el nodo, false en caso contrario.
     */
    bool BuscarNodo(char nom);
    /**
     * @brief Devuelve el grado del nodo con el nombre especificado.
     * @param nom El nombre del nodo cuyo grado se desea obtener.
     * @return El grado del nodo, es decir, el número de aristas incidentes en él.
     */
    int Grado(char nom);

    /**
     * @brief Agrega una arista entre los nodos de inicio y fin especificados.
     * @param inicio El nombre del nodo de inicio de la arista.
     * @param fin El nombre del nodo de fin de la arista.
     */
    void AgregarArista(char inicio, char fin);
    /**
     * @brief Elimina la arista entre los nodos de inicio y fin especificados.
     * @param inicio El nombre del nodo de inicio de la arista a eliminar.
     * @param fin El nombre del nodo de fin de la arista a eliminar.
     */
    void EliminarArista(char inicio, char fin);
    /**
     * @brief Comprueba si la gráfica está vacía, es decir, si no tiene nodos.
     * @return true si la gráfica está vacía, false en caso contrario.
     */
    bool EstaVacia();
    /**
     * @brief Devuelve el número de aristas en la gráfica.
     * @return El número de aristas en la gráfica.
     */
    int NumAristas();
    /**
     * @brief Busca una arista entre los nodos de inicio y fin especificados.
     * @param inicio El nombre del nodo de inicio de la arista a buscar.
     * @param fin El nombre del nodo de fin de la arista a buscar.
     * @return true si se encuentra la arista, false en caso contrario.
     */
    bool BuscarArista(char inicio, char fin);
    /**
     * @brief Elimina todos los nodos y aristas de la gráfica.
     */
    void Vaciar();
    /**
     * @brief Imprime el contenido de la gráfica.
     */
    void Imprimir();

private:
    /**
     * @brief Número de nodos en la gráfica.
     */
    int numNodos;
    /**
     * @brief Número de aristas en la gráfica.
     */
    int numAristas;


    /**
     * @brief Estructura que representa un nodo en la gráfica.
     */
    struct Nodo;
    /**
     * @brief Estructura que representa una arista en la gráfica.
     */
    struct Arista{
        Arista(Nodo *ady, Arista *sig = nullptr, Arista *ant = nullptr);
        Nodo * adyacente;
        Arista *siguiente, *anterior;
    };
    struct Nodo{
        /**
         * @brief Constructor de Nodo.
         * @param nom El nombre del nodo.
         * @param sig Puntero al siguiente nodo en la lista de nodos.
         * @param ant Puntero al nodo anterior en la lista de nodos.
         */
        Nodo(char nom, Nodo *sig = nullptr, Nodo *ant = nullptr);
        /**
        * @brief Agrega una arista con el nodo adyacente especificado al nodo actual.
        * @param ady Puntero al nodo adyacente.
        */
        void Agregar(Nodo *ady);
        /**
        * @brief Elimina una arista con el nodo adyacente especificado del nodo actual.
        * @param ady Puntero al nodo adyacente.
        */
        void Eliminar(Nodo *ady);
        /**
        * @brief Comprueba si el nodo está vacío, es decir, si no tiene aristas adyacentes.
        * @return true si el nodo está vacío, false en caso contrario.
        */
        bool EstaVacio();
         /**
        * @brief Comprueba si el nodo es aislado, es decir, si no tiene aristas adyacentes.
        * @return true si el nodo es aislado, false en caso contrario.
        */
        bool esAislado();
        /**
        * @brief Elimina todas las aristas adyacentes al nodo.
        * @return El número de aristas eliminadas.
        */
        int Aislar();
        /**
        * @brief Busca una arista con el nodo adyacente especificado.
        * @param ady Puntero al nodo adyacente.
        * @return Puntero a la arista si se encuentra, nullptr en caso contrario.
        */
        Arista*BuscarDir(Nodo *ady);
        /**
        * @brief El nombre del nodo.
        */
        char nombre;
        /**
        * @brief El grado del nodo, es decir, el número de aristas incidentes en él.
        */
        int grado;
        Arista *primera, *ultima;
        Nodo *siguiente, *anterior;
    }*primero, *ultimo;

    /**
     * @brief Busca un nodo con el nombre especificado en la gráfica.
     * @param nom El nombre del nodo a buscar.
     * @return Puntero al nodo si se encuentra, nullptr en caso contrario.
     */
    Nodo *BuscarDireccion(char nom);
};
#endif // GRAFICA_H_INCLUDED
