#include <iostream>
#include "Grafo.h"


using namespace std;

int main()
{
    Grafo* grafo = new Grafo();
    int opc = 0;


    grafo->InsertarVertice("A");
    grafo->InsertarVertice("B");
    grafo->InsertarVertice("C");
    grafo->InsertarVertice("D");
    grafo->InsertarVertice("E");
    grafo->InsertarVertice("F");
    grafo->InsertarVertice("G");
    grafo->InsertarArista("A", "B", 7);
    grafo->InsertarArista("A", "D", 5);
    grafo->InsertarArista("B", "A", 7);
    grafo->InsertarArista("B", "C", 8);
    grafo->InsertarArista("B", "D", 9);
    grafo->InsertarArista("B", "E", 7);
    grafo->InsertarArista("C", "B", 8);
    grafo->InsertarArista("C", "E", 5);
    grafo->InsertarArista("D", "A", 5);
    grafo->InsertarArista("D", "B", 9);
    grafo->InsertarArista("D", "E", 15);
    grafo->InsertarArista("D", "F", 6);
    grafo->InsertarArista("E", "B", 7);
    grafo->InsertarArista("E", "C", 5);
    grafo->InsertarArista("E", "D", 15);
    grafo->InsertarArista("E", "F", 8);
    grafo->InsertarArista("E", "G", 9);
    grafo->InsertarArista("F", "D", 6);
    grafo->InsertarArista("F", "E", 8);
    grafo->InsertarArista("F", "G", 11);
    grafo->InsertarArista("G", "E", 9);
    grafo->InsertarArista("G", "F", 11);




    while(opc != 9)
    {
        system("cls");
        cout << "1. Insertar vertice" << endl;
        cout << "2. Insertar arista" << endl;
        cout << "3. Obtener tamanio" << endl;
        cout << "4. Mostrar lista de adyacencia" << endl;
        cout << "5. Eliminar vertice" << endl;
        cout << "6. Eliminar arista" << endl;
        cout << "7. Eliminar todo" << endl;
        cout << "8. Algoritmo Prim" << endl;
        cout << "9. Salir" << endl;


        cout << endl;
        cout << "Ingrese la opcion: ";
        cin >> opc;

        system("cls");


        switch(opc)
        {
        case 1:
            {
                string nombre;
                cout << "Ingrese el nombre del vertice: ";
                cin >> nombre;

                grafo->InsertarVertice(nombre);

                break;
            }
        case 2:
            {
                if(grafo->EstaVacio())
                    cout << "El grafo esta vacio..." << endl;
                else{

                    string ori, dest;
                    int precio;


                    cout << "Ingrese el nombre del vertice origen: ";
                    cin >> ori;
                    cout << "Ingrese el nombre del vertice destino: ";
                    cin >> dest;
                    cout << "Ingrese el precio: ";
                    cin >> precio;

                    grafo->InsertarArista(ori,dest, precio);
                }
                break;
            }
        case 3:
            {
                int tamano = grafo->ObtenerTamano();
                cout << "El grafo tiene " << tamano << " vertices" << endl;

                break;
            }
        case 4:
            {
                if(grafo->EstaVacio())
                    cout << "El grafo esta vacio..." << endl;
                else
                {
                    grafo->MostrarListaAdyacencia();
                }

                break;
            }
        case 5:
            {
                if(grafo->EstaVacio())
                    cout << "El grafo esta vacio..." << endl;
                else
                {
                    string nombre;
                    cout << "Ingrese el nombre del vertice: ";
                    cin >> nombre;

                    grafo->EliminarVertice(nombre);
                }

                break;
            }
        case 6:
            {
                if(grafo->EstaVacio())
                    cout << "El grafo esta vacio..." << endl;
                else
                {
                    string ori, dest;
                    cout << "Ingrese el nombre del vertice origen: ";
                    cin >> ori;
                    cout << "Ingrese el nombre del vertice destino: ";
                    cin >> dest;

                    grafo->EliminarArista(ori, dest);
                }
                break;
            }
        case 7:
            {
                if(grafo->EstaVacio())
                    cout << "El grafo esta vacio..." << endl;
                else
                {
                    grafo->Vaciar();
                }

                break;
            }
        case 8:
            {
                if(grafo->EstaVacio())
                    cout << "El grafo está vacio..." << endl;
                else
                {
                    string nombre;
                    cout << "Ingrese el nombre del vertice origen: ";
                    cin>> nombre;

                    grafo->Prim(nombre);
                }
                break;
            }
        }
        cin.get();
        cin.get();
    }
}
