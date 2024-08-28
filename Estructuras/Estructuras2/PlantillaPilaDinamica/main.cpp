#include <iostream>
#include "Lista.h"

int main() {
    Lista<int> lista;

    char respuesta;

    std::cout << "----------Agregando elementos----------" << std::endl;
    do {
        std::cout << "Desea agregar un elemento a la lista? (s/n): ";
        std::cin >> respuesta;

        if (respuesta == 's') {
            int valor;
            std::cout << "Ingrese el valor a agregar a la lista: ";
            std::cin >> valor;
            lista.AgregarAlFinal(valor);
            std::cout << "Lista después de agregar el elemento: " << std::endl;
            std::cout << "La lista tiene: " << lista.Tamano() << " elementos" << std::endl;
            lista.Imprimir();
            std::cout << std::endl;
        }
    } while (respuesta == 's');

    std::cout << "----------Eliminando elementos----------" << std::endl;

    do {
        std::cout << "¿Desea eliminar un elemento de la lista? (s/n): ";
        std::cin >> respuesta;

        if (respuesta == 's') {
            try {
                lista.EliminarDeFinal();
                std::cout << "Elemento eliminado correctamente." << std::endl;
                std::cout << "Lista después de eliminar el elemento: " << std::endl;
                std::cout << "La lista tiene: " << lista.Tamano() << " elementos" << std::endl;
                lista.Imprimir();
                std::cout << std::endl;
            } catch (const std::out_of_range& e) {
                std::cerr << "Error al eliminar elemento: " << e.what() << std::endl;
            }
        }
    } while (respuesta == 's');

    std::cout << "Lista final: " << std::endl;
    lista.Imprimir();

    std::cout << std::endl;

    std::cout << "Programa terminado." << std::endl;
    return 0;
}

