#include <iostream>
#include <cstdlib>
#include <iostream>
#include "Lista.h"

using namespace std;

int main()
{
    ColaM personitas;
    cout << "Insertando valor al principio:" << endl;
    personitas.InsertarPrincipio(10);
    personitas.Imprimir();
    cout << "Insertando valor al principio:" << endl;
    personitas.InsertarPrincipio(15);
    personitas.Imprimir();
    cout << "Insertando valor al principio:" << endl;
    personitas.InsertarPrincipio(20);
    personitas.Imprimir();

    cout << "Tamanio de la lista1: " << personitas.Tam() << endl;

    personitas.Imprimir();

    personitas.InsertarEnIndice(1, 20);
    personitas.InsertarFinal(50);

    cout << "Tamanio de la lista1: " << personitas.Tam() << endl;

    personitas.Imprimir();
    personitas.EliminarPrincipio();
    personitas.Imprimir();
    personitas.EliminarFinal();
    personitas.Imprimir();
    personitas.EliminarEnIndice(1);
    personitas.Imprimir();
    personitas.EstaVacia();

    if(personitas.EstaVacia())
    {
        cout << "La lista esta vacia.";
    }
    else
    {
        cout << "La lista no esta vacia... \n";
    }

    //cout << "Vaciando lista...";
    //lista1.Vaciar();
    cout << endl;
    personitas.Imprimir();
    cout << endl;
    cout << "Modificando elemento en indice 1" << endl;
    personitas.Modificar(1,55);
    personitas.Imprimir();
    cout << endl;
    cout << "Buscando el valor 55..." << endl;
    int indice = personitas.BuscarValor(55);
    if(indice != -1){
        cout << "El valor se ha encontrado en la lista";
    }else{
        cout << "El valor no se ha encontrado en la lista...";
    }

    return 0;
}
