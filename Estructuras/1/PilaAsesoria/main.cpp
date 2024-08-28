#include <iostream>
#include "pila.h"
using namespace std;

int main()
{
    try{
        Pila p;
        p.Apilar('a');
        p.Apilar('b');
        p.Apilar('c');
        p.Apilar('d');
        p.Apilar('e');
        p.Apilar('f');
        p.Apilar('g');
        p.Apilar('h');
        p.Apilar('i');
        p.Apilar('+');

        p.Imprimir();
        cout <<endl;
        cout << "Tope: " << p.ElementoTope() << endl;
        cout << "Sacando un elemento..." << endl;
        p.Desapilar();
        p.Imprimir();
        cout << endl;
        cout << "Vaciando pila..." << endl;
        p.VaciarPila();
        p.Imprimir();
        cout << endl;
        cout << "Conociendo el elemento tope cuando esta vacia..." << endl;
        p.ElementoTope();
        //p.Desapilar();
    }catch(const char *msg)
    {
        cerr << "Error: " << msg << endl;
    }catch(...)
    {
        cerr  << "Error: Error inesperado...";
    }

    system("pause");
    return 0;
}
