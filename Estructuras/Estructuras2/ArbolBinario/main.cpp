#include <iostream>
#include <cstdlib>

#include "ABB.h"

using namespace std;

int main()
{
    ArbolBinBusqueda arbol;

    cout << "Agregando valores al arbol" << endl;
    arbol.Agregar(25);
    arbol.Imprimir();
    cout << endl;
    arbol.Agregar(10);
    arbol.Imprimir();
    cout << endl;
    arbol.Agregar(2);
    arbol.Imprimir();
    cout << endl;
    arbol.Agregar(34);
    arbol.Imprimir();

    cout << "\n\n";
    system("pause");
    return 0;
}
