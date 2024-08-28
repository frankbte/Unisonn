#ifndef FUNCIONESHASH_H_INCLUDED
#define FUNCIONESHASH_H_INCLUDED

#include <iostream>
#include <string>
#include <limits>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unordered_set>

#include "utilerias.h"
#include "TablaHash.h"


int MenuDeInicio();
void AgregarElementos(TablaHashDC& tabla);
void AgregarElementosAleatorios(TablaHashDC& tabla);
void EliminarElementos(TablaHashDC& tabla);
void ImprimirTabla(TablaHashDC& tabla);
bool VaciarTabla(TablaHashDC& tabla);
void ModificarElemento(TablaHashDC& tabla);

#endif // FUNCIONESHASH_H_INCLUDED
