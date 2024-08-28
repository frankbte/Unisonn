#include <iostream>
#include "Matriz.h"

using namespace std;

int main()
{
    matriz m1(2,2);
    m1.Capturar();
    m1.Imprimir();

    cout << endl;

    matriz m2(2, 2);
    m2.Capturar();
    m2.Imprimir();

    cout << endl;

    cout << "Sumando la matriz m1 con la matriz m2:" << endl;
    matriz suma = m1 + m2;
    suma.Imprimir();

    cout << endl;

    cout << "Restando la matriz m1 con la matriz m2:" << endl;
    matriz resta = m1 - m2;
    resta.Imprimir();

    cout << endl;

    cout << "Multiplicando la matriz m1 por un escalar:" << endl;
    matriz multi = m1 * 4;
    multi.Imprimir();

    cout << endl;

    cout << "Multiplicando la matriz m1 por la matriz m2" << endl;
    matriz m3 = m1.Multiplicar(m2);
    m3.Imprimir();

    return 0;
}
