#include "Menu.h"
#include <cstdlib>
#include <iostream>
#include "Utileria.h"

int Menu()
{
    int op;
    do{
        std::system("cls");
        std::cout << "Calculadora de Combinatoria" << std::endl << std::endl;
        std::cout << SALIR << ") Salir de la calculadora" << std::endl;
        std::cout << FACT  << ") Calcular el factorial de un n\243mero" << std::endl;
        std::cout << COMB  << ") Calcular las combinaciones de n en r" << std::endl;
        std::cout << PERM  << ") Calcular las permutacines de n es r" << std::endl;

        op = CapturarEntero("\nElija una opci\242n: ");
    }while(op < SALIR || op > PERM);
    return op;
}
