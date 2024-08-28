#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

/** \brief Conjunto de opciones del programa
 * Descripción extensa...
 */
enum {
    SALIR,  /// Opción para terminar el programa
    FACT,   /// Opción para calcular el factorial de un número
    COMB,   /// Opción para calcular las combinaciones de n en r
    PERM    /// Opción para calcular las permutaciones de n en r
};

/** \brief Captura la opción elegida por el usuario
 * Presenta las opciones del menú al usuario, captura la opción,
 * la valida y la devuelve
 *
 * \return La opción elegida por el usuario
 */
int Menu();


#endif // MENU_H_INCLUDED
