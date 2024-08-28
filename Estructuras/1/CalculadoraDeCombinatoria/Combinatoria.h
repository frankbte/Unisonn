#ifndef COMBINATORIA_H_INCLUDED
#define COMBINATORIA_H_INCLUDED

#define MAXFACT 1754 /// Maximo valor al que se le puede calcular el factorial en una variable long double


/** \brief Calcula el factorial de un n�mero no negativo
 *
 * \param n N�mero al que se le calcula el factorial
 *
 * \return El factorial de n
 */
long double CalcularFactorial(int n);

/** \brief Calcula permutaciones
 *
 * \param n N�mero de elementos en el conjunto
 * \param r N�mero de elementos a ordenar del conjunto
 *
 * \return Las permutaciones de n en r
 */
long double CalcularPermutaciones(int n, int r);

/** \brief Calcula combinaciones
 *
 * \param n N�mero de elementos en el conjunto
 * \param r N�mero de elementos a elegir del conjunto
 *
 * \return Las combinaciones de n en r
 */
long double CalcularCombinaciones(int n, int r);


#endif // COMBINATORIA_H_INCLUDED
