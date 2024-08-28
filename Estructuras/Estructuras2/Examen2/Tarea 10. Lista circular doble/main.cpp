#include <iostream>
#include "ListaCircularDoble.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;

string generarNombreAleatorio() {
    string nombres[] = {"Francisco", "Luis", "Joana", "Nicole", "Joao", "Olga",
        "Eduardo", "Camila", "Ivan", "Paola", "Juan", "jesus", "Pablo",
        "Itzel", "Maria" , "Eloy" , "Rosario" , "Sofia", "Carmen"};

    int longitud = sizeof(nombres) / sizeof(nombres[0]);

    int indice = rand() % longitud;

    return nombres[indice];
}

int main() {
    srand(time(0));

    try {
        ListaCD<string> lista;
        string nombre;
        int n, k;
        do {
            cout << "Elige el numero de personas para el juego (debe ser mayor que 1): ";
            cin >> n;
        } while (n <= 1);

        do {
            cout << "Elige el tamano del paso (debe ser mayor que 0): ";
            cin >> k;
        } while (k < 1);
        for(int i = 1; i <= n; ++i){
            nombre = generarNombreAleatorio();
            lista.Agregar(nombre);
        }
        lista.Imprimir();
        cout << endl;
        cout << endl;
        cout << endl;

        while(lista.ObtenerTam() != 1){
            cout << "La lista de personas es la siguiente: " << endl;
            lista.Imprimir();
            for(int i = 0; i < k-1 ; ++i){
                lista.AvanzarCabeza();
            }
            cout << "Eliminamos elemento: " << lista.ValorCabeza() << endl;
            cout << endl;

            lista.Eliminar(lista.ValorCabeza());
            sleep(2);
        }
        cout << "La persona que ha ganado es: " << lista.ValorCabeza();
    }
    catch (const exception& e) {
        cerr << "Ocurrió una excepción: " << e.what() << endl;
    }

    return 0;
}

