#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <windows.h>
#include "ColaM.h"

using namespace std;

// Función para establecer la posición del cursor en la consola
void setCursorPosition(int x, int y) {
#ifdef _WIN32
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
#else
    std::cout << "\033[" << y << ";" << x << "H";
#endif
}

//Funcion para generar un nombre aleatorio
std::string generarNombreAleatorio(const std::vector<std::string>& lista1, const std::vector<std::string>& lista2) {
    int indice1 = rand() % lista1.size();
    int indice2 = rand() % lista2.size();
    std::string nombre = lista1[indice1] + " " + lista2[indice2];
    return nombre;
}
//Funcion que genera los clientes y las interacciones que tienen con la cola
void generarClientes(Cola& clientes, int tiempoTotal, std::vector<std::string>& clientesAtendidos) {
    std::vector<std::string> nombres = {"Francisco", "Luis", "Orlando", "Pedro", "Maria", "Ana", "Camila", "Eduardo", "Lucia", "Joana"};
    std::vector<std::string> apellidos = {"Yanez", "Lopez", "Hernandez", "Roque", "Islas", "Gonzalez", "Salazar", "Fernandez", "Garcia", "Sanchez"};

    srand(time(0));

    int tiempoActual = 0;
    int tiempoInicioAtencion = 0;
    bool atendiendoCliente = false;
    std::string clienteActual = "";

    // Limpiar pantalla y mostrar la cola vacia
    system("cls");
    std::cout << "Lista de espera: " << std::endl;
    clientes.Imprimir();
    std::cout << std::endl;

    while (tiempoActual < tiempoTotal) {
        system("cls");
        setCursorPosition(0, 1);
        std::cout << "\rReloj: " << tiempoActual << std::flush << std::endl;

        setCursorPosition(0, 3);
        std::cout << "---------------------------------------------------------------------";
        setCursorPosition(5, 4);
        if (atendiendoCliente) {
            int tiempoAtendido = tiempoActual - tiempoInicioAtencion;
            std::cout << "Atendiendo a: " << clientes.ObtenerPrimero() << " - Tiempo transcurrido: " << tiempoAtendido;
        } else {
            std::cout << "No hay clientes siendo atendidos";
        }
        setCursorPosition(0, 5);
        std::cout << "---------------------------------------------------------------------";

        setCursorPosition(0, 6);
        std::cout <<"Clientes en espera: " << std::endl;
        clientes.Imprimir();

        Sleep(1000);
        tiempoActual++;

        int randomAgregar = rand() % 3 + 1;
        int randomQuitar = rand() % 5 + 1;

        if (randomAgregar == 1 && randomAgregar != randomQuitar) {
            std::string nombreCliente = generarNombreAleatorio(nombres, apellidos);
            clientes.Encolar(nombreCliente);
            if (!atendiendoCliente) {
                atendiendoCliente = true;
                tiempoInicioAtencion = tiempoActual;
                clienteActual = nombreCliente;
            }
        }
        if (clientes.EstaVacia()) {
            atendiendoCliente = false;
            tiempoInicioAtencion = 0;
        }
        if (clienteActual != clientes.ObtenerPrimero()) {
            tiempoInicioAtencion = tiempoActual;
            clienteActual = clientes.ObtenerPrimero();
        }

        if (randomQuitar == 1 && !clientes.EstaVacia()) {
            clientesAtendidos.push_back(clientes.ObtenerPrimero());
            clientes.Desencolar();
        }
    }

    system("cls");
    std::cout << "Tiempo de atencion global alcanzado. Simulacion terminada." << std::endl;
    std::cout << "---------------------------------------------------------------------" << std::endl;
    std::cout << "Clientes que quedaron sin atender: " << std::endl;
    clientes.Imprimir();
}

int main() {
    srand(time(nullptr));
    int tiempoTotal = rand() % 121 + 120; ;
    std::cout << "La caja atendera a cuantas personas pueda en " << tiempoTotal << " minutos.\n\n";
    std::cout << "El tiempo de atencion por persona es aleatorio\n\n\n";
    std::cout << "Presiona ENTER para continuar . . . .";
    std::cin.get();
    system("cls");

    Cola clientes;
    std::vector<std::string> clientesAtendidos;

    int tiempoActual = 0;

    generarClientes(clientes, tiempoTotal, clientesAtendidos);

    std::cout << "---------------------------------------------------------------------" << std::endl;
    std::cout << "Clientes atendidos:" << std::endl;
    for (const auto& cliente : clientesAtendidos) {
        std::cout << cliente << std::endl;
    }
    std::cout << "---------------------------------------------------------------------" << std::endl;
    return 0;
}
