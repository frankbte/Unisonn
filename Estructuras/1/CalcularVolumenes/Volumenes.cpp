#include "Volumenes.h"

float CalcularVolEsfera (float radio)
{
    return (4*PI*radio*radio*radio)/3;
}
float CalcularVolCubo (float lado)
{
    return lado*lado*lado;
}
float CalcularVolPiramide (float lado_piramide,float altura_piramide)
{
    return ((lado_piramide*lado_piramide)*altura_piramide)/3 ;
}
float CalcularVolCilindro (float radio_cilindro, float altura_cilindro)
{
    return PI*(radio_cilindro*radio_cilindro)*altura_cilindro ;
}
