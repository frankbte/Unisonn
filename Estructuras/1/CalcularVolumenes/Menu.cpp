#include "Menu.h"
#include <cstdlib>
#include <iostream>
#include "Utileria.h"

int Menu()
{
    int opcion;
    do{
        std::system("cls");
        std::cout << "Calculadora de volumen con funciones " << std::endl;
        std::cout << SALIR << ")para salir" << std::endl;
        std::cout << ESFERA << ") Volumen de esfera" << std::endl;
        std::cout << CUBO << ") Volumen cubo" << std::endl;
        std::cout << PIRAMIDE << ") Volumen piramide cuadrangular" << std::endl;
        std::cout << CILINDRO << ") Volumen de un cilindro" << std::endl;

        opcion = CapturarEntero("Elija una opcion: ");

        if(opcion < SALIR || opcion > CILINDRO){
            std::cout << "Valor no permitido" <<std::endl;
            std::system("pause");
        }
    }while(opcion < SALIR || opcion > CILINDRO);
    return opcion;
}
