#include <iostream>
#include "Lista.h"

using namespace std;
int main() {
    Lista<int> lista;
    Lista<int> lista2;
    char respuesta;

    do {
        cout << endl;
        cout << "Que accion desea realizar?" << endl;
        cout << "a: Agregar elementos" << endl;
        cout << "e: Eliminar elementos" << endl;
        cout << "c: Consultar un elemento" << endl;
        cout << "i: Intercambio de listas" << endl;
        cout << "s: Salir" << endl;
        cout << "Ingrese la letra de su opcion: ";
        cin >> respuesta;
        system("cls");

        switch (respuesta) {
            case 'a':
                char opcionAgregar;
                cout << "                       -------------AGREGANDO ELEMENTOS---------------\n\n";
                cout << "Donde desea agregar el elemento? (i: Inicio, f: Final, o: Indice): ";
                cin >> opcionAgregar;

                int valorAgregar, indiceAgregar;
                switch (opcionAgregar) {
                    case 'i':
                        cout << "Ingrese el valor a agregar al inicio de la lista: ";
                        cin >> valorAgregar;
                        lista.AgregarEnInicio(valorAgregar);
                        break;
                    case 'f':
                        cout << "Ingrese el valor a agregar al final de la lista: ";
                        cin >> valorAgregar;
                        lista.AgregarAlFinal(valorAgregar);
                        break;
                    case 'o':
                        cout << "Ingrese el valor a agregar: ";
                        cin >> valorAgregar;
                        cout << "Ingrese el indice donde desea agregar el elemento: ";
                        cin >> indiceAgregar;
                        try {
                            lista.AgregarEnIndice(indiceAgregar, valorAgregar);
                        } catch (const out_of_range& e) {
                            cerr << "Error al agregar elemento en el indice: " << e.what() << endl;
                        }
                        break;
                    default:
                        cout << "Opcion no valida." << endl;
                }
                system("cls");

                cout << "Lista despues de agregar el elemento: " << endl;
                cout << "La lista tiene: " << lista.Tamano() << " elementos" << endl;
                lista.Imprimir();
                cout << endl;
                break;

            case 'e':
                cout << "                   -----------ELIMINANDO ELEMENTOS----------\n\n";
                char opcionEliminar;
                cout << "Como desea eliminar el elemento? (i: Inicio, f: Final, o: Indice, v: Vaciar): ";
                cin >> opcionEliminar;

                switch (opcionEliminar) {
                    case 'i':
                        try {
                            lista.EliminarDeInicio();
                            cout << "Elemento eliminado correctamente." << endl;
                        } catch (const out_of_range& e) {
                            cerr << "Error al eliminar elemento: " << e.what() << endl;
                        }
                        break;
                    case 'f':
                        try {
                            lista.EliminarDeFinal();
                            cout << "Elemento eliminado correctamente." << endl;
                        } catch (const out_of_range& e) {
                            cerr << "Error al eliminar elemento: " << e.what() << endl;
                        }
                        break;
                    case 'o':
                        int indiceEliminar;
                        cout << "Ingrese el indice del elemento que desea eliminar: ";
                        cin >> indiceEliminar;
                        try {
                            lista.EliminarEnIndice(indiceEliminar);
                            cout << "Elemento eliminado correctamente." << endl;
                        } catch (const out_of_range& e) {
                            cerr << "Error al eliminar elemento: " << e.what() << endl;
                        }
                        break;
                    case 'v':
                        try{
                            lista.Vaciar();
                            cout << "Lista vaciada correctamente." << endl;
                        }catch (const out_of_range& e) {
                            cerr << "Error al vaciar la lista: " << e.what() << endl;
                        }
                        break;
                    default:
                        cout << "Opcion no valida." << endl;
                }
                system("cls");

                cout << "La lista tiene: " << lista.Tamano() << " elementos" << endl;
                lista.Imprimir();
                cout << endl;
                break;

            case 'c':
                cout << "               -------------CONSULTANDO ELEMENTOS--------------------\n\n";
                int indiceConsultar;
                cout << "Que desea hacer?" << endl;
                cout << "1: Buscar valor" << endl;
                cout << "2: Buscar posicion de un valor (primera ocurrencia)" << endl;
                cout << "3: Consultar si la lista esta vacia" << endl;
                cout << "4: Obtener primero" << endl;
                cout << "5: Obtener ultimo" << endl;
                cout << "6: Obtener valor en cierto indice" << endl;
                cout << "7: Obtener tamano de la lista" << endl;
                cout << "Ingerese el valor de su opcion: ";
                cin >> indiceConsultar;
                switch(indiceConsultar){
                case 1:
                    int numeroABuscar;
                    cout << "Que elemento desea saber si está ena la lista?: ";
                    cin >> numeroABuscar;
                    if(lista.BuscarValor(numeroABuscar) == true){
                        cout << "El numero si se encuentra en la lista" << endl;
                    }else{
                        cout << "El numero no se encuentra en la lista" << endl;
                    }
                    break;
                case 2:
                    int numeroABuscar2;
                    cout << "Que elemento desea buscar?: ";
                    cin >> numeroABuscar2;
                    cout << "La primera ocurrencia del valor " << numeroABuscar2 << " esta en la posicion " << lista.BuscarPos(numeroABuscar2) << endl;
                    break;
                case 3:
                    if(lista.EstaVacia()){
                        cout << "La lista esta vacia" << endl;
                    }else{
                        cout << "La lista no esta vacia, estos son sus elementos:" << endl;
                        lista.Imprimir();
                        break;
                    }
                case 4:
                    if(lista.EstaVacia()){
                        cout << "La lista esta vacia." << endl;
                    }else{
                        cout << "El elemento al principio de la lista es: " << lista.ObtenerPrimero() << endl;
                    }
                    break;
                case 5:
                    if(lista.EstaVacia()){
                        cout << "La lista esta vacia." << endl;
                    }else{
                        cout << "El elemento al final de la lista es: " << lista.ObtenerPrimero() << endl;
                    }
                    break;
                case 6:
                    int indiceBuscar;
                    cout << "Indique el indice del elemento que quiera conocer su valor: ";
                    cin >>  indiceBuscar;
                    cout << "El valor del indice " << indiceBuscar << " es " << lista.ObtenerValorEnIndice(indiceBuscar) << endl;
                    break;
                case 7:
                    if(lista.EstaVacia()){
                        cout << "La lista esta vacia" << endl;
                    }else{
                        cout << "El tamaño de la lista es de " << lista.Tamano() << " elementos" << endl;
                    }
                    break;
                }
                break;

            case 'i':
                cout << "               -------------INTERCAMBIANDO ELEMENTOS--------------------\n\n";
                int indiceIntercambio;
                cout << "Que desea hacer?" << endl;
                cout << "1: Transferir todos los elementos de una lista a otra" << endl;
                cout << "2: Transferir los elementos de un indice A hasta un indice B" << endl;
                cout << "3: Transferir los elementos de un indice A en adelante" << endl;
                cout << "Ingerese el valor de su opcion: ";
                cin >> indiceIntercambio;

                switch(indiceIntercambio){
                case 1:
                    cout << "Tenemos la lista 1:" << endl;
                    lista.Imprimir();
                    cout << endl;

                    cout << "Tenemos la lista 2: " << endl;
                    lista2.Imprimir();
                    cout << endl;

                    cout << "Intercambiamos..." << endl;
                    lista.Intercambiar(lista2);
                    cout << "Lista 1:" << endl;
                    lista.Imprimir();
                    cout << endl;
                    cout << "Lista 2:" << endl;
                    lista2.Imprimir();
                    break;

                case 2:
                    cout << "Indique el indice de la lista 1 desde donde y hasta cual elemento se tranferira a la lista 2:" << endl;
                    int indiceA1;
                    int indiceB1;
                    cout << "Indice A lista 1:";
                    cin >> indiceA1;
                    cout << "Indice B lista 1: ";
                    cin >> indiceB1;
                    cout << endl;

                    cout << "Los mismo para la lista 2:" << endl;
                    int indiceA2;
                    int indiceB2;
                    cout << "Indice A lista 2:";
                    cin >> indiceA2;
                    cout << "Indice B lista 2: ";
                    cin >> indiceB2;
                    cout << endl;

                    cout << "Tenemos la lista 1:" << endl;
                    lista.Imprimir();
                    cout << "Tenemos la lista 2:" << endl;
                    lista2.Imprimir();
                    cout << endl;

                    cout << "Intercambiamos..." << endl;
                    lista.IntercambiarElementos(indiceA1, indiceB1, lista2, indiceA2, indiceB2);
                    cout << "Lista 1: " << endl;
                    lista.Imprimir();
                    cout << endl;
                    cout << "Lista 2: " << endl;
                    lista2.Imprimir();
                    cout << endl;
                    break;
                case 3:
                    cout << "Indique el indice de la lista a partir del cual la lista se transferira a otra:" << endl;
                    int indicea;
                    cout << "Indice A lista 1:";
                    cin >> indicea;
                    cout << endl;

                    cout << "Los mismo para la lista 2:" << endl;
                    int indiceb;
                    cout << "Indice A lista 2:";
                    cin >> indiceb;

                    cout << "Tenemos la lista 1:" << endl;
                    lista.Imprimir();
                    cout << "Tenemos la lista 2:" << endl;
                    lista2.Imprimir();
                    cout << endl;

                    cout << "Intercambiamos..." << endl;
                    lista.IntercambiarElementos2(indicea,lista2,indiceb);
                    cout << "Lista 1: " << endl;
                    lista.Imprimir();
                    cout << endl;
                    cout << "Lista 2: " << endl;
                    lista2.Imprimir();
                    cout << endl;
                    break;



                }


                break;

            case 's':
                cout << "Saliendo del programa." << endl;
                break;

            default:
                cout << "Opcion no valida." << endl;
        }

    } while (respuesta != 's');

    char resp;
    cout << "Desea ordenar la lista de manera ascendente?: ";
    cin >> resp;
    if(resp == 's'){
        cout << "Lista ordenada:" << endl;
        lista.OrdenarAscendente();
        lista.Imprimir();
    }else{
        cout << "Lista final: " << endl;
        lista.Imprimir();
        cout << endl;
        cout << "Lista en orden inverso: " << endl;
        lista.ImprimirReversa();
        cout << endl;

    }

    cout << "Programa terminado." << endl;

    return 0;
}

