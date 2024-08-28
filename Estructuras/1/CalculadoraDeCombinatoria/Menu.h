#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

/** \brief Conjunto de opciones del programa
 * Descripci�n extensa...
 */
enum {
    SALIR,  /// Opci�n para terminar el programa
    FACT,   /// Opci�n para calcular el factorial de un n�mero
    COMB,   /// Opci�n para calcular las combinaciones de n en r
    PERM    /// Opci�n para calcular las permutaciones de n en r
};

/** \brief Captura la opci�n elegida por el usuario
 * Presenta las opciones del men� al usuario, captura la opci�n,
 * la valida y la devuelve
 *
 * \return La opci�n elegida por el usuario
 */
int Menu();


#endif // MENU_H_INCLUDED
