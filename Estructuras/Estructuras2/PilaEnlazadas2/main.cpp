#include <iostream>
#include "pila.h"
using namespace std;

bool ValidarExpresion(const char *expresion)
{
    Pila<char> pila;

    while(*expresion){
        char c = *expresion;

        if(c == '(' || c == '[' || c == '{'){
            pila.Apilar(c);
        }else if(c == ')' || c == ']' || c == '}'){
            if(pila.EstaVacia()){
                return false;
            }
            char tope = pila.ElementoTope();
            if ((c == ')' && tope == '(') ||
                (c == ']' && tope == '[') ||
                (c == '}' && tope == '{')){
                pila.Desapilar();
            }else{
                return false;
            }

        }
        expresion++;
    }
    return pila.EstaVacia();
}

double EvaluarExpresion(const char *expresion)
{
    Pila<double> pila;
}


int main()
{
    /*Pila<int> pila;

    char respuesta;

    cout << "----------Agregando elementos----------" << endl;
    do {
        std::cout << "Desea agregar un elemento a la pila? (s/n): ";
        std::cin >> respuesta;

        if (respuesta == 's') {
            int valor;
            std::cout << "Ingrese el valor a agregar a la pila: ";
            std::cin >> valor;
            pila.Apilar(valor);
            std::cout << "Pila despues de agregar elemento: " << endl;
            std::cout << "La pila tiene: " << pila.ObtenerElementos() << " elementos";

            pila.ObtenerElementos();
            std::cout <<"\n";
            pila.Imprimir();
            std::cout << std::endl;
        }
    } while (respuesta == 's');

    cout << " ----------Eliminando elementos----------" << endl;

    do {
        std::cout << "¿Desea eliminar un elemento de la pila? (s/n): ";
        std::cin >> respuesta;

        if (respuesta == 's') {
            try {
                pila.Desapilar();
                std::cout << "Elemento eliminado correctamente." << std::endl;
                std::cout << "Pila despues de eliminar elemento: " << endl;
                std::cout << "La pila tiene: " << pila.ObtenerElementos() << " elementos" << endl;
                pila.Imprimir();
                std::cout << std::endl;
            } catch (const char* mensaje) {
                std::cerr << "Error al eliminar elemento: " << mensaje << std::endl;
            }
        }
    } while (respuesta == 's');

    cout << "Pila final: " << endl;
    pila.Imprimir();

    cout << endl;

    std::cout << "Programa terminado." << std::endl;
    */

    const char *expresion = "{(2+3)*[4-1]}";
    if(ValidarExpresion(expresion)){
        std::cout << "La cadena es valida.";
    }else{
        std::cout << "La cadena no es valida.";
    }

    return 0;
}
