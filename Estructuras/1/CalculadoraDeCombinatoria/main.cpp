#include <iostream>
#include <cstdlib>

#include "Combinatoria.h"
#include "Utileria.h"
#include "Menu.h"

using namespace std;
int main()
{
    int opcion;
    int n, r;

    do{
        opcion = Menu();

        if(opcion == SALIR) continue;

        do{
            n = CapturarEntero("n: ");
        }while (n < 0 || n > MAXFACT);

        if(opcion != FACT){
            do{
                r = CapturarEntero("r: ");
            }while (r < 0 || r > n);
        }

        switch(opcion){
            case FACT:
                cout << n << "! = " << CalcularFactorial(n) << endl;
                break;
            case COMB:
                cout << "C(" << n << "," << r << ") = " << CalcularCombinaciones(n,r) << endl;
                break;
            case PERM:
                cout << "P(" << n << "," << r << ") = " << CalcularPermutaciones(n,r) << endl;
        }

        system("pause");

    }while(opcion != SALIR);

	return 0;
}
