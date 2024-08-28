#include "Utileria.h"
#include <limits>
#include <cstdlib>
#include <iostream>

int CapturarEntero( const char solicitud[])
{
    float num;
    std::cout << solicitud;
    std::cin >> num;
    while(std::cin.fail() || num != (int)num){
        std::cout << "Error... No es un numero entero" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<int>::max(), '\n');
        std::cout << solicitud;
        std::cin >> num;
    }
    return num;
}

float CapturarReal()
{
    float num;

    std::cin >> num;
    while(std::cin.fail()){
        std::cout << "Error... No es un numero" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<int>::max(), '\n');
        std::cout << "Introduzca un numero entero: ";
        std::cin >> num;
    }
    return num;
}
