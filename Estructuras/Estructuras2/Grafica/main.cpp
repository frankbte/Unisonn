#include <iostream>
#include "Grafica.h"

using namespace std;

void mostrarMenu() {
    cout << "\n--- MENU ---" << endl;
    cout << "1. Agregar nodo" << endl;
    cout << "2. Agregar arista" << endl;
    cout << "3. Eliminar arista" << endl;
    cout << "4. Vaciar nodo" << endl;
    cout << "5. Vaciar grafica" << endl;
    cout << "6. Imprimir grafica" << endl;
    cout << "7. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

int main()
{
    Grafica g;

    g.AgregarNodo('A');
    g.AgregarNodo('B');
    g.AgregarNodo('C');
    g.AgregarNodo('D');
    g.AgregarNodo('E');

    g.AgregarArista('A', 'B');
    g.AgregarArista('A', 'C');
    g.AgregarArista('A', 'D');
    g.AgregarArista('A', 'E');

    char opcion;
    char nombreInicio, nombreFin;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case '1':
                cout << "Ingrese el nombre del nodo a agregar: ";
                cin >> nombreInicio;
                g.AgregarNodo(nombreInicio);
                system("cls");
                break;
            case '2':
                cout << "Ingrese el nombre del nodo de inicio de la arista: ";
                cin >> nombreInicio;
                cout << "Ingrese el nombre del nodo de fin de la arista: ";
                cin >> nombreFin;
                g.AgregarArista(nombreInicio, nombreFin);
                system("cls");
                break;
            case '3':
                cout << "Ingrese el nombre del nodo de inicio de la arista a eliminar: ";
                cin >> nombreInicio;
                cout << "Ingrese el nombre del nodo de fin de la arista a eliminar: ";
                cin >> nombreFin;
                g.EliminarArista(nombreInicio, nombreFin);
                system("cls");
                break;
            case '4':
                cout << "Ingrese el nombre del nodo a vaciar: ";
                cin >> nombreInicio;
                g.VaciarNodo(nombreInicio);
                system("cls");
                break;
            case '5':
                g.Vaciar();
                cout << "La grafica ha sido vaciada." << endl;
                system("cls");
                break;
            case '6':
                cout << "Contenido de la grafica:" << endl;
                g.Imprimir();
                break;
            case '7':
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
                system("cls");
                break;
        }

    } while (opcion != '7');

    return 0;
}
