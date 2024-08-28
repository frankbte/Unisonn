
#include <iostream>
#include <cstdlib>


#include "Arbol.h"
using namespace std;

int main()
{

    ABB<int> arbol;


    arbol.Insertar(45);
    arbol.Insertar(23);
    arbol.Insertar(65);
    arbol.Insertar(2);
    arbol.Insertar(38);
    arbol.Insertar(52);
    arbol.Insertar(96);
    arbol.Insertar(7);
    arbol.Insertar(48);
    cout << "Imprimiendo InOrden: ";
    arbol.ImprimirInOrden();
    cout << endl;
    cout << "Imprimiendo InOrdenInverso: ";
    arbol.ImprimirInOrdenInverso();
    cout << endl;
    cout << "Imprimiendo PostOrden: ";
    arbol.ImprimirPostOrden();
    cout << endl;
    cout << "Imprimiendo PostOrdenInverso: ";
    arbol.ImprimirPostOrdenInverso();
    cout << endl;
    cout << "Imprimiendo PreOrden: ";
    arbol.ImprimirPreOrden();
    cout << endl;
    cout << "Imprimiendo PreOrdenInverso: ";
    arbol.ImprimirPreOrdenInverso();
    cout << endl;



    return 0;
}
