#include <iostream>
#include "ListaCompuesta.h"

using namespace std;

int main()
{
    ListaCompuesta<int> lista, lista2, lista3;
    lista.Agregar(5);
    lista.Agregar(1);
    lista.Agregar(5);
    lista.Agregar(3);
    cout << "Lista 1 en orden ascendente: " << endl;
    lista.ImprimirAscendente();
    cout << "Eliminamos un elemento:" << endl;
    lista.Eliminar(5);
    cout << "Lista 1: " << endl;
    lista.ImprimirAscendente();
    cout << "Lista 1 en orden descendente: " << endl;
    lista.ImprimirDescendente();
    lista2.Agregar(20);
    lista2.Agregar(2);
    lista2.Agregar(4);
    cout << "Lista 2 en orden ascendente: " << endl;
    lista2.ImprimirAscendente();
    cout << "Mezclamos las 2 listas: " << endl;
    lista3 = lista.Mezclar(lista2);
    cout << "Lista mezclada: " << endl;
    lista3.ImprimirAscendente();
    return 0;
}
