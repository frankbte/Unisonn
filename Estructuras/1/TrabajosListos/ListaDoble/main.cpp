#include <iostream>
#include <cstdlib>
#include <iostream>

#include "Lista.h"

using namespace std;

int main()
{
    Lista lista1;
    cout << "Insertando valor al principio:" << endl;
    lista1.InsertarPrincipio(10);
    lista1.Imprimir();
    cout << "Insertando valor al principio:" << endl;
    lista1.InsertarPrincipio(15);
    lista1.Imprimir();
    cout << "Insertando valor al principio:" << endl;
    lista1.InsertarPrincipio(20);
    lista1.Imprimir();
    cout << "Insertando valor al final:" << endl;
    lista1.InsertarFinal(20);
    lista1.Imprimir();
    cout << "Primer elemento: " << lista1.ObtenerPrimero() << endl;

    cout << "Tamanio de la lista1: " << lista1.Tam() << endl;

    cout << "Eliminando valor del principio de la lista..." << endl;
    lista1.EliminarPrincipio();
    lista1.Imprimir();
    cout << "Eliminando ultimo valor de la lista..." << endl;
    lista1.EliminarFinal();
    lista1.Imprimir();
    cout << "Imprimiendo en reversa..." << endl;
    lista1.ImprimirReversa();
    lista1.EstaVacia();

    if(lista1.EstaVacia())
    {
        cout << "La lista esta vacia.";
    }
    else
    {
        cout << "La lista no esta vacia... \n";
    }

    cout << "Vaciando lista..." << endl;
    lista1.Vaciar();
    lista1.Imprimir();
    cout << endl;
    /*cout << "Modificando elemento en indice 1" << endl;
    lista1.Modificar(1,55);
    lista1.Imprimir();
    cout << endl;
    cout << "Buscando el valor 55..." << endl;
    int indice = lista1.BuscarValor(55);
    if(indice != -1){
        cout << "El valor se ha encontrado en la lista";
    }else{
        cout << "El valor no se ha encontrado en la lista...";
    }

    */
    return 0;
}
