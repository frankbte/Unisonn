#include <iostream>
#include "Pila.h" //

using namespace std;

int main() {
    try{
        Pila miPila;
        char respuesta;
        int valor;

        do{
            cout << "Valor a agregar: ";
            cin >> valor;
            miPila.Agregar(valor);
            cout << "Elemento agregado. Ahora la pila tiene " << miPila.ObtenerTam() << " elemento(s)...\n\n";
            miPila.Imprimir();
            cout << "\n\n";
            do{
                cout << "\250Quiere agregar otro elemento? (s/n): ";
                cin >> respuesta;
                respuesta = tolower(respuesta);
            }while(respuesta != 's' && respuesta != 'n');
        }while(respuesta == 's');

        cout << "Eliminando elementos..." << endl;
        do{
            cout << "Elemento a eliminar: " << miPila.ObtenerTope() << endl;
            miPila.Eliminar();
            cout << "Elemento eliminado. Ahora la pila tiene " << miPila.ObtenerTam() << " elemento(s)...\n\n";
            miPila.Imprimir();
            cout << "\n\n";
            do{
                cout << "\250Quiere eliminar otro elemento? (s/n): ";
                cin >> respuesta;
                respuesta = tolower(respuesta);
            }while(respuesta != 's' && respuesta != 'n');
        }while(respuesta == 's');



    }catch(const char *msn){
        cerr << "Error: " << msn << endl;
    }



    return 0;
}
