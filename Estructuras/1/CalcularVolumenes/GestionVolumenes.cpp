#include <iostream>
#include "Volumenes.h"
#include <cstdlib>
#include "GestionVolumenes.h"
#include "Utileria.h"



void GestionVolCilindro()
{
    float radio_cilindro, altura_cilindro;
    std::cout << "Ingrese el radio y la altura del cilindro a calcular su volumen" << std::endl;
    std::cout << "Radio: " << std::endl;
    std::cin >> radio_cilindro;
    std::cout << "Altura del cilindro: " << std::endl;
    std::cin >> altura_cilindro ;
    std::cout << "El volumen de un cilindro de radio " << radio_cilindro << " y de altura " << altura_cilindro << " es de : " << CalcularVolCilindro(radio_cilindro, altura_cilindro) << std::endl;
}

void GestionVolCubo()
{
    float lado;
    std::cout << "Introduzca el lado del cubo a calcular su volumen" << std::endl;
    lado = CapturarReal();
    std::cout << "El volumen del cubo de lado " << lado << " es: " << CalcularVolCubo(lado) << std::endl;
}

void GestionVolEsfera()
{
    float radio;
    std::cout << "Introduzca el radio de la esfera a calcular su volumen" << std::endl;
    std::cin >> radio ;
    std::cout << "El volumen de la esfera de radio " << radio << " es: " << CalcularVolEsfera(radio) << std::endl;
}

void GestionVolPiramide()
{
    float lado_piramide, altura_piramide;
    std::cout << "Introduzca el lado de la piramide y su altura para calcular su volumen" << std::endl;
    std::cout << "Lado: " << std::endl;
    std::cin >> lado_piramide;
    std::cout << "Altura: " << std::endl;
    std::cin >> altura_piramide ;
    std::cout << "El volumen de la piramide cuadrangular de lado " << lado_piramide << " y de altura " << altura_piramide << " es de : " << CalcularVolPiramide(lado_piramide, altura_piramide) << std::endl;
}
