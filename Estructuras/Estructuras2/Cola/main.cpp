#include <iostream>
#include "cola.h"

using namespace std;

int main()
{
    Cola<int> cola;
    char respuesta;

    cout << "----------Agregando elementos----------" << endl;
    do {
        std::cout << "Desea agregar un elemento a la cola? (s/n): ";
        std::cin >> respuesta;

        if (respuesta == 's') {
            int valor;
            std::cout << "Ingrese el valor a agregar a la cola: ";
            std::cin >> valor;
            cola.Encolar(valor);
            std::cout << "Cola despues de agregar elemento: " << endl;
            std::cout << "La cola tiene: " << cola.ObtenerTam() << " elementos";
            std::cout <<"\n";
            cola.Imprimir();
            std::cout << std::endl;
        }
    } while (respuesta == 's');

    cout << " ----------Eliminando elementos----------" << endl;

    do {
        std::cout << "¿Desea eliminar un elemento de la cola? (s/n): ";
        std::cin >> respuesta;

        if (respuesta == 's') {
            try {
                cola.Desencolar();
                std::cout << "Elemento eliminado correctamente." << std::endl;
                std::cout << "Cola despues de eliminar elemento: " << endl;
                std::cout << "La cola tiene: " << cola.ObtenerTam() << " elementos" << endl;
                cola.Imprimir();
                std::cout << std::endl;
            } catch (const char* mensaje) {
                std::cerr << "Error al eliminar elemento: " << mensaje << std::endl;
            }
        }
    } while (respuesta == 's');

    cout << "Cola final: " << endl;
    cola.Imprimir();

    cout << endl;

    std::cout << "Programa terminado." << std::endl;
    return 0;
}
