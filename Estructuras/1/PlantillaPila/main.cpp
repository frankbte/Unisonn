    #include <iostream>
    #include "pila.h"

using namespace std;

int main()
{
    try{
        Pila a;
        a.Agregar(1);
        cout << "Pila: ";
        a.Imprimir();
        cout << '\n';
        cout << "Elemento en el tope: " << a.Tope() << endl;
        cout << "Tamaño de la pila: " << a.Tam() << endl;
        a.Agregar(2);
        a.Agregar(3);
        a.Agregar(4);
        cout << "Pila: ";
        a.Imprimir();
        cout << '\n';
        cout << "Elemento en el tope: " << a.Tope() << endl;
        a.Sacar();
        cout << "Pila: ";
        a.Imprimir();





    }catch(const char * msn){

    };

    //char expresion[]= "{a*[b-c/{d-e*{f+g/[([{(([h+i]-j)*k)-m}*n]+0)/p]+q}*r}";





    return 0;
}
