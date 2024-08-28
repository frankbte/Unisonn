#include <iostream>
#include <conio.h>
#include "Lista.h"
#include "TablaHash.h"
#include "utilerias.h"
#include "FuncionesHash.h"
#include "InterfazGrafica.h"

using namespace std;

int main()
{
    TablaHashDC tablaOriginal(5);

    int opcion;
    int cantidad;
    string texto;
    //enum opciones {AGREGAR_ELEMENTOS=1, ELIMINAR_ELEMENTOS, BUSCAR_ELEMENTO, IMPRIMIR_TABLA, IMPRIMIR_ESTADISTICAS, GUARDAR_COPIA, RESTAURAR_COPIA, VACIAR_TABLA, ELIMINAR_COPIA, SALIR};


    do
    {
        borrador();
        opcion = menuInicio();
        switch (opcion)
        {

        case AGREGAR_ENTRADA:
            AgregarElementos(tablaOriginal);
            break;

        case AGREGAR_RANDOM:
            cout<< "AGREGAR RANDOM" << endl;

            AgregarElementosAleatorios(tablaOriginal);
            break;

        case ELIMINAR_ENTRADA:
            cout<< "ELIMINAR_ENTRADA:" << endl;
            EliminarElementos(tablaOriginal);
            break;

        case VACIAR_TABLA:
            cout << "VACIAR_TABLA:" << endl;
            VaciarTabla(tablaOriginal);
            _getch();  // Espera a que el usuario presione una tecla
            break;

        case MODIFICAR_ENTRADA:
            cout<< "MODIFICAR_ENTRADA:" << endl;
            ModificarElemento(tablaOriginal);
            break;

        case IMPRIMIR_TABLA:
            cout<< "IMPRIMIR_TABLA:" << endl;
            ImprimirTabla(tablaOriginal);
            _getch();
            break;

        case SALIR:
            cout<< "Programa Terminado" << endl;
            //RestaurarUltimaCopia(tablaOriginal, tablaCopia);
            break;

        }
    }
    while(opcion != SALIR);

    cout <<endl;
}
