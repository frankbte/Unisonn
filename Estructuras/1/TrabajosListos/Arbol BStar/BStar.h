#ifndef BSTAR_H_INCLUDED
#define BSTAR_H_INCLUDED

#include <cstddef>
#include <iostream>
#include <cstring>
#include <cmath>

/**
 * Variable global, configuraci�n del n�mero m�ximo
 * de elementos por nodo del �rbol.
 */
const long ELEMENTOS_POR_NODO = 4;

/**
 * Definici�n de la estructura nodo de �rbol B*.
 * @tparam TLlave El tipo de las llaves por guardar en el nodo.
 * @tparam TValor El tipo de los valores asociados a las llaves.
 */
template <typename TLlave, typename TValor>
struct s_nodo_arbol {
    /**
     * Indica si es un nodo hoja.
     */
    bool es_hoja;
    /**
     * N�mero de llaves actualmente utilizadas en el nodo.
     */
    int cantidad_llaves_guardadas;
    /**
     * Arreglo fijo de las llaves guardadas.
     * @note Capacidad m�xima de ELEMENTOS_POR_NODO.
     */
    TLlave llaves[ELEMENTOS_POR_NODO];
    /**
     * Arreglo fijo de los valores guardados.
     * @note Capacidad m�xima de ELEMENTOS_POR_NODO.
     */
    TValor valores[ELEMENTOS_POR_NODO];
    /**
     * Punteros a los nodos disponibles, union para compartir el mismo
     * espacio de almacenamiento, consume memoria como el elemento m�s
     * grande en la uni�n.
     */
    union {
        /**
         * Puntero a un arreglo fijo de hijos.
         * @note Capacidad m�xima de ELEMENTOS_POR_NODO + 1.
         */
        s_nodo_arbol* hijos[ELEMENTOS_POR_NODO + 1];
        /**
         * Puntero al siguiente nodo en la estructura.
         */
        s_nodo_arbol* siguiente;
    };
    /**
     * Constructor por default.
     */
    s_nodo_arbol();
};

/**
 * Definici�n de la clase �rbol B*.
 * @tparam TLlave El tipo de las llaves para acceder a los elementos.
 * @tparam TValor El tipo de los valores guardados.
 */
template <typename TLlave, typename TValor>
class BStarTree {
private:
    /**
     * Puntero al nodo ra�z del �rbol.
     */
    s_nodo_arbol<TLlave, TValor>* raiz;
    /**
     * Funci�n de utiler�a: Separa un nodo hijo del padre solicitado.
     * @param[out] padre Puntero al nodo padre.
     * @param hijo_indice �ndice del nodo hijo por separar.
     */
    void separar_hijo(s_nodo_arbol<TLlave, TValor>* padre, int hijo_indice);
    /**
     * Funci�n de utiler�a: Agrega una nueva llave a un nodo no lleno.
     * @param[out] nodo Puntero al nodo no lleno donde se agregar� la llave.
     * @param[in] llave Referencia a la llave por agregar.
     * @param[in] value �ndice del nodo hijo por separar.
     */
    void agregar_no_lleno(s_nodo_arbol<TLlave, TValor>* nodo, const TLlave& llave, const TValor& valor);
    /**
     * Funci�n de utiler�a: Elimina una llave partiendo de un nodo dado.
     * @param[out] nodo Puntero al nodo no lleno donde se agregar� la llave.
     * @param[in] llave Referencia a la llave por agregar.
     */
    void eliminar_llave(s_nodo_arbol<TLlave, TValor>* nodo, const TLlave& llave);
    /**
     * Funci�n de utiler�a: Combina los nodos proporcionados a uno solo.
     * @param[out] izquierda Puntero al nodo de la izquierda.
     * @param[out] derecha Puntero al nodo de la derecha.
     * @param indice Referencia a la llave por agregar.
     */
    void combinar_nodos(s_nodo_arbol<TLlave, TValor>* izquierda, s_nodo_arbol<TLlave, TValor>* derecha, int indice);
    /**
     * Funci�n de utiler�a: Ajusta un nodo hijo a tener (ELEMENTOS_POR_NODO / 2) llaves.
     * @param[out] padre Puntero al nodo padre.
     * @param hijo_indice �ndice del nodo hijo.
     */
    void ajustar_hijo(s_nodo_arbol<TLlave, TValor>* padre, int hijo_indice);
    /**
     * Funci�n de utiler�a: Busca un nodo en el �rbol por llave.
     * @param[out] nodo Puntero al nodo considerado como ra�z.
     * @param[in] llave Referencia a la llave a buscar.
     */
    bool buscar_nodo(s_nodo_arbol<TLlave, TValor>* nodo, const TLlave& llave);

public:
    /**
     * Constructor por default.
     */
    BStarTree();
    /**
     * TODO: NO IMPLEMENTADO
     * Constructor de copias.
     */
    BStarTree(const BStarTree<TLlave, TValor> &arbol);
    /**
     * TODO: NO IMPLEMENTADO
     * Destructor de la instancia.
     */
    ~BStarTree();
    /**
     * Agrega un nuevo par de llave-valor al �rbol.
     * @param[in] llave Referencia a la llave por agregar.
     * @param[in] value Referencia al valor a asociar a la llave.
     */
    void Agregar(const TLlave& llave, const TValor& value);
    /**
     * Elimina un elemento del �rbol por llave.
     * @param[in] llave Referencia a la llave por eliminar.
     */
    void Eliminar(const TLlave& llave);
    /**
     * Busca e indica si el �rbol contiene un elemento asociado
     * a la llave proporcionada.
     * @param[in] llave Referencia a la llave por buscar.
     */
    bool Buscar(const TLlave& llave);
    /**
     * TODO: NO IMPLEMENTADO
     * Sobrecarga de operador igual (=).
	 * @param[in] arbol Valor a asignar.
	 * @return Instancia actual.
	 */
	BStarTree<TLlave, TValor> &operator=(const BStarTree<TLlave, TValor> &arbol);
};

#endif // BSTAR_H_INCLUDED
