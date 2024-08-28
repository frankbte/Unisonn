#include "Utileria.h"
#include <iostream>
#include <limits>

//****************************************************************************************

int CapturarEntero(const char solicitud[])
{
    float num;

    std::cout << solicitud;
    std::cin >> num;
    while(std::cin.fail() || num != (int)num){
        std::cout << "Error: No es un n\243mero entero" << std::endl;
        std::cin.clear();	// Restablecer el flujo cin
        std::cin.ignore(std::numeric_limits<int>::max(),'\n');	// Limpia el buffer
        std::cout << solicitud;
        std::cin >> num;
    }
    return num;
}
