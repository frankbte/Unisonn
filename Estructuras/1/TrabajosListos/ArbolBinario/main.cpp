#include <iostream>
#include <cstdlib>
#include <iostream>

#include "Lista.h"

using namespace std;

int main()
{
    ABB arbol;

    arbol.Agregar(5);
    arbol.Agregar(5);
    arbol.Agregar(13);
    arbol.Agregar(20);
    arbol.Agregar(35);
    arbol.Agregar(1);
    arbol.Agregar(2);
    arbol.Agregar(0);


    cout << "Numero de nodos en el arbol: " << arbol.NumeroNodos() << endl;

    cout << "Inorden trasversal..." << endl;
    arbol.InOrden();
    cout << endl;

    cout << "Buscando el valor 4: " << (arbol.Buscar(4) ? "Encontrado" : "No encontrado") << endl;
    cout << "Buscando el valor 5: " << (arbol.Buscar(5) ? "Encontrado" : "No encontrado") << endl;


}
