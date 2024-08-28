#include <iostream>
#include "pila.h"
using namespace std;

int main()
{
    try{
        Pila p;
        p.Apilar(1);
        p.Apilar(2);
        p.Apilar(3);
        p.Apilar(4);
        p.Apilar(5);
        p.Apilar(6);
        p.Apilar(7);
        p.Apilar(8);
        p.Apilar(9);
        p.Apilar(10);
        p.Apilar(11);
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
