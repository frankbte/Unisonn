#include <iostream>
#include "Lista.h"
#include "TablaHash.h"
#include "utilerias.h"
#include "Gestion.h"

using namespace std;

int main()
{
    int opcion;
    TablaHashDC tablaOriginal(5);
    TablaHashDC tablaCopia(5);

    enum opciones {AGREGAR_ELEMENTOS=1, ELIMINAR_ELEMENTOS, BUSCAR_ELEMENTO, IMPRIMIR_TABLA, VACIAR_TABLA, SALIR};


    do
    {
        opcion = MenuDeInicio();
        switch (opcion)
        {

        case AGREGAR_ELEMENTOS:
            AgregarElementos(tablaOriginal);
            break;

        case ELIMINAR_ELEMENTOS:
            EliminarElementos(tablaOriginal);
            break;

        case BUSCAR_ELEMENTO:
            BuscarElementos(tablaOriginal);
            break;

        case IMPRIMIR_TABLA:
            ImprimirTabla(tablaOriginal);
            break;

        case VACIAR_TABLA:

            if (VaciarTabla(tablaOriginal))
            {
                gotoxy(1,14);
                cout << "  La tabla se ha vaciado correctamente.                         " << endl;
            }
            else
            {
                gotoxy(1,14);
                cout << "  La tabla ya est\240 vac\241a.                            " << endl;
            }
            break;

        case SALIR:
            color(0);
            gotoxy(1,14);
            borrador();
            tablaOriginal.Vaciar();
            tablaCopia.Vaciar();
            color(7);
            return 0;
            break;


        }
    }
    while(opcion != SALIR);

    cout <<endl;
}
