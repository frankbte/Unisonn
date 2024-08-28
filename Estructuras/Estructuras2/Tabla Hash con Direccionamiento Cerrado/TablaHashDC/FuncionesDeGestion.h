#ifndef FUNCIONESDEGESTION_H_INCLUDED
#define FUNCIONESDEGESTION_H_INCLUDED

#include <iostream>
#include <limits>
#include <conio.h>
#include <windows.h>

#include "TablaHashDC.h"
#include "Utilerias.h"


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
 * \brief Imprime en pantalla las estad�sticas de la tabla hash.
 * \param tabla La tabla hash de la cual se obtendr�n las estad�sticas.
 */
void ImprimirEstadisticas(const TablaHashDC& tabla);

/**
 * \brief Copia una tabla hash en otra.
 * \param tablaA La tabla hash que se copiar�.
 * \param tablaB La tabla hash donde se realizar� la copia.
 */
void CopiarTabla(TablaHashDC& tablaA, TablaHashDC& tablaB);

/**
 * \brief Restaura la �ltima copia de la tabla hash.
 * \param tablaA La tabla hash que se restaurar�.
 * \param tablaB La tabla hash desde la cual se restaurar� la copia.
 */
void RestaurarUltimaCopia(TablaHashDC& tablaA, TablaHashDC& tablaB);

/**
 * \brief Vacia la tabla hash.
 * \param tabla La tabla hash que se vaciar�.
 * \return true si se vaci� la tabla correctamente, false si la tabla ya estaba vac�a.
 */
bool VaciarTabla(TablaHashDC& tabla);

#endif // FUNCIONESDEGESTION_H_INCLUDED
