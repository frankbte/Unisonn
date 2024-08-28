#include <iostream>
#include "Pila.h"

using namespace std;

int main() {
    Pila<int, 10> pila;

    char respuesta;

    do {
        std::cout << "¿Desea agregar un elemento a la pila? (s/n): ";
        std::cin >> respuesta;

        if (respuesta == 's') {
            int valor;
            std::cout << "Ingrese el valor a agregar a la pila: ";
            std::cin >> valor;
            pila.Agregar(valor);
            std::cout << "Pila después de agregar elemento: ";
            pila.Imprimir();
            pila.ObtenerTam();
            std::cout << std::endl;
        }
    } while (respuesta == 's');

    do {
        std::cout << "¿Desea eliminar un elemento de la pila? (s/n): ";
        std::cin >> respuesta;

        if (respuesta == 's') {
            try {
                pila.Eliminar();
                std::cout << "Elemento eliminado correctamente." << std::endl;
                std::cout << "Pila después de eliminar elemento: ";
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

    return 0;
}
