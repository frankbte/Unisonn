#include "Combinatoria.h"

long double CalcularCombinaciones(int n, int r)
{
    return CalcularPermutaciones(n,r) / CalcularFactorial(r);
}


//****************************************************************************************
long double CalcularFactorial(int n)
{
    long double fact = 1;
    for(int i = 2 ; i <= n ; ++i) fact *= i;
    return fact;
}

//****************************************************************************************

long double CalcularPermutaciones(int n, int r)
{
    return CalcularFactorial(n) / CalcularFactorial(n-r);
}
