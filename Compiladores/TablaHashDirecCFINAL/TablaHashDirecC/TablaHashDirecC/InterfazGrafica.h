#ifndef INTERFAZGRAFICA_H_INCLUDED
#define INTERFAZGRAFICA_H_INCLUDED

#include <iostream> //std::cout;
#include <string>   //Argumento de m�todos.
#include <conio.h> //getch();
#include <Windows.h> //Sleep();

//********************** ENUMERACI�N.

/** \brief Opciones del men� inicial. */
enum posicion {AGREGAR_ENTRADA, AGREGAR_RANDOM, ELIMINAR_ENTRADA, VACIAR_TABLA, MODIFICAR_ENTRADA, IMPRIMIR_TABLA, SALIR};

//********************** M�TODOS.

/** \brief Muestra las opciones del men� inicial.
 *  \return Opci�n seleccionada por el usuario.
*/
int menuInicio();

//***************
/** \brief Escribe el texto en el centro de la consola; desde ah�, permite desplazarlo en horizontal y vertical.
 *  \param texto, es la cadena que se imprimir� en el centro de la consola.
 *  \param desplazamientoHorizontal, tomando el centro como origen, permite desplazar el texto en el eje X.
 *  \param desplazamientoVertical, tomando el centro como origen, permite desplazar el texto en el eje Y.
*/
void imprimirTexto(const std::string& texto, int desplazamientoHorizontal = 0, int desplazamientoVertical = 0);

//***************
/** \brief Obtiene la longitud de una cadena.
 *  \param cadena, cadena la cual se medir�.
 *  \return n�mero de elementos en la cadena.
*/
int longitudTexto(std::string cadena);

//***************
/** \brief
 *
*/
bool continuarOperacion(const std::string& cadena, int x = 0, int y = 0);

//***************
/** \brief Establece si el curso se muestra o no.
 *  \param visible, true para mostrar el cursor; false para ocultarlo.
 */
void visibilidadCursor(bool visible);

#endif // INTERFAZGRAFICA_H_INCLUDED
