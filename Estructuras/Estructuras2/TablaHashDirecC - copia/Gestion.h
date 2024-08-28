#ifndef GESTION_H_INCLUDED
#define GESTION_H_INCLUDED

#include <iostream>
#include <limits>
#include <conio.h>
#include <windows.h>

#include "TablaHash.h"
#include "utilerias.h"

/**
 * \brief Muestra el men� de inicio y permite seleccionar una opci�n.
 * \return El n�mero de la opci�n seleccionada.
 */
int MenuDeInicio();

/**
 * \brief Permite agregar elementos a la tabla hash.
 * \param tabla La tabla hash donde se agregar�n los elementos.
 */
void AgregarElementos(TablaHashDC& tabla);

/**
 * \brief Permite eliminar elementos de la tabla hash.
 * \param tabla La tabla hash de la cual se eliminar�n los elementos.
 */
void EliminarElementos(TablaHashDC& tabla);

/**
 * \brief Permite buscar elementos en la tabla hash.
 * \param tabla La tabla hash en la cual se buscar�n los elementos.
 */
void BuscarElementos(TablaHashDC& tabla);

/**
 * \brief Imprime en pantalla la tabla hash.
 * \param tabla La tabla hash que se imprimir�.
 */
void ImprimirTabla(TablaHashDC& tabla);

/**
 * \brief Vacia la tabla hash.
 * \param tabla La tabla hash que se vaciar�.
 * \return true si se vaci� la tabla correctamente, false si la tabla ya estaba vac�a.
 */
bool VaciarTabla(TablaHashDC& tabla);

#endif // GESTION_H_INCLUDED
