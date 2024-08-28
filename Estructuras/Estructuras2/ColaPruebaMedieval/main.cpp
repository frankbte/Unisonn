#include <iostream>
#include <cstdlib>
#include "cola.h"
#include <ctime>
#include <vector>
#include <windows.h>
using namespace std;

int main() {
    Cola colaMedieval;
    colaMedieval.Encolar("Francisco", true);  // noble
    colaMedieval.Encolar("Luis", true);  // noble
    colaMedieval.Encolar("Orlando", true); // noble
    colaMedieval.Encolar("Joana", true);   // noble
    colaMedieval.Encolar("Nicole", false);  // plebeyo
    colaMedieval.Encolar("Olga", true);  // noble
    colaMedieval.Encolar("Lucia", false);  // plebeyo
    colaMedieval.Encolar("Alex", false);  // plebeyo

    colaMedieval.Imprimir();
    cout << endl;
    Persona primero = colaMedieval.ObtenerPrimero();

    std::cout << "Primer ciudadano: " << primero.ObtenerNombre() << " (" << (primero.esNoble() ? "noble" : "plebeyo") << ")" << std::endl;
    colaMedieval.Desencolar();
    colaMedieval.Imprimir();

    return 0;
}
