    #include <iostream>
    #include "pila.h"

using namespace std;

int main()
{
    try{
        Pila a;
        cout << "Pila: ";
        a.Agregar(5);
        a.Agregar(7);
        a.Agregar(6);
        a.Agregar(8);
        a.Agregar(5);
        a.Agregar(7);
        a.Agregar(6);
        a.Agregar(8);
        a.Agregar(8);
        a.Imprimir();
        cout << endl;
        cout << "Sacando un elemento... " << endl;
        cout << "Pila: ";
        a.Sacar();
        a.Imprimir();
        cout << endl;
        cout << "Tope: " ;
        cout << a.Tope();
        cout << endl;
        cout << "Vaciando la Pila... " << endl;
        cout << "Pila: ";
        a.Vaciar();
        a.Imprimir();
        cout << endl;
        a.Sacar();

    }catch(const char * msg)
    {
        cerr << "Error: " << msg << endl;
    }catch(...)
    {
        cerr << "Error inesperado... " << endl;
    }

    system("Pause");
    //char expresion[]= "{a*[b-c/{d-e*{f+g/[([{(([h+i]-j)*k)-m}*n]+0)/p]+q}*r}";

    return 0;
}
