#include <iostream>
#include <string>
#include <cctype>
#define SIZE 5
#define Ignorado -1
#define x 41



const int NumEstados =137; // N�mero total de estados en el DFA
const int NumSimbolos = 29; // N�mero total de s�mbolos en el alfabeto (0 y 1)

const char FinDeLexema = '\0'; // Car�cter que indica el fin de la cadena


int TablaTransicion[NumEstados][NumSimbolos] = {
//{   0, 1,  2,  3,  4,   5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28}
    {133,  1, 10, 15, 19, 23, 38, 43, 47, 58, 68, 74, 80, 89, 91, 95,107,115,125,128,134,134,134,134,134,134,133,136,134},                  //0
    {134,134,134,134,134,134,134,134,134,3,134,134,9,134,134,134,134,134,134,134,2,4,134,134,134,134,134,134,134},          //1
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},  //2
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},  //3
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,5,134,134,134,134,134,134,134,134,134,134,134,134,134,134},     //4
    {134,134,134,134,134,134,134,134,134,134,134,134,134,6,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},    //5
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,7,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,8,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,11,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,12,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,13,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,14,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,16,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,17,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,18,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,20,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,21,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,22,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,24,134,134,134,34,134,134,134,26,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,25,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,31,27,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,28,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,29,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,30,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,32,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,33,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,35,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,36,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,37,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,39,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,40,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,41,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,42,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,44,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,45,134,46,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,48,134,134,134,134,134,134,134,134,134,134,134,134,53,134,134,134,134},
    {134,49,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,51,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,50,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,52,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,54,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,55,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,56,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,57,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,62,134,134,134,134,134,134,134,134,134,134,134,59,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,60,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,61,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,63,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,64,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,65,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,66,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,67,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,69,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,70,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,71,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,72,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,73,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,75,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,76,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,77,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,78,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,79,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,81,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,82,134,134,134,134,134,88,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,83,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,84,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,85,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,86,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,87,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,90,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,92,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,93,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,94,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,96,134,100,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,97,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,98,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,99,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,101,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,102,134,134,134,134,134,134,134,134,134,134},
    {134,103,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,104,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,105,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,106,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,112,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,108,134,134,134},
    {134,109,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,110,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,111,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,113,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,114,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,121,134,134,116,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,117,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,118,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,119,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,120,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,122,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,123,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,124,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,126,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,127,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,129,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,130,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,131,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,132,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135},//basura
    {136,136,136,136,136,136,136,136,136,136,136,163,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136}
  };

bool EstadosAceptacion[NumEstados] = {0,0,1,1,0,0,0,0,1,1,  0,0,0,0,1,0,0,0,1,0,  0,0,1,0,0,1,1,0,0,0,  1,0,0,1,0,0,0,1,
0,0,  0,0,1,0,0,1,1,0,0,0,  1,0,1,0,0,0,0,1,0,0,  1,1,0,0,0,0,0,1,0,0,  0,0,0,1,0,0,0,0,0,1,  0,0,0,0,0,0,0,1,1,0,  1,0,0,0,1,
0,0,0,0,1,  0,0,0,0,0,0,1,0,0,0,  0,1,0,0,1,0,0,0,0,0,  1,0,0,0,1,0,0,1,0,0,  0,0,1,0,1,0};

int simulaDFA(int state,char s) {


    int aux=state;
        //std::cout<<"PRIMER STATE: "<<state<<std::endl;
      int sIndex = (isalpha(s)) ? 0 : (isdigit(s))? 27:(s == '_')? 26: -1;//int sIndex = (isalpha(s)) ? 0 : (isdigit(s))? 2:(s == '-')? 1;

    switch(s) {
        case 'i':
            sIndex = 1;
            break;
        case 'F':
            sIndex = 2;
            break;
        case 'T':
            sIndex = 3;
            break;
        case 'N':
            sIndex = 4;
            break;
        case 'a':
            sIndex = 5;
            break;
        case 'b':
            sIndex = 6;
            break;
        case 'd':
            sIndex = 7;
            break;
        case 'e':
            sIndex = 8;
            break;
        case 'f':
            sIndex = 9;
            break;
        case 'g':
            sIndex = 10;
            break;
        case 'l':
            sIndex = 11;
            break;
        case 'n':
            sIndex = 12;
            break;
        case 'o':
            sIndex = 13;
            break;
        case 'p':
            sIndex = 14;
            break;
        case 'c':
            sIndex = 15;
            break;
        case 'w':
            sIndex = 16;
            break;
        case 'r':
            sIndex = 17;
            break;
        case 't':
            sIndex = 18;
            break;
        case 'y':
            sIndex = 19;
            break;
         case 's':
            sIndex = 20;
            break;
        case 'm':
            sIndex = 21;
            break;
        case 'u':
            sIndex = 22;
            break;
        case 'k':
            sIndex = 23;
            break;
        case 'x':
            sIndex = 24;
            break;
         case 'h':
            sIndex = 25;
            break;

    }


        state = TablaTransicion[state][sIndex];


        if(sIndex==-1){
            state=135;
            //sIndex=0;
        }
        if (s==' '){
            state=aux;
        }

        std::cout<<"Index: "<<sIndex<<std::endl;

        std::cout<<"Estado: "<<state<<std::endl;


    return state;
}

std::string tokenizar(int state){

    std::string token;

    switch(state) {
        case 2:
            token = "is";
            break;
        case 3:
            token = "if";
            break;
        case 8:
            token = "import";
            break;
        case 9:
            token = "in";
            break;
        case 14:
            token = "False";
            break;
        case 18:
            token = "True";
            break;
        case 22:
            token = "None";
            break;
        case 25:
            token = "and";
            break;
        case 26:
            token = "as";
            break;
        case 30:
            token = "assert";
            break;
        case 33:
            token = "async";
            break;
        case 37:
            token = "await";
            break;
        case 42:
            token = "break";
            break;
        case 45:
            token = "def";
            break;
        case 46:
            token = "del";
            break;
        case 50:
            token = "elif";
            break;
        case 52:
            token = "else";
            break;
        case 57:
            token = "except";
            break;
        case 60:
            token = "for";
            break;
         case 61:
            token = "form";
            break;
        case 67:
            token = "finally";
            break;
        case 73:
            token = "global";
            break;
        case 79:
            token = "lambda";
            break;
        case 87:
            token = "nonlocal";
            break;
         case 88:
            token = "not";
            break;
        case 90:
            token = "or";
            break;
        case 94:
            token = "pass";
            break;
        case 99:
            token = "class";
            break;
        case 106:
            token = "continue";
            break;
        case 111:
            token = "while";
            break;
        case 114:
            token = "with";
            break;
         case 120:
            token = "return";
            break;
        case 124:
            token = "raise";
            break;
        case 127:
            token = "try";
            break;
        case 132:
            token = "yield";
            break;
        case 134:
            token = "identificador";
            break;
        case 136:
            token = "numero";
            break;
    }

    return token;
}

typedef struct
{
    char buffer[SIZE];
    int head;
    int tail;
} BufferCircular;

int comentario = 0;
int bloquecomen = 0;
int comillas = 0;
int espacio = 0;
void initBuffer(BufferCircular *cbuf)
{
    cbuf->head = 0;
    cbuf->tail = 0;
}

int BufferVacio(const BufferCircular *cbuf)
{
    return (cbuf->head == cbuf->tail);
}

int BufferLleno(const BufferCircular *cbuf)
{
    return ((cbuf->tail + 1) % SIZE == cbuf->head);
}

int enqueue(BufferCircular *cbuf, int value, int &state, std::string &t)
{
 std::string au;
    if (BufferLleno(cbuf))
    {
        std::cout<<"Buffer lleno. No se puede encolar.\n";
    }
    if (value == '#')
    {
        comentario = 1;
    }

    if (value == '"')
    {
        comillas++;
        if (comillas == 3)
        {
            bloquecomen = !bloquecomen;
            comillas = 0;
            return Ignorado;
        }
        return Ignorado;
    }
    else if (comillas > 0)
    {
        comillas = 0;
    }

    if (bloquecomen == 1)
    {
        return Ignorado;
    }

    if (comentario == 1)
    {
        if (value == '\n')
        {
            if(value=='\0'){
            au="newline";
            if (!t.empty()) {
                t += " ";
            }
            t+=au;
            state=0;
            }
            comentario = 0;
        }
        return Ignorado;
    }


    else if (value == '\n')
    {
        if(value=='\0'){
        au="newline";
        if (!t.empty()) {
            t += " ";
        }
        t+=au;
        state=0;
        }
        return Ignorado;

    }

    if (value == ' ')
    {
        espacio++;
        if (EstadosAceptacion[state] == 1){
            au=tokenizar(state);
           if (!t.empty()) {
                t += " ";
            }
            t+=au;
            state=0;
        }
    }


      switch(value) {
        case '+':
        case '=':
        case '==': //:sss
        case '!=':
        case '<':
        case '>':
        case '<=':
        case '>=':
        case '-':
        case '/':
        case ',':
        case '(':
        case ')':
        case ':':
            au=value;
            if (!t.empty()) {
                t += " ";
            }
            t+=au;
        break;

      }
      if(value=='\t'&& value!='\0'){
        au="indent";
        if (!t.empty()) {
            t += " ";
        }
        t+=au;
      }

    else if (espacio > 0)
    {
        espacio = 0;
    }

    if (espacio > 1)
    {
        return Ignorado;
    }
    else
    {
        cbuf->buffer[cbuf->tail] = value;
        cbuf->tail = (cbuf->tail + 1) % SIZE;
        return value;
    }

}

int dequeue(BufferCircular *cbuf)
{
    int value = 0;

    if (!BufferVacio(cbuf))
    {
        value = cbuf->buffer[cbuf->head];
        cbuf->head = (cbuf->head + 1) % SIZE;
    }
    else
    {
        std::cout<<"Buffer vac�o. No se puede desencolar.\n";
    }

    return value;
}



int main()
{
    BufferCircular cbuf;
    initBuffer(&cbuf);

    FILE *file = fopen("archivo.txt", "r");
    if (file == NULL)
    {
        perror("Error al abrir el archivo");
        return 1;
    }

    char ch;
    int state= 0;
    std::string t;
    std::string au;
    while ((ch = fgetc(file)) != EOF)
    {
        if (BufferLleno(&cbuf))
        {
            while (!BufferVacio(&cbuf))
            {
                dequeue(&cbuf);
            }
        }
        int resultado = enqueue(&cbuf, ch, state, t);

        if (resultado != Ignorado)
        {
            printf("Encolando: %c\n", resultado);
            state= simulaDFA(state, resultado);
        }


    }
    // para la situacion en cuando quede en un estado intermedio de reconocer una palabra reservada se vaya a identificador

    if((!EstadosAceptacion[state] && state!=135)){ //poner los estados
        state=134;
        }

t = tokenizar(state);
std::cout << "TOKEN ES " << t << std::endl;
std::cout << "CH ES " << ch << std::endl;

    if(ch!=' ' && ch=='\0'){

        au=tokenizar(state);
        if (!t.empty()) {
            t += " ";
        }
        t+=au;
    }

    while (!BufferVacio(&cbuf))
    {
        dequeue(&cbuf);
    }
    std::cout<<"EL ESTADO ES EL "<<state;

    if (EstadosAceptacion[state] == 1){
            std::cout<<"Identificador\n";
        }else{
            std::cout<<"Rechazado\n";
        }

std::cout << "TOKEN ES " << t << std::endl;
    fclose(file);
    return 0;
}
